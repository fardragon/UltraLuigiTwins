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
	XMLNode(const std::string &name);
	XMLAttrib operator[](const std::string &index) const;
	XMLNode *const addChild(const std::string &name);
	void addAttrib(const std::string &key, const std::string &value);
	std::string getName();

private:
	std::string m_name;
	std::vector<XMLAttrib> m_attribs;
	std::vector<std::unique_ptr<XMLNode>> m_childNodes;

public:
	static const XMLAttrib error;



};



#endif // XMLNode_h__

