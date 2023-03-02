/*
 * Author: Armaan Hajar
 * Date:
 * Program: A heap data stucture
 */

#include <iostream>
#include <cmath>

using namespace std;

// right child: index * 2 + 1
// left child: index * 2
// parent: floor(index / 2)

int main() {
  int heap[100];
  int index = 1;
  heap[0] = NULL;
  heap[index] = 100;
  index++;

  char input[10];
  bool running = true;

  // main code, running will stay true until user says "QUIT"
  while (running == true) {
    cout << "---------------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/GENERATE/PRINT/DELETE/QUIT/HELP)" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (input[1] == 'D' || input[1] == 'd') { // adds number
      int inputNum;
      cout << "Begin Inputting Numbers Between 1-1000. When Done, Type 0" << endl;
      while (inputNum != 0) {
      if (inputNum != 0 && inputNum >= 1 && inputNum <= 1000) {
        cin >> inputNum;
        cin.ignore(1, '\n');
        heap[index] = inputNum;
        int parent = floor(index / 2);
        if (heap[index] > heap[parent]) {
          int temp = heap[index];
          heap[index] = heap[parent];
          heap[parent] = temp;
        }
        index++
      }
      else (inputNum < 1 || inputNum > 1000) {
        cout << "Invalid Number" << endl;
      }
      else if (inputNum == 0) {
        cout << "Done Inputting Numbers" << endl;
        break;
      }
      }
    }
    else if (input[0] == 'G' || input[0] == 'g') { // generates random numbers
      
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      
    }
    else if (input[2] == 'L' || input[2] == 'l') { // deletes a number
      
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else if (input[0] == 'H' || input[0] == 'h') { // prints help message
      cout << "Type \"ADD\" To Enter A New Student" << endl;
      cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
      cout << "Type \"DELETE\" To Delete A Student" << endl;
      cout << "Type \"QUIT\" To End Program" << endl;
    }
    else {
      cout << "Not Sure What You're Trying to Do" << endl;
    }
  }  
  return 0;
}
