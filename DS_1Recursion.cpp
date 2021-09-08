#include <iostream>
#include <iomanip>
using namespace std;
/*
Outputs to the console each step of the sequence given n as a starting point, in a formatted table.
The table shoudl have two columns:
-The count of that term
-The value of each one

Then, output wheter the sequence was aborted, and the highest value reached.
Example sequence
10, 5, 16, 8, 4, 2, 1
*/


void hailstone(int val, int curIdx, int limit, int &highest) {
    
  if (curIdx == limit + 1) {
    // -If the sequence was aborted early, report it
    cout << "Sequence was aborted early.\n"; 
    return; 
  }
  else if (val == 1) {
    cout << curIdx << setw(20) <<  val  <<endl;
    return;
  }
  else {
    int curVal = 0;
    if (val % 2) {
      curVal = ( 3 * val )+ 1;
    }
    else {
      curVal = val/2;
    }

    cout << curIdx << setw(20) << val << endl; 
    if (curVal > highest) {
        highest = curVal;
    }
    hailstone(curVal, curIdx + 1, limit, highest); //Incremental the current Idx.
  }
}

int main(){
  int n;
  int lim;

  cout << "Number:";
  cin >> n;
  
  while (n <= 1) {
    //validate input for the starting number
      cout << "Invalid number, please try again.\n";
      cout << "Number : ";
      cin >> n;
  }
 
  cout << "Limit of terms:";
  cin >> lim;
  
  while ( lim <= 1) {
    //validate input for the limit of terms
    cout << "Invalid number, please try again.\n";
    cout << "Limit of terms : ";
    cin >> lim;

  }

  cout << "Term Number         Value"<< endl;
  cout << "---------------------------"<< endl;

  //Initialize variables
  int highest  = 0, curIdx = 1;
  
  //Make a call to hailstone
  hailstone(n, curIdx, lim, highest);
  
  // -Highest number reached
  cout << "Highest number reached: " << highest << endl;
  
  return 0;
}
