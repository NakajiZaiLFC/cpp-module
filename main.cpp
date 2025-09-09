#include "SampleClass.hpp"

int main(void)
{
	std::cout << "=== Testing SampleClass C++89 Compliance ===" << std::endl;

	// Test default constructor
	std::cout << "\n--- Testing Default Constructor ---" << std::endl;
	SampleClass defaultInstance;
	defaultInstance.displayInstanceInformation();

	// Test parameterized constructor  
	std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
	SampleClass parameterizedInstance(42, "Hello World");
	parameterizedInstance.displayInstanceInformation();

	// Test copy constructor
	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	SampleClass copiedInstance(parameterizedInstance);
	copiedInstance.displayInstanceInformation();

	// Test assignment operator
	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	defaultInstance = parameterizedInstance;
	defaultInstance.displayInstanceInformation();

	// Test getter methods
	std::cout << "\n--- Testing Getter Methods ---" << std::endl;
	std::cout << "Integer value via getter: " << defaultInstance.getPrivateIntegerValue() << std::endl;
	std::cout << "String value via getter: " << defaultInstance.getPrivateStringValue() << std::endl;

	// Test setter methods
	std::cout << "\n--- Testing Setter Methods ---" << std::endl;
	defaultInstance.setPrivateIntegerValue(-10);
	defaultInstance.setPrivateStringValue("Modified String");
	defaultInstance.displayInstanceInformation();

	// Test business logic methods
	std::cout << "\n--- Testing Business Logic Methods ---" << std::endl;
	std::cout << "Is integer positive? " << (defaultInstance.isIntegerValuePositive() ? "Yes" : "No") << std::endl;
	std::cout << "Is string empty? " << (defaultInstance.isStringValueEmpty() ? "Yes" : "No") << std::endl;

	// Test reset functionality
	std::cout << "\n--- Testing Reset Functionality ---" << std::endl;
	defaultInstance.resetInstanceToDefaultValues();
	defaultInstance.displayInstanceInformation();
	std::cout << "Is integer positive? " << (defaultInstance.isIntegerValuePositive() ? "Yes" : "No") << std::endl;
	std::cout << "Is string empty? " << (defaultInstance.isStringValueEmpty() ? "Yes" : "No") << std::endl;

	std::cout << "\n=== Testing Complete ===" << std::endl;
	return (0);
}