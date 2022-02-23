#ifndef MUSTERIKAYIT_H
#define MUSTERIKAYIT_H

#include <QWidget>

namespace Ui {
class musteriKayit;
}

class musteriKayit : public QWidget
{
    Q_OBJECT

public:
    explicit musteriKayit(QWidget *parent = nullptr);
    ~musteriKayit();
    QString tc;
    QString isim;
    QString soyisim;
    QString meslek;
    QString dogum;
    QString cepTel;
    QString evTel;
    QString eMail;
    QString adres;
    QString ehliyetNo;
    QString ehliyetTur;
    QString notlar;
    QString yes;
    QList<QString> yesA;
    QList<QString> tc1;
    QList<QString> isim1;
    QList<QString> soyisim1;
    QList<QString> meslek1;
    QList<QString> dogum1;
    QList<QString> cepTel1;
    QList<QString> evTel1;
    QList<QString> eMail1;
    QList<QString> adres1;
    QList<QString> ehliyetNo1;
    QList<QString> ehliyetTur1;
    QList<QString> notlar1;
/*
    QString tcnoB ;
    QString isimB ;
    QString soyisimB;
    QString meslekB ;
    QString dogumB ;
    QString ceptelB ;
    QString evtelB ;
    QString emailB ;
    QString adresB ;
    QString ehliyetNoB ;
    QString ehliyetTurB ;
    QString notlarB ;
*/
signals:
        void musteri_exceleAktar_clicked();
            void musteri_sil_clicked();
                void musteri_kaydet_clicked();
                    void musteri_resimsec_clicked();
private slots:
                    void on_pushButton_exceleAktar_clicked();

                    void on_pushButton_resimsec_clicked();

                    void on_pushButton_kaydet_clicked();

                    void on_pushButton_clicked();

                    void on_pushButton_Yenile_clicked();

                    void on_pushButton_isimAra_clicked();

                    void on_pushButton_emailAra_clicked();

private:
    Ui::musteriKayit *ui;

};

#endif // MUSTERIKAYIT_H
