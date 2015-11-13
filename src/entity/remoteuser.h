#ifndef REMOTEUSER_H
#define REMOTEUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class RemoteUser;
typedef shared_ptr<RemoteUser> RemoteUserPtr;
typedef vector<RemoteUserPtr> RemoteUserList;

class RemoteUser
{
	long long remote_userid; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string remote_username;
	std::string remote_password;
	std::string remote_functions;
public:
	RemoteUser();
	RemoteUser(long long remote_userid);
	void init();
	long long getRemoteUserid() const;
	void setRemoteUserid(long long value);
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
	std::string getRemoteUsername() const;
	void setRemoteUsername(std::string value);
	std::string getRemotePassword() const;
	void setRemotePassword(std::string value);
	std::string getRemoteFunctions() const;
	void setRemoteFunctions(std::string value);
};



#endif // REMOTEUSER_H
