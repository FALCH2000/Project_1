#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color: #1D1E2C");
    ui->listView->setStyleSheet("background-color: #0B253A");

    player= new QMediaPlayer(this);
    slider= ui->horizontalSlider;
    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_actionStop_triggered()
{
    player->pause();
}

void MainWindow::on_actionNext_triggered()
{

}

void MainWindow::on_actionPrevious_triggered()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, "Open a File","","Song File (*.mp3)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));
    player->setVolume(50);

}
