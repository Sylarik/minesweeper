//Hecho por Sara Garcia y Guillermo Martinez de Hurtado

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "board.h"
#include "playableboard.h"

using namespace std;

int menu(string name) {
  cout << "*******MINESWEEPER*******\n\n";
  cout << "1.Easy mode.\n"
  "2.Hard mode.\n"
  "3.END PROGRAM.\n";

  int opt;
  cin >> opt;
  //funcion que sirve para forzar a introducir un entero.
  if(!cin)
  {
        cout << "-> Wrong Choice.\n";
        cin.clear();
        cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );
        opt++;
  }
  cout<<"-> You will automatically play easy mode.\n";

  switch (opt) {
  case 1: {
    PlayableBoard t1(6, 6, 5);
    t1.setName(name);
    t1.play();
    break;
  }
  case 2: {
    PlayableBoard t2(9, 9, 10);
    t2.setName(name);
    t2.play();
    break;
  }
  case 3: {
    cout << "See you soon.\n\n";
    break;
  }
  default:
    cout << "Not a valid option choose again.\n\n";
    break;
  }

  return opt;
}

int main() {

  string name;
  cout << "**************** LET'S PLAY ****************\n-> What is your name?\n";
  cin >> name;
  cout << "\n";

  int opt;

  do {
    opt = menu(name);
  } while (opt != 3);

  return 0;
}
