#include "supportmessagerepository.h"
#include "util.hpp"
SupportMessageRepository::SupportMessageRepository(soci::session& db) : dataBase(db)
{
}

SupportMessagePtr SupportMessageRepository::select(const SupportMessage& obj)
{
	soci::row row;
	SupportMessagePtr supportmessage(new SupportMessage);
	dataBase << "SELECT  support_message.support_message_id as SupportMessage_support_message_id, support_message.sys_userid as SupportMessage_sys_userid, support_message.sys_groupid as SupportMessage_sys_groupid, support_message.sys_perm_user as SupportMessage_sys_perm_user, support_message.sys_perm_group as SupportMessage_sys_perm_group, support_message.sys_perm_other as SupportMessage_sys_perm_other, support_message.recipient_id as SupportMessage_recipient_id, support_message.sender_id as SupportMessage_sender_id, support_message.subject as SupportMessage_subject, support_message.message as SupportMessage_message, support_message.tstamp as SupportMessage_tstamp"
	" FROM support_message "
	"WHERE support_message.support_message_id = :SupportMessage_support_message_id", into(row), use(obj);
	if(!dataBase.got_data())
		supportmessage.reset();
	else
		type_conversion<SupportMessage>::from_base(row, i_ok, *supportmessage);
	return supportmessage;
}
SupportMessageList SupportMessageRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  support_message.support_message_id as SupportMessage_support_message_id, support_message.sys_userid as SupportMessage_sys_userid, support_message.sys_groupid as SupportMessage_sys_groupid, support_message.sys_perm_user as SupportMessage_sys_perm_user, support_message.sys_perm_group as SupportMessage_sys_perm_group, support_message.sys_perm_other as SupportMessage_sys_perm_other, support_message.recipient_id as SupportMessage_recipient_id, support_message.sender_id as SupportMessage_sender_id, support_message.subject as SupportMessage_subject, support_message.message as SupportMessage_message, support_message.tstamp as SupportMessage_tstamp "
	" FROM support_message" 
	<< (where.size()?" WHERE "+where:"");
	SupportMessageList supportmessageList;
	for(row& r: rs)
	{
		SupportMessagePtr supportmessage(new SupportMessage);
		type_conversion<SupportMessage>::from_base(r, i_ok, *supportmessage);
		supportmessageList.push_back(supportmessage);
	}
	return supportmessageList;
}

int SupportMessageRepository::insert(const SupportMessage& supportmessage)
{
	dataBase << "insert into support_message(support_message_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, recipient_id, sender_id, subject, message, tstamp)\
values(:SupportMessage_support_message_id, :SupportMessage_sys_userid, :SupportMessage_sys_groupid, :SupportMessage_sys_perm_user, :SupportMessage_sys_perm_group, :SupportMessage_sys_perm_other, :SupportMessage_recipient_id, :SupportMessage_sender_id, :SupportMessage_subject, :SupportMessage_message, :SupportMessage_tstamp)", use(supportmessage);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SupportMessageRepository::remove(const SupportMessage& supportmessage)
{
	dataBase << "DELETE from support_message WHERE support_message_id=:SupportMessage_support_message_id", use(supportmessage);
}

void SupportMessageRepository::update(const SupportMessage& supportmessage)
{
	dataBase << "update support_message set support_message_id=:SupportMessage_support_message_id, sys_userid=:SupportMessage_sys_userid, sys_groupid=:SupportMessage_sys_groupid, sys_perm_user=:SupportMessage_sys_perm_user, sys_perm_group=:SupportMessage_sys_perm_group, sys_perm_other=:SupportMessage_sys_perm_other, recipient_id=:SupportMessage_recipient_id, sender_id=:SupportMessage_sender_id, subject=:SupportMessage_subject, message=:SupportMessage_message, tstamp=:SupportMessage_tstamp WHERE support_message_id=:SupportMessage_support_message_id", use(supportmessage);
}

void SupportMessageRepository::update(const SupportMessage& oldObj, const SupportMessage& newObj)
{
	dataBase << "update support_message set support_message_id=:SupportMessage_support_message_id, sys_userid=:SupportMessage_sys_userid, sys_groupid=:SupportMessage_sys_groupid, sys_perm_user=:SupportMessage_sys_perm_user, sys_perm_group=:SupportMessage_sys_perm_group, sys_perm_other=:SupportMessage_sys_perm_other, recipient_id=:SupportMessage_recipient_id, sender_id=:SupportMessage_sender_id, subject=:SupportMessage_subject, message=:SupportMessage_message, tstamp=:SupportMessage_tstamp WHERE support_message_id='"<<oldObj.getSupportMessageId()<<"\'", use(newObj);
}

