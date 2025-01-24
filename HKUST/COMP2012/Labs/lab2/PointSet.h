/*
 * PointSet.h
 * The header file for the class PointSet
 */

#include "Point.h"

class PointSet
{
  public:
    // Conversion constructor
    // Dynamically allocate an array of Points with capacity "capacity" and make it pointed by the data member "points". 
    // It also initializes the data member "capacity" and set numPoints to 0.
    PointSet(int capacity);  

    // Other constructor
    // Dynamically allocate an array of Points with capacity equals to the parameter "numPoints" and make it pointed by the data member "points".
    // Copy all the points in the parameter "points" over.
    // Remember to set all the corresponding data members properly.
    PointSet(const Point points[], int numPoints); 

    // Copy constructor - Perform deep copy
    PointSet(const PointSet& s);

    // Destructor
    // Deallocate all the dynamically allocated memory to prevent memory leak
    ~PointSet();

    // Add a point p to the end of the point set, output (cout) the message "Insufficient array space" and 
    // do nothing else if there are already "capacity" number of points in the point set.
    void addPoint(const Point& p); 

    // Remove the last point (the one with the largest index) in the set,
    // output (cout) the message "No points" and do nothing if the set has no points at all.
    void removeLastPoint();
 
    // Return true if all the points in the point set is collinear; return false otherwise
    bool isCollinear() const;

    // Print the list of points in the set
    void print() const;	

  private:
    Point* points;
    int capacity;
    int numPoints;
    bool isCollinear_3points(const Point p1, const Point p2, const Point p3) const; // return true if 3 given points are on the same straight line
};
