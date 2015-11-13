#include "openvzvm.h"

OpenvzVm::OpenvzVm(){
	init();
}
OpenvzVm::OpenvzVm(long long vm_id)
{
	init();
	this->vm_id = vm_id;
}

void OpenvzVm::init()
{
	active_until_date = {0};
}
long long OpenvzVm::getVmId() const
{
	return vm_id;
}
void OpenvzVm::setVmId(long long value)
{
	vm_id = value;
}
int OpenvzVm::getSysUserid() const
{
	return sys_userid;
}
void OpenvzVm::setSysUserid(int value)
{
	sys_userid = value;
}
int OpenvzVm::getSysGroupid() const
{
	return sys_groupid;
}
void OpenvzVm::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string OpenvzVm::getSysPermUser() const
{
	return sys_perm_user;
}
void OpenvzVm::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string OpenvzVm::getSysPermGroup() const
{
	return sys_perm_group;
}
void OpenvzVm::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string OpenvzVm::getSysPermOther() const
{
	return sys_perm_other;
}
void OpenvzVm::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int OpenvzVm::getServerId() const
{
	return server_id;
}
void OpenvzVm::setServerId(int value)
{
	server_id = value;
}
long long OpenvzVm::getVeid() const
{
	return veid;
}
void OpenvzVm::setVeid(long long value)
{
	veid = value;
}
int OpenvzVm::getOstemplateId() const
{
	return ostemplate_id;
}
void OpenvzVm::setOstemplateId(int value)
{
	ostemplate_id = value;
}
int OpenvzVm::getTemplateId() const
{
	return template_id;
}
void OpenvzVm::setTemplateId(int value)
{
	template_id = value;
}
std::string OpenvzVm::getIpAddress() const
{
	return ip_address;
}
void OpenvzVm::setIpAddress(std::string value)
{
	ip_address = value;
}
std::string OpenvzVm::getHostname() const
{
	return hostname;
}
void OpenvzVm::setHostname(std::string value)
{
	hostname = value;
}
std::string OpenvzVm::getVmPassword() const
{
	return vm_password;
}
void OpenvzVm::setVmPassword(std::string value)
{
	vm_password = value;
}
std::string OpenvzVm::getStartBoot() const
{
	return start_boot;
}
void OpenvzVm::setStartBoot(std::string value)
{
	start_boot = value;
}
std::string OpenvzVm::getActive() const
{
	return active;
}
void OpenvzVm::setActive(std::string value)
{
	active = value;
}
tm OpenvzVm::getActiveUntilDate() const
{
	return active_until_date;
}
void OpenvzVm::setActiveUntilDate(tm value)
{
	active_until_date = value;
}
std::string OpenvzVm::getDescription() const
{
	return description;
}
void OpenvzVm::setDescription(std::string value)
{
	description = value;
}
int OpenvzVm::getDiskspace() const
{
	return diskspace;
}
void OpenvzVm::setDiskspace(int value)
{
	diskspace = value;
}
int OpenvzVm::getTraffic() const
{
	return traffic;
}
void OpenvzVm::setTraffic(int value)
{
	traffic = value;
}
int OpenvzVm::getBandwidth() const
{
	return bandwidth;
}
void OpenvzVm::setBandwidth(int value)
{
	bandwidth = value;
}
int OpenvzVm::getRam() const
{
	return ram;
}
void OpenvzVm::setRam(int value)
{
	ram = value;
}
int OpenvzVm::getRamBurst() const
{
	return ram_burst;
}
void OpenvzVm::setRamBurst(int value)
{
	ram_burst = value;
}
int OpenvzVm::getCpuUnits() const
{
	return cpu_units;
}
void OpenvzVm::setCpuUnits(int value)
{
	cpu_units = value;
}
int OpenvzVm::getCpuNum() const
{
	return cpu_num;
}
void OpenvzVm::setCpuNum(int value)
{
	cpu_num = value;
}
int OpenvzVm::getCpuLimit() const
{
	return cpu_limit;
}
void OpenvzVm::setCpuLimit(int value)
{
	cpu_limit = value;
}
int OpenvzVm::getIoPriority() const
{
	return io_priority;
}
void OpenvzVm::setIoPriority(int value)
{
	io_priority = value;
}
std::string OpenvzVm::getNameserver() const
{
	return nameserver;
}
void OpenvzVm::setNameserver(std::string value)
{
	nameserver = value;
}
std::string OpenvzVm::getCreateDns() const
{
	return create_dns;
}
void OpenvzVm::setCreateDns(std::string value)
{
	create_dns = value;
}
std::string OpenvzVm::getCapability() const
{
	return capability;
}
void OpenvzVm::setCapability(std::string value)
{
	capability = value;
}
std::string OpenvzVm::getConfig() const
{
	return config;
}
void OpenvzVm::setConfig(std::string value)
{
	config = value;
}

