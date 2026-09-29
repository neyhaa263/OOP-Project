#include "Flight.h"
#include <stdexcept>

// Constructor
Flight::Flight(string fn, string org, string dest, int seats);
{
    flightNumber = fn;
    origin = org;
    destination = dest;
    totalSeats = seats;
    availableSeats = seats;
}

// Book a seat
bool Flight::bookSeat()
{
    if (availableSeats <= 0)
    {
        throw runtime_error("No seats available on this flight.");
    }

    availableSeats--;
    return true;
}

// Cancel a seat
void Flight::cancelSeat()
{
    if (availableSeats < totalSeats)
    {
        availableSeats++;
    }
}

// Getters
string Flight::getFlightNumber() const
{
    return flightNumber;
}

string Flight::getOrigin() const
{
    return origin;
}

string Flight::getDestination() const
{
    return destination;
}

int Flight::getTotalSeats() const
{
    return totalSeats;
}

int Flight::getAvailableSeats() const
{
    return availableSeats;
}

// Destructor
Flight::~Flight()
{
}

// =====================
// Domestic Flight
// =====================

DomesticFlight::DomesticFlight(string fn, string org,
                               string dest, int seats)
    : Flight(fn, org, dest, seats)
{
}

double DomesticFlight::calculateBaseFare()
{
    return 5000.0;
}

void DomesticFlight::display()
{
    cout << "\n----- Domestic Flight -----" << endl;
    cout << "Flight Number : " << flightNumber << endl;
    cout << "Origin        : " << origin << endl;
    cout << "Destination   : " << destination << endl;
    cout << "Total Seats   : " << totalSeats << endl;
    cout << "Available     : " << availableSeats << endl;
    cout << "Base Fare     : Rs. "
         << calculateBaseFare() << endl;
}

// =====================
// International Flight
// =====================

InternationalFlight::InternationalFlight(
    string fn,
    string org,
    string dest,
    int seats)
    : Flight(fn, org, dest, seats)
{
}

double InternationalFlight::calculateBaseFare()
{
    return 20000.0;
}

void InternationalFlight::display()
{
    cout << "\n----- International Flight -----" << endl;
    cout << "Flight Number : " << flightNumber << endl;
    cout << "Origin        : " << origin << endl;
    cout << "Destination   : " << destination << endl;
    cout << "Total Seats   : " << totalSeats << endl;
    cout << "Available     : " << availableSeats << endl;
    cout << "Base Fare     : Rs. "
         << calculateBaseFare() << endl;
}

