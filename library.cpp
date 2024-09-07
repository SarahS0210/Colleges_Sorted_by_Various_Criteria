#include "library.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// You shall implement the display, search, sort_by_name, sort_by_cost,
// sort_by_acceptance functions here

void display(const College a[], unsigned n, int summary) {
  //display highest and lowest costs
  int average = 0;
  cout << "College";
  cout << right << setw(45) << "Cost";
  cout << right << setw(10) << "Rate" << endl;
  cout << "==============================================================" << endl;
  for (int i = 0; i < n; i++) {
    cout << left << setw(38) << a[i].name;
    cout << right << setw(10) << "$" << a[i].cost;
    cout << right << setw(8) << a[i].acceptance_rate << "%" << endl;
  }
  cout << "==============================================================" << endl;
  if (summary == 1){
    for (int i = 0; i<n; i++){
      average = average + a[i].cost;
    }
  average = average/n;
  cout << "The most expensive university is: " << a[0].name << endl;
  cout << "The least expensive university is: " << a[n-1].name << endl;
  cout << "The average cost of all the univerities is: $" << fixed << setprecision(2) << double (average);
  }
}


int search(const College a[], unsigned n, string name, string category) {
  int summary;
  int return_value = 0;
  for (int i=0; i<n; i++){
    if(name == a[i].name){
      if (category == "rate"){
        return_value = a[i].acceptance_rate;
      }
      else if(category == "cost"){
        return_value = a[i].cost;
      }
      else{
				// We wanted you to just use the return value to determine if these
				// messages should be displayed in the main, not here in the search.
        cout << "please enter cost or rate" << endl;
        }
      }
    }
  if (name != a[0].name && name != a[1].name && name != a[2].name && name != a[3].name && name != a[4].name && name != a[5].name) {
      cout << "nonexistent. The university inputted was invalid, please try again" << endl;
      return -2;
  }
   summary = 0;
  return return_value;
}

//Bubble Sort
void sort_by_name(College a[], unsigned n) {
  bool swapped;
  do {
    swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1].name < a[i].name) {
        swap(a[i], a[i + 1]);
        swapped = true;
      }
    }
  } while (swapped);
  int summary = 0;
  display(a, n, summary);
}

//Insertion Sort
void sort_by_cost(College a[], unsigned n, int summary) {
      for (int i = 1; i < n; i++) {
        for (int e = i-1; e>-1; e--){
          if (a[e + 1].cost > a[e].cost) {
            swap(a[e], a[e + 1]);
          }
        }
      }
    summary = 1;
    display(a, n, summary);
  }

//Selection Sort
void sort_by_acceptance(College a[], unsigned n) {
    int min = 0;
  for(int e = 0; e < n-1; e++){
      min = e;
      for (int i = e + 1; i < n; i++) {
        if (a[min].acceptance_rate > a[i].acceptance_rate) {
          min = i;
        }
        swap(a[e], a[min]);
      }
    }
  int summary = 0;
    display(a, n, summary);
  }