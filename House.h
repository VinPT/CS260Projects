//This is the house object that contains the address and other atrebutes of a house 
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git
#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class House
{
	friend std::ostream& operator<<(std::ostream& output, const House& house);

public:
	House();
	House(const House &otherHouse);
	
	//Setters yay
	void setAddress(char* newAdress);  //<--not sure if using void is bad code ... probably is
	void setSqFootage(int newSqFootage);
	void setNumBedrooms(int newNumBedrooms);
	void setNumBathrooms(float newNumBathrooms);
	void setDescription(char* newDescription);

	char* getAddress() const;
        int   getSqFootage() const;
        int   getNumBedrooms() const;
        float getNumBathrooms() const;
        char* getDescription() const;

	const House& operator = (const House& house);

	~House();

private:
	char* address;
	int   sqFootage;
	int   numBedrooms;
	float numBathrooms;
	char* description;

};
