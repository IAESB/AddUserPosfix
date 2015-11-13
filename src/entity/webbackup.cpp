#include "webbackup.h"

WebBackup::WebBackup(){
	init();
}
WebBackup::WebBackup(long long backup_id)
{
	init();
	this->backup_id = backup_id;
}

void WebBackup::init()
{
}
long long WebBackup::getBackupId() const
{
	return backup_id;
}
void WebBackup::setBackupId(long long value)
{
	backup_id = value;
}
long long WebBackup::getServerId() const
{
	return server_id;
}
void WebBackup::setServerId(long long value)
{
	server_id = value;
}
long long WebBackup::getParentDomainId() const
{
	return parent_domain_id;
}
void WebBackup::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string WebBackup::getBackupType() const
{
	return backup_type;
}
void WebBackup::setBackupType(std::string value)
{
	backup_type = value;
}
std::string WebBackup::getBackupMode() const
{
	return backup_mode;
}
void WebBackup::setBackupMode(std::string value)
{
	backup_mode = value;
}
long long WebBackup::getTstamp() const
{
	return tstamp;
}
void WebBackup::setTstamp(long long value)
{
	tstamp = value;
}
std::string WebBackup::getFilename() const
{
	return filename;
}
void WebBackup::setFilename(std::string value)
{
	filename = value;
}
std::string WebBackup::getFilesize() const
{
	return filesize;
}
void WebBackup::setFilesize(std::string value)
{
	filesize = value;
}

