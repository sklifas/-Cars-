#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h" 
#include "Driver.h"
Vehicle::Vehicle(const string& _model, unsigned int _yearOfProduction, unsigned int _price, Colors_e _color, unsigned int _tankVolume):
	m_Model( _model ),
	m_YearOfProduction(_yearOfProduction),
	m_Price(_price),
	m_Color(_color)
{
	cout << "Vehicle " << m_Model << " created"<<endl;
	m_FuelTank_ptr = new FuelTank(_tankVolume);
}

Vehicle::Vehicle(const Vehicle& _obj):
	m_Model(_obj.m_Model),
	m_YearOfProduction(_obj.m_YearOfProduction),
	m_Price(_obj.m_Price),
	m_Color(_obj.m_Color)
{
	m_FuelTank_ptr = new FuelTank(*(_obj.m_FuelTank_ptr));
	cout << "Vehicle::Copy constructor" << endl;
}

Vehicle& Vehicle::operator=(const Vehicle& _obj)
{
	cout << "Vehicle::Assign operator"<<endl;
	if (&_obj != this)
	{
		m_Model = _obj.m_Model;
		m_YearOfProduction	 = _obj.m_YearOfProduction;
		m_Price = _obj.m_Price;
		m_Color = _obj.m_Color;
		
		delete m_FuelTank_ptr;
		m_FuelTank_ptr = new FuelTank(*(_obj.m_FuelTank_ptr));
	}
	return *this;
}

Vehicle::Vehicle(Vehicle&& _obj) noexcept:
	m_Model(_obj.m_Model),
	m_YearOfProduction(_obj.m_YearOfProduction),
	m_Price(_obj.m_Price),
	m_Color(_obj.m_Color),
	m_FuelTank_ptr(_obj.m_FuelTank_ptr),
	m_Driver_ptr(_obj.m_Driver_ptr)
{
	cout << "Vehicle::Move copy constructor" << endl;;
	_obj.m_FuelTank_ptr = nullptr;
	_obj.m_Driver_ptr = nullptr;

}
Vehicle& Vehicle::operator=(Vehicle&& _obj) noexcept
{
	cout << "Vehicle::Move assign operator"<<endl;
	if (&_obj != this)
	{
		m_Model = _obj.m_Model;
		m_YearOfProduction = _obj.m_YearOfProduction;
		m_Price = _obj.m_Price;
		m_Color = _obj.m_Color;

		delete m_FuelTank_ptr;
		m_FuelTank_ptr = _obj.m_FuelTank_ptr;
		_obj.m_FuelTank_ptr = nullptr;

		m_Driver_ptr = _obj.m_Driver_ptr;
		_obj.m_Driver_ptr = nullptr;
	}
	return *this;
}
Vehicle::~Vehicle()
{
	cout << "Vehicle " << m_Model << " destroed" << endl;
	delete m_FuelTank_ptr;
}
string Vehicle::model()
{
	return m_Model;
}

unsigned int Vehicle::yearOfProduction()
{
	return m_YearOfProduction;
}

unsigned int Vehicle::price()
{
	return m_Price;
}

void Vehicle::setPrice(unsigned int _price)
{
	m_Price = _price;
}

Vehicle::Colors_e Vehicle::colors()
{
	return m_Color;
}

void Vehicle::setColor(Vehicle::Colors_e _color)
{
	m_Color = _color;
}

unsigned int Vehicle::tankVolume()
{
	return m_FuelTank_ptr->tankVolume();
}

double Vehicle::currentFuelVolume()
{
	return m_FuelTank_ptr->currentFuelVolume();
}

void Vehicle::setCurrentFuelVolume(double _currentFuelVolume)
{
	m_FuelTank_ptr->setCurrentFuelVolume(_currentFuelVolume);
}

string Vehicle::toString()
{
	 string resault = "Model: " + m_Model + ", Year of production: " + to_string(m_YearOfProduction) + ", Price: " + to_string(m_Price) + ", Color: " + to_string(static_cast<int>(m_Color)) + ", Tank volume: " + to_string(m_FuelTank_ptr->tankVolume()) + 
		 ", Current fuel volume: " + to_string(m_FuelTank_ptr->currentFuelVolume());
	 
	 return resault;
}

void Vehicle::drive(unsigned int _distance)
{
	if (m_Driver_ptr == nullptr)
	{
		cout << "No driver. Can't drive" << endl;
	}
	else if (!m_Driver_ptr->hasValidDrivingLicense())
	{
		cout << m_Driver_ptr->name() << "doesn't have valid driving licanse. Can't drive" << endl;
	}
	else
	{
		pair<bool, double> driveData = canDrive(_distance);

		if (driveData.first)
		{
			m_FuelTank_ptr->setCurrentFuelVolume(m_FuelTank_ptr->currentFuelVolume() - driveData.second);
			cout << "We have driven: " << _distance << " km. " << "Current fuel volume = " << m_FuelTank_ptr->currentFuelVolume() << endl;
		}
		else
		{
			cout << "Not enough fuel to drive: " << _distance << " km " << endl;
		}
	}
}

void Vehicle::refuel(unsigned int _volume)
{
	m_FuelTank_ptr->refuel(_volume);
}

void Vehicle::refuel()
{
	m_FuelTank_ptr->refuel();
}

bool Vehicle::isTunkFull()
{
	return m_FuelTank_ptr->isTunkFull();
}

void Vehicle::setDriver(Driver* _driver_ptr)
{
	m_Driver_ptr = _driver_ptr;
}

void Vehicle::removeDriver()
{
	m_Driver_ptr = nullptr;
}
