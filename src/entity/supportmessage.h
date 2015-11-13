#ifndef SUPPORTMESSAGE_H
#define SUPPORTMESSAGE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SupportMessage;
typedef shared_ptr<SupportMessage> SupportMessagePtr;
typedef vector<SupportMessagePtr> SupportMessageList;

class SupportMessage
{
	long long support_message_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long recipient_id;
	long long sender_id;
	std::string subject;
	std::string message;
	int tstamp;
public:
	SupportMessage();
	SupportMessage(long long support_message_id);
	void init();
	long long getSupportMessageId() const;
	void setSupportMessageId(long long value);
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
	long long getRecipientId() const;
	void setRecipientId(long long value);
	long long getSenderId() const;
	void setSenderId(long long value);
	std::string getSubject() const;
	void setSubject(std::string value);
	std::string getMessage() const;
	void setMessage(std::string value);
	int getTstamp() const;
	void setTstamp(int value);
};



#endif // SUPPORTMESSAGE_H
