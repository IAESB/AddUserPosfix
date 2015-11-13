#include "mailuser.h"

MailUser::MailUser(){
	init();
}
MailUser::MailUser(long long mailuser_id)
{
	init();
	this->mailuser_id = mailuser_id;
}

void MailUser::init()
{
	autoresponder_start_date = {0};
	autoresponder_end_date = {0};
	last_quota_notification = {0};
}
long long MailUser::getMailuserId() const
{
	return mailuser_id;
}
void MailUser::setMailuserId(long long value)
{
	mailuser_id = value;
}
long long MailUser::getSysUserid() const
{
	return sys_userid;
}
void MailUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailUser::getSysGroupid() const
{
	return sys_groupid;
}
void MailUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailUser::getSysPermUser() const
{
	return sys_perm_user;
}
void MailUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailUser::getSysPermOther() const
{
	return sys_perm_other;
}
void MailUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailUser::getServerId() const
{
	return server_id;
}
void MailUser::setServerId(long long value)
{
	server_id = value;
}
std::string MailUser::getEmail() const
{
	return email;
}
void MailUser::setEmail(std::string value)
{
	email = value;
}
std::string MailUser::getLogin() const
{
	return login;
}
void MailUser::setLogin(std::string value)
{
	login = value;
}
std::string MailUser::getPassword() const
{
	return password;
}
void MailUser::setPassword(std::string value)
{
	password = value;
}
std::string MailUser::getName() const
{
	return name;
}
void MailUser::setName(std::string value)
{
	name = value;
}
int MailUser::getUid() const
{
	return uid;
}
void MailUser::setUid(int value)
{
	uid = value;
}
int MailUser::getGid() const
{
	return gid;
}
void MailUser::setGid(int value)
{
	gid = value;
}
std::string MailUser::getMaildir() const
{
	return maildir;
}
void MailUser::setMaildir(std::string value)
{
	maildir = value;
}
long long MailUser::getQuota() const
{
	return quota;
}
void MailUser::setQuota(long long value)
{
	quota = value;
}
std::string MailUser::getCc() const
{
	return cc;
}
void MailUser::setCc(std::string value)
{
	cc = value;
}
std::string MailUser::getHomedir() const
{
	return homedir;
}
void MailUser::setHomedir(std::string value)
{
	homedir = value;
}
std::string MailUser::getAutoresponder() const
{
	return autoresponder;
}
void MailUser::setAutoresponder(std::string value)
{
	autoresponder = value;
}
tm MailUser::getAutoresponderStartDate() const
{
	return autoresponder_start_date;
}
void MailUser::setAutoresponderStartDate(tm value)
{
	autoresponder_start_date = value;
}
tm MailUser::getAutoresponderEndDate() const
{
	return autoresponder_end_date;
}
void MailUser::setAutoresponderEndDate(tm value)
{
	autoresponder_end_date = value;
}
std::string MailUser::getAutoresponderSubject() const
{
	return autoresponder_subject;
}
void MailUser::setAutoresponderSubject(std::string value)
{
	autoresponder_subject = value;
}
std::string MailUser::getAutoresponderText() const
{
	return autoresponder_text;
}
void MailUser::setAutoresponderText(std::string value)
{
	autoresponder_text = value;
}
std::string MailUser::getMoveJunk() const
{
	return move_junk;
}
void MailUser::setMoveJunk(std::string value)
{
	move_junk = value;
}
std::string MailUser::getCustomMailfilter() const
{
	return custom_mailfilter;
}
void MailUser::setCustomMailfilter(std::string value)
{
	custom_mailfilter = value;
}
std::string MailUser::getPostfix() const
{
	return postfix;
}
void MailUser::setPostfix(std::string value)
{
	postfix = value;
}
std::string MailUser::getAccess() const
{
	return access;
}
void MailUser::setAccess(std::string value)
{
	access = value;
}
std::string MailUser::getDisableimap() const
{
	return disableimap;
}
void MailUser::setDisableimap(std::string value)
{
	disableimap = value;
}
std::string MailUser::getDisablepop3() const
{
	return disablepop3;
}
void MailUser::setDisablepop3(std::string value)
{
	disablepop3 = value;
}
std::string MailUser::getDisabledeliver() const
{
	return disabledeliver;
}
void MailUser::setDisabledeliver(std::string value)
{
	disabledeliver = value;
}
std::string MailUser::getDisablesmtp() const
{
	return disablesmtp;
}
void MailUser::setDisablesmtp(std::string value)
{
	disablesmtp = value;
}
std::string MailUser::getDisablesieve() const
{
	return disablesieve;
}
void MailUser::setDisablesieve(std::string value)
{
	disablesieve = value;
}
std::string MailUser::getDisablesieveFilter() const
{
	return disablesieve_filter;
}
void MailUser::setDisablesieveFilter(std::string value)
{
	disablesieve_filter = value;
}
std::string MailUser::getDisablelda() const
{
	return disablelda;
}
void MailUser::setDisablelda(std::string value)
{
	disablelda = value;
}
std::string MailUser::getDisablelmtp() const
{
	return disablelmtp;
}
void MailUser::setDisablelmtp(std::string value)
{
	disablelmtp = value;
}
std::string MailUser::getDisabledoveadm() const
{
	return disabledoveadm;
}
void MailUser::setDisabledoveadm(std::string value)
{
	disabledoveadm = value;
}
tm MailUser::getLastQuotaNotification() const
{
	return last_quota_notification;
}
void MailUser::setLastQuotaNotification(tm value)
{
	last_quota_notification = value;
}
std::string MailUser::getBackupInterval() const
{
	return backup_interval;
}
void MailUser::setBackupInterval(std::string value)
{
	backup_interval = value;
}
int MailUser::getBackupCopies() const
{
	return backup_copies;
}
void MailUser::setBackupCopies(int value)
{
	backup_copies = value;
}

