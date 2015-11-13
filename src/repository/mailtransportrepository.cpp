#include "mailtransportrepository.h"
#include "util.hpp"
MailTransportRepository::MailTransportRepository(soci::session& db) : dataBase(db)
{
}

MailTransportPtr MailTransportRepository::select(const MailTransport& obj)
{
	soci::row row;
	MailTransportPtr mailtransport(new MailTransport);
	dataBase << "SELECT  mail_transport.transport_id as MailTransport_transport_id, mail_transport.sys_userid as MailTransport_sys_userid, mail_transport.sys_groupid as MailTransport_sys_groupid, mail_transport.sys_perm_user as MailTransport_sys_perm_user, mail_transport.sys_perm_group as MailTransport_sys_perm_group, mail_transport.sys_perm_other as MailTransport_sys_perm_other, mail_transport.server_id as MailTransport_server_id, mail_transport.domain as MailTransport_domain, mail_transport.transport as MailTransport_transport, mail_transport.sort_order as MailTransport_sort_order, mail_transport.active as MailTransport_active"
	" FROM mail_transport "
	"WHERE mail_transport.transport_id = :MailTransport_transport_id AND mail_transport.server_id = :MailTransport_server_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailtransport.reset();
	else
		type_conversion<MailTransport>::from_base(row, i_ok, *mailtransport);
	return mailtransport;
}
MailTransportList MailTransportRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_transport.transport_id as MailTransport_transport_id, mail_transport.sys_userid as MailTransport_sys_userid, mail_transport.sys_groupid as MailTransport_sys_groupid, mail_transport.sys_perm_user as MailTransport_sys_perm_user, mail_transport.sys_perm_group as MailTransport_sys_perm_group, mail_transport.sys_perm_other as MailTransport_sys_perm_other, mail_transport.server_id as MailTransport_server_id, mail_transport.domain as MailTransport_domain, mail_transport.transport as MailTransport_transport, mail_transport.sort_order as MailTransport_sort_order, mail_transport.active as MailTransport_active "
	" FROM mail_transport" 
	<< (where.size()?" WHERE "+where:"");
	MailTransportList mailtransportList;
	for(row& r: rs)
	{
		MailTransportPtr mailtransport(new MailTransport);
		type_conversion<MailTransport>::from_base(r, i_ok, *mailtransport);
		mailtransportList.push_back(mailtransport);
	}
	return mailtransportList;
}

int MailTransportRepository::insert(const MailTransport& mailtransport)
{
	dataBase << "insert into mail_transport(transport_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, domain, transport, sort_order, active)\
values(:MailTransport_transport_id, :MailTransport_sys_userid, :MailTransport_sys_groupid, :MailTransport_sys_perm_user, :MailTransport_sys_perm_group, :MailTransport_sys_perm_other, :MailTransport_server_id, :MailTransport_domain, :MailTransport_transport, :MailTransport_sort_order, :MailTransport_active)", use(mailtransport);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailTransportRepository::remove(const MailTransport& mailtransport)
{
	dataBase << "DELETE from mail_transport WHERE transport_id=:MailTransport_transport_id AND server_id=:MailTransport_server_id", use(mailtransport);
}

void MailTransportRepository::update(const MailTransport& mailtransport)
{
	dataBase << "update mail_transport set transport_id=:MailTransport_transport_id, sys_userid=:MailTransport_sys_userid, sys_groupid=:MailTransport_sys_groupid, sys_perm_user=:MailTransport_sys_perm_user, sys_perm_group=:MailTransport_sys_perm_group, sys_perm_other=:MailTransport_sys_perm_other, server_id=:MailTransport_server_id, domain=:MailTransport_domain, transport=:MailTransport_transport, sort_order=:MailTransport_sort_order, active=:MailTransport_active WHERE transport_id=:MailTransport_transport_id AND server_id=:MailTransport_server_id", use(mailtransport);
}

void MailTransportRepository::update(const MailTransport& oldObj, const MailTransport& newObj)
{
	dataBase << "update mail_transport set transport_id=:MailTransport_transport_id, sys_userid=:MailTransport_sys_userid, sys_groupid=:MailTransport_sys_groupid, sys_perm_user=:MailTransport_sys_perm_user, sys_perm_group=:MailTransport_sys_perm_group, sys_perm_other=:MailTransport_sys_perm_other, server_id=:MailTransport_server_id, domain=:MailTransport_domain, transport=:MailTransport_transport, sort_order=:MailTransport_sort_order, active=:MailTransport_active WHERE transport_id='"<<oldObj.getTransportId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'", use(newObj);
}

