//This is the house queue deals with adding the houses from list and giving them to you one by one 
//Written by Vinayaka Patrick Thompson;
//Sources Project1, Project2Description, Project2DriverCode
//https://github.com/caspen/CS260Projects.git
#include "HouseQueue.h"


HouseQueue::HouseQueue(char *filename) // <- constructor constructs from file
{
	head = NULL;
	tail = NULL;

	ifstream houseDataFile(filename);
	if (houseDataFile.good()) //check the file is open
	{
		// read starts here
		while (true != houseDataFile.eof())
		{
			cout << "Loading Houses..."<<endl;
			char tempChar[MAX_CHAR_SIZE];
   			House tempHouse;


			houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
			tempHouse.setAddress(tempChar);
			houseDataFile.ignore(MAX_CHAR_SIZE, ';');

			houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
        		tempHouse.setSqFootage(atoi(tempChar));
      			houseDataFile.ignore(MAX_CHAR_SIZE, ';');

			houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
        		tempHouse.setNumBedrooms(atoi(tempChar));
	       		houseDataFile.ignore(MAX_CHAR_SIZE, ';');

        		houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
        		tempHouse.setNumBathrooms(atof(tempChar));
       			houseDataFile.ignore(MAX_CHAR_SIZE, ';');     // tabs are sometimes spaces here (i think coppy and paste uses spaces insted of tabs)

			houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
			tempHouse.setDescription(tempChar);
			houseDataFile.ignore(MAX_CHAR_SIZE, ';');

			enqueue(tempHouse);


  		}
		cout <<" Houses successfully loaded." << endl //; on next line
			<< endl;

		houseDataFile.close();

	}

	else // Makes sure to tell you you dont have your data file
	{
		cout << "Failed to open file to load houses";
	}
}

//adds houses to the tail
void HouseQueue::enqueue(House newHouse)
{
	HouseNode *newHouseNode = new HouseNode();

	newHouseNode->house = newHouse;
	newHouseNode->nextHouse = NULL;
	if(NULL != tail)//buypass this code if no house in head taking care of getting the pointer right in all cases
	{
		tail->nextHouse = newHouseNode;
	}
	else//basicly -> if(NULL == head)
	{
		head = newHouseNode;
	}
	tail =newHouseNode;
	return;
}

// removes houses from queue and deletes the node removed
House HouseQueue::dequeue() 
{
	House result;

	if (NULL != head)
	{

		HouseNode *tempNextHouse = head->nextHouse;
		result = head->house;
		head->nextHouse = NULL;
		delete head;
		head = tempNextHouse;

	}

	return result;//acts like else statement. Empty house returned if no houses in queue
}

// Desplays Houses
void HouseQueue::display() // would it not be cleaner to overload the output opparator as we assume there is a terminal to output to here
{

	HouseNode *currentHouseNode = head;

	do //brakes if no houses in queue
	{
	cout<< currentHouseNode->house << endl;
	currentHouseNode = currentHouseNode->nextHouse;
	}while(currentHouseNode != tail);//stops us at tail of linked list
}

//tells us if we are empty
bool HouseQueue::queueNotEmpty()
{
	bool result = false;
	if (NULL != head)
		result = true;

	return result;
}

//Destructor
HouseQueue::~HouseQueue()
{
	while (queueNotEmpty())//<- Hygiene has been added to remove odd smells from program.
	{
		(void)dequeue();
	}
}
