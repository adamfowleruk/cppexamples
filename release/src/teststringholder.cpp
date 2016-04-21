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
	StringHolder* ptrS;
	{
	  std::string s = std::string("Some String that is really really long and easy to truncate in memory");
	  std::cout << "original string: " << s << std::endl;

	  StringHolder holder(s);
	  std::cout << "holder string: " << *(holder.getString()) << std::endl;

	  ptrS = &holder;
	}

	std::cout << "holder string now: " << *(ptrS->getString()) << std::endl;
}
