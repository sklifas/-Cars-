#include <iostream>
#include <string>
using namespace std;
#include "PassangerCar.h"
#include "Vehicle.h"

PassangerCar::PassangerCar(const string& _model, unsigned int _yearOfProduction, unsigned int _price, Colors_e _color, unsigned int _tankVolume):
	Vehicle(_model, _yearOfProduction, _price, _color, _tankVolume)
{
	cout << "Passanger car " << model() << " created" << endl;
}

PassangerCar::PassangerCar(const PassangerCar& _obj): 
	Vehicle(_obj)
{
	cout << "PassangerCar copy constructor"<<endl;
}

PassangerCar& PassangerCar::operator=(const PassangerCar& _obj) 
{
	cout << "PassangerCar assign operator" << endl;
	if (&_obj != this)
	{
		Vehicle::operator =(_obj);
	}
	return *this;
}

PassangerCar::PassangerCar(PassangerCar&& _obj) noexcept:
	Vehicle(std::move(_obj))
{
	cout << "PassangerCar move copy constructor"<<endl;
}

PassangerCar& PassangerCar::operator=(PassangerCar&& _obj) noexcept
{
	cout << "PassangerCar move assign operator";
	if (&_obj != this)
	{
		Vehicle::operator=(std::move(_obj));
	}
	return *this;
}

PassangerCar::~PassangerCar()
{
	cout << "Passanger car " << model() << " destroed" << endl;
}

pair<bool, double> PassangerCar::canDrive(unsigned int _distance)
{
	pair<bool, double> resault;

	resault.second = _distance / 10.0;
	resault.first = currentFuelVolume() - resault.second >= 0;

	return resault;
}
