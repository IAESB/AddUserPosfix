#include "spamfilterusersrepository.h"
#include "util.hpp"
SpamfilterUsersRepository::SpamfilterUsersRepository(soci::session& db) : dataBase(db)
{
}

SpamfilterUsersPtr SpamfilterUsersRepository::select(const SpamfilterUsers& obj)
{
	soci::row row;
	SpamfilterUsersPtr spamfilterusers(new SpamfilterUsers);
	dataBase << "SELECT  spamfilter_users.id as SpamfilterUsers_id, spamfilter_users.sys_userid as SpamfilterUsers_sys_userid, spamfilter_users.sys_groupid as SpamfilterUsers_sys_groupid, spamfilter_users.sys_perm_user as SpamfilterUsers_sys_perm_user, spamfilter_users.sys_perm_group as SpamfilterUsers_sys_perm_group, spamfilter_users.sys_perm_other as SpamfilterUsers_sys_perm_other, spamfilter_users.server_id as SpamfilterUsers_server_id, spamfilter_users.priority as SpamfilterUsers_priority, spamfilter_users.policy_id as SpamfilterUsers_policy_id, spamfilter_users.email as SpamfilterUsers_email, spamfilter_users.fullname as SpamfilterUsers_fullname, spamfilter_users.local as SpamfilterUsers_local"
	" FROM spamfilter_users "
	"WHERE spamfilter_users.id = :SpamfilterUsers_id AND spamfilter_users.email = :SpamfilterUsers_email", into(row), use(obj);
	if(!dataBase.got_data())
		spamfilterusers.reset();
	else
		type_conversion<SpamfilterUsers>::from_base(row, i_ok, *spamfilterusers);
	return spamfilterusers;
}
SpamfilterUsersList SpamfilterUsersRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  spamfilter_users.id as SpamfilterUsers_id, spamfilter_users.sys_userid as SpamfilterUsers_sys_userid, spamfilter_users.sys_groupid as SpamfilterUsers_sys_groupid, spamfilter_users.sys_perm_user as SpamfilterUsers_sys_perm_user, spamfilter_users.sys_perm_group as SpamfilterUsers_sys_perm_group, spamfilter_users.sys_perm_other as SpamfilterUsers_sys_perm_other, spamfilter_users.server_id as SpamfilterUsers_server_id, spamfilter_users.priority as SpamfilterUsers_priority, spamfilter_users.policy_id as SpamfilterUsers_policy_id, spamfilter_users.email as SpamfilterUsers_email, spamfilter_users.fullname as SpamfilterUsers_fullname, spamfilter_users.local as SpamfilterUsers_local "
	" FROM spamfilter_users" 
	<< (where.size()?" WHERE "+where:"");
	SpamfilterUsersList spamfilterusersList;
	for(row& r: rs)
	{
		SpamfilterUsersPtr spamfilterusers(new SpamfilterUsers);
		type_conversion<SpamfilterUsers>::from_base(r, i_ok, *spamfilterusers);
		spamfilterusersList.push_back(spamfilterusers);
	}
	return spamfilterusersList;
}

int SpamfilterUsersRepository::insert(const SpamfilterUsers& spamfilterusers)
{
	dataBase << "insert into spamfilter_users(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, priority, policy_id, email, fullname, local)\
values(:SpamfilterUsers_sys_userid, :SpamfilterUsers_sys_groupid, :SpamfilterUsers_sys_perm_user, :SpamfilterUsers_sys_perm_group, :SpamfilterUsers_sys_perm_other, :SpamfilterUsers_server_id, :SpamfilterUsers_priority, :SpamfilterUsers_policy_id, :SpamfilterUsers_email, :SpamfilterUsers_fullname, :SpamfilterUsers_local)", use(spamfilterusers);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SpamfilterUsersRepository::remove(const SpamfilterUsers& spamfilterusers)
{
	dataBase << "DELETE from spamfilter_users WHERE id=:SpamfilterUsers_id AND email=:SpamfilterUsers_email", use(spamfilterusers);
}

void SpamfilterUsersRepository::update(const SpamfilterUsers& spamfilterusers)
{
	dataBase << "update spamfilter_users set sys_userid=:SpamfilterUsers_sys_userid, sys_groupid=:SpamfilterUsers_sys_groupid, sys_perm_user=:SpamfilterUsers_sys_perm_user, sys_perm_group=:SpamfilterUsers_sys_perm_group, sys_perm_other=:SpamfilterUsers_sys_perm_other, server_id=:SpamfilterUsers_server_id, priority=:SpamfilterUsers_priority, policy_id=:SpamfilterUsers_policy_id, email=:SpamfilterUsers_email, fullname=:SpamfilterUsers_fullname, local=:SpamfilterUsers_local WHERE id=:SpamfilterUsers_id AND email=:SpamfilterUsers_email", use(spamfilterusers);
}

void SpamfilterUsersRepository::update(const SpamfilterUsers& oldObj, const SpamfilterUsers& newObj)
{
	dataBase << "update spamfilter_users set sys_userid=:SpamfilterUsers_sys_userid, sys_groupid=:SpamfilterUsers_sys_groupid, sys_perm_user=:SpamfilterUsers_sys_perm_user, sys_perm_group=:SpamfilterUsers_sys_perm_group, sys_perm_other=:SpamfilterUsers_sys_perm_other, server_id=:SpamfilterUsers_server_id, priority=:SpamfilterUsers_priority, policy_id=:SpamfilterUsers_policy_id, email=:SpamfilterUsers_email, fullname=:SpamfilterUsers_fullname, local=:SpamfilterUsers_local WHERE id='"<<oldObj.getId()<<"\'' AND email='"<<oldObj.getEmail()<<"\'", use(newObj);
}

