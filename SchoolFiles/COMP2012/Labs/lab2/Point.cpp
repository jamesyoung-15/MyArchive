/*
 * Point.cpp
 *
 */
 
#include <iostream>
#include "Point.h"
using namespace std;

// Default constructor. It creates a point (0,0)
Point::Point() 
{
  x = 0;
  y = 0;
}

// Conversion constructor that can convert a double to a Point object
Point::Point(double x)
{
  this->x = x;
  y = 0;
}

// Construct a point with the given coordinates
Point::Point(double x, double y)
{
  this->x = x;
  this->y = y;
}

// Check whether two points are the same
bool Point::equal(const Point& p) const
{
  return (x == p.x && y == p.y);
}

// Print the point
void Point::print() const
{
  cout << "(" << x << "," << y  << ")";
}

// Get x coordinate
double Point::getX() const
{
  return x;
}  

// Get y coordinate
double Point::getY() const
{
  return y;
}