#include "calculatorapp.h"
#include "ui_calculatorapp.h"
#include "mathlogic.h" // Include your calculator logic here
#include <QPushButton>
#include <QKeyEvent>

CalculatorApp::CalculatorApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorApp) {
    ui->setupUi(this);

    // Connect all buttons to the onButtonClicked() slot
    for (auto button : findChildren<QPushButton*>()) {
        connect(button, &QPushButton::clicked, this, &CalculatorApp::onButtonClicked);
    }
    connect(ui->pushButton_23, &QPushButton::clicked, this, &CalculatorApp::evaluateExpression);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &CalculatorApp::updateExpression);
    connect(ui->showQueueButton, &QPushButton::clicked, this, &CalculatorApp::displayOutputQueue);

}

CalculatorApp::~CalculatorApp() {
    delete ui;
}

void CalculatorApp::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();


    if (buttonText == "=") {
        evaluateExpression();
    } else if (buttonText == "C") {
        currentExpression.clear();
        ui->lineEdit->clear();
        ui->outputTextBox->clear();
        clear_output_queue();
    }else if (buttonText == "del"){
        deleteLastButtonInput();
    }else {
        currentExpression += buttonText;
        ui->lineEdit->setText(currentExpression);
    }
}

void CalculatorApp::evaluateExpression() {
    //QByteArray expression = currentExpression.toLatin1();
    if (parse_expression(currentExpression.toUtf8().constData())) {
        double result = evaluate_rpn();
        ui->lineEdit->setText(QString::number(result));
        currentExpression = QString::number(result);
    } else {
        ui->lineEdit->setText("Error");
        currentExpression.clear();
    }
}

void CalculatorApp::deleteLastButtonInput() {
    // Get the current expression

    if (!currentExpression.isEmpty()){
        qDebug() << "Before chop:" << currentExpression;

        // Remove the last character
        currentExpression.chop(1);

        qDebug() << "After chop:" << currentExpression;

        // Update the display
        ui->lineEdit->setText(currentExpression);
    }
}


void CalculatorApp::updateExpression(const QString &newText) {
    currentExpression = newText;  // Synchronize with QLineEdit content
}

// Override the keyPressEvent to handle Enter/Return key press
void CalculatorApp::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        evaluateExpression();  // Trigger evaluation on "Enter" key press
    } else {
        QMainWindow::keyPressEvent(event);  // Pass other key events to the default handler
    }
}

void CalculatorApp::displayOutputQueue(){
    // Call the C function to get the output queue as a string
    char* queue_string = get_output_queue_as_string();

    // Set the text in the QTextEdit (or QLabel)
    ui->outputTextBox->setText(QString::fromUtf8(queue_string));
}


