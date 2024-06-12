
#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QVariant>
void test(QString name) //COPY
{
    qInfo() << name;
}
void varTest(QVariant var)
{
    qInfo() << var;
}
int main(int argc, char *argv[])
{

    qInfo() << "//----------------//";
    //----------------//



    QCoreApplication a(argc, argv);
    //QDate, Qtime and QDateTime
    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(20);

    //Different than Qt 5
    //qInfo() << today.toString(Qt::DateFormat::SystemLocaleDate);

    qInfo() << "ISODate" << today.toString(Qt::DateFormat::ISODate);
    qInfo() << "RFC2822Date" << today.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << "TextDate" << today.toString(Qt::DateFormat::TextDate);

    QTime now = QTime::currentTime();
    qInfo() << "ISODate" << now.toString(Qt::DateFormat::ISODate);
    qInfo() << "RFC2822Date" << now.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << "TextDate" << now.toString(Qt::DateFormat::TextDate);

    QDateTime current = QDateTime::currentDateTime();
    qInfo() << current;

    QDateTime expire = current.addDays(45);
    qInfo() << "Expire on" << expire;


    if(current > expire)
    {
        qInfo() << "Expired!";
    }
    else
    {
        qInfo() << "Not Expired!";
    }


    qInfo() << "//----------------//";

    //----------------//


    //QByteArray
    QString greeting = "Hello World!";
    QByteArray buffer(greeting.toUtf8());
    buffer.append("!");
    qInfo() << buffer;

    qInfo() << buffer.rightJustified(20,'.');
    qInfo() << buffer.at(buffer.length() - 1);

    QString modified(buffer);
    qInfo() << modified;

    //Basic encoding and decoding
    qInfo() << buffer.toBase64();
    qInfo() << buffer.toHex();



    //----------------//

    qInfo() << "//----------------//";

    //Qstring
    QString name = "Durukan Oktay";
    qInfo() << name;
    qInfo() << name.mid(1,3);
    qInfo() << name.insert(0,"Bay ");
    qInfo() << name.split(" ");

    int index = name.indexOf(" ");
    if(index > -1)
    {
        qInfo() << name.remove(0, index).trimmed();
    }

    QString title = "Student";
    QString full = name.trimmed() + " " + title;
    qInfo() << full;

    qInfo() << full.toUtf8();

    test(full);
    // QVariant

    QVariant var1= "Durukan";
    QVariant var2= 2;

    varTest(var1);
    varTest(var2);

    //----------------//

    qInfo() << "//----------------//";

    // QStringList

    QString Batukan = "Hello World! My name is Batukan";
    QStringList lst = Batukan.split(' ');
    qInfo() << lst;

    foreach(QString str, lst)
    {
        qInfo() << str;
    }

    //----------------//

    qInfo() << "//----------------//";

    // QList

    QList<QString> list = Batukan.split(" ");
    qInfo() << list;
    QList<int> intList({44,12,31,11,2});
    qInfo() << intList;
    intList.append(14);
    intList.remove(1);
    qInfo() << intList;

    //----------------//

    qInfo() << "//----------------//";

    // QVector

    QVector<QString> list1 = Batukan.split(" ");
    qInfo() << list1;
    QVector<int> intList1({44,12,31,11,2});
    qInfo() << intList1;
    intList1.append(14);
    intList1.remove(1);
    qInfo() << intList1;


    return a.exec();
}
