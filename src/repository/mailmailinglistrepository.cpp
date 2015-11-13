#include "mailmailinglistrepository.h"
#include "util.hpp"
MailMailinglistRepository::MailMailinglistRepository(soci::session& db) : dataBase(db)
{
}

MailMailinglistPtr MailMailinglistRepository::select(const MailMailinglist& obj)
{
	soci::row row;
	MailMailinglistPtr mailmailinglist(new MailMailinglist);
	dataBase << "SELECT  mail_mailinglist.mailinglist_id as MailMailinglist_mailinglist_id, mail_mailinglist.sys_userid as MailMailinglist_sys_userid, mail_mailinglist.sys_groupid as MailMailinglist_sys_groupid, mail_mailinglist.sys_perm_user as MailMailinglist_sys_perm_user, mail_mailinglist.sys_perm_group as MailMailinglist_sys_perm_group, mail_mailinglist.sys_perm_other as MailMailinglist_sys_perm_other, mail_mailinglist.server_id as MailMailinglist_server_id, mail_mailinglist.domain as MailMailinglist_domain, mail_mailinglist.listname as MailMailinglist_listname, mail_mailinglist.email as MailMailinglist_email, mail_mailinglist.password as MailMailinglist_password"
	" FROM mail_mailinglist "
	"WHERE mail_mailinglist.mailinglist_id = :MailMailinglist_mailinglist_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailmailinglist.reset();
	else
		type_conversion<MailMailinglist>::from_base(row, i_ok, *mailmailinglist);
	return mailmailinglist;
}
MailMailinglistList MailMailinglistRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_mailinglist.mailinglist_id as MailMailinglist_mailinglist_id, mail_mailinglist.sys_userid as MailMailinglist_sys_userid, mail_mailinglist.sys_groupid as MailMailinglist_sys_groupid, mail_mailinglist.sys_perm_user as MailMailinglist_sys_perm_user, mail_mailinglist.sys_perm_group as MailMailinglist_sys_perm_group, mail_mailinglist.sys_perm_other as MailMailinglist_sys_perm_other, mail_mailinglist.server_id as MailMailinglist_server_id, mail_mailinglist.domain as MailMailinglist_domain, mail_mailinglist.listname as MailMailinglist_listname, mail_mailinglist.email as MailMailinglist_email, mail_mailinglist.password as MailMailinglist_password "
	" FROM mail_mailinglist" 
	<< (where.size()?" WHERE "+where:"");
	MailMailinglistList mailmailinglistList;
	for(row& r: rs)
	{
		MailMailinglistPtr mailmailinglist(new MailMailinglist);
		type_conversion<MailMailinglist>::from_base(r, i_ok, *mailmailinglist);
		mailmailinglistList.push_back(mailmailinglist);
	}
	return mailmailinglistList;
}

int MailMailinglistRepository::insert(const MailMailinglist& mailmailinglist)
{
	dataBase << "insert into mail_mailinglist(mailinglist_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, domain, listname, email, password)\
values(:MailMailinglist_mailinglist_id, :MailMailinglist_sys_userid, :MailMailinglist_sys_groupid, :MailMailinglist_sys_perm_user, :MailMailinglist_sys_perm_group, :MailMailinglist_sys_perm_other, :MailMailinglist_server_id, :MailMailinglist_domain, :MailMailinglist_listname, :MailMailinglist_email, :MailMailinglist_password)", use(mailmailinglist);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailMailinglistRepository::remove(const MailMailinglist& mailmailinglist)
{
	dataBase << "DELETE from mail_mailinglist WHERE mailinglist_id=:MailMailinglist_mailinglist_id", use(mailmailinglist);
}

void MailMailinglistRepository::update(const MailMailinglist& mailmailinglist)
{
	dataBase << "update mail_mailinglist set mailinglist_id=:MailMailinglist_mailinglist_id, sys_userid=:MailMailinglist_sys_userid, sys_groupid=:MailMailinglist_sys_groupid, sys_perm_user=:MailMailinglist_sys_perm_user, sys_perm_group=:MailMailinglist_sys_perm_group, sys_perm_other=:MailMailinglist_sys_perm_other, server_id=:MailMailinglist_server_id, domain=:MailMailinglist_domain, listname=:MailMailinglist_listname, email=:MailMailinglist_email, password=:MailMailinglist_password WHERE mailinglist_id=:MailMailinglist_mailinglist_id", use(mailmailinglist);
}

void MailMailinglistRepository::update(const MailMailinglist& oldObj, const MailMailinglist& newObj)
{
	dataBase << "update mail_mailinglist set mailinglist_id=:MailMailinglist_mailinglist_id, sys_userid=:MailMailinglist_sys_userid, sys_groupid=:MailMailinglist_sys_groupid, sys_perm_user=:MailMailinglist_sys_perm_user, sys_perm_group=:MailMailinglist_sys_perm_group, sys_perm_other=:MailMailinglist_sys_perm_other, server_id=:MailMailinglist_server_id, domain=:MailMailinglist_domain, listname=:MailMailinglist_listname, email=:MailMailinglist_email, password=:MailMailinglist_password WHERE mailinglist_id='"<<oldObj.getMailinglistId()<<"\'", use(newObj);
}

