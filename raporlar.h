#ifndef RAPORLAR_H
#define RAPORLAR_H

#include <QWidget>

namespace Ui {
class raporlar;
}

class raporlar : public QWidget
{
    Q_OBJECT

public:
    explicit raporlar(QWidget *parent = nullptr);
    ~raporlar();

private:
    Ui::raporlar *ui;
};

#endif // RAPORLAR_H
