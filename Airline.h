#include "Airline.h"
#include <fstream>
#include <stdexcept>

Airline::Airline()
{
}


// Add Flight


void Airline::addFlight()
{
    int type;
    string fn, org, dest;
    int seats;

    cout << "\n1. Domestic Flight";
    cout << "\n2. International Flight";
    cout << "\nEnter choice: ";
    cin >> type;

    cout << "Flight Number: ";
    cin >> fn;

    cout << "Origin: ";
    cin >> org;

    cout << "Destination: ";
    cin >> dest;

    cout << "Total Seats: ";
    cin >> seats;

    if (type == 1)
    {
        flights.push_back(
            new DomesticFlight(fn, org, dest, seats));
    }
    else if (type == 2)
    {
        flights.push_back(
            new InternationalFlight(fn, org, dest, seats));
    }
    else
    {
        cout << "Invalid flight type.\n";
        return;
    }

    cout << "Flight added successfully.\n";
}


// Show Flights


void Airline::showFlights()
{
    if (flights.empty())
    {
        cout << "No flights available.\n";
        return;
    }

    for (size_t i = 0; i < flights.size(); i++)
    {
        cout << "\nFlight Index: " << i << endl;
        flights[i]->display();
    }
}


// Add Passenger


void Airline::addPassenger()
{
    int type;
    string name, id;

    cout << "\n1. Economy";
    cout << "\n2. Business";
    cout << "\n3. First Class";
    cout << "\nEnter choice: ";
    cin >> type;

    cout << "Passenger Name: ";
    cin >> name;

    cout << "Passenger ID: ";
    cin >> id;

    switch (type)
    {
    case 1:
        passengers.push_back(
            new EconomyPassenger(name, id));
        break;

    case 2:
        passengers.push_back(
            new BusinessPassenger(name, id));
        break;

    case 3:
        passengers.push_back(
            new FirstClassPassenger(name, id));
        break;

    default:
        cout << "Invalid choice.\n";
        return;
    }

    cout << "Passenger added successfully.\n";
}


// Show Passengers


void Airline::showPassengers()
{
    if (passengers.empty())
    {
        cout << "No passengers available.\n";
        return;
    }

    for (size_t i = 0; i < passengers.size(); i++)
    {
        cout << "\nPassenger Index: " << i << endl;
        passengers[i]->display();
    }
}


// Book Ticket


void Airline::bookTicket()
{
    if (flights.empty())
    {
        cout << "No flights available.\n";
        return;
    }

    if (passengers.empty())
    {
        cout << "No passengers available.\n";
        return;
    }

    showFlights();
    int flightIndex;

    cout << "\nSelect Flight Index: ";
    cin >> flightIndex;

    if (flightIndex < 0 ||
        flightIndex >= (int)flights.size())
    {
        cout << "Invalid flight selection.\n";
        return;
    }

    showPassengers();
    int passengerIndex;

    cout << "\nSelect Passenger Index: ";
    cin >> passengerIndex;

    if (passengerIndex < 0 ||
        passengerIndex >= (int)passengers.size())
    {
        cout << "Invalid passenger selection.\n";
        return;
    }

    string seat;

    cout << "Seat Number: ";
    cin >> seat;

    try
    {
        flights[flightIndex]->bookSeat();

        Ticket* t =
            new Ticket(
                flights[flightIndex],
                passengers[passengerIndex],
                seat);

        tickets.push_back(t);

        cout << "Ticket booked successfully.\n";
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}


// Cancel Ticket


void Airline::cancelTicket()
{
    if (tickets.empty())
    {
        cout << "No tickets available.\n";
        return;
    }

    showTickets();

    int index;

    cout << "\nEnter Ticket Index: ";
    cin >> index;

    if (index < 0 ||
        index >= (int)tickets.size())
    {
        cout << "Invalid ticket index.\n";
        return;
    }

    tickets[index]->cancel();
}


// Show Tickets


void Airline::showTickets()
{
    if (tickets.empty())
    {
        cout << "No tickets booked.\n";
        return;
    }

    for (size_t i = 0; i < tickets.size(); i++)
    {
        cout << "\nTicket Index: " << i << endl;
        tickets[i]->display();
    }
}

// =====================
// Occupancy Report
// =====================

void Airline::report()
{
    if (flights.empty())
    {
        cout << "No flights available.\n";
        return;
    }

    cout << "\n===== Occupancy Report =====\n";

    for (size_t i = 0; i < flights.size(); i++)
    {
        double occupancy =
            ((double)(flights[i]->getTotalSeats() -
            flights[i]->getAvailableSeats())
            / flights[i]->getTotalSeats()) * 100;

        cout << "Flight: "
             << flights[i]->getFlightNumber()
             << " | Occupancy: "
             << occupancy << "%\n";
    }
}


// Save Data


void Airline::saveData()
{
    ofstream file("tickets.txt");

    if (!file)
    {
        cout << "File could not be opened.\n";
        return;
    }

    for (size_t i = 0; i < tickets.size(); i++)
    {
        file << tickets[i]->getPassengerId()
             << " "
             << tickets[i]->getFlightNumber()
             << " "
             << tickets[i]->getSeatNumber()
             << " "
             << tickets[i]->getFare()
             << endl;
    }

    file.close();

    cout << "Data saved successfully.\n";
}


// Destructor


Airline::~Airline()
{
    for (size_t i = 0; i < flights.size(); i++)
        delete flights[i];

    for (size_t i = 0; i < passengers.size(); i++)
        delete passengers[i];

    for (size_t i = 0; i < tickets.size(); i++)
        delete tickets[i];
}

