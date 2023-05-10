#ifndef PLAYABLEBOARD_H
#define PLAYABLEBOARD_H

#include <iostream>

#include "board.h"


class PlayableBoard: public Board {
  private:
    // vector de vectores que indica si cada casilla está visible o no
    vector < vector < string >> hiddenBoard;
    bool endGame = false;
    int freeSquares;
    string name;
    int WonGames = 0;
  public:

    void initialize();

    PlayableBoard(int f, int c, int m);

    const string &getName() const;

    void setName(const string &newName);

    vector < vector < string >> getHiddenBoard();

    void changeContent(int f, int c);

    void check(int f, int c);

    void flag(int f, int c);

    void removeFlag(int f, int c);

    int menuPlay();

    void play();

    friend ostream & operator << (std::ostream & os, PlayableBoard & tablero) {
      //fila superior numeros columna
      os << "  ";
      for (int j = 0; j < tablero.getTotalColumns(); j++) {
        os << j << " ";
      }
      os << endl;

      //tablero
      for (int i = 0; i < tablero.getTotalRows(); i++) {
        // Imprimir el número de fila a la izquierda
        os << i << " ";

        // Imprimir las casillas de la fila actual
        for (int j = 0; j < tablero.getTotalColumns(); j++) {
          os << tablero.getHiddenBoard().at(i).at(j) << " ";

        }
        os << endl;
      }
      os << endl;
      return os;
    }
};

#endif // PLAYABLEBOARD_H
