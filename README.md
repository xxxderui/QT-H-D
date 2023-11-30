# QT-H-D
基于QT的H-D密钥交换交互界面
Mainwindow窗口进入一个欢迎界面，设置自动播放背景音乐
#include "mainwindow.h"
#include <QApplication>

QSound *sound= new QSound(":/backmusic2.wav");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    sound->setLoops(100);
    sound->play();
    w.show();
    return a.exec();
}
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/dc6d8090-d5a1-42c7-a285-f35b0646a153)

点击主程序窗口的进入，则跳转到D-H密钥交换窗口
点击退出，则退出程序
进入密钥交换窗口：
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/7c174467-0e4d-42e1-85d6-577c1b2c3420)

首先需要输入双方协定好的原根g和素数p
点击开始计算会逐一检验输入的合法性（没有输入则会显示你未输入某某）
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/b13f101d-8657-4392-b57c-c3d8285c4efb)

若输入的不是数字也会显示输入不是数字
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/744126e5-1a54-4374-864e-f373fd198353)

若输入的素数并非素数也会判断为你输入的不是素数
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/4ec4e8ff-667c-4d30-8da2-18ee1be6de18)

私钥同理
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/08a84ba0-7e79-49f6-b001-323a30b9a69a)

Step1一开始需要输入双方协定好的原根g和素数p以及双方的私钥a和b
Step2客户端根据私钥a以及双方协定好的原根g和素数p，对a进行幂模运算得到公钥A计算公式如下 
Step3客户端将公钥A发送给服务端
Step4客户端根据私钥b以及双方协定好的原根g和素数p，对b进行幂模运算得到公钥B计算公式如下 
Step5服务端将公钥B发送给客户端
Step6双方知道A和B的情况下分别计算公钥S1，S2
客户端已知：g、p、A、B、a  
服务端已知：g、p、A、B、b  
若计算出的S1等于S2则验证成功双方计算的公钥相同
计算前：
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/dcb64150-21a9-4bd9-8a5c-8acf3fa1b706)

计算后：
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/32e0e870-68c0-4819-8f43-a3e580524072)

更换不同参数验证：
 ![image](https://github.com/xxxderui/QT-H-D/assets/126744071/5daa2bea-75e6-4c20-bb04-9714c05a7a1c)

由于由A逆推a、B逆推b的难度很大很好的完成了公钥交换的任务
