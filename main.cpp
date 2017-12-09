#include <iostream>
#include "board.h"
#include <string>
#include <time.h>
#define minecount 20
using namespace std;

Board board(minecount);
int play(int x, int y)
{
        char v = board.valueAt(x,y);
        switch(v)
        {
                case '*':
                        board.printMines();
                        return -1;
                        break;
                case '0':
                        board.isEmpty(x, y);
                        break;
                case 'o':
                        break;
                default:
                        board.copyBoard(x, y);
                        break;
        }
        if(board.isEnd() == 1) 
        {
                board.print();
                return 1;
        }

        cout << endl;
        board.print();
        return 0;
}

int main()
{
        int x, y, state;
        board.print();
        while(true)
        {
                cout << "Enter X: ";
                cin >> x;

                cout << "Enter Y: ";
                cin >> y;

                state = play(x, y);

                if(state == -1) 
                {
                        cout << endl << "You lost. Press any key to exit."<< endl; 
                        return 0;
                }
                else
                {
                        cout << endl << "Congratulations! You won the game."<< endl;
                        return 0;
                }
        }
        return 0;
}

