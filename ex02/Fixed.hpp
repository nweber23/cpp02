#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	_raw;
		static const int	_fb = 8;
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const& other);
		Fixed& operator=(Fixed const& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// comparison
		bool	operator>(Fixed const& other) const;
		bool	operator<(Fixed const& other) const;
		bool	operator>=(Fixed const& other) const;
		bool	operator<=(Fixed const& other) const;
		bool	operator==(Fixed const& other) const;
		bool	operator!=(Fixed const& other) const;

		// arithmetic
		Fixed	operator+(Fixed const& other) const;
		Fixed	operator-(Fixed const& other) const;
		Fixed	operator*(Fixed const& other) const;
		Fixed	operator/(Fixed const& other) const;

		// increment / decrement
		Fixed&	operator++();    // pre-increment
		Fixed	operator++(int); // post-increment
		Fixed&	operator--();    // pre-decrement
		Fixed	operator--(int); // post-decrement

		// min / max
		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& os, Fixed const& f);

#endif