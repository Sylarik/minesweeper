#include "playableboard.h"

PlayableBoard::PlayableBoard(int f, int c, int m): Board(f, c, m) {
  freeSquares = f * c - m;
  initialize();
}

const string &PlayableBoard::getName() const {
    return name;
}

void PlayableBoard::setName(const string &newName) {
    name = newName;
}

void PlayableBoard::initialize() {
  for (int i = 0; i < totalRows; i++) {
    hiddenBoard.push_back(vector < string > ());
    for (int j = 0; j < totalColumns; j++) {
      hiddenBoard.back().push_back("-");
    }
  }
}

vector < vector < string > > PlayableBoard::getHiddenBoard() {
  return hiddenBoard;
}

void PlayableBoard::changeContent(int f, int c) {
  if (hiddenBoard.at(f).at(c) == "-") {
    int valor = board.at(f).at(c);
    if (valor == -1) {
      endGame = true;
      cout << "NT, you lose\n " <<
        name << " Watch this to get better:\n https://www.youtube.com/watch?v=dQw4w9WgXcQ\n";
    } else if (valor == 0) {
      check(f, c);
    } else {
      hiddenBoard.at(f).at(c) = to_string(valor);
      freeSquares = freeSquares - 1; //casillasLibres--;
    }
  } else {
    cout << "-> This square is already revealed or has a flag on it.\n\n";
  }
}

void PlayableBoard::check(int f, int c) {
  if (f < 0 or f >= totalRows or c < 0 or c >= totalColumns) {

  } else {
    int v = board.at(f).at(c);
    if (v == 0) {
      if (hiddenBoard.at(f).at(c) == "-") {
        hiddenBoard.at(f).at(c) = to_string(board.at(f).at(c));
        freeSquares = freeSquares - 1;
        check(f - 1, c - 1);
        check(f - 1, c);
        check(f - 1, c + 1);
        check(f, c - 1);
        check(f, c + 1);
        check(f + 1, c - 1);
        check(f + 1, c);
        check(f + 1, c + 1);
      }
    }
    if (hiddenBoard.at(f).at(c) == "-") {
      hiddenBoard.at(f).at(c) = to_string(board.at(f).at(c));
      freeSquares = freeSquares - 1;
    }

  }
}

void PlayableBoard::flag(int f, int c) {
  if (hiddenBoard.at(f).at(c) == "-") {
    hiddenBoard.at(f).at(c) = "?";
  } else {
    cout << "-> This square is already revealed or has a flag on it.\n\n";
  }
}

void PlayableBoard::removeFlag(int f, int c) {
  if (hiddenBoard.at(f).at(c) == "?") {
    hiddenBoard.at(f).at(c) = "-";
  } else {
    cout << "-> This square is already revealed or doesn't have a flag on it.\n\n";
  }

}

int PlayableBoard::menuPlay() {
  int row, column;
  int optPlay;
  try {
    cout << * this;
    cout << "\n*******CHOOSE AN OPTION*******\n\n";
    cout << "1.Reveal a square.\n"
    "2.Flag a square.\n"
    "3.Remove flag.\n"
    "4.Go to main menu.\n";
    cin >> optPlay;

    //funcion que sirve para forzar a introducir un entero.
    if(!cin)
    {
          cout << "-> Wrong Choice.\n";
          cin.clear();
          cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );
          cout<<"-> Try again: \n";
          cin>>optPlay;
    }
    switch (optPlay) {
    case 1: {
      cout << endl;
      cout << "Enter row (-) and column (|) you want to reveal:\nRow: ";
      cin >> row;
      if (row > totalRows) {
        throw string("\nNot a valid row you choose poorly.\n\n");
      }
      cout << "Column: ";
      cin >> column;
      if (column > totalColumns) {
        throw string("\nNot a valid column you choose poorly.\n\n");
      }
      cout << "\n";
      changeContent(row, column);

      if (freeSquares == 0) {
        cout << "YOU WIN " << name << " !!\n\n"
        "Share on youtube:\n"
        "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
        WonGames++;
        cout << "You have won " << WonGames << " matches.\n\n";
      }
      break;
    }
    case 2: {
      cout << endl;
      cout << "Enter row (-) and column (|) you want to put a flag on:\nRow: ";
      cin >> row;
      if (row > totalRows) {
        throw string("\nNot a valid row you choose poorly.\n\n");
      }
      cout << "Column: ";
      cin >> column;
      if (column > totalColumns) {
        throw string("\nNot a valid column you choose poorly.\n\n");
      }
      cout << "\n";
      flag(row, column);
      break;
    }
    case 3: {
      cout << endl;
      cout << "Enter row (-) and column (|) you want to remove a flag from:\nRow: ";
      cin >> row;
      if (row > totalRows) {
        throw string("\nNot a valid row you choose poorly.\n\n");
      }
      cout << "Column: ";
      cin >> column;
      if (column > totalColumns) {
        throw string("\nNot a valid column you choose poorly.\n\n");
      }
      cout << "\n";
      removeFlag(row, column);
      break;
    }
    case 4: {
      cout << "\n-> NT, " << name << " .\n\n";
      break;
    }
    default:
      cout << "-> Not a valid option choose again.\n";
      break;
    }
  } catch (string e) {
    cout << e;
  }
  return optPlay;
}

void PlayableBoard::play() {
  int optPlay;
  do {
    optPlay = menuPlay();
  } while (optPlay != 4 && !endGame && freeSquares != 0);
}
