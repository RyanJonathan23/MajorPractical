// 'guards' to prevent redeclaration of Panda class
#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <string>
#include "animal.h"

// no namespaces in include file!!!

// Class definition
class riverbank
{
 	animal* bankName;
 	int count;

 	public:
 	//Constructors
 	riverbank();

 	//returns the array of the animals
	animal* returnArray();

	//adds an animal to the animal array
	void addAnimal(animal a);

	//subtracts an animal to the animal array
	void removeAnimal(animal a);

	//Prints the status of the bank or what is in the array
	void printBankStatus();

	//checks whether the array has all the animals in it (will use with the while loop)
	bool checkBank();


 	//Destructor
 	~riverbank();
};

#endif