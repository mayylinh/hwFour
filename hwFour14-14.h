// HW FOUR: Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889
/* For this assignment you will design a set of classes that work together to simulate a
police officer issuing a parking ticket. */

#include "stdafx.h"     // only for Visual Studio
#include <iostream>
#include <string>
using namespace std;

/* The ParkedCar Class: This class should simulate a parked car.
		– To know the car's make, model, color, license number, and the number of minutes
		that the car has been parked */
class ParkedCar
{
private:
	string make, model, color, license;
	int minsParked;
public:
	ParkedCar(string mk, string mdl, string clr, string lcns, int mins)
	{
		make = mk;
		model = mdl;
		color = clr;
		license = lcns;
		minsParked = mins;
	}
	string getMake() const;
	string getModel() const;
	string getColor() const;
	string getLicense() const;
	int getMinsParked() const;
};

/* The ParkingMeter Class: This class should simulate a parking meter.
		– To know the number of minutes of parking time that has been purchased */
class ParkingMeter
{
private:
	int minsPurchased;
public:
	ParkingMeter(int mins)
	{
		minsPurchased = mins;
	}
	int getMinsPurchased() const;
};

/* The ParkingTicket Class: This class should simulate a parking ticket.
		– To report the make, model, color, and license number of the illegally parked car
		– To report the amount of the fine, which is $25 for the first hour or part of an
		hour that the car is illegally parked, plus $10 for every additional hour or part of
		an hour that the car is illegally parked
		– To report the name and badge number of the police officer issuing the ticket */
class ParkingTicket
{
private:
	int fine;
public:
	ParkingTicket(int mins)
	{
		if (mins < 60)
			fine = 25;
		else if (mins % 60 == 0)
			fine = 25 + ((mins - 60) / 60) * 10;
		else if (mins % 60 > 0)
			fine = 25 + (mins / 60) * 10;
	}
	int getFine() const;
};

/* The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars.
		– To know the police officer’s name and badge number
		– To examine a ParkedCar object and a ParkingMeter object, and determine
		whether the car's time has expired
		– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired */
class PoliceOfficer
{
private:
	string name, badge;
public:
	PoliceOfficer()
	{
		name = "";
		badge = "";
	}
	PoliceOfficer(string nombre, string number)
	{
		name = nombre;
		badge = number;
	}
	string getName() const;
	string getBadge() const;
};

string ParkedCar::getMake() const { return make; }
string ParkedCar::getModel() const { return model; }
string ParkedCar::getColor() const { return color; }
string ParkedCar::getLicense() const { return license; }
int ParkedCar::getMinsParked() const { return minsParked; }

int ParkingMeter::getMinsPurchased() const { return minsPurchased; }

int ParkingTicket::getFine() const { return fine; }

string PoliceOfficer::getName() const { return name; }
string PoliceOfficer::getBadge() const { return badge; }