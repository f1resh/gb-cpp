#include <iostream>
#include <string>

using namespace std;

void task_1() {
	int a, b;
	cout << "Please, enter first number: "s;
	cin >> a;
	cout << "Please, enter second number: "s;
	cin >> b;
	string result;
	if ((a + b >= 10 && a + b <= 20)) {
		result = "true";
	}
	else {
		result = "false";
	}

	cout << result << endl;
}

void task_2() {
	const int a = 4;
	const int b = 15;
	string result;

	if (a == 10 && b == 10) {
		result = "true";
	}
	else if (a + b == 10) {
		result = "true";
	}
	else {
		result = "false";
	}
	cout << result << endl;
}

void task_3() {
	cout << "Your numbers: "s;
	for (size_t i = 1; i < 50; i += 2) {
		cout << i << " ";
	}
	cout << endl;
}

string NumberType(int number) {
	for (size_t i = 2; i < number; ++i) {
		if (number % i == 0) {
			return "Composite";
		}
	}
	return "Prime";
}

bool IsLeap(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) return true; else return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main()
{
	//Task 1
	task_1();

	//Task 2
	task_2();

	//Task 3
	task_3();

	//Task 4
	{
		int n;
		cout << "Please enter number: "s;
		cin >> n;
		cout << "Number "s << n << " is "s << NumberType(n) << endl;
	}

	//Task 5
	{
		cout << 100 % 400 << endl;
		int year;
		do {
			cout << "Please, enter year in range [1..3000]: "s;
			cin >> year;

		} while (year < 1 || year>3000);

		if (IsLeap(year)) {
			cout << "This year is Leap!"s << endl;
		}
		else {
			cout << "This year is NOT Leap!"s << endl;
		}
	}
	
}


