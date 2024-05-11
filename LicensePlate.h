#pragma once
#include <iostream>
#include "Ticket.h"

using namespace std;

class LicensePlate
{
private:
	string plateNumber;
    string ownerName;
    Ticket violationRecord[100] = {};
    int numOfTicket;

public:
    LicensePlate();
    // Default constructor    // Default constructor

    void setPlateNumber(const string& plate); 
    // Mutator for plateNumber

    string getPlateNumber() const; 
    // Accesser for plateNumber

    void setOwnerName(const string& name);
    // Mutator for owner name

    string getOwerName() const;
    // Accesser for owner name

    bool isValid() const; 
    // Method to check if the plate number is valid

    void display();
    // Display the information of the license plate

    void addViolation(Ticket type);
    // Add Violation to the ticket
};

