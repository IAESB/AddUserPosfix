#ifndef SYSUSER_H
#define SYSUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysUser;
typedef shared_ptr<SysUser> SysUserPtr;
typedef vector<SysUserPtr> SysUserList;

class SysUser
{
	long long userid; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string username;
	std::string passwort;
	std::string modules;
	std::string startmodule;
	std::string app_theme;
	std::string typ;
	int active;
	std::string language;
	std::string groups;
	long long default_group;
	long long client_id;
	std::string id_rsa;
	std::string ssh_rsa;
public:
	SysUser();
	SysUser(long long userid);
	void init();
	long long getUserid() const;
	void setUserid(long long value);
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
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getPasswort() const;
	void setPasswort(std::string value);
	std::string getModules() const;
	void setModules(std::string value);
	std::string getStartmodule() const;
	void setStartmodule(std::string value);
	std::string getAppTheme() const;
	void setAppTheme(std::string value);
	std::string getTyp() const;
	void setTyp(std::string value);
	int getActive() const;
	void setActive(int value);
	std::string getLanguage() const;
	void setLanguage(std::string value);
	std::string getGroups() const;
	void setGroups(std::string value);
	long long getDefaultGroup() const;
	void setDefaultGroup(long long value);
	long long getClientId() const;
	void setClientId(long long value);
	std::string getIdRsa() const;
	void setIdRsa(std::string value);
	std::string getSshRsa() const;
	void setSshRsa(std::string value);
};



#endif // SYSUSER_H
