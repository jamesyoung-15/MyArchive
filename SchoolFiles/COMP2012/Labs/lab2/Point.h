/*
 * Point.h
 * The header file for the class Point
 */
 
class Point
{
  public:
    Point();                   // Default constructor. It creates a point (0,0)
    Point(double x);           // Conversion constructor that can convert a double to a Point object
                               // Assign x to data member x, and set y to 0
    Point(double x, double y); // Construct a point with the given coordinates
    bool equal(const Point& p) const; // Check whether two points are the same
    void print() const;	       // Print the point
    double getX() const;       // Get x coordinate
	  double getY() const;       // Get y coordinate

  private:
    double x, y;               // Coordinates
};
