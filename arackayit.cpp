#include "arackayit.h"
#include "ui_arackayit.h"
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
aracKayit::aracKayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aracKayit)
{

    ui->setupUi(this);
    //connect(ui->pushButton_ExcelAktar,SIGNAL(clicked()),this,SIGNAL(arac_exceleAktar_clicked()));
   //connect(ui->pushButton_Kaydet,SIGNAL(clicked()),this,SIGNAL(arac_kaydet_clicked()));
   // connect(ui->pushButton_resimEkle,SIGNAL(clicked()),this,SIGNAL(arac_resimsec_clicked()));

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/samar/OneDrive/Masaüstü/data/database.db");

    //Database açık/kapalı kontrol.
    if(!db.open()){
        QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
    }
    //Tablo oluşturma tableView atama.
     QSqlQuery *query = new QSqlQuery;
     query->exec("SELECT * FROM aracKayit");
     QSqlQueryModel *model_tablom = new QSqlQueryModel;
     model_tablom->setQuery(*query);
     ui->tableView_araclar->setModel(model_tablom);

      ui->pushButton_ExcelAktar->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/excel.png"));
      ui->pushButton_Kaydet->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/onay.png"));
      ui->pushButton_resimEkle->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/photo.png"));

      ui->tableView_araclar->setSelectionBehavior(QAbstractItemView::SelectRows);//Tüm tabloyu seçme

      ui->tableView_araclar->setSelectionMode(QAbstractItemView::SingleSelection);//Tek satır seçme






}

aracKayit::~aracKayit()
{
    delete ui;
}

void aracKayit::yenile()
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM aracKayit");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*query);
    ui->tableView_araclar->setModel(model_tablom);

}

void aracKayit::on_pushButton_ExcelAktar_clicked()
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM aracKayit");


    QSqlQuery *queryCount = new QSqlQuery;
    queryCount->exec("SELECT count(*) FROM aracKayit");
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
         ehliyetNo1 << query->value(9).toString();
         ehliyetTur1 << query->value(10).toString();
         notlar1 << query->value(11).toString();
    }
    QFile dosyam("C:/Users/samar/OneDrive/Masaüstü/excel_araçKayıt/excel.csv");
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
        ehliyetNo = ehliyetNo1[i];
        ehliyetTur = ehliyetTur1[i];
        notlar = notlar1[i];





        ciktimiz<<tc<<";"<< isim<<";"<<soyisim<<";"<<meslek<<";"<<dogum<<";"<<cepTel<<";"<< evTel<<";"<<eMail<<";"<<ehliyetNo<<";"<<ehliyetTur<<";"<<notlar<<";"<<Qt::endl;
    }
     QMessageBox::information(this,"Aktarım","'excel_araçKayıt' dosyasına aktarım tamamlanmıştır!");
}

void aracKayit::on_pushButton_resimEkle_clicked()
{
    QFileDialog dialog(this);
       dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
       dialog.setViewMode(QFileDialog::Detail);
       QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/samar/OneDrive/Masaüstü/Araç Resimleri",tr("Images (*.png *.xpm *.jpg)"));
       ui->label_resimEkle->setPixmap(fileName);

}

void aracKayit::on_pushButton_Kaydet_clicked()
{
    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT * FROM aracKayit");
    QSqlQueryModel *model_tablom = new QSqlQueryModel;
    model_tablom->setQuery(*query);
    ui->tableView_araclar->setModel(model_tablom);


QSqlQuery *query_ekle= new QSqlQuery;
tc = ui->lineEdit_plaka->text();
isim =    ui->lineEdit_Marka->text();
soyisim =    ui->lineEdit_Model->text();
meslek =     ui->lineEdit_Yil->text();
dogum =    ui->lineEdit_SonKm->text();
cepTel =     ui->comboBox_yakit->currentText();
evTel =    ui->comboBox_Vites->currentText();
eMail =     ui->comboBox_MotorGucu->currentText();
ehliyetNo =    ui->comboBox_Cekis->currentText();
ehliyetTur =     ui->comboBox_KasaTipi->currentText();
notlar =     ui->comboBox_Renk->currentText();
Hasar = ui->lineEdit_Hasar->text();


qDebug()<<query_ekle->exec("INSERT INTO aracKayit VALUES(NULL,'"+tc+"','"+isim+"','"+soyisim+"','"+meslek+"','"+dogum+"','"+cepTel+"','"+evTel+"','"+eMail+"','"+ehliyetNo+"','"+ehliyetTur+"','"+notlar+"','"+Hasar+"')");
yenile();
    QMessageBox::information(this,"Araç Kayıt","Araç Kaydı oluşturuldu!");



 ui->lineEdit_plaka->clear();
 ui->lineEdit_Marka->clear();
 ui->lineEdit_Model->clear();
 ui->lineEdit_Yil->clear();
 ui->lineEdit_SonKm->clear();
 ui->comboBox_yakit->clear();
 ui->comboBox_Vites->clear();
 ui->comboBox_MotorGucu->clear();
 ui->comboBox_Cekis->clear();
 ui->comboBox_KasaTipi->clear();
 ui->comboBox_Renk->clear();
 ui->lineEdit_Hasar->clear();

}

