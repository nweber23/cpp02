#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main() {
  std::cout << "=== Fixed class demo ===\n\n";

  Fixed a;
  std::cout << "Default-constructed a: " << a
            << "  (raw=" << a.getRawBits()
            << ", int=" << a.toInt()
            << ", float=" << a.toFloat() << ")\n\n";

  Fixed const b( Fixed(5.05f) * Fixed(2) );
  std::cout << "b = Fixed(5.05f) * Fixed(2): " << b
            << "  (raw=" << b.getRawBits()
            << ", int=" << b.toInt()
            << ", float=" << b.toFloat() << ")\n\n";

  std::cout << std::boolalpha;
  std::cout << "-- Increment / Decrement --\n";
  std::cout << "++a -> " << ++a << '\n';
  std::cout << "a     -> " << a << '\n';
  std::cout << "a++ -> " << a++ << "  (printed old value)\n";
  std::cout << "a     -> " << a << '\n';
  std::cout << "--a -> " << --a << '\n';
  std::cout << "a-- -> " << a-- << "  (printed old value)\n";
  std::cout << "a     -> " << a << '\n';

  std::cout << "\n-- Arithmetic --\n";
  Fixed x(10);
  Fixed y(3);
  std::cout << "x = " << x << "  y = " << y << '\n';
  std::cout << "x + y = " << x + y << '\n';
  std::cout << "x - y = " << x - y << '\n';
  std::cout << "x * y = " << x * y << '\n';
  std::cout << "x / y = " << x / y << '\n';

  std::cout << "\n-- Mixed expressions / chaining --\n";
  Fixed chain = (x * Fixed(2)) + Fixed(1.5f) - y;
  std::cout << "chain = (x * 2) + 1.5 - y = " << chain
            << "  (int=" << chain.toInt()
            << ", float=" << std::setprecision(6) << chain.toFloat() << ")\n";

  std::cout << "\n-- Comparisons & min/max --\n";
  std::cout << "x > y: " << (x > y) << '\n';
  std::cout << "x < y: " << (x < y) << '\n';
  std::cout << "x == y: " << (x == y) << '\n';
  std::cout << "min(x,y) = " << Fixed::min(x, y) << '\n';
  std::cout << "max(x,y) = " << Fixed::max(x, y) << '\n';

  std::cout << "\n-- Original example check --\n";
  std::cout << "a = " << a << '\n';
  std::cout << "b = " << b << '\n';
  std::cout << "max(a, b) = " << Fixed::max(a, b) << '\n';

  return 0;
}
// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }