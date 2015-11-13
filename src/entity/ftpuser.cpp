#include "ftpuser.h"

FtpUser::FtpUser(){
	init();
}
FtpUser::FtpUser(long long ftp_user_id)
{
	init();
	this->ftp_user_id = ftp_user_id;
}

void FtpUser::init()
{
	expires = {0};
}
long long FtpUser::getFtpUserId() const
{
	return ftp_user_id;
}
void FtpUser::setFtpUserId(long long value)
{
	ftp_user_id = value;
}
long long FtpUser::getSysUserid() const
{
	return sys_userid;
}
void FtpUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long FtpUser::getSysGroupid() const
{
	return sys_groupid;
}
void FtpUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string FtpUser::getSysPermUser() const
{
	return sys_perm_user;
}
void FtpUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string FtpUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void FtpUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string FtpUser::getSysPermOther() const
{
	return sys_perm_other;
}
void FtpUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long FtpUser::getServerId() const
{
	return server_id;
}
void FtpUser::setServerId(long long value)
{
	server_id = value;
}
long long FtpUser::getParentDomainId() const
{
	return parent_domain_id;
}
void FtpUser::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string FtpUser::getUsername() const
{
	return username;
}
void FtpUser::setUsername(std::string value)
{
	username = value;
}
std::string FtpUser::getUsernamePrefix() const
{
	return username_prefix;
}
void FtpUser::setUsernamePrefix(std::string value)
{
	username_prefix = value;
}
std::string FtpUser::getPassword() const
{
	return password;
}
void FtpUser::setPassword(std::string value)
{
	password = value;
}
long long FtpUser::getQuotaSize() const
{
	return quota_size;
}
void FtpUser::setQuotaSize(long long value)
{
	quota_size = value;
}
std::string FtpUser::getActive() const
{
	return active;
}
void FtpUser::setActive(std::string value)
{
	active = value;
}
std::string FtpUser::getUid() const
{
	return uid;
}
void FtpUser::setUid(std::string value)
{
	uid = value;
}
std::string FtpUser::getGid() const
{
	return gid;
}
void FtpUser::setGid(std::string value)
{
	gid = value;
}
std::string FtpUser::getDir() const
{
	return dir;
}
void FtpUser::setDir(std::string value)
{
	dir = value;
}
long long FtpUser::getQuotaFiles() const
{
	return quota_files;
}
void FtpUser::setQuotaFiles(long long value)
{
	quota_files = value;
}
int FtpUser::getUlRatio() const
{
	return ul_ratio;
}
void FtpUser::setUlRatio(int value)
{
	ul_ratio = value;
}
int FtpUser::getDlRatio() const
{
	return dl_ratio;
}
void FtpUser::setDlRatio(int value)
{
	dl_ratio = value;
}
int FtpUser::getUlBandwidth() const
{
	return ul_bandwidth;
}
void FtpUser::setUlBandwidth(int value)
{
	ul_bandwidth = value;
}
int FtpUser::getDlBandwidth() const
{
	return dl_bandwidth;
}
void FtpUser::setDlBandwidth(int value)
{
	dl_bandwidth = value;
}
tm FtpUser::getExpires() const
{
	return expires;
}
void FtpUser::setExpires(tm value)
{
	expires = value;
}

