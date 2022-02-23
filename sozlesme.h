#ifndef SOZLESME_H
#define SOZLESME_H

#include <QWidget>
#include <QString>
#include <QList>
#include "sil.h"
namespace Ui {
class Sozlesme;
}

class Sozlesme : public QWidget
{
    Q_OBJECT

public:
    explicit Sozlesme(QWidget *parent = nullptr);
    ~Sozlesme();
    QString tc1;
    QString isim1;
    QString soyisim1;
    QString meslek1;
    QString dogum1;
    QString cepTel1;
    QString evTel1;
    QString eMail1;
    QString ehliyetNo1;
    QString ehliyetTur1;
    QString notlar1;
    QString  adres;
      int  topla;
    QList<QString> yesA;
    QList<QString> tc2;
    QList<QString> isim2;
    QList<QString> soyisim2;
    QList<QString> meslek2;
    QList<QString> dogum2;
    QList<QString> cepTel2;
    QList<QString> evTel2;
    QList<QString> eMail2;
    QList<QString> ehliyetNo2;
    QList<QString> ehliyetTur2;
    QList<QString>  adres1;
/*
    QString plaka;
    QString marka;
    QString yıl;
    QString son_km;
    QString yakıt;
    QString vites;
    QString motor_gucu;
    QString cekis;
    QString kasa_tipi;
    QString renk;
    QString hasar;

    QList<QString> plakaA;
    QList<QString> markaA;
    QList<QString> yılA;
    QList<QString> son_kmA;
    QList<QString> yakıtA;
    QList<QString> vitesA;
    QList<QString> motor_gucuA;
    QList<QString> cekisA;
    QList<QString> kasa_tipiA;
    QList<QString> renkA;
    QList<QString> hasarA;
*/
signals:
    void sozlesme_plakaAra_clicked();
       void sozlesme_tcAra_clicked();
          void sozlesme_kirala_clicked();
             void sozlesme_exceleAktar_clicked();
                void sozlesme_sil_clicked();
private slots:
                void on_pushButton_exceleAktar_clicked();


                void on_pushButton_Kirala_clicked();

private:
    Ui::Sozlesme *ui;
;
};

#endif // SOZLESME_H
