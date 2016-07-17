#include "HouseQueue.h"


HouseQueue::HouseQueue(char *filename) // <- constructor constructs from file
{
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
	if(NULL != head)//buypass this code if no house in head taking care of getting the pointer right in all cases
	{
		head->nextHouse = newHouseNode;
	}
	else//basicly -> if(NULL == tail)
	{
		tail = newHouseNode;
	}
	head =newHouseNode;
}

House HouseQueue::dequeue() //you cant refill this thing once it is emptyed .... it will break here if you try to do so
{
	House result;

	if (NULL != tail)
	{

		HouseNode *tempNextHouse = tail->nextHouse;
		result = tail->house;
		//delete tail;
		tail = tempNextHouse;

	}

	return result;//acts like else statement
}

void HouseQueue::display() // would it not be cleaner to overload the output opparator
{
	HouseNode *currentHouseNode = tail;

	do //brakes if no houses there
	{
	cout<< currentHouseNode->house << endl;
	currentHouseNode = currentHouseNode->nextHouse;
	}while(currentHouseNode != head);//stops us at head of linked list
}

bool HouseQueue::queueEmpty()
{
	bool result = false;
	if (NULL != tail)
		result = true;

	return result;
}

HouseQueue::~HouseQueue()
{
	//delete head;
	//delete tail;
}
