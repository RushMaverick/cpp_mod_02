#ifndef FIXEDHPP
#define FIXEDHPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fract;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed &operator=(const Fixed &other);
		int getRawBits() const;
		int setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif