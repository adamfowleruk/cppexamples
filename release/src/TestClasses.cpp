#include <string>
#include "TestClasses.hpp"

namespace mltests {

/*
 * ANTI PATTERN
 */
StringReference::StringReference() {
	;
}

void StringReference::setString(std::string& ref) {
	str = ref;
}

std::string& StringReference::getString() {
	return str;
}






/*
 * ANTI PATTERN
 */
StringHolder::StringHolder(std::string s) : str() {
  str = &s;
}

std::string* StringHolder::getString() {
	return str;
}








/*
 * Working use of the unique_ptr with a container pattern
 */
	PointerWrapper::PointerWrapper() {

	}
	PointerWrapper::~PointerWrapper() {

	}

  /*
   * Step 3: Accept just a plain unique_ptr for an IN ONLY (Sink) use of str
   */
	void PointerWrapper::setString(std::unique_ptr<std::string> str) { // by value, so take ownership
		ptr = std::move(str); // move needed again, as moving from function to object ownership.
	}
	/*
	 * Step 4: Return a reference to the string held by our internal unique_ptr instance - see TestClasses.hpp for its declaration
	 */
	std::string& PointerWrapper::getString() {
		return *ptr;
	}







	/*
	 * ANTI PATTERN
	 */
	StringWrapper::StringWrapper() {

	}
	StringWrapper::~StringWrapper() {

	}

	void StringWrapper::setString(std::string str) {
		theString = str;
	}
	std::string StringWrapper::getString() {
		return theString;
	}

}
