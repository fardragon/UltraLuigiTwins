#ifndef XMLNode_h__
#define XMLNode_h__
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "XMLAttrib.h"

class XMLNode
{
public:
	XMLNode();
	~XMLNode();
	XMLAttrib operator[](const std::string &index) const;

private:
	std::string m_name;
	std::vector<XMLAttrib> m_attribs;
	std::vector<std::unique_ptr<XMLNode>> m_childNodes;

public:
	static const XMLAttrib error;



};



#endif // XMLNode_h__

