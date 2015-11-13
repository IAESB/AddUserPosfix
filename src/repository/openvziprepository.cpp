#include "openvziprepository.h"
#include "util.hpp"
OpenvzIpRepository::OpenvzIpRepository(soci::session& db) : dataBase(db)
{
}

OpenvzIpPtr OpenvzIpRepository::select(const OpenvzIp& obj)
{
	soci::row row;
	OpenvzIpPtr openvzip(new OpenvzIp);
	dataBase << "SELECT  openvz_ip.ip_address_id as OpenvzIp_ip_address_id, openvz_ip.sys_userid as OpenvzIp_sys_userid, openvz_ip.sys_groupid as OpenvzIp_sys_groupid, openvz_ip.sys_perm_user as OpenvzIp_sys_perm_user, openvz_ip.sys_perm_group as OpenvzIp_sys_perm_group, openvz_ip.sys_perm_other as OpenvzIp_sys_perm_other, openvz_ip.server_id as OpenvzIp_server_id, openvz_ip.ip_address as OpenvzIp_ip_address, openvz_ip.vm_id as OpenvzIp_vm_id, openvz_ip.reserved as OpenvzIp_reserved"
	" FROM openvz_ip "
	"WHERE openvz_ip.ip_address_id = :OpenvzIp_ip_address_id", into(row), use(obj);
	if(!dataBase.got_data())
		openvzip.reset();
	else
		type_conversion<OpenvzIp>::from_base(row, i_ok, *openvzip);
	return openvzip;
}
OpenvzIpList OpenvzIpRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  openvz_ip.ip_address_id as OpenvzIp_ip_address_id, openvz_ip.sys_userid as OpenvzIp_sys_userid, openvz_ip.sys_groupid as OpenvzIp_sys_groupid, openvz_ip.sys_perm_user as OpenvzIp_sys_perm_user, openvz_ip.sys_perm_group as OpenvzIp_sys_perm_group, openvz_ip.sys_perm_other as OpenvzIp_sys_perm_other, openvz_ip.server_id as OpenvzIp_server_id, openvz_ip.ip_address as OpenvzIp_ip_address, openvz_ip.vm_id as OpenvzIp_vm_id, openvz_ip.reserved as OpenvzIp_reserved "
	" FROM openvz_ip" 
	<< (where.size()?" WHERE "+where:"");
	OpenvzIpList openvzipList;
	for(row& r: rs)
	{
		OpenvzIpPtr openvzip(new OpenvzIp);
		type_conversion<OpenvzIp>::from_base(r, i_ok, *openvzip);
		openvzipList.push_back(openvzip);
	}
	return openvzipList;
}

int OpenvzIpRepository::insert(const OpenvzIp& openvzip)
{
	dataBase << "insert into openvz_ip(ip_address_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, ip_address, vm_id, reserved)\
values(:OpenvzIp_ip_address_id, :OpenvzIp_sys_userid, :OpenvzIp_sys_groupid, :OpenvzIp_sys_perm_user, :OpenvzIp_sys_perm_group, :OpenvzIp_sys_perm_other, :OpenvzIp_server_id, :OpenvzIp_ip_address, :OpenvzIp_vm_id, :OpenvzIp_reserved)", use(openvzip);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void OpenvzIpRepository::remove(const OpenvzIp& openvzip)
{
	dataBase << "DELETE from openvz_ip WHERE ip_address_id=:OpenvzIp_ip_address_id", use(openvzip);
}

void OpenvzIpRepository::update(const OpenvzIp& openvzip)
{
	dataBase << "update openvz_ip set ip_address_id=:OpenvzIp_ip_address_id, sys_userid=:OpenvzIp_sys_userid, sys_groupid=:OpenvzIp_sys_groupid, sys_perm_user=:OpenvzIp_sys_perm_user, sys_perm_group=:OpenvzIp_sys_perm_group, sys_perm_other=:OpenvzIp_sys_perm_other, server_id=:OpenvzIp_server_id, ip_address=:OpenvzIp_ip_address, vm_id=:OpenvzIp_vm_id, reserved=:OpenvzIp_reserved WHERE ip_address_id=:OpenvzIp_ip_address_id", use(openvzip);
}

void OpenvzIpRepository::update(const OpenvzIp& oldObj, const OpenvzIp& newObj)
{
	dataBase << "update openvz_ip set ip_address_id=:OpenvzIp_ip_address_id, sys_userid=:OpenvzIp_sys_userid, sys_groupid=:OpenvzIp_sys_groupid, sys_perm_user=:OpenvzIp_sys_perm_user, sys_perm_group=:OpenvzIp_sys_perm_group, sys_perm_other=:OpenvzIp_sys_perm_other, server_id=:OpenvzIp_server_id, ip_address=:OpenvzIp_ip_address, vm_id=:OpenvzIp_vm_id, reserved=:OpenvzIp_reserved WHERE ip_address_id='"<<oldObj.getIpAddressId()<<"\'", use(newObj);
}

