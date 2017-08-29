#include "XMLNode.h"

const XMLAttrib XMLNode::error = XMLAttrib("error", "error");


XMLNode::XMLNode(const std::string & name): m_name(name)
{
}

XMLAttrib XMLNode::operator[](const std::string & index) const
{
	auto result = std::find_if(m_attribs.begin(), m_attribs.end(), [&index](const XMLAttrib &at)->bool {return at.getKey() == index; });
	if (result != m_attribs.end())
	{
		return *result;
	}
	return XMLNode::error;

}

XMLNode * const XMLNode::addChild(const std::string & name)
{
	m_childNodes.push_back(std::make_unique<XMLNode>(name));
	return m_childNodes.back().get();
}

void XMLNode::addAttrib(const std::string &key, const std::string &value)
{
	m_attribs.emplace_back(key, value);
}

std::string XMLNode::getName()
{
	return m_name;
}
