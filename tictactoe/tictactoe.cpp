#include <iostream>
#include <random>

//size of field
#define SIZE 3

#define SQR(x) (x*x)

using namespace std;

enum ECell : char {
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'
};

enum ETurn {
    HUMAN = 0,
    AI = 1
};

enum EStatus {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct Game {
    const size_t size{ SQR(SIZE) }; //number of fields in pField
    ECell* pField{nullptr};
    EStatus status{IN_PROGRESS};
    ETurn turn{HUMAN};
    ECell human;
    ECell ai;
};


void clearConsole() {
    system("cls");
    cout << "\x1b[H\x1b[2J";
};

void initGame(Game &game) {
    game.status = IN_PROGRESS;
    game.turn = static_cast<ETurn>(rand() % 2);
    if (game.turn == HUMAN) {
        game.human = CROSS;
        game.ai = ZERO;
    }
    else {
        game.human = ZERO;
        game.ai = CROSS;
    }


    game.pField = new ECell[game.size];
    for (size_t i = 0; i < game.size; i++) {
        game.pField[i] = EMPTY;
    }
}

void deinitGame(Game& game) {
    delete[] game.pField;
    game.pField = nullptr;
}


void printGame(const Game &game) {
    clearConsole();
    cout << "Field numbers:" << endl;
    cout << "-------------" << endl
        << "| 1 | 2 | 3 |" << endl
        <<  "-------------" << endl
        << "| 4 | 5 | 6 |" << endl
        <<  "-------------" << endl
        << "| 7 | 8 | 9 |" << endl
        <<  "-------------" << endl;

    cout << "Status of the current game" << endl;
    for (size_t i = 0; i < SIZE; i++) {
        cout << "-------------" << endl;
        for (size_t j = 0; j < SIZE; j++) {
            cout << "| " << game.pField[i * 3 + j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
    cout << "Human: " << game.human << "      AI: " << game.ai << endl;
}

EStatus getStatus(const Game& game) {
    //checking lines
    for (size_t i = 0; i < SIZE; i++) {
        //horizontal checks
        if (game.pField[3*i] == game.pField[3*i + 1] && game.pField[3*i] == game.pField[3*i + 2] && game.pField[3*i]!=EMPTY) {
           return game.pField[3*i] == game.human ? WON_HUMAN : WON_AI;
        }

        //vertical checks
        if (game.pField[i] == game.pField[i + 3] && game.pField[i] == game.pField[i + 6] && game.pField[i] != EMPTY) {
           return game.pField[i] == game.human ? WON_HUMAN : WON_AI;
        }
    }

    //checking diags
    if (game.pField[0] == game.pField[4] && game.pField[0] == game.pField[8] && game.pField[0] != EMPTY) {
        return game.pField[0] == game.human ? WON_HUMAN : WON_AI;
    }
    if (game.pField[2] == game.pField[4] && game.pField[2] == game.pField[6] && game.pField[2] != EMPTY) {
        return game.pField[2] == game.human ? WON_HUMAN : WON_AI;
    }

    //Checking empty fields
    for (size_t i = 0; i < game.size; i++) {
        if (game.pField[i] == EMPTY) return IN_PROGRESS;
    }

    //draw if no win and no empty fields
    return DRAW;
}

int playerTurn(const Game &game) {
    int i{0};
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
        }

        cout << "It's your turn. Please enter number of field: ";
        cin >> i;
    } while (i<1 || i>game.size || game.pField[i-1] != EMPTY || cin.fail());
    return i-1;
}

int aiTurn(Game &game) {
    //PRE WIN/LOSS


    for (size_t i = 0; i < game.size; i++) {
        if (game.pField[i] == EMPTY) {
            game.pField[i] = game.ai;
            if (getStatus(game) == WON_AI) {
                game.pField[i] = EMPTY;
                return i;
            }

            game.pField[i] = game.human;
            if (getStatus(game) == WON_HUMAN) {
                game.pField[i] = EMPTY;
                return i;
            }
            game.pField[i] = EMPTY;

        }
    }

    //TAKE CENTER
    if (game.pField[4] == EMPTY) {
        return 4;
    }

    
    //CORNERS
    int buf[4];
    size_t num{ 0 };
    int temp[4]{ 0,2,6,8 };
    for (const int i : temp) {
        if (game.pField[i] == EMPTY) {
            buf[num] = i;
            num++;
        }
    }
    if (num > 0) {
        return buf[rand() % num];
    }

    //DEFAULT
    num = 0;
    temp[0] = 1; temp[1] = 3; temp[2] = 5; temp[3] = 7;
    for (const int i : temp) {
        if (game.pField[i] == EMPTY) {
            buf[num] = i;
            num++;
        }
    }
    if (num > 0) {
        return buf[rand() % num];
    }
}


int main()
{
    srand(time(NULL));
    Game game;
    initGame(game);
    int i;

    do {
        printGame(game);

        if (game.turn == HUMAN) {
            int field = playerTurn(game);
            game.pField[field] = game.human;
        }
        else if (game.turn == AI) {
            int field = aiTurn(game);
            game.pField[field] = game.ai;
        }

        game.turn = (game.turn==HUMAN) ? AI : HUMAN;
        game.status = getStatus(game);


    } while (game.status == IN_PROGRESS);

    printGame(game);

    if (game.status == WON_AI) {
        cout << "Sorry, you're not a winner :( AI won!" << endl;
    }
    else if (game.status == WON_HUMAN) {
        cout << "You win!" << endl;
    }
    else if (game.status == DRAW) {
        cout << "DRAW!" << endl;
    }

    deinitGame(game);

}

