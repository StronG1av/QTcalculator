#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <cmath> // Для математических функций
#include <cstdlib> // Для функции изменения знака числа


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_numberButton_clicked();
    void on_operatorButton_clicked();
    void on_pointButton_clicked();
    void on_clearButton_clicked();
    void on_equalsButton_clicked();

    void on_signChangeButton_clicked();
    void on_tanButton_clicked();
    void on_squareRootButton_clicked();
    void on_factorialButton_clicked();

private:
    Ui::MainWindow *ui;
    double m_num1;
    double m_num2;
    QString m_operator;
};

#endif // MAINWINDOW_H
