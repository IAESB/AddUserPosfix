#ifndef MAILUSER_H
#define MAILUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailUser;
typedef shared_ptr<MailUser> MailUserPtr;
typedef vector<MailUserPtr> MailUserList;

class MailUser
{
	long long mailuser_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id; //key: MUL
	std::string email; //key: MUL
	std::string login;
	std::string password;
	std::string name;
	int uid;
	int gid;
	std::string maildir;
	long long quota;
	std::string cc;
	std::string homedir;
	std::string autoresponder;
	tm autoresponder_start_date;
	tm autoresponder_end_date;
	std::string autoresponder_subject;
	std::string autoresponder_text;
	std::string move_junk;
	std::string custom_mailfilter;
	std::string postfix;
	std::string access;
	std::string disableimap;
	std::string disablepop3;
	std::string disabledeliver;
	std::string disablesmtp;
	std::string disablesieve;
	std::string disablesieve_filter;
	std::string disablelda;
	std::string disablelmtp;
	std::string disabledoveadm;
	tm last_quota_notification;
	std::string backup_interval;
	int backup_copies;
public:
	MailUser();
	MailUser(long long mailuser_id);
	void init();
	long long getMailuserId() const;
	void setMailuserId(long long value);
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
	std::string getEmail() const;
	void setEmail(std::string value);
	std::string getLogin() const;
	void setLogin(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	std::string getName() const;
	void setName(std::string value);
	int getUid() const;
	void setUid(int value);
	int getGid() const;
	void setGid(int value);
	std::string getMaildir() const;
	void setMaildir(std::string value);
	long long getQuota() const;
	void setQuota(long long value);
	std::string getCc() const;
	void setCc(std::string value);
	std::string getHomedir() const;
	void setHomedir(std::string value);
	std::string getAutoresponder() const;
	void setAutoresponder(std::string value);
	tm getAutoresponderStartDate() const;
	void setAutoresponderStartDate(tm value);
	tm getAutoresponderEndDate() const;
	void setAutoresponderEndDate(tm value);
	std::string getAutoresponderSubject() const;
	void setAutoresponderSubject(std::string value);
	std::string getAutoresponderText() const;
	void setAutoresponderText(std::string value);
	std::string getMoveJunk() const;
	void setMoveJunk(std::string value);
	std::string getCustomMailfilter() const;
	void setCustomMailfilter(std::string value);
	std::string getPostfix() const;
	void setPostfix(std::string value);
	std::string getAccess() const;
	void setAccess(std::string value);
	std::string getDisableimap() const;
	void setDisableimap(std::string value);
	std::string getDisablepop3() const;
	void setDisablepop3(std::string value);
	std::string getDisabledeliver() const;
	void setDisabledeliver(std::string value);
	std::string getDisablesmtp() const;
	void setDisablesmtp(std::string value);
	std::string getDisablesieve() const;
	void setDisablesieve(std::string value);
	std::string getDisablesieveFilter() const;
	void setDisablesieveFilter(std::string value);
	std::string getDisablelda() const;
	void setDisablelda(std::string value);
	std::string getDisablelmtp() const;
	void setDisablelmtp(std::string value);
	std::string getDisabledoveadm() const;
	void setDisabledoveadm(std::string value);
	tm getLastQuotaNotification() const;
	void setLastQuotaNotification(tm value);
	std::string getBackupInterval() const;
	void setBackupInterval(std::string value);
	int getBackupCopies() const;
	void setBackupCopies(int value);
};



#endif // MAILUSER_H
