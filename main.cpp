//Eshaan Vora
//2318955
//evora@chapman.edu
//CPSC 350-02
//Assignment 6

#include <iostream>
#include <ctime>
#include <fstream>
#include "Sort.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Sort x;

  //Store file name from command-line argument
  string fileName = argv[1];

  ifstream infile(fileName);

  int line;
  //First line of the text file is the number of elements to sort
  infile >> line;

  //Initialize arrays for each sorting algorithm
  double quickSortArray[line];
  double mergeSortArray[line];
  double selectionSortArray[line];
  double insertionSortArray[line];
  double bubbleSortArray[line];

  clock_t start;
  clock_t end;

  double totalTime;
  double num;

  //Store numbers from file to arrays
  for (int i = 0; i < line; ++i){
    infile >> num;
    quickSortArray[i] = num;
    mergeSortArray[i] = num;
    selectionSortArray[i] = num;
    insertionSortArray[i] = num;
    bubbleSortArray[i] = num;
  }

  //QuickSort
  start = clock();
  x.QuickSort(quickSortArray, 0, line - 1);
  end = clock();

  //Divide clock tick count by "CLOCKS_PER_SEC" to get number of seconds
  //Covert time to milliseconds
  totalTime = double(end - start) / CLOCKS_PER_SEC * 1000;

  cout << "QUICK SORT" << endl;
  cout << "Start: " << start << endl;
  cout << "End: " << end << endl;
  cout << "Total time: " << totalTime << " milliseconds\n" << endl;

  //MergeSort
  start = clock();
  x.MergeSort(mergeSortArray, 0, line - 1);
  end = clock();
  totalTime = double(end - start) / CLOCKS_PER_SEC * 1000;

  cout << "MERGE SORT" << endl;
  cout << "Start: " << start << endl;
  cout << "End: " << end << endl;
  cout << "Total time: " << totalTime << " milliseconds\n" << endl;

  //SelectionSort
  start = clock();
  x.SelectionSort(selectionSortArray, line);
  end = clock();
  totalTime = double(end - start) / CLOCKS_PER_SEC * 1000;

  cout << "SELECTION SORT" << endl;
  cout << "Start: " << start << endl;
  cout << "End: " << end << endl;
  cout << "Total time: " << totalTime << " milliseconds\n" << endl;

  //InsertionSort
  start = clock();
  x.InsertionSort(insertionSortArray, line);
  end = clock();
  totalTime = double(end - start) / CLOCKS_PER_SEC * 1000;

  cout << "INSERTION SORT" << endl;
  cout << "Start: " << start << endl;
  cout << "End: " << end << endl;
  cout << "Total time: " << totalTime << " milliseconds\n" << endl;

  //BubbleSort
  start = clock();
  x.BubbleSort(bubbleSortArray, line);
  end = clock();
  totalTime = double(end - start) / CLOCKS_PER_SEC * 1000;

  cout << "BUBBLE SORT" << endl;
  cout << "Start: " << start << endl;
  cout << "End: " << end << endl;
  cout << "Total time: " << totalTime << " milliseconds" << endl;

  return 0;
}
