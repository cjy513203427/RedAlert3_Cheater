/********************************************************************************
** Form generated from reading UI file 'ra3window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RA3WINDOW_H
#define UI_RA3WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ra3Window
{
public:
    QWidget *centralWidget;
    QWidget *background_widget;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *Ra3Window)
    {
        if (Ra3Window->objectName().isEmpty())
            Ra3Window->setObjectName(QStringLiteral("Ra3Window"));
        Ra3Window->resize(339, 639);
        centralWidget = new QWidget(Ra3Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        background_widget = new QWidget(centralWidget);
        background_widget->setObjectName(QStringLiteral("background_widget"));
        background_widget->setGeometry(QRect(0, 0, 351, 171));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 550, 120, 16));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 550, 100, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 580, 120, 18));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 580, 72, 22));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 580, 100, 20));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 230, 321, 251));
        textEdit->setAutoFillBackground(false);
        textEdit->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 200, 55, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(240, 200, 85, 22));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 490, 140, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 490, 66, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 490, 100, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 520, 66, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 520, 140, 22));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 520, 100, 20));
        Ra3Window->setCentralWidget(centralWidget);

        retranslateUi(Ra3Window);

        QMetaObject::connectSlotsByName(Ra3Window);
    } // setupUi

    void retranslateUi(QMainWindow *Ra3Window)
    {
        Ra3Window->setWindowTitle(QApplication::translate("Ra3Window", "Ra3Window", Q_NULLPTR));
        label_3->setText(QApplication::translate("Ra3Window", "\347\255\226\347\225\245\345\212\240\346\273\241", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("Ra3Window", "\351\200\211\345\217\226\345\215\225\344\275\215", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Ra3Window", "\345\260\217", Q_NULLPTR)
         << QApplication::translate("Ra3Window", "\346\240\207\345\207\206", Q_NULLPTR)
         << QApplication::translate("Ra3Window", "\345\244\247", Q_NULLPTR)
        );
        pushButton_4->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Ra3Window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\257\264\346\230\216</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\207\221\351\222\261\357\274\232\350\276\223\345\205\245\351\207\221\351\222\261\346\225\260\351\242\235\357\274\214\345\206\215\347\202\271\345\207\273\345\217\263\344\276\247\342\200\234\347\253\213\345\215\263\347\224\237\346\225\210\342\200\235\346\214\211\351\222\256\357\274\214\345\215\263\345\217\257\350\216\267\345\276\227\346\214\207\345\256\232\347\232\204\351\207\221\351\222\261\346"
                        "\225\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\224\265\345\212\233\357\274\232\350\276\223\345\205\245\347\224\265\345\212\233\345\200\274\357\274\214\345\206\215\347\202\271\345\207\273\345\217\263\344\276\247\342\200\234\347\253\213\345\215\263\347\224\237\346\225\210\342\200\235\346\214\211\351\222\256\357\274\214\345\215\263\345\217\257\350\216\267\345\276\227\346\214\207\345\256\232\347\232\204\347\224\265\345\212\233\345\200\274</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\255\226\347\225\245\345\212\240\346\273\241\357\274\232\344\270\215\351\234\200\350\246\201\346\214\207\345\256\232\357\274\214\351\273\230\350\256\244\345\212\240\346\273\241</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\200\211\345\217\226\345\215\225\344\275\215\357"
                        "\274\232\345\205\210\351\200\211\346\213\251\344\270\200\344\270\252\345\215\225\344\275\215\357\274\214\344\270\213\346\213\211\346\241\206\351\200\211\346\213\251\345\244\247\345\260\217\357\274\214\345\206\215\347\202\271\345\207\273\345\217\263\344\276\247\342\200\234\347\253\213\345\215\263\347\224\237\346\225\210\342\200\235\346\214\211\351\222\256\357\274\214\345\217\257\344\273\245\347\234\213\345\210\260\345\215\225\344\275\215\347\232\204\345\244\247\345\260\217\345\217\230\345\214\226\357\274\233\346\240\207\345\207\206\357\274\232\346\255\243\345\270\270\345\244\247\345\260\217\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\345\215\232\345\256\242\345\234\260\345\235\200\357\274\232https://www.cnblogs.com/Java-Starter/</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\344\273\205\344\276\233\345\255\246\344\271\240\344\272\244\346\265\201\357\274\214\344\270\245\347\246\201\345\225\206\347\224\250</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">				   \344\275\234\350"
                        "\200\205\357\274\232Jonas</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Ra3Window", "\350\257\255\350\250\200", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Ra3Window", "\347\256\200\344\275\223\344\270\255\346\226\207", Q_NULLPTR)
         << QApplication::translate("Ra3Window", "\350\213\261\350\257\255", Q_NULLPTR)
         << QApplication::translate("Ra3Window", "\345\276\267\350\257\255", Q_NULLPTR)
        );
        lineEdit->setPlaceholderText(QApplication::translate("Ra3Window", "\350\276\223\345\205\245\351\207\221\351\222\261\346\225\260\351\242\235", Q_NULLPTR));
        label->setText(QApplication::translate("Ra3Window", "\351\207\221\351\222\261", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("Ra3Window", "\347\224\265\345\212\233", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("Ra3Window", "\350\276\223\345\205\245\347\224\265\345\212\233\345\200\274", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ra3Window: public Ui_Ra3Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RA3WINDOW_H
