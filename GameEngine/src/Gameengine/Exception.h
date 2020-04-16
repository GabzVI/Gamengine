#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include <string>

///This is a struct Exception which is a personalised exception that allows us to type the message we want to output during errors during run time, so users can indentify where errors are happening more easily.
struct Exception : public std::exception
{

private:

	std::string message;

public:

	Exception(const std::string& message);
	virtual ~Exception() throw();
	virtual const char* what() const throw();

};

#endif
