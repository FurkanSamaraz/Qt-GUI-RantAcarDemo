#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QMainWindow>
#include <QList>
#include <QDate>
#include <QTime>
#include <QtMath>
#include <QObject>
#include <QTimer>
#include "arackayit.h"
#include "musterikayit.h"
#include "sozlesme.h"
#include "raporlar.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

/*
    //Arac Slotları
    void arac_exceleAktar_SLOT();
    void arac_kaydet_SLOT();
    void arac_resimsec_SLOT();

    //Musteri Slotları
    void musteri_duzenle_SLOT();
void musteri_exceleAktar_SLOT();
    void musteri_kaydet_SLOT();
    void musteri_resimsec_SLOT();
    void musteri_sil_SLOT();

    //Sozlesme Slotları
    void sozlesme_kirala_SLOT();
    void sozlesme_plakaAra_SLOT();
    void sozlesme_sil_SLOT();
    void sozlesme_tcAra_SLOT();
    void sozlesme_exceleAktar_SLOT();
*/
    void on_pushButton_Anasayfa_clicked();
    void on_pushButton_Arac_islemleri_clicked();
    void on_pushButton_musteri_islemleri_clicked();
    void on_pushButton_sozlesme_islemleri_clicked();
    void on_pushButton_Raporlar_clicked();
private:
    Ui::MainWindow *ui;

    Sozlesme *sozlesme;
    musteriKayit *musteri;
    aracKayit *arac;
    raporlar *rapor;


};
#endif // MAINWINDOW_H
