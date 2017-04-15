
#include <iostream>
#include <string>
#include <cstdlib>
#include "CargoPlane.h"
#include "Cargo.h"
using namespace std;

void main(){
	//Create the cargo plane.
	//Input maxWeight, maxVolume, fuelCapacity, fuelRate and starting city.
	CargoPlane plane(50000,60000,40000,10,"New York");
	//Starts the simulation.
	plane.startCargoPlane_simulation();
	system("pause"); //Stops program from closing instantly after plane crash.
}

