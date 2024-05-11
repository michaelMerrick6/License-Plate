#include "Ticket.h"


// Default Constructor
Ticket::Ticket()
{
	violation = ViolationType::SPEEDING;
}


// Setter for violation
void Ticket::setViolation(ViolationType newViolation)
{
	violation = newViolation;
}


// Getter for violation
ViolationType Ticket::getViolation() const
{
	return violation;
}


// Overloading the << Operator
ostream& operator<<(ostream& out, const Ticket& obj)
{
    switch (obj.violation) 
    {
    case ViolationType::SPEEDING:
        out << "Speeding";
        break;
    case ViolationType::RUNNING_RED_LIGHT:
        out << "Running Red Light";
        break;
    case ViolationType::DRIVING_UNDER_INFLUENCE:
        out << "Driving Under Influence";
        break;
    case ViolationType::PARKING_FIRE_LANE:
        out << "Parking in Fire Lane";
        break;
    case ViolationType::PARKING_HANDICAPPED_ZONE:
        out << "Parking in Handicapped Zone";
        break;
    case ViolationType::PARKING_STREET_SWEEPING:
        out << "Parking during Street Sweeping";
        break;
    }

    return out;

}