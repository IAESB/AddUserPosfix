#include "mailforwardingrepository.h"
#include "util.hpp"
MailForwardingRepository::MailForwardingRepository(soci::session& db) : dataBase(db)
{
}

MailForwardingPtr MailForwardingRepository::select(const MailForwarding& obj)
{
	soci::row row;
	MailForwardingPtr mailforwarding(new MailForwarding);
	dataBase << "SELECT  mail_forwarding.forwarding_id as MailForwarding_forwarding_id, mail_forwarding.sys_userid as MailForwarding_sys_userid, mail_forwarding.sys_groupid as MailForwarding_sys_groupid, mail_forwarding.sys_perm_user as MailForwarding_sys_perm_user, mail_forwarding.sys_perm_group as MailForwarding_sys_perm_group, mail_forwarding.sys_perm_other as MailForwarding_sys_perm_other, mail_forwarding.server_id as MailForwarding_server_id, mail_forwarding.source as MailForwarding_source, mail_forwarding.destination as MailForwarding_destination, mail_forwarding.type as MailForwarding_type, mail_forwarding.active as MailForwarding_active"
	" FROM mail_forwarding "
	"WHERE mail_forwarding.forwarding_id = :MailForwarding_forwarding_id AND mail_forwarding.server_id = :MailForwarding_server_id AND mail_forwarding.type = :MailForwarding_type", into(row), use(obj);
	if(!dataBase.got_data())
		mailforwarding.reset();
	else
		type_conversion<MailForwarding>::from_base(row, i_ok, *mailforwarding);
	return mailforwarding;
}
MailForwardingList MailForwardingRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_forwarding.forwarding_id as MailForwarding_forwarding_id, mail_forwarding.sys_userid as MailForwarding_sys_userid, mail_forwarding.sys_groupid as MailForwarding_sys_groupid, mail_forwarding.sys_perm_user as MailForwarding_sys_perm_user, mail_forwarding.sys_perm_group as MailForwarding_sys_perm_group, mail_forwarding.sys_perm_other as MailForwarding_sys_perm_other, mail_forwarding.server_id as MailForwarding_server_id, mail_forwarding.source as MailForwarding_source, mail_forwarding.destination as MailForwarding_destination, mail_forwarding.type as MailForwarding_type, mail_forwarding.active as MailForwarding_active "
	" FROM mail_forwarding" 
	<< (where.size()?" WHERE "+where:"");
	MailForwardingList mailforwardingList;
	for(row& r: rs)
	{
		MailForwardingPtr mailforwarding(new MailForwarding);
		type_conversion<MailForwarding>::from_base(r, i_ok, *mailforwarding);
		mailforwardingList.push_back(mailforwarding);
	}
	return mailforwardingList;
}

int MailForwardingRepository::insert(const MailForwarding& mailforwarding)
{
	dataBase << "insert into mail_forwarding(forwarding_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, source, destination, type, active)\
values(:MailForwarding_forwarding_id, :MailForwarding_sys_userid, :MailForwarding_sys_groupid, :MailForwarding_sys_perm_user, :MailForwarding_sys_perm_group, :MailForwarding_sys_perm_other, :MailForwarding_server_id, :MailForwarding_source, :MailForwarding_destination, :MailForwarding_type, :MailForwarding_active)", use(mailforwarding);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailForwardingRepository::remove(const MailForwarding& mailforwarding)
{
	dataBase << "DELETE from mail_forwarding WHERE forwarding_id=:MailForwarding_forwarding_id AND server_id=:MailForwarding_server_id AND type=:MailForwarding_type", use(mailforwarding);
}

void MailForwardingRepository::update(const MailForwarding& mailforwarding)
{
	dataBase << "update mail_forwarding set forwarding_id=:MailForwarding_forwarding_id, sys_userid=:MailForwarding_sys_userid, sys_groupid=:MailForwarding_sys_groupid, sys_perm_user=:MailForwarding_sys_perm_user, sys_perm_group=:MailForwarding_sys_perm_group, sys_perm_other=:MailForwarding_sys_perm_other, server_id=:MailForwarding_server_id, source=:MailForwarding_source, destination=:MailForwarding_destination, type=:MailForwarding_type, active=:MailForwarding_active WHERE forwarding_id=:MailForwarding_forwarding_id AND server_id=:MailForwarding_server_id AND type=:MailForwarding_type", use(mailforwarding);
}

void MailForwardingRepository::update(const MailForwarding& oldObj, const MailForwarding& newObj)
{
	dataBase << "update mail_forwarding set forwarding_id=:MailForwarding_forwarding_id, sys_userid=:MailForwarding_sys_userid, sys_groupid=:MailForwarding_sys_groupid, sys_perm_user=:MailForwarding_sys_perm_user, sys_perm_group=:MailForwarding_sys_perm_group, sys_perm_other=:MailForwarding_sys_perm_other, server_id=:MailForwarding_server_id, source=:MailForwarding_source, destination=:MailForwarding_destination, type=:MailForwarding_type, active=:MailForwarding_active WHERE forwarding_id='"<<oldObj.getForwardingId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'' AND type='"<<oldObj.getType()<<"\'", use(newObj);
}

