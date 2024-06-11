#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

// for creating our own exception data typr
struct MyIssue : public exception
{
    const char * description;
    const char * what() const throw()
    {
        return "My Issue";
    }
};



bool DoDiv(int max)
{
    int value;
    qInfo() << "enter a number";
    cin >> value;

    /*
    if(value==0)
    {
        qInfo() << "goodbye world!";
        throw "can not divide by zero";
    }

    int result = max/value;
    qInfo() << "result: " << result;
    return true;
    */



    /*
    try
    {
        //Throw  - ???
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0) throw QString("Can not divide by zero");
        if(value > 5) throw 99;
        if(value == 1) throw std::runtime_error("Should be greater than 1 !!!");

        int result = max / value;
        qInfo() << "Result = " << result;
    }
    catch (std::exception const& e)
    {
        qWarning() << "We caught a STD exception:" << e.what();
        return false;
    }
    catch (QString e)
    {
        qWarning() << "We caught a QString:" << e;
        return false;
    }
    catch (int e)
    {
        qWarning() << "We caught a int:" << e;
        return false;
    }
    catch (...)
    {
        qWarning() << "We know something went wrong, but we dont know what.";
        return false;
    }
    */



    try
    {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0) throw std::invalid_argument("Can not divide by zero");
        if(value > 5) throw std::out_of_range("Should be less than 5");

        if(value == 1)
        {
            MyIssue e;
            e.description = "User did not read the manual";
            throw e;
        }

        int result = max / value;
        qInfo() << "Result = " << result;

        return true;
    }
    catch (MyIssue &e)
    {
        qWarning() << e.what() << " " << e.description;
        return false;
    }
    catch (std::exception &e)
    {
        qWarning() << e.what();
        return false;
    }
}
int main(int argc, char *argv[])
{
    int max=44;
    do
    {
        //loop
    }while(DoDiv(max));
    QCoreApplication a(argc, argv);

    return a.exec();
}

