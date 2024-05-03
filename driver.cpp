#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>


using namespace std;

struct details {
	vector <string> det;
	string color;
	string make;
	string model;
	string ticketStrategy;
	string violation;
	int ticketCount = 0;
};

class ocSystem {

private:
	//string plate;
	unordered_map < string, details> plateTable; // key  , index
	string fileName = "license_plates.txt";
public:
	ocSystem() {

	}
	/*
	string setPlate() {
		plate =
	}
	string getPlate() {
		return plate;
	}
*/
	bool searchPlate(string plate) {

		if (plateTable.find(plate) != plateTable.end())
		{
			int choice2;
			cout << endl << "Plate found in system would you like to display info : ";
			cout << endl << "enter 0 or 1 : ";
			cin >> choice2;
			if (choice2 == 1) {
				displayInfo(plate);
			}
			else {
				return 0;
			}
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
		details description;

		cout << "Car description: ";
		cout << "\nCar color: " ;
		cin >> description.color;
		cout << "\nCar make: ";
		cin >> description.make;
		cout << "\nCar model: ";
		cin >> description.model;
		cout << "\nCar ticketStrategy: ";
		cin >> description.ticketStrategy;
		cout << "\nViolation: ";
		cin >> description.violation;
		description.ticketCount++;

		plateTable[plate] = description;
		count++;
	}

	void addViolation(string plate, details info) {
		
		cout << "Ticket Strategy: " << info.ticketStrategy << endl;
		cout << "Violation: " << info.violation << endl;
		
	}

	void displayInfo(string plate) {
		cout << "Plate: " << plate << endl;
		cout << "Description:" << endl;
		
		details info = plateTable[plate];
		cout << "Number of Tickets : " << info.ticketCount << endl;
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

int menuOption() {
	

	string userInput;
	char option;
	cout << "\n\tCMPR131 - Final : License Plate Look Up by Group 2 (5/1/2024)";
	cout << "\n\t======================================================================================";
	cout << "\n\t\tA.Look up license plate";
	cout << "\n\t--------------------------------------------------------------------------------------";
	cout << "\n\t\tB.Save license plate to file";
	cout << "\n\t\tC.Load license plate from file";
	cout << "\n\t--------------------------------------------------------------------------------------";
	cout << "\n\t\tX.Exit";
	cout << "\n\t======================================================================================";

	cout << "\n\t\tOption: ";
	getline(cin, userInput);

	// Convert the input to uppercase for comparison
	transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

	// Check if the input is valid
	if (userInput.size() == 1 && (userInput[0] == 'A' || userInput[0] == 'B' || userInput[0] == 'C' || userInput[0] == 'X')) {
		option = userInput[0];
	}
	else {
		cout << "\n\tInvalid option. Please enter A, B, C, or X." << endl;
		// Recursively call menuOption until a valid option is entered
		option = menuOption();
	}

	return option;
}


int main()
{   string plate;
	ocSystem obj;
	do
	{
		system("cls");
		switch (toupper(menuOption()))
		{
		case 'X': exit(1); break;

		case 'A': 
			cout << "Enter Plate : ";
			cin >> plate;
			if (obj.searchPlate(plate)) {

			}
			break;

		case 'B': obj.saveToFile(); 
			break;

		case 'C': obj.loadFromFile(); 
			break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}



/*int main() {

	ocSystem obj;
	string plate;
	cout << "ENTER PLATE :  ";
	cin >> plate;
	if (obj.searchPlate(plate) == true) {
		obj.displayInfo(plate);

	}
}*/
