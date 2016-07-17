#pragma once

#include "House.h"
#include "HouseQueue.h" //<-we need the struct from houseQueue 
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
