// EECS402
// project 5
// Shiyang Lu
// shiyoung@umich.edu
// UMID: 69796900
// This project is to implement a server simulation at a fast food restaurant.
// The simulation is implemented as an event-driven simulation.
// LinkedListNode SortedListClass and FIFOQueueClass template were used.
// Two additional classes -- Customer and Event were created
// The purpose of this project is to let us be familiar with event driven
// simulation and practice creating and using tamplate.

#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"
#include "random.h"
#include "SortedListClass.h"
#include "Event.h"
#include "Customer.h"

int main() {
const string CUSTOMER_COME = "come";
const string CUSTOMER_LEAVE = "leave";
const int START_TIME = 0;
const int EMPTY = 0;
    
bool idle = true;
int qSize = 0;
int maxQSize = 0;
int numCustomers = 0;
int currentTime = 0;
int startServeTime = 0;
int startBreakTime = 0;
int busyTime = 0; // accumulative busy time in the simulation
int numCustomersWait = 0; // number of customers wait in queue;
int minCustomerInterval = 1000000; // min time between two customer come
int maxServingTime = 0; // max serving time for one customer
int minServingTime = 1000000; // min serving time for one customer
int maxBreakTime = 0; // longest time the server can have a rest

int MIN;
int MAX;
double MEAN;
double STDDEV;
int CLOSE_TIME;

cout << "enter the min and max for the uniform distribution: " << endl;
cin >> MIN >> MAX;
while (cin.fail() || MIN > MAX || MIN < 0) {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "error, min and max should be integer and min should be smaller "
        << "than max, please try again" << endl;
    cin >> MIN >> MAX;
}

cout << "enter the mean and standard deviation for the normal "
    << "distribution: " << endl;
cin >> MEAN >> STDDEV;
while (cin.fail() || MEAN < 0 || STDDEV < 0) {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "error, mean and standard deviation should be double and "
        "greater than or equal to 0, please try again" << endl;
    cin >> MEAN >> STDDEV;
}

cout << "enter the close time for the restaurant: " << endl;
cin >> CLOSE_TIME;
while (cin.fail() || CLOSE_TIME <= 0) {
    cin.clear();
    cin.ignore(200, '\n');
    cout << "error, close time should be greater than 0," 
        << "please try again" << endl;
    cin >> CLOSE_TIME;
}

SortedListClass<Event> list;
FIFOQueueClass<Customer> q;

Event firstCustomerCome(CUSTOMER_COME, START_TIME);
list.insertValue(firstCustomerCome);

Event e;
Customer c;

while (currentTime < CLOSE_TIME || qSize > 0) {
    list.removeFront(e);
    currentTime = e.getTimeStamp();
    string eventType = e.getEventType();

    cout << "current time: " << currentTime << ", ";

    if (eventType == CUSTOMER_COME && currentTime < CLOSE_TIME) {
        // enqueue a new customer
        Customer *newCustomer = new Customer(++numCustomers);
        q.enqueue(*newCustomer);
        qSize++;

        cout << "customer" << newCustomer->getCustomerId() << " come, ";

        // add next CUSTOMER_COME event
        int customerInterval = getUniform(MIN, MAX);
        int nextTimeStamp = currentTime + customerInterval;
        if (nextTimeStamp < CLOSE_TIME) {
            Event nextCustomerCome(CUSTOMER_COME, nextTimeStamp);
            list.insertValue(nextCustomerCome);
            if (customerInterval < minCustomerInterval) {
                minCustomerInterval = customerInterval;
            }
        }
    } else { // customer leave
        cout << "customer" << c.getCustomerId() << " leave, ";
        busyTime += currentTime - startServeTime;
        idle = true;
        startBreakTime = currentTime;
    }

    if (idle && qSize > EMPTY) {
        // serve the next customer
        q.dequeue(c);
        qSize--;
        idle = false;
        startServeTime = currentTime;
        cout << "start serving customer" << c.getCustomerId() << ", ";

        // add next CUSTOMER_LEAVE event
        int servingTime = getNormal(MEAN, STDDEV);
        // servingTime must be non-negative
        servingTime = servingTime > 0 ? servingTime : 1;

        int nextTimeStamp = currentTime + servingTime;

        Event leaveEvent(CUSTOMER_LEAVE, nextTimeStamp);
        list.insertValue(leaveEvent);

        if (servingTime > maxServingTime) {
            maxServingTime = servingTime;
        }
        if (servingTime < minServingTime) {
            minServingTime = servingTime;
        }
        if (currentTime - startBreakTime > maxBreakTime) {
            maxBreakTime = currentTime - startBreakTime;
        }
    }

    if (eventType == CUSTOMER_COME && qSize > EMPTY) {
        numCustomersWait++;
    }
    maxQSize = qSize > maxQSize ? qSize : maxQSize;
    cout << qSize << " customers waiting in the queue" << endl;
}

// print out statistics
// 1
cout << "Total number of customers simulated: " << numCustomers << endl;

// 2
double busyPercentage = (double)busyTime / currentTime;
cout << "Percentage of time the server was busy helping customers: " 
    << busyPercentage << endl;

// 3
double waitPercentage = (double)numCustomersWait / numCustomers;
cout << "Percentage of customers had to wait in line:"
    << waitPercentage << endl;

// 4
cout << "The longest the line was: " << maxQSize << endl;

// 5
cout << "Minimum interval between two customer come events: "
    << minCustomerInterval << endl;

// 6
cout << "Longest serving time for one customer: " 
    << maxServingTime << endl;

// 7
cout << "Shortest serving time for one customer: "
    << minServingTime << endl;

// 8
cout << "Longest time the server can have a rest: "
    << maxBreakTime << endl;

return 0;
}