//This is the houseStack deals in houses we want to look at again
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git

#include "HouseStack.h"

//initalize values
HouseStack::HouseStack()
{
	head = NULL;
}

//Add to top
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

//Remove from top
House HouseStack::popHouse()
{
	HouseNode *tempHouseNode = head;
	House house = tempHouseNode->house;
	head = head->nextHouse;
	
	delete tempHouseNode;
	
	return house;
}

//Output to screen
void HouseStack::display()//we never use this but i was told to make it
{
	HouseNode *currentHouseNode = head;

	while (NULL != currentHouseNode)
	{
		cout<< currentHouseNode->house<< endl;
		currentHouseNode = currentHouseNode->nextHouse;
	}

}

//used to run loops in main project
bool HouseStack::stackNotEmpty()
{
        bool result = false;
        if (NULL != head)
                result = true;

        return result;

}

//desctruction
HouseStack::~HouseStack()
{
	while (stackNotEmpty())
	{
		(void)popHouse();
	}
}

