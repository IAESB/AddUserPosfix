#ifndef DIRECTIVESNIPPETS_H
#define DIRECTIVESNIPPETS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class DirectiveSnippets;
typedef shared_ptr<DirectiveSnippets> DirectiveSnippetsPtr;
typedef vector<DirectiveSnippetsPtr> DirectiveSnippetsList;

class DirectiveSnippets
{
	long long directive_snippets_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string name;
	std::string type;
	std::string snippet;
	std::string active;
public:
	DirectiveSnippets();
	DirectiveSnippets(long long directive_snippets_id);
	void init();
	long long getDirectiveSnippetsId() const;
	void setDirectiveSnippetsId(long long value);
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
	std::string getName() const;
	void setName(std::string value);
	std::string getType() const;
	void setType(std::string value);
	std::string getSnippet() const;
	void setSnippet(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // DIRECTIVESNIPPETS_H
