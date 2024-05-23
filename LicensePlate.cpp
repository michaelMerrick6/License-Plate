
#include "LicensePlate.h"


// Copy constructor
LicensePlate::LicensePlate(const LicensePlate& other)
	: plateNumber(other.plateNumber), ownerName(other.ownerName), violationRecord(other.violationRecord), numOfTicket(other.numOfTicket) {}

// Copy assignment operator
LicensePlate& LicensePlate::operator=(const LicensePlate& other)
{
	if (this == &other)
	{
		return *this;
	}
	plateNumber = other.plateNumber;
	ownerName = other.ownerName;
	violationRecord = other.violationRecord;
	numOfTicket = other.numOfTicket;
	return *this;
}

// Destructor
LicensePlate::~LicensePlate() {}


LicensePlate::LicensePlate()
{
	plateNumber = "0000AAA";
	ownerName = "Unknown";
	numOfTicket = 0;
}




void LicensePlate::setPlateNumber(const string& plate)
{
	plateNumber = plate;
}


string LicensePlate::getPlateNumber() const
{
	return plateNumber;
}


void LicensePlate::setOwnerName(const string& name)
{
	ownerName = name;
}


string LicensePlate::getOwnerName() const
{
	return ownerName;
}


void LicensePlate::displayInformation() const
{
	cout << "\n\tLicense number  : " << plateNumber;
	cout << "\n\tOwner name      : " << ownerName;
	cout << "\n\tViolation Record: ";

	if (numOfTicket == 0)
		cout << "\n\t\tNo Violation";
	else
	{
		for (int i = 0; i < numOfTicket; i++)
			cout << "\n\t\t" << i + 1 << " " << violationRecord[i];
	}

	cout << "\n\n";
}


void LicensePlate::addViolation(Ticket type)
{
	violationRecord.push_back(type);
	numOfTicket++;
}


void LicensePlate::displayTicket()
{
	if (numOfTicket == 0)
		cout << "\n\t\tNo Violation";
	else
	{
		for (int i = 0; i < numOfTicket; i++)
			cout << "\n\t\t" << i + 1 << " " << violationRecord[i];
	}
}

int LicensePlate::getNumOfTicket() const
{
	return numOfTicket;
}

void LicensePlate::removeTicket(int index)
{
	violationRecord.erase(violationRecord.begin() + index);
	numOfTicket--;
}

const vector<Ticket>& LicensePlate::getViolationRecord() const
{
	return violationRecord;
}

