#include "dnsrrrepository.h"
#include "util.hpp"
DnsRrRepository::DnsRrRepository(soci::session& db) : dataBase(db)
{
}

DnsRrPtr DnsRrRepository::select(const DnsRr& obj)
{
	soci::row row;
	DnsRrPtr dnsrr(new DnsRr);
	dataBase << "SELECT  dns_rr.id as DnsRr_id, dns_rr.sys_userid as DnsRr_sys_userid, dns_rr.sys_groupid as DnsRr_sys_groupid, dns_rr.sys_perm_user as DnsRr_sys_perm_user, dns_rr.sys_perm_group as DnsRr_sys_perm_group, dns_rr.sys_perm_other as DnsRr_sys_perm_other, dns_rr.server_id as DnsRr_server_id, dns_rr.zone as DnsRr_zone, dns_rr.name as DnsRr_name, dns_rr.type as DnsRr_type, dns_rr.data as DnsRr_data, dns_rr.aux as DnsRr_aux, dns_rr.ttl as DnsRr_ttl, dns_rr.active as DnsRr_active, dns_rr.stamp as DnsRr_stamp, dns_rr.serial as DnsRr_serial"
	" FROM dns_rr "
	"WHERE dns_rr.id = :DnsRr_id AND dns_rr.zone = :DnsRr_zone", into(row), use(obj);
	if(!dataBase.got_data())
		dnsrr.reset();
	else
		type_conversion<DnsRr>::from_base(row, i_ok, *dnsrr);
	return dnsrr;
}
DnsRrList DnsRrRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  dns_rr.id as DnsRr_id, dns_rr.sys_userid as DnsRr_sys_userid, dns_rr.sys_groupid as DnsRr_sys_groupid, dns_rr.sys_perm_user as DnsRr_sys_perm_user, dns_rr.sys_perm_group as DnsRr_sys_perm_group, dns_rr.sys_perm_other as DnsRr_sys_perm_other, dns_rr.server_id as DnsRr_server_id, dns_rr.zone as DnsRr_zone, dns_rr.name as DnsRr_name, dns_rr.type as DnsRr_type, dns_rr.data as DnsRr_data, dns_rr.aux as DnsRr_aux, dns_rr.ttl as DnsRr_ttl, dns_rr.active as DnsRr_active, dns_rr.stamp as DnsRr_stamp, dns_rr.serial as DnsRr_serial "
	" FROM dns_rr" 
	<< (where.size()?" WHERE "+where:"");
	DnsRrList dnsrrList;
	for(row& r: rs)
	{
		DnsRrPtr dnsrr(new DnsRr);
		type_conversion<DnsRr>::from_base(r, i_ok, *dnsrr);
		dnsrrList.push_back(dnsrr);
	}
	return dnsrrList;
}

int DnsRrRepository::insert(const DnsRr& dnsrr)
{
	dataBase << "insert into dns_rr(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, zone, name, type, data, aux, ttl, active, stamp, serial)\
values(:DnsRr_sys_userid, :DnsRr_sys_groupid, :DnsRr_sys_perm_user, :DnsRr_sys_perm_group, :DnsRr_sys_perm_other, :DnsRr_server_id, :DnsRr_zone, :DnsRr_name, :DnsRr_type, :DnsRr_data, :DnsRr_aux, :DnsRr_ttl, :DnsRr_active, :DnsRr_stamp, :DnsRr_serial)", use(dnsrr);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DnsRrRepository::remove(const DnsRr& dnsrr)
{
	dataBase << "DELETE from dns_rr WHERE id=:DnsRr_id AND zone=:DnsRr_zone", use(dnsrr);
}

void DnsRrRepository::update(const DnsRr& dnsrr)
{
	dataBase << "update dns_rr set sys_userid=:DnsRr_sys_userid, sys_groupid=:DnsRr_sys_groupid, sys_perm_user=:DnsRr_sys_perm_user, sys_perm_group=:DnsRr_sys_perm_group, sys_perm_other=:DnsRr_sys_perm_other, server_id=:DnsRr_server_id, zone=:DnsRr_zone, name=:DnsRr_name, type=:DnsRr_type, data=:DnsRr_data, aux=:DnsRr_aux, ttl=:DnsRr_ttl, active=:DnsRr_active, stamp=:DnsRr_stamp, serial=:DnsRr_serial WHERE id=:DnsRr_id AND zone=:DnsRr_zone", use(dnsrr);
}

void DnsRrRepository::update(const DnsRr& oldObj, const DnsRr& newObj)
{
	dataBase << "update dns_rr set sys_userid=:DnsRr_sys_userid, sys_groupid=:DnsRr_sys_groupid, sys_perm_user=:DnsRr_sys_perm_user, sys_perm_group=:DnsRr_sys_perm_group, sys_perm_other=:DnsRr_sys_perm_other, server_id=:DnsRr_server_id, zone=:DnsRr_zone, name=:DnsRr_name, type=:DnsRr_type, data=:DnsRr_data, aux=:DnsRr_aux, ttl=:DnsRr_ttl, active=:DnsRr_active, stamp=:DnsRr_stamp, serial=:DnsRr_serial WHERE id='"<<oldObj.getId()<<"\'' AND zone='"<<oldObj.getZone()<<"\'", use(newObj);
}

