#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

class RegularPolygon
{
public:
    RegularPolygon(unsigned int numSides, double sideLength);

    // Note: If a class has any virtual method then we need to declare a virtual
    // destructor. However, since we have no special need for a destructor in
    // RegularPolygon then we tell the compiler to implement a default for us.
    virtual ~RegularPolygon() = default;

    // The implementation is different for each subclass and here we only have
    // the interface for the method. Subclasses must implement the calcArea
    // method.
    const virtual double calcArea() = 0;

    // The implementation is the same for ll regular polygons and thus the
    // RegularPolygon class has an implementation for this method
    const virtual double calcTotalLength();

    const double calcHeight();

    // Nowadays the compiler is smart enough to make a small method such as this
    // implemented in the \.h file inline even if we don't use the inline
    // keyword.
    const inline unsigned int getNumSides() { return numSides; }

protected:
    const unsigned int numSides;
    const double sideLength;

};



#endif
