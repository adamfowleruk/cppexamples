#include "TestClasses.hpp"
#include <string>
#include <iostream>

using namespace mltests;

const char* getString(PointerWrapper* pw) {
	return pw->getString().c_str();
}


/*
 * Working use of the unique_ptr with a container pattern
 */
int main(int argc, const char * argv[])
{
	PointerWrapper* wrapper = new PointerWrapper(); // Yes, I could use std::unique_ptr<PointerWrapper> here instead, but a bit overkill for a simple solution. In the real world you MUST do this too if it exists beyond this function.
	{
	  // STEP 1: use new so that you get a Pointer
	  std::unique_ptr<std::string> s(new std::string("Some String that is really really long and easy to truncate in memory"));
	  std::cout << "myStr: " << *s.get() << std::endl;
	  wrapper->setString(std::move(s)); // STEP 2: Use std::move() to eat s - thus do NOT use the variable s directly after this point - only the wrapper
	} // Destroys s (which no longer points to our string - as the reference was moved to the wrapper instance)

	std::cout << "getString: " << getString(wrapper) << std::endl;
	
	// For STEPS 4, 5 See TestClasses.cpp
	// For STEP 6, See TestClasses.hpp
}
