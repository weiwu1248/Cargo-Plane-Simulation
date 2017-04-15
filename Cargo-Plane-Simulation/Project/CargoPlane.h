//This is CargoPlane.h

/**
* \class CargoPlane
*
* \brief
*
* This class is meant to represent and simulate a cargo plane.
* Requires the cargo class.
*
*/
#ifndef Cargo_Plane_H
#define Cargo_Plane_H
#include "Cargo.h"
#include <string>
using namespace std;
class CargoPlane
{
private:
	string currentCity; ///< The current city the plane is at.
	int milesFlown;     ///< The number miles the plane has flown.
	int hoursFlown;     ///< The number of hours the plane has flown.
	int fuelRate;       ///< The fuel consumption rate of the plane, in gallons per hour.
	int fuelCapacity;   ///< The maximum amount of fuel the plane can hold, also the starting amnount of fuel of the plane.
	int fuelConsumed;   ///< The amount of fuel the plane has used up so far.
	int maxVolume;      ///< The maximum volume of cargos the plane can carry.
	int usedVolume;     ///< The amount of volume that is used up so far.
	double maxWeight;   ///< The maximum weight of cargos the plane can carry.
	double usedWeight;  ///< The amount of weight that is used up so far.
	Cargo* loadedCargo; ///< A pointer of type Cargo, points to a array of cargos, stores the cargos on the plane.
	int maxCargoCount;  ///< The maximum size of the cargo array, Is set to 200 by default in the construtor.
public:
	/** Funtion: CargoPlane()
	*
	* This is the default constructor, will initialize all member variables of class CargoPlane to zero, NULL, empty string.
	*
	*/
	CargoPlane();
	/** Funtion: CargoPlane(double maxWeight, int maxVolume, int fuelCapacity, int fuelRate, const string& city);
	*
	* This is the second constructor.
	*
	* @param maxWeight   A double, The maximum weight the cargo plane can carry.
	* @param maxVolume   A integer, The maximum volume the plane can carry.
	* @param fuelCapacity  A integer, The maximum amount of fuel the plane can store, is also the starting amnount of fuel of the plane.
	* @param fuelRate      A integer, The fuel consumption rate of the plane, in gallons per hour.
	* @param city          A string, The current or starting city of the plane.
	*/
	CargoPlane(double maxWeight, int maxVolume, int fuelCapacity, int fuelRate, const string& city);
	/** Funtion: loadCargo(Cargo cargo)
	*
	* This funtion will attempt to load the cargo that is passed in, into the loadedCargo array.
	* usedVolume and usedWeight are updated if loading was successful.
	*
	* @param cargo  A cargo that will be loaded onto the plane.
	* @return int   Returns -1 if weight limit is exceeded, -2 is volume limit is exceeded, -3 if both are exceeded or returns 1 if loading was successful.
	*/
	int loadCargo(Cargo cargo);
	/** Funtion: unLoadCargo(string label)
	*
	* This funtion will attempt to unload a cargo with the label that is passed in.
	* Will output a message if unloading is successful or if the unloading was unsuccessful.
	* Variables usedWeight and usedVolume is updated if unloading is successful
	* Unloads by setting all variables of the cargo to zero and the label to empty.
	*
	* @param label  The name/label of the cargo that is to be unloaded.
	*
	*/
	void unLoadCargo(string label);
	/** Funtion: fly(string city, int hours, int miles)
	*
	* This funtion will attempt to fly the plane to the city that is passed in.
	*
	* @param city   The name of the city that the plane would fly to, the name can be multi-worded.
	* @param hours  The number of hours it would take to fly to the location.
	* @param miles  The number of miles it takes to fly to the location.
	* @return bool  Returns true if flight was successful, false otherwise.
	*/
	bool fly(string city, int hours, int miles);
	/** Funtion: print()
	*
	* This funtion will print out the status, varaibles and the cargos that are loaded on the plane in a decent format.
	*
	*/
	void print();
	/** Funtion: startCargoPlane_simulation()
	*
	* This funtion controls the flow of the cargo plane simulation.
	* Starts the cargo plane simulation.
	*
	*/
	void startCargoPlane_simulation();
	/** Funtion: getRemainingFuel()
	*
	* @return int   Returns the remaining amount of fuel.
	*
	*/
	int getRemainingFuel();
	/** Funtion: getRemainingVolume()
	*
	* @return int   Returns the remaining amount of volume the plane can store.
	*
	*/
	int getRemainingVolume();
	/** Funtion: getRemainingWeight()
	*
	* @return double   Returns the remaining amount of weight the plane can carry.
	*
	*/
	double getRemainingWeight();
	/** Funtion: ~CargoPlane()()
	*
	* This is the destructor, will delete the array of cargo objects that the cargo pointer is pointing to,
	* Then the cargo pointer will be set to NULL.
	*
	*/
	~CargoPlane();
};

#endif