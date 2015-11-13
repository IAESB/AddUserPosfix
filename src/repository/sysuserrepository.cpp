#include "sysuserrepository.h"
#include "util.hpp"
SysUserRepository::SysUserRepository(soci::session& db) : dataBase(db)
{
}

SysUserPtr SysUserRepository::select(const SysUser& obj)
{
	soci::row row;
	SysUserPtr sysuser(new SysUser);
	dataBase << "SELECT  sys_user.userid as SysUser_userid, sys_user.sys_userid as SysUser_sys_userid, sys_user.sys_groupid as SysUser_sys_groupid, sys_user.sys_perm_user as SysUser_sys_perm_user, sys_user.sys_perm_group as SysUser_sys_perm_group, sys_user.sys_perm_other as SysUser_sys_perm_other, sys_user.username as SysUser_username, sys_user.passwort as SysUser_passwort, sys_user.modules as SysUser_modules, sys_user.startmodule as SysUser_startmodule, sys_user.app_theme as SysUser_app_theme, sys_user.typ as SysUser_typ, sys_user.active as SysUser_active, sys_user.language as SysUser_language, sys_user.groups as SysUser_groups, sys_user.default_group as SysUser_default_group, sys_user.client_id as SysUser_client_id, sys_user.id_rsa as SysUser_id_rsa, sys_user.ssh_rsa as SysUser_ssh_rsa"
	" FROM sys_user "
	"WHERE sys_user.userid = :SysUser_userid", into(row), use(obj);
	if(!dataBase.got_data())
		sysuser.reset();
	else
		type_conversion<SysUser>::from_base(row, i_ok, *sysuser);
	return sysuser;
}
SysUserList SysUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_user.userid as SysUser_userid, sys_user.sys_userid as SysUser_sys_userid, sys_user.sys_groupid as SysUser_sys_groupid, sys_user.sys_perm_user as SysUser_sys_perm_user, sys_user.sys_perm_group as SysUser_sys_perm_group, sys_user.sys_perm_other as SysUser_sys_perm_other, sys_user.username as SysUser_username, sys_user.passwort as SysUser_passwort, sys_user.modules as SysUser_modules, sys_user.startmodule as SysUser_startmodule, sys_user.app_theme as SysUser_app_theme, sys_user.typ as SysUser_typ, sys_user.active as SysUser_active, sys_user.language as SysUser_language, sys_user.groups as SysUser_groups, sys_user.default_group as SysUser_default_group, sys_user.client_id as SysUser_client_id, sys_user.id_rsa as SysUser_id_rsa, sys_user.ssh_rsa as SysUser_ssh_rsa "
	" FROM sys_user" 
	<< (where.size()?" WHERE "+where:"");
	SysUserList sysuserList;
	for(row& r: rs)
	{
		SysUserPtr sysuser(new SysUser);
		type_conversion<SysUser>::from_base(r, i_ok, *sysuser);
		sysuserList.push_back(sysuser);
	}
	return sysuserList;
}

int SysUserRepository::insert(const SysUser& sysuser)
{
	dataBase << "insert into sys_user(userid, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, username, passwort, modules, startmodule, app_theme, typ, active, language, groups, default_group, client_id, id_rsa, ssh_rsa)\
values(:SysUser_userid, :SysUser_sys_userid, :SysUser_sys_groupid, :SysUser_sys_perm_user, :SysUser_sys_perm_group, :SysUser_sys_perm_other, :SysUser_username, :SysUser_passwort, :SysUser_modules, :SysUser_startmodule, :SysUser_app_theme, :SysUser_typ, :SysUser_active, :SysUser_language, :SysUser_groups, :SysUser_default_group, :SysUser_client_id, :SysUser_id_rsa, :SysUser_ssh_rsa)", use(sysuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysUserRepository::remove(const SysUser& sysuser)
{
	dataBase << "DELETE from sys_user WHERE userid=:SysUser_userid", use(sysuser);
}

void SysUserRepository::update(const SysUser& sysuser)
{
	dataBase << "update sys_user set userid=:SysUser_userid, sys_userid=:SysUser_sys_userid, sys_groupid=:SysUser_sys_groupid, sys_perm_user=:SysUser_sys_perm_user, sys_perm_group=:SysUser_sys_perm_group, sys_perm_other=:SysUser_sys_perm_other, username=:SysUser_username, passwort=:SysUser_passwort, modules=:SysUser_modules, startmodule=:SysUser_startmodule, app_theme=:SysUser_app_theme, typ=:SysUser_typ, active=:SysUser_active, language=:SysUser_language, groups=:SysUser_groups, default_group=:SysUser_default_group, client_id=:SysUser_client_id, id_rsa=:SysUser_id_rsa, ssh_rsa=:SysUser_ssh_rsa WHERE userid=:SysUser_userid", use(sysuser);
}

void SysUserRepository::update(const SysUser& oldObj, const SysUser& newObj)
{
	dataBase << "update sys_user set userid=:SysUser_userid, sys_userid=:SysUser_sys_userid, sys_groupid=:SysUser_sys_groupid, sys_perm_user=:SysUser_sys_perm_user, sys_perm_group=:SysUser_sys_perm_group, sys_perm_other=:SysUser_sys_perm_other, username=:SysUser_username, passwort=:SysUser_passwort, modules=:SysUser_modules, startmodule=:SysUser_startmodule, app_theme=:SysUser_app_theme, typ=:SysUser_typ, active=:SysUser_active, language=:SysUser_language, groups=:SysUser_groups, default_group=:SysUser_default_group, client_id=:SysUser_client_id, id_rsa=:SysUser_id_rsa, ssh_rsa=:SysUser_ssh_rsa WHERE userid='"<<oldObj.getUserid()<<"\'", use(newObj);
}

