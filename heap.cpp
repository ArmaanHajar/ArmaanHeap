/*
 * Author: Armaan Hajar
 * Date:
 * Program: A heap data stucture
 */

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void print(int* heap, int location, int space);
void heapSort(int heap[], int heapCount);

// right child: index * 2 + 1
// left child: index * 2
// parent: floor(index / 2)
/*
heap[heapCount] = inputNum;
int parent = floor(heapCount / 2);
if (heap[heapCount] > heap[parent]) {
  int temp = heap[heapCount];
  heap[heapCount] = heap[parent];
  heap[parent] = temp;
}
*/

int main() {
  int heapCount = 0;
  int* heap = new int[100];
  for(int i = 0; i<100; i++){
    heap[i] = 0;
  }

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
      bool done = false;
      if (heapCount >= 100) {
        cout << "Heap is Full!" << endl;
      }
      else {
        cout << "Begin Inputting Numbers Between 1-1000, Type '0' When Done" << endl;
        while (done == false) {
          cin >> inputNum;
          cin.ignore(1, '\n');
          if (inputNum >= 1 && inputNum <= 1000) {
            heap[heapCount] = inputNum;
            heapCount++;
          }
          else if (inputNum == 0) {
            done = true;
            cout << "Done Inputting Numbers" << endl;
            heapSort(heap, heapCount);
          }
          else {
            cout << "Invalid Input" << endl;
          }
        }
      }
    }
    else if (input[0] == 'G' || input[0] == 'g') { // generates random numbers
      
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      print(heap, 0, 0);
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

void heapSort(int heap[], int heapCount) {
  for (int i = 0; i <= heapCount; i++) {
    int parent = floor(heap[i] / 2);
    int child = heapCount;
    if (heap[child] > heap[parent]) {
      int temp = heap[child];
      heap[child] = heap[parent];
      heap[parent] = temp;
    }
  }
}

void print(int* heap, int location, int space){
  if (heap[location] == 0){
    return;
  }
  space += 10;

  print(heap, location * 2, space);

  cout << "\n" <<endl;
  for (int i = 10; i < space; i++){
    cout << " ";
  }
  cout << heap[location] << "\n";
  print(heap, location * 2, space);
}