
#include "PlateSystem.h"
#include <string> // Include this for getline function


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



// Default value for unknown violation type
const ViolationType DEFAULT_VIOLATION_TYPE = ViolationType::DEFAULT;

void PlateSystem::loadFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "\n\tError: Unable to open file \"" << filename << "\"";
        return;
    }

    string line;
    string plateNumber;
    string ownerName;
    int numOfTickets;
    string violationType;

    while (getline(file, line))
    {
        if (line.find("License number") != string::npos)
        {
            // Extract license number
            plateNumber = line.substr(line.find(":") + 2);
        }
        else if (line.find("Owner name") != string::npos)
        {
            // Extract owner name
            ownerName = line.substr(line.find(":") + 2);
        }
        else if (line.find("Violation Record") != string::npos)
        {
            // Extract number of tickets
            numOfTickets = stoi(line.substr(line.find(":") + 2));

            // Create a new LicensePlate object
            LicensePlate plate;
            plate.setPlateNumber(plateNumber);
            plate.setOwnerName(ownerName);

            // Parse violation records
            for (int i = 0; i < numOfTickets; ++i)
            {
                getline(file, violationType);
                violationType = violationType.substr(violationType.find("-") + 2); // Extract violation type

                // Convert violation string to ViolationType enum
                ViolationType violationEnum = DEFAULT_VIOLATION_TYPE; // Default to SPEEDING
                if (violationType == "Speeding") {
                    violationEnum = ViolationType::SPEEDING;
                }
                else if (violationType == "Running Red Light") {
                    violationEnum = ViolationType::RUNNING_RED_LIGHT;
                }
                else if (violationType == "Driving Under Influence") {
                    violationEnum = ViolationType::DRIVING_UNDER_INFLUENCE;
                }
                else if (violationType == "Parking in Fire Lane") {
                    violationEnum = ViolationType::PARKING_FIRE_LANE;
                }
                else if (violationType == "Parking in Handicapped Zone") {
                    violationEnum = ViolationType::PARKING_HANDICAPPED_ZONE;
                }
                else if (violationType == "Parking during Street Sweeping") {
                    violationEnum = ViolationType::PARKING_STREET_SWEEPING;
                }
                else {
                    violationEnum = DEFAULT_VIOLATION_TYPE; // Default
                }
               

                // Create a Ticket object with violation type
                Ticket ticket;
                ticket.setViolation(violationEnum);

                // Add the Ticket object to the plate
                plate.addViolation(ticket);
            }

            // Add the LicensePlate object to the database
            dataBase[plateNumber] = plate;
        }
    }

    cout << "\n\tData loaded successfully from file \"" << filename << "\"";
	
    file.close();
}




void PlateSystem::saveToFile(const string& filename)
{
	ofstream file(filename);
	if (!file.is_open())
	{
       		cout << "\n\tError: Unable to create or open file \"" << filename << "\"";
		return;
	}

	for (const auto& pair : dataBase)
	{
		const LicensePlate& plate = pair.second;
		file << "\tLicense number  : " << plate.getPlateNumber() << "\n";
		file << "\tOwner name      : " << plate.getOwnerName() << "\n";
		file << "\tViolation Record: " << plate.getNumOfTicket() << "\n";

		// Write each violation record to the file
		const vector<Ticket>& violations = plate.getViolationRecord();
		for (const Ticket& violation : violations)
		{
			file << "\t\t- " << violation << "\n";
		}

		file << "\n";
	}

  	cout << "\n\tData saved successfully to file \"" << filename << "\"";

	file.close();
}



