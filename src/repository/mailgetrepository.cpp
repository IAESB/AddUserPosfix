#include "mailgetrepository.h"
#include "util.hpp"
MailGetRepository::MailGetRepository(soci::session& db) : dataBase(db)
{
}

MailGetPtr MailGetRepository::select(const MailGet& obj)
{
	soci::row row;
	MailGetPtr mailget(new MailGet);
	dataBase << "SELECT  mail_get.mailget_id as MailGet_mailget_id, mail_get.sys_userid as MailGet_sys_userid, mail_get.sys_groupid as MailGet_sys_groupid, mail_get.sys_perm_user as MailGet_sys_perm_user, mail_get.sys_perm_group as MailGet_sys_perm_group, mail_get.sys_perm_other as MailGet_sys_perm_other, mail_get.server_id as MailGet_server_id, mail_get.type as MailGet_type, mail_get.source_server as MailGet_source_server, mail_get.source_username as MailGet_source_username, mail_get.source_password as MailGet_source_password, mail_get.source_delete as MailGet_source_delete, mail_get.source_read_all as MailGet_source_read_all, mail_get.destination as MailGet_destination, mail_get.active as MailGet_active"
	" FROM mail_get "
	"WHERE mail_get.mailget_id = :MailGet_mailget_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailget.reset();
	else
		type_conversion<MailGet>::from_base(row, i_ok, *mailget);
	return mailget;
}
MailGetList MailGetRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_get.mailget_id as MailGet_mailget_id, mail_get.sys_userid as MailGet_sys_userid, mail_get.sys_groupid as MailGet_sys_groupid, mail_get.sys_perm_user as MailGet_sys_perm_user, mail_get.sys_perm_group as MailGet_sys_perm_group, mail_get.sys_perm_other as MailGet_sys_perm_other, mail_get.server_id as MailGet_server_id, mail_get.type as MailGet_type, mail_get.source_server as MailGet_source_server, mail_get.source_username as MailGet_source_username, mail_get.source_password as MailGet_source_password, mail_get.source_delete as MailGet_source_delete, mail_get.source_read_all as MailGet_source_read_all, mail_get.destination as MailGet_destination, mail_get.active as MailGet_active "
	" FROM mail_get" 
	<< (where.size()?" WHERE "+where:"");
	MailGetList mailgetList;
	for(row& r: rs)
	{
		MailGetPtr mailget(new MailGet);
		type_conversion<MailGet>::from_base(r, i_ok, *mailget);
		mailgetList.push_back(mailget);
	}
	return mailgetList;
}

int MailGetRepository::insert(const MailGet& mailget)
{
	dataBase << "insert into mail_get(mailget_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, type, source_server, source_username, source_password, source_delete, source_read_all, destination, active)\
values(:MailGet_mailget_id, :MailGet_sys_userid, :MailGet_sys_groupid, :MailGet_sys_perm_user, :MailGet_sys_perm_group, :MailGet_sys_perm_other, :MailGet_server_id, :MailGet_type, :MailGet_source_server, :MailGet_source_username, :MailGet_source_password, :MailGet_source_delete, :MailGet_source_read_all, :MailGet_destination, :MailGet_active)", use(mailget);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailGetRepository::remove(const MailGet& mailget)
{
	dataBase << "DELETE from mail_get WHERE mailget_id=:MailGet_mailget_id", use(mailget);
}

void MailGetRepository::update(const MailGet& mailget)
{
	dataBase << "update mail_get set mailget_id=:MailGet_mailget_id, sys_userid=:MailGet_sys_userid, sys_groupid=:MailGet_sys_groupid, sys_perm_user=:MailGet_sys_perm_user, sys_perm_group=:MailGet_sys_perm_group, sys_perm_other=:MailGet_sys_perm_other, server_id=:MailGet_server_id, type=:MailGet_type, source_server=:MailGet_source_server, source_username=:MailGet_source_username, source_password=:MailGet_source_password, source_delete=:MailGet_source_delete, source_read_all=:MailGet_source_read_all, destination=:MailGet_destination, active=:MailGet_active WHERE mailget_id=:MailGet_mailget_id", use(mailget);
}

void MailGetRepository::update(const MailGet& oldObj, const MailGet& newObj)
{
	dataBase << "update mail_get set mailget_id=:MailGet_mailget_id, sys_userid=:MailGet_sys_userid, sys_groupid=:MailGet_sys_groupid, sys_perm_user=:MailGet_sys_perm_user, sys_perm_group=:MailGet_sys_perm_group, sys_perm_other=:MailGet_sys_perm_other, server_id=:MailGet_server_id, type=:MailGet_type, source_server=:MailGet_source_server, source_username=:MailGet_source_username, source_password=:MailGet_source_password, source_delete=:MailGet_source_delete, source_read_all=:MailGet_source_read_all, destination=:MailGet_destination, active=:MailGet_active WHERE mailget_id='"<<oldObj.getMailgetId()<<"\'", use(newObj);
}

