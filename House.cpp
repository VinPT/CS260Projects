//This is the house object that contains the address and other atrebutes of a house 
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git

#include "House.h"


House::House()
{
	address = NULL;
	sqFootage = 0;
	numBedrooms = 0;
	numBathrooms = 0.0; //<-- this one is a float because of half baths
	description = NULL;
}

House::House(const House &otherHouse)
{
	address = NULL;
	description = NULL;
	*this = otherHouse;
}

//House overloads live here

std::ostream& operator<<(std::ostream& output, const House& house)
{
	output << house.address<<"; "<< house.sqFootage <<"; "<< house.numBedrooms <<"; "<< house.numBathrooms <<"; "<< house.description <<endl;
	return output;
}

const House& House::operator = (const House& house)
{
	if(this == &house)
	{
		return *this;
	}
	
	setAddress(house.getAddress()); 
	
	sqFootage = house.getSqFootage();
	numBedrooms = house.getNumBedrooms();
	numBathrooms = house.getNumBathrooms();

	setDescription(house.getDescription());
	return house;
		
}


//Setters start here
void House::setAddress(char* newAddress)  //<--not sure if using void is bad code ... probably is
{

	if (address != NULL) { // YIKES this thing saves me so much ... need to find out why
		delete [] address;
		address = NULL;
	}
	address = new char[strlen(newAddress)+1];
	strcpy( address, newAddress);
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
	if (description != NULL) {//Yikes again
		delete [] description;
		description = NULL;
	}
        description = new char[strlen(newDescription)+1];

	strcpy( description, newDescription);
	return;
}

//Getters start here

char* House::getAddress() const
{
        return address;
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
	if (address != NULL) {
		delete [] address;
		address = NULL;
	}
	if (description != NULL) {
		delete [] description;		
		description = NULL;
	}
}

