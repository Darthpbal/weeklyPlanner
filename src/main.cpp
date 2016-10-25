#include <iostream>
#include <string>
#include <cstdlib>
#include "Week.hpp"
using namespace std;

int main(){
    cout << "Hello World\n";

    Week myWeek;
    string option, task, day, timeStart, timeEnd;
    while(option != "exit"){
      myWeek.printWeek();
      cout << "what should I do?\n";
      cin >> option;
      if(option == "exit") exit(0);

      cout << "What is the task to do?\n";
      cin >> task;

      if(option == "clear") myWeek.emptyWeek();

      else if(option == "setblock"){
        cout << "what day?\n";
        cin >> day;
        cout << "what time?\n";
        cin >> timeStart;
        myWeek.setWeekBlock(task, day, timeStart);
      }

      else if(option == "setrange"){
        cout << "what day?\n";
        cin >> day;
        cout << "start time?\n";
        cin >> timeStart;
        cout << "end time?\n";
        cin >> timeEnd;
        myWeek.setWeekBlockRange(task, day, timeStart, timeEnd);
      }
    }

  return 0;
}
