#include "Passenger.h"


// Base Class Passenger


Passenger::Passenger(string n, string i)
{
    name = n;
    id = i;
}

string Passenger::getName() const
{
    return name;
}

string Passenger::getId() const
{
    return id;
}

Passenger::~Passenger()
{
}

// Economy Passenger


EconomyPassenger::EconomyPassenger(string n, string i)
    : Passenger(n, i)
{
}

double EconomyPassenger::getDiscount()
{
    return 0.0; // No discount
}

double EconomyPassenger::refundPercent()
{
    return 0.50; // 50% refund
}

void EconomyPassenger::display()
{
    cout << "\n----- Economy Passenger -----" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
}


// Business Passenger


BusinessPassenger::BusinessPassenger(string n, string i)
    : Passenger(n, i)
{
}

double BusinessPassenger::getDiscount()
{
    return 0.10; // 10% discount
}

double BusinessPassenger::refundPercent()
{
    return 0.70; // 70% refund
}

void BusinessPassenger::display()
{
    cout << "\nBusiness Passenger " << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
}


// First Class Passenger


FirstClassPassenger::FirstClassPassenger(string n, string i)
    : Passenger(n, i)
{
}

double FirstClassPassenger::getDiscount()
{
    return 0.20; // 20% discount
}

double FirstClassPassenger::refundPercent()
{
    return 0.90; // 90% refund
}

void FirstClassPassenger::display()
{
    cout << "\n----- First Class Passenger -----" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
}

