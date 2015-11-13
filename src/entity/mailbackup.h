#ifndef MAILBACKUP_H
#define MAILBACKUP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailBackup;
typedef shared_ptr<MailBackup> MailBackupPtr;
typedef vector<MailBackupPtr> MailBackupList;

class MailBackup
{
	long long backup_id; //key: PRI
	long long server_id;
	long long parent_domain_id;
	long long mailuser_id;
	std::string backup_mode;
	long long tstamp;
	std::string filename;
	std::string filesize;
public:
	MailBackup();
	MailBackup(long long backup_id);
	void init();
	long long getBackupId() const;
	void setBackupId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	long long getParentDomainId() const;
	void setParentDomainId(long long value);
	long long getMailuserId() const;
	void setMailuserId(long long value);
	std::string getBackupMode() const;
	void setBackupMode(std::string value);
	long long getTstamp() const;
	void setTstamp(long long value);
	std::string getFilename() const;
	void setFilename(std::string value);
	std::string getFilesize() const;
	void setFilesize(std::string value);
};



#endif // MAILBACKUP_H
