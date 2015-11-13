#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Admin;
typedef shared_ptr<Admin> AdminPtr;
typedef vector<AdminPtr> AdminList;

class Admin
{
	std::string username; //key: PRI
	std::string password;
	std::string domain;
	tm create_date;
	tm change_date;
	std::string permite;
	int active;
public:
	Admin();
	Admin(std::string username);
	void init();
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	std::string getDomain() const;
	void setDomain(std::string value);
	tm getCreateDate() const;
	void setCreateDate(tm value);
	tm getChangeDate() const;
	void setChangeDate(tm value);
	std::string getPermite() const;
	void setPermite(std::string value);
	int getActive() const;
	void setActive(int value);
};



#endif // ADMIN_H
