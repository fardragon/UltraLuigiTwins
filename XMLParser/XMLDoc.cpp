#include "XMLDoc.h"


XMLDoc::XMLDoc()
{
}


bool XMLDoc::parseFromFile(const std::string &filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open()) return false;
	auto data = std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());	
	return this->parseFromString(data);
}

bool XMLDoc::parseFromString(std::string data)
{
	this->clear();
	XMLBuilder parser(data);
	auto result = parser.parse();
	if (std::get<2>(result) == nullptr)
	{
		return false;
	}
	m_rootNode.reset(std::get<2>(result));
	m_encoding = std::get<1>(result);
	m_xmlVersion = std::get<0>(result);
	return true;
}

void XMLDoc::clear()
{
	m_xmlVersion.clear();
	m_encoding.clear();
	m_rootNode.reset(nullptr);
}
