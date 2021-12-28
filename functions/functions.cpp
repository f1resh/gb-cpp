#include <iostream>
#include <cstdlib> 

using namespace std;

void PrintArray(const double* , int);
void PrintArray(const int*, int);

void FillArray(int* nArray, int length, int max_value);
void FillArrayTask3(int*, int);
void InverseArray(int*, int);

void ShiftArray(int* nArray, int length, int shift);
void ShiftArrayRight(int* nArray, int length);

int SumSubArray(int* nArray, int first_index, int last_index);
bool CheckBalance(int*, int);

int main()
{
	srand(time(NULL));
	//Task 1
	{
		cout << "Task 1"s << endl;

		const int SIZE = 5;
		double arr[SIZE] = { 1.5, -5.23, 4, 4.01, 4.4 };

		PrintArray(arr, SIZE);
		cout << endl;
	}

	//Task 2
	{
		cout << "Task 2"s << endl;

		const int SIZE = 10;
		int arr[SIZE];

		FillArray(arr, SIZE,1);
		PrintArray(arr, SIZE);
		InverseArray(arr, SIZE);
		PrintArray(arr, SIZE);
		cout << endl;
	}

	//Task 3
	{
		cout << "Task 3"s << endl;

		const int SIZE = 8;

		int arr[SIZE];

		FillArrayTask3(arr, SIZE);
		PrintArray(arr, SIZE);
		cout << endl;
	}

	//Task 4
	{
		cout << "Task 4"s << endl;

		const int SIZE = 10;
		const int SHIFT = 5;

		int arr[SIZE];

		FillArray(arr, SIZE, 10);
		cout << "Initial array of size "s << SIZE << ": \t"s;
		PrintArray(arr, SIZE);
		ShiftArray(arr, SIZE, SHIFT);
		cout << "Array shifted to "s << SHIFT << ":\t\t"s;
		PrintArray(arr, SIZE);
		cout << endl;
	}

	//Task 5
	{
		cout << "Task 5"s << endl;

		const int SIZE = 10;
		int arr[SIZE];  // = {3,-1,2,0};
		FillArray(arr, SIZE,5);
		PrintArray(arr, SIZE);
		cout << "Is array balanced: "s << boolalpha << CheckBalance(arr, SIZE) << endl;

	}
}



//print array of doubles
void __fastcall PrintArray(const double* dArray, const size_t length) {
	for (size_t i = 0; i < length; ++i) {
		cout << dArray[i] << " "s;
	}
	cout << endl;
}

//overload: array of int
void __fastcall PrintArray(const int* nArray, const size_t length) {
	for (size_t i = 0; i < length; ++i) {
		cout << nArray[i] << " "s;
	}
	cout << endl;
}

//fill array with random int numbers up to max_value
void FillArray(int* nArray, const size_t length, int max_value) {
	for (size_t i = 0; i < length; ++i) {
		nArray[i] = rand() % (max_value + 1);
	}
}

//inverse 1->0 and 0->1
void InverseArray(int* nArray, const size_t length) {
	for (size_t i = 0; i < length; ++i) {
		nArray[i] ^= 1;
	}
}

//Task 3
void FillArrayTask3(int* nArray, const size_t length) {
	for (size_t i = 0; i < length; ++i) {
		nArray[i] = 1 + i * 3;
	}
}

void ShiftArray(int* nArray, const size_t length, int shift) {
	int shiftNormalized = shift % length;

	if (shiftNormalized == 0) {
		return;
	}
	else if (shiftNormalized < 0) {
		//convert negative shift to positive
		shiftNormalized += length;
	}
	//do normalized number of shifts right
	for (int i = 0; i < shiftNormalized; ++i) {
		ShiftArrayRight(nArray, length);
	}
}

void ShiftArrayRight(int* nArray, const size_t length) {
	int last = nArray[length - 1];
	for (int i = length - 1; i > 0; --i) {
		nArray[i] = nArray[i - 1];
	}
	nArray[0] = last;
}

//sum subarray from first_index to last_index
int SumSubArray(int* nArray, int first_index, int last_index) {
	int sum = 0;
	for (int i = first_index; i < last_index; i++) {
		sum += nArray[i];
	}
	return sum;
}

bool CheckBalance(int* nArray, const size_t length) {
	for (int i = 1; i < length; ++i) {
		if (SumSubArray(nArray, 0, i) == SumSubArray(nArray, i, length)) return true;
	}
	return false;
}