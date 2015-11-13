#ifndef APSINSTANCES_H
#define APSINSTANCES_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ApsInstances;
typedef shared_ptr<ApsInstances> ApsInstancesPtr;
typedef vector<ApsInstancesPtr> ApsInstancesList;

class ApsInstances
{
	int id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	int customer_id;
	int package_id;
	int instance_status;
public:
	ApsInstances();
	ApsInstances(int id);
	void init();
	int getId() const;
	void setId(int value);
	long long getSysUserid() const;
	void setSysUserid(long long value);
	long long getSysGroupid() const;
	void setSysGroupid(long long value);
	std::string getSysPermUser() const;
	void setSysPermUser(std::string value);
	std::string getSysPermGroup() const;
	void setSysPermGroup(std::string value);
	std::string getSysPermOther() const;
	void setSysPermOther(std::string value);
	int getServerId() const;
	void setServerId(int value);
	int getCustomerId() const;
	void setCustomerId(int value);
	int getPackageId() const;
	void setPackageId(int value);
	int getInstanceStatus() const;
	void setInstanceStatus(int value);
};



#endif // APSINSTANCES_H
