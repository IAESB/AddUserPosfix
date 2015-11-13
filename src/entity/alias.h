#ifndef ALIAS_H
#define ALIAS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Alias;
typedef shared_ptr<Alias> AliasPtr;
typedef vector<AliasPtr> AliasList;

class Alias
{
	std::string address; //key: PRI
	std::string goto_;
	std::string domain;
	tm create_date;
	tm change_date;
	std::string add_info;
	int active;
public:
	Alias();
	Alias(std::string address);
	void init();
	std::string getAddress() const;
	void setAddress(std::string value);
	std::string getGoto() const;
	void setGoto(std::string value);
	std::string getDomain() const;
	void setDomain(std::string value);
	tm getCreateDate() const;
	void setCreateDate(tm value);
	tm getChangeDate() const;
	void setChangeDate(tm value);
	std::string getAddInfo() const;
	void setAddInfo(std::string value);
	int getActive() const;
	void setActive(int value);
};



#endif // ALIAS_H
