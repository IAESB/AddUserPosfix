#include "mailuserfilterrepository.h"
#include "util.hpp"
MailUserFilterRepository::MailUserFilterRepository(soci::session& db) : dataBase(db)
{
}

MailUserFilterPtr MailUserFilterRepository::select(const MailUserFilter& obj)
{
	soci::row row;
	MailUserFilterPtr mailuserfilter(new MailUserFilter);
	dataBase << "SELECT  mail_user_filter.filter_id as MailUserFilter_filter_id, mail_user_filter.sys_userid as MailUserFilter_sys_userid, mail_user_filter.sys_groupid as MailUserFilter_sys_groupid, mail_user_filter.sys_perm_user as MailUserFilter_sys_perm_user, mail_user_filter.sys_perm_group as MailUserFilter_sys_perm_group, mail_user_filter.sys_perm_other as MailUserFilter_sys_perm_other, mail_user_filter.mailuser_id as MailUserFilter_mailuser_id, mail_user_filter.rulename as MailUserFilter_rulename, mail_user_filter.source as MailUserFilter_source, mail_user_filter.searchterm as MailUserFilter_searchterm, mail_user_filter.op as MailUserFilter_op, mail_user_filter.action as MailUserFilter_action, mail_user_filter.target as MailUserFilter_target, mail_user_filter.active as MailUserFilter_active"
	" FROM mail_user_filter "
	"WHERE mail_user_filter.filter_id = :MailUserFilter_filter_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailuserfilter.reset();
	else
		type_conversion<MailUserFilter>::from_base(row, i_ok, *mailuserfilter);
	return mailuserfilter;
}
MailUserFilterList MailUserFilterRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_user_filter.filter_id as MailUserFilter_filter_id, mail_user_filter.sys_userid as MailUserFilter_sys_userid, mail_user_filter.sys_groupid as MailUserFilter_sys_groupid, mail_user_filter.sys_perm_user as MailUserFilter_sys_perm_user, mail_user_filter.sys_perm_group as MailUserFilter_sys_perm_group, mail_user_filter.sys_perm_other as MailUserFilter_sys_perm_other, mail_user_filter.mailuser_id as MailUserFilter_mailuser_id, mail_user_filter.rulename as MailUserFilter_rulename, mail_user_filter.source as MailUserFilter_source, mail_user_filter.searchterm as MailUserFilter_searchterm, mail_user_filter.op as MailUserFilter_op, mail_user_filter.action as MailUserFilter_action, mail_user_filter.target as MailUserFilter_target, mail_user_filter.active as MailUserFilter_active "
	" FROM mail_user_filter" 
	<< (where.size()?" WHERE "+where:"");
	MailUserFilterList mailuserfilterList;
	for(row& r: rs)
	{
		MailUserFilterPtr mailuserfilter(new MailUserFilter);
		type_conversion<MailUserFilter>::from_base(r, i_ok, *mailuserfilter);
		mailuserfilterList.push_back(mailuserfilter);
	}
	return mailuserfilterList;
}

int MailUserFilterRepository::insert(const MailUserFilter& mailuserfilter)
{
	dataBase << "insert into mail_user_filter(filter_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, mailuser_id, rulename, source, searchterm, op, action, target, active)\
values(:MailUserFilter_filter_id, :MailUserFilter_sys_userid, :MailUserFilter_sys_groupid, :MailUserFilter_sys_perm_user, :MailUserFilter_sys_perm_group, :MailUserFilter_sys_perm_other, :MailUserFilter_mailuser_id, :MailUserFilter_rulename, :MailUserFilter_source, :MailUserFilter_searchterm, :MailUserFilter_op, :MailUserFilter_action, :MailUserFilter_target, :MailUserFilter_active)", use(mailuserfilter);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailUserFilterRepository::remove(const MailUserFilter& mailuserfilter)
{
	dataBase << "DELETE from mail_user_filter WHERE filter_id=:MailUserFilter_filter_id", use(mailuserfilter);
}

void MailUserFilterRepository::update(const MailUserFilter& mailuserfilter)
{
	dataBase << "update mail_user_filter set filter_id=:MailUserFilter_filter_id, sys_userid=:MailUserFilter_sys_userid, sys_groupid=:MailUserFilter_sys_groupid, sys_perm_user=:MailUserFilter_sys_perm_user, sys_perm_group=:MailUserFilter_sys_perm_group, sys_perm_other=:MailUserFilter_sys_perm_other, mailuser_id=:MailUserFilter_mailuser_id, rulename=:MailUserFilter_rulename, source=:MailUserFilter_source, searchterm=:MailUserFilter_searchterm, op=:MailUserFilter_op, action=:MailUserFilter_action, target=:MailUserFilter_target, active=:MailUserFilter_active WHERE filter_id=:MailUserFilter_filter_id", use(mailuserfilter);
}

void MailUserFilterRepository::update(const MailUserFilter& oldObj, const MailUserFilter& newObj)
{
	dataBase << "update mail_user_filter set filter_id=:MailUserFilter_filter_id, sys_userid=:MailUserFilter_sys_userid, sys_groupid=:MailUserFilter_sys_groupid, sys_perm_user=:MailUserFilter_sys_perm_user, sys_perm_group=:MailUserFilter_sys_perm_group, sys_perm_other=:MailUserFilter_sys_perm_other, mailuser_id=:MailUserFilter_mailuser_id, rulename=:MailUserFilter_rulename, source=:MailUserFilter_source, searchterm=:MailUserFilter_searchterm, op=:MailUserFilter_op, action=:MailUserFilter_action, target=:MailUserFilter_target, active=:MailUserFilter_active WHERE filter_id='"<<oldObj.getFilterId()<<"\'", use(newObj);
}

