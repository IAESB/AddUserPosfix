#include "shelluserrepository.h"
#include "util.hpp"
ShellUserRepository::ShellUserRepository(soci::session& db) : dataBase(db)
{
}

ShellUserPtr ShellUserRepository::select(const ShellUser& obj)
{
	soci::row row;
	ShellUserPtr shelluser(new ShellUser);
	dataBase << "SELECT  shell_user.shell_user_id as ShellUser_shell_user_id, shell_user.sys_userid as ShellUser_sys_userid, shell_user.sys_groupid as ShellUser_sys_groupid, shell_user.sys_perm_user as ShellUser_sys_perm_user, shell_user.sys_perm_group as ShellUser_sys_perm_group, shell_user.sys_perm_other as ShellUser_sys_perm_other, shell_user.server_id as ShellUser_server_id, shell_user.parent_domain_id as ShellUser_parent_domain_id, shell_user.username as ShellUser_username, shell_user.username_prefix as ShellUser_username_prefix, shell_user.password as ShellUser_password, shell_user.quota_size as ShellUser_quota_size, shell_user.active as ShellUser_active, shell_user.puser as ShellUser_puser, shell_user.pgroup as ShellUser_pgroup, shell_user.shell as ShellUser_shell, shell_user.dir as ShellUser_dir, shell_user.chroot as ShellUser_chroot, shell_user.ssh_rsa as ShellUser_ssh_rsa"
	" FROM shell_user "
	"WHERE shell_user.shell_user_id = :ShellUser_shell_user_id", into(row), use(obj);
	if(!dataBase.got_data())
		shelluser.reset();
	else
		type_conversion<ShellUser>::from_base(row, i_ok, *shelluser);
	return shelluser;
}
ShellUserList ShellUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  shell_user.shell_user_id as ShellUser_shell_user_id, shell_user.sys_userid as ShellUser_sys_userid, shell_user.sys_groupid as ShellUser_sys_groupid, shell_user.sys_perm_user as ShellUser_sys_perm_user, shell_user.sys_perm_group as ShellUser_sys_perm_group, shell_user.sys_perm_other as ShellUser_sys_perm_other, shell_user.server_id as ShellUser_server_id, shell_user.parent_domain_id as ShellUser_parent_domain_id, shell_user.username as ShellUser_username, shell_user.username_prefix as ShellUser_username_prefix, shell_user.password as ShellUser_password, shell_user.quota_size as ShellUser_quota_size, shell_user.active as ShellUser_active, shell_user.puser as ShellUser_puser, shell_user.pgroup as ShellUser_pgroup, shell_user.shell as ShellUser_shell, shell_user.dir as ShellUser_dir, shell_user.chroot as ShellUser_chroot, shell_user.ssh_rsa as ShellUser_ssh_rsa "
	" FROM shell_user" 
	<< (where.size()?" WHERE "+where:"");
	ShellUserList shelluserList;
	for(row& r: rs)
	{
		ShellUserPtr shelluser(new ShellUser);
		type_conversion<ShellUser>::from_base(r, i_ok, *shelluser);
		shelluserList.push_back(shelluser);
	}
	return shelluserList;
}

int ShellUserRepository::insert(const ShellUser& shelluser)
{
	dataBase << "insert into shell_user(shell_user_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, username, username_prefix, password, quota_size, active, puser, pgroup, shell, dir, chroot, ssh_rsa)\
values(:ShellUser_shell_user_id, :ShellUser_sys_userid, :ShellUser_sys_groupid, :ShellUser_sys_perm_user, :ShellUser_sys_perm_group, :ShellUser_sys_perm_other, :ShellUser_server_id, :ShellUser_parent_domain_id, :ShellUser_username, :ShellUser_username_prefix, :ShellUser_password, :ShellUser_quota_size, :ShellUser_active, :ShellUser_puser, :ShellUser_pgroup, :ShellUser_shell, :ShellUser_dir, :ShellUser_chroot, :ShellUser_ssh_rsa)", use(shelluser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ShellUserRepository::remove(const ShellUser& shelluser)
{
	dataBase << "DELETE from shell_user WHERE shell_user_id=:ShellUser_shell_user_id", use(shelluser);
}

void ShellUserRepository::update(const ShellUser& shelluser)
{
	dataBase << "update shell_user set shell_user_id=:ShellUser_shell_user_id, sys_userid=:ShellUser_sys_userid, sys_groupid=:ShellUser_sys_groupid, sys_perm_user=:ShellUser_sys_perm_user, sys_perm_group=:ShellUser_sys_perm_group, sys_perm_other=:ShellUser_sys_perm_other, server_id=:ShellUser_server_id, parent_domain_id=:ShellUser_parent_domain_id, username=:ShellUser_username, username_prefix=:ShellUser_username_prefix, password=:ShellUser_password, quota_size=:ShellUser_quota_size, active=:ShellUser_active, puser=:ShellUser_puser, pgroup=:ShellUser_pgroup, shell=:ShellUser_shell, dir=:ShellUser_dir, chroot=:ShellUser_chroot, ssh_rsa=:ShellUser_ssh_rsa WHERE shell_user_id=:ShellUser_shell_user_id", use(shelluser);
}

void ShellUserRepository::update(const ShellUser& oldObj, const ShellUser& newObj)
{
	dataBase << "update shell_user set shell_user_id=:ShellUser_shell_user_id, sys_userid=:ShellUser_sys_userid, sys_groupid=:ShellUser_sys_groupid, sys_perm_user=:ShellUser_sys_perm_user, sys_perm_group=:ShellUser_sys_perm_group, sys_perm_other=:ShellUser_sys_perm_other, server_id=:ShellUser_server_id, parent_domain_id=:ShellUser_parent_domain_id, username=:ShellUser_username, username_prefix=:ShellUser_username_prefix, password=:ShellUser_password, quota_size=:ShellUser_quota_size, active=:ShellUser_active, puser=:ShellUser_puser, pgroup=:ShellUser_pgroup, shell=:ShellUser_shell, dir=:ShellUser_dir, chroot=:ShellUser_chroot, ssh_rsa=:ShellUser_ssh_rsa WHERE shell_user_id='"<<oldObj.getShellUserId()<<"\'", use(newObj);
}

