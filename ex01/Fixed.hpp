#ifndef FIXEDHPP
#define FIXEDHPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fract = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed &operator=(const Fixed &other);
		int getRawBits();
		int setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif