#ifndef CLIENTMESSAGETEMPLATE_H
#define CLIENTMESSAGETEMPLATE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ClientMessageTemplate;
typedef shared_ptr<ClientMessageTemplate> ClientMessageTemplatePtr;
typedef vector<ClientMessageTemplatePtr> ClientMessageTemplateList;

class ClientMessageTemplate
{
	long long client_message_template_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string template_type;
	std::string template_name;
	std::string subject;
	std::string message;
public:
	ClientMessageTemplate();
	ClientMessageTemplate(long long client_message_template_id);
	void init();
	long long getClientMessageTemplateId() const;
	void setClientMessageTemplateId(long long value);
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
	std::string getTemplateType() const;
	void setTemplateType(std::string value);
	std::string getTemplateName() const;
	void setTemplateName(std::string value);
	std::string getSubject() const;
	void setSubject(std::string value);
	std::string getMessage() const;
	void setMessage(std::string value);
};



#endif // CLIENTMESSAGETEMPLATE_H
