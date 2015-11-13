#include "iptablesrepository.h"
#include "util.hpp"
IptablesRepository::IptablesRepository(soci::session& db) : dataBase(db)
{
}

IptablesPtr IptablesRepository::select(const Iptables& obj)
{
	soci::row row;
	IptablesPtr iptables(new Iptables);
	dataBase << "SELECT  iptables.iptables_id as Iptables_iptables_id, iptables.server_id as Iptables_server_id, iptables.table as Iptables_table, iptables.source_ip as Iptables_source_ip, iptables.destination_ip as Iptables_destination_ip, iptables.protocol as Iptables_protocol, iptables.singleport as Iptables_singleport, iptables.multiport as Iptables_multiport, iptables.state as Iptables_state, iptables.target as Iptables_target, iptables.active as Iptables_active"
	" FROM iptables "
	"WHERE iptables.iptables_id = :Iptables_iptables_id", into(row), use(obj);
	if(!dataBase.got_data())
		iptables.reset();
	else
		type_conversion<Iptables>::from_base(row, i_ok, *iptables);
	return iptables;
}
IptablesList IptablesRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  iptables.iptables_id as Iptables_iptables_id, iptables.server_id as Iptables_server_id, iptables.table as Iptables_table, iptables.source_ip as Iptables_source_ip, iptables.destination_ip as Iptables_destination_ip, iptables.protocol as Iptables_protocol, iptables.singleport as Iptables_singleport, iptables.multiport as Iptables_multiport, iptables.state as Iptables_state, iptables.target as Iptables_target, iptables.active as Iptables_active "
	" FROM iptables" 
	<< (where.size()?" WHERE "+where:"");
	IptablesList iptablesList;
	for(row& r: rs)
	{
		IptablesPtr iptables(new Iptables);
		type_conversion<Iptables>::from_base(r, i_ok, *iptables);
		iptablesList.push_back(iptables);
	}
	return iptablesList;
}

int IptablesRepository::insert(const Iptables& iptables)
{
	dataBase << "insert into iptables(iptables_id, server_id, table, source_ip, destination_ip, protocol, singleport, multiport, state, target, active)\
values(:Iptables_iptables_id, :Iptables_server_id, :Iptables_table, :Iptables_source_ip, :Iptables_destination_ip, :Iptables_protocol, :Iptables_singleport, :Iptables_multiport, :Iptables_state, :Iptables_target, :Iptables_active)", use(iptables);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void IptablesRepository::remove(const Iptables& iptables)
{
	dataBase << "DELETE from iptables WHERE iptables_id=:Iptables_iptables_id", use(iptables);
}

void IptablesRepository::update(const Iptables& iptables)
{
	dataBase << "update iptables set iptables_id=:Iptables_iptables_id, server_id=:Iptables_server_id, table=:Iptables_table, source_ip=:Iptables_source_ip, destination_ip=:Iptables_destination_ip, protocol=:Iptables_protocol, singleport=:Iptables_singleport, multiport=:Iptables_multiport, state=:Iptables_state, target=:Iptables_target, active=:Iptables_active WHERE iptables_id=:Iptables_iptables_id", use(iptables);
}

void IptablesRepository::update(const Iptables& oldObj, const Iptables& newObj)
{
	dataBase << "update iptables set iptables_id=:Iptables_iptables_id, server_id=:Iptables_server_id, table=:Iptables_table, source_ip=:Iptables_source_ip, destination_ip=:Iptables_destination_ip, protocol=:Iptables_protocol, singleport=:Iptables_singleport, multiport=:Iptables_multiport, state=:Iptables_state, target=:Iptables_target, active=:Iptables_active WHERE iptables_id='"<<oldObj.getIptablesId()<<"\'", use(newObj);
}

