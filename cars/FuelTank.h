#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "IRefuable.h" 

class FuelTank
{
public:
	FuelTank(unsigned int _tankVolume);

	unsigned int tankVolume();

	 double currentFuelVolume() ;
	 void setCurrentFuelVolume(double _currentFuelVolume) ;
	
	 void refuel(unsigned int _volume) ;
	 void refuel() ;

	 bool isTunkFull();
private:
	unsigned int m_TankVolume;
	double m_CurrentFuelVolume{ 0.0 };
};