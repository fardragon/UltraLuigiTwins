#include "XMLBuilder.h"



XMLBuilder::XMLBuilder(const std::string &data)
{
	m_data = std::make_unique<XMLString>(data);
}

std::tuple<std::string, std::string, XMLNode*> XMLBuilder::parse()
{
	auto result = std::make_tuple<std::string, std::string, XMLNode*>("", "", nullptr);
	bool XMLValid = true;

	if (m_data->isEmpty()) return result;
	if (XMLString::isProlog(m_data->peekNext()))
	{
		auto prolog = m_data->extractNext();
		auto prologData = XMLString::parseProlog(prolog);
		std::get<0>(result) = prologData.first;
		std::get<1>(result) = prologData.second;
	}
	while ((!m_data->isEmpty()) && (XMLValid))
	{
		std::string xml_element = m_data->extractNext();
		auto elementType = XMLString::elementType(xml_element);
		std::vector<std::string> tokens;
		switch (elementType)
		{
		case XMLelementType::openTag:
		{
			tokens = this->parseOpenElement(xml_element);
			if (m_parsingStack.empty())
			{
				m_parsingStack.push(new XMLNode(tokens.front()));
				tokens.erase(tokens.begin());
				std::get<2>(result) = m_parsingStack.top();
			}
			else
			{
				auto ptr = m_parsingStack.top()->addChild(tokens.front());
				tokens.erase(tokens.begin());
				m_parsingStack.push(ptr);
			}
			this->addAttribs(tokens);
			break;
		}
		case XMLelementType::closeTag:
		{
			if (m_parsingStack.empty())
			{
				XMLValid = false;
				break;
			}
			tokens = this->parseCloseElement(xml_element);
			if (tokens.front() == m_parsingStack.top()->getName())
			{
				m_parsingStack.pop();
			}
			else
			{
				XMLValid = false;
			}

			break;
		}		
		case XMLelementType::singleTag:
		{
			if (m_parsingStack.empty())
			{
				XMLValid = false;
				break;
			}
			tokens = this->parseSingleElement(xml_element);
			auto ptr = m_parsingStack.top()->addChild(tokens.front());
			tokens.erase(tokens.begin());
			m_parsingStack.push(ptr);
			this->addAttribs(tokens);
			m_parsingStack.pop();
			break;
		}		
		case XMLelementType::syntaxError:
		{
			XMLValid = false;
			break;
		}
		}
	}
	if (XMLValid) return result;
	if (std::get<2>(result) != nullptr)
	{
		delete std::get<2>(result);
	}
	result = std::make_tuple<std::string, std::string, XMLNode*>("", "", nullptr);
	return result;
}

std::vector<std::string> XMLBuilder::parseOpenElement(std::string element)
{
	std::vector<std::string> result;

	element = std::string(std::next(element.begin()), std::prev(element.end()));
	result.emplace_back(element.begin(), std::find(element.begin(),element.end(),' '));
	std::regex attribPattern(R"([\S]*="[^"]+")");


 	std::sregex_iterator iter(element.begin(), element.end(), attribPattern);
	std::sregex_iterator end;
 	while (iter != end)
 	{
		auto partial_result = (*iter).str(0);
		result.emplace_back(partial_result.begin(), std::find(partial_result.begin(), partial_result.end(), '='));
		result.emplace_back(std::next(std::find(partial_result.begin(), partial_result.end(), '"')), 
			std::prev((std::find(partial_result.rbegin(), partial_result.rend(), '"').base())));
 		++iter;
 	}


	return result;
}

std::vector<std::string> XMLBuilder::parseCloseElement(std::string element)
{
	std::vector<std::string> result;
	result.emplace_back(std::next(element.begin(), 2), std::prev(element.end()));
	return result;
}

std::vector<std::string> XMLBuilder::parseSingleElement(std::string element)
{
	std::vector<std::string> result;
	element = std::string(std::next(element.begin()), std::prev(element.end(),2));
	result.emplace_back(element.begin(), std::find(element.begin(), element.end(), ' '));
	std::regex attribPattern(R"([\S]*="[^"]*")");

	std::sregex_iterator iter(element.begin(), element.end(), attribPattern);
	std::sregex_iterator end;
	while (iter != end)
	{
		auto partial_result = (*iter).str(0);
		result.emplace_back(partial_result.begin(), std::find(partial_result.begin(), partial_result.end(), '='));
		result.emplace_back(std::next(std::find(partial_result.begin(), partial_result.end(), '"')),
			std::prev((std::find(partial_result.rbegin(), partial_result.rend(), '"').base())));
		++iter;
	}


	return result;
}

void XMLBuilder::addAttribs(std::vector<std::string> attribs)
{
	if ((attribs.size() % 2) != 0)
	{
		attribs.emplace_back("Error");
	}

	while (!attribs.empty())
	{
		auto value = attribs.back();
		attribs.pop_back();
		auto key = attribs.back();
		attribs.pop_back();
		m_parsingStack.top()->addAttrib(key, value);
	}
}

