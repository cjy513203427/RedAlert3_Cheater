#include "ra3window.h"
#include "ui_ra3window.h"
Ra3Window::Ra3Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ra3Window)
{
    ui->setupUi(this);

    qDebug() <<"长度"<<this->width()<<"宽度"<< this->height();//2
    ui->background_widget->setFixedSize(this->width(),this->height()/3-20);
    ui->background_widget->setAutoFillBackground(true);
    //设置背景图片
    QPalette palette;
    QPixmap pix("./images/Ra3Logo.jpg");
    pix = pix.scaled(QSize(this->width(),this->height()/3),Qt::KeepAspectRatio);
    palette.setBrush(QPalette::Background, QBrush(pix));
    ui->background_widget->setPalette(palette);
    //设置下拉框comboBox
    ui->comboBox->insertItem(1,"小","0.5");
    ui->comboBox->insertItem(2,"标准","1");
    ui->comboBox->insertItem(3,"大","2");
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
    qDebug() << "on_pushButton_4_clicked"; //abc
    QVariant data = ui->comboBox->currentData(); //apple
    qDebug() << data.toFloat()<<endl;
    float nSizeOfUnit = data.toFloat();
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
    //float nSizeOfUnit = 2;
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


void Ra3Window::on_comboBox_2_activated(int index)
{
    switch(index)
    {
        case 0:
            m_Translator->load("E:/QT_project/RA3_Cheat/Translate_CN.qm");
            break;
        case 1:
            m_Translator->load("E:/QT_project/RA3_Cheat/Translate_EN.qm");
            break;
        case 2:
            m_Translator->load("E:/QT_project/RA3_Cheat/Translate_DE.qm");
            break;
        default :
            break;
    }
    qApp->installTranslator(m_Translator);
    ui->retranslateUi(this);
}
