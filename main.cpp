#include <QApplication>
#include "photoeditor.h"
#include "ui_PhotoEditor.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PhotoEditor *photoEditor = new PhotoEditor();
    photoEditor->show();
    return QApplication::exec();
}
