#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include<QTimer>
#include "cronometro.h"
#include "estaciones.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reset();
    void crearmatriz();


private slots:
    void on_pushButton_2_clicked();
    void movercronometro();
    void on_pushButton_clicked();

private:
    int filas;
    int columnas;
    Ui::MainWindow *ui;
    QPushButton *** botones;
    QTimer* timer;
    Cronometro* tiempo;
    QPushButton **aux;
    Estaciones estaciones;

};
#endif // MAINWINDOW_H
