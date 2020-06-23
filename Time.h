//
// Created by Gunjan Joshi on 11/29/19.
//

#ifndef TIME_CLASS_H
#define TIME_CLASS_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Time {
public:
	Time();
	Time(int hour, int min) throw (logic_error);
	static int elapsedMin(Time t1, Time t2);
	string toString();

private:
	int hour;
	int min;
};

#endif //TIME_CLASS_H