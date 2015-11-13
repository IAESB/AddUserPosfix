#ifndef SYSCONFIG_H
#define SYSCONFIG_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysConfig;
typedef shared_ptr<SysConfig> SysConfigPtr;
typedef vector<SysConfigPtr> SysConfigList;

class SysConfig
{
	std::string group; //key: PRI
	std::string name; //key: PRI
	std::string value;
public:
	SysConfig();
	SysConfig(std::string group, std::string name);
	void init();
	std::string getGroup() const;
	void setGroup(std::string value);
	std::string getName() const;
	void setName(std::string value);
	std::string getValue() const;
	void setValue(std::string value);
};



#endif // SYSCONFIG_H
