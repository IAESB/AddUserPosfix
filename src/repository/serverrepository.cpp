#include "serverrepository.h"
#include "util.hpp"
ServerRepository::ServerRepository(soci::session& db) : dataBase(db)
{
}

ServerPtr ServerRepository::select(const Server& obj)
{
	soci::row row;
	ServerPtr server(new Server);
	dataBase << "SELECT  server.server_id as Server_server_id, server.sys_userid as Server_sys_userid, server.sys_groupid as Server_sys_groupid, server.sys_perm_user as Server_sys_perm_user, server.sys_perm_group as Server_sys_perm_group, server.sys_perm_other as Server_sys_perm_other, server.server_name as Server_server_name, server.mail_server as Server_mail_server, server.web_server as Server_web_server, server.dns_server as Server_dns_server, server.file_server as Server_file_server, server.db_server as Server_db_server, server.vserver_server as Server_vserver_server, server.proxy_server as Server_proxy_server, server.firewall_server as Server_firewall_server, server.config as Server_config, server.updated as Server_updated, server.mirror_server_id as Server_mirror_server_id, server.dbversion as Server_dbversion, server.active as Server_active"
	" FROM server "
	"WHERE server.server_id = :Server_server_id", into(row), use(obj);
	if(!dataBase.got_data())
		server.reset();
	else
		type_conversion<Server>::from_base(row, i_ok, *server);
	return server;
}
ServerList ServerRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  server.server_id as Server_server_id, server.sys_userid as Server_sys_userid, server.sys_groupid as Server_sys_groupid, server.sys_perm_user as Server_sys_perm_user, server.sys_perm_group as Server_sys_perm_group, server.sys_perm_other as Server_sys_perm_other, server.server_name as Server_server_name, server.mail_server as Server_mail_server, server.web_server as Server_web_server, server.dns_server as Server_dns_server, server.file_server as Server_file_server, server.db_server as Server_db_server, server.vserver_server as Server_vserver_server, server.proxy_server as Server_proxy_server, server.firewall_server as Server_firewall_server, server.config as Server_config, server.updated as Server_updated, server.mirror_server_id as Server_mirror_server_id, server.dbversion as Server_dbversion, server.active as Server_active "
	" FROM server" 
	<< (where.size()?" WHERE "+where:"");
	ServerList serverList;
	for(row& r: rs)
	{
		ServerPtr server(new Server);
		type_conversion<Server>::from_base(r, i_ok, *server);
		serverList.push_back(server);
	}
	return serverList;
}

int ServerRepository::insert(const Server& server)
{
	dataBase << "insert into server(server_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_name, mail_server, web_server, dns_server, file_server, db_server, vserver_server, proxy_server, firewall_server, config, updated, mirror_server_id, dbversion, active)\
values(:Server_server_id, :Server_sys_userid, :Server_sys_groupid, :Server_sys_perm_user, :Server_sys_perm_group, :Server_sys_perm_other, :Server_server_name, :Server_mail_server, :Server_web_server, :Server_dns_server, :Server_file_server, :Server_db_server, :Server_vserver_server, :Server_proxy_server, :Server_firewall_server, :Server_config, :Server_updated, :Server_mirror_server_id, :Server_dbversion, :Server_active)", use(server);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ServerRepository::remove(const Server& server)
{
	dataBase << "DELETE from server WHERE server_id=:Server_server_id", use(server);
}

void ServerRepository::update(const Server& server)
{
	dataBase << "update server set server_id=:Server_server_id, sys_userid=:Server_sys_userid, sys_groupid=:Server_sys_groupid, sys_perm_user=:Server_sys_perm_user, sys_perm_group=:Server_sys_perm_group, sys_perm_other=:Server_sys_perm_other, server_name=:Server_server_name, mail_server=:Server_mail_server, web_server=:Server_web_server, dns_server=:Server_dns_server, file_server=:Server_file_server, db_server=:Server_db_server, vserver_server=:Server_vserver_server, proxy_server=:Server_proxy_server, firewall_server=:Server_firewall_server, config=:Server_config, updated=:Server_updated, mirror_server_id=:Server_mirror_server_id, dbversion=:Server_dbversion, active=:Server_active WHERE server_id=:Server_server_id", use(server);
}

void ServerRepository::update(const Server& oldObj, const Server& newObj)
{
	dataBase << "update server set server_id=:Server_server_id, sys_userid=:Server_sys_userid, sys_groupid=:Server_sys_groupid, sys_perm_user=:Server_sys_perm_user, sys_perm_group=:Server_sys_perm_group, sys_perm_other=:Server_sys_perm_other, server_name=:Server_server_name, mail_server=:Server_mail_server, web_server=:Server_web_server, dns_server=:Server_dns_server, file_server=:Server_file_server, db_server=:Server_db_server, vserver_server=:Server_vserver_server, proxy_server=:Server_proxy_server, firewall_server=:Server_firewall_server, config=:Server_config, updated=:Server_updated, mirror_server_id=:Server_mirror_server_id, dbversion=:Server_dbversion, active=:Server_active WHERE server_id='"<<oldObj.getServerId()<<"\'", use(newObj);
}

