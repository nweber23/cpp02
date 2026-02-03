#pragma once

#include "Fixed.hpp"

class Point {
  private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point();
    Point(float const x, float const y);
    Point(Point const& other);
    Point& operator=(Point const& other);
    ~Point();

    Fixed const& getX() const;
    Fixed const& getY() const;
};
