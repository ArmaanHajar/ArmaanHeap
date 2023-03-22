/*
 * Author: Armaan Hajar
 * Date: 3/4/2023
 * Program: A max heap data stucture, meaning that the parent is always larger than its children
 */

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void print(int* heap, int location, int space);
void heapSort(int* heap, int heapCount);

int main() {
  // intializing heap variables
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
      if (heapCount >= 100) { // checks if heap is full
        cout << "Heap is Full!" << endl;
      }
      else { // adds number to heap
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

      if (heapCount > 100) { // checks if heap is full
        break;
        cout << "Heap is Full!" << endl;
      }
      for (int i = heapCount; i < 20; i++) { // adds numbers from file to heap
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
      if (heapCount == 0) { // checks if heap is empty
        cout << "Heap is Empty!" << endl;
      }
      else { // prints heap if not empty
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
        if (heapCount == 0) { // checks if heap is empty
          cout << "Heap is Empty!" << endl;
        }
        else { // deletes root if heap is not empty
          cout << "Deleted: " << heap[0] << endl;
          for (int i = 0; i < heapCount; i++) {
            heap[i] = heap[i + 1];
          }
          heapCount--;
          heapSort(heap, heapCount);
        }
      }
      else if (tempInput[0] == 'W' || tempInput[0] == 'w') { // deletes whole list
        cout << "Deleted: ";
        for (int i = 0; i < heapCount; i++) {
          cout << heap[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < 100; i++) { // sets all values in heap to 0
          heap[i] = 0;
        }
        heapCount = 0;
      }
      else {
        cout << "Not Sure What You're Trying to Do" << endl;
      }
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Heap Maker!" << endl;
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

// sorting so that a parent is not smaller than it's children 
void heapSort(int* heap, int heapCount) {
  for (int current = 0; current < heapCount - 1; current++) { // goes through each element in heap
    for (int next = current + 1; next < heapCount; next++) { // goes through each element after current
      if (heap[current] < heap[next]) { // swaps if parent is smaller than child
        int temp = heap[current];
        heap[current] = heap[next];
        heap[next] = temp;
      }
    }
  }
}


void print(int* heap, int temp, int indent) { // prints heap
  if (heap[temp] == 0) { // checks if heap is empty
    return;
  }
  indent += 10; // adds 10 spaces to indent
  print(heap, temp * 2 + 1, indent); // goes to left child
  cout << "\n" << endl; // prints new line
  for (int i = 10; i < indent; i++) { // prints spaces
    cout << " ";
  }
  cout << heap[temp] << "\n"; // prints value
  print(heap, temp * 2 + 2, indent); // goes to right child
}