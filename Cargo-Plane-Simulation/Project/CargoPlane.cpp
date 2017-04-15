//This is CargoPlane.cpp
#include "CargoPlane.h"
#include "Cargo.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

CargoPlane::CargoPlane()
{
	//initializes the variables in the class.
	maxWeight = 0;
	maxVolume = 0;
	fuelCapacity = 0;
	fuelRate = 0;
	currentCity = "";
	milesFlown = 0;
	hoursFlown = 0;
	fuelConsumed = 0;
	usedVolume = 0;
	usedWeight = 0;
	maxCargoCount = 0;
	loadedCargo = NULL;
}
CargoPlane::CargoPlane(double maxWeight, int maxVolume, int fuelCapacity, int fuelRate, const string& city)
{	
	//Setting the variables to what is passed in.
	this->maxWeight = maxWeight;
	this->maxVolume = maxVolume;
	this->fuelCapacity = fuelCapacity;
	this->fuelRate = fuelRate;
	this->currentCity = city;
	milesFlown = 0;
	hoursFlown = 0;
	fuelConsumed = 0;
	usedVolume = 0;
	usedWeight = 0;
	maxCargoCount = 200; //Default size of the cargo array, can be increased here only.
	loadedCargo = new Cargo[maxCargoCount]; //Creates the cargo array.
}
void CargoPlane::startCargoPlane_simulation(){
	//  This funtion controls the flow of the cargo plane simulation program.
	//  All variables below are used to temporary store the user inputs.
	//  All inputs are check for errors and used right after input.	
	string userCommand = "";
	string destination = "";
	string tempLabel = "";
	double tempWeight = 0;
	int tempHeight = 0;
	int tempWidth = 0;
	int tempLength = 0;
	int tempInt = 0;
	int mileage = 0;
	int flightTime = 0;
	Cargo tempCargo;

	bool run = true; // The on and off swtich.

	while (run){
		cout << "Please choose one of the following commands: \n";
		cout << "FLY, LOAD, UNLOAD, PRINT, QUIT\n";
		cout << "Command: ";
		cin >> userCommand; //get user command
		if (userCommand == "FLY" || userCommand == "fly"){
			//This will clear the cin buffer so that the getline() funtion does not get skipped.
			//Because a "enter" key will be in the buffer due to the input from the usercommand input.
			cin.ignore(256,'\n');
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Input Destination: ";
				//Gets the name of the destination,
				//multi-worded destinations are allowed with getline() compared to cin which only allows one word.
				getline(cin, destination);
				//Checks if user entered a blank destination.
				if (destination.find_first_not_of(' ') == string::npos){
					cout << "Blank destinations are not allowed, please try again.\n";
				}
				else{
					break;
				}
			}
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Input Mileage: ";
				cin >> mileage;
				if (mileage < 0 || cin.fail()){
					cout << "Invalid input, please try again.\n";
					cin.clear();
					cin.ignore(255, '\n');
				}
				else{
					break;
				}
			}
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
			cout << "Input Flight Time: ";
			cin >> flightTime;
			if (flightTime < 0 || cin.fail()){
				cout << "Invalid input, please try again.\n";
				cin.clear();
				cin.ignore(255, '\n');
			}
			else{
				break;
			}
			}
			if (fly(destination, flightTime, mileage) == true){
				cout << "Flight Successful. Arrived at: " << destination << endl << endl;
			}
			else{
				cout << "\nFlight Unsuccessful. Plane Crashed\n";
				run = false; //Ends the simulation if plane crashed.
			}
		}
		else if (userCommand == "LOAD" || userCommand == "load"){
			bool tempBool = false; //A temp bool to check if the label inputed does not already exist or not.
			//This will clear the cin buffer so that the getline() funtion does not get skipped.
			//Because a "enter" key will be in the buffer due to the input from the usercommand input.
			cin.ignore(256, '\n');
			do{
				cout << "Cargo Label: ";
				getline(cin, tempLabel); //Allows the label to be muli-worded
				for (int i = 0; i < maxCargoCount; i++){
					//This loop will check if the label the user is trying to input does not already exist or not.
					if (loadedCargo[i].getLabel() == tempLabel || tempLabel.find_first_not_of(' ') == string::npos){
						cout << "Error in cargo label input.\n"
							<< "Either the cargo already exist or you entered a blank label. Please try again.\n";
						tempBool = true;
						break; //Breaks out of the for loop if a label with the same name is found, or user enters a blank label.
					}
					else{
						tempBool = false; //If not label with the same name is found then the while loop will end.
					}
				}
			} while (tempBool);

			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Weight: ";
				cin >> tempWeight;
				if (tempWeight < 0 || cin.fail()){
					cout << "Invalid input, please try again.\n";
					cin.clear();
					cin.ignore(255, '\n');
				}
				else{
					break;
				}
			}
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Height: ";
				cin >> tempHeight;
				if (tempHeight < 0 || cin.fail()){
					cout << "Invalid input, please try again.\n";
					cin.clear();
					cin.ignore(255, '\n');
				}
				else{
					break;
				}
			}
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Width: ";
				cin >> tempWidth;
				if (tempWidth < 0 || cin.fail()){
					cout << "Invalid input, please try again.\n";
					cin.clear();
					cin.ignore(255, '\n');
				}
				else{
					break;
				}
			}
			while (true){
				//loop that will check the user input. Will continue to ask the user for input if the user inputs a invalid value.
				cout << "Length: ";
				cin >> tempLength;
				if (tempLength < 0 || cin.fail()){
					cout << "Invalid input, please try again.\n";
					cin.clear();
					cin.ignore(255, '\n');
				}
				else{
					break;
				}
			}
			//Sets the temp cargo to the values the user inputed.
			tempCargo.set(tempLabel,tempHeight,tempWidth,tempLength,tempWeight);
			//Pass in the temp cargo to be loaded.
			tempInt = loadCargo(tempCargo);
			//tempInt will store the return value of the loadCargo funtion.
			if (tempInt == (-3)){
				cout << "Volume and Weight limit exceeded. Loading Failed\n";
			}
			else if (tempInt == (-2)){
				cout << "Volume limit exceeded. Loading Failed\n";
			}
			else if (tempInt == (-1)){
				cout << "Weight limit exceeded. Loading Failed\n";
			}
			else if (tempInt == 1){
				cout << "Cargo was successfully loaded.\n\n";
			}
		}
		else if (userCommand == "UNLOAD" || userCommand == "unload"){
			cout << "Input Cargo label to be unloaded: ";
			cin >> tempLabel;
			//attemps to unload the cargo with the label that is inputted
			unLoadCargo(tempLabel);
		}
		else if (userCommand == "PRINT" || userCommand == "print"){
			print(); // prints out
		}
		else if (userCommand == "QUIT" || userCommand == "quit"){
			run = false; //Ends the simulation
		}
		else {
			//Will continue to ask the user for input if the user inputs a invalid value.
			cout << "Invalid Command. Please try again.\n\n";
		}
	}
	//End of simulation
	cout << "\nCargo Plane Simulation Ended\n\n";
}
int CargoPlane::loadCargo(Cargo cargo){
	//Checks if the weight and volume would be exceeded or not, returns -3 if true.
	if (cargo.getWeight() + usedWeight > maxWeight && cargo.getVolume() + usedVolume > maxVolume){
		return (-3);
	}
	//Checks if only the volume would be exceeded, returns -2 if true.
	else if (cargo.getVolume() + usedVolume > maxVolume){
		return (-2);
	}
	//Checks if only the weight would be exceeded, returns -1 if true.
	else if (cargo.getWeight() + usedWeight > maxWeight){
		return (-1);
	}
	//If volume or weight would not be exceeded then the cargo will be loaded, and then returns 1.
	else {
		//Search the loadedCargo array for a unused spot.
		//Sets the cargo of that unused spot.
		for (int i = 0; i < maxCargoCount;i++){
			if (loadedCargo[i].getLabel().empty()){
				//sets the values of the unused cargo.
				loadedCargo[i].set(cargo.getLabel(), cargo.getHeight(), cargo.getWidth(), cargo.getLength(), cargo.getWeight());
				break;//breaks out of for loop, if a unused spot is found.
			}
		}
		usedVolume = usedVolume + cargo.getVolume(); //updates usedVolume
		usedWeight = usedWeight + cargo.getWeight(); //updates usedWeight
		return 1; //returns 1 when loading is succesful

	}

}
void CargoPlane::unLoadCargo(string label){
	//This bool is used to check if a cargo was unloaded or not.
	bool cargoUnloaded = false;
	//Loop that will search the cargo array for a cargo with the same label name.
	for (int i = 0; i < maxCargoCount; i++){
		if (loadedCargo[i].getLabel() == label){
			//If a cargo with the label is found, then usedVolume and usedWeight is updated.
			usedVolume = usedVolume - loadedCargo[i].getVolume();
			usedWeight = usedWeight - loadedCargo[i].getWeight();
			//Sets the variables of the cargo that is to be removed to zero.
			loadedCargo[i].set("",0,0,0,0);
			cargoUnloaded = true; //Cargo was unloaded.
			//Outputs a message to let user know that the cargo was found and unloaded.
			cout << "Cargo with label " << label << " was unloaded.\n\n";
			break; //Stops the loop,  because the cargo was found.
		}
	}
	if (cargoUnloaded == false){
		//If cargo was not found then output a message to let user know.
		cout << "Cargo with label " << label << " does not exist, Unloading failed.\n\n";
	}
}
bool CargoPlane::fly(string city, int hours, int miles){
	//Checks the plane would run out of fuel or not, returns false if the plane will run out of fuel.
	if ((hours*fuelRate)+fuelConsumed > fuelCapacity){
		return false;
	}
	//Otherwise flight is successful and will return true.
	else{
		currentCity = city;  //updates the currentCity to the new city.
		fuelConsumed = fuelConsumed + (hours*fuelRate); //updates the amount of fuel consumed.
		milesFlown = milesFlown + miles; //updates miles flown.
		hoursFlown = hoursFlown + hours; //updates hours flown.
		return true; 
	}
     
}
void CargoPlane::print(){
	//Prints out everything.
	cout << left << setw(15) <<"Current City: " << currentCity << endl;
	cout << setw(15) << "Miles Flown: " << milesFlown << endl;
	cout << setw(15) << "Hours Flown: " << hoursFlown << endl;
	cout << setw(15) << "Fuel Rate: " << fuelRate << " gallons per hour" << endl;
	cout << setw(15) << "Fuel Capacity: " << setw(12) << fuelCapacity;
	cout << setw(10) << " Consumed: " << setw(12) << fuelConsumed;
	cout << " Remaining: " << getRemainingFuel() << endl;
	cout << fixed << setprecision(2); //Weight output will be outputed with two decimal places.
	cout << setw(15) << "Weight Limit: " << setw(12) << maxWeight;
	cout << setw(11) << " Loaded: " << setw(12) << usedWeight;
	cout << " Remaining: " << getRemainingWeight() << endl;
	cout << setw(15) << "Volume Limit: " << setw(12) << maxVolume;
	cout << setw(11) << " Loaded: " << setw(12) << usedVolume;
	cout << " Remaining: " << getRemainingVolume() << endl;
	cout << "Current Cargo:\n";
	bool notEmpty = false; //A temp bool to check if the cargo array has any cargos or not.
	//loops through the cargo array and prints out any cargos that is found.
	//Cargos with no label is considered to be nonexistent and skiped.
	for (int i = 0; i < maxCargoCount; i++){
		if (loadedCargo[i].getLabel() != ""){
			notEmpty = true; //Cargo array is not empty
			loadedCargo[i].print();
		}
	}
	if (notEmpty == false){
		//If cargo array is empty then a message will tell the user that there is no cargos on the plane.
		cout << "No Cargo On Plane.\n";
	}
	cout << endl;
}
int CargoPlane::getRemainingFuel(){
	return fuelCapacity - fuelConsumed; 
}
int CargoPlane::getRemainingVolume(){
	return maxVolume - usedVolume; 
}
double CargoPlane::getRemainingWeight(){
	return maxWeight - usedWeight; 
}

CargoPlane::~CargoPlane()
{
	delete[] loadedCargo; //Deletes the array of cargos that the pointer is pointing to.
	loadedCargo = NULL;  //sets the point to point to NULL.
}
