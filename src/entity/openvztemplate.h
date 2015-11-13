#ifndef OPENVZTEMPLATE_H
#define OPENVZTEMPLATE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class OpenvzTemplate;
typedef shared_ptr<OpenvzTemplate> OpenvzTemplatePtr;
typedef vector<OpenvzTemplatePtr> OpenvzTemplateList;

class OpenvzTemplate
{
	long long template_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string template_name;
	int diskspace;
	int traffic;
	int bandwidth;
	int ram;
	int ram_burst;
	int cpu_units;
	int cpu_num;
	int cpu_limit;
	int io_priority;
	std::string active;
	std::string description;
	std::string numproc;
	std::string numtcpsock;
	std::string numothersock;
	std::string vmguarpages;
	std::string kmemsize;
	std::string tcpsndbuf;
	std::string tcprcvbuf;
	std::string othersockbuf;
	std::string dgramrcvbuf;
	std::string oomguarpages;
	std::string privvmpages;
	std::string lockedpages;
	std::string shmpages;
	std::string physpages;
	std::string numfile;
	std::string avnumproc;
	std::string numflock;
	std::string numpty;
	std::string numsiginfo;
	std::string dcachesize;
	std::string numiptent;
	std::string swappages;
	std::string hostname;
	std::string nameserver;
	std::string create_dns;
	std::string capability;
public:
	OpenvzTemplate();
	OpenvzTemplate(long long template_id);
	void init();
	long long getTemplateId() const;
	void setTemplateId(long long value);
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
	std::string getTemplateName() const;
	void setTemplateName(std::string value);
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
	std::string getActive() const;
	void setActive(std::string value);
	std::string getDescription() const;
	void setDescription(std::string value);
	std::string getNumproc() const;
	void setNumproc(std::string value);
	std::string getNumtcpsock() const;
	void setNumtcpsock(std::string value);
	std::string getNumothersock() const;
	void setNumothersock(std::string value);
	std::string getVmguarpages() const;
	void setVmguarpages(std::string value);
	std::string getKmemsize() const;
	void setKmemsize(std::string value);
	std::string getTcpsndbuf() const;
	void setTcpsndbuf(std::string value);
	std::string getTcprcvbuf() const;
	void setTcprcvbuf(std::string value);
	std::string getOthersockbuf() const;
	void setOthersockbuf(std::string value);
	std::string getDgramrcvbuf() const;
	void setDgramrcvbuf(std::string value);
	std::string getOomguarpages() const;
	void setOomguarpages(std::string value);
	std::string getPrivvmpages() const;
	void setPrivvmpages(std::string value);
	std::string getLockedpages() const;
	void setLockedpages(std::string value);
	std::string getShmpages() const;
	void setShmpages(std::string value);
	std::string getPhyspages() const;
	void setPhyspages(std::string value);
	std::string getNumfile() const;
	void setNumfile(std::string value);
	std::string getAvnumproc() const;
	void setAvnumproc(std::string value);
	std::string getNumflock() const;
	void setNumflock(std::string value);
	std::string getNumpty() const;
	void setNumpty(std::string value);
	std::string getNumsiginfo() const;
	void setNumsiginfo(std::string value);
	std::string getDcachesize() const;
	void setDcachesize(std::string value);
	std::string getNumiptent() const;
	void setNumiptent(std::string value);
	std::string getSwappages() const;
	void setSwappages(std::string value);
	std::string getHostname() const;
	void setHostname(std::string value);
	std::string getNameserver() const;
	void setNameserver(std::string value);
	std::string getCreateDns() const;
	void setCreateDns(std::string value);
	std::string getCapability() const;
	void setCapability(std::string value);
};



#endif // OPENVZTEMPLATE_H
