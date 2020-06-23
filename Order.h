#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Time.h"
using namespace std;

class Order {
public:
	Order();
	Order(Time time, string info);

	void depart() throw(logic_error);

	void deliver(Time time) throw (logic_error);
	int getMinToDelivery() throw(logic_error);
	string toString();
private:
	string orderInfo;
	Time ordered;
	Time delivered;
	string state;
};

#endif
