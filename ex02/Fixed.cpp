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

bool Fixed::operator>(Fixed const& other) const {
	return _raw > other._raw;
}

bool Fixed::operator<(Fixed const& other) const {
	return _raw < other._raw;
}

bool Fixed::operator>=(Fixed const& other) const {
	return _raw >= other._raw;
}

bool Fixed::operator<=(Fixed const& other) const {
	return _raw <= other._raw;
}

bool Fixed::operator==(Fixed const& other) const {
	return _raw == other._raw;
}

bool Fixed::operator!=(Fixed const& other) const {
	return _raw != other._raw;
}

Fixed Fixed::operator+(Fixed const& other) const {
	Fixed r;
	r._raw = _raw - other._raw;
	return r;
}

Fixed Fixed::operator-(Fixed const& other) const {
	Fixed r;
	r._raw = _raw - other._raw;
	return r;
}

Fixed Fixed::operator*(Fixed const& other) const {
	Fixed r;
	int64_t tmp = static_cast<int64_t>(_raw) * static_cast<int64_t>(other._raw);
	r._raw = static_cast<int>(tmp >> _fb);
	return r;
}

Fixed Fixed::operator/(Fixed const& other) const {
	Fixed r;
	int64_t num = (static_cast<int64_t>(_raw) << _fb);
	r._raw = static_cast<int>(num / other._raw);
	return r;
}

Fixed& Fixed::operator++() { // pre
	++_raw;
	return *this;
}

Fixed Fixed::operator++(int) { // post
	Fixed tmp(*this);
	_raw++;
	return tmp;
}

Fixed& Fixed::operator--() { // pre
	--_raw;
	return *this;
}

Fixed Fixed::operator--(int) { // post
	Fixed tmp(*this);
	_raw--;
	return tmp;
}

// min / max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, Fixed const& f) {
	os << f.toFloat();
	return os;
}