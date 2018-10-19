#ifndef FT_GKRELLM_EXCEPTIONS
#define FT_GKRELLM_EXCEPTIONS

#include <exception>
#include <string>

class BadModuleException : public std::exception {

public:
	BadModuleException();
	BadModuleException(std::string module);
	virtual ~BadModuleException() throw();

	virtual const char * what() const throw();

protected:
	std::string errorMsg_;

private:
	BadModuleException(const exception &);
	BadModuleException & operator=(BadModuleException const &);

};

#endif
