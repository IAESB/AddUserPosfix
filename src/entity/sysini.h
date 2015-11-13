#ifndef SYSINI_H
#define SYSINI_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysIni;
typedef shared_ptr<SysIni> SysIniPtr;
typedef vector<SysIniPtr> SysIniList;

class SysIni
{
	long long sysini_id; //key: PRI
	std::string config;
public:
	SysIni();
	SysIni(long long sysini_id);
	void init();
	long long getSysiniId() const;
	void setSysiniId(long long value);
	std::string getConfig() const;
	void setConfig(std::string value);
};



#endif // SYSINI_H
