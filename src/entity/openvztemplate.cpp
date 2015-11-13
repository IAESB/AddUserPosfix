#include "openvztemplate.h"

OpenvzTemplate::OpenvzTemplate(){
	init();
}
OpenvzTemplate::OpenvzTemplate(long long template_id)
{
	init();
	this->template_id = template_id;
}

void OpenvzTemplate::init()
{
}
long long OpenvzTemplate::getTemplateId() const
{
	return template_id;
}
void OpenvzTemplate::setTemplateId(long long value)
{
	template_id = value;
}
int OpenvzTemplate::getSysUserid() const
{
	return sys_userid;
}
void OpenvzTemplate::setSysUserid(int value)
{
	sys_userid = value;
}
int OpenvzTemplate::getSysGroupid() const
{
	return sys_groupid;
}
void OpenvzTemplate::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string OpenvzTemplate::getSysPermUser() const
{
	return sys_perm_user;
}
void OpenvzTemplate::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string OpenvzTemplate::getSysPermGroup() const
{
	return sys_perm_group;
}
void OpenvzTemplate::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string OpenvzTemplate::getSysPermOther() const
{
	return sys_perm_other;
}
void OpenvzTemplate::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string OpenvzTemplate::getTemplateName() const
{
	return template_name;
}
void OpenvzTemplate::setTemplateName(std::string value)
{
	template_name = value;
}
int OpenvzTemplate::getDiskspace() const
{
	return diskspace;
}
void OpenvzTemplate::setDiskspace(int value)
{
	diskspace = value;
}
int OpenvzTemplate::getTraffic() const
{
	return traffic;
}
void OpenvzTemplate::setTraffic(int value)
{
	traffic = value;
}
int OpenvzTemplate::getBandwidth() const
{
	return bandwidth;
}
void OpenvzTemplate::setBandwidth(int value)
{
	bandwidth = value;
}
int OpenvzTemplate::getRam() const
{
	return ram;
}
void OpenvzTemplate::setRam(int value)
{
	ram = value;
}
int OpenvzTemplate::getRamBurst() const
{
	return ram_burst;
}
void OpenvzTemplate::setRamBurst(int value)
{
	ram_burst = value;
}
int OpenvzTemplate::getCpuUnits() const
{
	return cpu_units;
}
void OpenvzTemplate::setCpuUnits(int value)
{
	cpu_units = value;
}
int OpenvzTemplate::getCpuNum() const
{
	return cpu_num;
}
void OpenvzTemplate::setCpuNum(int value)
{
	cpu_num = value;
}
int OpenvzTemplate::getCpuLimit() const
{
	return cpu_limit;
}
void OpenvzTemplate::setCpuLimit(int value)
{
	cpu_limit = value;
}
int OpenvzTemplate::getIoPriority() const
{
	return io_priority;
}
void OpenvzTemplate::setIoPriority(int value)
{
	io_priority = value;
}
std::string OpenvzTemplate::getActive() const
{
	return active;
}
void OpenvzTemplate::setActive(std::string value)
{
	active = value;
}
std::string OpenvzTemplate::getDescription() const
{
	return description;
}
void OpenvzTemplate::setDescription(std::string value)
{
	description = value;
}
std::string OpenvzTemplate::getNumproc() const
{
	return numproc;
}
void OpenvzTemplate::setNumproc(std::string value)
{
	numproc = value;
}
std::string OpenvzTemplate::getNumtcpsock() const
{
	return numtcpsock;
}
void OpenvzTemplate::setNumtcpsock(std::string value)
{
	numtcpsock = value;
}
std::string OpenvzTemplate::getNumothersock() const
{
	return numothersock;
}
void OpenvzTemplate::setNumothersock(std::string value)
{
	numothersock = value;
}
std::string OpenvzTemplate::getVmguarpages() const
{
	return vmguarpages;
}
void OpenvzTemplate::setVmguarpages(std::string value)
{
	vmguarpages = value;
}
std::string OpenvzTemplate::getKmemsize() const
{
	return kmemsize;
}
void OpenvzTemplate::setKmemsize(std::string value)
{
	kmemsize = value;
}
std::string OpenvzTemplate::getTcpsndbuf() const
{
	return tcpsndbuf;
}
void OpenvzTemplate::setTcpsndbuf(std::string value)
{
	tcpsndbuf = value;
}
std::string OpenvzTemplate::getTcprcvbuf() const
{
	return tcprcvbuf;
}
void OpenvzTemplate::setTcprcvbuf(std::string value)
{
	tcprcvbuf = value;
}
std::string OpenvzTemplate::getOthersockbuf() const
{
	return othersockbuf;
}
void OpenvzTemplate::setOthersockbuf(std::string value)
{
	othersockbuf = value;
}
std::string OpenvzTemplate::getDgramrcvbuf() const
{
	return dgramrcvbuf;
}
void OpenvzTemplate::setDgramrcvbuf(std::string value)
{
	dgramrcvbuf = value;
}
std::string OpenvzTemplate::getOomguarpages() const
{
	return oomguarpages;
}
void OpenvzTemplate::setOomguarpages(std::string value)
{
	oomguarpages = value;
}
std::string OpenvzTemplate::getPrivvmpages() const
{
	return privvmpages;
}
void OpenvzTemplate::setPrivvmpages(std::string value)
{
	privvmpages = value;
}
std::string OpenvzTemplate::getLockedpages() const
{
	return lockedpages;
}
void OpenvzTemplate::setLockedpages(std::string value)
{
	lockedpages = value;
}
std::string OpenvzTemplate::getShmpages() const
{
	return shmpages;
}
void OpenvzTemplate::setShmpages(std::string value)
{
	shmpages = value;
}
std::string OpenvzTemplate::getPhyspages() const
{
	return physpages;
}
void OpenvzTemplate::setPhyspages(std::string value)
{
	physpages = value;
}
std::string OpenvzTemplate::getNumfile() const
{
	return numfile;
}
void OpenvzTemplate::setNumfile(std::string value)
{
	numfile = value;
}
std::string OpenvzTemplate::getAvnumproc() const
{
	return avnumproc;
}
void OpenvzTemplate::setAvnumproc(std::string value)
{
	avnumproc = value;
}
std::string OpenvzTemplate::getNumflock() const
{
	return numflock;
}
void OpenvzTemplate::setNumflock(std::string value)
{
	numflock = value;
}
std::string OpenvzTemplate::getNumpty() const
{
	return numpty;
}
void OpenvzTemplate::setNumpty(std::string value)
{
	numpty = value;
}
std::string OpenvzTemplate::getNumsiginfo() const
{
	return numsiginfo;
}
void OpenvzTemplate::setNumsiginfo(std::string value)
{
	numsiginfo = value;
}
std::string OpenvzTemplate::getDcachesize() const
{
	return dcachesize;
}
void OpenvzTemplate::setDcachesize(std::string value)
{
	dcachesize = value;
}
std::string OpenvzTemplate::getNumiptent() const
{
	return numiptent;
}
void OpenvzTemplate::setNumiptent(std::string value)
{
	numiptent = value;
}
std::string OpenvzTemplate::getSwappages() const
{
	return swappages;
}
void OpenvzTemplate::setSwappages(std::string value)
{
	swappages = value;
}
std::string OpenvzTemplate::getHostname() const
{
	return hostname;
}
void OpenvzTemplate::setHostname(std::string value)
{
	hostname = value;
}
std::string OpenvzTemplate::getNameserver() const
{
	return nameserver;
}
void OpenvzTemplate::setNameserver(std::string value)
{
	nameserver = value;
}
std::string OpenvzTemplate::getCreateDns() const
{
	return create_dns;
}
void OpenvzTemplate::setCreateDns(std::string value)
{
	create_dns = value;
}
std::string OpenvzTemplate::getCapability() const
{
	return capability;
}
void OpenvzTemplate::setCapability(std::string value)
{
	capability = value;
}

