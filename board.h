#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class Board {
  protected:

    // tamaño del tablero
    int totalRows, totalColumns, totalMines;
    // vector de vectores de juego
    vector < vector < int >> board;

    void initialize();

  public:
    //constructor
    Board(int f, int c, int m);

    //getters
    int getTotalRows() const;
    int getTotalColumns() const;
};

#endif // BOARD_H
