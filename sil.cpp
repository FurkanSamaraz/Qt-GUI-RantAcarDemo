#include "sil.h"
#include "ui_sil.h"
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
sil::sil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sil)
{
    ui->setupUi(this);

}

sil::~sil()
{
    delete ui;
}



void sil::on_pushButton_clicked()
{

    QSqlQuery *gry_sil = new QSqlQuery;

    QString new_name = ui->lineEdit->text();
    gry_sil->exec("DELETE FROM sozlesme WHERE id ='"+new_name+"' ");
      QMessageBox::information(this,"SİLİNDİ","Silme Başarılı");


}
