
#include <iostream>
#include <stdexcept>
#include <iostream>
using namespace std;

#include "Driver.h"

//Post: Creates a logged-in driver with the given name.
Driver::Driver(string name)
{
	user = name;
	place ="At the restaurant";
	numberDelivery = 0;
	loggedIn = true;
	sumTips = 0;
	Time departed;
	Time delivered;
	Time arrived;
	Order ord;
}

//Pre: Driver is not logged in.
//Post: Logs the driver in.
void Driver::login() throw (logic_error)
{
	if (isLoggedIn()) {
		throw logic_error("Logged in already");
	}
	else {
		loggedIn = true;
	}
}

//Pre: Driver is logged in and at the restaurant
//Post: Logs the driver out
void Driver::logout() throw (logic_error)
{
	if (!isLoggedIn() || place != "At the restaurant")
	{
		throw logic_error("Either driver is not at the restaurant or already logged out");
	}
	else
	{
		loggedIn = false;
	}
}

/******/

//Pre: Driver is logged in and at the restaurant.
//Post: Driver is delivering. Departure time is recorded
void Driver::depart(Time time, Order o) throw (logic_error)
{
	if (loggedIn && place == "At the restaurant") {
		place = "Delivering";
		departed = time;
		ord = o;
	}
	else {
		throw logic_error("Driver is not available.");
	}
}

//Pre: Driver is delivering, tip >= 0.
//Post: Driver is not delivering. Driver’s stats are updated.
void Driver::deliver(Time time, float tip) throw (logic_error)
{
	if (tip < 0 || place != "Delivering")
	{
		throw logic_error("Either tip amount is invalid or driver is not delivering");
	}
	else
	{
		delivered = time;
		sumTips = sumTips + tip;
		place = "Driving";
		totalDelivering = totalDelivering + departed.elapsedMin(departed, delivered);
	}
}

//Pre: Driver is driving but not delivering.
//Post: Driver is at the restaurant. Driver’s stats are updated.
void Driver::arrive(Time time) throw (logic_error)
{
	if (place == "Driving") {
		place = "At the restarant";
		arrived = time;
		totalDriving = totalDriving + delivered.elapsedMin(delivered, arrived);
		numberDelivery++;
	}
	else {
		throw logic_error("Driver is not driving.");
	}
}

//Post: Returns the driver’s name.
string Driver::getName()
{
	return user;
}

//Post: Returns true if and only if the driver is logged in.
bool Driver::isLoggedIn()
{
	return loggedIn;
}

//Post: Returns the total number of completed deliveries
int Driver::getTotalDeliveries()
{
	return numberDelivery;
}

//Post: Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands).
int Driver::getTotalMinDelivering()
{
	return totalDelivering;
}

//Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
int Driver::getTotalMinDriving()
{
	return totalDriving;
}
//Post: Returns the total tips received, in dollars.
float Driver::getTotalTips()
{
	return sumTips;
}

//Pre: Driver is delivering.
//Post: Returns the order being delivered.
Order Driver::getOrder() throw (logic_error)
{
	if (place != "Driving") {
		throw logic_error("Driver is not driving");
	}
	else
	{
		return ord;
	}
}

//Post: Returns a string containing the driver’s name, state (e.g., not logged in),
// and, if the driver is delivering an order, the departure time and toString of
// the order being delivered.
string Driver::toString()
{
	string output;
	string str_loggedIn;
	if (isLoggedIn())
	{
		str_loggedIn = " is logged in, ";
		if (place == "Delivering")
		{
			string deliver = "is delivering with departure time of" + departed.toString();
			string order = ord.toString();
			output = user + str_loggedIn + deliver + order;
		}
		else
		{
			output = user + str_loggedIn + "is not delivering";
		}
	}
	else
	{
		str_loggedIn = " is not logged in, ";
		output = user + str_loggedIn;
	}
	
	return output;
}