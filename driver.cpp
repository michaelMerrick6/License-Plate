#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct VehicleDetails {
    string color;
    string make;
    string model; 
vector<violationDetails> violations;
};

struct violationDetails {
    string ticketStrategy;
    string violation;
    string date;
    int ticketCount = 0;
};

class OCSystem {
private:
    unordered_map<string, VehicleDetails> plateTable;
    const string fileName = "license_plates.txt";

public:
    OCSystem() {
        loadFromFile();
    }

    bool searchPlate(const string& plate) const {
        return plateTable.find(plate) != plateTable.end();
    }

    void addPlate(const string& plate) {
        if (searchPlate(plate)) {
            cout << "Plate already exists in the system." << endl;
            return;
        }
        VehicleDetails details;
        cout << "Enter vehicle details:" << endl;
        cout << "Color: ";
        cin >> details.color;
        cout << "Make: ";
        cin >> details.make;
        cout << "Model: ";
        cin >> details.model;
        cout << "Ticket Strategy: ";
        cin >> details.ticketStrategy;
        cout << "Violation: ";
        cin >> details.violation;
        details.ticketCount++;
        plateTable[plate] = details;
        cout << "Plate added successfully." << endl;
        saveToFile();
    }

    void addViolation(const string& plate) {
        if (!searchPlate(plate)) {
            cout << "Plate not found in the system." << endl;
            return;
        }
        VehicleDetails& details = plateTable[plate];
        cout << "Enter violation details:" << endl;
        cout << "Violation: ";
        cin >> details.violation;
        cout << "Ticket Strategy: ";
        cin >> details.ticketStrategy;
        details.ticketCount++;
        cout << "Violation added successfully." << endl;
    }

    void displayInfo(const string& plate) const {
        if (!searchPlate(plate)) {
            cout << "Plate not found in the system." << endl;
            return;
        }
        const VehicleDetails& details = plateTable.at(plate);
        cout << "Plate: " << plate << endl;
        cout << "Number of Tickets: " << details.ticketCount << endl;
        cout << "Color: " << details.color << endl;
        cout << "Make: " << details.make << endl;
        cout << "Model: " << details.model << endl;
        cout << "Ticket Strategy: " << details.ticketStrategy << endl;
        cout << "Violation: " << details.violation << endl;
    }

    void saveToFile() const {
        ofstream outputFile(fileName);
        if (outputFile.is_open()) {
            for (const auto& entry : plateTable) {
                outputFile << entry.first << " " << entry.second.color << " " << entry.second.make << " "
                    << entry.second.model << " " << entry.second.ticketStrategy << " " << entry.second.violation << " "
                    << entry.second.ticketCount << endl;
            }
            cout << "Data saved to file successfully." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }

    void loadFromFile() {
        ifstream inputFile(fileName);
        if (inputFile.is_open()) {
            plateTable.clear();
            string plate, color, make, model, ticketStrategy, violation;
            int ticketCount;
            while (inputFile >> plate >> color >> make >> model >> ticketStrategy >> violation >> ticketCount) {
                VehicleDetails plateDetails;
                plateDetails.color = color;
                plateDetails.make = make;
                plateDetails.model = model;
                plateDetails.ticketStrategy = ticketStrategy;
                plateDetails.violation = violation;
                plateDetails.ticketCount = ticketCount;
                plateTable[plate] = plateDetails;
            }
            cout << "Data loaded from file successfully." << endl;
        }
        else {
            cout << "Unable to open file. Creating new file." << endl;
        }
    }
};

char menuOption() {
    cout << "\nOptions:" << endl;
    cout << "1. Look up license plate" << endl;
    cout << "2. Add new plate" << endl;
    cout << "3. Add violation" << endl;
    cout << "4. Save to file" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter option: ";
    char option;
    cin >> option;
    return option;
}

int main() {
    OCSystem obj;
    char option;
    do {
        option = menuOption();
        switch (option) {
        case '1': {
            string plate;
            cout << "Enter Plate: ";
            cin >> plate;
            obj.displayInfo(plate);
            break;
        }
        case '2': {
            string plate;
            cout << "Enter Plate: ";
            cin >> plate;
            obj.addPlate(plate);
            break;
        }
        case '3': {
            string plate;
            cout << "Enter Plate: ";
            cin >> plate;
            obj.addViolation(plate);
            break;
        }
        case '4':
            obj.saveToFile();
            break;
        case '5':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please enter again." << endl;
            break;
        }
    } while (option != '5');

    return 0;
}

