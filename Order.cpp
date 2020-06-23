#include <ctime>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include "Order.h"

using namespace std;
//Post: Creates an order with default values for data members.
Order::Order() {
	orderInfo = "NULL";
	state = "NULL";
}
//Post: Creates an order with the given order time and information.
Order::Order(Time time, string info) {
	ordered = time;
	orderInfo = info;
	state = "At the restaurant";
}
//Pre: Order is at the restaurant.
//Post: Order is out for delivery.
void Order::depart() throw(logic_error) {
	if (state != "At the restaurant") {
		throw logic_error("Order must be at the restaurant");
	}
	else {
		state = "Out for delivery";
	}

}
//Pre: Order is out for delivery.
//Post: Order is delivered. Time to delivery is recorded.
void Order::deliver(Time time) throw (logic_error) {
	if (state != "Out for delivery") {
		throw logic_error("Order must be out for delivery");
	}
	else {
		state = "Delivered";
		delivered = time;
	}
}
//Pre: Order is delivered.
//Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
int Order::getMinToDelivery() throw(logic_error) {
	if (state != "Delivered") {
		throw logic_error("Order must be delivered");
	}
	else
	{
		return ordered.elapsedMin(ordered, delivered);
	}
}
//Post: Returns a string containing the order time and info.
string Order::toString() {
	string s = "Ordered Time: " + ordered.toString() + "  " + "Order info: " + orderInfo;
	return s;
}