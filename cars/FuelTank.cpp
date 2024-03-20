#include "FuelTank.h"

FuelTank::FuelTank(unsigned int _tankVolume):
	m_TankVolume(_tankVolume)
{

}

unsigned int FuelTank::tankVolume()
{
    return 0;
}

double FuelTank::currentFuelVolume()
{
    return m_CurrentFuelVolume;
}

void FuelTank::setCurrentFuelVolume(double _currentFuelVolume)
{
	m_CurrentFuelVolume = _currentFuelVolume;
}

void FuelTank::refuel(unsigned int _volume)
{
	if (m_CurrentFuelVolume + _volume <= m_TankVolume)
	{
		m_CurrentFuelVolume += _volume;
		cout << "Added: " << _volume << " Yor current fuel volume: " << m_CurrentFuelVolume << endl;
	}
	else
	{
		cout << "Too mush fuel. Aborted." << endl;
	}
}

void FuelTank::refuel()
{
	cout << "Refuel to full tunk: " << m_TankVolume - m_CurrentFuelVolume << "L." << "\nTunk is full" << endl;

	m_CurrentFuelVolume = m_TankVolume;
}

bool FuelTank::isTunkFull()
{
	return m_CurrentFuelVolume == m_TankVolume;;
}
