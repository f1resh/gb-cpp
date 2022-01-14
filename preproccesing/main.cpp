#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"

#define CHECK(a,max) (a >= 0 && a<max )

#define ARRAY_SIZE 5


int main()
{
	//Task 1 - 5
	myLib::printTaskNumber(5);

	float* fArr = myLib::initArray(ARRAY_SIZE);
	myLib::printArray(fArr, ARRAY_SIZE);
	myLib::countPositiveNegative(fArr, ARRAY_SIZE);

	/*fArr = new float[ARRAY_SIZE] {0, 0, 0, 0, 0};
	myLib::printArray(fArr, ARRAY_SIZE);
	myLib::countPositiveNegative(fArr, ARRAY_SIZE);*/

	delete[] fArr;
	fArr = nullptr;


	//Task 2
	myLib::printTaskNumber(2);
	const int max = 10;

	std::cout << "Please, enter number: ";
	int x;
	std::cin >> x;
	std::cout << std::boolalpha << CHECK(x, max) << std::endl;


	//Task 3
	myLib::printTaskNumber(3);
	int Arr[ARRAY_SIZE];
	std::cout << "Please, enter " << ARRAY_SIZE << " array elements of type int: ";
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cin >> Arr[i];
	}

	std::cout << "Unsorted array: " << std::endl;
	myLib::printArray(Arr, ARRAY_SIZE);

	myLib::sortBubble(Arr, ARRAY_SIZE);
	std::cout << "Sorted array: " << std::endl;
	myLib::printArray(Arr, ARRAY_SIZE);


	//Task 4
	myLib::printTaskNumber(4);

	const std::string filename = "struct.txt";

	Employee *pManager = new Employee;
	pManager->id = 1523;
	pManager->salary = 10'000;
	pManager->birthYear = 1990;
	pManager->passportId = 72329424;

	pManager->print();
	std::cout << "Size of structure = " << sizeof(*pManager) << std::endl;

	std::ofstream fout(filename, std::ios_base::binary);
	if (fout.is_open()) {
		fout.write((char*)pManager, sizeof(*pManager));
		fout.close();
		std::cout << "Structure is saved to file " << filename << std::endl << std::endl;
	}

	delete pManager;
	pManager = nullptr;

	std::cout << "Reading structure from file " << filename << std::endl;
	Employee *read = new Employee;
	std::ifstream fin(filename, std::ios_base::binary);
	if (fin.is_open()) {
		fin.read((char*)read, sizeof(*read));
		fin.close();
	}
	read->print();

	delete read;
	read = nullptr;

}

