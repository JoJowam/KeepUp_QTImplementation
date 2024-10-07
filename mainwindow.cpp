#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "src/FactoryImpl.hpp"
#include "src/ServiceOrder.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_pushButton_clicked(){
    valorLineEdit1 = ui->lineEdit->text();
    valorLineEdit2 = ui->lineEdit_2->text();
    valorLineEdit3 = ui->lineEdit_3->text();
    valorLineEdit4 = ui->lineEdit_4->text();
    dataSelecionada = ui->dateEdit->date();
    checkboxCorretiva = ui->checkBox_4->isChecked();
    checkboxPreventiva = ui->checkBox_5->isChecked();
    descricaoProblema = ui->textEdit->toPlainText();

    if (ui->radioButton->isChecked()) {
        prioridade = "Baixo";
    } else if (ui->radioButton_2->isChecked()) {
        prioridade = "Médio";
    } else if (ui->radioButton_3->isChecked()) {
        prioridade = "Alto";
    }

    QString tipoOrdem;
    if (checkboxCorretiva) {
        tipoOrdem = "Corretiva";
    } else if (checkboxPreventiva) {
        tipoOrdem = "Preventiva";
    } else {
        tipoOrdem = "Não especificado";
    }

    std::string nomeFuncionario = valorLineEdit1.toStdString();
    std::string equipamento = valorLineEdit3.toStdString();
    std::string setor = valorLineEdit2.toStdString();
    std::string prioridadeOrdem = prioridade.toStdString();
    std::string prazo = dataSelecionada.toString("yyyy-MM-dd").toStdString();
    std::string tipoOrdemStr = tipoOrdem.toStdString();
    std::string descricao = descricaoProblema.toStdString();

    Factory* factory = FactoryImpl::getInstance();
    ServiceOrder* serviceOrder = factory->createServiceOrder(
        nomeFuncionario,
        equipamento,
        setor,
        prioridadeOrdem,
        prazo,
        tipoOrdemStr,
        descricao
    );

    qDebug() << "Ordem de serviço criada com sucesso.";
    qDebug() << "Nome da Ordem:" << QString::fromStdString(serviceOrder->getOrderName());
    qDebug() << "Equipamento:" << QString::fromStdString(serviceOrder->getEquipment());
    qDebug() << "Setor:" << QString::fromStdString(serviceOrder->getSector());
    qDebug() << "Prioridade:" << QString::fromStdString(serviceOrder->getPriority());
    qDebug() << "Prazo:" << QString::fromStdString(serviceOrder->getDeadline());
    qDebug() << "Tipo de Ordem:" << QString::fromStdString(serviceOrder->getOrderType());
    qDebug() << "Descrição do Erro:" << QString::fromStdString(serviceOrder->getErrorDescription());
}

