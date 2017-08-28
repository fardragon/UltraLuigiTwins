#include "XMLAttrib.h"



XMLAttrib::XMLAttrib(const std::string &key, const std::string &value):m_key(key), m_value(value), m_valid(false)
{

}

int XMLAttrib::asInt()
{
	try
	{
		int result = std::stoi(m_value);
		m_valid = true;
		return result;
	}
	catch (std::invalid_argument)
	{
		m_valid = false;
		return 0;
	}
	catch (std::out_of_range)
	{
		m_valid = false;
		return 0;
	}
}

std::string XMLAttrib::asString()
{
	m_valid = true;
	return m_value;
}

float XMLAttrib::asFloat()
{
	try
	{
		float result = std::stof(m_value);
		m_valid = true;
		return result;
	}
	catch (std::invalid_argument)
	{
		m_valid = false;
		return 0;
	}
	catch (std::out_of_range)
	{
		m_valid = false;
		return 0;
	}
}

bool XMLAttrib::isValid()
{
	return m_valid;
}

std::string XMLAttrib::getKey() const
{
	return m_key;
}
