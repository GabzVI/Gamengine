#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include <string>


struct Exception : public std::exception
{
public:

  Exception(const std::string& message);
  virtual ~Exception() throw();
  virtual const char* what() const throw();

private:
  std::string message;

};

#endif
