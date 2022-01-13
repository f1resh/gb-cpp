#pragma once

namespace myLib {

	float* __fastcall initArray(size_t size);

	void __fastcall printArray(const float Array[], size_t size);
	void __fastcall printArray(const int Array[], size_t size);

	void __fastcall countPositiveNegative(const float Array[], size_t size);

	void __fastcall printTaskNumber(int number);

	void __fastcall sortBubble(int Array[], size_t size);
}


#pragma pack(push,1)

struct Employee {
	uint32_t id;
	uint16_t salary;
	uint16_t birthYear;
	uint32_t passportId;

	void print() {
		std::cout << "Id = " << id << "\n"
			<< "Salary = " << salary << "\n"
			<< "BirthYear = " << birthYear << "\n"
			<< "PassportId = " << passportId << std::endl;
	}		
};

#pragma pack(pop)