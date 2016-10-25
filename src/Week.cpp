#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Week.hpp"
#include <string>

using namespace std;



Week::Week(){     //ctor
  setweekPointer(0);
  setdayBlockPointer(0);
  constrTimeScale();
  constrDayNames();
  emptyWeek();

  // printWeek();
}


void Week::printWeek(){
  printFrameSeperator();
  printWeekDays();
  printFrameSeperator();
  for (int dayBlockCount = 0; dayBlockCount < dayBlockNum; dayBlockCount++) {
    cout << setw(15) << left << timeScale[dayBlockCount + 1];
    for (int dayCount = 0; dayCount < dayNum; dayCount++) {
      cout << setw(15) << left << weekInBlocks[dayCount][dayBlockCount];
    }
    cout << endl;
  }
  printFrameSeperator();
  cout << endl;
}


int Week::getweekPointer(){
  return weekPointer;
}


void Week::setweekPointer(int newLoc){
  weekPointer = newLoc;
}


int Week::getdayBlockPointer(){
  return dayBlockPointer;
}


void Week::setdayBlockPointer(int newLoc){
  dayBlockPointer = newLoc;
}


void Week::setWeekBlock(string taskName, string day, string block){
  weekInBlocks[weekDayStringToWeekNum(day)][dayTimeToBlockLocation(block)] = taskName;
}


void Week::setWeekBlockRange(string taskName, string day, string blockStart, string blockEnd){
  int blockNumStart = dayTimeToBlockLocation(blockStart);
  int blockNumEnd = dayTimeToBlockLocation(blockEnd);
  for(int blockCounter = blockNumStart; blockCounter < blockNumEnd; blockCounter++){
    weekInBlocks[weekDayStringToWeekNum(day)][blockCounter] = taskName;
  }
}


string Week::getWeekBlock(int day, int block){
  return weekInBlocks[day][block];
}


void Week::printDay(int dayOfWeek){
  printFrameSeperator();
  cout << setw(15) << left << dayNames[dayOfWeek] << endl;
  for (int dayBlockCount = 0; dayBlockCount < dayBlockNum; dayBlockCount++) {
    cout << getWeekBlock(dayOfWeek, dayBlockCount) << endl;
  }
  printFrameSeperator();
}


void Week::constrDayNames(){
  dayNames[0] = "monday";
  dayNames[1] = "tuesday";
  dayNames[2] = "wednesday";
  dayNames[3] = "thursday";
  dayNames[4] = "friday";
  dayNames[5] = "saturday";
  dayNames[6] = "sunday";
}


void Week::constrTimeScale(){
  timeScale[0] = "timeTitle";//when working, change counter i to 1 and uncomment this line
  // for(int i = 1; i < (dayBlockNum + 1); i++){
  //   timeScale[i] = "timeScale";
  //   // cout << timeScale[dayBlockNum] << endl;
  // }
  timeScale[1] = "00:00";
  timeScale[2] = "00:30";
  timeScale[3] = "01:00";
  timeScale[4] = "01:30";
  timeScale[5] = "02:00";
  timeScale[6] = "02:30";
  timeScale[7] = "03:00";
  timeScale[8] = "03:30";
  timeScale[9] = "04:00";
  timeScale[10] = "04:30";
  timeScale[11] = "05:00";
  timeScale[12] = "05:30";
  timeScale[13] = "06:00";
  timeScale[14] = "06:30";
  timeScale[15] = "07:00";
  timeScale[16] = "07:30";
  timeScale[17] = "08:00";
  timeScale[18] = "08:30";
  timeScale[19] = "09:00";
  timeScale[20] = "09:30";
  timeScale[21] = "10:00";
  timeScale[22] = "10:30";
  timeScale[23] = "11:00";
  timeScale[24] = "11:30";
  timeScale[25] = "12:00";
  timeScale[26] = "12:30";
  timeScale[27] = "13:00";
  timeScale[28] = "13:30";
  timeScale[29] = "14:00";
  timeScale[30] = "14:30";
  timeScale[31] = "15:00";
  timeScale[32] = "15:30";
  timeScale[33] = "16:00";
  timeScale[34] = "16:30";
  timeScale[35] = "17:00";
  timeScale[36] = "17:30";
  timeScale[37] = "18:00";
  timeScale[38] = "18:30";
  timeScale[39] = "19:00";
  timeScale[40] = "19:30";
  timeScale[41] = "20:00";
  timeScale[42] = "20:30";
  timeScale[43] = "21:00";
  timeScale[44] = "21:30";
  timeScale[45] = "22:00";
  timeScale[46] = "22:30";
  timeScale[47] = "23:00";
  timeScale[48] = "23:30";
}


void Week::printFrameSeperator(){
  for (int i = 0; i < (dayNum + 1); i++) {
    cout << "===============";
  }
  cout << endl;
}


void Week::printWeekDays(){
  cout << setw(15) << left << timeScale[0];
  for (int dayCount = 0; dayCount < dayNum; dayCount++) {
    cout << setw(15) << left << dayNames[dayCount];
  }
  cout << endl;
}


void Week::emptyWeek(){
  for (int day = 0; day < dayNum; day++) {
    for (int blockNum = 0; blockNum < dayBlockNum; blockNum++) {
      weekInBlocks[day][blockNum] = " ";
      // setWeekBlock("null", day, blockNum);
    }
  }
}


void Week::printTimeScale(){
  for(int i = 0; i < (dayBlockNum + 1); i++){
    cout << timeScale[i] << endl;
  }
}


int Week::weekDayStringToWeekNum(string weekString){
  if(weekString.compare("monday") == 0)return 0;
  else if(weekString.compare("tuesday") == 0)return 1;
  else if(weekString.compare("wednesday") == 0)return 2;
  else if(weekString.compare("thursday") == 0)return 3;
  else if(weekString.compare("friday") == 0)return 4;
  else if(weekString.compare("saturday") == 0)return 5;
  else if(weekString.compare("sunday") == 0)return 6;
  else{
    cout << "error, day unknown\n";
    cout << weekString << endl;
    exit(-1);
  }
}


int Week::dayTimeToBlockLocation(string timeAmPm){
  if(timeAmPm.compare("00:00") == 0)return 0;
  else if(timeAmPm.compare("00:30") == 0)return 1;
  else if(timeAmPm.compare("01:00") == 0)return 2;
  else if(timeAmPm.compare("01:30") == 0)return 3;
  else if(timeAmPm.compare("02:00") == 0)return 4;
  else if(timeAmPm.compare("02:30") == 0)return 5;
  else if(timeAmPm.compare("03:00") == 0)return 6;
  else if(timeAmPm.compare("03:30") == 0)return 7;
  else if(timeAmPm.compare("04:00") == 0)return 8;
  else if(timeAmPm.compare("04:30") == 0)return 9;
  else if(timeAmPm.compare("05:00") == 0)return 10;
  else if(timeAmPm.compare("05:30") == 0)return 11;
  else if(timeAmPm.compare("06:00") == 0)return 12;
  else if(timeAmPm.compare("06:30") == 0)return 13;
  else if(timeAmPm.compare("07:00") == 0)return 14;
  else if(timeAmPm.compare("07:30") == 0)return 15;
  else if(timeAmPm.compare("08:00") == 0)return 16;
  else if(timeAmPm.compare("08:30") == 0)return 17;
  else if(timeAmPm.compare("09:00") == 0)return 18;
  else if(timeAmPm.compare("09:30") == 0)return 19;
  else if(timeAmPm.compare("10:00") == 0)return 20;
  else if(timeAmPm.compare("10:30") == 0)return 21;
  else if(timeAmPm.compare("11:00") == 0)return 22;
  else if(timeAmPm.compare("11:30") == 0)return 23;
  else if(timeAmPm.compare("12:00") == 0)return 24;
  else if(timeAmPm.compare("12:30") == 0)return 25;
  else if(timeAmPm.compare("13:00") == 0)return 26;
  else if(timeAmPm.compare("13:30") == 0)return 27;
  else if(timeAmPm.compare("14:00") == 0)return 28;
  else if(timeAmPm.compare("14:30") == 0)return 29;
  else if(timeAmPm.compare("15:00") == 0)return 30;
  else if(timeAmPm.compare("15:30") == 0)return 31;
  else if(timeAmPm.compare("16:00") == 0)return 32;
  else if(timeAmPm.compare("16:30") == 0)return 33;
  else if(timeAmPm.compare("17:00") == 0)return 34;
  else if(timeAmPm.compare("17:30") == 0)return 35;
  else if(timeAmPm.compare("18:00") == 0)return 36;
  else if(timeAmPm.compare("18:30") == 0)return 37;
  else if(timeAmPm.compare("19:00") == 0)return 38;
  else if(timeAmPm.compare("19:30") == 0)return 39;
  else if(timeAmPm.compare("20:00") == 0)return 40;
  else if(timeAmPm.compare("20:30") == 0)return 41;
  else if(timeAmPm.compare("21:00") == 0)return 42;
  else if(timeAmPm.compare("21:30") == 0)return 43;
  else if(timeAmPm.compare("22:00") == 0)return 44;
  else if(timeAmPm.compare("22:30") == 0)return 45;
  else if(timeAmPm.compare("23:00") == 0)return 46;
  else if(timeAmPm.compare("23:30") == 0)return 47;
  else {
    cout << "error, time unknown\n";
    cout << timeAmPm << endl;
    exit(-1);
  }
}
