#ifndef SIL_H
#define SIL_H

#include <QWidget>
#include "sozlesme.h"
namespace Ui {
class sil;
}

class sil : public QWidget
{
    Q_OBJECT

public:
    explicit sil(QWidget *parent = nullptr);
    ~sil();
signals:
    void deletee_clicked();
private slots:
    void on_pushButton_clicked();

private:
    Ui::sil *ui;
    sil *del = new sil;

};

#endif // SIL_H
