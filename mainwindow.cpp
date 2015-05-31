#include<iostream>
/*
#include <iomanip>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include <QKeyEvent>
#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
    ui->label_1->setPixmap(QPixmap(":/2.png"));
  ui->label_2->setPixmap(QPixmap(":/tie.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
using namespace std;
int pane[4][4]; //棋盘
int N=1; //2的n次方


void newgame() //遊戲開始
{
 N=1;
 for(int i=0;i<=3;i++) //重新排
 for(int j=0;j<=3;j++)
 pane[i][j]=0;
 srand( (unsigned)time( NULL ) );
 int m=rand()%4;
 int n=rand()%4;
 int p=rand()%4;
 int q=rand()%4;
 pane[m][n]=pane[p][q]=2;

}
int if2n(int x) //判斷x是否2的整數次方
{
 int flag=0;
 for(int n=1;n<=11;n++)
 {
 if(x==pow(2,n))
 {
 flag=1;
 if(n>N)
 N=n;
 return flag;
 }
 }
 return flag;
}
int upmove() //往上家
{
 int flag=0;
 for(int j=0;j<=3;j++)
 for(int i=0;i<3;i++)
 {
 if(if2n(pane[i][j]+pane[i+1][j])==1)
 {
 pane[i][j]=pane[i][j]+pane[i+1][j];
 pane[i+1][j]=0;
 flag=1;
 }
 }
 return flag;
}
int downmove() //往下加
{
 int flag=0;
 for(int j=0;j<=3;j++)
 for(int i=3;i>0;i--)
 {
 if(if2n(pane[i][j]+pane[i-1][j])==1)
 {
 pane[i][j]=pane[i][j]+pane[i-1][j];
 pane[i-1][j]=0;
 flag=1;
 }
 }
 return flag;
}
int leftmove() //往左加
{
 int flag=0;
 for(int i=0;i<=3;i++)
 for(int j=0;j<3;j++)
 {
 if(if2n(pane[i][j]+pane[i][j+1])==1)
 {
 pane[i][j]=pane[i][j]+pane[i][j+1];
 pane[i][j+1]=0;
 flag=1;
 }
 }
 return flag;
}
int rightmove() //往右加
{
 int flag=0;
 for(int i=0;i<=3;i++)
 for(int j=3;j>0;j--)
 {
 if(if2n(pane[i][j]+pane[i][j-1])==1)
 {
 pane[i][j]=pane[i][j]+pane[i][j-1];
 pane[i][j-1]=0;
 flag=1;
 }
 }
 return flag;
}
int testup() //能否上移
{
 int flag=0;
 for(int j=0;j<=3;j++)
 for(int i=0;i<3;i++)
 {
 if(if2n(pane[i][j]+pane[i+1][j])==1)
 {
 flag=1;
 }
 }
 return flag;
}
int testdown() //能否下移
{
 int flag=0;
 for(int j=0;j<=3;j++)
 for(int i=3;i>0;i--)
 {
 if(if2n(pane[i][j]+pane[i-1][j])==1)
 {
 flag=1;
 }
 }
 return flag;
}
int testleft() //能否左移
{
 int flag=0;
 for(int i=0;i<=3;i++)
 for(int j=0;j<3;j++)
 {
 if(if2n(pane[i][j]+pane[i][j+1])==1)
 {
 flag=1;
 }
 }
 return flag;
}
int testright() //能否右移
{
 int flag=0;
 for(int i=0;i<=3;i++)
 for(int j=3;j>0;j--)
 {
 if(if2n(pane[i][j]+pane[i][j-1])==1)
 {
 flag=1;
 }
 }
 return flag;
}
int panemax() //棋盤最多情況
{
 int max=pane[0][0];
 for(int i=0;i<=3;i++)
 for(int j=0;j<=3;j++)
 if(pane[i][j]>max)
 max=pane[i][j];
 return max;
}
int ifwin() //判斷勝利
{
 int flag=0;
 if(panemax()==2048)
 {
 cout<<setw(45)<<"You Win!"<<endl;
 flag=1;
 }
 return flag;
}
int ifGameOver() //判斷遊戲結時候
{
 int flag=0;
 if(testup()+ testdown() + testleft() + testright() ==0)
 {
 flag=1;
 }
 return flag;
}
void addnewnumberup() //往上時＋新的數
{
 srand( (unsigned)time( NULL ) );
 int n;
 if(N==1)
 n=1;
 else
 n=(rand()%(N)+1);
 int newnumber=pow(2,n);
 for(int i=3;i>=0;i--)
 for(int j=0;j<=3;j++)
 if(pane[i][j]==0)
 {
 pane[i][j]=newnumber;
 return;
 }
}
void addnewnumberdown() //往下＋新的數
{
 srand( (unsigned)time( NULL ) );
 int n;
 if(N==1)
 n=1;
 else
 n=(rand()%(N)+1); int newnumber=pow(2,n);
 for(int i=0;i<=3;i++)
 for(int j=0;j<=3;j++)
 if(pane[i][j]==0)
 {
 pane[i][j]=newnumber;
 return;
 }
}
void addnewnumberleft() //往左＋新的數
{
 srand( (unsigned)time( NULL ) );
 int n;
 if(N==1)
 n=1;
 else
 n=(rand()%(N)+1);
 int newnumber=pow(2,n);
 for(int j=3;j>=0;j--)
 for(int i=0;i<=3;i++)
 if(pane[i][j]==0)
 {
 pane[i][j]=newnumber;
 return;
 }
}
void addnewnumberright() //往右＋新的數
{
 srand( (unsigned)time( NULL ) );
 int n;
 if(N==1)
 n=1;
 else
 n=(rand()%(N)+1);
 int newnumber=pow(2,n);
 for(int j=0;j<=3;j++)
 for(int i=0;i<=3;i++)
 if(pane[i][j]==0)
 {
 pane[i][j]=newnumber;
 return;
 }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
 {

   if(event->key() == Qt::Key_Left){
        leftmove();
        addnewnumberleft();
        system("cls");
        }
   else if(event->key() == Qt::Key_Up){
        upmove();
        addnewnumberup();
        system("cls");;
   }
   else if(event->key() == Qt::Key_Right){
        rightmove();
        addnewnumberright();
        system("cls");
       }
   else if(event->key() == Qt::Key_Down){
        downmove();
        addnewnumberdown();
        system("cls");
       }

   }
void MainWindow::print()
   {    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
        if(pane[i][j]==2)
        {ui->label_1->setPixmap(QPixmap(":/new/prefix1/2.png"));}
       else if (pane[i][j]==4)
        {ui->label_1->setPixmap(QPixmap(":/new/prefix1/4.png"));}
       else if (pane[i][j]==8)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/8.png"));}
       else if (pane[i][j]==16)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/16.png"));}
        else if (pane[i][j]==32)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/32.png"));}
        else if (pane[i][j]==64)
        {ui->label_1->setPixmap(QPixmap(":/new/prefix1/64.png"));}
        else if (pane[i][j]==128)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/128.png"));}
        else if (pane[i][j]==256)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/256.png"));}
        else if (pane[i][j]==512)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/512.png"));}
        else if (pane[i][j]==1024)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/1024.png"));}
        else if (pane[i][j]==2048)
         {ui->label_1->setPixmap(QPixmap(":/new/prefix1/2048.png"));}
}
    */
   int main() //主函数
{
/*
 int makesure=1;

 while(makesure)
 {
 system("cls");
 newgame();
 while(ifwin()+ifGameOver()==0)
 {
    break;
     }
 }
 */
}


/*
void MainWindow::on_pushButton_clicked()
{
    emit newgame ();
}

*/
