#ifndef WEEK_HPP
#define WEEK_HPP

#include <string>
using namespace std;

class Week
{
  public:
    Week();
    void printWeek();

    // int getweekPointer();
    // void setweekPointer(int newLoc);
    //
    // int getdayBlockPointer();
    // void setdayBlockPointer(int newLoc);

    void emptyWeek();

    void setWeekBlockRange(string taskName, string day, string blockStart, string blockEnd);
    void setWeekBlock(string taskName, string day, string block);

    void clearWeekBlock(string day, string block);
    void clearWeekDay(string weekday);
    void clearRange(string day, string blockStart, string blockEnd);

    string getWeekBlock(int day, int block);

    void exp();

    //converting human to computer
    int weekDayStringToWeekNum(string weekString);
    int dayTimeToBlockLocation(string timeAmPm);

  private:
    //dataset
    static const int dayNum = 7;
    static const int dayBlockNum = 48;
    string weekInBlocks[dayNum][dayBlockNum];
    string timeScale[dayBlockNum + 1];
    string dayNames[dayNum];
    // char fileName[] = "myWeek.txt";


    //graphical
    void printFrameSeperator();
    void printDaySeperator();
    void printDay(int dayOfWeek);
    void printverticalLayerSscan();
    void printWeekDays();


    //utility
    // int weekPointer;
    // int dayBlockPointer;
    void constrTimeScale();
    void constrDayNames();

    void loadWeek();

    // int timeRangeTodayBlockrangeSize(string endTime, string startTime);

    void printTimeScale();
};

#endif
