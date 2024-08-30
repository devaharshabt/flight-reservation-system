#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class
class User {
public:
    string name;

    User(string n) : name(n) {}
};

// Derived class
class Passenger : public User {
public:
    int seatNumber;
    string flightNumber;

    Passenger(string n, int sn, string fn)
        : User(n), seatNumber(sn), flightNumber(fn) {}

    void display() {
        cout << "Name: " << name << ", Seat Number: " << seatNumber << ", Flight Number: " << flightNumber << "\n";
    }
};

class Flight {
public:
    string flightNumber;
    string destination;
    string departureTime;
    int availableSeats;
    double distance;

    Flight(string fn, string dest, string dt, int seats, double dist)
        : flightNumber(fn), destination(dest), departureTime(dt), availableSeats(seats), distance(dist) {}

    void display() {
        cout << "Flight No: " << flightNumber << ", Dest: " << destination << ", Time: " << departureTime << ", Seats: " << availableSeats << ", Distance: " << distance << "km \n";
    }
};

class FlightReservationSystem {
private:
    vector<Flight> flights;
    vector<Passenger> passengers;

public:
    void addFlight(Flight flight) {
        flights.push_back(flight);
    }

    void addPassenger(Passenger passenger) {
        passengers.push_back(passenger);
    }

    void showFlights() {
        cout << "Welcome to rakshita flights \n Available Flights:\n";
        for (size_t i = 0; i < flights.size(); ++i) {
            flights[i].display();
        }
    }

    void showPassengers() {
        cout << "Passengers:\n";
        for (size_t i = 0; i < passengers.size(); ++i) {
            passengers[i].display();
        }
    }

    bool isSeatAvailable(string flightNumber, int seatNumber) {
        for (size_t i = 0; i < passengers.size(); ++i) {
            if (passengers[i].flightNumber == flightNumber && passengers[i].seatNumber == seatNumber) {
                return false;
            }
        }
        return true;
    }

    void showAvailableFlightNumbers() {
        cout << "Available Flight Numbers:\n";
        for (size_t i = 0; i < flights.size(); ++i) {
            cout << flights[i].flightNumber << "\n";
        }
    }
};

int main() {
	
    FlightReservationSystem fss;

    // Add your flights
    fss.addFlight(Flight("A1", "raichur - bellary", "09:45 PM", 50, 200.1));
    fss.addFlight(Flight("B2", "bellary - bengaluru", "3:30 AM", 30, 300.2));

    fss.showFlights();

    string name;
    int seatNumber;
    string flightNumber;

    cout << "Enter passenger name: ";
    getline(cin, name);

    cout << "Enter flight number: ";
    getline(cin, flightNumber);

    cout << "Enter seat number: ";
    cin >> seatNumber;


    if (fss.isSeatAvailable(flightNumber, seatNumber)) {

        fss.addPassenger(Passenger(name, seatNumber, flightNumber));
        cout << " Booked Passenger successfully!\n";
    } else {
        cout << "Seat is already booked. Please choose a different seat.\n";
    }

    fss.showPassengers();

    return 0;
}
