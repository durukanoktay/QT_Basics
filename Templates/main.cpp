#include <QCoreApplication>
#include <QDebug>
#include "test.h"
//defining this template provides to manage function,algoritms, array and other things with different varaible types
template<typename U>
void print(U value)
{
    qInfo() << value;
}
template<class C1, class C2>
C1 add(C1 value1, C2 value2)
{
    return value1 + value2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    print<int>(1);
    print<std::string>("Hello");
    print<QString>(QString("Durukan Oktay"));
    qInfo() << add<int, double>(12, 11.03);
    qInfo() << add(3.05,true);
    qInfo() << add("Durukan",false);
    Test<int> intCalc;
    qInfo() << intCalc.add(1,4);

    Test<double> dCalc;
    qInfo() << dCalc.add(6.09,3.04);

    Test<QString> sCalc;
    qInfo() << sCalc.add(QString("Hello"),QString("World"));

    return a.exec();
}
