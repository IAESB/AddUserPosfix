#include "maildomainrepository.h"
#include "util.hpp"
MailDomainRepository::MailDomainRepository(soci::session& db) : dataBase(db)
{
}

MailDomainPtr MailDomainRepository::select(const MailDomain& obj)
{
	soci::row row;
	MailDomainPtr maildomain(new MailDomain);
	dataBase << "SELECT  mail_domain.domain_id as MailDomain_domain_id, mail_domain.sys_userid as MailDomain_sys_userid, mail_domain.sys_groupid as MailDomain_sys_groupid, mail_domain.sys_perm_user as MailDomain_sys_perm_user, mail_domain.sys_perm_group as MailDomain_sys_perm_group, mail_domain.sys_perm_other as MailDomain_sys_perm_other, mail_domain.server_id as MailDomain_server_id, mail_domain.domain as MailDomain_domain, mail_domain.dkim as MailDomain_dkim, mail_domain.dkim_selector as MailDomain_dkim_selector, mail_domain.dkim_private as MailDomain_dkim_private, mail_domain.dkim_public as MailDomain_dkim_public, mail_domain.active as MailDomain_active"
	" FROM mail_domain "
	"WHERE mail_domain.domain_id = :MailDomain_domain_id AND mail_domain.server_id = :MailDomain_server_id AND mail_domain.domain = :MailDomain_domain", into(row), use(obj);
	if(!dataBase.got_data())
		maildomain.reset();
	else
		type_conversion<MailDomain>::from_base(row, i_ok, *maildomain);
	return maildomain;
}
MailDomainList MailDomainRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_domain.domain_id as MailDomain_domain_id, mail_domain.sys_userid as MailDomain_sys_userid, mail_domain.sys_groupid as MailDomain_sys_groupid, mail_domain.sys_perm_user as MailDomain_sys_perm_user, mail_domain.sys_perm_group as MailDomain_sys_perm_group, mail_domain.sys_perm_other as MailDomain_sys_perm_other, mail_domain.server_id as MailDomain_server_id, mail_domain.domain as MailDomain_domain, mail_domain.dkim as MailDomain_dkim, mail_domain.dkim_selector as MailDomain_dkim_selector, mail_domain.dkim_private as MailDomain_dkim_private, mail_domain.dkim_public as MailDomain_dkim_public, mail_domain.active as MailDomain_active "
	" FROM mail_domain" 
	<< (where.size()?" WHERE "+where:"");
	MailDomainList maildomainList;
	for(row& r: rs)
	{
		MailDomainPtr maildomain(new MailDomain);
		type_conversion<MailDomain>::from_base(r, i_ok, *maildomain);
		maildomainList.push_back(maildomain);
	}
	return maildomainList;
}

int MailDomainRepository::insert(const MailDomain& maildomain)
{
	dataBase << "insert into mail_domain(domain_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, domain, dkim, dkim_selector, dkim_private, dkim_public, active)\
values(:MailDomain_domain_id, :MailDomain_sys_userid, :MailDomain_sys_groupid, :MailDomain_sys_perm_user, :MailDomain_sys_perm_group, :MailDomain_sys_perm_other, :MailDomain_server_id, :MailDomain_domain, :MailDomain_dkim, :MailDomain_dkim_selector, :MailDomain_dkim_private, :MailDomain_dkim_public, :MailDomain_active)", use(maildomain);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailDomainRepository::remove(const MailDomain& maildomain)
{
	dataBase << "DELETE from mail_domain WHERE domain_id=:MailDomain_domain_id AND server_id=:MailDomain_server_id AND domain=:MailDomain_domain", use(maildomain);
}

void MailDomainRepository::update(const MailDomain& maildomain)
{
	dataBase << "update mail_domain set domain_id=:MailDomain_domain_id, sys_userid=:MailDomain_sys_userid, sys_groupid=:MailDomain_sys_groupid, sys_perm_user=:MailDomain_sys_perm_user, sys_perm_group=:MailDomain_sys_perm_group, sys_perm_other=:MailDomain_sys_perm_other, server_id=:MailDomain_server_id, domain=:MailDomain_domain, dkim=:MailDomain_dkim, dkim_selector=:MailDomain_dkim_selector, dkim_private=:MailDomain_dkim_private, dkim_public=:MailDomain_dkim_public, active=:MailDomain_active WHERE domain_id=:MailDomain_domain_id AND server_id=:MailDomain_server_id AND domain=:MailDomain_domain", use(maildomain);
}

void MailDomainRepository::update(const MailDomain& oldObj, const MailDomain& newObj)
{
	dataBase << "update mail_domain set domain_id=:MailDomain_domain_id, sys_userid=:MailDomain_sys_userid, sys_groupid=:MailDomain_sys_groupid, sys_perm_user=:MailDomain_sys_perm_user, sys_perm_group=:MailDomain_sys_perm_group, sys_perm_other=:MailDomain_sys_perm_other, server_id=:MailDomain_server_id, domain=:MailDomain_domain, dkim=:MailDomain_dkim, dkim_selector=:MailDomain_dkim_selector, dkim_private=:MailDomain_dkim_private, dkim_public=:MailDomain_dkim_public, active=:MailDomain_active WHERE domain_id='"<<oldObj.getDomainId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'' AND domain='"<<oldObj.getDomain()<<"\'", use(newObj);
}

