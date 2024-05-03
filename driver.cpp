#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

struct details {
	string color;
	string make;
	string model;
	string ticketStrategy;
	string violation;


};

class ocSystem {

private:
	string plate;
	unordered_map < string, details> plateTable; // key  , index
	string fileName = "license_plates.txt";
public:
	ocSystem() {

	}
public:
	bool searchPlate(string plate) {

		if (plateTable.find(plate) != plateTable.end())
		{
			displayInfo(plate);
		}
		else {
			cout << plate << " Not Found In the OC System";
			cout << endl << "1) add or 2) no add  : ";
			int choice;
			cin >> choice;
			if (choice == 1) {
				addPlate(plate);
			}
			else
			{
				return 0;
			}
		}

	}
	void addPlate(string plate) {
		int count = 0;
		cout << "Violation : " << endl << "Car description: ";
		details description;
		cin >> description.color;
		cin >> description.make;
		cin >> description.model;
		cin >> description.ticketStrategy;
		cin >> description.violation;

		plateTable[plate] = description;
		count++;
	}
	void displayInfo(string plate) {
		cout << "Plate: " << plate << endl;
		cout << "Description:" << endl;
		
		details info = plateTable[plate];
			cout << "Color: " << info.color << endl;
			cout << "Make: " << info.make << endl;
			cout << "Model: " << info.model << endl;
			cout << "Ticket Strategy: " << info.ticketStrategy << endl;
			cout << "Violation: " << info.violation << endl;
	}
	
	void saveToFile() {
		ofstream outputFile(fileName);
		if (outputFile.is_open()) {
			for (const auto& entry : plateTable) {
				outputFile << entry.first << " " << entry.second.color << " " << entry.second.make << " "
					<< entry.second.model << " " << entry.second.ticketStrategy << " " << entry.second.violation << endl;
			}
			outputFile.close();
			cout << "Data saved to file successfully." << endl;
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}

	void loadFromFile() {
		ifstream inputFile(fileName);
		if (inputFile.is_open()) {
			plateTable.clear(); // Clear the existing contents of plateTable before loading new data
			string plate, color, make, model, ticketStrategy, violation;
			while (inputFile >> plate >> color >> make >> model >> ticketStrategy >> violation) {
				details plateDetails;
				plateDetails.color = color;
				plateDetails.make = make;
				plateDetails.model = model;
				plateDetails.ticketStrategy = ticketStrategy;
				plateDetails.violation = violation;
				plateTable[plate] = plateDetails;
			}
			inputFile.close();
			cout << "Data loaded from file successfully." << endl;
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}


};

int main() {

	ocSystem obj;
	string plate;
	cout << "ENTER PLATE :  ";
	cin >> plate;
	if (obj.searchPlate(plate) == true) {
		obj.displayInfo(plate);

	}
}


/*
#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

class ocSystem {

private:
	string plate;
	unordered_map < string, string> plateTable; // key  , index
public:
	ocSystem() {
		
	}
public:
	bool searchPlate(string plate) {
		
		if (plateTable.find(plate) != plateTable.end())
		{
			return 1;
		}
		else {
				return 0;
			}
		
	}
	void addPlate(string plate) {
		int count = 0; 
		cout << "Violation : " << endl << "Car description: ";
		string description;
		cin >> description;
		plateTable[plate] = description;
		count++;
	}
	void displayInfo(string plate) {

		cout << "Plate: " << plate;
		cout << "Description" << plateTable[plate];
	}
	void saveLicensePlatesToFile(){}
	void loadLicensePlatesFromFile(){}
};

int main() {

	ocSystem obj;
	string plate;
	cout << "ENTER PLATE :  ";
	cin >> plate;
	if ( obj.searchPlate(plate) == true) {
		obj.displayInfo(plate);
	}
	else {
		cout << plate << " Not Found In the OC System";
		cout << endl << "1) add or 2) no add  : ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			obj.addPlate(plate);
		}
		else
		{
			return 0;
		}
	}

}
*/
