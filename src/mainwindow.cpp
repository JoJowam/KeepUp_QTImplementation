#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "getserviceorders.h"
#include "FactoryImpl.hpp"
#include "ServiceOrder.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}




void MainWindow::on_pushButton_clicked() {
    valorLineEdit1 = ui->lineEdit->text();
    valorLineEdit2 = ui->lineEdit_2->text();
    valorLineEdit3 = ui->lineEdit_3->text();
    dataSelecionada = ui->dateEdit->date();
    checkboxCorretiva = ui->checkBox_4->isChecked();
    checkboxPreventiva = ui->checkBox_5->isChecked();
    descricaoProblema = ui->textEdit->toPlainText();

    if (valorLineEdit1.isEmpty() || valorLineEdit2.isEmpty() || valorLineEdit3.isEmpty() || descricaoProblema.isEmpty()) {
        QMessageBox::warning(this, "Atenção", "Por favor, preencha todos os campos.");
        return;
    }

    if (ui->radioButton->isChecked()) {
        prioridade = "Baixo";
    } else if (ui->radioButton_2->isChecked()) {
        prioridade = "Médio";
    } else if (ui->radioButton_3->isChecked()) {
        prioridade = "Alto";
    } else {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione uma prioridade.");
        return;
    }

    QString tipoOrdem;
    if (checkboxCorretiva) {
        tipoOrdem = "Corretiva";
    } else if (checkboxPreventiva) {
        tipoOrdem = "Preventiva";
    } else {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um tipo de ordem.");
        return;
    }

    std::string orderName = valorLineEdit1.toStdString();
    std::string equipament = valorLineEdit3.toStdString();
    std::string sector = valorLineEdit2.toStdString();
    std::string orderPriority = prioridade.toStdString();
    std::string deadline = dataSelecionada.toString("yyyy-MM-dd").toStdString();
    std::string orderType = tipoOrdem.toStdString();
    std::string description = descricaoProblema.toStdString();

    Factory* factory = FactoryImpl::getInstance();
    ServiceOrder* serviceOrder = factory->createServiceOrder(
        orderName,
        equipament,
        sector,
        orderPriority,
        deadline,
        orderType,
        description
    );

    QMessageBox::information(this, "KeepUp", "Ordem de serviço criada com sucesso.");
}

void MainWindow::on_actionAbrir_2_triggered(){
    getServiceOrders getOrdersWindow;
    getOrdersWindow.exec();
}

