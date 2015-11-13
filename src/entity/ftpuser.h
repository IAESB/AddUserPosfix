#ifndef FTPUSER_H
#define FTPUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class FtpUser;
typedef shared_ptr<FtpUser> FtpUserPtr;
typedef vector<FtpUserPtr> FtpUserList;

class FtpUser
{
	long long ftp_user_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id; //key: MUL
	long long parent_domain_id;
	std::string username; //key: MUL
	std::string username_prefix;
	std::string password;
	long long quota_size;
	std::string active; //key: MUL
	std::string uid;
	std::string gid;
	std::string dir;
	long long quota_files; //key: MUL
	int ul_ratio;
	int dl_ratio;
	int ul_bandwidth;
	int dl_bandwidth;
	tm expires;
public:
	FtpUser();
	FtpUser(long long ftp_user_id);
	void init();
	long long getFtpUserId() const;
	void setFtpUserId(long long value);
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
	long long getParentDomainId() const;
	void setParentDomainId(long long value);
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getUsernamePrefix() const;
	void setUsernamePrefix(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	long long getQuotaSize() const;
	void setQuotaSize(long long value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getUid() const;
	void setUid(std::string value);
	std::string getGid() const;
	void setGid(std::string value);
	std::string getDir() const;
	void setDir(std::string value);
	long long getQuotaFiles() const;
	void setQuotaFiles(long long value);
	int getUlRatio() const;
	void setUlRatio(int value);
	int getDlRatio() const;
	void setDlRatio(int value);
	int getUlBandwidth() const;
	void setUlBandwidth(int value);
	int getDlBandwidth() const;
	void setDlBandwidth(int value);
	tm getExpires() const;
	void setExpires(tm value);
};



#endif // FTPUSER_H
