#ifndef DNSRR_H
#define DNSRR_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class DnsRr;
typedef shared_ptr<DnsRr> DnsRrPtr;
typedef vector<DnsRrPtr> DnsRrList;

class DnsRr
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	long long zone; //key: MUL
	std::string name;
	std::string type;
	std::string data;
	long long aux;
	long long ttl;
	std::string active;
	tm stamp;
	long long serial;
public:
	DnsRr();
	DnsRr(long long id);
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
	long long getZone() const;
	void setZone(long long value);
	std::string getName() const;
	void setName(std::string value);
	std::string getType() const;
	void setType(std::string value);
	std::string getData() const;
	void setData(std::string value);
	long long getAux() const;
	void setAux(long long value);
	long long getTtl() const;
	void setTtl(long long value);
	std::string getActive() const;
	void setActive(std::string value);
	tm getStamp() const;
	void setStamp(tm value);
	long long getSerial() const;
	void setSerial(long long value);
};



#endif // DNSRR_H
