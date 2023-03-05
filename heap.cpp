/*
 * Author: Armaan Hajar
 * Date:
 * Program: A heap data stucture
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

void print(int* heap, int location, int space);
void heapSort(int* heap, int heapCount);

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
    else if (input[0] == 'G' || input[0] == 'g') { // generates random numbers from numbers.txt file
      ifstream numbers;
      numbers.open("numbers.txt");
      int count = 0;

      if (heapCount > 100) {
        break;
        cout << "Heap is Full!" << endl;
      }
      for (int i = heapCount; i < 20; i++) {
        if (heapCount > 100) {
          break;
          cout << "Heap is Full!" << endl;
        }
        else {
          numbers >> heap[i];
          heapCount++;
        }
      }
      numbers.close();
      heapSort(heap, heapCount);
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints all students inputted
      if (heapCount == 0) {
        cout << "Heap is Empty!" << endl;
      }
      else {
        cout << "Heap: " << endl;
        print(heap, 0, 0);
      }
    }
    else if (input[0] == 'D' || input[0] == 'd') { // either deletes root or deletes whole list
      char tempInput[10];
      cout << "Do You Want To Delete The Root Or The Whole List? (ROOT/WHOLE)" << endl;
      cin.get(tempInput, 10);
      cin.ignore(1, '\n');

      if (tempInput[0] == 'R' || tempInput[0] == 'r') { // deletes root
        if (heapCount == 0) {
          cout << "Heap is Empty!" << endl;
        }
        else {
          cout << "Deleted: " << heap[0] << endl;
          for (int i = 0; i < heapCount; i++) {
            heap[i] = heap[i + 1];
          }
          heapCount--;
          heapSort(heap, heapCount);
        }
      }
      else if (tempInput[0] == 'W' || tempInput[0] == 'w') { // deletes whole list
        for (int i = 0; i < 100; i++) {
          heap[i] = 0;
        }
        heapCount = 0;
      }
      else {
        cout << "Not Sure What You're Trying to Do" << endl;
      }
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
      cout << "Heap Count: " << heapCount << endl;
    }
    else {
      cout << "Not Sure What You're Trying to Do" << endl;
    }
  }  
  return 0;
}

// sorting so that a parent is not smaller than it's children 
void heapSort(int* heap, int heapCount) {
  for (int current = 0; current < heapCount - 1; current++) {
    for (int next = current + 1; next < heapCount; next++) {
      if (heap[current] < heap[next]) {
        int temp = heap[current];
        heap[current] = heap[next];
        heap[next] = temp;
      }
    }
  }
}


void print(int* heap, int location, int space){
  if (heap[location] == 0){
    return;
  }
  space += 10;

  print(heap, location * 2 + 1, space);

  cout << "\n" <<endl;
  for (int i = 10; i < space; i++) {
    cout << " ";
  }
  cout << heap[location] << "\n";
  print(heap, location * 2 + 2, space);
}