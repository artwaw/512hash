#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clipboard = QGuiApplication::clipboard();
    ui->hashLine->setEnabled(false);
    connect(ui->copyBtn,&QPushButton::clicked,this,&MainWindow::copyHash);
    connect(ui->pasteBtn,&QPushButton::clicked,this,&MainWindow::pastePwd);
    connect(ui->genPassBtn,&QPushButton::clicked,this,&MainWindow::genPwd);
    connect(ui->makeHashBtn,&QPushButton::clicked,this,&MainWindow::makeHash);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::copyHash() {
    clipboard->setText(ui->hashLine->text());
}

void MainWindow::pastePwd() {
    ui->passLine->setText(clipboard->text());
}

void MainWindow::genPwd() {
    ui->passLine->setText(crypto.generateRndStr(ui->passCharCount->value()));
}

void MainWindow::makeHash() {
    ui->hashLine->setText(crypto.getHash(ui->passLine->text().toUtf8()).toBase64());
    crypto.reset();
}
