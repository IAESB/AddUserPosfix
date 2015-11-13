#include "webdavuserrepository.h"
#include "util.hpp"
WebdavUserRepository::WebdavUserRepository(soci::session& db) : dataBase(db)
{
}

WebdavUserPtr WebdavUserRepository::select(const WebdavUser& obj)
{
	soci::row row;
	WebdavUserPtr webdavuser(new WebdavUser);
	dataBase << "SELECT  webdav_user.webdav_user_id as WebdavUser_webdav_user_id, webdav_user.sys_userid as WebdavUser_sys_userid, webdav_user.sys_groupid as WebdavUser_sys_groupid, webdav_user.sys_perm_user as WebdavUser_sys_perm_user, webdav_user.sys_perm_group as WebdavUser_sys_perm_group, webdav_user.sys_perm_other as WebdavUser_sys_perm_other, webdav_user.server_id as WebdavUser_server_id, webdav_user.parent_domain_id as WebdavUser_parent_domain_id, webdav_user.username as WebdavUser_username, webdav_user.username_prefix as WebdavUser_username_prefix, webdav_user.password as WebdavUser_password, webdav_user.active as WebdavUser_active, webdav_user.dir as WebdavUser_dir"
	" FROM webdav_user "
	"WHERE webdav_user.webdav_user_id = :WebdavUser_webdav_user_id", into(row), use(obj);
	if(!dataBase.got_data())
		webdavuser.reset();
	else
		type_conversion<WebdavUser>::from_base(row, i_ok, *webdavuser);
	return webdavuser;
}
WebdavUserList WebdavUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  webdav_user.webdav_user_id as WebdavUser_webdav_user_id, webdav_user.sys_userid as WebdavUser_sys_userid, webdav_user.sys_groupid as WebdavUser_sys_groupid, webdav_user.sys_perm_user as WebdavUser_sys_perm_user, webdav_user.sys_perm_group as WebdavUser_sys_perm_group, webdav_user.sys_perm_other as WebdavUser_sys_perm_other, webdav_user.server_id as WebdavUser_server_id, webdav_user.parent_domain_id as WebdavUser_parent_domain_id, webdav_user.username as WebdavUser_username, webdav_user.username_prefix as WebdavUser_username_prefix, webdav_user.password as WebdavUser_password, webdav_user.active as WebdavUser_active, webdav_user.dir as WebdavUser_dir "
	" FROM webdav_user" 
	<< (where.size()?" WHERE "+where:"");
	WebdavUserList webdavuserList;
	for(row& r: rs)
	{
		WebdavUserPtr webdavuser(new WebdavUser);
		type_conversion<WebdavUser>::from_base(r, i_ok, *webdavuser);
		webdavuserList.push_back(webdavuser);
	}
	return webdavuserList;
}

int WebdavUserRepository::insert(const WebdavUser& webdavuser)
{
	dataBase << "insert into webdav_user(webdav_user_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, username, username_prefix, password, active, dir)\
values(:WebdavUser_webdav_user_id, :WebdavUser_sys_userid, :WebdavUser_sys_groupid, :WebdavUser_sys_perm_user, :WebdavUser_sys_perm_group, :WebdavUser_sys_perm_other, :WebdavUser_server_id, :WebdavUser_parent_domain_id, :WebdavUser_username, :WebdavUser_username_prefix, :WebdavUser_password, :WebdavUser_active, :WebdavUser_dir)", use(webdavuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebdavUserRepository::remove(const WebdavUser& webdavuser)
{
	dataBase << "DELETE from webdav_user WHERE webdav_user_id=:WebdavUser_webdav_user_id", use(webdavuser);
}

void WebdavUserRepository::update(const WebdavUser& webdavuser)
{
	dataBase << "update webdav_user set webdav_user_id=:WebdavUser_webdav_user_id, sys_userid=:WebdavUser_sys_userid, sys_groupid=:WebdavUser_sys_groupid, sys_perm_user=:WebdavUser_sys_perm_user, sys_perm_group=:WebdavUser_sys_perm_group, sys_perm_other=:WebdavUser_sys_perm_other, server_id=:WebdavUser_server_id, parent_domain_id=:WebdavUser_parent_domain_id, username=:WebdavUser_username, username_prefix=:WebdavUser_username_prefix, password=:WebdavUser_password, active=:WebdavUser_active, dir=:WebdavUser_dir WHERE webdav_user_id=:WebdavUser_webdav_user_id", use(webdavuser);
}

void WebdavUserRepository::update(const WebdavUser& oldObj, const WebdavUser& newObj)
{
	dataBase << "update webdav_user set webdav_user_id=:WebdavUser_webdav_user_id, sys_userid=:WebdavUser_sys_userid, sys_groupid=:WebdavUser_sys_groupid, sys_perm_user=:WebdavUser_sys_perm_user, sys_perm_group=:WebdavUser_sys_perm_group, sys_perm_other=:WebdavUser_sys_perm_other, server_id=:WebdavUser_server_id, parent_domain_id=:WebdavUser_parent_domain_id, username=:WebdavUser_username, username_prefix=:WebdavUser_username_prefix, password=:WebdavUser_password, active=:WebdavUser_active, dir=:WebdavUser_dir WHERE webdav_user_id='"<<oldObj.getWebdavUserId()<<"\'", use(newObj);
}

