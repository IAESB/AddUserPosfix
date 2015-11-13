#include "dnsslaverepository.h"
#include "util.hpp"
DnsSlaveRepository::DnsSlaveRepository(soci::session& db) : dataBase(db)
{
}

DnsSlavePtr DnsSlaveRepository::select(const DnsSlave& obj)
{
	soci::row row;
	DnsSlavePtr dnsslave(new DnsSlave);
	dataBase << "SELECT  dns_slave.id as DnsSlave_id, dns_slave.sys_userid as DnsSlave_sys_userid, dns_slave.sys_groupid as DnsSlave_sys_groupid, dns_slave.sys_perm_user as DnsSlave_sys_perm_user, dns_slave.sys_perm_group as DnsSlave_sys_perm_group, dns_slave.sys_perm_other as DnsSlave_sys_perm_other, dns_slave.server_id as DnsSlave_server_id, dns_slave.origin as DnsSlave_origin, dns_slave.ns as DnsSlave_ns, dns_slave.active as DnsSlave_active, dns_slave.xfer as DnsSlave_xfer"
	" FROM dns_slave "
	"WHERE dns_slave.id = :DnsSlave_id AND dns_slave.origin = :DnsSlave_origin AND dns_slave.active = :DnsSlave_active", into(row), use(obj);
	if(!dataBase.got_data())
		dnsslave.reset();
	else
		type_conversion<DnsSlave>::from_base(row, i_ok, *dnsslave);
	return dnsslave;
}
DnsSlaveList DnsSlaveRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  dns_slave.id as DnsSlave_id, dns_slave.sys_userid as DnsSlave_sys_userid, dns_slave.sys_groupid as DnsSlave_sys_groupid, dns_slave.sys_perm_user as DnsSlave_sys_perm_user, dns_slave.sys_perm_group as DnsSlave_sys_perm_group, dns_slave.sys_perm_other as DnsSlave_sys_perm_other, dns_slave.server_id as DnsSlave_server_id, dns_slave.origin as DnsSlave_origin, dns_slave.ns as DnsSlave_ns, dns_slave.active as DnsSlave_active, dns_slave.xfer as DnsSlave_xfer "
	" FROM dns_slave" 
	<< (where.size()?" WHERE "+where:"");
	DnsSlaveList dnsslaveList;
	for(row& r: rs)
	{
		DnsSlavePtr dnsslave(new DnsSlave);
		type_conversion<DnsSlave>::from_base(r, i_ok, *dnsslave);
		dnsslaveList.push_back(dnsslave);
	}
	return dnsslaveList;
}

int DnsSlaveRepository::insert(const DnsSlave& dnsslave)
{
	dataBase << "insert into dns_slave(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, origin, ns, active, xfer)\
values(:DnsSlave_sys_userid, :DnsSlave_sys_groupid, :DnsSlave_sys_perm_user, :DnsSlave_sys_perm_group, :DnsSlave_sys_perm_other, :DnsSlave_server_id, :DnsSlave_origin, :DnsSlave_ns, :DnsSlave_active, :DnsSlave_xfer)", use(dnsslave);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DnsSlaveRepository::remove(const DnsSlave& dnsslave)
{
	dataBase << "DELETE from dns_slave WHERE id=:DnsSlave_id AND origin=:DnsSlave_origin AND active=:DnsSlave_active", use(dnsslave);
}

void DnsSlaveRepository::update(const DnsSlave& dnsslave)
{
	dataBase << "update dns_slave set sys_userid=:DnsSlave_sys_userid, sys_groupid=:DnsSlave_sys_groupid, sys_perm_user=:DnsSlave_sys_perm_user, sys_perm_group=:DnsSlave_sys_perm_group, sys_perm_other=:DnsSlave_sys_perm_other, server_id=:DnsSlave_server_id, origin=:DnsSlave_origin, ns=:DnsSlave_ns, active=:DnsSlave_active, xfer=:DnsSlave_xfer WHERE id=:DnsSlave_id AND origin=:DnsSlave_origin AND active=:DnsSlave_active", use(dnsslave);
}

void DnsSlaveRepository::update(const DnsSlave& oldObj, const DnsSlave& newObj)
{
	dataBase << "update dns_slave set sys_userid=:DnsSlave_sys_userid, sys_groupid=:DnsSlave_sys_groupid, sys_perm_user=:DnsSlave_sys_perm_user, sys_perm_group=:DnsSlave_sys_perm_group, sys_perm_other=:DnsSlave_sys_perm_other, server_id=:DnsSlave_server_id, origin=:DnsSlave_origin, ns=:DnsSlave_ns, active=:DnsSlave_active, xfer=:DnsSlave_xfer WHERE id='"<<oldObj.getId()<<"\'' AND origin='"<<oldObj.getOrigin()<<"\'' AND active='"<<oldObj.getActive()<<"\'", use(newObj);
}

