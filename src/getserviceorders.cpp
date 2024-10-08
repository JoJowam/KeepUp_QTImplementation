#include "getserviceorders.h"
#include "ui_getserviceorders.h"
#include "FactoryImpl.hpp"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QColor>

getServiceOrders::getServiceOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getServiceOrders)
{
    ui->setupUi(this);

    Factory* factory = FactoryImpl::getInstance();


    if (factory != nullptr) {
        std::vector<ServiceOrder*> serviceOrders = factory->getAllServiceOrders();

        if (!serviceOrders.empty()) {
            for (ServiceOrder* order : serviceOrders) {
                if (order != nullptr) {
                    QString orderDetails = QString::fromStdString(order->getOrderName())
                    + " - " + QString::fromStdString(order->getDeadline());

                    QListWidgetItem* item = new QListWidgetItem(orderDetails);

                    QString priority = QString::fromStdString(order->getPriority());

                    if (priority == "Alto") {
                        item->setBackground(Qt::red);
                    } else if (priority == "Baixo") {
                        item->setBackground(Qt::green);
                    } else if (priority == "Médio") {
                        item->setBackground(QColor(255, 165, 0));
                    }
                    if (order->getPostedOrderState()) {
                        item->setForeground(Qt::blue);
                    } else {
                        item->setForeground(Qt::black);
                    }

                    ui->listWidget->addItem(item);
                } else {
                    QMessageBox::warning(this, "Erro", "Ordem de serviço nula detectada.");
                }
            }
        } else {
            QMessageBox::information(this, "Informação", "Nenhuma ordem de serviço encontrada.");
        }
    } else {
        QMessageBox::critical(this, "Erro", "Erro ao obter a instância da Factory.");
    }
}


getServiceOrders::~getServiceOrders()
{
    delete ui;
}

void getServiceOrders::on_eraseButton_clicked(){
    QListWidgetItem* currentItem = ui->listWidget->currentItem();

    if (currentItem != nullptr) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmação",
                                      "Você tem certeza que deseja excluir esta ordem de serviço?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString orderName = currentItem->text().split(" - ").first();

            Factory* factory = FactoryImpl::getInstance();

            ServiceOrder* serviceOrderToDelete = nullptr;
            std::vector<ServiceOrder*> serviceOrders = factory->getAllServiceOrders();
            for (ServiceOrder* order : serviceOrders) {
                if (order != nullptr && QString::fromStdString(order->getOrderName()) == orderName) {
                    serviceOrderToDelete = order;
                    break;
                }
            }

            if (serviceOrderToDelete != nullptr) {
                bool success = factory->destroyServiceOrder(serviceOrderToDelete);
                if (success) {
                    delete ui->listWidget->takeItem(ui->listWidget->row(currentItem));
                    QMessageBox::information(this, "Sucesso", "Ordem de serviço excluída com sucesso.");
                } else {
                    QMessageBox::warning(this, "Erro", "Falha ao excluir a ordem de serviço.");
                }
            } else {
                QMessageBox::warning(this, "Erro", "Ordem de serviço não encontrada no sistema.");
            }
        }
    } else {
        QMessageBox::warning(this, "Erro", "Nenhuma ordem de serviço selecionada.");
    }
}


void getServiceOrders::on_sendButton_clicked(){
    QListWidgetItem* currentItem = ui->listWidget->currentItem();

    if (currentItem != nullptr) {
        QString orderName = currentItem->text().split(" - ").first();

        Factory* factory = FactoryImpl::getInstance();

        ServiceOrder* serviceOrderToPost = nullptr;
        std::vector<ServiceOrder*> serviceOrders = factory->getAllServiceOrders();
        for (ServiceOrder* order : serviceOrders) {
            if (order != nullptr && QString::fromStdString(order->getOrderName()) == orderName) {
                serviceOrderToPost = order;
                break;
            }
        }

        if (serviceOrderToPost != nullptr) {
            bool success = factory->setServiceOrderPosted(serviceOrderToPost);
            if (success) {
                QMessageBox::information(this, "Sucesso", "Ordem de serviço marcada como postada.");
                currentItem->setForeground(Qt::blue);
            } else {
                QMessageBox::warning(this, "Aviso", "A ordem de serviço já está marcada como postada.");
            }
        } else {
            QMessageBox::warning(this, "Erro", "Ordem de serviço não encontrada no sistema.");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Nenhuma ordem de serviço selecionada.");
    }
}

