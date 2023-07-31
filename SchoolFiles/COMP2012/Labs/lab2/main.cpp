/*
 * main.cpp
 */

#include <iostream>
#include "PointSet.h"
using namespace std;

int main()
{
  cout << "PointSet1:" << endl;
  PointSet set1(10); // Initialized by the default constructor
  set1.print();
  cout << "Remove last point" << endl;
  set1.removeLastPoint();
  set1.print();
  cout << "Does PointSet1 collinear? ";
  cout << boolalpha << set1.isCollinear() << endl;
  cout << endl;

  Point points[4] = {Point(0, 0), Point(1.5, 2), Point(3, 4), Point(7.5, 10) };

  cout << "PointSet2:" << endl;
  PointSet* set2 = new PointSet(points, 4); // Initialized by the other constructor
  set2->print();
  cout << "Does PointSet2 collinear? ";
  cout << boolalpha << set2->isCollinear() << endl;
  cout << endl;

  cout << "PointSet3:" << endl;
  PointSet set3(*set2); // Initialized by the copy constructor
  cout << "Remove last point" << endl;
  set3.removeLastPoint();
  cout << "Add point (3, 1.7)" << endl;
  set3.addPoint(Point(3, 1.7));
  set3.print();
  cout << endl;
  cout << "Add point (5, 5)" << endl;
  set3.addPoint(Point(5, 5));
  set3.print();
  cout << "Does PointSet3 collinear? ";
  cout << boolalpha << set3.isCollinear() << endl;

  delete set2; // Deallocate the dynamically allocated memory

  return 0;
}
