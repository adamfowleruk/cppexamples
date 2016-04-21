#include "TestClasses.hpp"
#include <string>
#include <iostream>

using namespace mltests;

const char* getString(PointerWrapper* pw) {
	return pw->getString().c_str();
}


/*
 * ANTI PATTERN - See testpointerwrapper.cpp
 */
int main(int argc, const char * argv[])
{
	//std::string orig = std::string("Whatever");
	StringReference str;
	//std::cout << "orig ref: " << str.getString() << std::endl;
	{
	  std::string os = std::string("Some String that is really really long and easy to truncate in memory");
	  std::cout << "original string: " << os << std::endl;
	  //std::string& s = os;
	  //std::cout << "string ref: " << s << std::endl;

	  str.setString(os);
	  std::cout << "get string ref: " << str.getString() << std::endl;
	}

	std::cout << "string ref now: " << str.getString() << std::endl;
}
