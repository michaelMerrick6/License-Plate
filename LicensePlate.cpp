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


void LicensePlate::setOwnerName(const string& name)
{
	ownerName = name;
}


string LicensePlate::getOwnerName() const
{
	return ownerName;
}


void LicensePlate::displayInformation()
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
