#include "sozlesme.h"
#include "ui_sozlesme.h"
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QDate>
#include <QTime>
#include <QtMath>
#include <QObject>
#include "sil.h"
Sozlesme::Sozlesme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sozlesme)
{
    ui->setupUi(this);
   // connect(ui->pushButton_Sil,SIGNAL(clicked()),this,SIGNAL(sozlesme_kirala_clicked()));
    connect(ui->pushButton_Kirala,SIGNAL(clicked()),this,SIGNAL(sozlesme_kirala_clicked()));
    //connect(ui->pushButton_Plaka_ara,SIGNAL(clicked()),this,SIGNAL(sozlesme_plakaAra_clicked()));
   // connect(ui->pushButton_Sil,SIGNAL(clicked()),this,SIGNAL(sozlesme_sil_clicked()));
   // connect(ui->pushButton_TCNo_Ara,SIGNAL(clicked()),this,SIGNAL(sozlesme_tcAra_clicked()));
    connect(ui->pushButton_exceleAktar,SIGNAL(clicked()),this,SIGNAL(sozlesme_exceleAktar_clicked()));
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/samar/OneDrive/Masaüstü/data/database.db");

    //Database açık/kapalı kontrol.
    if(!db.open()){
        QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
    }
    //Tablo oluşturma tableView atama.
     QSqlQuery *query = new QSqlQuery;
     query->exec("SELECT * FROM sozlesme");
     QSqlQueryModel *model_tablom = new QSqlQueryModel;
     model_tablom->setQuery(*query);
     ui->tableView_AracListesi->setModel(model_tablom);

     ui->pushButton_Kirala->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/onay.png"));
     //ui->pushButton_Sil->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/delete.png"));
     ui->pushButton_exceleAktar->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/excel.png"));


}

Sozlesme::~Sozlesme()
{
    delete ui;
}

void Sozlesme::on_pushButton_exceleAktar_clicked()
{

    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM sozlesme");


    QSqlQuery *queryCount = new QSqlQuery;
    queryCount->exec("SELECT count(*) FROM sozlesme");
    queryCount->next();
    int sno_sayisi = queryCount->value(0).toInt();
    while(query->next()){
         tc2 << query->value(1).toString();
         isim2 << query->value(2).toString();
         soyisim2 << query->value(3).toString();
         meslek2 << query->value(4).toString();
         dogum2 << query->value(5).toString();
         cepTel2 << query->value(6).toString();
         evTel2 << query->value(7).toString();
         eMail2 << query->value(8).toString();
         ehliyetNo2 << query->value(9).toString();
         ehliyetTur2 << query->value(10).toString();
    }
    QFile dosya("C:/Users/samar/OneDrive/Masaüstü/excel_sozlesme/excel.csv");
    dosya.open(QIODevice::WriteOnly);
    QTextStream ciktim(&dosya);

    for (int i=0; i<sno_sayisi; i++ ) {
        tc1 = tc2[i];
        isim1 = isim2[i];
        soyisim1 = soyisim2[i];
        meslek1 = meslek2[i];
        dogum1 = dogum2[i];
        cepTel1 = cepTel2[i];
        evTel1 = evTel2[i];
        eMail1 = eMail2[i];
        ehliyetNo1 = ehliyetNo2[i];
        ehliyetTur1 = ehliyetTur2[i];

        ciktim<<tc1<<";"<< isim1<<";"<<soyisim1<<";"<<meslek1<<";"<<dogum1<<";"<<cepTel1<<";"<< evTel1<<";"<<eMail1<<";"<<ehliyetNo1<<";"<<ehliyetTur1<<";"<<Qt::endl;
    }

QMessageBox::information(this,"Aktarım","'excel_sozlesme' dosyasına aktarım tamamlanmıştır!");
/*
    while(quer->next()){
         plakaA << quer->value(1).toString();
         markaA << quer->value(2).toString();
         yılA << quer->value(3).toString();
         son_kmA << quer->value(4).toString();
         yakıtA << quer->value(5).toString();
         vitesA << quer->value(6).toString();
         motor_gucuA << quer->value(7).toString();
         cekisA << quer->value(8).toString();
         kasa_tipiA << quer->value(9).toString();
         renkA << quer->value(10).toString();
         hasarA << quer->value(11).toString();
    }

    QFile dosyam("C:/Users/samar/OneDrive/Masaüstü/excel_araçKayıt/excel.csv");
    dosyam.open(QIODevice::WriteOnly);
    QTextStream cikti(&dosyam);

    for (int i=0; i<sno_say; i++ ) {
        plaka = plakaA[i];
        marka = markaA[i];
        yıl = yılA[i];
        son_km = son_kmA[i];
        yakıt = yakıtA[i];
        vites = vitesA[i];
        motor_gucu = motor_gucuA[i];
        cekis = cekisA[i];
        kasa_tipi = kasa_tipiA[i];
        renk = renkA[i];
        hasar = hasarA[i];




        cikti<<plaka<<";"<< marka<<";"<<yıl<<";"<<son_km<<";"<<yakıt<<";"<<vites<<";"<< motor_gucu<<";"<<cekis<<";"<<kasa_tipi<<";"<<renk<<";"<<hasar<<";"<<Qt::endl;
    }
    */
}




void Sozlesme::on_pushButton_Kirala_clicked()
{
    QSqlQuery *query_ekle= new QSqlQuery;
    tc1 = ui->dateTimeEdit_AlisTarih->text();
    isim1=   ui->dateTimeEdit_TeslimTarih->text();
    soyisim1 = ui->lineEdit_TCNo_Getir->text();
    meslek1 =  ui->lineEdit_isim->text();
    dogum1 =      ui->lineEdit_Soyisim->text();
    cepTel1 =        ui->lineEdit_Telefon->text();
    evTel1 =    ui->lineEdit_Plaka_Getir->text();
    eMail1 =     ui->lineEdit_sonKm->text();
    adres =      ui->lineEdit_ToplamTutar->text();


    qDebug()<<query_ekle->exec("INSERT INTO sozlesme VALUES(NULL,'"+tc1+"','"+isim1+"','"+soyisim1+"','"+meslek1+"','"+dogum1+"','"+cepTel1+"','"+evTel1+"','"+eMail1+"','"+adres+"')");

    //Tablo oluşturma tableView atama.
     QSqlQuery *query = new QSqlQuery;
     query->exec("SELECT * FROM sozlesme");
     QSqlQueryModel *model_tablom = new QSqlQueryModel;
     model_tablom->setQuery(*query);
     ui->tableView_AracListesi->setModel(model_tablom);

    QMessageBox::information(this,"Sözleşme","Randevu oluşturuldu!");

  ui->dateTimeEdit_AlisTarih->clear();
    ui->dateTimeEdit_TeslimTarih->clear();
  ui->lineEdit_TCNo_Getir->clear();
  ui->lineEdit_isim->clear();
    ui->lineEdit_Soyisim->clear();
      ui->lineEdit_Telefon->clear();
    ui->lineEdit_Plaka_Getir->clear();
       ui->lineEdit_sonKm->clear();
     ui->lineEdit_ToplamTutar->clear();


}
