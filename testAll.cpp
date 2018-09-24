//Use this to complile tests
//g++ -o testAll animal.cpp cat.cpp dog.cpp mouse.cpp returnID.cpp riverbank-array-two.cpp testAll.cpp

#include <iostream>
#include <string>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern int returnID(string word);

int main(void)
{
	cout << endl << "==== ==== ==== ==== ====" << endl << "Program starts here" << endl << "==== ==== ==== ==== ====" << endl << endl;

	//********** Testing creating all the animals **********//

	//Testing creating an animal and setting it's initial and species

	cout << "TESTING ANIMALS" << endl << endl;
	animal defaultAnimal(117, "Undefined Animal");	// 117 = u

	//testing getters
	cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;

	// test setters
	defaultAnimal.setInitial(99);	//102 = c
	defaultAnimal.setSpecies("Fake Cat");
	cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;

	// Creating animal pointers to a cat, dog and mouse and testing their functions
	cat* kitten = new cat;
	cout << kitten->getSpecies() << " has the initial " << kitten->getInitial() << ", " << kitten->getSpecies() << "'s go " << kitten->makeSound(2) <<endl;

	dog* puppy = new dog;
	cout << puppy->getSpecies() << " has the initial " << puppy->getInitial() << ", " << puppy->getSpecies() << "'s go " << puppy->makeSound(2)<<endl;

	mouse* stuart = new mouse;
	cout << stuart->getSpecies() << " has the initial " << stuart->getInitial() << ", " << stuart->getSpecies() << "'s go " << stuart->makeSound(2)<<endl;
	

	//********** Testing returnID function **********//

	//the function take a string and retuns an integer 1 for dog or any variation (dOg, Dog, doG), 2 for cat, 3 for mouse or 4 for pass
	cout << endl << endl <<"TESTING RETURN ID FUNCTION" << endl << endl;

	cout << "Dog - If this works, will print 1: " << returnID("dog") << endl;
	cout << "DOg - If this works, will print 1: " << returnID("dOg") << endl;
	cout << "DoG - If this works, will print 1: " << returnID("doG") << endl;
	cout << "DOG - If this works, will print 1: " << returnID("DOG") << endl;

	cout << "Cat - If this works, will print 2: " << returnID("cat") << endl;
	cout << "Mouse - If this works, will print 3: " << returnID("mouse") << endl;
	cout << "Pass - If this works, will print 4: " << returnID("pass") << endl;
	cout << "Blah - If this works, will print 99: " << returnID("Blah") << endl;


	//********** Testing riverbank class and its functions **********//

	cout << endl << endl << "TESTING RIVERBANK CLASS" << endl << endl;

	riverbank A;

	//initialiseNULL() test
	A.initialiseNULL();
	animal** a = A.returnArray();
	cout << "Testing initialiseNULL() function" << endl;
		cout << "if it prints NULL three times, the function works" << endl;
		cout << "Prints: ";
	for(int i = 0; i < 3; i++)
		if (a[i]==NULL)
			cout << "NULL" << " ";
	cout << endl << endl;

	//testing adding animals to the array and the print function
	cout << "Testing addAnimal() function" << endl;
	A.addAnimal(kitten);
	A.addAnimal(puppy);
	A.addAnimal(stuart);
	cout << "If this works, will print Cat Dog Mouse" << endl;
	cout << "Prints: ";
	A.printBankStatus();
	cout << endl;


	//if all animals are in the array, returns true
	cout << "Testing checkBank() function on full array" << endl;
	cout << "if it prints true, the function works" << endl;
	if (A.checkBank() == true)
		cout << "Prints: true" << endl << endl;

	//testing removing animals to the array
	cout << "Testing removeAnimal() function" << endl;
	A.removeAnimal(puppy);
	cout << "If this works, will print Cat Mouse" << endl;
	cout << "Prints: ";
	A.printBankStatus();


	cout << endl << "Testing checkBank() function on partly full array" << endl;
	cout << "if it prints false, the function works" << endl;
	if (A.checkBank() == false)
		cout << "Prints: false" << endl << endl;


	cout << endl << "Testing checkAnimals() function on array with Cat and Mouse" << endl;
	cout << "if it prints true, the function works" << endl;
	if (A.checkAnimals() == 2)
		cout << "Prints: true" << endl << endl;


	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for cat)" << endl;
	cout << "if it prints true, the function works" << endl;
	if (A.checkIfExists(kitten) == true)
		cout << "Prints: true" << endl << endl;


	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for dog)" << endl;
	cout << "if it prints false, the function works" << endl;
	if (A.checkIfExists(puppy) == false)
		cout << "Prints: false" << endl;


	//deleting memory allocated
	delete kitten;
	delete puppy;
	delete stuart;

	cout << endl << "==== ==== ==== ==== ====" << endl << "Program ends here" << endl << "==== ==== ==== ==== ====" << endl;


}
