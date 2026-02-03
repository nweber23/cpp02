#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  Point a(0, 0);
  Point b(10, 0);
  Point c(5, 10);

  std::cout << "\n=== BSP Tests ===" << std::endl;

  {
    Point p(5, 5);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 1 (inside): " << (result ? "PASS" : "FAIL") << std::endl;
  }

  {
    Point p(0, 10);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 2 (outside): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(0, 0);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 3 (at vertex a): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(10, 0);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 4 (at vertex b): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(5, 10);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 5 (at vertex c): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(5, 0);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 6 (on edge ab): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(7.5, 5);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 7 (on edge bc): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(2.5, 5);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 8 (on edge ca): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  {
    Point p(5, 3);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 9 (clearly inside): " << (result ? "PASS" : "FAIL") << std::endl;
  }

  {
    Point p(-10, -10);
    bool result = bsp(a, b, c, p);
    std::cout << "Test 10 (far outside): " << (result ? "FAIL" : "PASS") << std::endl;
  }

  std::cout << std::endl;
  return 0;
}
