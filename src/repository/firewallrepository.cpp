#include "firewallrepository.h"
#include "util.hpp"
FirewallRepository::FirewallRepository(soci::session& db) : dataBase(db)
{
}

FirewallPtr FirewallRepository::select(const Firewall& obj)
{
	soci::row row;
	FirewallPtr firewall(new Firewall);
	dataBase << "SELECT  firewall.firewall_id as Firewall_firewall_id, firewall.sys_userid as Firewall_sys_userid, firewall.sys_groupid as Firewall_sys_groupid, firewall.sys_perm_user as Firewall_sys_perm_user, firewall.sys_perm_group as Firewall_sys_perm_group, firewall.sys_perm_other as Firewall_sys_perm_other, firewall.server_id as Firewall_server_id, firewall.tcp_port as Firewall_tcp_port, firewall.udp_port as Firewall_udp_port, firewall.active as Firewall_active"
	" FROM firewall "
	"WHERE firewall.firewall_id = :Firewall_firewall_id", into(row), use(obj);
	if(!dataBase.got_data())
		firewall.reset();
	else
		type_conversion<Firewall>::from_base(row, i_ok, *firewall);
	return firewall;
}
FirewallList FirewallRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  firewall.firewall_id as Firewall_firewall_id, firewall.sys_userid as Firewall_sys_userid, firewall.sys_groupid as Firewall_sys_groupid, firewall.sys_perm_user as Firewall_sys_perm_user, firewall.sys_perm_group as Firewall_sys_perm_group, firewall.sys_perm_other as Firewall_sys_perm_other, firewall.server_id as Firewall_server_id, firewall.tcp_port as Firewall_tcp_port, firewall.udp_port as Firewall_udp_port, firewall.active as Firewall_active "
	" FROM firewall" 
	<< (where.size()?" WHERE "+where:"");
	FirewallList firewallList;
	for(row& r: rs)
	{
		FirewallPtr firewall(new Firewall);
		type_conversion<Firewall>::from_base(r, i_ok, *firewall);
		firewallList.push_back(firewall);
	}
	return firewallList;
}

int FirewallRepository::insert(const Firewall& firewall)
{
	dataBase << "insert into firewall(firewall_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, tcp_port, udp_port, active)\
values(:Firewall_firewall_id, :Firewall_sys_userid, :Firewall_sys_groupid, :Firewall_sys_perm_user, :Firewall_sys_perm_group, :Firewall_sys_perm_other, :Firewall_server_id, :Firewall_tcp_port, :Firewall_udp_port, :Firewall_active)", use(firewall);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void FirewallRepository::remove(const Firewall& firewall)
{
	dataBase << "DELETE from firewall WHERE firewall_id=:Firewall_firewall_id", use(firewall);
}

void FirewallRepository::update(const Firewall& firewall)
{
	dataBase << "update firewall set firewall_id=:Firewall_firewall_id, sys_userid=:Firewall_sys_userid, sys_groupid=:Firewall_sys_groupid, sys_perm_user=:Firewall_sys_perm_user, sys_perm_group=:Firewall_sys_perm_group, sys_perm_other=:Firewall_sys_perm_other, server_id=:Firewall_server_id, tcp_port=:Firewall_tcp_port, udp_port=:Firewall_udp_port, active=:Firewall_active WHERE firewall_id=:Firewall_firewall_id", use(firewall);
}

void FirewallRepository::update(const Firewall& oldObj, const Firewall& newObj)
{
	dataBase << "update firewall set firewall_id=:Firewall_firewall_id, sys_userid=:Firewall_sys_userid, sys_groupid=:Firewall_sys_groupid, sys_perm_user=:Firewall_sys_perm_user, sys_perm_group=:Firewall_sys_perm_group, sys_perm_other=:Firewall_sys_perm_other, server_id=:Firewall_server_id, tcp_port=:Firewall_tcp_port, udp_port=:Firewall_udp_port, active=:Firewall_active WHERE firewall_id='"<<oldObj.getFirewallId()<<"\'", use(newObj);
}

