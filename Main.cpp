#include <iostream>
#include <regex>

#include "input.h"
#include "PlateSystem.h"
#include "LicensePlate.h"
#include "Ticket.h"

using namespace std;

int menuOption(PlateSystem& obj);

void Case1(PlateSystem& obj);   // Add license
void Case2(PlateSystem& obj);   // Update Information 
void Case3(PlateSystem& obj);   // Look up license
void Case4(PlateSystem& obj);   // Display all license in the system 
void Case5(PlateSystem& obj);   // Remove a license
void Case6(PlateSystem& obj);   // Delete all license in the system
void Case7(PlateSystem& obj);
void Case8(PlateSystem& obj);

void editTicket(LicensePlate& obj);

void addTicketCase(LicensePlate& obj);
void removeTicketCase(LicensePlate& obj);
void checkTicketCase(LicensePlate& obj);

void UpdateViolationCase(LicensePlate& obj);
void UpdateOwnerNameCase(LicensePlate& obj);

string licensePattern();        // Check if the license is in the format 0AAA000


int main()
{
    PlateSystem Container;

    do
    {
        switch (menuOption(Container))
        {
        case 0: exit(0); break;
        case 1: Case1(Container); break;
        case 2: Case2(Container); break;
        case 3: Case3(Container); break;
        case 4: Case4(Container); break;
        case 5: Case5(Container); break;
        case 6: Case6(Container); break;
        case 7: Case7(Container); break;
        case 8: Case8(Container); break;


        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

// Display main menu option
int menuOption(PlateSystem& obj)
{
    system("cls");

    cout << "\n\tCMPR131 - Final : License Plate Look Up by Group 2 (5/29/2024)";
    cout << "\n\n\t\033[94mDataBase size: " << obj.size() << "\033[0m";

    cout << "\n\t" << string(85, char(205));
    cout << "\n\t\t1. Add license plate";
    cout << "\n\t\t2. Update information";
    cout << "\n\t\t3. Look up license plate";
    cout << "\n\t\t4. Display all";
    cout << "\n\t\t5. Remove license plate";
    cout << "\n\t\t6. Remove all license plate";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t\t7. Read from file";
    cout << "\n\t\t8. Save to file";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t\t0. Exit";
    cout << "\n\t" << string(85, char(205));

    return inputInteger("\n\t\tOption: ", 0, 8);
}


// Add the license plate to the system 
void Case1(PlateSystem& obj)
{
    system("cls");

    LicensePlate user;

    string plate = licensePattern();

    if (!obj.searchPlate(plate))
    {
        // Set information of License object
        user.setPlateNumber(plate);
        user.setOwnerName(inputString("\n\tEnter the Owner Name : ", true));
        editTicket(user);

        // Add the license plate to the dataBase
        obj.addPlate(user);
    }
    else
    {
        cout << "\n\tThe license is already in record";
    }

}

// Add Violation to the license
void editTicket(LicensePlate& obj)
{
    int choice;

    do {
        system("cls");
        cout << "\n\t1. Add ticket";
        cout << "\n\t2. Remove ticket";
        cout << "\n\t3. Check ticket";
        cout << "\n\t" << string(85, char(196));
        cout << "\n\t0. Exit";
        cout << "\n\t" << string(85, char(196));

        choice = inputInteger("\n\tOption: ", 0, 3);

        switch (choice)
        {
        case 1: addTicketCase(obj); break;
        case 2: removeTicketCase(obj); break;
        case 3: checkTicketCase(obj); break;
        case 0: return;
            break;
        default:
            cout << "\nInvalid choice";
            break;
        }
        cout << "\n";
        system("pause");
    } while (choice != 0);
}



string licensePattern()
{
    // Define regex pattern for license plate format
    regex pattern("^[0-9][A-Z]{3}[0-9]{3}$");

    string input;

    do {
        // Prompt for license plate
        input = inputString("\n\tEnter the License    : ", true);

        // Convert to uppercase
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        // Check if the entered plate matches the pattern
        if (!regex_match(input, pattern)) {
            cout << "\n\tInvalid format. The valid format is 0AAA000. Please try again.\n";
        }

    } while (!regex_match(input, pattern));

    return input;
}

void addTicketCase(LicensePlate& obj)
{
    system("cls");

    cout << "\n\tChoose violation";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t1. Speeding";
    cout << "\n\t2. Running red light";
    cout << "\n\t3. Driving Under Influence";
    cout << "\n\t4. Parking Handicapped Zone";
    cout << "\n\t5. Parking during Street wipe";
    cout << "\n\t6. Parking Fire lane";
    cout << "\n\t" << string(85, char(205));
    int choice = inputInteger("\n\tOption: ", 1, 6);

    Ticket ticket;

    switch (choice)
    {
    case 1:
    {
        ticket.setViolation(ViolationType::SPEEDING);
        obj.addViolation(ticket);
    }
    break;
    case 2:
    {
        ticket.setViolation(ViolationType::RUNNING_RED_LIGHT);
        obj.addViolation(ticket);
    }
    break;
    case 3:
    {
        ticket.setViolation(ViolationType::DRIVING_UNDER_INFLUENCE);
        obj.addViolation(ticket);
    }
    break;
    case 4:
    {
        ticket.setViolation(ViolationType::PARKING_HANDICAPPED_ZONE);
        obj.addViolation(ticket);
    }
    break;
    case 5:
    {
        ticket.setViolation(ViolationType::PARKING_STREET_SWEEPING);
        obj.addViolation(ticket);
    }
    break;
    case 6:
    {
        ticket.setViolation(ViolationType::PARKING_FIRE_LANE);
        obj.addViolation(ticket);
    }
    break;
    }

    // Display a list of ticket
    obj.displayTicket();
}

void removeTicketCase(LicensePlate& obj)
{
    if (obj.getNumOfTicket() == 0)
    {
        cout << "\n\tThe license has no ticket";
    }
    else
    {
        // Display a list of ticket
        obj.displayTicket();

        int option = inputInteger("\n\tEnter a number to remove: ", 1, obj.getNumOfTicket());

        // Remove a ticket
        obj.removeTicket(option - 1);

        cout << "\n\tThe current record: ";
        obj.displayTicket();
    }

}

void checkTicketCase(LicensePlate& obj)
{
    if (obj.getNumOfTicket() == 0)
    {
        cout << "\n\tThe license has no ticket";
    }
    else
    {
        // Display a list of ticket
        obj.displayTicket();
    }
}


void Case2(PlateSystem& obj)
{
    if (obj.isEmpty())
    {
        cout << "\n\tEmpty dataBase";
        return;
    }

    string plate = licensePattern();

    if (!obj.searchPlate(plate))
    {
        cout << "\n\tThe license is not on dataBase";
        return;
    }

    // Assign the value of license to user
    LicensePlate user = obj.valueAt(plate);

    int choice;

    do {
        system("cls");
        cout << "\n\t1. Update Owner Name";
        cout << "\n\t2. Update Violation";
        cout << "\n\t" << string(85, char(196));
        cout << "\n\t0. Exit";
        cout << "\n\t" << string(85, char(196));

        choice = inputInteger("\n\tOption: ", 0, 2);

        switch (choice)
        {
        case 1:
        {
            UpdateOwnerNameCase(user);
            obj.updateLicenseInformation(user, plate);
        }
        break;
        case 2:
        {
            UpdateViolationCase(user);
            obj.updateLicenseInformation(user, plate);
        }
        break;
        case 0: return;
            break;
        default:
            cout << "\nInvalid choice";
            break;
        }
        cout << "\n";
        system("pause");
    } while (choice != 0);
}

void UpdateViolationCase(LicensePlate& obj)
{
    editTicket(obj);

    cout << "\n\tThe updated information";
    obj.displayInformation();

}


void UpdateOwnerNameCase(LicensePlate& obj)
{
    obj.setOwnerName(inputString("\n\tEnter the new name : ", true));

    cout << "\n\tThe updated information";
    obj.displayInformation();

}

// Look up license
void Case3(PlateSystem& obj)
{
    if (obj.isEmpty())
    {
        cout << "\n\tCan not look up an empty dataBase";
        return;
    }

    LicensePlate user;

    string plate = licensePattern();

    // Set the information of License object
    user.setPlateNumber(plate);

    if (obj.searchPlate(plate))
    {
        obj.displayPlate(user.getPlateNumber());
    }
    else
    {
        cout << "\n\tThe license is not on dataBase";
    }
}

// Display all license in the system
void Case4(PlateSystem& obj)
{
    if (obj.isEmpty())
    {
        cout << "\n\tCan not display an empty dataBase";
        return;
    }

    obj.displayAll();
}

// Delete a license in the system
void Case5(PlateSystem& obj)
{
    if (obj.isEmpty())
    {
        cout << "\n\tThe dataBase is already empty";
        return;
    }

    string plate = licensePattern();

    if (obj.searchPlate(plate))
    {
        obj.deletePlate(plate);
        cout << "\n\tSuccesfullt delete license information";
    }
    else
    {
        cout << "\n\tThe license is not on dataBase";
    }

}


// Delete all license in the system
void Case6(PlateSystem& obj)
{
    if (obj.isEmpty())
    {
        cout << "\n\tThe dataBase is already empty";
        return;
    }

    obj.deleteAll();
    cout << "\n\tSuccesfullt delete all license information";

}

void Case7(PlateSystem& obj) { // Read from file
    string filename = "C:\\Users\\alber_6h954kk\\OneDrive\\Desktop\\CMPR131\\licenseplate.txt";
    obj.loadFromFile(filename);
    cout << "\n\tData loaded successfully from " << filename;
}

void Case8(PlateSystem& obj) { // Save to file
    string filename = "C:\\Users\\alber_6h954kk\\OneDrive\\Desktop\\CMPR131\\licenseplate.txt";
    obj.saveToFile(filename);
    cout << "\n\tData saved successfully to " << filename;
