#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    grid = new QGridLayout();
    verLayout = new QVBoxLayout(this);
    centralWidget = new QWidget(this);
    entry = new QLineEdit();
    entry->setText("0");
    verLayout->addWidget(entry);
    verLayout->addLayout(grid);
    centralWidget->setLayout(verLayout);
    this->setCentralWidget(centralWidget);
    this->setGeometry(400,400,400,400);
    int i;
    for(i=0;i<10;i++){
        btns[i] = new QPushButton(QString::number(i));
        connect(btns[i],SIGNAL(clicked()),this,SLOT(btnNoPressed( )));
        grid->addWidget(btns[i],i/3,i%3);
    }
    addBtn = new QPushButton("+");
    grid->addWidget(addBtn,3,1);
    subBtn = new QPushButton("-");
    grid->addWidget(subBtn,3,2);
    mulBtn = new QPushButton("*");
    grid->addWidget(mulBtn,4,0);
    divBtn = new QPushButton("/");
    grid->addWidget(divBtn,4,1);
    clrBtn = new QPushButton("C");
    grid->addWidget(clrBtn,4,2);
    eqlBtn = new QPushButton("=");
    grid->addWidget(eqlBtn,5,2);
    connect(mulBtn,SIGNAL(clicked()),this,SLOT(btnOpPressed( )));
    connect(addBtn,SIGNAL(clicked()),this,SLOT(btnOpPressed( )));
    connect(subBtn,SIGNAL(clicked()),this,SLOT(btnOpPressed( )));
    connect(divBtn,SIGNAL(clicked()),this,SLOT(btnOpPressed( )));
    connect(eqlBtn,SIGNAL(clicked()),this,SLOT(btnEqlPressed( )));
    connect(clrBtn,SIGNAL(clicked()),this,SLOT(btnClrPressed( )));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::btnNoPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString val = button->text();
    if(QString::compare(entry->text(),"0",Qt::CaseInsensitive) == 0)
    {
         entry->setText(val);
    }
    else
    {
        entry->setText(entry->text()+val);
    }


}
void MainWindow::btnOpPressed()
{
    firstNum = (entry->text()).toInt();
    entry->setText("0");
    isAdd = false;
    isSub = false;
    isDiv = false;
    isMul = false;
    QPushButton *button = (QPushButton *)sender();
    QString val = button->text();
    if(QString::compare(val,"+",Qt::CaseInsensitive) == 0)
    {
        isAdd = true;
    }
    else if(QString::compare(val,"-",Qt::CaseInsensitive) == 0)
    {
        isSub = true;
    }
    else if(QString::compare(val,"*",Qt::CaseInsensitive) == 0)
    {
        isMul = true;
    }
    else if(QString::compare(val,"/",Qt::CaseInsensitive) == 0)
    {
        isDiv = true;
    }
}
void MainWindow::btnClrPressed()
{
    entry->setText("0");
    res=0;
    firstNum = 0;
    secondNum = 0;
}
void MainWindow::btnEqlPressed()
{
    secondNum = (entry->text()).toInt();
    if(isMul)
    {
        res = firstNum*secondNum;
    }
    else if(isSub)
    {
         res = firstNum-secondNum;
    }
    else if(isAdd)
    {
         res = firstNum+secondNum;
    }
    else if(isDiv)
    {
         res = firstNum/secondNum;
    }
    entry->setText(QString::number(res));
}
