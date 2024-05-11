#pragma once
#include <iostream>
#include <unordered_map>
#include "LicensePlate.h"

using namespace std;


class PlateChecker
{
private: 
	unordered_map<string, LicensePlate> dataBase;	
	// A hash table structure that store record of all licensePlate 

public:
	void addPlate(LicensePlate plate);
	// Add new licnese plate number and its associated information

	bool searchPlate(LicensePlate plate);
	// Return wheter an plateNumber is in the system

	void deletePlate(LicensePlate plate);
	// Delete an plateNumber

	void displayAll();
	// Display all license plate number in the system

	void saveToFile() const;

	void loadFromFile();


};

