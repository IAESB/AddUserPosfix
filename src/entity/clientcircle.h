#ifndef CLIENTCIRCLE_H
#define CLIENTCIRCLE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ClientCircle;
typedef shared_ptr<ClientCircle> ClientCirclePtr;
typedef vector<ClientCirclePtr> ClientCircleList;

class ClientCircle
{
	int circle_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string circle_name;
	std::string client_ids;
	std::string description;
	std::string active;
public:
	ClientCircle();
	ClientCircle(int circle_id);
	void init();
	int getCircleId() const;
	void setCircleId(int value);
	int getSysUserid() const;
	void setSysUserid(int value);
	int getSysGroupid() const;
	void setSysGroupid(int value);
	std::string getSysPermUser() const;
	void setSysPermUser(std::string value);
	std::string getSysPermGroup() const;
	void setSysPermGroup(std::string value);
	std::string getSysPermOther() const;
	void setSysPermOther(std::string value);
	std::string getCircleName() const;
	void setCircleName(std::string value);
	std::string getClientIds() const;
	void setClientIds(std::string value);
	std::string getDescription() const;
	void setDescription(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // CLIENTCIRCLE_H
