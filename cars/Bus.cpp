#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
#include "Bus.h"

Bus::Bus(const string& _model, unsigned int _yearOfProduction, unsigned int _price, Vehicle::Colors_e _color, unsigned int _tankVolume, bool _hasCompartmentForLaggage):
	Vehicle(_model, _yearOfProduction, _price, _color, _tankVolume),
	m_HasCompartmentForLaggage(_hasCompartmentForLaggage)
{
	cout << "Bus " << model() << " created" << endl;
}
Bus::Bus(const Bus& _obj):
	Vehicle(_obj),
	m_HasCompartmentForLaggage(_obj.m_HasCompartmentForLaggage)
{
	cout << "Bus copy constructor" << endl;
}
Bus& Bus::operator=(const Bus& _obj)
{
	cout << "Bus assign constructor" << endl;
	if (&_obj != this)
	{
		Vehicle::operator=(_obj);
		m_HasCompartmentForLaggage = _obj.m_HasCompartmentForLaggage;
	}
	return *this;
}
Bus::Bus(Bus&& _obj) noexcept:
	Vehicle(std::move(_obj)),
	m_HasCompartmentForLaggage(_obj.m_HasCompartmentForLaggage)
{

}
Bus& Bus::operator=(Bus&& _obj) noexcept
{
	cout << "Bus move assign constructor" << endl;
	if (&_obj != this)
	{
		Vehicle::operator=(std::move(_obj));
		m_HasCompartmentForLaggage = _obj.m_HasCompartmentForLaggage;
	}
	return *this;
}
Bus::~Bus()
{
	cout << "Bus " << model() << " destroed" << endl;
}

bool Bus::hasCompartmentForLaggage()
{
	return m_HasCompartmentForLaggage;
}
//5 liters on 100 km
//1l = 20km 
pair<bool, double> Bus::canDrive(unsigned int _distance)
{
	pair<bool, double> resault;

	resault.second = _distance / 5.0;
	resault.first = currentFuelVolume() - resault.second >= 0;

	return resault;
}

string Bus::toString()
{
	string resault = Vehicle::toString();
	resault += ", Has compartmet for laggage: " + to_string(m_HasCompartmentForLaggage);

	return resault;
}
