#include "House.h"

//This is the house object that contains the adress and other atrebutes of a house 
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//I need to start using sorce control


House::House()
{
	adress = NULL;
	sqFootage = 0;
	numBedrooms = 0;
	numBathrooms = 0.0; //<-- this one is a float because of half baths
	description = NULL;
}

//House overloads live here

std::ostream& operator<<(std::ostream& output, const House& house)
{
	output << house.adress<<"; "<< house.sqFootage <<"; "<< house.numBedrooms <<"; "<< house.numBathrooms <<"; "<< house.description <<endl;
	return output;
}

const House& House::operator = (const House& house)
{
	if(this == &house)
	{
		return *this;
	}
	
	setAdress(house.getAdress()); //the pluss one makes sure that the end charecter has room
	
	sqFootage = house.getSqFootage();
	numBedrooms = house.getNumBedrooms();
	numBathrooms = house.getNumBathrooms();

	setDescription(house.getDescription());
	return house;
		
}


       //Setters yay
void House::setAdress(char* newAdress)  //<--not sure if using void is bad code ... probably is
{
	adress = new char[strlen(newAdress)+1];

	strcpy( adress, newAdress);
        return;
}

void House::setSqFootage(int newSqFootage)
{
	sqFootage = newSqFootage;
	return;
}

void House::setNumBedrooms(int newNumBedrooms)
{
	numBedrooms = newNumBedrooms;
	return;
}

void House::setNumBathrooms(float newNumBathrooms) //<- dont forget half baths
{
	numBathrooms = newNumBathrooms;
	return;
}

void House::setDescription(char* newDescription)
{
        description = new char[strlen(newDescription)+1];

	strcpy( description, newDescription);
	return;
}

//Getters start here

char* House::getAdress() const
{
        return adress;
}

int   House::getSqFootage() const
{
        return sqFootage;
}

int   House::getNumBedrooms() const
{
        return numBedrooms;
}

float House::getNumBathrooms() const        
{
        return numBathrooms;
}

char* House::getDescription() const
{
	return description;
}

House::~House()
{
	//delete adress;
	//delete description;		
}



