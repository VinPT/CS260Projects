//This is the houseQueue contains a queue of houses and is built with data from a file
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git
#pragma once

#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "House.h"

#define MAX_CHAR_SIZE 901

using namespace std;

struct HouseNode
{
	House house;
	HouseNode *nextHouse;
};

class HouseQueue
{
public:
	HouseQueue(char *filename);

	void enqueue(House newHouse);
	House dequeue();
	void display();
	bool queueNotEmpty();


	~HouseQueue();
private:

	HouseNode *head;
	HouseNode *tail;
};	
