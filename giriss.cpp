#include "giriss.h"
#include "ui_giriss.h"

giriss::giriss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giriss)
{
    ui->setupUi(this);
    //Resim eklentisi.
   QPixmap pix4("C:/Users/samar/OneDrive/Masaüstü/image/login_2");
   ui->label_login->setPixmap(pix4);
   ui->pushButton_giris->setToolTip("<font color='black'><b>Login</b>");
   ui->pushButton_giris->setIcon(QIcon("C:/Users/samar/OneDrive/Masaüstü/image/login_2"));


   ui->lineEdit_kullanici->setPlaceholderText("Username");
   ui->lineEdit_sifre->setPlaceholderText("Password");
}

giriss::~giriss()
{
    delete ui;
}

void giriss::on_pushButton_giris_clicked()
{
    QString tempKullanici,tempSifre;
    tempKullanici = ui->lineEdit_kullanici->text();
    tempSifre = ui->lineEdit_sifre->text();

    QSqlQuery *query =new QSqlQuery;
    query->exec("SELECT sifre FROM login WHERE isim ='"+tempKullanici+"'");
    query->first();

    qDebug()<<query->value(0).toString() <<tempSifre<< (tempSifre==query->value(0).toString());

    if(tempSifre==""){
        MainWindow *m = new MainWindow;
        m->close();
    }else {
        if(tempSifre==query->value(0).toString() ){

            MainWindow *m = new MainWindow;
            m->show();
            this->hide();
            QSqlDatabase db;
            db.removeDatabase(QSqlDatabase::defaultConnection);


        }else {
            MainWindow *m = new MainWindow;
            m->close();
     QMessageBox::warning(0,"uyari","giris olunamadi.");
    }
    }

}
