#ifndef ARACKAYIT_H
#define ARACKAYIT_H

#include <QWidget>

namespace Ui {
class aracKayit;
}

class aracKayit : public QWidget
{
    Q_OBJECT

public:
    explicit aracKayit(QWidget *parent = nullptr);
    ~aracKayit();
      void yenile();
    QString tc;
    QString isim;
    QString soyisim;
    QString meslek;
    QString dogum;
    QString cepTel;
    QString evTel;
    QString eMail;
    QString ehliyetNo;
    QString ehliyetTur;
    QString notlar;
    QString Hasar;

    QString secilen;
    QString Hasar_2;

    QList<QString> tc1;
    QList<QString> isim1;
    QList<QString> soyisim1;
    QList<QString> meslek1;
    QList<QString> dogum1;
    QList<QString> cepTel1;
    QList<QString> evTel1;
    QList<QString> eMail1;
    QList<QString> ehliyetNo1;
    QList<QString> ehliyetTur1;
    QList<QString> notlar1;
signals:
    void arac_kaydet_clicked();
    void arac_exceleAktar_clicked();
    void arac_resimsec_clicked();

private slots:
    void on_pushButton_ExcelAktar_clicked();

    void on_pushButton_resimEkle_clicked();

    void on_pushButton_Kaydet_clicked();



private:
    Ui::aracKayit *ui;
};

#endif // ARACKAYIT_H
