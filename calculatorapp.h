#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorApp; }
QT_END_NAMESPACE

class CalculatorApp : public QMainWindow {
    Q_OBJECT

public:
    explicit CalculatorApp(QWidget *parent = nullptr);
    ~CalculatorApp();

private slots:
    void onButtonClicked(); // Handles button clicks
    void evaluateExpression(); // Parses and evaluates the expression
    void deleteLastButtonInput();
    void updateExpression(const QString &newText);
    void keyPressEvent(QKeyEvent *event);
    void displayOutputQueue();


private:
    Ui::CalculatorApp *ui;
    QString currentExpression; // Stores the current expression

};


#endif // CALCULATORAPP_H
