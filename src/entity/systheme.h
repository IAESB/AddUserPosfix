#ifndef SYSTHEME_H
#define SYSTHEME_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysTheme;
typedef shared_ptr<SysTheme> SysThemePtr;
typedef vector<SysThemePtr> SysThemeList;

class SysTheme
{
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long var_id; //key: PRI
	std::string tpl_name;
	std::string username;
	std::string logo_url;
public:
	SysTheme();
	SysTheme(long long var_id);
	void init();
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
	long long getVarId() const;
	void setVarId(long long value);
	std::string getTplName() const;
	void setTplName(std::string value);
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getLogoUrl() const;
	void setLogoUrl(std::string value);
};



#endif // SYSTHEME_H
