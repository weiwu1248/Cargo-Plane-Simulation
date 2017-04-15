//This is Cargo.cpp

#include "Cargo.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Cargo::Cargo() :label(""), height(0), width(0), length(0), weight(0)
{
	//This constructer will initialize the member varibles using a member initialization list
	//All member variables will be initialized to zero or empty string.
}

Cargo::Cargo(string label, int height, int width, int length, double weight) :label(label), height(height), width(width), length(length), weight(weight)
{
	// This constructer will initialize the member varibles using a member initialization list.
}

void Cargo::set(string label, int height, int width, int length, double weight){
	//This funtion will set the label, height, width, length and weight varibles of the cargo class.
	this->label = label;
	this->height = height;
	this->width = width;
	this->length = length;
	this->weight = weight;

}

int Cargo::getHeight(){
	// This funtion will return the height of the cargo.
	return height;
}

int Cargo::getWidth(){
	//This funtion will return the width of the cargo.
	return width;
}

int Cargo::getLength(){
	//This funtion will return the Length of the cargo.
	return length;
}

int Cargo::getVolume(){
	// This funtion will return the Volume of the cargo.
	return height*width*length;
}

double Cargo::getWeight(){
	//This funtion will return the Weight of the cargo.
	return weight;
}

string Cargo::getLabel(){
	//This funtion will return the Label of the cargo.
	return label;
}
void Cargo::print(){
	//This funtion will print out the label, weight, volume and dimensions of the cargo.
	cout << left << fixed << setprecision(2); /// Sets the output to left justified, standard numerical and two decimal place.
	cout << "Label: " << setw(8) << label
		<< " Weight: " << setw(8) << weight
		<< " Volume: " << setw(8) << getVolume()
		<< " Dimensions: " << height << " X " << width << " X " << length << endl;
}
Cargo::~Cargo()
{
	//Does nothing
}
