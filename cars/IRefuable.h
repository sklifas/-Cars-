#pragma once

class IRefuable 
{
public:
	virtual ~IRefuable()
	{}

	virtual bool isTunkFull() = 0;
	virtual double currentFuelVolume() = 0;
	virtual void setCurrentFuelVolume(double _currentFuelVolume) = 0;
	virtual void refuel(unsigned int _volume) = 0;
	virtual void refuel() = 0;
};