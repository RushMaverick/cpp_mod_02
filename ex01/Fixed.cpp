#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = nbr << _fract;
}

Fixed::Fixed(float const nbr) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = std::roundf(nbr * (1 << _fract));
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

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

int Fixed::setRawBits(int const raw) {
	this->_value = raw;
	std::cout << "setRawBits member function called." << std::endl;
	return(this->_value);
}

float Fixed::toFloat(void) const{
	float val = static_cast<float>(this->_value) / (1 << this->_fract);
	return (val);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fract;
}

std::ostream &operator<<(std::ostream &out, Fixed const &other){
	out << other.toFloat();
	return out;
}