#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QLineEdit>
#include <QDebug>
#include <QFileInfoList>
#include <QFileInfo>
#include <QStringList>
#include <QList>
#include <QHBoxLayout>
#include <QFile>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_actionClear_All_triggered();

    void on_actionRename_All_triggered();

private:
    Ui::MainWindow *ui;
    QDir *dir;
    QLineEdit *linie[200];
    QHBoxLayout *layout;
    int erstellt;
    QFileInfoList list;
};

#endif // MAINWINDOW_H
