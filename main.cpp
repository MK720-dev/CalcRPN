#include "calculatorapp.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorApp w;
    w.resize(370, 250);
    w.show();
    return a.exec();
}

