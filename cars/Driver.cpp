#include "Driver.h"

Driver::Driver(const string _name):
    m_Name(_name)
{
}

string Driver::name()
{
    return m_Name;
}

bool Driver::hasValidDrivingLicense()
{
    return m_HasValidDrivingLicense;
}

void Driver::provideValidDrivingLicense()
{
    m_HasValidDrivingLicense = true;
}

void Driver::rejectValidDrivingLicense()
{
    m_HasValidDrivingLicense = false;
}
