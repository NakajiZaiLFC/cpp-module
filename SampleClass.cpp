#include "SampleClass.hpp"

// Default constructor
SampleClass::SampleClass(void) : privateIntegerValue(0), privateStringValue("")
{
	std::cout << "SampleClass default constructor called" << std::endl;
}

// Copy constructor
SampleClass::SampleClass(const SampleClass& otherInstance)
{
	std::cout << "SampleClass copy constructor called" << std::endl;
	*this = otherInstance;
}

// Assignment operator
SampleClass& SampleClass::operator=(const SampleClass& otherInstance)
{
	std::cout << "SampleClass assignment operator called" << std::endl;
	if (this != &otherInstance)
	{
		this->privateIntegerValue = otherInstance.privateIntegerValue;
		this->privateStringValue = otherInstance.privateStringValue;
	}
	return (*this);
}

// Destructor
SampleClass::~SampleClass(void)
{
	std::cout << "SampleClass destructor called" << std::endl;
}

// Parameterized constructor
SampleClass::SampleClass(int initialIntegerValue, const std::string& initialStringValue)
	: privateIntegerValue(initialIntegerValue), privateStringValue(initialStringValue)
{
	std::cout << "SampleClass parameterized constructor called" << std::endl;
}

// Getter for integer value
int SampleClass::getPrivateIntegerValue(void) const
{
	return (this->privateIntegerValue);
}

// Getter for string value
std::string SampleClass::getPrivateStringValue(void) const
{
	return (this->privateStringValue);
}

// Setter for integer value
void SampleClass::setPrivateIntegerValue(int newIntegerValue)
{
	this->privateIntegerValue = newIntegerValue;
}

// Setter for string value
void SampleClass::setPrivateStringValue(const std::string& newStringValue)
{
	this->privateStringValue = newStringValue;
}

// Display instance information
void SampleClass::displayInstanceInformation(void) const
{
	std::cout << "Integer value: " << this->privateIntegerValue << std::endl;
	std::cout << "String value: " << this->privateStringValue << std::endl;
}

// Check if integer value is positive
bool SampleClass::isIntegerValuePositive(void) const
{
	return (this->privateIntegerValue > 0);
}

// Check if string value is empty
bool SampleClass::isStringValueEmpty(void) const
{
	return (this->privateStringValue.empty());
}

// Reset instance to default values
void SampleClass::resetInstanceToDefaultValues(void)
{
	this->privateIntegerValue = 0;
	this->privateStringValue = "";
}