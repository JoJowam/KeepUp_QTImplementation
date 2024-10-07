#ifndef GETSERVICEORDERS_H
#define GETSERVICEORDERS_H

#include <QDialog>

namespace Ui {
class getServiceOrders;
}

class getServiceOrders : public QDialog
{
    Q_OBJECT

public:
    explicit getServiceOrders(QWidget *parent = nullptr);
    ~getServiceOrders();

private slots:
    void on_eraseButton_clicked();

    void on_sendButton_clicked();

private:
    Ui::getServiceOrders *ui;
};

#endif // GETSERVICEORDERS_H
