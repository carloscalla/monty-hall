#include <ctime>
#include <iostream>

using namespace std;

int main() {

  srand(static_cast<unsigned int>(time(nullptr)));

  int runs, wins = 0, loses = 0;
  int i;
  cout << "Enter the number of runs: ";
  cin >> runs;

  for (i = 0; i < runs; i++) {
    /* 1 - can switch */
    /* 0 - can't switch */

    int doors[3] = {1, 1, 1}, prize, choice;
    int j, k;

    prize = rand() % 3;
    choice = rand() % 3;
    doors[choice] = 0;

    for (j = 0; j < 3; j++) {
      if (j != prize && j != choice) {
        /* bluff */
        doors[j] = 0;
        break;
      }
    }

    for (k = 0; k < 3; k++) {
      if (doors[k] == 1) {
        if (k == prize) {
          wins++;
        } else {
          loses++;
        }
        break;
      }
    }
  }

  cout << "wins: " << wins << endl;
  cout << "loses: " << loses << endl;

  return 0;
}

/**
 * Assuming we always switch our initial choice:
 * After running and printing multiple times, we can visualize
 * that if we initially choose the door with the prize, we will lose.
 * However, if we initially choose either one of the 2 without the prize, we
 * will win. This leave us with 1/3 chance of loosing and 2/3 chance of winning
 *
 * The simulation can be reduced to this statement:
 * (prize == choice) ? loses++ : wins++;
 */
