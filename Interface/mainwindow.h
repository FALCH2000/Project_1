#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QFileDialog>
#include <QSlider>
#include "memoryusage.h"
#include "memoryusage.h"
#include "table_model.h"
#include <QThread>
#include <QLabel>
#include <QLCDNumber>
#include <QTableView>
#include <QScrollBar>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableViewVerticalSlider_released();

    void on_PlayButton_clicked();

    void on_StopButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QSlider* slider;
    void setInterfaceStyle();
    MemoryUsage* memoryUsage;
    QString qstr;
    Table_Model *myModel;
    QTableView *tableview;
    int counter=0;
};
#endif // MAINWINDOW_H
