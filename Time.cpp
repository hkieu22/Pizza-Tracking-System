#ifndef TIME_CLASS_CPP
#define TIME_CLASS_CPP
#include <string>


#include "Time.h"
#include <iostream>

//pre: none
//post: Constructor that creates a time with default values for data members.
Time ::Time() : hour(0) , min(0){

}

//pre: 0 <= hour <= 23 and 0 <= min <= 59
//post: Creates a time with the given hour and minute. 
Time::Time(int hour, int min) throw (logic_error) {
	if ((hour < 0) && (hour > 23) || (min < 0) && (min > 59)) {
		throw("Invalid time entry.");
	}
	else {
		this->hour = hour;
		this->min = min;
	}
}

//pre: none
//post: Returns the difference in minutes between t1 and t2.
		//Assumes t2 is between 00:00 and 23:59 hours after t1. 
int Time::elapsedMin(Time t1, Time t2) {
	int period;
	int minutes_t1 = (t1.hour * 60) + t1.min;
	int minutes_t2 = (t2.hour * 60) + t2.min;
	/*if (minutes_t2 - minutes_t1 < 0) {
		period = 60 + minutes_t2 - minutes_t1;
	}
	else {*/
		period = minutes_t2 - minutes_t1;
	//}
	return period ;
}

//pre: none
//post: Returns a string containing the hour and minute (e.g., “13:01”).    
string Time::toString() {
	string output = to_string(hour) + ":" + to_string(min);
	//cout << hour << ":" << min << endl;
	return output;
}




#endif //TIME_CLASS_CPP