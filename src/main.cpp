/*
todo
add textfile based load functions
add html reporting
add fancy style shiz to the html report

use the ostream class type as a function argument to save typing on the save file
function and just pass cout or an fstream to the print functions. (remember to pas by refernce)
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "Week.hpp"
using namespace std;

int main(){
    cout << "Hello World\noptions are \n\"exit\" \n\"setblock\" \n\"setrange\"\n";
    Week myWeek;
    string option, task, day, timeStart, timeEnd;
    while(option != "exit"){
      myWeek.printWeek();
      cout << "what should I do?\n";
      cin >> option;

      if(option == "exit") exit(0);
      else if(option == "clear"){
        myWeek.emptyWeek();
        continue;
      }
      else if(option == "save"){
        myWeek.saveWeek();
        continue;
      }


      cout << "What is the task to do?\n";
      cin >> task;


      if(option == "setblock"){
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
