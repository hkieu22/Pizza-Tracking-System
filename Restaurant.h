//
// Created by Gunjan Joshi on 11/29/19.
//

#ifndef RESTAURANT_CLASS_H
#define RESTAURANT_CLASS_H

#include <stdexcept>
#include <iostream>
#include <list>
#include <queue>
#include "Driver.h"
#include "Order.h"
#include "Time.h"

using namespace std;

class Restaurant {
public:
	Restaurant();
	void status();
	void summary();
	Driver* getDriver(string name);
	void addDriver(Driver driver);
	void addOrder(string info, Time time);
	void serveNextOrder() throw (logic_error);
	void departNextOrder(Driver driver, Time time) throw (logic_error);
	void deliver(Driver driver, Time time, float tip);

private:
	list<Driver>Drivers;
	list<Order>Orders;
	list<Order>Cooked;
	list<Order>Delivering;
	list<Order>CompOrder;
	list<Driver>LoggedOut;

};

#endif //RESTAURANT_CLASS_H#pragma once
