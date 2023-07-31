#include <iostream>
#include "PointSet.h"
using namespace std;

PointSet::PointSet(int capacity)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's conversion constructor" << endl;

  // TODO #1: add your code here
  // new array of Point with size capacity, set numPoints to 0
  points = new Point[capacity];
  numPoints = 0;

}

PointSet::PointSet(const Point points[], int numPoints)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's other constructor" << endl;

  // TODO #2: add your code here
  // create new array of Point
  this->points = new Point[numPoints];
  // copy const points to new array
  for(int i =0;i<numPoints;i++)
  {
    this->points[i] = points[i];
  }
  // set numPoints and capacity to parameter numPoints
  this->numPoints = numPoints;
  this->capacity = numPoints;
}

PointSet::PointSet(const PointSet& s)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's copy constructor" << endl;

  // TODO #3: add your code here
  // copy over numPoints and capacity
  this->capacity = s.capacity;
  this->numPoints = s.numPoints;
  // create new array of Point to store s.points
  points = new Point[capacity];
  for(int i =0; i<s.numPoints; i++)
  {
    this->points[i] = s.points[i];
  }
}

PointSet::~PointSet()
{
  // TODO #4: add your code here
  delete [] points;

}

void PointSet::addPoint(const Point& p)
{
  // TODO #5: add your code here
  if(numPoints==capacity)
  {
    cout<<"Insufficient array space"<<endl;
    return;
  }
  else 
  {
    points[numPoints]=p;
    numPoints++;
  }
  
}

void PointSet::removeLastPoint()
{
  // TODO #6: add your code here
  if(numPoints==0)
  {
    cout<<"No points" <<endl;
    return;
  }
  else 
  {
    numPoints--;
    for(int i =0;i<numPoints;i++)
    {
      points[i]=points[i];
    }
  }
}

// Return true if the all the points in the point set is collinear; return false otherwise
bool PointSet::isCollinear() const
{
  // TODO #7: add your code here
  if(numPoints<=2)
  {
    return true;
  }
  else
  {
    for(int i =0; i<numPoints-2;i++)
    {
      if(!(isCollinear_3points(points[i], points[i+1], points[i+2])))
      {
        return false;
      }
    }
    return true;
  }
}

// return true if 3 given points are on the same straight line
bool PointSet::isCollinear_3points(const Point p1, const Point p2, const Point p3) const
{
  // TODO #8: add your code here
  double check = p1.getX() * (p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY()) + p3.getX() * (p1.getY()-p2.getY());
  if(check<0)
  {
    check*=-1;
  }
  double a = 0.5*check;
  if(a ==0)
    return true;
  else
    return false;
}

void PointSet::print() const
{
  // This function is already completed.
  if (numPoints == 0) {
    cout << "The PointSet is empty!" << endl;
    return;
  }
  cout << "Number of points: " << numPoints << endl;;
  cout << "points: " << endl;
  for(int i = 0; i < numPoints; i++)
  {
    points[i].print();
    cout << endl;
  }
}
