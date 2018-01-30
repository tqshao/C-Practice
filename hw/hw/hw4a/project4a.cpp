// EECS402
// project 4a
// Shiyang Lu
// shiyoung@umich.edu
// Project Overview: 
// This is the first part of the project4. Four classes were created:
// LinkedNodeClass, SortedListClass, LIFOStackClass and FIFOQueueClass.
// I'm basically implementing these classic data structures based on
// linked list.

#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.

  cout << "test on sorted list" << endl;
  cout << "==================================================" << endl;

  SortedListClass testList;
  
  testList.printForward();
  testList.insertValue(42);
  testList.insertValue(1);
  testList.insertValue(118);
  testList.insertValue(24);
  testList.printForward();
  testList.printBackward();

  SortedListClass test2(testList);
  test2.printForward();
  test2.printBackward();
  test2.insertValue(11);
  cout << test2.getNumElems() << endl;
  
  test2.printForward();
  test2.printBackward();

  int out;
  test2.removeFront(out);
  cout << "first" << out << endl;
  test2.removeFront(out);
  cout << "first" << out << endl;
  cout << test2.getNumElems() << endl;
  
  test2.removeLast(out);
  cout << "last" << out << endl;
  test2.removeLast(out);
  cout << "last" << out << endl;

  test2.printForward();
  test2.printBackward();

  test2.insertValue(13);
  test2.insertValue(18);
  test2.printForward();

  test2.getElemAtIndex(3, out);
  cout << "get" << out << endl;
  test2.getElemAtIndex(2, out);
  cout << "get" << out << endl;
  test2.getElemAtIndex(0, out);
  cout << "get" << out << endl;
  test2.getElemAtIndex(-1, out);
  cout << "get" << out << endl;

  test2.clear();
  test2.printForward();
  test2.printBackward();
  cout << "numEle" << test2.getNumElems() << endl;
  test2.getElemAtIndex(1, out);
  cout << "get" << out << endl;
  test2.removeFront(out);
  test2.removeLast(out);
  cout << "get" << out << endl;
  

  testList.printForward();
  testList.printBackward();

  
  cout << "test on queue" << endl;
  cout << "====================================================" << endl;

  FIFOQueueClass q1;
  q1.print();
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);
  q1.print();

  int outValue = 0;
  q1.dequeue(outValue);
  cout << outValue << endl;
  q1.print();

  q1.dequeue(outValue);
  cout << outValue << endl;
  q1.print();

  q1.dequeue(outValue);
  cout << outValue << endl;
  q1.print();

  if (!q1.dequeue(outValue)) {
    cout << "empty" << endl;
  }

  FIFOQueueClass q2;
  q2.enqueue(4);
  q2.enqueue(5);
  q2.enqueue(6);
  q2.print();
  q2.clear();
  q2.print();

  cout << "Test on stack" << endl;
  cout << "========================================================" << endl;
  LIFOStackClass s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.print();

  int outValue2 = 0;
  s1.pop(outValue2);
  cout << outValue2 << endl;
  s1.print();

  s1.pop(outValue2);
  cout << outValue2 << endl;
  s1.print();

  s1.pop(outValue2);
  cout << outValue2 << endl;
  s1.print();

  if (!s1.pop(outValue2)) {
    cout << "empty" << endl;
  }

  LIFOStackClass s2;
  s2.push(4);
  s2.push(5);
  s2.push(6);
  s2.print();

  s2.clear();
  s2.print();

  return 0;
}

#endif
