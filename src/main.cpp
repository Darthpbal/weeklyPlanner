#include <iostream>
#include <string>
#include "Week.hpp"
using namespace std;

int main(){
    cout << "Hello World\n";

    Week myWeek;
    string option, day, tim;
    while(option != "exit"){
      myWeek.printWeek();
      cout << "what should I do?\n";
      cin >> option;
      cout << "what day??\n";
      cin >> day;
      cout << "what time?\n";
      cin >> tim;
      myWeek.setWeekBlock(option, day, tim);
      if(option == "clear") myWeek.emptyWeek();
    }

  return 0;
}
