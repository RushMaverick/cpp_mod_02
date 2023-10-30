#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return (*this);
}

int Fixed::getRawBits(){
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

int Fixed::setRawBits(int const raw) {
	this->_value = raw;
	std::cout << "setRawBits member function called." << std::endl;
	return(this->_value);
}
