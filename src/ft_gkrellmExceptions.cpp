#include "ft_gkrellmExceptions.hpp"

BadModuleException::BadModuleException()
	{ errorMsg_ = "illegal module"; }

BadModuleException::BadModuleException(std::string module)
	{ errorMsg_ = module + ": illegal module"; }

BadModuleException::~BadModuleException() throw ()
	{ }

const char* BadModuleException::what() const throw()
	{ return errorMsg_.c_str(); }
