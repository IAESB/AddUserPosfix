#include "mailbackup.h"

MailBackup::MailBackup(){
	init();
}
MailBackup::MailBackup(long long backup_id)
{
	init();
	this->backup_id = backup_id;
}

void MailBackup::init()
{
}
long long MailBackup::getBackupId() const
{
	return backup_id;
}
void MailBackup::setBackupId(long long value)
{
	backup_id = value;
}
long long MailBackup::getServerId() const
{
	return server_id;
}
void MailBackup::setServerId(long long value)
{
	server_id = value;
}
long long MailBackup::getParentDomainId() const
{
	return parent_domain_id;
}
void MailBackup::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
long long MailBackup::getMailuserId() const
{
	return mailuser_id;
}
void MailBackup::setMailuserId(long long value)
{
	mailuser_id = value;
}
std::string MailBackup::getBackupMode() const
{
	return backup_mode;
}
void MailBackup::setBackupMode(std::string value)
{
	backup_mode = value;
}
long long MailBackup::getTstamp() const
{
	return tstamp;
}
void MailBackup::setTstamp(long long value)
{
	tstamp = value;
}
std::string MailBackup::getFilename() const
{
	return filename;
}
void MailBackup::setFilename(std::string value)
{
	filename = value;
}
std::string MailBackup::getFilesize() const
{
	return filesize;
}
void MailBackup::setFilesize(std::string value)
{
	filesize = value;
}

