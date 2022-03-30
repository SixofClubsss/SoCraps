#ifndef RULESPOPUP_H
#define RULESPOPUP_H

#include <QDialog>

namespace Ui {
class rulespopup;
}

class rulespopup : public QDialog
{
    Q_OBJECT

public:
    explicit rulespopup(QWidget *parent = nullptr);
    ~rulespopup();

private:
    Ui::rulespopup *ui;
};

#endif // RULESPOPUP_H
