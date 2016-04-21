#include <string>

namespace mltests {

using namespace std;

/*
 * ANTI PATTERN
 */
class StringReference {
public:
	StringReference();
	void setString(std::string& strRef);
	std::string& getString();
private:
	std::string str;
};

/*
 * ANTI PATTERN
 */
class StringHolder {
public:
	StringHolder(std::string s);
	std::string* getString();
private:
	std::string* str;
};

/*
 * Working use of the unique_ptr with a container pattern - See testpointerwrapper.cpp for full details.
 */
class PointerWrapper {
public:
	PointerWrapper();
	~PointerWrapper();

	void setString(std::unique_ptr<std::string> str); // requires move semantics, and this class takes ownership
	std::string& getString();
private:
	std::unique_ptr<std::string> ptr; // STEP 6: declare as a plain object, no pointers, no references, no const
};

/*
 * ANTI PATTERN
 */
class StringWrapper {
public:
	StringWrapper();
	~StringWrapper();

	void setString(std::string str);
	std::string getString();
private:
	std::string theString;
};

}
