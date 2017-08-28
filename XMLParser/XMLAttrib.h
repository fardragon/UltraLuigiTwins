#ifndef XMLAttrib_h__
#define XMLAttrib_h__
#include <string>
#include <exception>

class XMLAttrib
{
public:
	XMLAttrib(const std::string &key, const std::string &value);

	int asInt();
	std::string asString();
	float asFloat();
	bool isValid();
	std::string getKey() const;

private:
	std::string m_key;
	std::string m_value;
	bool m_valid;
};
#endif // XMLAttrib_h__

