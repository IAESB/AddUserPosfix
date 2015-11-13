#include "helpfaqsections.h"

HelpFaqSections::HelpFaqSections(){
	init();
}
HelpFaqSections::HelpFaqSections(int hfs_id)
{
	init();
	this->hfs_id = hfs_id;
}

void HelpFaqSections::init()
{
}
int HelpFaqSections::getHfsId() const
{
	return hfs_id;
}
void HelpFaqSections::setHfsId(int value)
{
	hfs_id = value;
}
std::string HelpFaqSections::getHfsName() const
{
	return hfs_name;
}
void HelpFaqSections::setHfsName(std::string value)
{
	hfs_name = value;
}
int HelpFaqSections::getHfsOrder() const
{
	return hfs_order;
}
void HelpFaqSections::setHfsOrder(int value)
{
	hfs_order = value;
}
int HelpFaqSections::getSysUserid() const
{
	return sys_userid;
}
void HelpFaqSections::setSysUserid(int value)
{
	sys_userid = value;
}
int HelpFaqSections::getSysGroupid() const
{
	return sys_groupid;
}
void HelpFaqSections::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string HelpFaqSections::getSysPermUser() const
{
	return sys_perm_user;
}
void HelpFaqSections::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string HelpFaqSections::getSysPermGroup() const
{
	return sys_perm_group;
}
void HelpFaqSections::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string HelpFaqSections::getSysPermOther() const
{
	return sys_perm_other;
}
void HelpFaqSections::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}

