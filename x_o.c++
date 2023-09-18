#include <iostream>
#include <string.h>
#include <string>
using namespace std;



void print_X_O (char symbols[][3], unsigned int row, unsigned int column); // TO PRINT THE NEW STATE OF GAME AFTER EACH TURN

void init_symbols ();

struct player {
    string player_name;
    char player_symbol;
};


unsigned int counter = 0;                       // THE OUTER LOOP COUNTER
unsigned int index = 0;                         // THE INNER LOOP COUNTER

char symbols[3][3];                             // ARRAY TO STORE Xs AND Os


int main () {
    unsigned int row_num;                       // INDEX OF THE ROW
    unsigned int column_num;                    // INDEX OF THE COLUMN
    char enter;                                 // TO DETERMINE CONDITIONS OF PLAYING
    string beginner;                            // TO DETERMINE WHICH ONE WILL START THE GAME
    unsigned int iden = 0;                      // this counter prevent users to write X or O twice.

    player player_one;
    player player_two;



    cout << "\n X-O GAME FOR CODSOFT INTERN \n \n";

    cout << "Do you wanr to play (Y/N) : ";
    cin >> enter;
    cin.ignore();

    if (enter == 'Y') {

        // information of players
        cout << "For player one, Enter your name : ";
        getline(cin, player_one.player_name);
        cout << "Enter the symbol you want to play with : ";
        cin >> player_one.player_symbol;
        cin.ignore();
        while(1){
        if (player_one.player_symbol != 'X' && player_one.player_symbol != 'O' ) {
            cout << "Invalid symbol! Please Enter X or O : ";
            cin >> player_one.player_symbol;
        }else
            break;
        }
        cout << "For player two, Enter your name : ";
        getline(cin, player_two.player_name);
        if (player_one.player_symbol == 'X') {
            player_two.player_symbol = 'O';
        }else {
            player_two.player_symbol = 'X';
        }


        // which one will start
        cout << "which one will start : " << player_one.player_name << " or " << player_two.player_name << " ? ";
        getline(cin, beginner);

        // check the name of beginner
        while(1) {
            if (beginner != player_one.player_name && beginner != player_two.player_name)
            {
                cout << "Invalid name! type one of the names you entered before, please : ";
                getline(cin, beginner);
            }else
                break;
        }
        ///////////////////////////////////////////////////////

        cout << "\n\n\n\nFill the squares with Xs or Os by entering the number of raw and column, then enter X or O ";
        cout << "Raws start from 0 to 2, columns start from 0 to 2 ";
        cout << "If you fill one raw, column or diagonal with only Xs or only Os, you win, otherwise, it's game draw ";
        cout << "Note: Xs and Os must be upper case, it will treated as a strange symbol if it is not uppercase. \n\n\n\n";

        cout << "\t\t\t\t\t\t\t| 0 0 | 0 1 | 0 2 |" << endl;
        cout << "\t\t\t\t\t\t\t-------------------" << endl;
        cout << "\t\t\t\t\t\t\t| 1 0 | 1 1 | 1 2 |" << endl;
        cout << "\t\t\t\t\t\t\t-------------------" << endl;
        cout << "\t\t\t\t\t\t\t| 2 0 | 2 1 | 2 2 |" << "\n\n\n";

        cout << "\t\t\t\t\t\t\t     |  |  |  |" << endl;
        cout << "\t\t\t\t\t\t\t     ----------" << endl;
        cout << "\t\t\t\t\t\t\t     |  |  |  |" << endl;
        cout << "\t\t\t\t\t\t\t     ----------" << endl;
        cout << "\t\t\t\t\t\t\t     |  |  |  |" << "\n\n\n\n\n";


        while (1) {
            iden = 0;
            init_symbols();

            while(1)
            {

                /////////////////////////////////////////////////////////

                if (beginner == player_one.player_name) {
                    if (iden % 2 == 0) {
                        cout << player_one.player_name  << " enter the row then enter column : ";
                        cin >> row_num >> column_num;
                    }else
                    {
                        cout << player_two.player_name  << " enter the row then enter column : ";
                        cin >> row_num >> column_num;
                    }
                }else
                {
                    if (iden % 2 == 0) {
                        cout << player_two.player_name  << " enter the row then enter column : ";
                        cin >> row_num >> column_num;
                    }else
                    {
                        cout << player_one.player_name  << " enter the row then enter column : ";
                        cin >> row_num >> column_num;
                    }
                }



                //////////////////////////////////////////////////////////


                while(1) {
                if (row_num > 2 || row_num < 0 || column_num > 2 || column_num < 0) {
                    cout << "Invalid index of row and column \n";
                    cout << "enter the row then enter the column : ";
                    cin >> row_num >> column_num;
                }
                else
                    break;
                }

                if (symbols[row_num][column_num] == 'X' || symbols[row_num][column_num] == 'O') {
                    cout << "This place is reserved for symbol : " << symbols[row_num][column_num] << endl;
                    cout << "please choose a free place : ";
                    cin >> row_num >> column_num;
                }


                //////////////////////////
                if (beginner == player_one.player_name) {
                    if (iden % 2 == 0) {
                        symbols[row_num][column_num] = player_one.player_symbol;
                    }else
                    {
                        symbols[row_num][column_num] = player_two.player_symbol;
                    }
                }else
                {
                    if (iden % 2 == 0) {
                        symbols[row_num][column_num] = player_two.player_symbol;
                    }else
                    {
                        symbols[row_num][column_num] = player_one.player_symbol;
                    }
                }
                //////////////////////////



                iden++;
                print_X_O( symbols, row_num, column_num);

                if ((symbols[0][0] == player_one.player_symbol && symbols[0][1] == player_one.player_symbol && symbols[0][2] == player_one.player_symbol) ||
                    (symbols[1][0] == player_one.player_symbol && symbols[1][1] == player_one.player_symbol && symbols[1][2] == player_one.player_symbol) ||
                    (symbols[2][0] == player_one.player_symbol && symbols[2][1] == player_one.player_symbol && symbols[2][2] == player_one.player_symbol) ||
                    (symbols[0][0] == player_one.player_symbol && symbols[1][0] == player_one.player_symbol && symbols[2][0] == player_one.player_symbol) ||
                    (symbols[0][1] == player_one.player_symbol && symbols[1][1] == player_one.player_symbol && symbols[2][1] == player_one.player_symbol) ||
                    (symbols[0][2] == player_one.player_symbol && symbols[1][2] == player_one.player_symbol && symbols[2][2] == player_one.player_symbol) ||
                    (symbols[0][0] == player_one.player_symbol && symbols[1][1] == player_one.player_symbol && symbols[2][2] == player_one.player_symbol) ||
                    (symbols[0][2] == player_one.player_symbol && symbols[1][1] == player_one.player_symbol && symbols[2][0] == player_one.player_symbol))
                {
                    cout << player_one.player_name << " is winner. Congratulations! \n";
                    break;
                }else if ((symbols[0][0] == player_two.player_symbol && symbols[0][1] == player_two.player_symbol && symbols[0][2] == player_two.player_symbol) ||
                            (symbols[1][0] == player_two.player_symbol && symbols[1][1] == player_two.player_symbol && symbols[1][2] == player_two.player_symbol) ||
                            (symbols[2][0] == player_two.player_symbol && symbols[2][1] == player_two.player_symbol && symbols[2][2] == player_two.player_symbol) ||
                            (symbols[0][0] == player_two.player_symbol && symbols[1][0] == player_two.player_symbol && symbols[2][0] == player_two.player_symbol) ||
                            (symbols[0][1] == player_two.player_symbol && symbols[1][1] == player_two.player_symbol && symbols[2][1] == player_two.player_symbol) ||
                            (symbols[0][2] == player_two.player_symbol && symbols[1][2] == player_two.player_symbol && symbols[2][2] == player_two.player_symbol) ||
                            (symbols[0][0] == player_two.player_symbol && symbols[1][1] == player_two.player_symbol && symbols[2][2] == player_two.player_symbol) ||
                            (symbols[0][2] == player_two.player_symbol && symbols[1][1] == player_two.player_symbol && symbols[2][0] == player_two.player_symbol))
                {
                    cout << player_two.player_name << " is winner. Congratulations! \n";
                    break;
                }else if(symbols[0][0] != ' ' && symbols[0][1] != ' ' && symbols[0][2] != ' ' &&
                        symbols[1][0] != ' ' && symbols[1][1] !=  ' ' && symbols[1][2] != ' ' &&
                        symbols[2][0] != ' ' && symbols[2][1] != ' ' && symbols[2][2] != ' ')
                {
                    cout << "No one of you won, it is a DRAW. \n";
                    break;
                }else
                    continue;
            }

            // play again and some edits
            cout << "Do you want to play again (Y/N) : ";
            cin >> enter;
            if (enter == 'N') {
                break;
            }
            cout << "Do you want to change turns (Y/N) ? ";
            cin >> enter;
            if (enter == 'Y') {
                if (beginner == player_one.player_name)
                    beginner = player_two.player_name;
                else
                    beginner = player_one.player_name;
            }
            cout << "Do you want to change symbols (Y/N) ? ";
            cin >> enter;
            if (enter == 'Y') {
                char temp                = player_one.player_symbol;
                player_one.player_symbol = player_two.player_symbol;
                player_two.player_symbol = temp;
            }
        }
    }
    return 0;
}





void print_X_O (char symbols[][3], unsigned int row, unsigned int column) {

        cout << "\t\t\t\t\t\t\t     | " <<symbols[0][0]<<" | " << symbols[0][1] <<" | " <<symbols[0][2] <<" |" << endl;
        cout << "\t\t\t\t\t\t\t     -------------" << endl;
        cout << "\t\t\t\t\t\t\t     | " <<symbols[1][0]<<" | " << symbols[1][1] <<" | " <<symbols[1][2] <<" |" << endl;
        cout << "\t\t\t\t\t\t\t     -------------" << endl;
        cout << "\t\t\t\t\t\t\t     | " <<symbols[2][0]<<" | " << symbols[2][1] <<" | " <<symbols[2][2] <<" |" << endl;
}

void init_symbols () {
    for (counter = 0; counter < 3; counter++)
        for (index = 0; index < 3; index++)
            symbols[counter][index] = ' ';
}

