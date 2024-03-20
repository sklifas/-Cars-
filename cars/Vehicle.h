#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "IRefuable.h" 
#include "FuelTank.h"
#include "Driver.h"


class Vehicle : public IRefuable
{
public:
	enum class Colors_e
	{
		White,
		Blue,
		Red,
		Black,
		Yellow,
		Green,
	};

public:

	Vehicle( const string& _model, unsigned int _yearOfProduction, unsigned int _price, Colors_e _color, unsigned int _tankVolume );

	Vehicle(const Vehicle& _obj);
	Vehicle& operator=(const Vehicle& _obj);

	Vehicle(Vehicle&& _obj) noexcept;
	Vehicle& operator=(Vehicle&& _obj) noexcept;

	virtual~Vehicle();

	string model();

	unsigned int yearOfProduction();

	unsigned int price();
	void setPrice(unsigned int _price);

	Colors_e colors();
	void setColor(Colors_e _color);

	unsigned int tankVolume();

	virtual double currentFuelVolume() override;
	virtual void setCurrentFuelVolume(double _currentFuelVolume) override;

	virtual string toString();
	virtual pair<bool, double> canDrive(unsigned int _distance) = 0;
    void drive(unsigned int _distance);
	virtual void refuel(unsigned int _volume) override;
	virtual void refuel() override;
	bool isTunkFull();
	void setDriver(Driver* _driver_ptr);
	void removeDriver();

private:
	string m_Model; 
	unsigned int m_YearOfProduction;
	unsigned int m_Price;
	Colors_e m_Color;

	FuelTank* m_FuelTank_ptr=nullptr;
	Driver* m_Driver_ptr = nullptr;
};