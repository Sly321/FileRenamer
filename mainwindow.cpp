#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setVisible(false);
    erstellt = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString sDirectory = ui->lineEdit->text();
    ui->textEdit->clear();
    erstellt = 0;
    if(QDir().isAbsolutePath(sDirectory)) {
        qDebug() << sDirectory << "- Filepath geladen.";
        dir = new QDir(sDirectory);
        list = dir->entryInfoList();
        erstellt = 0;
        for (QFileInfoList::Iterator ite = list.begin() + 2; ite != list.end(); ite++) {
            if(ite[0].isDir()) {
                QString content = ui->textEdit->toPlainText();
                ui->textEdit->setText(content + ite[0].fileName() + "\n");
            } else {
                QString content = ui->textEdit->toPlainText();
                ui->textEdit->setText(content + ite[0].fileName() + "\n");
            }
            erstellt++;
        }
        QString a = QString::number(erstellt) + " items";
        statusBar()->showMessage(a);
    } else {
        qDebug() << sDirectory << "ist kein gültiger Filepath.";
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionClear_All_triggered()
{
    ui->textEdit->clear();
    list.clear();
    erstellt = 0;
    statusBar()->showMessage("Files unloaded");
}

void MainWindow::on_actionRename_All_triggered()
{
    /*
    int i = 0;
    for (QFileInfoList::Iterator ite = list.begin() + 2; ite != list.end(); ite++) {

        qDebug() << "File Path" << ite[0].absoluteFilePath();
        qDebug() << "Name der neuen" << linie[i]->text();
        qDebug() << "Directory" << ite[0].dir().absolutePath();

        QString copyDirectory = ite[0].dir().absolutePath() + "/copy/";
        QString newName = linie[i]->text();
        QString oldName = ite[0].fileName();

        if(newName != oldName) {
            if(ite[0].isDir()) {

            } else {
                QFile file(ite[0].absoluteFilePath());
                dir->mkdir(copyDirectory);
                file.copy(copyDirectory + newName);
                file.close();
            }
        }
        i++;
    }*/
    if(list.size() > 2) {
        int i = 0;
        for (QFileInfoList::Iterator ite = list.begin() + 2; ite != list.end(); ite++) {
            QString copyDirectory = ite[0].dir().absolutePath() + "/copy/";

            QString text = ui->textEdit->toPlainText();

            QStringList stList = text.split(QRegExp("[\n]"), QString::SkipEmptyParts);
            QString newName = stList[i];
            QString oldName = ite[0].fileName();

            if(newName != oldName) {
                if(ite[0].isDir()) {

                } else {
                    QFile file(ite[0].absoluteFilePath());
                    dir->mkdir(copyDirectory);
                    file.copy(copyDirectory + newName);
                    file.close();
                }
            }
            i++;
        }
    }
}
