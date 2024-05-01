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
