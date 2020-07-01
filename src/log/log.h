#ifndef LOG_H
#define LOG_H

#include <string>


namespace Log{
	void Message(const std::string&);
	void Warning(const std::string&);
	void Error(const std::string&);
	void Debugf(const char* fmt...);
}


#endif
