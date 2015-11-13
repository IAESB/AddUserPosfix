#ifndef WEBFOLDER_H
#define WEBFOLDER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebFolder;
typedef shared_ptr<WebFolder> WebFolderPtr;
typedef vector<WebFolderPtr> WebFolderList;

class WebFolder
{
	long long web_folder_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	int parent_domain_id;
	std::string path;
	std::string active;
public:
	WebFolder();
	WebFolder(long long web_folder_id);
	void init();
	long long getWebFolderId() const;
	void setWebFolderId(long long value);
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
	int getServerId() const;
	void setServerId(int value);
	int getParentDomainId() const;
	void setParentDomainId(int value);
	std::string getPath() const;
	void setPath(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // WEBFOLDER_H
