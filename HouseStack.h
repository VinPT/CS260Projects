//This is the housestack handles the houses we want to look at when we come back
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git

#pragma once

#include "House.h"
#include "HouseQueue.h" //<-we need the struct HouseNode from houseQueue 
using namespace std;

class HouseStack
{
public:
	HouseStack();

        void pushHouse(House newHouse);
        House popHouse();
        void display();
	bool stackNotEmpty();

	~HouseStack();
private:

        HouseNode *head;
};
