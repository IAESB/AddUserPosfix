#include "openvzvmrepository.h"
#include "util.hpp"
OpenvzVmRepository::OpenvzVmRepository(soci::session& db) : dataBase(db)
{
}

OpenvzVmPtr OpenvzVmRepository::select(const OpenvzVm& obj)
{
	soci::row row;
	OpenvzVmPtr openvzvm(new OpenvzVm);
	dataBase << "SELECT  openvz_vm.vm_id as OpenvzVm_vm_id, openvz_vm.sys_userid as OpenvzVm_sys_userid, openvz_vm.sys_groupid as OpenvzVm_sys_groupid, openvz_vm.sys_perm_user as OpenvzVm_sys_perm_user, openvz_vm.sys_perm_group as OpenvzVm_sys_perm_group, openvz_vm.sys_perm_other as OpenvzVm_sys_perm_other, openvz_vm.server_id as OpenvzVm_server_id, openvz_vm.veid as OpenvzVm_veid, openvz_vm.ostemplate_id as OpenvzVm_ostemplate_id, openvz_vm.template_id as OpenvzVm_template_id, openvz_vm.ip_address as OpenvzVm_ip_address, openvz_vm.hostname as OpenvzVm_hostname, openvz_vm.vm_password as OpenvzVm_vm_password, openvz_vm.start_boot as OpenvzVm_start_boot, openvz_vm.active as OpenvzVm_active, openvz_vm.active_until_date as OpenvzVm_active_until_date, openvz_vm.description as OpenvzVm_description, openvz_vm.diskspace as OpenvzVm_diskspace, openvz_vm.traffic as OpenvzVm_traffic, openvz_vm.bandwidth as OpenvzVm_bandwidth, openvz_vm.ram as OpenvzVm_ram, openvz_vm.ram_burst as OpenvzVm_ram_burst, openvz_vm.cpu_units as OpenvzVm_cpu_units, openvz_vm.cpu_num as OpenvzVm_cpu_num, openvz_vm.cpu_limit as OpenvzVm_cpu_limit, openvz_vm.io_priority as OpenvzVm_io_priority, openvz_vm.nameserver as OpenvzVm_nameserver, openvz_vm.create_dns as OpenvzVm_create_dns, openvz_vm.capability as OpenvzVm_capability, openvz_vm.config as OpenvzVm_config"
	" FROM openvz_vm "
	"WHERE openvz_vm.vm_id = :OpenvzVm_vm_id", into(row), use(obj);
	if(!dataBase.got_data())
		openvzvm.reset();
	else
		type_conversion<OpenvzVm>::from_base(row, i_ok, *openvzvm);
	return openvzvm;
}
OpenvzVmList OpenvzVmRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  openvz_vm.vm_id as OpenvzVm_vm_id, openvz_vm.sys_userid as OpenvzVm_sys_userid, openvz_vm.sys_groupid as OpenvzVm_sys_groupid, openvz_vm.sys_perm_user as OpenvzVm_sys_perm_user, openvz_vm.sys_perm_group as OpenvzVm_sys_perm_group, openvz_vm.sys_perm_other as OpenvzVm_sys_perm_other, openvz_vm.server_id as OpenvzVm_server_id, openvz_vm.veid as OpenvzVm_veid, openvz_vm.ostemplate_id as OpenvzVm_ostemplate_id, openvz_vm.template_id as OpenvzVm_template_id, openvz_vm.ip_address as OpenvzVm_ip_address, openvz_vm.hostname as OpenvzVm_hostname, openvz_vm.vm_password as OpenvzVm_vm_password, openvz_vm.start_boot as OpenvzVm_start_boot, openvz_vm.active as OpenvzVm_active, openvz_vm.active_until_date as OpenvzVm_active_until_date, openvz_vm.description as OpenvzVm_description, openvz_vm.diskspace as OpenvzVm_diskspace, openvz_vm.traffic as OpenvzVm_traffic, openvz_vm.bandwidth as OpenvzVm_bandwidth, openvz_vm.ram as OpenvzVm_ram, openvz_vm.ram_burst as OpenvzVm_ram_burst, openvz_vm.cpu_units as OpenvzVm_cpu_units, openvz_vm.cpu_num as OpenvzVm_cpu_num, openvz_vm.cpu_limit as OpenvzVm_cpu_limit, openvz_vm.io_priority as OpenvzVm_io_priority, openvz_vm.nameserver as OpenvzVm_nameserver, openvz_vm.create_dns as OpenvzVm_create_dns, openvz_vm.capability as OpenvzVm_capability, openvz_vm.config as OpenvzVm_config "
	" FROM openvz_vm" 
	<< (where.size()?" WHERE "+where:"");
	OpenvzVmList openvzvmList;
	for(row& r: rs)
	{
		OpenvzVmPtr openvzvm(new OpenvzVm);
		type_conversion<OpenvzVm>::from_base(r, i_ok, *openvzvm);
		openvzvmList.push_back(openvzvm);
	}
	return openvzvmList;
}

int OpenvzVmRepository::insert(const OpenvzVm& openvzvm)
{
	dataBase << "insert into openvz_vm(vm_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, veid, ostemplate_id, template_id, ip_address, hostname, vm_password, start_boot, active, active_until_date, description, diskspace, traffic, bandwidth, ram, ram_burst, cpu_units, cpu_num, cpu_limit, io_priority, nameserver, create_dns, capability, config)\
values(:OpenvzVm_vm_id, :OpenvzVm_sys_userid, :OpenvzVm_sys_groupid, :OpenvzVm_sys_perm_user, :OpenvzVm_sys_perm_group, :OpenvzVm_sys_perm_other, :OpenvzVm_server_id, :OpenvzVm_veid, :OpenvzVm_ostemplate_id, :OpenvzVm_template_id, :OpenvzVm_ip_address, :OpenvzVm_hostname, :OpenvzVm_vm_password, :OpenvzVm_start_boot, :OpenvzVm_active, :OpenvzVm_active_until_date, :OpenvzVm_description, :OpenvzVm_diskspace, :OpenvzVm_traffic, :OpenvzVm_bandwidth, :OpenvzVm_ram, :OpenvzVm_ram_burst, :OpenvzVm_cpu_units, :OpenvzVm_cpu_num, :OpenvzVm_cpu_limit, :OpenvzVm_io_priority, :OpenvzVm_nameserver, :OpenvzVm_create_dns, :OpenvzVm_capability, :OpenvzVm_config)", use(openvzvm);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void OpenvzVmRepository::remove(const OpenvzVm& openvzvm)
{
	dataBase << "DELETE from openvz_vm WHERE vm_id=:OpenvzVm_vm_id", use(openvzvm);
}

void OpenvzVmRepository::update(const OpenvzVm& openvzvm)
{
	dataBase << "update openvz_vm set vm_id=:OpenvzVm_vm_id, sys_userid=:OpenvzVm_sys_userid, sys_groupid=:OpenvzVm_sys_groupid, sys_perm_user=:OpenvzVm_sys_perm_user, sys_perm_group=:OpenvzVm_sys_perm_group, sys_perm_other=:OpenvzVm_sys_perm_other, server_id=:OpenvzVm_server_id, veid=:OpenvzVm_veid, ostemplate_id=:OpenvzVm_ostemplate_id, template_id=:OpenvzVm_template_id, ip_address=:OpenvzVm_ip_address, hostname=:OpenvzVm_hostname, vm_password=:OpenvzVm_vm_password, start_boot=:OpenvzVm_start_boot, active=:OpenvzVm_active, active_until_date=:OpenvzVm_active_until_date, description=:OpenvzVm_description, diskspace=:OpenvzVm_diskspace, traffic=:OpenvzVm_traffic, bandwidth=:OpenvzVm_bandwidth, ram=:OpenvzVm_ram, ram_burst=:OpenvzVm_ram_burst, cpu_units=:OpenvzVm_cpu_units, cpu_num=:OpenvzVm_cpu_num, cpu_limit=:OpenvzVm_cpu_limit, io_priority=:OpenvzVm_io_priority, nameserver=:OpenvzVm_nameserver, create_dns=:OpenvzVm_create_dns, capability=:OpenvzVm_capability, config=:OpenvzVm_config WHERE vm_id=:OpenvzVm_vm_id", use(openvzvm);
}

void OpenvzVmRepository::update(const OpenvzVm& oldObj, const OpenvzVm& newObj)
{
	dataBase << "update openvz_vm set vm_id=:OpenvzVm_vm_id, sys_userid=:OpenvzVm_sys_userid, sys_groupid=:OpenvzVm_sys_groupid, sys_perm_user=:OpenvzVm_sys_perm_user, sys_perm_group=:OpenvzVm_sys_perm_group, sys_perm_other=:OpenvzVm_sys_perm_other, server_id=:OpenvzVm_server_id, veid=:OpenvzVm_veid, ostemplate_id=:OpenvzVm_ostemplate_id, template_id=:OpenvzVm_template_id, ip_address=:OpenvzVm_ip_address, hostname=:OpenvzVm_hostname, vm_password=:OpenvzVm_vm_password, start_boot=:OpenvzVm_start_boot, active=:OpenvzVm_active, active_until_date=:OpenvzVm_active_until_date, description=:OpenvzVm_description, diskspace=:OpenvzVm_diskspace, traffic=:OpenvzVm_traffic, bandwidth=:OpenvzVm_bandwidth, ram=:OpenvzVm_ram, ram_burst=:OpenvzVm_ram_burst, cpu_units=:OpenvzVm_cpu_units, cpu_num=:OpenvzVm_cpu_num, cpu_limit=:OpenvzVm_cpu_limit, io_priority=:OpenvzVm_io_priority, nameserver=:OpenvzVm_nameserver, create_dns=:OpenvzVm_create_dns, capability=:OpenvzVm_capability, config=:OpenvzVm_config WHERE vm_id='"<<oldObj.getVmId()<<"\'", use(newObj);
}

