#include <iostream>
using namespace std;
class Time
{
    int hours;
    int minutes;
    int seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int h, int m, int s)
    {

        hours = h;
        minutes = m;
        seconds = s;
    }

    void setHours(int hours)
    {
        hours = hours;
    }

    void setMinutes(int min)
    {
        minutes = minutes;
    }

    void setSeconds(int sec)
    {
        seconds = seconds;
    }

    int getHours()
    {
        return hours;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getSeconds()
    {
        return seconds;
    }

    void acceptTime()
    {
        cout << "Enter Time  " << endl;
        cout << "Hours -: ";
        cin >> hours;
        cout << "Minutes -: ";
        cin >> minutes;
        cout << "Seconds -: ";
        cin >> seconds;
    }
    void PrintTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};
int main()
{

    Time **ptr = new Time *[5];
	for(int i=0;i<5;i++)
	   ptr[i]=new Time;
	for(int i=0;i<5;i++)
	   ptr[i]->acceptTime();
	for(int i=0;i<5;i++)
	   ptr[i]->PrintTime();
	for(int i=0;i<5;i++)        
    {
        delete ptr[i];
        ptr[i] = NULL;
    }

    delete ptr;
    ptr = NULL;
    return 0;
}