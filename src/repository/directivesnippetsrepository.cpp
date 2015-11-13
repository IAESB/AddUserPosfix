#include "directivesnippetsrepository.h"
#include "util.hpp"
DirectiveSnippetsRepository::DirectiveSnippetsRepository(soci::session& db) : dataBase(db)
{
}

DirectiveSnippetsPtr DirectiveSnippetsRepository::select(const DirectiveSnippets& obj)
{
	soci::row row;
	DirectiveSnippetsPtr directivesnippets(new DirectiveSnippets);
	dataBase << "SELECT  directive_snippets.directive_snippets_id as DirectiveSnippets_directive_snippets_id, directive_snippets.sys_userid as DirectiveSnippets_sys_userid, directive_snippets.sys_groupid as DirectiveSnippets_sys_groupid, directive_snippets.sys_perm_user as DirectiveSnippets_sys_perm_user, directive_snippets.sys_perm_group as DirectiveSnippets_sys_perm_group, directive_snippets.sys_perm_other as DirectiveSnippets_sys_perm_other, directive_snippets.name as DirectiveSnippets_name, directive_snippets.type as DirectiveSnippets_type, directive_snippets.snippet as DirectiveSnippets_snippet, directive_snippets.active as DirectiveSnippets_active"
	" FROM directive_snippets "
	"WHERE directive_snippets.directive_snippets_id = :DirectiveSnippets_directive_snippets_id", into(row), use(obj);
	if(!dataBase.got_data())
		directivesnippets.reset();
	else
		type_conversion<DirectiveSnippets>::from_base(row, i_ok, *directivesnippets);
	return directivesnippets;
}
DirectiveSnippetsList DirectiveSnippetsRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  directive_snippets.directive_snippets_id as DirectiveSnippets_directive_snippets_id, directive_snippets.sys_userid as DirectiveSnippets_sys_userid, directive_snippets.sys_groupid as DirectiveSnippets_sys_groupid, directive_snippets.sys_perm_user as DirectiveSnippets_sys_perm_user, directive_snippets.sys_perm_group as DirectiveSnippets_sys_perm_group, directive_snippets.sys_perm_other as DirectiveSnippets_sys_perm_other, directive_snippets.name as DirectiveSnippets_name, directive_snippets.type as DirectiveSnippets_type, directive_snippets.snippet as DirectiveSnippets_snippet, directive_snippets.active as DirectiveSnippets_active "
	" FROM directive_snippets" 
	<< (where.size()?" WHERE "+where:"");
	DirectiveSnippetsList directivesnippetsList;
	for(row& r: rs)
	{
		DirectiveSnippetsPtr directivesnippets(new DirectiveSnippets);
		type_conversion<DirectiveSnippets>::from_base(r, i_ok, *directivesnippets);
		directivesnippetsList.push_back(directivesnippets);
	}
	return directivesnippetsList;
}

int DirectiveSnippetsRepository::insert(const DirectiveSnippets& directivesnippets)
{
	dataBase << "insert into directive_snippets(directive_snippets_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, name, type, snippet, active)\
values(:DirectiveSnippets_directive_snippets_id, :DirectiveSnippets_sys_userid, :DirectiveSnippets_sys_groupid, :DirectiveSnippets_sys_perm_user, :DirectiveSnippets_sys_perm_group, :DirectiveSnippets_sys_perm_other, :DirectiveSnippets_name, :DirectiveSnippets_type, :DirectiveSnippets_snippet, :DirectiveSnippets_active)", use(directivesnippets);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DirectiveSnippetsRepository::remove(const DirectiveSnippets& directivesnippets)
{
	dataBase << "DELETE from directive_snippets WHERE directive_snippets_id=:DirectiveSnippets_directive_snippets_id", use(directivesnippets);
}

void DirectiveSnippetsRepository::update(const DirectiveSnippets& directivesnippets)
{
	dataBase << "update directive_snippets set directive_snippets_id=:DirectiveSnippets_directive_snippets_id, sys_userid=:DirectiveSnippets_sys_userid, sys_groupid=:DirectiveSnippets_sys_groupid, sys_perm_user=:DirectiveSnippets_sys_perm_user, sys_perm_group=:DirectiveSnippets_sys_perm_group, sys_perm_other=:DirectiveSnippets_sys_perm_other, name=:DirectiveSnippets_name, type=:DirectiveSnippets_type, snippet=:DirectiveSnippets_snippet, active=:DirectiveSnippets_active WHERE directive_snippets_id=:DirectiveSnippets_directive_snippets_id", use(directivesnippets);
}

void DirectiveSnippetsRepository::update(const DirectiveSnippets& oldObj, const DirectiveSnippets& newObj)
{
	dataBase << "update directive_snippets set directive_snippets_id=:DirectiveSnippets_directive_snippets_id, sys_userid=:DirectiveSnippets_sys_userid, sys_groupid=:DirectiveSnippets_sys_groupid, sys_perm_user=:DirectiveSnippets_sys_perm_user, sys_perm_group=:DirectiveSnippets_sys_perm_group, sys_perm_other=:DirectiveSnippets_sys_perm_other, name=:DirectiveSnippets_name, type=:DirectiveSnippets_type, snippet=:DirectiveSnippets_snippet, active=:DirectiveSnippets_active WHERE directive_snippets_id='"<<oldObj.getDirectiveSnippetsId()<<"\'", use(newObj);
}

