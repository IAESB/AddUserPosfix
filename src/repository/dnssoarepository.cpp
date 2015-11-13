#include "dnssoarepository.h"
#include "util.hpp"
DnsSoaRepository::DnsSoaRepository(soci::session& db) : dataBase(db)
{
}

DnsSoaPtr DnsSoaRepository::select(const DnsSoa& obj)
{
	soci::row row;
	DnsSoaPtr dnssoa(new DnsSoa);
	dataBase << "SELECT  dns_soa.id as DnsSoa_id, dns_soa.sys_userid as DnsSoa_sys_userid, dns_soa.sys_groupid as DnsSoa_sys_groupid, dns_soa.sys_perm_user as DnsSoa_sys_perm_user, dns_soa.sys_perm_group as DnsSoa_sys_perm_group, dns_soa.sys_perm_other as DnsSoa_sys_perm_other, dns_soa.server_id as DnsSoa_server_id, dns_soa.origin as DnsSoa_origin, dns_soa.ns as DnsSoa_ns, dns_soa.mbox as DnsSoa_mbox, dns_soa.serial as DnsSoa_serial, dns_soa.refresh as DnsSoa_refresh, dns_soa.retry as DnsSoa_retry, dns_soa.expire as DnsSoa_expire, dns_soa.minimum as DnsSoa_minimum, dns_soa.ttl as DnsSoa_ttl, dns_soa.active as DnsSoa_active, dns_soa.xfer as DnsSoa_xfer, dns_soa.also_notify as DnsSoa_also_notify, dns_soa.update_acl as DnsSoa_update_acl"
	" FROM dns_soa "
	"WHERE dns_soa.id = :DnsSoa_id AND dns_soa.origin = :DnsSoa_origin AND dns_soa.active = :DnsSoa_active", into(row), use(obj);
	if(!dataBase.got_data())
		dnssoa.reset();
	else
		type_conversion<DnsSoa>::from_base(row, i_ok, *dnssoa);
	return dnssoa;
}
DnsSoaList DnsSoaRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  dns_soa.id as DnsSoa_id, dns_soa.sys_userid as DnsSoa_sys_userid, dns_soa.sys_groupid as DnsSoa_sys_groupid, dns_soa.sys_perm_user as DnsSoa_sys_perm_user, dns_soa.sys_perm_group as DnsSoa_sys_perm_group, dns_soa.sys_perm_other as DnsSoa_sys_perm_other, dns_soa.server_id as DnsSoa_server_id, dns_soa.origin as DnsSoa_origin, dns_soa.ns as DnsSoa_ns, dns_soa.mbox as DnsSoa_mbox, dns_soa.serial as DnsSoa_serial, dns_soa.refresh as DnsSoa_refresh, dns_soa.retry as DnsSoa_retry, dns_soa.expire as DnsSoa_expire, dns_soa.minimum as DnsSoa_minimum, dns_soa.ttl as DnsSoa_ttl, dns_soa.active as DnsSoa_active, dns_soa.xfer as DnsSoa_xfer, dns_soa.also_notify as DnsSoa_also_notify, dns_soa.update_acl as DnsSoa_update_acl "
	" FROM dns_soa" 
	<< (where.size()?" WHERE "+where:"");
	DnsSoaList dnssoaList;
	for(row& r: rs)
	{
		DnsSoaPtr dnssoa(new DnsSoa);
		type_conversion<DnsSoa>::from_base(r, i_ok, *dnssoa);
		dnssoaList.push_back(dnssoa);
	}
	return dnssoaList;
}

int DnsSoaRepository::insert(const DnsSoa& dnssoa)
{
	dataBase << "insert into dns_soa(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, origin, ns, mbox, serial, refresh, retry, expire, minimum, ttl, active, xfer, also_notify, update_acl)\
values(:DnsSoa_sys_userid, :DnsSoa_sys_groupid, :DnsSoa_sys_perm_user, :DnsSoa_sys_perm_group, :DnsSoa_sys_perm_other, :DnsSoa_server_id, :DnsSoa_origin, :DnsSoa_ns, :DnsSoa_mbox, :DnsSoa_serial, :DnsSoa_refresh, :DnsSoa_retry, :DnsSoa_expire, :DnsSoa_minimum, :DnsSoa_ttl, :DnsSoa_active, :DnsSoa_xfer, :DnsSoa_also_notify, :DnsSoa_update_acl)", use(dnssoa);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DnsSoaRepository::remove(const DnsSoa& dnssoa)
{
	dataBase << "DELETE from dns_soa WHERE id=:DnsSoa_id AND origin=:DnsSoa_origin AND active=:DnsSoa_active", use(dnssoa);
}

void DnsSoaRepository::update(const DnsSoa& dnssoa)
{
	dataBase << "update dns_soa set sys_userid=:DnsSoa_sys_userid, sys_groupid=:DnsSoa_sys_groupid, sys_perm_user=:DnsSoa_sys_perm_user, sys_perm_group=:DnsSoa_sys_perm_group, sys_perm_other=:DnsSoa_sys_perm_other, server_id=:DnsSoa_server_id, origin=:DnsSoa_origin, ns=:DnsSoa_ns, mbox=:DnsSoa_mbox, serial=:DnsSoa_serial, refresh=:DnsSoa_refresh, retry=:DnsSoa_retry, expire=:DnsSoa_expire, minimum=:DnsSoa_minimum, ttl=:DnsSoa_ttl, active=:DnsSoa_active, xfer=:DnsSoa_xfer, also_notify=:DnsSoa_also_notify, update_acl=:DnsSoa_update_acl WHERE id=:DnsSoa_id AND origin=:DnsSoa_origin AND active=:DnsSoa_active", use(dnssoa);
}

void DnsSoaRepository::update(const DnsSoa& oldObj, const DnsSoa& newObj)
{
	dataBase << "update dns_soa set sys_userid=:DnsSoa_sys_userid, sys_groupid=:DnsSoa_sys_groupid, sys_perm_user=:DnsSoa_sys_perm_user, sys_perm_group=:DnsSoa_sys_perm_group, sys_perm_other=:DnsSoa_sys_perm_other, server_id=:DnsSoa_server_id, origin=:DnsSoa_origin, ns=:DnsSoa_ns, mbox=:DnsSoa_mbox, serial=:DnsSoa_serial, refresh=:DnsSoa_refresh, retry=:DnsSoa_retry, expire=:DnsSoa_expire, minimum=:DnsSoa_minimum, ttl=:DnsSoa_ttl, active=:DnsSoa_active, xfer=:DnsSoa_xfer, also_notify=:DnsSoa_also_notify, update_acl=:DnsSoa_update_acl WHERE id='"<<oldObj.getId()<<"\'' AND origin='"<<oldObj.getOrigin()<<"\'' AND active='"<<oldObj.getActive()<<"\'", use(newObj);
}

