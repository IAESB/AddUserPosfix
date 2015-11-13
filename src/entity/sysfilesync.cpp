#include "sysfilesync.h"

SysFilesync::SysFilesync(){
	init();
}
SysFilesync::SysFilesync(long long id)
{
	init();
	this->id = id;
}

void SysFilesync::init()
{
}
long long SysFilesync::getId() const
{
	return id;
}
void SysFilesync::setId(long long value)
{
	id = value;
}
std::string SysFilesync::getJobname() const
{
	return jobname;
}
void SysFilesync::setJobname(std::string value)
{
	jobname = value;
}
long long SysFilesync::getSyncIntervalMinutes() const
{
	return sync_interval_minutes;
}
void SysFilesync::setSyncIntervalMinutes(long long value)
{
	sync_interval_minutes = value;
}
std::string SysFilesync::getFtpHost() const
{
	return ftp_host;
}
void SysFilesync::setFtpHost(std::string value)
{
	ftp_host = value;
}
std::string SysFilesync::getFtpPath() const
{
	return ftp_path;
}
void SysFilesync::setFtpPath(std::string value)
{
	ftp_path = value;
}
std::string SysFilesync::getFtpUsername() const
{
	return ftp_username;
}
void SysFilesync::setFtpUsername(std::string value)
{
	ftp_username = value;
}
std::string SysFilesync::getFtpPassword() const
{
	return ftp_password;
}
void SysFilesync::setFtpPassword(std::string value)
{
	ftp_password = value;
}
std::string SysFilesync::getLocalPath() const
{
	return local_path;
}
void SysFilesync::setLocalPath(std::string value)
{
	local_path = value;
}
std::string SysFilesync::getWputOptions() const
{
	return wput_options;
}
void SysFilesync::setWputOptions(std::string value)
{
	wput_options = value;
}
int SysFilesync::getActive() const
{
	return active;
}
void SysFilesync::setActive(int value)
{
	active = value;
}

