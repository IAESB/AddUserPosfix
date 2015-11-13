#include "spamfilterwblistrepository.h"
#include "util.hpp"
SpamfilterWblistRepository::SpamfilterWblistRepository(soci::session& db) : dataBase(db)
{
}

SpamfilterWblistPtr SpamfilterWblistRepository::select(const SpamfilterWblist& obj)
{
	soci::row row;
	SpamfilterWblistPtr spamfilterwblist(new SpamfilterWblist);
	dataBase << "SELECT  spamfilter_wblist.wblist_id as SpamfilterWblist_wblist_id, spamfilter_wblist.sys_userid as SpamfilterWblist_sys_userid, spamfilter_wblist.sys_groupid as SpamfilterWblist_sys_groupid, spamfilter_wblist.sys_perm_user as SpamfilterWblist_sys_perm_user, spamfilter_wblist.sys_perm_group as SpamfilterWblist_sys_perm_group, spamfilter_wblist.sys_perm_other as SpamfilterWblist_sys_perm_other, spamfilter_wblist.server_id as SpamfilterWblist_server_id, spamfilter_wblist.wb as SpamfilterWblist_wb, spamfilter_wblist.rid as SpamfilterWblist_rid, spamfilter_wblist.email as SpamfilterWblist_email, spamfilter_wblist.priority as SpamfilterWblist_priority, spamfilter_wblist.active as SpamfilterWblist_active"
	" FROM spamfilter_wblist "
	"WHERE spamfilter_wblist.wblist_id = :SpamfilterWblist_wblist_id", into(row), use(obj);
	if(!dataBase.got_data())
		spamfilterwblist.reset();
	else
		type_conversion<SpamfilterWblist>::from_base(row, i_ok, *spamfilterwblist);
	return spamfilterwblist;
}
SpamfilterWblistList SpamfilterWblistRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  spamfilter_wblist.wblist_id as SpamfilterWblist_wblist_id, spamfilter_wblist.sys_userid as SpamfilterWblist_sys_userid, spamfilter_wblist.sys_groupid as SpamfilterWblist_sys_groupid, spamfilter_wblist.sys_perm_user as SpamfilterWblist_sys_perm_user, spamfilter_wblist.sys_perm_group as SpamfilterWblist_sys_perm_group, spamfilter_wblist.sys_perm_other as SpamfilterWblist_sys_perm_other, spamfilter_wblist.server_id as SpamfilterWblist_server_id, spamfilter_wblist.wb as SpamfilterWblist_wb, spamfilter_wblist.rid as SpamfilterWblist_rid, spamfilter_wblist.email as SpamfilterWblist_email, spamfilter_wblist.priority as SpamfilterWblist_priority, spamfilter_wblist.active as SpamfilterWblist_active "
	" FROM spamfilter_wblist" 
	<< (where.size()?" WHERE "+where:"");
	SpamfilterWblistList spamfilterwblistList;
	for(row& r: rs)
	{
		SpamfilterWblistPtr spamfilterwblist(new SpamfilterWblist);
		type_conversion<SpamfilterWblist>::from_base(r, i_ok, *spamfilterwblist);
		spamfilterwblistList.push_back(spamfilterwblist);
	}
	return spamfilterwblistList;
}

int SpamfilterWblistRepository::insert(const SpamfilterWblist& spamfilterwblist)
{
	dataBase << "insert into spamfilter_wblist(wblist_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, wb, rid, email, priority, active)\
values(:SpamfilterWblist_wblist_id, :SpamfilterWblist_sys_userid, :SpamfilterWblist_sys_groupid, :SpamfilterWblist_sys_perm_user, :SpamfilterWblist_sys_perm_group, :SpamfilterWblist_sys_perm_other, :SpamfilterWblist_server_id, :SpamfilterWblist_wb, :SpamfilterWblist_rid, :SpamfilterWblist_email, :SpamfilterWblist_priority, :SpamfilterWblist_active)", use(spamfilterwblist);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SpamfilterWblistRepository::remove(const SpamfilterWblist& spamfilterwblist)
{
	dataBase << "DELETE from spamfilter_wblist WHERE wblist_id=:SpamfilterWblist_wblist_id", use(spamfilterwblist);
}

void SpamfilterWblistRepository::update(const SpamfilterWblist& spamfilterwblist)
{
	dataBase << "update spamfilter_wblist set wblist_id=:SpamfilterWblist_wblist_id, sys_userid=:SpamfilterWblist_sys_userid, sys_groupid=:SpamfilterWblist_sys_groupid, sys_perm_user=:SpamfilterWblist_sys_perm_user, sys_perm_group=:SpamfilterWblist_sys_perm_group, sys_perm_other=:SpamfilterWblist_sys_perm_other, server_id=:SpamfilterWblist_server_id, wb=:SpamfilterWblist_wb, rid=:SpamfilterWblist_rid, email=:SpamfilterWblist_email, priority=:SpamfilterWblist_priority, active=:SpamfilterWblist_active WHERE wblist_id=:SpamfilterWblist_wblist_id", use(spamfilterwblist);
}

void SpamfilterWblistRepository::update(const SpamfilterWblist& oldObj, const SpamfilterWblist& newObj)
{
	dataBase << "update spamfilter_wblist set wblist_id=:SpamfilterWblist_wblist_id, sys_userid=:SpamfilterWblist_sys_userid, sys_groupid=:SpamfilterWblist_sys_groupid, sys_perm_user=:SpamfilterWblist_sys_perm_user, sys_perm_group=:SpamfilterWblist_sys_perm_group, sys_perm_other=:SpamfilterWblist_sys_perm_other, server_id=:SpamfilterWblist_server_id, wb=:SpamfilterWblist_wb, rid=:SpamfilterWblist_rid, email=:SpamfilterWblist_email, priority=:SpamfilterWblist_priority, active=:SpamfilterWblist_active WHERE wblist_id='"<<oldObj.getWblistId()<<"\'", use(newObj);
}

