#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);

    connect(ui->pushButton_Plus, &QPushButton::clicked, this, &MainWindow::on_operatorButton_clicked);
    connect(ui->pushButton_Minus, &QPushButton::clicked, this, &MainWindow::on_operatorButton_clicked);
    connect(ui->pushButton_Multi, &QPushButton::clicked, this, &MainWindow::on_operatorButton_clicked);
    connect(ui->pushButton_Division, &QPushButton::clicked, this, &MainWindow::on_operatorButton_clicked);
    connect(ui->pushButton_Point, &QPushButton::clicked, this, &MainWindow::on_pointButton_clicked);
    connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(ui->pushButton_Equals, &QPushButton::clicked, this, &MainWindow::on_equalsButton_clicked);

    connect(ui->signChangeButton, &QPushButton::clicked, this, &MainWindow::on_signChangeButton_clicked);
    connect(ui->tanButton, &QPushButton::clicked, this, &MainWindow::on_tanButton_clicked);
    connect(ui->squareRootButton, &QPushButton::clicked, this, &MainWindow::on_squareRootButton_clicked);
    connect(ui->factorialButton, &QPushButton::clicked, this, &MainWindow::on_factorialButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_numberButton_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();
    QString currentText = ui->lineEdit->text();
    ui->lineEdit->setText(currentText + buttonText);
}

void MainWindow::on_operatorButton_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    m_num1 = ui->lineEdit->text().toDouble();
    m_operator = button->text();
    ui->lineEdit->clear();
}

void MainWindow::on_pointButton_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (!currentText.contains('.')) {
        ui->lineEdit->setText(currentText + ".");
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_equalsButton_clicked()
{
    m_num2 = ui->lineEdit->text().toDouble();
    double result = 0.0;

    if (m_operator == "+") {
        result = m_num1 + m_num2;
    } else if (m_operator == "-") {
        result = m_num1 - m_num2;
    } else if (m_operator == "*") {
        result = m_num1 * m_num2;
    } else if (m_operator == "/") {
        if (m_num2 != 0) {
            result = m_num1 / m_num2;
        } else {
            ui->lineEdit->setText("Error: Division by zero");
            return;
        }
    }

    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_signChangeButton_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.contains('-')) {
        ui->lineEdit->setText(currentText.mid(1));
    } else {
        ui->lineEdit->setText("-" + currentText);
    }
}

void MainWindow::on_tanButton_clicked()
{
    double value = ui->lineEdit->text().toDouble();
    const double pi = 3.14159265359;
    double radians = value * pi / 180.0;
    double result = tan(radians);
    ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_squareRootButton_clicked()
{
    double value = ui->lineEdit->text().toDouble();
    if (value >= 0) {
        double result = sqrt(value);
        ui->lineEdit->setText(QString::number(result));
    } else {
        ui->lineEdit->setText("Error: Invalid input for square root");
    }
}

void MainWindow::on_factorialButton_clicked()
{
    int value = ui->lineEdit->text().toInt();
    if (value >= 0) {
        unsigned long long result = 1;
        for (int i = 1; i <= value; ++i) {
            result *= i;
        }
        ui->lineEdit->setText(QString::number(result));
    } else {
        ui->lineEdit->setText("Error: Invalid input for factorial");
    }
}
