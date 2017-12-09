#include "board.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#define rows 9
#define cols 9

using namespace std;

Board::Board(int mines)
{
        // create boards instance
        copy = new char* [rows];
        orig = new char* [rows];
        int i = 0;
        int y = 0;
        int x = 0;
        initialize();
        placeMines(mines);

        //count adjecent cell mines
        for(y = 0; y < cols; y++)
        {
                for(x = 0; x < rows; x++)
                {
                        if(orig[x][y] != '*')
                        {
                                int mineSize = 0;
                                countAdjacentMines(x - 1, y - 1, mineSize);
                                countAdjacentMines(x, y - 1, mineSize);
                                countAdjacentMines(x + 1, y - 1, mineSize);
                                countAdjacentMines(x - 1, y, mineSize);
                                countAdjacentMines(x + 1, y, mineSize);
                                countAdjacentMines(x - 1, y + 1, mineSize);
                                countAdjacentMines(x, y + 1, mineSize);
                                countAdjacentMines(x + 1, y + 1, mineSize);
                                char c = (char)(((int)'0')+mineSize);
                                orig[x][y] = c;
                        }
                }
        }
}

void Board::initialize()
{
        int i = 0;
        int y = 0;
        int x = 0;
        while(i < rows)
        {
                copy[i] = new char[cols];
                orig[i] = new char[cols];
                i++;
        }

        // initialize board
        while(y < cols)
        {
                while( x < rows)
                {
                        copy[x][y] = '.';
                        orig[x][y] = '.';
                        x++;
                }
                y++;
        }

}

void Board::placeMines(int mines)
{
        srand(time(NULL));
        int i = 0;
        int y = 0;
        int x = 0;
        // place mines randomly
        for(i = 0; i < mines; i++)
        {
                while(true)
                {
                        x = rand() % rows;
                        y = rand() % cols;
                        if(orig[x][y] != '*')
                        {
                                orig[x][y] = '*';
                                break;
                        }
                }
        }
}



//print board
void Board::print()
{
        cout << endl << "   ";
        int i=0;
        int x=0,y=0;
        //print header
        while(i < rows)
        {
                cout <<i<<" ";
                i++;
        }
        cout << "\n\n";

        while(y < cols)
        {
                cout <<y<< "  ";
                x=0;
                while(x < rows)
                {
                        cout << copy[x][y]<<" ";// print user moves
                        x++;
                }
                y++;
                cout <<"\n";
        }
        cout << "\n";
}
// print mines
void Board::printMines()
{
        cout <<"\n";
        for(int i = 0; i < rows; i++)
        {
                cout <<i<<" ";
        }
        cout << endl << endl;

        for(int y = 0; y < cols; y++)
        {
                cout <<y<< "  ";
                for(int x = 0; x < rows; x++)
                {
                        if(orig[x][y] == '*')
                                cout << orig[x][y]<<" ";
                        else 
                                cout << copy[x][y]<<" ";
                }
                cout << endl;
        }
        cout << endl;
}
char Board::valueAt(int x, int y)
{
        if(isValid(x,y))
        {
                return orig[x][y];
        }
        return 'o';

}
bool Board::isValid(int x, int y)
{
        if(x < rows && y < cols && x >= 0 && y >= 0)
        {
                return true;
        }
        return false;
}
void Board::copyBoard(int x, int y)
{
        copy[x][y] = orig[x][y];
}

// if board[x][y] doesnt contains mine then check it adjecent cells
void Board::isEmpty(int x, int y)
{
        if(isValid(x,y))
        {
                if(orig[x][y] == '0' && copy[x][y] == '.'){
                        copy[x][y] = '0';
                        isEmpty(x - 1, y - 1);
                        isEmpty(x, y - 1);
                        isEmpty(x + 1, y - 1);
                        isEmpty(x - 1, y);
                        isEmpty(x + 1, y);
                        isEmpty(x -1, y + 1);
                        isEmpty(x, y + 1);
                        isEmpty(x + 1, y + 1);
                } else {
                        copyBoard(x, y);
                }
        }
}

int Board::countAdjacentMines(int x, int y, int& mineSize){
        if(isValid(x,y))
        {
                if(orig[x][y] == '*') mineSize++;
        }
        return 0;
}


int Board::isEnd()
{
        for(int y = 0; y < cols; y++)
        {
                for(int x = 0; x < rows; x++)
                {

                        if(copy[x][y] == '.') 
                        {       
                                if(orig[x][y] != '*')
                                {
                                        return 0;
                                }
                        }
                }
        }
        return 1;
}

