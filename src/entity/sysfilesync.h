#ifndef SYSFILESYNC_H
#define SYSFILESYNC_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysFilesync;
typedef shared_ptr<SysFilesync> SysFilesyncPtr;
typedef vector<SysFilesyncPtr> SysFilesyncList;

class SysFilesync
{
	long long id; //key: PRI
	std::string jobname;
	long long sync_interval_minutes;
	std::string ftp_host;
	std::string ftp_path;
	std::string ftp_username;
	std::string ftp_password;
	std::string local_path;
	std::string wput_options;
	int active;
public:
	SysFilesync();
	SysFilesync(long long id);
	void init();
	long long getId() const;
	void setId(long long value);
	std::string getJobname() const;
	void setJobname(std::string value);
	long long getSyncIntervalMinutes() const;
	void setSyncIntervalMinutes(long long value);
	std::string getFtpHost() const;
	void setFtpHost(std::string value);
	std::string getFtpPath() const;
	void setFtpPath(std::string value);
	std::string getFtpUsername() const;
	void setFtpUsername(std::string value);
	std::string getFtpPassword() const;
	void setFtpPassword(std::string value);
	std::string getLocalPath() const;
	void setLocalPath(std::string value);
	std::string getWputOptions() const;
	void setWputOptions(std::string value);
	int getActive() const;
	void setActive(int value);
};



#endif // SYSFILESYNC_H
