#ifndef MAILGET_H
#define MAILGET_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailGet;
typedef shared_ptr<MailGet> MailGetPtr;
typedef vector<MailGetPtr> MailGetList;

class MailGet
{
	long long mailget_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	std::string type;
	std::string source_server;
	std::string source_username;
	std::string source_password;
	std::string source_delete;
	std::string source_read_all;
	std::string destination;
	std::string active;
public:
	MailGet();
	MailGet(long long mailget_id);
	void init();
	long long getMailgetId() const;
	void setMailgetId(long long value);
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
	long long getServerId() const;
	void setServerId(long long value);
	std::string getType() const;
	void setType(std::string value);
	std::string getSourceServer() const;
	void setSourceServer(std::string value);
	std::string getSourceUsername() const;
	void setSourceUsername(std::string value);
	std::string getSourcePassword() const;
	void setSourcePassword(std::string value);
	std::string getSourceDelete() const;
	void setSourceDelete(std::string value);
	std::string getSourceReadAll() const;
	void setSourceReadAll(std::string value);
	std::string getDestination() const;
	void setDestination(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILGET_H
