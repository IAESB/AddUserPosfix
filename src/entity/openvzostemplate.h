#ifndef OPENVZOSTEMPLATE_H
#define OPENVZOSTEMPLATE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class OpenvzOstemplate;
typedef shared_ptr<OpenvzOstemplate> OpenvzOstemplatePtr;
typedef vector<OpenvzOstemplatePtr> OpenvzOstemplateList;

class OpenvzOstemplate
{
	long long ostemplate_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string template_name;
	std::string template_file;
	int server_id;
	std::string allservers;
	std::string active;
	std::string description;
public:
	OpenvzOstemplate();
	OpenvzOstemplate(long long ostemplate_id);
	void init();
	long long getOstemplateId() const;
	void setOstemplateId(long long value);
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
	std::string getTemplateName() const;
	void setTemplateName(std::string value);
	std::string getTemplateFile() const;
	void setTemplateFile(std::string value);
	int getServerId() const;
	void setServerId(int value);
	std::string getAllservers() const;
	void setAllservers(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getDescription() const;
	void setDescription(std::string value);
};



#endif // OPENVZOSTEMPLATE_H
