#pragma once
#include <iostream>
#include <string>
#include "Driver.h"
using namespace std;
class Driver
{
public:
	Driver(const string _name);
	string name();
	bool hasValidDrivingLicense();

	void provideValidDrivingLicense();
	void rejectValidDrivingLicense();
private:
	string m_Name;
	bool m_HasValidDrivingLicense = true;

};

