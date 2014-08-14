#ifndef FLOATING_H
#define FLOATING_H

#include <QDialog>


namespace Ui {
class Floating;
}

class Floating : public QDialog
{
    Q_OBJECT
    
public:
    explicit Floating(QWidget *parent = 0);
    ~Floating();
    
private:
    Ui::Floating *ui;
};

#endif // FLOATING_H
