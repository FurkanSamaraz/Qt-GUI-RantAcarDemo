#include "musterikayit.h"
#include "ui_musterikayit.h"
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
#include <QFileDialog>
#include <QPixmap>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
musteriKayit::musteriKayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musteriKayit)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/samar/OneDrive/Masaüstü/image/ara");
    ui->label_arama1->setPixmap(pix1.scaled(59,80,Qt::KeepAspectRatio));

    QPixmap pix2("C:/Users/samar/OneDrive/Masaüstü/image/ara");
    ui->label_arama2->setPixmap(pix2.scaled(59,80,Qt::KeepAspectRatio));

    QPixmap pix3("C:/Users/samar/OneDrive/Masaüstü/image/ara");
    ui->label_arama3->setPixmap(pix3.scaled(59,80,Qt::KeepAspectRatio));

    //connect(ui->pushButton_duzenle,SIGNAL(clicked()),this,SIGNAL(musteri_duzenle_clicked()));
    connect(ui->pushButton_exceleAktar,SIGNAL(clicked()),this,SIGNAL(musteri_exceleAktar_clicked()));
    connect(ui->pushButton_kaydet,SIGNAL(clicked()),this,SIGNAL(musteri_kaydet_clicked()));
    connect(ui->pushButton_resimsec,SIGNAL(clicked()),this,SIGNAL(musteri_resimsec_clicked()));
    connect(ui->pushButton_sil,SIGNAL(clicked()),this,SIGNAL(musteri_sil_clicked()));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/samar/OneDrive/Masaüstü/data/database.db");

    //Database açık/kapalı kontrol.
    if(!db.open()){
        QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
    }
    //Tablo oluşturma tableView atama.
     QSqlQuery *query = new QSqlQuery;
     query->exec("SELECT * FROM musteriKayit");
     QSqlQueryModel *model_tablom = new QSqlQueryModel;
     model_tablom->setQuery(*query);
     ui->tableView_musteriListesi->setModel(model_tablom);



     ui->pushButton_exceleAktar->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/excel.png"));
     ui->pushButton_kaydet->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/onay.png"));
     ui->pushButton_resimsec->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/photo.png"));
     ui->pushButton_sil->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/delete.png"));
     ui->pushButton_Yenile->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/yenile.png"));


}

musteriKayit::~musteriKayit()
{
    delete ui;
}

void musteriKayit::on_pushButton_exceleAktar_clicked()
{

    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM musteriKayit");


    QSqlQuery *queryCount = new QSqlQuery;
    queryCount->exec("SELECT count(*) FROM musteriKayit");
    queryCount->next();
    int sno_sayisi = queryCount->value(0).toInt();

    while(query->next()){
         tc1 << query->value(1).toString();
         isim1 << query->value(2).toString();
         soyisim1 << query->value(3).toString();
         meslek1 << query->value(4).toString();
         dogum1 << query->value(5).toString();
         cepTel1 << query->value(6).toString();
         evTel1 << query->value(7).toString();
         eMail1 << query->value(8).toString();
         adres1 << query->value(9).toString();
         ehliyetNo1 << query->value(10).toString();
         ehliyetTur1 << query->value(11).toString();
         notlar1 << query->value(12).toString();
    }







    QFile dosyam("C:/Users/samar/OneDrive/Masaüstü/excel_musterikayit/excel.csv");
    dosyam.open(QIODevice::WriteOnly);
    QTextStream ciktimiz(&dosyam);

    for (int i=0; i<sno_sayisi; i++ ) {
        tc = tc1[i];
        isim = isim1[i];
        soyisim = soyisim1[i];
        meslek = meslek1[i];
        dogum = dogum1[i];
        cepTel = cepTel1[i];
        evTel = evTel1[i];
        eMail = eMail1[i];
        adres=adres1[i];
        ehliyetNo = ehliyetNo1[i];
        ehliyetTur = ehliyetTur1[i];
        notlar = notlar1[i];




        ciktimiz<<tc<<";"<< isim<<";"<<soyisim<<";"<<meslek<<";"<<dogum<<";"<<cepTel<<";"<< evTel<<";"<<eMail<<";"<<adres<<";"<<ehliyetNo<<";"<<ehliyetTur<<";"<<notlar<<";"<<Qt::endl;
    }

    QMessageBox::information(this,"Aktarım","'excel_musterikayit' dosyasına aktarım tamamlanmıştır!");

}

void musteriKayit::on_pushButton_resimsec_clicked()
{

    QFileDialog dialog(this);
       dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
       dialog.setViewMode(QFileDialog::Detail);
       QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/samar/OneDrive/Masaüstü/Müşteri Resimleri",tr("Images (*.png *.xpm *.jpg)"));
       ui->label_7->setPixmap(fileName);




}



void musteriKayit::on_pushButton_kaydet_clicked()
{

QSqlQuery *query_ekle= new QSqlQuery;
tc = ui->lineEdit_tcno->text();
isim =    ui->lineEdit_isim->text();
soyisim =    ui->lineEdit_soyisim->text();
meslek =     ui->lineEdit_meslek->text();
dogum =    ui->dateEdit_dogumtarihi->text();
cepTel =     ui->lineEdit_ceptel->text();
evTel =    ui->lineEdit_evtel->text();
eMail =     ui->lineEdit_email->text();
adres =      ui->lineEdit_adres->text();
ehliyetNo =    ui->lineEdit_EhliyetNO->text();
ehliyetTur =     ui->lineEdit_EhliyetTuru->text();
notlar =     ui->lineEdit_2->text();


qDebug()<<query_ekle->exec("INSERT INTO musteriKayit VALUES(NULL,'"+tc+"','"+isim+"','"+soyisim+"','"+meslek+"','"+dogum+"','"+cepTel+"','"+evTel+"','"+eMail+"','"+adres+"','"+ehliyetNo+"','"+ehliyetTur+"','"+notlar+"')");

//Tablo oluşturma tableView atama.
 QSqlQuery *query = new QSqlQuery;
 query->exec("SELECT * FROM musteriKayit");
 QSqlQueryModel *model_tablom = new QSqlQueryModel;
 model_tablom->setQuery(*query);
 ui->tableView_musteriListesi->setModel(model_tablom);

QMessageBox::information(this,"KAYIT","Kayıt işlemi Başarılı!");
ui->lineEdit_tcno->clear();
ui->lineEdit_isim->clear();
 ui->lineEdit_soyisim->clear();
   ui->lineEdit_meslek->clear();
   ui->dateEdit_dogumtarihi->clear();
     ui->lineEdit_ceptel->clear();
    ui->lineEdit_evtel->clear();
   ui->lineEdit_email->clear();
   ui->lineEdit_adres->clear();
  ui->lineEdit_EhliyetNO->clear();
  ui->lineEdit_EhliyetTuru->clear();
    ui->lineEdit_2->clear();

}


void musteriKayit::on_pushButton_clicked()
{
    QSqlQuery *gry_id = new QSqlQuery;
    QString id =ui->lineEdit_tcno_Ara->text();


    gry_id->exec("SELECT * FROM musteriKayit WHERE tc = '"+id+"'");

    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry_id);
    ui->tableView_musteriListesi->setModel(model_tablom);
}

void musteriKayit::on_pushButton_Yenile_clicked()
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM musteriKayit");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*query);
    ui->tableView_musteriListesi->setModel(model_tablom);

}

void musteriKayit::on_pushButton_isimAra_clicked()
{
    QSqlQuery *gry_isim = new QSqlQuery;
    QString isim =ui->lineEdit_isim_Ara->text();


    gry_isim->exec("SELECT * FROM musteriKayit WHERE isim = '"+isim+"'");

    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry_isim);
    ui->tableView_musteriListesi->setModel(model_tablom);
}

void musteriKayit::on_pushButton_emailAra_clicked()
{
    QSqlQuery *gry_mail = new QSqlQuery;
    QString mail =ui->lineEdit_Email_Ara->text();


    gry_mail->exec("SELECT * FROM musteriKayit WHERE eMail = '"+mail+"'");

    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*gry_mail);
    ui->tableView_musteriListesi->setModel(model_tablom);;
}
