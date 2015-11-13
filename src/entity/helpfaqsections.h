#ifndef HELPFAQSECTIONS_H
#define HELPFAQSECTIONS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class HelpFaqSections;
typedef shared_ptr<HelpFaqSections> HelpFaqSectionsPtr;
typedef vector<HelpFaqSectionsPtr> HelpFaqSectionsList;

class HelpFaqSections
{
	int hfs_id; //key: PRI
	std::string hfs_name;
	int hfs_order;
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
public:
	HelpFaqSections();
	HelpFaqSections(int hfs_id);
	void init();
	int getHfsId() const;
	void setHfsId(int value);
	std::string getHfsName() const;
	void setHfsName(std::string value);
	int getHfsOrder() const;
	void setHfsOrder(int value);
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
};



#endif // HELPFAQSECTIONS_H
