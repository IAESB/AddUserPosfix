#ifndef CRON_H
#define CRON_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Cron;
typedef shared_ptr<Cron> CronPtr;
typedef vector<CronPtr> CronList;

class Cron
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long parent_domain_id;
	std::string type;
	std::string command;
	std::string run_min;
	std::string run_hour;
	std::string run_mday;
	std::string run_month;
	std::string run_wday;
	std::string log;
	std::string active;
public:
	Cron();
	Cron(long long id);
	void init();
	long long getId() const;
	void setId(long long value);
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
	std::string getType() const;
	void setType(std::string value);
	std::string getCommand() const;
	void setCommand(std::string value);
	std::string getRunMin() const;
	void setRunMin(std::string value);
	std::string getRunHour() const;
	void setRunHour(std::string value);
	std::string getRunMday() const;
	void setRunMday(std::string value);
	std::string getRunMonth() const;
	void setRunMonth(std::string value);
	std::string getRunWday() const;
	void setRunWday(std::string value);
	std::string getLog() const;
	void setLog(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // CRON_H
