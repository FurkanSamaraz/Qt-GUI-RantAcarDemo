#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "giriss.h"
#include "arackayit.h"
#include  "musterikayit.h"
#include "sozlesme.h"
#include "raporlar.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*
    //Arac bağantıları
    connect(arac,SIGNAL(arac_exceleAktar_clicked()),this,SLOT(arac_exceleAktar_SLOT()));
    connect(arac,SIGNAL(arac_kaydet_clicked()),this,SLOT(arac_kaydet_SLOT()));
    connect(arac,SIGNAL(arac_resimsec_clicked()),this,SLOT(arac_resimsec_SLOT()));

    //Musteri bağlantıları
    connect(musteri,SIGNAL(musteri_duzenle_clicked()),this,SLOT(musteri_duzenle_SLOT()));
    connect(musteri,SIGNAL(musteri_exceleAktar_clicked()),this,SLOT(musteri_exceleAktar_SLOT()));
    connect(musteri,SIGNAL(musteri_kaydet_clicked()),this,SLOT(musteri_kaydet_SLOT()));
    connect(musteri,SIGNAL(musteri_resimsec_clicked()),this,SLOT(musteri_resimsec_SLOT()));
    connect(musteri,SIGNAL(musteri_sil_clicked()),this,SLOT(musteri_sil_SLOT()));

    //Sozlesme Bağlantıları
    connect(sozlesme,SIGNAL(sozlesme_kirala_clicked()),this,SLOT(sozlesme_kirala_SLOT()));
    connect(sozlesme,SIGNAL(sozlesme_plakaAra_clicked()),this,SLOT(sozlesme_plakaAra_SLOT()));
    connect(sozlesme,SIGNAL(sozlesme_sil_clicked()),this,SLOT(sozlesme_sil_SLOT()));
    connect(sozlesme,SIGNAL(sozlesme_tcAra_clicked()),this,SLOT(sozlesme_tcAra_SLOT()));
    connect(sozlesme,SIGNAL(sozlesme_exceleAktar_clicked()),this,SLOT(sozlesme_exceleAktar_SLOT()));
*/

    ui->setupUi(this);
    QPixmap pix4("C:/Users/samar/OneDrive/Masaüstü/image/dvc2");
    ui->label->setPixmap(pix4.scaled(180,180,Qt::KeepAspectRatio));

    QPixmap pix5("C:/Users/samar/OneDrive/Masaüstü/image/tay.png");
    ui->label_2->setPixmap(pix5.scaled(1500,700,Qt::KeepAspectRatio));

 giriss g;
    //DATABASE BAĞLANTISI
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("veritabanim");
    db.setUserName("postgres");
    db.setPassword("172754");

    //Database açık/kapalı kontrol.
    if(!db.open()){
        QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
    }else{

    }

 g.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_Anasayfa_clicked()
{
        MainWindow *w= new MainWindow;
        w->show();
}
void MainWindow::on_pushButton_Arac_islemleri_clicked()
{
 aracKayit *arac = new aracKayit;
 arac->show();
}

void MainWindow::on_pushButton_musteri_islemleri_clicked()
{
musteriKayit *musteri = new musteriKayit;
musteri->show();
}

void MainWindow::on_pushButton_sozlesme_islemleri_clicked()
{
 Sozlesme *sozlesme = new Sozlesme;
 sozlesme->show();
}

void MainWindow::on_pushButton_Raporlar_clicked()
{
  raporlar *rapor = new raporlar;
  rapor->show();
}
