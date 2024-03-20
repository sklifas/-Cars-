#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
class Bus : public Vehicle
{
public:

	Bus(const string& _model, unsigned int _yearOfProduction, unsigned int _price,
		Colors_e _color, unsigned int _tankVolume, bool _hasCompartmentForLaggage);

	Bus(const Bus& _obj);
	Bus& operator=(const Bus& _obj);

	Bus(Bus&& _obj) noexcept;
	Bus& operator=(Bus&& _obj) noexcept;

	~Bus();

	bool hasCompartmentForLaggage();

	pair<bool, double> canDrive(unsigned int _distance);
	string toString() override;

private:	
	bool m_HasCompartmentForLaggage;
};
