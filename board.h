#ifndef BOARD_H
#define BOARD_H

class Board
{
        public:
                Board(int mines);
                void print();
                void placeMines(int mines);
                void initialize();
                void printMines();
                char valueAt(int x, int y);
                void copyBoard(int x, int y);
                void isEmpty(int x, int y);
                int countAdjacentMines(int x, int y, int& minecount);
                int isEnd();
                bool isValid(int x, int y);
        private:
                // to represent board, 2 arrays are create 1. copy, 2. orgi.
                // the array1 keep tracks of user moves while array2 keep tracks of mines and their counts
                char** copy;
                char** orig;

};

#endif
