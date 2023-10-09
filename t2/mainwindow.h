#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include<QTimer>
#include "cronometro.h"
#include "estaciones.h"
#include<QPushButton>
#include "camino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearjuego();
    void cerrarjuego();
    void reset();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void aumentartiempo();
    void crearcamino();

private:
    Ui::MainWindow *ui;
    QPushButton *** botones;
    QTimer timer;
    Cronometro cronometro;
    Matriz matriz;
    Estaciones estaciones;

    int filas;
    int columnas;
};
#endif // MAINWINDOW_H
