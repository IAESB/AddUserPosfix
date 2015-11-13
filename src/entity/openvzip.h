#ifndef OPENVZIP_H
#define OPENVZIP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class OpenvzIp;
typedef shared_ptr<OpenvzIp> OpenvzIpPtr;
typedef vector<OpenvzIpPtr> OpenvzIpList;

class OpenvzIp
{
	long long ip_address_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	std::string ip_address;
	int vm_id;
	std::string reserved;
public:
	OpenvzIp();
	OpenvzIp(long long ip_address_id);
	void init();
	long long getIpAddressId() const;
	void setIpAddressId(long long value);
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
	std::string getIpAddress() const;
	void setIpAddress(std::string value);
	int getVmId() const;
	void setVmId(int value);
	std::string getReserved() const;
	void setReserved(std::string value);
};



#endif // OPENVZIP_H
