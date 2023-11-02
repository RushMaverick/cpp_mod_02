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

		/*min/max methods*/
		static const Fixed& min (const Fixed &n1, const Fixed &n2);
		static const Fixed& max (const Fixed &n1, const Fixed &n2);
		static Fixed& min (Fixed &n1, Fixed &n2);
		static Fixed& max (Fixed &n1, Fixed &n2);

		/*Comparison operators*/
		Fixed &operator=(const Fixed &other);
		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator!=(const Fixed &other);
		bool operator==(const Fixed &other);

		/*Arithmetic operators*/
		Fixed &operator+(const Fixed &other);
		Fixed &operator-(const Fixed &other);
		Fixed &operator*(const Fixed &other);
		Fixed &operator/(const Fixed &other);

		/*Post- and prefix increments/decrements*/
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int getRawBits() const;
		int setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif