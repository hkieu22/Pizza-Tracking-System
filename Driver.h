//
// Created by Huy Kieu on 11/28/19.
//

#ifndef FINAL_PROJECT_DRIVER_H
#define FINAL_PROJECT_DRIVER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"
#include "Order.h"

using namespace std;

class Driver {
public:
	Driver(string name);
	void login() throw (logic_error);
	void logout() throw (logic_error);
	void depart(Time time, Order o) throw (logic_error);
	void deliver(Time time, float tip) throw (logic_error);
	void arrive(Time time) throw (logic_error);
	string getName();
	bool isLoggedIn();
	int getTotalDeliveries();
	int getTotalMinDelivering();
	int getTotalMinDriving();
	float getTotalTips();
	Order getOrder() throw (logic_error);
	string toString();

private:
	string user;
	string place; // where the driver is: at the restaurant, driving, or delivering
	int numberDelivery;
	int totalDelivering;
	int totalDriving;
	bool loggedIn;
	double sumTips;
	Time departed;
	Time delivered;
	Time arrived;
	Order ord;
};
#endif //FINAL_PROJECT_DRIVER_H
