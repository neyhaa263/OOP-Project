#include <iostream>
#include "Airline.h"

using namespace std;

int main()
{
    Airline airline;
    int choice;

    do
    {
        cout << "\n=================================";
        cout << "\n AIRLINE RESERVATION SYSTEM";
        cout << "\n=================================";
        cout << "\n1. Add Flight";
        cout << "\n2. Add Passenger";
        cout << "\n3. Show Flights";
        cout << "\n4. Show Passengers";
        cout << "\n5. Book Ticket";
        cout << "\n6. Show Tickets";
        cout << "\n7. Cancel Ticket";
        cout << "\n8. Occupancy Report";
        cout << "\n9. Save Data";
        cout << "\n0. Exit";
        cout << "\n\nEnter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            airline.addFlight();
            break;

        case 2:
            airline.addPassenger();
            break;

        case 3:
            airline.showFlights();
            break;

        case 4:
            airline.showPassengers();
            break;

        case 5:
            airline.bookTicket();
            break;

        case 6:
            airline.showTickets();
            break;

        case 7:
            airline.cancelTicket();
            break;

        case 8:
            airline.report();
            break;

        case 9:
            airline.saveData();
            break;

        case 0:
            cout << "\nThank you for using Airline Reservation System.\n";
            break;

        default:
            cout << "\nInvalid Choice. Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}

