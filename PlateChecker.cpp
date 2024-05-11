#include "PlateChecker.h"

void PlateChecker::addPlate(LicensePlate plate)
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


bool PlateChecker::searchPlate(LicensePlate plate)
{
	// If the license number is in the system
	return dataBase.count(plate.getPlateNumber()) ? true : false;
}


// Display all the licensePlate in the system
void PlateChecker::displayAll()
{
	for (auto it = dataBase.begin(); it != dataBase.end(); it++)
		it->second.display();		
}


void PlateChecker::deletePlate(LicensePlate plate)
{
	dataBase.erase(plate.getPlateNumber());
}


void PlateChecker::saveToFile() const
{

}


void PlateChecker::loadFromFile() 
{

}
