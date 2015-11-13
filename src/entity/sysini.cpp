#include "sysini.h"

SysIni::SysIni(){
	init();
}
SysIni::SysIni(long long sysini_id)
{
	init();
	this->sysini_id = sysini_id;
}

void SysIni::init()
{
}
long long SysIni::getSysiniId() const
{
	return sysini_id;
}
void SysIni::setSysiniId(long long value)
{
	sysini_id = value;
}
std::string SysIni::getConfig() const
{
	return config;
}
void SysIni::setConfig(std::string value)
{
	config = value;
}

