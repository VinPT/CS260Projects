#include "HouseStack.h"

HouseStack::HouseStack()
{
	head = NULL;
}

void HouseStack::pushHouse(House newhouse)
{
	HouseNode *newHouseNode = new HouseNode();
	
	newHouseNode->house = newhouse;
	if(NULL == head)
	{
		newHouseNode->nextHouse = NULL; // initalizing the end pointer to the expected null value
	}	
	else 
	{
		newHouseNode->nextHouse = head;
	}
	
	head = newHouseNode;

}

House HouseStack::popHouse()
{
	HouseNode *tempHouseNode = head;
	House house = tempHouseNode->house;
	head = head->nextHouse;
	
	delete tempHouseNode;
	
	return house;
}
void HouseStack::display()//we never use this but i was told to make it
{
	HouseNode *currentHouseNode = head;

	while (NULL != currentHouseNode)
	{
		cout<< currentHouseNode->house<< endl;
		currentHouseNode = currentHouseNode->nextHouse;
	}

}
bool HouseStack::stackNotEmpty()
{
        bool result = false;
        if (NULL != head)
                result = true;

        return result;

}

HouseStack::~HouseStack()
{
	while (stackNotEmpty())
	{
		(void)popHouse();
	}
}

