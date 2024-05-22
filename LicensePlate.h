#pragma once
#include <iostream>
#include <vector>

#include "Ticket.h"

using namespace std;

class LicensePlate
{
private:
    string plateNumber;
    string ownerName;
    vector<Ticket> violationRecord = {};
    int numOfTicket;

public:
    LicensePlate();
    // Default constructor    // Default constructor

  // Constructor with parameters for plate number and owner name
    LicensePlate(const string& plate, const string& name);



    void setPlateNumber(const string& plate);
    // Mutator for plateNumber

    string getPlateNumber() const;
    // Accesser for plateNumber

    void setOwnerName(const string& name);
    // Mutator for owner name

    string getOwnerName() const;
    // Accesser for owner name

    int getNumOfTicket() const;
    // Display number of ticket the license has

    void displayInformation() const; 
    // Display the information of the license plate

    void displayTicket();
    // Display all the ticket information of the license plate

    void addViolation(Ticket type);
    // Add Violation to the ticket

    void removeTicket(int index);

    const vector<Ticket>& getViolationRecord() const;
    // Accessor for violationRecord

};



