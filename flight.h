#ifndef FLIGHT_H
#define FLIGHT_H
 
#include <iostream>
#include <string>
 
// ============================================================
//  ABSTRACT BASE CLASS: Flight
//  - Holds common data for every type of flight
//  - Pure virtual functions force derived classes to provide
//    their own pricing and display logic  (Abstraction)
// ============================================================
 
class Flight {
protected:
    // protected ? derived classes can read these directly
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureDate;   // "YYYY-MM-DD"
    std::string departureTime;   // "HH:MM"
    int totalSeats;
    int availableSeats;
 
public:
    // ---------- Constructor ----------
    Flight(const std::string& flightNum,
           const std::string& orig,
           const std::string& dest,
           const std::string& date,
           const std::string& time,
           int seats);
 
    // ---------- Virtual Destructor ----------
    // Always needed in a base class that uses virtual functions
    virtual ~Flight();
 
    // ---------- Pure Virtual Functions ----------
    // Every derived class MUST override these
    virtual double calculateBaseFare() const = 0;
    virtual void   displayDetails()   const = 0;
 
    // ---------- Common Operations ----------
    // These are the same for all flight types
    bool bookSeat();        // reduces availableSeats by 1
    bool cancelSeat();      // increases availableSeats by 1
    bool isFull()  const;
    bool hasAvailableSeats() const;
 
    // ---------- Getters (Encapsulation) ----------
    std::string getFlightNumber()  const;
    std::string getOrigin()        const;
    std::string getDestination()   const;
    std::string getDepartureDate() const;
    std::string getDepartureTime() const;
    int         getTotalSeats()    const;
    int         getAvailableSeats() const;
    int         getBookedSeats()   const;   // total - available
    double      getOccupancyPct()  const;   // booked/total * 100
 
    // ---------- Setters ----------
    void setDepartureDate(const std::string& date);
    void setDepartureTime(const std::string& time);
 
    // ---------- Operator Overloading ----------
    // << lets us do:  cout << flightObject;
    friend std::ostream& operator<<(std::ostream& os, const Flight& f);
 
    // == compares two flights by flight number
    bool operator==(const Flight& other) const;
};
 
#endif // FLIGHT_H
