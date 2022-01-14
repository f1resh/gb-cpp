#pragma once
//#ifndef _DLL_HW6_H_
//#define _DLL_HW6_H_
#include <iostream>
#include <string>

#ifdef DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

extern "C" {
	using namespace std;

	DECLDIR bool isWordInFile(const string& word, const string& filename);

	DECLDIR void task_5();

	DECLDIR void task_1();

	DECLDIR int getPositiveInt();

	DECLDIR void __fastcall initArrayWith2(int* ptr, size_t length);

	DECLDIR void __fastcall clearArray(int* ptr);

	DECLDIR void __fastcall printArray(int* ptr, size_t length);

	DECLDIR int** __fastcall allocIntMatrix(size_t strs, size_t cols);

	DECLDIR void __fastcall initMatrixWithRand(int** ptr, size_t strs, size_t cols);

	DECLDIR void __fastcall printMatrix(int** ptr, size_t strs, size_t cols);

	DECLDIR void __fastcall clearMatrix(int** ptr, size_t strs);

	DECLDIR void task_2();

	DECLDIR string getFileNameToWrite();

	DECLDIR void fillFileWithText(string filename);

	DECLDIR void clearCinBuf();

	DECLDIR void task_3();

	DECLDIR string getFileNameToRead();

	DECLDIR void copyContent(const string& file_source, ofstream& file_dest);

	DECLDIR void concatFiles(const string& concat_file, const string files[], int files_number);

	DECLDIR void task_4();
}

//#endif