#include "cron.h"

Cron::Cron(){
	init();
}
Cron::Cron(long long id)
{
	init();
	this->id = id;
}

void Cron::init()
{
}
long long Cron::getId() const
{
	return id;
}
void Cron::setId(long long value)
{
	id = value;
}
long long Cron::getSysUserid() const
{
	return sys_userid;
}
void Cron::setSysUserid(long long value)
{
	sys_userid = value;
}
long long Cron::getSysGroupid() const
{
	return sys_groupid;
}
void Cron::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string Cron::getSysPermUser() const
{
	return sys_perm_user;
}
void Cron::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string Cron::getSysPermGroup() const
{
	return sys_perm_group;
}
void Cron::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string Cron::getSysPermOther() const
{
	return sys_perm_other;
}
void Cron::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long Cron::getServerId() const
{
	return server_id;
}
void Cron::setServerId(long long value)
{
	server_id = value;
}
long long Cron::getParentDomainId() const
{
	return parent_domain_id;
}
void Cron::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string Cron::getType() const
{
	return type;
}
void Cron::setType(std::string value)
{
	type = value;
}
std::string Cron::getCommand() const
{
	return command;
}
void Cron::setCommand(std::string value)
{
	command = value;
}
std::string Cron::getRunMin() const
{
	return run_min;
}
void Cron::setRunMin(std::string value)
{
	run_min = value;
}
std::string Cron::getRunHour() const
{
	return run_hour;
}
void Cron::setRunHour(std::string value)
{
	run_hour = value;
}
std::string Cron::getRunMday() const
{
	return run_mday;
}
void Cron::setRunMday(std::string value)
{
	run_mday = value;
}
std::string Cron::getRunMonth() const
{
	return run_month;
}
void Cron::setRunMonth(std::string value)
{
	run_month = value;
}
std::string Cron::getRunWday() const
{
	return run_wday;
}
void Cron::setRunWday(std::string value)
{
	run_wday = value;
}
std::string Cron::getLog() const
{
	return log;
}
void Cron::setLog(std::string value)
{
	log = value;
}
std::string Cron::getActive() const
{
	return active;
}
void Cron::setActive(std::string value)
{
	active = value;
}

