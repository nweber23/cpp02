#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) {
	std::cout << "Defaul constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _raw(n << _fb) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _raw(static_cast<int>(roundf(f * (1 << _fb)))) {
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_raw = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_raw = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return _raw;
}

void Fixed::setRawBits(int const raw) {
	_raw = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_raw) / (1 << _fb);
}

int Fixed::toInt(void) const {
	return _raw >> _fb;
}

std::ostream& operator<<(std::ostream& os, Fixed const& f) {
	os << f.toFloat();
	return os;
}