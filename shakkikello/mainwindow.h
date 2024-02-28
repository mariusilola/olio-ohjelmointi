#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout(); //annetaan public timeout funktio, jotta voidaan mahdollistaa qtimerin käyttö

private slots:
    //määritellään kaikki napit mitkä ovat pelissä toimivia, kuten aina
    void on_swich1_clicked();

    void on_swich2_clicked();

    void on_seconds_clicked();

    void on_minutes_clicked();

    void on_start_clicked();

    void on_stop_clicked();

    void on_progressBar_valueChanged(int value);

    void on_progressBar_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void updateProgressBar();
    void setGameInfoText(QString, short);
    short player1Time; //tällä merkitään 1. pelaajan aikaa. Muuttuva aika.
    short player2Time; //tämä merkitsee 2. pelaajan aikaa
    short currentPlayer; //merkitsee tällähetkellä pelaavaa pelaajaa
    short gameTime; //tämä asetetaan joko 120 tai 300 sek, riipuen kumpaa nappia painetaan
    QTimer *pQTimer; //luodaan timerille olio, jolla sitä kutsutaan
};
#endif // MAINWINDOW_H
