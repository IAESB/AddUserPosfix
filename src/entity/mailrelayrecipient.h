#ifndef MAILRELAYRECIPIENT_H
#define MAILRELAYRECIPIENT_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailRelayRecipient;
typedef shared_ptr<MailRelayRecipient> MailRelayRecipientPtr;
typedef vector<MailRelayRecipientPtr> MailRelayRecipientList;

class MailRelayRecipient
{
	long long relay_recipient_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	std::string source;
	std::string access;
	std::string active;
public:
	MailRelayRecipient();
	MailRelayRecipient(long long relay_recipient_id);
	void init();
	long long getRelayRecipientId() const;
	void setRelayRecipientId(long long value);
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
	std::string getSource() const;
	void setSource(std::string value);
	std::string getAccess() const;
	void setAccess(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILRELAYRECIPIENT_H
