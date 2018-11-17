#include "ra3window.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ra3Window w;
    w.setWindowTitle("红色警戒3原版修改器");
    QIcon icon("./images/ra3.ico");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}
