#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setInterfaceStyle();

    player= new QMediaPlayer(this);
    slider= ui->horizontalSlider;
    memoryUsage= new MemoryUsage;
    myModel= new Table_Model;
    tableview = ui->tableView;

    ui->Memory_Label->setText(memoryUsage->getValue());

    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::positionChanged, memoryUsage, &MemoryUsage::getValue);
    connect(memoryUsage, &MemoryUsage::valueChanged, ui->Memory_Label, &QLabel::setText);

    //connection that indicates when the tableview is clicked
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(on_tableView_clicked(const QModelIndex &)));

    //connect the tableview vertical slider with the slot
    connect(tableview->verticalScrollBar(), SIGNAL(sliderReleased()), this, SLOT(on_tableViewVerticalSlider_released()));

}

void MainWindow::setInterfaceStyle(){
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #0B253A, stop:0.5 #1A344B, stop:1 #61717E);");
    ui->frame_2->setStyleSheet("background-color: #0B253A");
    ui->SongsView_Button->setStyleSheet("background-color: #61717E; border-style: outset; border-width: 2px; border-radius: 10px;font: bold 14px; min-width: 10em; padding: 6px;");
    ui->pushButton->setStyleSheet("background-color: #61717E; border-style: outset;  border-radius: 10px;font: bold 14px; min-width: 10em; padding: 6px;");
    ui->tableView->setStyleSheet("background-color: white");
    ui->listView->setStyleSheet("background-color: white");
    ui->label->setStyleSheet("color: white");
    ui->Memory_Label->setStyleSheet("color: white");
    ui->checkBox->setStyleSheet("color: white");

    QPixmap pixmap_1(":/images/relicons/PlayButton_");
    QIcon ButtonIcon_1(pixmap_1);
    ui->PlayButton->setIcon(ButtonIcon_1);
    ui->PlayButton->setIconSize(QSize(30, 30));
    ui->PlayButton->setStyleSheet("background-color: Transparent;border-style: outset;");

    QPixmap pixmap_2(":/images/relicons/StopButton_");
    QIcon ButtonIcon_2(pixmap_2);
    ui->StopButton->setIcon(ButtonIcon_2);
    ui->StopButton->setIconSize(QSize(30, 30));
    ui->StopButton->setStyleSheet("background-color: Transparent;border-style: outset;");


    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(303);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    player->destroyed();

    if(index.isValid()){ //obtener el url del índice index de la lista que despliega el table_model
        int rowPosition= index.row();

        QString cellText= this->myModel->getUrl(rowPosition);
        player->setMedia(QUrl::fromLocalFile(cellText));
        player->play();
    }
}

void MainWindow::on_tableViewVerticalSlider_released(){

    int counter_2= counter + 80;

    //------- Sume to the counter
    if(tableview->verticalScrollBar()->sliderPosition() == tableview->verticalScrollBar()->maximum() && counter<7938){
        myModel->resetModel();
        counter += 81;
        counter_2 +=81;
        if(counter>=7938){ //it's the maximun of the list
            int counter_2=8000;
            myModel->chargeSongs(counter,counter_2);
        } else{
            myModel->chargeSongs(counter,counter_2);
    }

    } //------ Rest to the counter
    else if(tableview->verticalScrollBar()->sliderPosition()==0 && counter>0){
        myModel->resetModel();
        counter -= 81;
        counter_2 -= 81;
        myModel->chargeSongs(counter,counter_2);
    }

}

void MainWindow::on_pushButton_clicked()
{
    //QString filename= QFileDialog::getOpenFileName(this, "Open a File","","Song File (*.mp3)");
    //on_actionStop_triggered();
    //player->setMedia(QUrl::fromLocalFile(filename));
    //player->setVolume(50);
    myModel->chargeSongs(0,80);
    ui->tableView->setModel(myModel);

}

void MainWindow::on_PlayButton_clicked()
{
    player->play();
}

void MainWindow::on_StopButton_clicked()
{
    player->pause();
}
