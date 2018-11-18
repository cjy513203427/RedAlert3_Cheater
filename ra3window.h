#ifndef RA3WINDOW_H
#define RA3WINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QDebug>
#include <QWidget>
#include <Windows.h>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTranslator>
#include <QEvent>
/*
    作者：Jonas
    时间：2018/11/18
*/
namespace Ui {
class Ra3Window;
}

class Ra3Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ra3Window(QWidget *parent = 0);
    ~Ra3Window();
    //根据基址计算出两次偏移后的地址
    int *get2Point(int g_nBaseAddr, int p1, int p2);
    //根据基址计算出三次偏移后的地址
    int *get3Point(int g_nBaseAddr, int p1, int p2, int p3);
    //根据基址计算出四次偏移后的地址
    int *get4Point(int g_nBaseAddr, int p1, int p2, int p3, int p4);
    //改变电力
    void ModifyElectricity(int nElecValue);
    //修改策略值
    void ModifyStrategy();
    //修改金钱
    void ModifyMoney(int nElecMoney);
    //修改选取单位的大小
    //支持选择单个单位对大小进行修改，多选会导致错乱
    void ModifySizeOfUnit(float ModifySizeOfUnit);
    //查看当前游戏进程是否打开
    //初始化游戏句柄
    void checkProcessState();
private slots:
    //金钱生效按钮
    void on_pushButton_clicked();
    //电力生效按钮
    void on_pushButton_2_clicked();
    //策略点生效按钮
    void on_pushButton_3_clicked();
    //单位大小生效按钮
    void on_pushButton_4_clicked();
    //监控语言comboBox改变状态
    void changeEvent(QEvent *e);
    //语言comboBox触发函数
    void on_comboBox_2_activated(int index);
    //重写retranslateUi
    //注释掉语言comboBox清空，修复语言状态错乱（只显示简体中文）
    //不建议直接修改源码，复制出来重写
    void retranslateUi(QMainWindow *Ra3Window);
private:
    Ui::Ra3Window *ui;
    //游戏基址1
    int g_nBaseAddr = 0x00DFBD74;
    //游戏基址2
    int g_otherBaseAddr = 0x00DEEA3C;
    //游戏句柄
    HANDLE g_hProcess;
    //翻译组件
    QTranslator *m_Translator;
};

#endif // RA3WINDOW_H
