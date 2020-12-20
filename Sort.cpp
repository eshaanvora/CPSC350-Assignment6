//Eshaan Vora
//2318955
//evora@chapman.edu
//CPSC 350-02
//Assignment 6

#include "Sort.h"
#include <iostream>

using namespace std;

int Sort::Partition(double numbers[], int lowIndex, int highIndex){

  //Pick middle element as pivot
  int midpoint = lowIndex + (highIndex - lowIndex) / 2;
  int pivot = numbers[midpoint];

  bool done = false;
  while (!done){
    //Increment lowIndex while numbers[lowIndex] < pivot
    while (numbers[lowIndex] < pivot){
      lowIndex += 1;
    }
    //Decrement highIndex while pivot < numbers[highIndex]
    while (pivot < numbers[highIndex]){
      highIndex -= 1;
    }
    // If zero or one elements remain, then all numbers are partitioned. Return highIndex.
    if (lowIndex >= highIndex){
      done = true;
    }else{
      //Swap numbers[lowIndex] and numbers[highIndex]
      int temp = numbers[lowIndex];
      numbers[lowIndex] = numbers[highIndex];
      numbers[highIndex] = temp;

      //Update lowIndex and highIndex
      lowIndex += 1;
      highIndex -= 1;
    }
  }
  return highIndex;
}

void Sort::QuickSort(double numbers[], int lowIndex, int highIndex){
  if (!(lowIndex >= highIndex)){
    int lowEndIndex = Partition(numbers, lowIndex, highIndex);

    QuickSort(numbers, lowIndex, lowEndIndex);
    QuickSort(numbers, lowEndIndex + 1, highIndex);
  }
}

void Sort::Merge(double numbers[], int i, int j, int k){

  int mergedSize = k - i + 1;
  int mergePos = 0;
  int leftPos = 0;
  int rightPos = 0;
  int *mergedNumbers;
  mergedNumbers = new int[mergedSize];

  // Initialize left/right partition position
  leftPos = i;
  rightPos = j + 1;

  //Add smallest element from left or right partition to merged numbers
  while (leftPos <= j && rightPos <= k){
    if (numbers[leftPos] <= numbers[rightPos]) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
    }else{
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
    }
    ++mergePos;
  }
  // If left partition is not empty, add remaining elements to merged numbers
  while (leftPos <= j){
    mergedNumbers[mergePos] = numbers[leftPos];
    ++leftPos;
    ++mergePos;
  }
  // If right partition is not empty, add remaining elements to merged numbers
  while (rightPos <= k){
    mergedNumbers[mergePos] = numbers[rightPos];
    ++rightPos;
    ++mergePos;
  }
  // Copy merge number back to numbers
  for (mergePos = 0; mergePos < mergedSize; ++mergePos){
   numbers[i + mergePos] = mergedNumbers[mergePos];
 }
}

void Sort::MergeSort(double numbers[], int i, int k){
  int j = 0;

  if (i < k){
    j = (i + k) / 2; //Find the midpoint in the partition

    //Recursively sort left and right partitions
    MergeSort(numbers, i, j);
    MergeSort(numbers, j+1, k);

    // Merge left and right partition in sorted order
    Merge(numbers, i, j, k);
  }
}

void Sort::SelectionSort(double numbers[], int numSize){
  int i = 0;
  int j = 0;
  int indexSmallest = 0;
  int temp = 0; //Temporary variable for swap

  for (i = 0; i < numSize - 1; ++i){
    //Find index of smallest remaining element
    indexSmallest = i;
    for (j = 1; j < numSize; ++j){
      if (numbers[j] < numbers[indexSmallest]){
        indexSmallest = j;
      }
    }
    //Swap numbers[i] and numbers[indexSmallest]
    temp = numbers[i];
    numbers[i] = numbers[indexSmallest];
    numbers[indexSmallest] = temp;
  }
}

void Sort::InsertionSort(double numbers[], int numSize){
  int i = 0;
  int j = 0;
  int temp = 0;

  for (i = 0; i < numSize; ++i){
    j = 1;
    // Insert numbers[i] into sorted part, stopping once numbers[i] is in correct position
    while (j > 0 && numbers[j] < numbers[j-1]){
      // Swap numbers[j] and numbers[j - 1]
      temp = numbers[j];
      numbers[j] = numbers[j-1];
      numbers[j-1] = temp;
      --j;
    }
  }
}

void Sort::BubbleSort(double numbers[], int numSize){
  int i = 0;
  int j = 0;
  int temp = 0;
  for (i = 0; i < numSize - 1; i++){
    for (j = 0; j < numSize - i - 1; j++){
      if (numbers[j] > numbers[j+1]){
        temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
}
