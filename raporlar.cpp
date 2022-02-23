#include "raporlar.h"
#include "ui_raporlar.h"
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

raporlar::raporlar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::raporlar)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/samar/OneDrive/Masaüstü/data/database.db");

    //Database açık/kapalı kontrol.
    if(!db.open()){
        QMessageBox::critical(this,"HATA","Veri tabanı bağlanmadı");
    }

    int a,b,c,d;

    QSqlQuery *que = new QSqlQuery;
    que->exec("SELECT count(*) AS id FROM musteriKayit");
    que->next();
    a= que->value(0).toInt();
    ui->lcdNumber_MUSTERISAYISI->display(a);



    QSqlQuery *quer = new QSqlQuery;
    quer->exec("SELECT count(*) AS id FROM aracKayit");
    quer->next();
    b=quer->value(0).toInt();
    ui->lcdNumber_ARACSAYISI->display(b);



    QSqlQuery *query = new QSqlQuery;
    query->exec("SELECT count(*) AS id FROM sozlesme");
    query->next();
    c =query->value(0).toInt();
    ui->lcdNumber_SOZLESMESAYISI->display(c);

    QSqlQuery *queryy = new QSqlQuery;
    queryy->exec("SELECT SUM(toplam_Tutar) FROM sozlesme");
    queryy->next();
    d=queryy->value(0).toInt();
    ui->lcdNumber_CIROTOPLAM->display(d);


}

raporlar::~raporlar()
{
    delete ui;
}
