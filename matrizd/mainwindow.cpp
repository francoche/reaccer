#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*int cant = 10;
    this->botones = new QPushButton**[cant];
    for (int i = 0; i< cant; i++) {
        this->botones[i] = new QPushButton*[cant];
        for(int j =0; j < cant; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");

            this->ui->gridLayout->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                this->botones[i][j]->setText(".");
            } );
        }
    }*/
    this->tiempo = new Cronometro();
    this->timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movercronometro()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::crearmatriz()
{
    int f=this->ui->spinBoxf->value();
    int c=this->ui->spinBoxc->value();

    this->botones = new QPushButton**[f];

    for (int i = 0; i< f; i++) {
        this->botones[i] = new QPushButton*[c];
        for(int j =0; j < c; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");

            this->ui->gridLayout->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                this->botones[i][j]->setText(".");
            } );
        }
    }
    this->filas=f;
    this->columnas=c;

    this->estaciones.crearmatriz(f,c);
    this->estaciones.crearestaciones(f,c,this->botones);



}



void MainWindow::on_pushButton_2_clicked()
{
    if (!this->timer->isActive()) {
        this->timer->start(1000);
    }
    crearmatriz();
    this->ui->pushButton_2->setEnabled(false);



}

void MainWindow::movercronometro()
{
    this->tiempo->aumentar();
    this->ui->lcdNumber->display(this->tiempo->get_seg());
    if(tiempo->get_seg()>9){
        QMessageBox::information(this,"perdiste","perdiste");
        on_pushButton_clicked();

    }
}


void MainWindow::on_pushButton_clicked()
{
    timer->stop();
    this->tiempo->reset();
    this->ui->lcdNumber->display(this->tiempo->get_seg());
    for(int i=0;i<filas;i++){
        delete [] botones[i];
    }
    delete [] botones;
    this->estaciones.borrarmatriz(filas,columnas);
    this->ui->pushButton_2->setEnabled(true);

}

