#ifndef SYSGROUP_H
#define SYSGROUP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysGroup;
typedef shared_ptr<SysGroup> SysGroupPtr;
typedef vector<SysGroupPtr> SysGroupList;

class SysGroup
{
	long long groupid; //key: PRI
	std::string name;
	std::string description;
	long long client_id;
public:
	SysGroup();
	SysGroup(long long groupid);
	void init();
	long long getGroupid() const;
	void setGroupid(long long value);
	std::string getName() const;
	void setName(std::string value);
	std::string getDescription() const;
	void setDescription(std::string value);
	long long getClientId() const;
	void setClientId(long long value);
};



#endif // SYSGROUP_H
