#include "mailcontentfilterrepository.h"
#include "util.hpp"
MailContentFilterRepository::MailContentFilterRepository(soci::session& db) : dataBase(db)
{
}

MailContentFilterPtr MailContentFilterRepository::select(const MailContentFilter& obj)
{
	soci::row row;
	MailContentFilterPtr mailcontentfilter(new MailContentFilter);
	dataBase << "SELECT  mail_content_filter.content_filter_id as MailContentFilter_content_filter_id, mail_content_filter.sys_userid as MailContentFilter_sys_userid, mail_content_filter.sys_groupid as MailContentFilter_sys_groupid, mail_content_filter.sys_perm_user as MailContentFilter_sys_perm_user, mail_content_filter.sys_perm_group as MailContentFilter_sys_perm_group, mail_content_filter.sys_perm_other as MailContentFilter_sys_perm_other, mail_content_filter.server_id as MailContentFilter_server_id, mail_content_filter.type as MailContentFilter_type, mail_content_filter.pattern as MailContentFilter_pattern, mail_content_filter.data as MailContentFilter_data, mail_content_filter.action as MailContentFilter_action, mail_content_filter.active as MailContentFilter_active"
	" FROM mail_content_filter "
	"WHERE mail_content_filter.content_filter_id = :MailContentFilter_content_filter_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailcontentfilter.reset();
	else
		type_conversion<MailContentFilter>::from_base(row, i_ok, *mailcontentfilter);
	return mailcontentfilter;
}
MailContentFilterList MailContentFilterRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_content_filter.content_filter_id as MailContentFilter_content_filter_id, mail_content_filter.sys_userid as MailContentFilter_sys_userid, mail_content_filter.sys_groupid as MailContentFilter_sys_groupid, mail_content_filter.sys_perm_user as MailContentFilter_sys_perm_user, mail_content_filter.sys_perm_group as MailContentFilter_sys_perm_group, mail_content_filter.sys_perm_other as MailContentFilter_sys_perm_other, mail_content_filter.server_id as MailContentFilter_server_id, mail_content_filter.type as MailContentFilter_type, mail_content_filter.pattern as MailContentFilter_pattern, mail_content_filter.data as MailContentFilter_data, mail_content_filter.action as MailContentFilter_action, mail_content_filter.active as MailContentFilter_active "
	" FROM mail_content_filter" 
	<< (where.size()?" WHERE "+where:"");
	MailContentFilterList mailcontentfilterList;
	for(row& r: rs)
	{
		MailContentFilterPtr mailcontentfilter(new MailContentFilter);
		type_conversion<MailContentFilter>::from_base(r, i_ok, *mailcontentfilter);
		mailcontentfilterList.push_back(mailcontentfilter);
	}
	return mailcontentfilterList;
}

int MailContentFilterRepository::insert(const MailContentFilter& mailcontentfilter)
{
	dataBase << "insert into mail_content_filter(content_filter_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, type, pattern, data, action, active)\
values(:MailContentFilter_content_filter_id, :MailContentFilter_sys_userid, :MailContentFilter_sys_groupid, :MailContentFilter_sys_perm_user, :MailContentFilter_sys_perm_group, :MailContentFilter_sys_perm_other, :MailContentFilter_server_id, :MailContentFilter_type, :MailContentFilter_pattern, :MailContentFilter_data, :MailContentFilter_action, :MailContentFilter_active)", use(mailcontentfilter);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailContentFilterRepository::remove(const MailContentFilter& mailcontentfilter)
{
	dataBase << "DELETE from mail_content_filter WHERE content_filter_id=:MailContentFilter_content_filter_id", use(mailcontentfilter);
}

void MailContentFilterRepository::update(const MailContentFilter& mailcontentfilter)
{
	dataBase << "update mail_content_filter set content_filter_id=:MailContentFilter_content_filter_id, sys_userid=:MailContentFilter_sys_userid, sys_groupid=:MailContentFilter_sys_groupid, sys_perm_user=:MailContentFilter_sys_perm_user, sys_perm_group=:MailContentFilter_sys_perm_group, sys_perm_other=:MailContentFilter_sys_perm_other, server_id=:MailContentFilter_server_id, type=:MailContentFilter_type, pattern=:MailContentFilter_pattern, data=:MailContentFilter_data, action=:MailContentFilter_action, active=:MailContentFilter_active WHERE content_filter_id=:MailContentFilter_content_filter_id", use(mailcontentfilter);
}

void MailContentFilterRepository::update(const MailContentFilter& oldObj, const MailContentFilter& newObj)
{
	dataBase << "update mail_content_filter set content_filter_id=:MailContentFilter_content_filter_id, sys_userid=:MailContentFilter_sys_userid, sys_groupid=:MailContentFilter_sys_groupid, sys_perm_user=:MailContentFilter_sys_perm_user, sys_perm_group=:MailContentFilter_sys_perm_group, sys_perm_other=:MailContentFilter_sys_perm_other, server_id=:MailContentFilter_server_id, type=:MailContentFilter_type, pattern=:MailContentFilter_pattern, data=:MailContentFilter_data, action=:MailContentFilter_action, active=:MailContentFilter_active WHERE content_filter_id='"<<oldObj.getContentFilterId()<<"\'", use(newObj);
}

