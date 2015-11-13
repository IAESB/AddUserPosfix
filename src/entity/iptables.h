#ifndef IPTABLES_H
#define IPTABLES_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Iptables;
typedef shared_ptr<Iptables> IptablesPtr;
typedef vector<IptablesPtr> IptablesList;

class Iptables
{
	long long iptables_id; //key: PRI
	long long server_id;
	std::string table;
	std::string source_ip;
	std::string destination_ip;
	std::string protocol;
	std::string singleport;
	std::string multiport;
	std::string state;
	std::string target;
	std::string active;
public:
	Iptables();
	Iptables(long long iptables_id);
	void init();
	long long getIptablesId() const;
	void setIptablesId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	std::string getTable() const;
	void setTable(std::string value);
	std::string getSourceIp() const;
	void setSourceIp(std::string value);
	std::string getDestinationIp() const;
	void setDestinationIp(std::string value);
	std::string getProtocol() const;
	void setProtocol(std::string value);
	std::string getSingleport() const;
	void setSingleport(std::string value);
	std::string getMultiport() const;
	void setMultiport(std::string value);
	std::string getState() const;
	void setState(std::string value);
	std::string getTarget() const;
	void setTarget(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // IPTABLES_H
