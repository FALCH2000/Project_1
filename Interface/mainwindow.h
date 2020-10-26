#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QFileDialog>
#include <QSlider>
#include "memoryusage.h"

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


    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QSlider* slider;
    void setInterfaceStyle();
    MemoryUsage* memoryUsage;


};
#endif // MAINWINDOW_H
