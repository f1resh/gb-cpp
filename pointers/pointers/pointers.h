#pragma once
#ifndef ADD_H
#define ADD_H
#include <string>

using namespace std;

bool isWordInFile(const string& word, const string& filename);

void task_5();

void task_1();

int getPositiveInt();

void __fastcall initArrayWith2(int* ptr, size_t length);

void __fastcall clearArray(int* ptr);

void __fastcall printArray(int* ptr, size_t length);

int** __fastcall allocIntMatrix(size_t strs, size_t cols);

void __fastcall initMatrixWithRand(int** ptr, size_t strs, size_t cols);

void __fastcall printMatrix(int** ptr, size_t strs, size_t cols);

void __fastcall clearMatrix(int** ptr, size_t strs);

void task_2();

string getFileNameToWrite();

void fillFileWithText(string filename);

void clearCinBuf();

void task_3();

string getFileNameToRead();

void copyContent(const string& file_source, ofstream& file_dest);

void concatFiles(const string& concat_file, const string files[], int files_number);

void task_4();

#endif // !ADD_H
