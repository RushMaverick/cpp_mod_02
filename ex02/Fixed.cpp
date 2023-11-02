#include "Fixed.hpp"

const int Fixed::_fract = 8;

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

//////////////////////*Comparison operator overloads*//////////////////////

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator for = called" << std::endl;
	this->_value = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &other) {
	return this->_value > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) {
	return this->_value < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) {
	return this->_value >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) {
	return this->_value <= other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) {
	return this->_value != other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) {
	return this->_value == other.getRawBits();
}
/////////////////////*Comparison operator overload end*////////////////////


//////////////////////*Arithmetic operator overload*//////////////////////

Fixed &Fixed::operator+(const Fixed &other){
	this->_value = this->getRawBits() + other.getRawBits();
	return (*this);
}

Fixed &Fixed::operator-(const Fixed &other){
	this->_value = this->getRawBits() - other.getRawBits();
	return (*this);
}

Fixed &Fixed::operator*(const Fixed &other){
	this->_value = (this->getRawBits() * other.getRawBits() / (1 << _fract));
	return (*this);
}

Fixed &Fixed::operator/(const Fixed &other){
	this->_value = ((this->getRawBits() / other.getRawBits()) * (1 << _fract));
	return (*this);
}
////////////////////*Arithmetic operator overload end*////////////////////


////////////////////*Post- and prefix increment/decrement operator overload*////////////////////

Fixed& Fixed::operator++() {
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	temp._value = this->_value++;
	return(temp);
}

Fixed& Fixed::operator--() {
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	temp._value = this->_value--;
	return (temp);
}

////////////////////*Post- and prefix increment/decrement operator overload end*////////////////

//////////////////////*Min/Max value return methods*//////////////////

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2){
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2){
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2){
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed& Fixed::max(Fixed &n1, Fixed &n2){
	if (n1 > n2)
		return (n1);
	return (n2);
}

////////////////////*Min/Max value return methods end*////////////////

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
	float val = static_cast<float>(this->_value) / static_cast<float>(1 << this->_fract);
	return (val);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fract;
}

std::ostream &operator<<(std::ostream &out, Fixed const &other){
	out << other.toFloat();
	return out;
}