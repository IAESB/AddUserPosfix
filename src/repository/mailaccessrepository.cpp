#include "mailaccessrepository.h"
#include "util.hpp"
MailAccessRepository::MailAccessRepository(soci::session& db) : dataBase(db)
{
}

MailAccessPtr MailAccessRepository::select(const MailAccess& obj)
{
	soci::row row;
	MailAccessPtr mailaccess(new MailAccess);
	dataBase << "SELECT  mail_access.access_id as MailAccess_access_id, mail_access.sys_userid as MailAccess_sys_userid, mail_access.sys_groupid as MailAccess_sys_groupid, mail_access.sys_perm_user as MailAccess_sys_perm_user, mail_access.sys_perm_group as MailAccess_sys_perm_group, mail_access.sys_perm_other as MailAccess_sys_perm_other, mail_access.server_id as MailAccess_server_id, mail_access.source as MailAccess_source, mail_access.access as MailAccess_access, mail_access.type as MailAccess_type, mail_access.active as MailAccess_active"
	" FROM mail_access "
	"WHERE mail_access.access_id = :MailAccess_access_id AND mail_access.server_id = :MailAccess_server_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailaccess.reset();
	else
		type_conversion<MailAccess>::from_base(row, i_ok, *mailaccess);
	return mailaccess;
}
MailAccessList MailAccessRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_access.access_id as MailAccess_access_id, mail_access.sys_userid as MailAccess_sys_userid, mail_access.sys_groupid as MailAccess_sys_groupid, mail_access.sys_perm_user as MailAccess_sys_perm_user, mail_access.sys_perm_group as MailAccess_sys_perm_group, mail_access.sys_perm_other as MailAccess_sys_perm_other, mail_access.server_id as MailAccess_server_id, mail_access.source as MailAccess_source, mail_access.access as MailAccess_access, mail_access.type as MailAccess_type, mail_access.active as MailAccess_active "
	" FROM mail_access" 
	<< (where.size()?" WHERE "+where:"");
	MailAccessList mailaccessList;
	for(row& r: rs)
	{
		MailAccessPtr mailaccess(new MailAccess);
		type_conversion<MailAccess>::from_base(r, i_ok, *mailaccess);
		mailaccessList.push_back(mailaccess);
	}
	return mailaccessList;
}

int MailAccessRepository::insert(const MailAccess& mailaccess)
{
	dataBase << "insert into mail_access(access_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, source, access, type, active)\
values(:MailAccess_access_id, :MailAccess_sys_userid, :MailAccess_sys_groupid, :MailAccess_sys_perm_user, :MailAccess_sys_perm_group, :MailAccess_sys_perm_other, :MailAccess_server_id, :MailAccess_source, :MailAccess_access, :MailAccess_type, :MailAccess_active)", use(mailaccess);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailAccessRepository::remove(const MailAccess& mailaccess)
{
	dataBase << "DELETE from mail_access WHERE access_id=:MailAccess_access_id AND server_id=:MailAccess_server_id", use(mailaccess);
}

void MailAccessRepository::update(const MailAccess& mailaccess)
{
	dataBase << "update mail_access set access_id=:MailAccess_access_id, sys_userid=:MailAccess_sys_userid, sys_groupid=:MailAccess_sys_groupid, sys_perm_user=:MailAccess_sys_perm_user, sys_perm_group=:MailAccess_sys_perm_group, sys_perm_other=:MailAccess_sys_perm_other, server_id=:MailAccess_server_id, source=:MailAccess_source, access=:MailAccess_access, type=:MailAccess_type, active=:MailAccess_active WHERE access_id=:MailAccess_access_id AND server_id=:MailAccess_server_id", use(mailaccess);
}

void MailAccessRepository::update(const MailAccess& oldObj, const MailAccess& newObj)
{
	dataBase << "update mail_access set access_id=:MailAccess_access_id, sys_userid=:MailAccess_sys_userid, sys_groupid=:MailAccess_sys_groupid, sys_perm_user=:MailAccess_sys_perm_user, sys_perm_group=:MailAccess_sys_perm_group, sys_perm_other=:MailAccess_sys_perm_other, server_id=:MailAccess_server_id, source=:MailAccess_source, access=:MailAccess_access, type=:MailAccess_type, active=:MailAccess_active WHERE access_id='"<<oldObj.getAccessId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'", use(newObj);
}

