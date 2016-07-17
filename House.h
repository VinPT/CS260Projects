#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class House
{
	friend std::ostream& operator<<(std::ostream& output, const House& house);

public:
	House();
	
	//Setters yay
	void setAdress(char* newAdress);  //<--not sure if using void is bad code ... probably is
	void setSqFootage(int newSqFootage);
	void setNumBedrooms(int newNumBedrooms);
	void setNumBathrooms(float newNumBathrooms);
	void setDescription(char* newDescription);

	char* getAdress() const;
        int   getSqFootage() const;
        int   getNumBedrooms() const;
        float getNumBathrooms() const;
        char* getDescription() const;

	const House& operator = (const House& house);

	~House();

private:
	char* adress;
	int   sqFootage;
	int   numBedrooms;
	float numBathrooms;
	char* description;

};
