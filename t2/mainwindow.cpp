#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(aumentartiempo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearjuego()
{
    this->filas=this->ui->spinBox_filas->value();
    this->columnas=this->ui->spinBox_columnas->value();
    this->botones = new QPushButton**[filas];

    for (int i = 0; i< filas; i++) {
        this->botones[i] = new QPushButton*[columnas];
        for(int j =0; j < columnas; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");

            this->ui->gridLayout_2->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                this->botones[i][j]->setText(".");
            } );
        }
    }
}

void MainWindow::cerrarjuego()
{
    this->ui->pushButton->setEnabled(true);

    for (int i = 0; i< filas; i++) {
        delete [] this->botones[i];
    }
    delete [] this->botones;
    reset();

    this->matriz.borrarmatrizocupado(filas,columnas);
    this->estaciones.borrarmatrienteros(filas,columnas);
    this->estaciones.borrarmatrizbool(filas,columnas);
}



void MainWindow::reset()
{
    this->ui->lcdNumber->display(cronometro.get_tiempo());
}


void MainWindow::on_pushButton_clicked()
{
    this->ui->pushButton->setEnabled(false);
    this->timer.start(1000);
    crearjuego();
    this->matriz.setmatrizocupado(filas,columnas);
    this->estaciones.setmatrizbool(filas,columnas);
    this->estaciones.copiarocupado(this->matriz);
    this->estaciones.setmatrizenteros(filas,columnas);
    this->estaciones.crearestaciones(filas,columnas,botones);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->timer.stop();
    this->cronometro.setreset();
    reset();
    cerrarjuego();
}

void MainWindow::aumentartiempo()
{
    if(this->cronometro.get_tiempo()<10){
        this->cronometro.setaumentar();
        reset();
    }else{

        QMessageBox::information(this,"perdiste","perdiste");
        on_pushButton_2_clicked();
    }
}



