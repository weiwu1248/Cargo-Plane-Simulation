//This is Cargo.h

/** 
* \class Cargo
*
* \brief
*
* This class is meant to represent a cargo container.
*
*/
#ifndef Cargo_H
#define Cargo_H
#include <string>
using namespace std;
class Cargo
{
private:
	string label;  ///< The name/label of the cargo.
	int height;    ///< The height of the cargo.
	int width;     ///< The width of the cargo.
	int length;    ///< The length of the cargo.
	double weight; ///< The weight of the cargo.
public:
	/** Default constructer: Cargo().
	*
	*  This constructer will initialize the member varibles using a member initialization list.
	*  All member variables will be initialized to zero or empty string.
	*
	*/
	Cargo();
	/** Second constructer: Cargo(string label, int height, int width, int length, double weight)
	*
	* This constructer will initialize the member varibles using a member initialization list.
	* Variables will be initialized to the values that is passed in.
	* @param label   A string, The name/label of the cargo.
	* @param height  A integer, The height of the cargo.
	* @param width   A integer, The width of the cargo.
	* @param length  A integer, The length of the cargo.
	* @param weight  A double, The weight of the cargo.
	*
	*/
	Cargo(string label, int height, int width, int length, double weight);
	/** Function: getHeight()
	*
	* This Function will return the height of the cargo.
	*
	* @return int  The height of the cargo.
	*
	*/
	int getHeight();
	/** Function: getWidth()
	*
	* This Function will return the width of the cargo.
	*
	* @return int  The width of the cargo.
	*
	*/
	int getWidth();
	/** Function: getLength()
	*
	* This Function will return the Length of the cargo.
	*
	* @return int  The length of the cargo.
	*
	*/
	int getLength();
	/** Function: getVolume()
	*
	* This Function will return the Volume of the cargo.
	*
	* @return int  The Volume of the cargo, width * height * length.
	*
	*/
	int getVolume();
	/** Function: getWeight()
	*
	* This Function will return the Weight of the cargo.
	*
	* @return double  The weight of the cargo
	*
	*/
	double getWeight();
	/** Function: getLabel()
	*
	* This Function will return the Label of the cargo.
	*
	* @return string  The label of the cargo
	*
	*/
	string getLabel();
	/** Function: set(string label, int height, int width, int length, double weight)
	*
	* This Function will set the label, height, width, length and weight varibles of the cargo class.
	*
	* @param label   A string, The name/label of the cargo.
	* @param height  A integer, The height of the cargo.
	* @param width   A integer, The width of the cargo.
	* @param length  A integer, The length of the cargo.
	* @param weight  A double, The weight of the cargo.
	* @return void
	*/
	void set(string label, int height, int width, int length, double weight);
	/** Function: print()
	*
	* This Function will print out the label, weight, volume and dimensions of the cargo.
	* The number outputs will be set to left justified, standard numerical 
	* Weight output will be set to two decimal place.
	*/
	void print();
	/** Function: ~Cargo()
	*
	* This Function does nothing.
	*
	*/
	~Cargo();
};

#endif

