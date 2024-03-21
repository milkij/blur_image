//
// Created by Александр Широков on 21.03.2024.
//

#ifndef INC_3_PHOTOEDITOR_H
#define INC_3_PHOTOEDITOR_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class PhotoEditor; }
QT_END_NAMESPACE

class PhotoEditor : public QWidget {
Q_OBJECT

public:
    explicit PhotoEditor(QWidget *parent = nullptr);

    ~PhotoEditor() override;

public:

    QImage blur_Image (QImage source, int blurRadius);

private:
    Ui::PhotoEditor *ui;
    bool is_open = false;

};



#endif //INC_3_PHOTOEDITOR_H
