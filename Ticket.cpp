#include "Ticket.h"

// Constructor
Ticket::Ticket(Flight* f, Passenger* p, string seat)
{
    flight = f;
    passenger = p;
    seatNumber = seat;
    status = "Booked";

    fare = flight->calculateBaseFare() *
           (1 - passenger->getDiscount());
}

// Cancel Ticket
void Ticket::cancel()
{
    if (status == "Cancelled")
    {
        cout << "Ticket is already cancelled." << endl;
        return;
    }

    status = "Cancelled";

    double refund =
        fare * passenger->refundPercent();

    flight->cancelSeat();

    cout << "Ticket cancelled successfully." << endl;
    cout << "Refund Amount: Rs. "
         << refund << endl;
}

// Display Ticket
void Ticket::display() const
{
    cout << "\n========== Ticket ==========" << endl;

    cout << "Passenger : "
         << passenger->getName() << endl;

    cout << "Passenger ID : "
         << passenger->getId() << endl;

    cout << "Flight Number : "
         << flight->getFlightNumber() << endl;

    cout << "Seat Number : "
         << seatNumber << endl;

    cout << "Fare : Rs. "
         << fare << endl;

    cout << "Status : "
         << status << endl;

    cout << "============================" << endl;
}

// Getters
double Ticket::getFare() const
{
    return fare;
}

string Ticket::getSeatNumber() const
{
    return seatNumber;
}

string Ticket::getStatus() const
{
    return status;
}

string Ticket::getPassengerId() const
{
    return passenger->getId();
}

string Ticket::getFlightNumber() const
{
    return flight->getFlightNumber();
}

