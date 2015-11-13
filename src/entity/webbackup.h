#ifndef WEBBACKUP_H
#define WEBBACKUP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebBackup;
typedef shared_ptr<WebBackup> WebBackupPtr;
typedef vector<WebBackupPtr> WebBackupList;

class WebBackup
{
	long long backup_id; //key: PRI
	long long server_id;
	long long parent_domain_id;
	std::string backup_type;
	std::string backup_mode;
	long long tstamp;
	std::string filename;
	std::string filesize;
public:
	WebBackup();
	WebBackup(long long backup_id);
	void init();
	long long getBackupId() const;
	void setBackupId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	long long getParentDomainId() const;
	void setParentDomainId(long long value);
	std::string getBackupType() const;
	void setBackupType(std::string value);
	std::string getBackupMode() const;
	void setBackupMode(std::string value);
	long long getTstamp() const;
	void setTstamp(long long value);
	std::string getFilename() const;
	void setFilename(std::string value);
	std::string getFilesize() const;
	void setFilesize(std::string value);
};



#endif // WEBBACKUP_H
