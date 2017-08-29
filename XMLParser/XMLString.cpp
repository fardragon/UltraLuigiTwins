#include "XMLString.h"


XMLString::XMLString(const std::string &data): m_data(data)
{
	m_data.erase(std::remove(m_data.begin(), m_data.end(), '\n'), m_data.end());
}

std::string XMLString::extractNext()
{
	if (m_data.empty())
	{
		return "";
	}
	auto left = std::find(m_data.begin(), m_data.end(), '<');
	auto right = std::find(m_data.begin(), m_data.end(), '>');
	if ((left == m_data.end()) || (right == m_data.end()))
	{
		return "";
	}
	auto result = std::string(left, std::next(right));
	m_data.erase(m_data.begin(), std::next(right));

	return result;
}

std::string XMLString::peekNext() const
{
	if (m_data.empty())
	{
		return "";
	}
	auto left = std::find(m_data.begin(), m_data.end(), '<');
	auto right = std::find(m_data.begin(), m_data.end(), '>');
	if ((left == m_data.end()) || (right == m_data.end()))
	{
		return "";
	}
	return std::string(left, std::next(right));
}



bool XMLString::isEmpty() const
{
	return m_data.empty();
}

bool XMLString::isProlog(const std::string &element)
{
	std::regex prologPattern(R"(<\?xml version=".*" encoding=".*"\?>)");
	return std::regex_match(element, prologPattern);
}

std::pair<std::string, std::string> XMLString::parseProlog(const std::string &element)
{
	std::pair<std::string, std::string> results;
	std::regex prologPattern(R"(\"([^(\")]*)\")");
	auto result_begin = std::sregex_iterator(element.begin(), element.end(), prologPattern);
	auto result_end = std::sregex_iterator();
	results.first = (*result_begin).str(1);
	std::advance(result_begin,1);
	results.second = (*result_begin).str(1);
	return results;
}

XMLelementType XMLString::elementType(const std::string &element)
{
	std::regex openTagPattern("<[^/].*[^/]>|<[^/]>");
	if (std::regex_match(element, openTagPattern)) return XMLelementType::openTag;
	std::regex closeTagPattern("</.*>");
	if (std::regex_match(element, closeTagPattern)) return XMLelementType::closeTag;
	std::regex singleTagPattern("<[^/].*/>");
	if (std::regex_match(element, singleTagPattern)) return XMLelementType::singleTag;

	return XMLelementType::syntaxError;
}

