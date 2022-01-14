#include <iostream>
#include <iomanip>

#define MAX 50.0 //
#define FIXED_FLOAT(x) std::fixed<<std::setprecision(x)
#define SwapINT(a,b) (a ^= b ^= a ^= b)

namespace myLib {

	float* __fastcall initArray(size_t size) {
		float* fArray = new float[size] {};
		for (int i = 0; i < size; ++i) {
			fArray[i] = ((float)rand() / RAND_MAX * 2 * MAX - MAX);
		}
		return fArray;
	}

	void __fastcall printArray(const float Array[], size_t size) {
		for (int i = 0; i < size; ++i) {
			std::cout << FIXED_FLOAT(2) << Array[i] << " ";
		}
		std::cout << std::endl;
	}

	//overload for array of int
	void __fastcall printArray(const int Array[], size_t size) {
		for (int i = 0; i < size; ++i) {
			std::cout << Array[i] << " ";
		}
		std::cout << std::endl;
	}

	void __fastcall countPositiveNegative(const float Array[], size_t size) {
		int pos{0}, neg{0};
		for (int i = 0; i < size; ++i) {
			if (Array[i] > 0) ++pos;
			if (Array[i] < 0) ++neg;
		}
		std::cout << "Number of positive: " << pos << ", number of negative: " << neg << std::endl;
	}

	void __fastcall printTaskNumber(int number) {
		std::cout << "=========================================" << std::endl << "Task " << number << std::endl;
	}

	void __fastcall sortBubble(int Array[], size_t size) {
		int i, j;
		for (i = 0; i < size - 1; ++i) {
			for (j = 0; j < size - 1 - i; ++j) {
				if (Array[j] > Array[j + 1]) SwapINT(Array[j], Array[j + 1]);
			}
		}
	}

	

}