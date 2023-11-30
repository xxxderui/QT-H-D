#include "figure.h"
#include "ui_figure.h"
#include "mainwindow.h"

figure::figure(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::figure)
{
    ui->setupUi(this);
}

figure::~figure()
{
    delete ui;
}

bool prime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    for (int i = 2; i <sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }
    return true;
}

void figure::on_pushButton_clicked()
{
    QString text1= ui->lineEdit->text();
    QString text2= ui->lineEdit_2->text();
    QString text3= ui->lineEdit_3->text();
    QString text4= ui->lineEdit_4->text();
    if(text1.length()==0)
    {
        QMessageBox::information(NULL, "错误", "你未输入原根g", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        if(text1.toInt()==0)
        {
            QMessageBox::information(NULL, "错误", "你输入的素数p不是数字", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        else
        {
            if(text2.length()==0)
            {
                QMessageBox::information(NULL, "错误", "你未输入素数p", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                if(text2.toInt()==0)
                {
                    QMessageBox::information(NULL, "错误", "你输入的素数p不是数字", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                }
                else
                {
                    if(!prime(text2.toInt()))
                    {
                        QMessageBox::information(NULL, "错误", "你输入的素数p不是素数", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                    }
                    else
                    {
                        if(text3.toInt()==0)
                        {
                            QMessageBox::information(NULL, "错误", "你输入的私钥a不是数字", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                        }
                        else
                        {
                            if(text4.toInt()==0)
                            {
                                QMessageBox::information(NULL, "错误", "你输入的私钥b不是数字", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                            }
                            else
                            {
                                int g=text1.toInt();
                                int p=text2.toInt();
                                int a=text3.toInt();
                                int b=text4.toInt();
                                int A=fmod(pow(g, a), p);
                                int B=fmod(pow(g, b), p);
                                int S1=fmod(pow(B, a), p);
                                int S2=fmod(pow(A, b), p);
                                ui->lineEdit_5->setText(QString::number(A));
                                ui->lineEdit_6->setText(QString::number(B));
                                ui->lineEdit_7->setText(QString::number(S1));
                                ui->lineEdit_8->setText(QString::number(S2));
                                if(S1==S2)
                                {
                                    QMessageBox::information(NULL, "验证成功", "客户端和服务端计算的公钥相同", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                                }
                                else
                                {
                                    QMessageBox::information(NULL, "验证失败", "客户端和服务端计算的公钥不相同", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void figure::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(e->x()>840&&e->x()<840+110&&e->y()>10&&e->y()<10+60)
        {
            this->close();
            MainWindow *f=new MainWindow();
            f->show();
        }
    }
}
