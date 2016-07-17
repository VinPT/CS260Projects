#include "HouseQueue.h"


HouseQueue::HouseQueue(char *filename) // <- constructor constructs from file
{
	head = NULL;
	tail = NULL;

	ifstream houseDataFile(filename);
	if (houseDataFile.good()) //check the file is open
	{
		// read away
		while (true != houseDataFile.eof())
		{
			cout << "Loading Houses..."<<endl;
			char tempChar[MAX_CHAR_SIZE];
   			House tempHouse;


			houseDataFile.get(tempChar, MAX_CHAR_SIZE,';');
			tempHouse.setAdress(tempChar);
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

	else
	{
		cout << "Failed to open file to load houses";
	}
}

void HouseQueue::enqueue(House newHouse)// Thinking overloading the input opparator might be a better plan
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

House HouseQueue::dequeue() //you cant refill this thing once it is emptyed .... it will break here if you try to do so
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

	return result;//acts like else statement
}

void HouseQueue::display() // would it not be cleaner to overload the output opparator
{

	HouseNode *currentHouseNode = head;

	do //brakes if no houses there
	{
	cout<< currentHouseNode->house << endl;
	currentHouseNode = currentHouseNode->nextHouse;
	}while(currentHouseNode != tail);//stops us at head of linked list
}

bool HouseQueue::queueNotEmpty()
{
	bool result = false;
	if (NULL != head)
		result = true;

	return result;
}

HouseQueue::~HouseQueue()
{
	while (queueNotEmpty())
	{
		(void)dequeue();
	}
}
