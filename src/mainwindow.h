#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDate>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionAbrir_2_triggered();

private:
    Ui::MainWindow *ui;

    QString valorLineEdit1;
    QString valorLineEdit2;
    QString valorLineEdit3;
    QString valorLineEdit4;
    QDate dataSelecionada;
    QString descricaoProblema;
    QString prioridade;
    bool checkboxCorretiva;
    bool checkboxPreventiva;

};
#endif // MAINWINDOW_H
