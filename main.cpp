// This program shall analyze the cost and acceptance rate of top Computer Science colleges across California.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "library.h"
using namespace std;


int main() {
  int capacity = 100000;
  College college[capacity]; 
  ifstream file_reader;
  unsigned n = 0;
  int selection = 0;
  string college_name;
  string rate_cost;
  int summary = 0;
  
  file_reader.open("california.csv");
  
  do{
    getline(file_reader, college[n].name, ',');
    file_reader >> college[n].cost;
    file_reader.ignore();
    file_reader >> college[n].acceptance_rate;
    file_reader.ignore();
    n++;
    }
  while(!file_reader.eof());

  display(college, n, 0);
do{
  cout << "Would you like to \n1. Search\n2. Sort by Name\n3. Sort by Cost\n4. Sort by Admissions Rate" << endl;
  cin >> selection;
  switch(selection){
    case 1:
      cout << "What is the college you would like to search?" << endl;
      cin.ignore();
      getline(cin, college_name);
      cout << "Would you like to see the acceptance rate or cost? (rate/cost)" << endl;
      getline(cin, rate_cost);
      if (rate_cost == "rate"){
      cout << "The acceptance rate of the " << college_name << " is " << search(college, n, college_name, rate_cost) << "%" << endl;
      }
      else if (rate_cost == "cost"){
      cout << "The cost of " << college_name << " is $" << search(college, n, college_name, rate_cost) << endl;
      }
      else {
        search(college, n, college_name, rate_cost);
      }
      break;
    case 2:
      sort_by_name(college, n);
      break;
    case 3:
      sort_by_cost(college, n, summary);
      break;
    case 4:
      sort_by_acceptance(college, n);
      break;
    }
  } while(selection!= 1 && selection!= 2 && selection!= 3 && selection!= 4);
  return 0;
}