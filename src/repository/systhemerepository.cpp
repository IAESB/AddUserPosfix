#include "systhemerepository.h"
#include "util.hpp"
SysThemeRepository::SysThemeRepository(soci::session& db) : dataBase(db)
{
}

SysThemePtr SysThemeRepository::select(const SysTheme& obj)
{
	soci::row row;
	SysThemePtr systheme(new SysTheme);
	dataBase << "SELECT  sys_theme.sys_userid as SysTheme_sys_userid, sys_theme.sys_groupid as SysTheme_sys_groupid, sys_theme.sys_perm_user as SysTheme_sys_perm_user, sys_theme.sys_perm_group as SysTheme_sys_perm_group, sys_theme.sys_perm_other as SysTheme_sys_perm_other, sys_theme.var_id as SysTheme_var_id, sys_theme.tpl_name as SysTheme_tpl_name, sys_theme.username as SysTheme_username, sys_theme.logo_url as SysTheme_logo_url"
	" FROM sys_theme "
	"WHERE sys_theme.var_id = :SysTheme_var_id", into(row), use(obj);
	if(!dataBase.got_data())
		systheme.reset();
	else
		type_conversion<SysTheme>::from_base(row, i_ok, *systheme);
	return systheme;
}
SysThemeList SysThemeRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_theme.sys_userid as SysTheme_sys_userid, sys_theme.sys_groupid as SysTheme_sys_groupid, sys_theme.sys_perm_user as SysTheme_sys_perm_user, sys_theme.sys_perm_group as SysTheme_sys_perm_group, sys_theme.sys_perm_other as SysTheme_sys_perm_other, sys_theme.var_id as SysTheme_var_id, sys_theme.tpl_name as SysTheme_tpl_name, sys_theme.username as SysTheme_username, sys_theme.logo_url as SysTheme_logo_url "
	" FROM sys_theme" 
	<< (where.size()?" WHERE "+where:"");
	SysThemeList systhemeList;
	for(row& r: rs)
	{
		SysThemePtr systheme(new SysTheme);
		type_conversion<SysTheme>::from_base(r, i_ok, *systheme);
		systhemeList.push_back(systheme);
	}
	return systhemeList;
}

int SysThemeRepository::insert(const SysTheme& systheme)
{
	dataBase << "insert into sys_theme(sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, var_id, tpl_name, username, logo_url)\
values(:SysTheme_sys_userid, :SysTheme_sys_groupid, :SysTheme_sys_perm_user, :SysTheme_sys_perm_group, :SysTheme_sys_perm_other, :SysTheme_var_id, :SysTheme_tpl_name, :SysTheme_username, :SysTheme_logo_url)", use(systheme);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysThemeRepository::remove(const SysTheme& systheme)
{
	dataBase << "DELETE from sys_theme WHERE var_id=:SysTheme_var_id", use(systheme);
}

void SysThemeRepository::update(const SysTheme& systheme)
{
	dataBase << "update sys_theme set sys_userid=:SysTheme_sys_userid, sys_groupid=:SysTheme_sys_groupid, sys_perm_user=:SysTheme_sys_perm_user, sys_perm_group=:SysTheme_sys_perm_group, sys_perm_other=:SysTheme_sys_perm_other, var_id=:SysTheme_var_id, tpl_name=:SysTheme_tpl_name, username=:SysTheme_username, logo_url=:SysTheme_logo_url WHERE var_id=:SysTheme_var_id", use(systheme);
}

void SysThemeRepository::update(const SysTheme& oldObj, const SysTheme& newObj)
{
	dataBase << "update sys_theme set sys_userid=:SysTheme_sys_userid, sys_groupid=:SysTheme_sys_groupid, sys_perm_user=:SysTheme_sys_perm_user, sys_perm_group=:SysTheme_sys_perm_group, sys_perm_other=:SysTheme_sys_perm_other, var_id=:SysTheme_var_id, tpl_name=:SysTheme_tpl_name, username=:SysTheme_username, logo_url=:SysTheme_logo_url WHERE var_id='"<<oldObj.getVarId()<<"\'", use(newObj);
}

