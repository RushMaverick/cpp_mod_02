#ifndef FIXEDHPP
#define FIXEDHPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fract = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int getRawBits();
		int setRawBits(int const raw);
};

#endif