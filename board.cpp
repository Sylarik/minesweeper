#include "board.h"

Board::Board(int f, int c, int m) {
  totalRows = f;
  totalColumns = c;
  totalMines = m;
  board.resize(totalRows);
  for (int i = 0; i < totalRows; i++) {
    board[i].resize(totalColumns);
  }
  initialize();
}

void Board::initialize() {
  srand(time(NULL));

  // Inicializar todas las casillas en 0
  for (int i = 0; i < totalRows; i++) {
    for (int j = 0; j < totalColumns; j++) {
      board.at(i).at(j) = 0;
    }
  }

  int minesPlaced = 0;
  while (minesPlaced < totalMines) {
    int f = rand() % totalRows;
    int c = rand() % totalColumns;
    if (board.at(f).at(c) != -1) { // Si la casilla no tiene una mina ya colocada
      board.at(f).at(c) = -1; // Colocar la mina
      minesPlaced++;
    }
  }

  // Contar el número de minas adyacentes a cada casilla
  for (int i = 0; i < totalRows; i++) {
    for (int j = 0; j < totalColumns; j++) {
      if (board.at(i).at(j) != -1) { // Si la casilla no es una mina
        int closeMines = 0;

        //cambiar
        for (int f = max(i - 1, 0); f <= min(i + 1, totalRows - 1); f++) { //limites del tablero
          for (int c = max(j - 1, 0); c <= min(j + 1, totalColumns - 1); c++) {
            if (board[f][c] == -1) { // Si la casilla adyacente es una mina
              closeMines++;
            }
          }
        }
        board[i][j] = closeMines; // Asignar el número de minas adyacentes a la casilla
      }
    }
  }
}

int Board::getTotalRows() const {
  return totalRows;
}

int Board::getTotalColumns() const {
  return totalColumns;
}
