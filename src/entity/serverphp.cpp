#include "serverphp.h"

ServerPhp::ServerPhp(){
	init();
}
ServerPhp::ServerPhp(long long server_php_id)
{
	init();
	this->server_php_id = server_php_id;
}

void ServerPhp::init()
{
}
long long ServerPhp::getServerPhpId() const
{
	return server_php_id;
}
void ServerPhp::setServerPhpId(long long value)
{
	server_php_id = value;
}
long long ServerPhp::getSysUserid() const
{
	return sys_userid;
}
void ServerPhp::setSysUserid(long long value)
{
	sys_userid = value;
}
long long ServerPhp::getSysGroupid() const
{
	return sys_groupid;
}
void ServerPhp::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string ServerPhp::getSysPermUser() const
{
	return sys_perm_user;
}
void ServerPhp::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ServerPhp::getSysPermGroup() const
{
	return sys_perm_group;
}
void ServerPhp::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ServerPhp::getSysPermOther() const
{
	return sys_perm_other;
}
void ServerPhp::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long ServerPhp::getServerId() const
{
	return server_id;
}
void ServerPhp::setServerId(long long value)
{
	server_id = value;
}
long long ServerPhp::getClientId() const
{
	return client_id;
}
void ServerPhp::setClientId(long long value)
{
	client_id = value;
}
std::string ServerPhp::getName() const
{
	return name;
}
void ServerPhp::setName(std::string value)
{
	name = value;
}
std::string ServerPhp::getPhpFastcgiBinary() const
{
	return php_fastcgi_binary;
}
void ServerPhp::setPhpFastcgiBinary(std::string value)
{
	php_fastcgi_binary = value;
}
std::string ServerPhp::getPhpFastcgiIniDir() const
{
	return php_fastcgi_ini_dir;
}
void ServerPhp::setPhpFastcgiIniDir(std::string value)
{
	php_fastcgi_ini_dir = value;
}
std::string ServerPhp::getPhpFpmInitScript() const
{
	return php_fpm_init_script;
}
void ServerPhp::setPhpFpmInitScript(std::string value)
{
	php_fpm_init_script = value;
}
std::string ServerPhp::getPhpFpmIniDir() const
{
	return php_fpm_ini_dir;
}
void ServerPhp::setPhpFpmIniDir(std::string value)
{
	php_fpm_ini_dir = value;
}
std::string ServerPhp::getPhpFpmPoolDir() const
{
	return php_fpm_pool_dir;
}
void ServerPhp::setPhpFpmPoolDir(std::string value)
{
	php_fpm_pool_dir = value;
}

