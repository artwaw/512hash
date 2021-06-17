#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include <QPushButton>
#include "cryptoclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CryptoClass crypto;
    QClipboard *clipboard;

private slots:
    void copyHash();
    void pastePwd();
    void genPwd();
    void makeHash();
};
#endif // MAINWINDOW_H
