#include "remoteuserrepository.h"
#include "util.hpp"
RemoteUserRepository::RemoteUserRepository(soci::session& db) : dataBase(db)
{
}

RemoteUserPtr RemoteUserRepository::select(const RemoteUser& obj)
{
	soci::row row;
	RemoteUserPtr remoteuser(new RemoteUser);
	dataBase << "SELECT  remote_user.remote_userid as RemoteUser_remote_userid, remote_user.sys_userid as RemoteUser_sys_userid, remote_user.sys_groupid as RemoteUser_sys_groupid, remote_user.sys_perm_user as RemoteUser_sys_perm_user, remote_user.sys_perm_group as RemoteUser_sys_perm_group, remote_user.sys_perm_other as RemoteUser_sys_perm_other, remote_user.remote_username as RemoteUser_remote_username, remote_user.remote_password as RemoteUser_remote_password, remote_user.remote_functions as RemoteUser_remote_functions"
	" FROM remote_user "
	"WHERE remote_user.remote_userid = :RemoteUser_remote_userid", into(row), use(obj);
	if(!dataBase.got_data())
		remoteuser.reset();
	else
		type_conversion<RemoteUser>::from_base(row, i_ok, *remoteuser);
	return remoteuser;
}
RemoteUserList RemoteUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  remote_user.remote_userid as RemoteUser_remote_userid, remote_user.sys_userid as RemoteUser_sys_userid, remote_user.sys_groupid as RemoteUser_sys_groupid, remote_user.sys_perm_user as RemoteUser_sys_perm_user, remote_user.sys_perm_group as RemoteUser_sys_perm_group, remote_user.sys_perm_other as RemoteUser_sys_perm_other, remote_user.remote_username as RemoteUser_remote_username, remote_user.remote_password as RemoteUser_remote_password, remote_user.remote_functions as RemoteUser_remote_functions "
	" FROM remote_user" 
	<< (where.size()?" WHERE "+where:"");
	RemoteUserList remoteuserList;
	for(row& r: rs)
	{
		RemoteUserPtr remoteuser(new RemoteUser);
		type_conversion<RemoteUser>::from_base(r, i_ok, *remoteuser);
		remoteuserList.push_back(remoteuser);
	}
	return remoteuserList;
}

int RemoteUserRepository::insert(const RemoteUser& remoteuser)
{
	dataBase << "insert into remote_user(remote_userid, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, remote_username, remote_password, remote_functions)\
values(:RemoteUser_remote_userid, :RemoteUser_sys_userid, :RemoteUser_sys_groupid, :RemoteUser_sys_perm_user, :RemoteUser_sys_perm_group, :RemoteUser_sys_perm_other, :RemoteUser_remote_username, :RemoteUser_remote_password, :RemoteUser_remote_functions)", use(remoteuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void RemoteUserRepository::remove(const RemoteUser& remoteuser)
{
	dataBase << "DELETE from remote_user WHERE remote_userid=:RemoteUser_remote_userid", use(remoteuser);
}

void RemoteUserRepository::update(const RemoteUser& remoteuser)
{
	dataBase << "update remote_user set remote_userid=:RemoteUser_remote_userid, sys_userid=:RemoteUser_sys_userid, sys_groupid=:RemoteUser_sys_groupid, sys_perm_user=:RemoteUser_sys_perm_user, sys_perm_group=:RemoteUser_sys_perm_group, sys_perm_other=:RemoteUser_sys_perm_other, remote_username=:RemoteUser_remote_username, remote_password=:RemoteUser_remote_password, remote_functions=:RemoteUser_remote_functions WHERE remote_userid=:RemoteUser_remote_userid", use(remoteuser);
}

void RemoteUserRepository::update(const RemoteUser& oldObj, const RemoteUser& newObj)
{
	dataBase << "update remote_user set remote_userid=:RemoteUser_remote_userid, sys_userid=:RemoteUser_sys_userid, sys_groupid=:RemoteUser_sys_groupid, sys_perm_user=:RemoteUser_sys_perm_user, sys_perm_group=:RemoteUser_sys_perm_group, sys_perm_other=:RemoteUser_sys_perm_other, remote_username=:RemoteUser_remote_username, remote_password=:RemoteUser_remote_password, remote_functions=:RemoteUser_remote_functions WHERE remote_userid='"<<oldObj.getRemoteUserid()<<"\'", use(newObj);
}

