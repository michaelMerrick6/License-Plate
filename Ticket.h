#pragma once
#include <iostream>

using namespace std;


enum class ViolationType : uint8_t {
    SPEEDING,
    RUNNING_RED_LIGHT,
    DRIVING_UNDER_INFLUENCE,
    PARKING_FIRE_LANE,
    PARKING_HANDICAPPED_ZONE,
    PARKING_STREET_SWEEPING
};


class Ticket
{
private:
    ViolationType violation;

public:
    Ticket();		// Default Constructor

    void setViolation(ViolationType newViolation);
    ViolationType getViolation() const;

    friend ostream& operator<<(ostream& out, const Ticket& obj);
};

