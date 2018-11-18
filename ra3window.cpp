#include "ra3window.h"
#include "ui_ra3window.h"
/*
    作者：Jonas
    时间：2018/11/18
*/
Ra3Window::Ra3Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ra3Window)
{
    ui->setupUi(this);

    qDebug() <<"长度"<<this->width()<<"宽度"<< this->height();
    //禁止修改窗口
    this->setFixedSize(this->width(),this->height());
    ui->background_widget->setFixedSize(this->width(),this->height()/3-20);
    ui->background_widget->setAutoFillBackground(true);
    //设置背景图片
    QPalette palette;
    QPixmap pix("./images/Ra3Logo.jpg");
    pix = pix.scaled(QSize(this->width(),this->height()/3),Qt::KeepAspectRatio);
    palette.setBrush(QPalette::Background, QBrush(pix));
    ui->background_widget->setPalette(palette);
    //设置textEdit为透明色
    ui->textEdit->setStyleSheet("border: none;background-color:rgb(255, 255, 255, 60);");
    //初始化翻译器
    m_Translator = new QTranslator(this);
}

Ra3Window::~Ra3Window()
{
    delete ui;
}

//金钱生效按钮
void Ra3Window::on_pushButton_clicked()
{
    checkProcessState();
    qDebug() << "on_pushButton_clicked()";
    QString str = ui->lineEdit->text();
    int nMoney = str.toInt();
    ModifyMoney(nMoney);
}

//电力生效按钮
void Ra3Window::on_pushButton_2_clicked()
{
    checkProcessState();
    qDebug() << "on_pushButton_2_clicked";
    QString str = ui->lineEdit_2->text();
    int nElecValue = str.toInt();
    ModifyElectricity(nElecValue);
}

//策略点生效按钮
void Ra3Window::on_pushButton_3_clicked()
{
    checkProcessState();
    qDebug() << "on_pushButton_3_clicked";
    ModifyStrategy();
}

//单位大小生效按钮
void Ra3Window::on_pushButton_4_clicked()
{
    checkProcessState();
    qDebug() << "on_pushButton_4_clicked";
    float nSizeOfUnit = ui->comboBox->currentIndex();
    //单位大小设置成0单位会消失
    if(nSizeOfUnit==0) nSizeOfUnit=0.5;
    qDebug() << nSizeOfUnit<<endl;
    ModifySizeOfUnit(nSizeOfUnit);
}

//改变电力
void Ra3Window::ModifyElectricity(int nElecValue)
{
    //获取电力所在地址
    int *pElec = get3Point(g_nBaseAddr, 0x2c, 0x74, 0x4);
    //将电力修改为目标值
    //修改
    WriteProcessMemory(g_hProcess, pElec, &nElecValue, 4, NULL);
}

//修改策略值
void Ra3Window::ModifyStrategy()
{
    //获取策略所在地址
    int *pStrategy = get3Point(g_nBaseAddr, 0x2c, 0x1320, 0x2c);
    //将策略修改为目标值
    //策略值类型为float
    //4320即可策略点加满,360可以加一次策略点
    float nStrategy = 4320;
    //修改
    WriteProcessMemory(g_hProcess, pStrategy, &nStrategy, 4, NULL);
}

//修改金钱
void Ra3Window::ModifyMoney(int nMoney)
{
    //获取金钱所在地址
    int *pMoney = get4Point(g_nBaseAddr, 0x2c, 0xe4, 0x0, 0x4);
    //将金钱修改为目标值
    //修改
    WriteProcessMemory(g_hProcess, pMoney, &nMoney, 4, NULL);
}

//修改选取单位的大小
//支持选择单个单位对大小进行修改，多选会导致错乱
void Ra3Window::ModifySizeOfUnit(float nSizeOfUnit)
{
    //获取单位大小所在地址
    int *pSizeOfUnit = get3Point(g_otherBaseAddr, 0x50, 0x8, 0x25c);
    //将单位大小修改为目标值
    //修改
    WriteProcessMemory(g_hProcess, pSizeOfUnit, &nSizeOfUnit, 4, NULL);
}

//查看当前游戏进程是否打开
//初始化游戏句柄
void Ra3Window::checkProcessState()
{
    //获取游戏窗口所在进程的进程ID，也就是PID
        HWND hWnd = FindWindow(NULL, TEXT("終極動員令：紅色警戒3"));
        if (NULL == hWnd)
        {
            //qDebug()<<"查找窗口失败"<<endl;
            QMessageBox::information(this,"警告","未找到红色警戒3窗口");
        }

        DWORD dwProcessId;
        GetWindowThreadProcessId(hWnd, &dwProcessId);
        qDebug()<<"进程ID:"<<dwProcessId<<endl;

        //获取进程句柄
        g_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
        if (NULL == g_hProcess)
        {
            QMessageBox::information(this,"警告","打开红色警戒3进程失败");
        }
}

//根据基址计算出两次偏移后的地址
int* Ra3Window::get2Point(int g_nBaseAddr, int p1, int p2)
{
    int iBase, iP1, *iP2;
    if (!ReadProcessMemory(g_hProcess, (LPVOID)g_nBaseAddr, &iBase, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iBase + p1), &iP1, 4, NULL))
    {
        return NULL;
    }

    //返回最终地址
    iP2 = (int *)(iP1 + p2);
    return iP2;
}

//根据基址计算出三次偏移后的地址
int* Ra3Window::get3Point(int g_nBaseAddr, int p1, int p2, int p3)
{
    int iBase, iP1, iP2, *iP3;

    if (!ReadProcessMemory(g_hProcess, (LPVOID)g_nBaseAddr, &iBase, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iBase + p1), &iP1, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iP1 + p2), &iP2, 4, NULL))
    {
        return NULL;
    }
    iP3 = (int *)(iP2 + p3);
    return iP3;
}

//根据基址计算出四次偏移后的地址
int* Ra3Window::get4Point(int g_nBaseAddr, int p1, int p2, int p3, int p4)
{
    int iBase, iP1, iP2, iP3, *iP4;

    if (!ReadProcessMemory(g_hProcess, (LPVOID)g_nBaseAddr, &iBase, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iBase + p1), &iP1, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iP1 + p2), &iP2, 4, NULL))
    {
        return NULL;
    }

    if (!ReadProcessMemory(g_hProcess, (LPVOID)(iP2 + p3), &iP3, 4, NULL))
    {
        return NULL;
    }
    iP4 = (int *)(iP3 + p4);
    return iP4;
}

//监控语言comboBox改变状态
void Ra3Window::changeEvent(QEvent *e)
{
    switch(e->type())
    {
    case QEvent::LanguageChange:
        qDebug()<<ui->comboBox_2->currentIndex()<<endl;
        for(int i=0;i<3;i++){
            if(ui->comboBox_2->currentIndex() == i)
            {
                ui->comboBox_2->setCurrentIndex(i);
            }
        }
        break;
    default:
        break;
    }

    retranslateUi(this);
}

//语言comboBox触发
void Ra3Window::on_comboBox_2_activated(int index)
{
    switch(index)
    {
        case 0:
            m_Translator->load("./Translate_CN.qm");
            break;
        case 1:
            m_Translator->load("./Translate_EN.qm");
            break;
        case 2:
            m_Translator->load("./Translate_DE.qm");
            break;
        default :
            break;
    }
    qApp->installTranslator(m_Translator);
}

//重写retranslateUi
//注释掉语言comboBox清空，修复语言状态错乱（只显示简体中文）
//不建议直接修改源码，复制出来重写
void Ra3Window::retranslateUi(QMainWindow *Ra3Window)
{
    Ra3Window->setWindowTitle(QApplication::translate("Ra3Window", "Ra3Window", Q_NULLPTR));
    ui->label_3->setText(QApplication::translate("Ra3Window", "\347\255\226\347\225\245\345\212\240\346\273\241", Q_NULLPTR));
    ui->pushButton_3->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
    ui->label_4->setText(QApplication::translate("Ra3Window", "\351\200\211\345\217\226\345\215\225\344\275\215", Q_NULLPTR));
    ui->comboBox->clear();
    ui->comboBox->insertItems(0, QStringList()
     << QApplication::translate("Ra3Window", "\345\260\217", Q_NULLPTR)
     << QApplication::translate("Ra3Window", "\346\240\207\345\207\206", Q_NULLPTR)
     << QApplication::translate("Ra3Window", "\345\244\247", Q_NULLPTR)
    );
    ui->pushButton_4->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
    ui->textEdit->setHtml(QApplication::translate("Ra3Window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
    ui->label_5->setText(QApplication::translate("Ra3Window", "\350\257\255\350\250\200", Q_NULLPTR));
//    ui->comboBox_2->clear();
//    ui->comboBox_2->insertItems(0, QStringList()
//     << QApplication::translate("Ra3Window", "\347\256\200\344\275\223\344\270\255\346\226\207", Q_NULLPTR)
//     << QApplication::translate("Ra3Window", "\350\213\261\350\257\255", Q_NULLPTR)
//     << QApplication::translate("Ra3Window", "\345\276\267\350\257\255", Q_NULLPTR)
//    );
    ui->lineEdit->setPlaceholderText(QApplication::translate("Ra3Window", "\350\276\223\345\205\245\351\207\221\351\222\261\346\225\260\351\242\235", Q_NULLPTR));
    ui->label->setText(QApplication::translate("Ra3Window", "\351\207\221\351\222\261", Q_NULLPTR));
    ui->pushButton->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
    ui->label_2->setText(QApplication::translate("Ra3Window", "\347\224\265\345\212\233", Q_NULLPTR));
    ui->lineEdit_2->setPlaceholderText(QApplication::translate("Ra3Window", "\350\276\223\345\205\245\347\224\265\345\212\233\345\200\274", Q_NULLPTR));
    ui->pushButton_2->setText(QApplication::translate("Ra3Window", "\347\253\213\345\215\263\347\224\237\346\225\210", Q_NULLPTR));
} // retranslateUi



