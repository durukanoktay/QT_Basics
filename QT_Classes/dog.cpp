#include "dog.h"

Dog::Dog(QObject *parent)
    : QObject{parent}
{}

void Dog::Chase()
{
    qInfo() << "Chasing" << sender();
}
