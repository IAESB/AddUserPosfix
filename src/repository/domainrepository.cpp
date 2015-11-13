#include "domainrepository.h"
#include "util.hpp"
DomainRepository::DomainRepository(soci::session& db) : dataBase(db)
{
}

DomainPtr DomainRepository::select(const Domain& obj)
{
	soci::row row;
	DomainPtr domain(new Domain);
	dataBase << "SELECT  domain.domain_id as Domain_domain_id, domain.sys_userid as Domain_sys_userid, domain.sys_groupid as Domain_sys_groupid, domain.sys_perm_user as Domain_sys_perm_user, domain.sys_perm_group as Domain_sys_perm_group, domain.sys_perm_other as Domain_sys_perm_other, domain.domain as Domain_domain"
	" FROM domain "
	"WHERE domain.domain_id = :Domain_domain_id AND domain.domain = :Domain_domain", into(row), use(obj);
	if(!dataBase.got_data())
		domain.reset();
	else
		type_conversion<Domain>::from_base(row, i_ok, *domain);
	return domain;
}
DomainList DomainRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  domain.domain_id as Domain_domain_id, domain.sys_userid as Domain_sys_userid, domain.sys_groupid as Domain_sys_groupid, domain.sys_perm_user as Domain_sys_perm_user, domain.sys_perm_group as Domain_sys_perm_group, domain.sys_perm_other as Domain_sys_perm_other, domain.domain as Domain_domain "
	" FROM domain" 
	<< (where.size()?" WHERE "+where:"");
	DomainList domainList;
	for(row& r: rs)
	{
		DomainPtr domain(new Domain);
		type_conversion<Domain>::from_base(r, i_ok, *domain);
		domainList.push_back(domain);
	}
	return domainList;
}

int DomainRepository::insert(const Domain& domain)
{
	dataBase << "insert into domain(domain_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, domain)\
values(:Domain_domain_id, :Domain_sys_userid, :Domain_sys_groupid, :Domain_sys_perm_user, :Domain_sys_perm_group, :Domain_sys_perm_other, :Domain_domain)", use(domain);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DomainRepository::remove(const Domain& domain)
{
	dataBase << "DELETE from domain WHERE domain_id=:Domain_domain_id AND domain=:Domain_domain", use(domain);
}

void DomainRepository::update(const Domain& domain)
{
	dataBase << "update domain set domain_id=:Domain_domain_id, sys_userid=:Domain_sys_userid, sys_groupid=:Domain_sys_groupid, sys_perm_user=:Domain_sys_perm_user, sys_perm_group=:Domain_sys_perm_group, sys_perm_other=:Domain_sys_perm_other, domain=:Domain_domain WHERE domain_id=:Domain_domain_id AND domain=:Domain_domain", use(domain);
}

void DomainRepository::update(const Domain& oldObj, const Domain& newObj)
{
	dataBase << "update domain set domain_id=:Domain_domain_id, sys_userid=:Domain_sys_userid, sys_groupid=:Domain_sys_groupid, sys_perm_user=:Domain_sys_perm_user, sys_perm_group=:Domain_sys_perm_group, sys_perm_other=:Domain_sys_perm_other, domain=:Domain_domain WHERE domain_id='"<<oldObj.getDomainId()<<"\'' AND domain='"<<oldObj.getDomain()<<"\'", use(newObj);
}

