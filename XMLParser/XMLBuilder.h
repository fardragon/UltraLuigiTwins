#ifndef XMLBuilder_h__
#define XMLBuilder_h__

#include <string>
#include <stack>
#include <tuple>
#include <memory>
#include <iostream>
#include <regex>
#include <algorithm>
#include "XMLString.h"
#include "XMLNode.h"

class XMLBuilder
{
public:
	XMLBuilder(const std::string &data);
	std::tuple<std::string, std::string, XMLNode*> parse();

private:
	std::vector<std::string> parseOpenElement(std::string element);
	std::vector<std::string> parseCloseElement(std::string element);
	std::vector<std::string> parseSingleElement(std::string element);
	void addAttribs(std::vector<std::string> attribs);


private:
	std::unique_ptr<XMLString> m_data;
	std::stack <XMLNode*> m_parsingStack;


};
#endif // XMLBuilder_h__

