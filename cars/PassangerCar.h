#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
class PassangerCar : public Vehicle
{
public:

	PassangerCar(const string& _model, unsigned int _yearOfProduction, unsigned int _price, Colors_e _color, unsigned int _tankVolume);

	PassangerCar(const PassangerCar& _obj);
	PassangerCar& operator=(const PassangerCar& _obj);

	PassangerCar(PassangerCar&& _obj) noexcept;
	PassangerCar& operator=(PassangerCar&& _obj) noexcept;

	~PassangerCar();

	virtual pair<bool, double> canDrive(unsigned int _distance) override;
};

