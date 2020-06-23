#ifndef RESTAURANT_CLASS_CPP
#define RESTAURANT_CLASS_CPP


#include "Restaurant.h"
#include <iostream>


//pre:	none
//post: Constructor that creates a restaurant in an initial state, with no drivers or orders.  
Restaurant::Restaurant() {
}

//pre: none.
//post: Prints status of orders and logged-in drivers, as specified by the “status” command description.  
void Restaurant::status()
{
	cout << "Orders waiting to be cook: " << endl;
	list<Order>::iterator iterator;
	for (iterator = Orders.begin(); iterator != Orders.end(); ++iterator) {
		cout << iterator->toString() << endl;
	}

	cout << "Orders waiting to be delivered: " << endl;
	list<Order>::iterator iterator2;
	for (iterator2 = Cooked.begin(); iterator2 != Cooked.end(); ++iterator2) {
		cout << iterator2->toString() << endl;
	}

	cout << "Orders being delivered: " << endl;
	list<Order>::iterator iterator3;
	for (iterator3 = Delivering.begin(); iterator3 != Delivering.end(); ++iterator3) {
		cout << iterator3->toString() << endl;
	}

	cout << "Orders completed: " << endl;
	list<Order>::iterator iterator4;
	for (iterator4 = CompOrder.begin(); iterator4 != CompOrder.end(); ++iterator4) {
		cout << iterator4->toString() << endl;
	}

	list<Driver>::iterator iterator5;
	for (iterator5 = Drivers.begin(); iterator5 != Drivers.end(); ++iterator5) {
		cout << iterator5->toString() << endl;
	}

	/*std::list<Driver>::iterator it2;
	for (it2 = Drivers.begin(); it2 != Drivers.end(); ++it2) {
		it2.toString();
	}
	std::queue<Orders>::iterator it;
	for (it = Orders.begin(); it != Orders.end(); ++it) {
		it.toString();
	}*/
}

//pre :none
//post: Prints summary statistics on orders and drivers, as specified by the “summary” command description.  
void Restaurant::summary()
{
	//cout >> "Number of orders completed: " >> numberOrder >> endl;
	//float s =
	cout << "Average time per order: " << endl;
	cout << "Driver ";

	cout << "  Number of deliveries completed: " << endl;
	cout << "  Average time per delivery: " << endl;
	cout << "  Total driving time: " << endl;
	cout << "  Total tips: " << endl;
}

/*******/
/*
Driver* Restaurant::getDriver(string name) {
	//std::list<Driver>::iterator it;
	Driver temp = Drivers.front();
	//for (it = Drivers.begin(); it != Drivers.end(); ++it) {
	//	if (name == it.getName()) {
	//		temp = it;
	//	}
	//}
	return &temp;
}*/

//pre: none
//post: Adds the given driver to the system. 
void Restaurant::addDriver(Driver driver)
{
	Drivers.push_back(driver);
}

//pre: none
//post: Adds the given order to the system, enqueuing it for cooking. 
void Restaurant::addOrder(string info, Time time)
{
	Order newOrder(time, info);
	Orders.push_back(newOrder);

}

//pre: The cooking queue is not empty. 
//post: Removes the oldest order from the cooking queue and enqueues it for departure.  
void Restaurant::serveNextOrder() throw (logic_error) {
	if (Orders.empty()) {
		throw logic_error("The order queue is empty");
	}
	else {
		Order temp;
		temp = Orders.front();
		Orders.pop_front();
		Cooked.push_back(temp);
	}
}

//pre: The departure queue is not empty.
//post: Removes the oldest order from the departure queue and returns it. 
void Restaurant::departNextOrder(Driver driver, Time time) throw (logic_error)
{
	if (Cooked.empty()) {
		throw logic_error("There is no order waiting to be delivered");
	}
	else
	{
		Order next = Cooked.front();
		driver.depart(time, next);
		Delivering.push_back(next);
		Cooked.pop_front();
	}
}

//pre: none
//post: The order carried by the driver is delivered at the given time. The driver receives the given tip. 
void Restaurant::deliver(Driver driver, Time time, float tip)
{
	Order temp = Delivering.front();
	driver.deliver(time, tip);
	CompOrder.push_back(temp);
	Delivering.pop_front();
}

#endif //RESTAURANT