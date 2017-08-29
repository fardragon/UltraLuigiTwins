#ifndef XMLString_h__
#define XMLString_h__

#include <string>
#include <algorithm>
#include <regex>

enum class XMLelementType;
class XMLString
{
public:
	XMLString(const std::string &data);
	std::string extractNext();
	std::string peekNext() const;
	bool isEmpty() const;

	static bool isProlog(const std::string &element);
	static std::pair<std::string, std::string> parseProlog(const std::string &element);
	static XMLelementType elementType(const std::string &element);


private:



private:
	std::string m_data;


};

enum class XMLelementType
{
	openTag,
	closeTag,
	singleTag,
	syntaxError
};

#endif // XMLString_h__

