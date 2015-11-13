#ifndef SHELLUSER_H
#define SHELLUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ShellUser;
typedef shared_ptr<ShellUser> ShellUserPtr;
typedef vector<ShellUserPtr> ShellUserList;

class ShellUser
{
	long long shell_user_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long parent_domain_id;
	std::string username;
	std::string username_prefix;
	std::string password;
	long long quota_size;
	std::string active;
	std::string puser;
	std::string pgroup;
	std::string shell;
	std::string dir;
	std::string chroot;
	std::string ssh_rsa;
public:
	ShellUser();
	ShellUser(long long shell_user_id);
	void init();
	long long getShellUserId() const;
	void setShellUserId(long long value);
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
	long long getParentDomainId() const;
	void setParentDomainId(long long value);
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getUsernamePrefix() const;
	void setUsernamePrefix(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	long long getQuotaSize() const;
	void setQuotaSize(long long value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getPuser() const;
	void setPuser(std::string value);
	std::string getPgroup() const;
	void setPgroup(std::string value);
	std::string getShell() const;
	void setShell(std::string value);
	std::string getDir() const;
	void setDir(std::string value);
	std::string getChroot() const;
	void setChroot(std::string value);
	std::string getSshRsa() const;
	void setSshRsa(std::string value);
};



#endif // SHELLUSER_H
