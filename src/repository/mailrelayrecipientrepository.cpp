#include "mailrelayrecipientrepository.h"
#include "util.hpp"
MailRelayRecipientRepository::MailRelayRecipientRepository(soci::session& db) : dataBase(db)
{
}

MailRelayRecipientPtr MailRelayRecipientRepository::select(const MailRelayRecipient& obj)
{
	soci::row row;
	MailRelayRecipientPtr mailrelayrecipient(new MailRelayRecipient);
	dataBase << "SELECT  mail_relay_recipient.relay_recipient_id as MailRelayRecipient_relay_recipient_id, mail_relay_recipient.sys_userid as MailRelayRecipient_sys_userid, mail_relay_recipient.sys_groupid as MailRelayRecipient_sys_groupid, mail_relay_recipient.sys_perm_user as MailRelayRecipient_sys_perm_user, mail_relay_recipient.sys_perm_group as MailRelayRecipient_sys_perm_group, mail_relay_recipient.sys_perm_other as MailRelayRecipient_sys_perm_other, mail_relay_recipient.server_id as MailRelayRecipient_server_id, mail_relay_recipient.source as MailRelayRecipient_source, mail_relay_recipient.access as MailRelayRecipient_access, mail_relay_recipient.active as MailRelayRecipient_active"
	" FROM mail_relay_recipient "
	"WHERE mail_relay_recipient.relay_recipient_id = :MailRelayRecipient_relay_recipient_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailrelayrecipient.reset();
	else
		type_conversion<MailRelayRecipient>::from_base(row, i_ok, *mailrelayrecipient);
	return mailrelayrecipient;
}
MailRelayRecipientList MailRelayRecipientRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_relay_recipient.relay_recipient_id as MailRelayRecipient_relay_recipient_id, mail_relay_recipient.sys_userid as MailRelayRecipient_sys_userid, mail_relay_recipient.sys_groupid as MailRelayRecipient_sys_groupid, mail_relay_recipient.sys_perm_user as MailRelayRecipient_sys_perm_user, mail_relay_recipient.sys_perm_group as MailRelayRecipient_sys_perm_group, mail_relay_recipient.sys_perm_other as MailRelayRecipient_sys_perm_other, mail_relay_recipient.server_id as MailRelayRecipient_server_id, mail_relay_recipient.source as MailRelayRecipient_source, mail_relay_recipient.access as MailRelayRecipient_access, mail_relay_recipient.active as MailRelayRecipient_active "
	" FROM mail_relay_recipient" 
	<< (where.size()?" WHERE "+where:"");
	MailRelayRecipientList mailrelayrecipientList;
	for(row& r: rs)
	{
		MailRelayRecipientPtr mailrelayrecipient(new MailRelayRecipient);
		type_conversion<MailRelayRecipient>::from_base(r, i_ok, *mailrelayrecipient);
		mailrelayrecipientList.push_back(mailrelayrecipient);
	}
	return mailrelayrecipientList;
}

int MailRelayRecipientRepository::insert(const MailRelayRecipient& mailrelayrecipient)
{
	dataBase << "insert into mail_relay_recipient(relay_recipient_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, source, access, active)\
values(:MailRelayRecipient_relay_recipient_id, :MailRelayRecipient_sys_userid, :MailRelayRecipient_sys_groupid, :MailRelayRecipient_sys_perm_user, :MailRelayRecipient_sys_perm_group, :MailRelayRecipient_sys_perm_other, :MailRelayRecipient_server_id, :MailRelayRecipient_source, :MailRelayRecipient_access, :MailRelayRecipient_active)", use(mailrelayrecipient);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailRelayRecipientRepository::remove(const MailRelayRecipient& mailrelayrecipient)
{
	dataBase << "DELETE from mail_relay_recipient WHERE relay_recipient_id=:MailRelayRecipient_relay_recipient_id", use(mailrelayrecipient);
}

void MailRelayRecipientRepository::update(const MailRelayRecipient& mailrelayrecipient)
{
	dataBase << "update mail_relay_recipient set relay_recipient_id=:MailRelayRecipient_relay_recipient_id, sys_userid=:MailRelayRecipient_sys_userid, sys_groupid=:MailRelayRecipient_sys_groupid, sys_perm_user=:MailRelayRecipient_sys_perm_user, sys_perm_group=:MailRelayRecipient_sys_perm_group, sys_perm_other=:MailRelayRecipient_sys_perm_other, server_id=:MailRelayRecipient_server_id, source=:MailRelayRecipient_source, access=:MailRelayRecipient_access, active=:MailRelayRecipient_active WHERE relay_recipient_id=:MailRelayRecipient_relay_recipient_id", use(mailrelayrecipient);
}

void MailRelayRecipientRepository::update(const MailRelayRecipient& oldObj, const MailRelayRecipient& newObj)
{
	dataBase << "update mail_relay_recipient set relay_recipient_id=:MailRelayRecipient_relay_recipient_id, sys_userid=:MailRelayRecipient_sys_userid, sys_groupid=:MailRelayRecipient_sys_groupid, sys_perm_user=:MailRelayRecipient_sys_perm_user, sys_perm_group=:MailRelayRecipient_sys_perm_group, sys_perm_other=:MailRelayRecipient_sys_perm_other, server_id=:MailRelayRecipient_server_id, source=:MailRelayRecipient_source, access=:MailRelayRecipient_access, active=:MailRelayRecipient_active WHERE relay_recipient_id='"<<oldObj.getRelayRecipientId()<<"\'", use(newObj);
}

