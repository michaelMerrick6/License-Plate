#include "PlateSystem.h"

void PlateSystem::addPlate(LicensePlate plate)
{
	// If the license number is alreay in the databse, display the warning
	if (dataBase.count(plate.getPlateNumber()))
	{
		cout << "\n\n\tThe license " << plate.getPlateNumber() << " already in the system";
	}
	else
	{
		// Using the license numebr as the key and added to the system
		dataBase[plate.getPlateNumber()] = plate;
	}
}


bool PlateSystem::searchPlate(string plateNumber)
{
	// If the license number is in the system
	return dataBase.count(plateNumber) ? true : false;
}


void PlateSystem::displayPlate(string plate)
{
	// If the license number is in the databse, display the information
	if (dataBase.count(plate))
		dataBase.at(plate).displayInformation();
	else
		cout << "\n\tLicense not found";
}


// Display all the licensePlate in the system
void PlateSystem::displayAll()
{
	for (auto it = dataBase.begin(); it != dataBase.end(); it++)
		it->second.displayInformation();		
}



void PlateSystem::deletePlate(string plateNumber)
{
	dataBase.erase(plateNumber);
}


bool PlateSystem::isEmpty()
{
	return dataBase.empty() ? true : false;
}

void PlateSystem::deleteAll()
{
	dataBase.clear();
}

int PlateSystem::size()
{
	return dataBase.size();
}

void PlateSystem::updateLicenseInformation(LicensePlate plate, string key)
{
	dataBase[key] = plate;
}


LicensePlate PlateSystem::valueAt(string key)
{
	// If the license number in the databse
	if (dataBase.count(key))
	{
		return dataBase.at(key);
	}
}
