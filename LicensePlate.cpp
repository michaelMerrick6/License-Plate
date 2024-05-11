#include "LicensePlate.h"

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


// Method to check if the plate number is valid
bool LicensePlate::isValid() const
{
	if (plateNumber.length() > 7)
		return false;

	return true;
}


void LicensePlate::setOwnerName(const string& name)
{
	ownerName = name;
}

string LicensePlate::getOwerName() const
{
	return ownerName;
}

void LicensePlate::display()
{
	cout << "\n\tLicense number  : " << plateNumber;
	cout << "\n\tOwner name      : " << ownerName;
	cout << "\n\tViolation Record: ";
	
	if (numOfTicket == 0)
		cout << "\n\t\tNo Recorded Violation";
	else
	{
		for (int i = 0; i < numOfTicket; i++)
			cout << "\n\t\t" << violationRecord[i];
	}

	cout << "\n\n";
}

void LicensePlate::addViolation(Ticket type)
{
	violationRecord[numOfTicket] = type;
	numOfTicket++;
}

