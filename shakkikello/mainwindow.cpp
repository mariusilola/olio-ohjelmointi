#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPlayer = 1;
    pQTimer = new QTimer(this);
    //yhdistetään timeri käyttöön
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
    //yhdistetään palkit, joissa näkyy jäljellä oleva aika
    connect(ui->progressBar, &QProgressBar::valueChanged, this, &MainWindow::on_progressBar_valueChanged);
    connect(ui->progressBar_2, &QProgressBar::valueChanged, this, &MainWindow::on_progressBar_2_valueChanged);
    setGameInfoText("Select palytime and press start to play", 20); //tämä teksti näkyy ruudussa heti kun sovellus aukeaa, antaa ohjeet
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pQTimer;
    pQTimer = nullptr;
}

//funktiossa määritellään start nappi käyttöön, jotta peli alkaa vasta kun sitä on painettu
void MainWindow::on_start_clicked()
{
    ui->start->setEnabled(false); //otaa napin pois käytöstä, jotta sitä ei voi painaa pelin aikana
    qDebug()<<"start pressed";
    setGameInfoText("Game ongoing", 20);

    //merkitsevät ajan alkamista
    pQTimer->start(1000);
    updateProgressBar();
}

void MainWindow::on_seconds_clicked()
{
    gameTime=120; //tässä annetaan ensimmäinen aika pelille ja se toimii määrittelynä playerTime:ille
    player1Time=gameTime;
    player2Time=gameTime;
    qDebug() << "Seconds button clicked";

    setGameInfoText("ready to play", 20);
}


void MainWindow::on_minutes_clicked()
{
    gameTime=300;
    player1Time=gameTime;
    player2Time=gameTime;
    qDebug() << "Minutes button clicked";

    setGameInfoText("ready to play", 20);
}

void MainWindow::on_swich1_clicked()
{
    currentPlayer = 2; //tässä swich nappia painettaessa pelaajaksi muuttuu 1
    updateProgressBar(); //tämä kutsuu päivitysfunktiota, jotta pelaajan aika päivittyy aina heti nappia painettua

    qDebug()<<"swich1 pressed";
}
void MainWindow::on_swich2_clicked()
{
    currentPlayer = 1; //täällä tapahtuu sama mutta saadan aktivoitua vuoro toiselle pelaajalle
    updateProgressBar();

    qDebug()<<"swich2 pressed";
}

 //täällä funktion sisällä määritellään kellon toimintaa
void MainWindow::timeout()
{
    //tämä kysyy vaan onko pelaja 1
    if(currentPlayer == 1){
        if(player1Time > 0){
            player1Time--;
        } //pelaajan ollessa 1 tämän aika vähenee kunnes se on 0
        else{
            currentPlayer=2;
            setGameInfoText("PLAYER 2 WON!!", 20);
            //jos aika pääsee ensimmäisenä 0 niin vuoro loppuu ja toinen pelaaja voittaa
        }
    }
    //mikäli pelaaja ei ole 1
    else if(currentPlayer==2){
        if(player2Time > 0){
        player2Time--;
        }
        else{
            setGameInfoText("PLAYER 1 WON!!", 20);
        }
    }
    updateProgressBar();
}

//funktiossa päivitetään kuluvaa aikaa
void MainWindow::updateProgressBar()
{
    int player1remaining, player2remaining; //näillä saa merkittyä pelaajien kulunutta aikaa
    //täällä tehdään pelajan ajan ja kokonaisajan jako ja muutetaan se prosentiksi, jotta saadaan jäljellä olevat prosentit esitetyä kätevästi
        player1remaining = static_cast<int>((static_cast<float>(player1Time)/gameTime)*100); //tässä int:ksi määritellyt p1r 'muutetaan' float arvoksi,
        player2remaining = static_cast<int>((static_cast<float>(player2Time)/gameTime)*100); //static_cast mahdollistaa int ja float parametrien keskustelun

    //näillä progressBarin arvo saadaan pysymään aina siinä mihin se on pysäytetty ja sitä saadaan jatketua
    ui->progressBar->setValue(player1remaining);
    ui->progressBar_2->setValue(player2remaining);
}

void MainWindow::on_stop_clicked()
{
    pQTimer->stop(); //tässä timer lopetetaan
    setGameInfoText("New game via start button", 20);

    //näillä sadaan pelaajien aika takaisin peliaikaan, eli peli alkaa alusta
    player1Time=gameTime;
    player2Time=gameTime;

    updateProgressBar();

    //alustaa start napin takaisin käyttöön, kun stop nappia on painettu, voidaan aloittaa uusi peli
    ui->start->setEnabled(true);
    qDebug()<<"stop pressed";

}

//täällä luodaan muokattava label, jotta saadaan eri vaiheissa peliä näytettyä uutta tekstiä ja ohjeita
void MainWindow::setGameInfoText(QString text, short fontsize)
{
    QString labelText = text; //tässä alustetaan tekstille paikka
    ui->label->setText(labelText); //tässä teksti asetetaan
    QFont font = ui->label->font(); //näillä alustetaan fontti toiminto qt:ssa. eli qFont:ille annetaan nimi joka viedään labelille ja siitä fontiksi
    font.setPointSize(static_cast<int>(fontsize)); //fontin tulee olla int, joten static_cast:illa short saadaan taas toimiman
    ui->label->setFont(font); //tässä vihdoin asetetaan fontti
}

void MainWindow::on_progressBar_valueChanged(int value)
{

}

void MainWindow::on_progressBar_2_valueChanged(int value)
{

}
