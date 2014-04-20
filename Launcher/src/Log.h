#ifndef LOG_H
#define LOG_H

#ifdef _DEBUG
# define LOG_DEBUG(_x_) std::cout << "[DEBUG][" << __FUNCTION__ << ":" << __LINE__ << "] " << _x_ << std::endl;
#else
# define LOG_DEBUG(_x_)
#endif
#define LOG_ERROR(_x_) std::cerr << "[ERROR][" << __FUNCTION__ << ":" << __LINE__ << "] " << _x_ << std::endl;

#endif
