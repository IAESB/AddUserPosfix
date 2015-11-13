#ifndef SOFTWAREREPO_H
#define SOFTWAREREPO_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SoftwareRepo;
typedef shared_ptr<SoftwareRepo> SoftwareRepoPtr;
typedef vector<SoftwareRepoPtr> SoftwareRepoList;

class SoftwareRepo
{
	long long software_repo_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string repo_name;
	std::string repo_url;
	std::string repo_username;
	std::string repo_password;
	std::string active;
public:
	SoftwareRepo();
	SoftwareRepo(long long software_repo_id);
	void init();
	long long getSoftwareRepoId() const;
	void setSoftwareRepoId(long long value);
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
	std::string getRepoName() const;
	void setRepoName(std::string value);
	std::string getRepoUrl() const;
	void setRepoUrl(std::string value);
	std::string getRepoUsername() const;
	void setRepoUsername(std::string value);
	std::string getRepoPassword() const;
	void setRepoPassword(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // SOFTWAREREPO_H
