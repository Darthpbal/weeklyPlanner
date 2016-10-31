/*
todo

fix loading function. If there are large numbers of empty cells, commas are interpretted as a task

add a setter function for one task for multiple days and a range


add ability for the week frame size to scale based on screen size. Currently only sized for my GIR laptop. (this may mean that there might have to be a new scheme for storing/displaying the weekblocks. Could get complex!)

add A function for counting how many cells are a certain task in a day for returning number of hours spent on the task that day. This can be then expanded for every day of the week in total.

If successful with function conting elements, maybe create a part of the display showing whether or not the time for this task has met some given threshold. Like 3 hrs homework for each hour of lecture. you ask the system how many lecture hours, it returns a float, and then the user sets a threshold for a specific label which is updated every time an action is done on the week. This could get complex, but I feel like if I'm careful, I can conserve a lot of code. I think I'd need to create member functions specifically for cleanly prompting users for inputs like day and time and then create a better tolerance for typos and simplify the controls...... sounds like fun.
add Html reporting? Do I care? add fancy style shiz like bootstrap to the html report?


Use the ostream class type as a function argument to save typing on the save file function and just pass cout or an ofstream to the print functions. (remember to pass by refernce, no need to create uneccesary memory stuffs)
This would essencially allow me to abstract out the "cout" part of any functions I might also want the same behavior with a file. This works because the "<<" and ">>" operators somehow belong to a root "stream" class that is used within many other classes like fstream (for text file manipulations),  streamstream (for manipulating strings like a stream), and iostream (like cout and cin).
In this way, both iostream and fstream are said to "inherit" the properties of a root class called ostream.
Aside from ostream being a more "root" parent layer of iostream and ofstream, I do not understand it's functional differences from iostream aside from maybe having different member functions
This should result in much less code being used for outputting text and file writing combined. This advantage is made because the file writingg is being done exactly the same way as the main display, so I'm repeating a ton of code to just write to a text file. So this should reduce that related code by half.
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
      else if(option == "clearweek"){
        myWeek.emptyWeek();
        continue;
      }
      else if(option == "export"){
        myWeek.exp();
        continue;
      }
      else if(option == "save"){
        myWeek.save();
        continue;
      }
      else if(option == "load"){
        myWeek.load();
        continue;
      }
      else if(option == "clearblock"){
        cout << "what day?\n";
        cin >> day;
        cout << "what time?\n";
        cin >> timeStart;
        myWeek.clearWeekBlock(day, timeStart);
        continue;
      }
      else if(option == "clearday"){
        cout << "what day?\n";
        cin >> day;
        myWeek.clearWeekDay(day);
        continue;
      }
      else if(option == "clearrange"){
        cout << "what day?\n";
        cin >> day;
        cout << "start time?\n";
        cin >> timeStart;
        cout << "end time?\n";
        cin >> timeEnd;
        myWeek.clearRange(day, timeStart, timeEnd);
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
