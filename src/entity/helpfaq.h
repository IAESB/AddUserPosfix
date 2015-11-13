#ifndef HELPFAQ_H
#define HELPFAQ_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class HelpFaq;
typedef shared_ptr<HelpFaq> HelpFaqPtr;
typedef vector<HelpFaqPtr> HelpFaqList;

class HelpFaq
{
	int hf_id; //key: PRI
	int hf_section;
	int hf_order;
	std::string hf_question;
	std::string hf_answer;
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
public:
	HelpFaq();
	HelpFaq(int hf_id);
	void init();
	int getHfId() const;
	void setHfId(int value);
	int getHfSection() const;
	void setHfSection(int value);
	int getHfOrder() const;
	void setHfOrder(int value);
	std::string getHfQuestion() const;
	void setHfQuestion(std::string value);
	std::string getHfAnswer() const;
	void setHfAnswer(std::string value);
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



#endif // HELPFAQ_H
