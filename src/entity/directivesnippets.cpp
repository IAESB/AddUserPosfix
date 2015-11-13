#include "directivesnippets.h"

DirectiveSnippets::DirectiveSnippets(){
	init();
}
DirectiveSnippets::DirectiveSnippets(long long directive_snippets_id)
{
	init();
	this->directive_snippets_id = directive_snippets_id;
}

void DirectiveSnippets::init()
{
}
long long DirectiveSnippets::getDirectiveSnippetsId() const
{
	return directive_snippets_id;
}
void DirectiveSnippets::setDirectiveSnippetsId(long long value)
{
	directive_snippets_id = value;
}
long long DirectiveSnippets::getSysUserid() const
{
	return sys_userid;
}
void DirectiveSnippets::setSysUserid(long long value)
{
	sys_userid = value;
}
long long DirectiveSnippets::getSysGroupid() const
{
	return sys_groupid;
}
void DirectiveSnippets::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string DirectiveSnippets::getSysPermUser() const
{
	return sys_perm_user;
}
void DirectiveSnippets::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string DirectiveSnippets::getSysPermGroup() const
{
	return sys_perm_group;
}
void DirectiveSnippets::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string DirectiveSnippets::getSysPermOther() const
{
	return sys_perm_other;
}
void DirectiveSnippets::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string DirectiveSnippets::getName() const
{
	return name;
}
void DirectiveSnippets::setName(std::string value)
{
	name = value;
}
std::string DirectiveSnippets::getType() const
{
	return type;
}
void DirectiveSnippets::setType(std::string value)
{
	type = value;
}
std::string DirectiveSnippets::getSnippet() const
{
	return snippet;
}
void DirectiveSnippets::setSnippet(std::string value)
{
	snippet = value;
}
std::string DirectiveSnippets::getActive() const
{
	return active;
}
void DirectiveSnippets::setActive(std::string value)
{
	active = value;
}

