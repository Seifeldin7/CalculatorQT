#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <string>
#include <iostream>
#include <QVBoxLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *entry;
    QPushButton *btns[10];
    QPushButton *addBtn;
    QPushButton *subBtn;
    QPushButton *mulBtn;
    QPushButton *divBtn;
    QPushButton *clrBtn;
    QPushButton *eqlBtn;
    QGridLayout * grid;
    QVBoxLayout * verLayout;
    QWidget *centralWidget;
    int firstNum;
    int secondNum;
    int res;
    bool isAdd;
    bool isSub;
    bool isMul;
    bool isDiv;

 private slots:
    void btnNoPressed();
    void btnEqlPressed();
    void btnClrPressed();
    void btnOpPressed();
};

#endif // MAINWINDOW_H
