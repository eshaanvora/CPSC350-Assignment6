//Eshaan Vora
//2318955
//evora@chapman.edu
//CPSC 350-02
//Assignment 6

#include <iostream>
using namespace std;

class Sort{

public:
  int Partition(double numbers[], int lowIndex, int highIndex);
  void QuickSort(double numbers[], int lowIndex, int highIndex);

  void Merge(double numbers[], int i, int j, int k);
  void MergeSort(double numbers[], int i, int k);

  void SelectionSort(double numbers[], int numSize);
  void InsertionSort(double numbers[], int numSize);
  void BubbleSort(double numbers[], int numSize);
};
