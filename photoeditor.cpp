//
// Created by Александр Широков on 21.03.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PhotoEditor.h" resolved

#include "photoeditor.h"
#include "ui_PhotoEditor.h"
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>


PhotoEditor::PhotoEditor(QWidget *parent) :
        QWidget(parent), ui(new Ui::PhotoEditor) {
    ui->setupUi(this);
    ui->label->setText("NO PICTURE");
    ui->label->setAlignment(Qt::AlignCenter);
    resize(1024,768);
    QString filePath;
    QPixmap pixmap;
    connect(ui->pushButton, &QPushButton::clicked, [this, &filePath, &pixmap](){
       filePath = QFileDialog::getOpenFileName(nullptr,
                                     "Open picture",
                                     "./",
                                     "open file (*.png)");
       pixmap = QPixmap(filePath);
       ui->label->setPixmap(pixmap.scaled(ui->label->width(),ui->label->height(), Qt::KeepAspectRatio));
       is_open = true;
    });


    connect(ui->horizontalSlider, &QSlider::valueChanged, [this, &pixmap](){
                ui->label->setPixmap(
                        QPixmap::fromImage(
                                this->blur_Image(pixmap.toImage(),ui->horizontalSlider->value()).scaled(
                                        ui->label->width(), ui->label->height(), Qt::KeepAspectRatio
                                )
                        )
                );
            }
    );

}

PhotoEditor::~PhotoEditor() {
    delete ui;
}

QImage PhotoEditor::blur_Image(QImage source, int blurRadius) {
    if(source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap (QPixmap:: fromImage(source));
//
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius (blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32) ;
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0, 0, source.width(), source.height()));
    return result;
}


