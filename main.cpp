#include <iostream>
#include "input.h"
using namespace std;
int menuOption();

void LookUpLicensePlate();
void SaveLicensePlate();
void LoadLicensePlate();

int main()
{
    do
    {
        system("cls");
        switch (toupper(menuOption()))
        {
        case 'X': exit(1); break;
        case 'A': LookUpLicensePlate(); break;
        case 'B': SaveLicensePlate(); break;
        case 'C': LoadLicensePlate(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    cout << "\n\tCMPR131 - Final : License Plate Look Up by Group 2 (5/1/2024)";
    cout << "\n\t======================================================================================";
    cout << "\n\t\tA.Look up license plate";
    cout << "\n\t--------------------------------------------------------------------------------------";
    cout << "\n\t\tB.Save license plate to file";
    cout << "\n\t\tC.Load license plate from file";
    cout << "\n\t--------------------------------------------------------------------------------------";
    cout << "\n\t\tX.Exit";
    cout << "\n\t======================================================================================";

    return inputChar("\n\t\tOption: ", static_cast<string>("ABCX"));

}

void LookUpLicensePlate()
{
    int choice;
    int ticket = 0;
    string plate;
    string ticketDescription;
    do {
        plate = inputString("\n\tEnter the license plate: ", true);
        if (plate.length() > 7) 
        {
            cout << "\tUnvalid plate. Please try again.\n"; 
        }
    } while (plate.length() > 7);

    transform(plate.begin(), plate.end(), plate.begin(), ::toupper);

    //check for tickets
    do {

        system("cls");

        cout << "\n\tChecking license plate: " << plate;
        cout << "\n\t===============================================================================";
        cout << "\n\tLicense plate have " << ticket << " ticket(s)";
        cout << "\n\t-------------------------------------------------------------------------------";
        cout << "\n\t1. Add ticket";
        cout << "\n\t2. Remove ticket";
        cout << "\n\t3. Check ticket";
        cout << "\n\t-------------------------------------------------------------------------------";
        cout << "\n\t0. Return to main menu";
        cout << "\n\t===============================================================================";

        choice = inputInteger("\n\tOption: ", 0, 3);

        switch (choice)
        {
        case 1:
        {
            cout << "\n\tChoose ticket strategy: ";
            cout << "\n\tTraffic (T)";
            cout << "\n\tParking (P)";
            char type = inputChar("\n\tOption: ", static_cast<string>("TP"));

            switch (toupper(type))
            {
            case 'T':
            {
                cout << "\n\tChoose violation: ";
                cout << "\n\t1.Speeding";
                cout << "\n\t2.Running red light";
                cout << "\n\t3.DUI";
                int violation = inputInteger("\n\tOption: ", 1, 3);

                ticketDescription = string(1, toupper(type)) + to_string(violation);
                cout << "\n\tTicket [" << ticketDescription << "] added to " << plate << " successful.";
                cout << "\n\nPress any key to continue . . .";
                cin.ignore();
                break;
            }
            case 'P':
            {
                cout << "\n\tChoose violation: ";
                cout << "\n\t1.Paralized";
                cout << "\n\t2.Street wipe";
                cout << "\n\t3.Fire lane";
                int violation = inputInteger("\n\tOption: ", 1, 3);

                ticketDescription = string(1, toupper(type)) + to_string(violation);
                cout << "\n\tTicket [" << ticketDescription << "] added to " << plate << " successful.";
                cout << "\n\nPress any key to continue . . .";
                cin.ignore();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 2:
        {
        
        }
        case 3:
        {
        
        }
        case 0:
            break;
        default:
            cout << "\nInvalid choice";
            break;
        }
    } while (choice != 0);
}

void SaveLicensePlate()
{

}

void LoadLicensePlate()
{

}
