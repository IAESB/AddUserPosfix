#ifndef WEBFOLDERUSER_H
#define WEBFOLDERUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebFolderUser;
typedef shared_ptr<WebFolderUser> WebFolderUserPtr;
typedef vector<WebFolderUserPtr> WebFolderUserList;

class WebFolderUser
{
	long long web_folder_user_id; //key: PRI
	int sys_userid;
	int sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	int web_folder_id;
	std::string username;
	std::string password;
	std::string active;
public:
	WebFolderUser();
	WebFolderUser(long long web_folder_user_id);
	void init();
	long long getWebFolderUserId() const;
	void setWebFolderUserId(long long value);
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
	int getWebFolderId() const;
	void setWebFolderId(int value);
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // WEBFOLDERUSER_H
