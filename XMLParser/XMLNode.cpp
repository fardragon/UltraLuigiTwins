#include "XMLNode.h"

const XMLAttrib XMLNode::error = XMLAttrib("error", "error");

XMLNode::XMLNode()
{
}


XMLNode::~XMLNode()
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
