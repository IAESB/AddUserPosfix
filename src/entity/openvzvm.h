#ifndef OPENVZVM_H
#define OPENVZVM_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class OpenvzVm;
typedef shared_ptr<OpenvzVm> OpenvzVmPtr;
typedef vector<OpenvzVmPtr> OpenvzVmList;

class OpenvzVm
{
	long long vm_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	long long veid;
	int ostemplate_id;
	int template_id;
	std::string ip_address;
	std::string hostname;
	std::string vm_password;
	std::string start_boot;
	std::string active;
	tm active_until_date;
	std::string description;
	int diskspace;
	int traffic;
	int bandwidth;
	int ram;
	int ram_burst;
	int cpu_units;
	int cpu_num;
	int cpu_limit;
	int io_priority;
	std::string nameserver;
	std::string create_dns;
	std::string capability;
	std::string config;
public:
	OpenvzVm();
	OpenvzVm(long long vm_id);
	void init();
	long long getVmId() const;
	void setVmId(long long value);
	int getSysUserid() const;
	void setSysUserid(int value);
	int getSysGroupid() const;
	void setSysGroupid(int value);
	std::string getSysPermUser() const;
	void setSysPermUser(std::string value);
	std::string getSysPermGroup() const;
	void setSysPermGroup(std::string value);
	std::string getSysPermOther() const;
	void setSysPermOther(std::string value);
	int getServerId() const;
	void setServerId(int value);
	long long getVeid() const;
	void setVeid(long long value);
	int getOstemplateId() const;
	void setOstemplateId(int value);
	int getTemplateId() const;
	void setTemplateId(int value);
	std::string getIpAddress() const;
	void setIpAddress(std::string value);
	std::string getHostname() const;
	void setHostname(std::string value);
	std::string getVmPassword() const;
	void setVmPassword(std::string value);
	std::string getStartBoot() const;
	void setStartBoot(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
	tm getActiveUntilDate() const;
	void setActiveUntilDate(tm value);
	std::string getDescription() const;
	void setDescription(std::string value);
	int getDiskspace() const;
	void setDiskspace(int value);
	int getTraffic() const;
	void setTraffic(int value);
	int getBandwidth() const;
	void setBandwidth(int value);
	int getRam() const;
	void setRam(int value);
	int getRamBurst() const;
	void setRamBurst(int value);
	int getCpuUnits() const;
	void setCpuUnits(int value);
	int getCpuNum() const;
	void setCpuNum(int value);
	int getCpuLimit() const;
	void setCpuLimit(int value);
	int getIoPriority() const;
	void setIoPriority(int value);
	std::string getNameserver() const;
	void setNameserver(std::string value);
	std::string getCreateDns() const;
	void setCreateDns(std::string value);
	std::string getCapability() const;
	void setCapability(std::string value);
	std::string getConfig() const;
	void setConfig(std::string value);
};



#endif // OPENVZVM_H
