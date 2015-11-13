#ifndef SERVERPHP_H
#define SERVERPHP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ServerPhp;
typedef shared_ptr<ServerPhp> ServerPhpPtr;
typedef vector<ServerPhpPtr> ServerPhpList;

class ServerPhp
{
	long long server_php_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long client_id;
	std::string name;
	std::string php_fastcgi_binary;
	std::string php_fastcgi_ini_dir;
	std::string php_fpm_init_script;
	std::string php_fpm_ini_dir;
	std::string php_fpm_pool_dir;
public:
	ServerPhp();
	ServerPhp(long long server_php_id);
	void init();
	long long getServerPhpId() const;
	void setServerPhpId(long long value);
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
	long long getClientId() const;
	void setClientId(long long value);
	std::string getName() const;
	void setName(std::string value);
	std::string getPhpFastcgiBinary() const;
	void setPhpFastcgiBinary(std::string value);
	std::string getPhpFastcgiIniDir() const;
	void setPhpFastcgiIniDir(std::string value);
	std::string getPhpFpmInitScript() const;
	void setPhpFpmInitScript(std::string value);
	std::string getPhpFpmIniDir() const;
	void setPhpFpmIniDir(std::string value);
	std::string getPhpFpmPoolDir() const;
	void setPhpFpmPoolDir(std::string value);
};



#endif // SERVERPHP_H
