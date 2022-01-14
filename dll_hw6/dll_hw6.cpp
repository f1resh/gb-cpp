#include "pch.h"
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include "dll_hw6.h"

#define DLL_EXPORT

using namespace std;

extern "C" {
    void printTaskNumber(int number) {
        cout << "========================================="s << endl << "Task "s << number << endl;
    }

    //==================================================================================================
    //TASK 1

    void task_1() {
        printTaskNumber(1);
        int* ptrArr;
        size_t n = getPositiveInt();

        ptrArr = new (std::nothrow) int[n];
        if (ptrArr != nullptr)
        {
            initArrayWith2(ptrArr, n);
            printArray(ptrArr, n);
            clearArray(ptrArr);
        }
        else
        {
            cout << "Error! Can not allocate memory!" << endl;
        }

    }

    int getPositiveInt() {
        while (true)
        {
            cout << "Enter an positive integer value: ";
            int num;
            cin >> num;
            if (cin.fail() || num <= 0)
            {
                cout << "Error. Enter an positive integer value!" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
            }
            else
            {
                return num;
            }
        }
    }

    void __fastcall initArrayWith2(int* ptr, size_t length) {
        ptr[0] = 1;
        for (size_t i = 1; i < length; i++) {
            ptr[i] = ptr[i - 1] << 1;
        }
    }

    void __fastcall clearArray(int* ptr) {
        delete[] ptr;
        ptr = nullptr;
    }

    void __fastcall printArray(int* ptr, size_t length) {
        for (size_t i = 0; i < length; i++) {
            cout << ptr[i] << " "s;
        }
        cout << endl;
    }

    //==================================================================================================
    //Task 2

    int** __fastcall allocIntMatrix(size_t strs, size_t cols) {
        int** ptr;
        ptr = new int* [strs];
        for (size_t i = 0; i < strs; i++) {
            ptr[i] = new int[cols];
        }
        return ptr;
    }

    void __fastcall initMatrixWithRand(int** ptr, size_t strs, size_t cols) {
        const int MAX_VALUE = 100;
        for (size_t i = 0; i < strs; i++) {
            for (size_t j = 0; j < cols; j++) {
                ptr[i][j] = rand() % MAX_VALUE + 1;
            }
        }
    }

    void __fastcall printMatrix(int** ptr, size_t strs, size_t cols) {
        for (size_t i = 0; i < strs; i++) {
            printArray(ptr[i], cols);
        }
    }

    void __fastcall clearMatrix(int** ptr, size_t strs) {
        for (size_t i = 0; i < strs; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = nullptr;
    }

    void task_2() {
        printTaskNumber(2);

        int** ptrMatrix;
        const int SIZE = 4;

        ptrMatrix = allocIntMatrix(SIZE, SIZE);
        initMatrixWithRand(ptrMatrix, SIZE, SIZE);
        printMatrix(ptrMatrix, SIZE, SIZE);
        clearMatrix(ptrMatrix, SIZE);
    }

    //==================================================================================================
    //Task 3

    void task_3() {
        printTaskNumber(3);

        string filename = getFileNameToWrite();

        fillFileWithText(filename);

        clearCinBuf();

        filename = getFileNameToWrite();

        fillFileWithText(filename);
    }

    string getFileNameToWrite() {
        while (true)
        {
            cout << "Enter name of file: ";
            string name;
            cin >> name;
            if (cin.fail())
            {
                cout << "Error. Enter name of file:" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
            }
            else
            {
                return name;
            }
        }
    }

    void fillFileWithText(string filename) {
        const int MIN_CHARS = 50;
        ofstream fout(filename + ".txt");
        for (int i = 0; i < rand() % MIN_CHARS + MIN_CHARS; i++) {
            fout << (char)('a' + rand() % 26);
        }
        fout.close();
    }

    void clearCinBuf() {
        cin.clear();
        cin.ignore(32767, '\n');
    }

    //==================================================================================================
    //Task 4

    void task_4() {
        printTaskNumber(4);


        const int FILES_NUMBER = 2;
        string filenames[FILES_NUMBER];
        //We can modify this, by asking user number of files to read from instead of CONST number

        cout << "Please enter filenames to read from. Number of files is "s << FILES_NUMBER << endl;
        for (int i = 0; i < FILES_NUMBER; i++) {
            filenames[i] = getFileNameToRead();
        }

        cout << "Please enter filename to write to."s << endl;
        string concat_file = getFileNameToWrite();

        concatFiles(concat_file, filenames, FILES_NUMBER);
    }

    string getFileNameToRead() {
        while (true)
        {
            cout << "Enter name of file: ";
            string name;
            cin >> name;
            if (cin.fail() || !filesystem::exists(name))
            {
                cout << "Error. Enter name of file that exists:" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
            }
            else
            {
                return name;
            }
        }
    }

    void copyContent(const string& file_source, ofstream& file_dest) {
        ifstream fin(file_source);
        if (fin.is_open()) {
            string buf;
            while (getline(fin, buf)) {
                file_dest << buf << endl;
            }
        }
        fin.close();
    }

    void concatFiles(const string& concat_file, const string files[], int files_number) {
        ofstream fout(concat_file);

        for (int i = 0; i < files_number; i++) {
            copyContent(files[i], fout);
        }

        fout.close();
    }




    //==================================================================================================
    //Task 5
    void task_5() {
        printTaskNumber(5);

        string word;
        cout << "Please, enter the word to search: "s;
        cin >> word;

        string filename = getFileNameToRead();

        cout << "File "s + filename + " contains word '"s + word + "'? "s << boolalpha << isWordInFile(word, filename) << endl;
    }

    bool isWordInFile(const string& word, const string& filename) {
        ifstream fin(filename);
        if (fin.is_open()) {
            string buf;
            while (getline(fin, buf)) {
                if (buf.find(word) != string::npos)
                {
                    return true;
                }
            }
            return false;
        }
        cerr << "Error. File "s + filename + " couldn't be opened!"s << endl;
        return false;
    }
}