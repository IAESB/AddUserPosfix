#include "serveriprepository.h"
#include "util.hpp"
ServerIpRepository::ServerIpRepository(soci::session& db) : dataBase(db)
{
}

ServerIpPtr ServerIpRepository::select(const ServerIp& obj)
{
	soci::row row;
	ServerIpPtr serverip(new ServerIp);
	dataBase << "SELECT  server_ip.server_ip_id as ServerIp_server_ip_id, server_ip.sys_userid as ServerIp_sys_userid, server_ip.sys_groupid as ServerIp_sys_groupid, server_ip.sys_perm_user as ServerIp_sys_perm_user, server_ip.sys_perm_group as ServerIp_sys_perm_group, server_ip.sys_perm_other as ServerIp_sys_perm_other, server_ip.server_id as ServerIp_server_id, server_ip.client_id as ServerIp_client_id, server_ip.ip_type as ServerIp_ip_type, server_ip.ip_address as ServerIp_ip_address, server_ip.virtualhost as ServerIp_virtualhost, server_ip.virtualhost_port as ServerIp_virtualhost_port"
	" FROM server_ip "
	"WHERE server_ip.server_ip_id = :ServerIp_server_ip_id", into(row), use(obj);
	if(!dataBase.got_data())
		serverip.reset();
	else
		type_conversion<ServerIp>::from_base(row, i_ok, *serverip);
	return serverip;
}
ServerIpList ServerIpRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  server_ip.server_ip_id as ServerIp_server_ip_id, server_ip.sys_userid as ServerIp_sys_userid, server_ip.sys_groupid as ServerIp_sys_groupid, server_ip.sys_perm_user as ServerIp_sys_perm_user, server_ip.sys_perm_group as ServerIp_sys_perm_group, server_ip.sys_perm_other as ServerIp_sys_perm_other, server_ip.server_id as ServerIp_server_id, server_ip.client_id as ServerIp_client_id, server_ip.ip_type as ServerIp_ip_type, server_ip.ip_address as ServerIp_ip_address, server_ip.virtualhost as ServerIp_virtualhost, server_ip.virtualhost_port as ServerIp_virtualhost_port "
	" FROM server_ip" 
	<< (where.size()?" WHERE "+where:"");
	ServerIpList serveripList;
	for(row& r: rs)
	{
		ServerIpPtr serverip(new ServerIp);
		type_conversion<ServerIp>::from_base(r, i_ok, *serverip);
		serveripList.push_back(serverip);
	}
	return serveripList;
}

int ServerIpRepository::insert(const ServerIp& serverip)
{
	dataBase << "insert into server_ip(server_ip_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, client_id, ip_type, ip_address, virtualhost, virtualhost_port)\
values(:ServerIp_server_ip_id, :ServerIp_sys_userid, :ServerIp_sys_groupid, :ServerIp_sys_perm_user, :ServerIp_sys_perm_group, :ServerIp_sys_perm_other, :ServerIp_server_id, :ServerIp_client_id, :ServerIp_ip_type, :ServerIp_ip_address, :ServerIp_virtualhost, :ServerIp_virtualhost_port)", use(serverip);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ServerIpRepository::remove(const ServerIp& serverip)
{
	dataBase << "DELETE from server_ip WHERE server_ip_id=:ServerIp_server_ip_id", use(serverip);
}

void ServerIpRepository::update(const ServerIp& serverip)
{
	dataBase << "update server_ip set server_ip_id=:ServerIp_server_ip_id, sys_userid=:ServerIp_sys_userid, sys_groupid=:ServerIp_sys_groupid, sys_perm_user=:ServerIp_sys_perm_user, sys_perm_group=:ServerIp_sys_perm_group, sys_perm_other=:ServerIp_sys_perm_other, server_id=:ServerIp_server_id, client_id=:ServerIp_client_id, ip_type=:ServerIp_ip_type, ip_address=:ServerIp_ip_address, virtualhost=:ServerIp_virtualhost, virtualhost_port=:ServerIp_virtualhost_port WHERE server_ip_id=:ServerIp_server_ip_id", use(serverip);
}

void ServerIpRepository::update(const ServerIp& oldObj, const ServerIp& newObj)
{
	dataBase << "update server_ip set server_ip_id=:ServerIp_server_ip_id, sys_userid=:ServerIp_sys_userid, sys_groupid=:ServerIp_sys_groupid, sys_perm_user=:ServerIp_sys_perm_user, sys_perm_group=:ServerIp_sys_perm_group, sys_perm_other=:ServerIp_sys_perm_other, server_id=:ServerIp_server_id, client_id=:ServerIp_client_id, ip_type=:ServerIp_ip_type, ip_address=:ServerIp_ip_address, virtualhost=:ServerIp_virtualhost, virtualhost_port=:ServerIp_virtualhost_port WHERE server_ip_id='"<<oldObj.getServerIpId()<<"\'", use(newObj);
}

