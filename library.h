#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct College {
  string name;
  int cost;   
  int acceptance_rate;  
};

void display(const College a[], unsigned n, int summary);

int search(const College a[], unsigned n, string name, string category);

void sort_by_name(College a[], unsigned n);

void sort_by_cost(College a[], unsigned n, int summary);

void sort_by_acceptance(College a[], unsigned n);