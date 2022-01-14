// pointers_dll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

typedef void (*DllFunction)();

int main()
{
    srand(time(NULL));

    DllFunction _dllFunction;
    HINSTANCE hInstLibrary = LoadLibraryA("dll_hw6.dll");


    if (hInstLibrary) {
        std::cout << "go";
        _dllFunction = (DllFunction)GetProcAddress(hInstLibrary, "task_1");
        _dllFunction();

        _dllFunction = (DllFunction)GetProcAddress(hInstLibrary, "task_2");
        _dllFunction();

        _dllFunction = (DllFunction)GetProcAddress(hInstLibrary, "task_3");
        _dllFunction();

        _dllFunction = (DllFunction)GetProcAddress(hInstLibrary, "task_4");
        _dllFunction();

        _dllFunction = (DllFunction)GetProcAddress(hInstLibrary, "task_5");
        _dllFunction();

        FreeLibrary(hInstLibrary);
    };

}

