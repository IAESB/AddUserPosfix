#include "helpfaq.h"

HelpFaq::HelpFaq(){
	init();
}
HelpFaq::HelpFaq(int hf_id)
{
	init();
	this->hf_id = hf_id;
}

void HelpFaq::init()
{
}
int HelpFaq::getHfId() const
{
	return hf_id;
}
void HelpFaq::setHfId(int value)
{
	hf_id = value;
}
int HelpFaq::getHfSection() const
{
	return hf_section;
}
void HelpFaq::setHfSection(int value)
{
	hf_section = value;
}
int HelpFaq::getHfOrder() const
{
	return hf_order;
}
void HelpFaq::setHfOrder(int value)
{
	hf_order = value;
}
std::string HelpFaq::getHfQuestion() const
{
	return hf_question;
}
void HelpFaq::setHfQuestion(std::string value)
{
	hf_question = value;
}
std::string HelpFaq::getHfAnswer() const
{
	return hf_answer;
}
void HelpFaq::setHfAnswer(std::string value)
{
	hf_answer = value;
}
int HelpFaq::getSysUserid() const
{
	return sys_userid;
}
void HelpFaq::setSysUserid(int value)
{
	sys_userid = value;
}
int HelpFaq::getSysGroupid() const
{
	return sys_groupid;
}
void HelpFaq::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string HelpFaq::getSysPermUser() const
{
	return sys_perm_user;
}
void HelpFaq::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string HelpFaq::getSysPermGroup() const
{
	return sys_perm_group;
}
void HelpFaq::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string HelpFaq::getSysPermOther() const
{
	return sys_perm_other;
}
void HelpFaq::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}

