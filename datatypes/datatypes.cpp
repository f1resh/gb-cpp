#include <iostream>

using namespace std;

int main()
{
    //Task1 #1
    {
        short int   iVar1 = -42;
        int         iVar2(232322);
        long long   verylongnumber = { 1293'1042'1047'1247 };
        char        character = 'X';
        bool        bVar{ false };
        auto        Var3 = 3.56f;
        auto        Var4 = double(-232.444242);
    }

    //Task #2
    {
        enum FieldSymbols {
            Empty = ' ',
            Cross = 'X',
            Zero = 'O'
        };

    //Task #3
        FieldSymbols Field[3][3] = { Empty,Zero,Empty,Empty,Empty,Cross,Empty,Empty,Empty };

        //for output
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << (char)Field[i][j] << "|";
            }
            cout << endl << "------" << endl;
            
        }

    //Task #4
        struct TicTacToe {
            //initializing of empty field
            FieldSymbols Field[3][3] = { Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty };

            //can't change C-strings, only by pointers :)
            char Player1[9] = "Player 1";
            char Player2[9] = { 'P','l','a','y','e','r',' ','2',0 };

            bool isFinished = 0;

            //who's turn
            enum Turn {
                P1,
                P2
            } PlayerTurn = Turn::P1;

        };
    }

    //Task #5
    {
        struct MyVariant {
            union MyData {
                int var_int;
                float var_float;
                char var_char;
            } Data;
            unsigned int isInt : 1;
            unsigned int isFloat : 1;
            unsigned int isChar : 1;
        };
        MyVariant Variant;

        
        //int
        Variant.Data.var_int = 5;
        Variant.isInt = 1;
        Variant.isFloat = 0;
        Variant.isChar = 0;
        cout << endl;
        cout << Variant.Data.var_int << endl;

        //float
        Variant.Data.var_float = -245.242f;
        Variant.isInt = 0;
        Variant.isFloat = 1;
        Variant.isChar = 0;
        cout << Variant.Data.var_float << endl;

        //char
        Variant.Data.var_char = 't';
        Variant.isInt = 0;
        Variant.isFloat = 0;
        Variant.isChar = 1;
        cout << Variant.Data.var_char << endl;
    }
}