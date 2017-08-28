#ifndef XMLDoc_h__
#define XMLDoc_h__
#include <string>
#include "XMLNode.h"
#include <memory>

class XMLDoc
{
public:
	XMLDoc();
	~XMLDoc();
	bool parse(const std::string &filepath);

private:
	std::string m_xmlVersion;
	std::string m_encoding;

	std::unique_ptr<XMLNode> rootNode;


};
#endif // XMLDoc_h__

