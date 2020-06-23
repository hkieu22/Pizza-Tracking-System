#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Driver.h"
#include "Time.h"
#include "Restaurant.h"
#include "Order.h"

int main() {
	Restaurant res1;
	Driver dan("Dan");
	Driver adam("Adam");
	res1.addDriver(dan);
	res1.addDriver(adam);

	Time time1(10, 00);
	Time time2(10, 15);
	Time time3(10, 30);
	Time time4(10, 45);
	Time time5(11, 00);
	res1.addOrder("2 cheese to 120 West Mango Lane", time1);
	dan.login();

	res1.serveNextOrder();
	res1.departNextOrder(dan, time2);

	res1.addOrder("7 goats to 140 Milner Avenue", time3);
	adam.login();
	res1.addOrder("12 bears to 12 Honey Badger Aquarium", time4);
	res1.serveNextOrder();

	cout << "Report 1: " << endl;
	res1.status();
	cout << endl;

	res1.deliver(dan, time4, 4.5);
	dan.arrive(time5);

	cout << "Report 2: " << endl;
	res1.status();
	cout << endl;
	cout << "\nSummary:\n";
	res1.summary();

}