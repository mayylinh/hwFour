#include "hwFour14-14.h"
#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

int main()
{
	int parked, purchased;
	const int NUM_METERS = 6;
	ParkedCar car[NUM_METERS] = { ParkedCar("MINI", "Cooper", "white", "8GHK461", 27),
				      ParkedCar("Acura", "MDX", "tan", "5KZT333", 90),
				      ParkedCar("Honda", "CR-V", "green", "7EPY451", 54),
				      ParkedCar("Mercedes-Benz", "S 550", "black", "6SSH199", 60),
				      ParkedCar("Dodge", "Challenger", "grey", "7DMS423", 180),
				      ParkedCar("Toyota", "Corolla", "silver", "4KLS540", 234) };
	ParkingMeter min[NUM_METERS] = { ParkingMeter(36),
					 ParkingMeter(180),
					 ParkingMeter(60),
					 ParkingMeter(59),
					 ParkingMeter(45),
					 ParkingMeter(10) };

	cout << "PARKING METER TICKET DUTY\n";
	PoliceOfficer officer = PoliceOfficer("Daniel Stepanov", "CS-927-XX-4RN5");

	for (int i = 0; i < NUM_METERS; i++)
	{
		parked = car[i].getMinsParked();
		purchased = min[i].getMinsPurchased();

		cout << "\nMeter #" << i + 1 << "\n";
		cout << "--------\n";
		cout << "Minutes Purchased: " << purchased << " minutes\n";
		cout << "Minutes Parked: " << parked << " minutes\n";

		if (purchased < parked)
		{
			int over = parked - purchased;
			ParkingTicket ticket = ParkingTicket(over);

			cout << "Parking Status: INVALID\n";
			cout << "------------------------------------------\n";
			cout << "|             PARKING TICKET             |\n";
			cout << "------------------------------------------\n";
			cout << "| " << setw(39) << left << "VEHICLE INFORMATION:" << "|\n";
			cout << "| " << "\tMake: " << setw(27) << left << car[i].getMake() << "|\n";
			cout << "| " << "\tModel: " << setw(26) << left << car[i].getModel() << "|\n";
			cout << "| " << "\tColor: " << setw(26) << left << car[i].getColor() << "|\n";
			cout << "| " << "\tLicense: " << setw(24) << left << car[i].getLicense() << "|\n";
			cout << "| " << setw(39) << left << "FINE: ($25 1st hr + $10/hr)" << "|\n";
			cout << "| " << "\tPayment due: $" << setw(19) << left << ticket.getFine() << "|\n";
			cout << "| " << setw(39) << left << "ISSUING OFFICER: " << "|\n";
			cout << "| " << "\tName: " << setw(27) << left << officer.getName() << "|\n";
			cout << "| " << "\tBadge: " << setw(26) << left << officer.getBadge() << "|\n";
			cout << "------------------------------------------\n";
		}
		else
			cout << "Parking Status: VALID\n";
	} 

	return 0; 
}
