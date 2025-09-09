#ifndef SAMPLECLASS_HPP
# define SAMPLECLASS_HPP

#include <iostream>
#include <string>

class SampleClass
{
private:
	int				privateIntegerValue;
	std::string		privateStringValue;

public:
	// Orthodox canonical form (required by 42)
	SampleClass(void);
	SampleClass(const SampleClass& otherInstance);
	SampleClass& operator=(const SampleClass& otherInstance);
	~SampleClass(void);

	// Parameterized constructor
	SampleClass(int initialIntegerValue, const std::string& initialStringValue);

	// Getter methods with descriptive names
	int				getPrivateIntegerValue(void) const;
	std::string		getPrivateStringValue(void) const;

	// Setter methods with descriptive names
	void			setPrivateIntegerValue(int newIntegerValue);
	void			setPrivateStringValue(const std::string& newStringValue);

	// Business logic methods with single responsibility
	void			displayInstanceInformation(void) const;
	bool			isIntegerValuePositive(void) const;
	bool			isStringValueEmpty(void) const;
	void			resetInstanceToDefaultValues(void);
};

#endif