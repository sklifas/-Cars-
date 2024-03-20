#include <iostream>
#include <string>
using namespace std;
#include "PassangerCar.h"
#include "Bus.h"
#include "Vehicle.h"

void testDriveBuValue(PassangerCar _passangerCar)
{
	_passangerCar.refuel(10);
	cout << "Just after refuel volume is " << _passangerCar.currentFuelVolume()<<endl;;
}

void testDriveBuReference(PassangerCar& _passangerCar)
{
	_passangerCar.refuel(10);
	cout << "Just after refuel volume is " << _passangerCar.currentFuelVolume()<<endl;;
}

int main()
{
	PassangerCar car1("Nissan", 2022, 2000, Vehicle::Colors_e::White, 40);

	testDriveBuValue(car1);

	cout << "After test drive volume is: " << car1.currentFuelVolume() << endl;












	////PassangerCar car2(srd::move(car1));
	//PassangerCar car2("BMW", 2020, 4000, Vehicle::Colors_e::Black, 60);

	//cout << "-----------------------------------------------------------------------------" << endl;

	//car1 = car2;
	///*PassangerCar car3("TOYOTA", 2021, 3000, Vehicle::Colors_e::Yellow, 50);*/
	//PassangerCar car3(car2);

	//car2 = car1;










	//Vehicle* passagerCar_ptr = new PassangerCar("Nissan", 2022, 2000, Vehicle::Colors_e::White, 40);
	//Vehicle* bus_ptr = new Bus("Mercedes", 2023, 20000, Vehicle::Colors_e::Black, 240, true);

	//Driver* antonDriver_ptr = new Driver("Anton");
	//Driver* viktorDriver_ptr = new Driver("Viktor");

	//passagerCar_ptr->refuel(10);
	//bus_ptr->refuel(20);
	//
	//passagerCar_ptr->setDriver(antonDriver_ptr);
	//passagerCar_ptr->drive(20);

	//antonDriver_ptr->rejectValidDrivingLicense();
	//passagerCar_ptr->drive(20);

	//passagerCar_ptr->setDriver(viktorDriver_ptr);
	//passagerCar_ptr->drive(20);
	//passagerCar_ptr->refuel(10);
	//bus_ptr->refuel(10);

	//passagerCar_ptr->drive(20);
	//bus_ptr->drive(20);

	//IRefuable* refuable_ptr = nullptr;
	//refuable_ptr = passagerCar_ptr;
	//refuable_ptr->refuel();

	//refuable_ptr = bus_ptr;
	//refuable_ptr->refuel();

	//delete passagerCar_ptr; // визов диструктора
	//delete bus_ptr;
	return 0;
}