#ifndef DNSSOA_H
#define DNSSOA_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class DnsSoa;
typedef shared_ptr<DnsSoa> DnsSoaPtr;
typedef vector<DnsSoaPtr> DnsSoaList;

class DnsSoa
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	std::string origin; //key: UNI
	std::string ns;
	std::string mbox;
	long long serial;
	long long refresh;
	long long retry;
	long long expire;
	long long minimum;
	long long ttl;
	std::string active; //key: MUL
	std::string xfer;
	std::string also_notify;
	std::string update_acl;
public:
	DnsSoa();
	DnsSoa(long long id);
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
	int getServerId() const;
	void setServerId(int value);
	std::string getOrigin() const;
	void setOrigin(std::string value);
	std::string getNs() const;
	void setNs(std::string value);
	std::string getMbox() const;
	void setMbox(std::string value);
	long long getSerial() const;
	void setSerial(long long value);
	long long getRefresh() const;
	void setRefresh(long long value);
	long long getRetry() const;
	void setRetry(long long value);
	long long getExpire() const;
	void setExpire(long long value);
	long long getMinimum() const;
	void setMinimum(long long value);
	long long getTtl() const;
	void setTtl(long long value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getXfer() const;
	void setXfer(std::string value);
	std::string getAlsoNotify() const;
	void setAlsoNotify(std::string value);
	std::string getUpdateAcl() const;
	void setUpdateAcl(std::string value);
};



#endif // DNSSOA_H
