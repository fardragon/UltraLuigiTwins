#ifndef XMLDoc_h__
#define XMLDoc_h__
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <tuple>
#include "XMLNode.h"
#include "XMLBuilder.h"



class __declspec(dllexport) XMLDoc
{
public:
	XMLDoc();
	bool parseFromFile(const std::string &filepath);
	bool parseFromString(std::string data);
	void clear();

private:
	std::string m_xmlVersion;
	std::string m_encoding;

	std::unique_ptr<XMLNode> m_rootNode;


};
#endif // XMLDoc_h__

