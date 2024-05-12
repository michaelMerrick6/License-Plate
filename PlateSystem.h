#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "LicensePlate.h"

using namespace std;


class PlateSystem
{
private: 
	unordered_map<string, LicensePlate> dataBase;	
	// A hash table structure that store record of all licensePlate 

public:
	void addPlate(LicensePlate plate);
	// Add new licnese plate number and its associated information

	bool searchPlate(string plateNumber);
	// Return wheter an plateNumber is in the system based on license plate

	void deletePlate(string plate);
	// Delete an plateNumber based on license plate number

	void deleteAll();
	// Delete all license plate number in the system

	void displayPlate(string plateNumber);
	// Display the plate in the system based on plateNumber

	void displayAll();
	// Display all license plate number in the system

	int size();
	// Return number of licnese stored in the system

	bool isEmpty();
	// Check if the dataBase is empty

	LicensePlate valueAt(string key);
	// Return a license plate value if the data base has it

	void updateLicenseInformation(LicensePlate plate, string key);
	// Update the license number that are already in the dataBase

	//void saveToFile() const;

	//void loadFromFile();


};

