#ifndef OPENVZVMREPOSITORY_H
#define OPENVZVMREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/openvzvm.h"
using namespace soci;


class OpenvzVmRepository
{
	soci::session& dataBase;
public:
	OpenvzVmRepository(soci::session& dataBase);
	int insert(const OpenvzVm& openvzvm);
	OpenvzVmPtr select(const OpenvzVm& openvzvm);
	OpenvzVmList select(const string& where="");
	void update(const OpenvzVm& openvzvm);
	void update(const OpenvzVm& oldObj, const OpenvzVm& newObj);
	void remove(const OpenvzVm& openvzvm);
};

namespace soci
{
template<>
struct type_conversion<OpenvzVm>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, OpenvzVm & p)
	{
		if (v.get_indicator("OpenvzVm_vm_id") != i_null){
			p.setVmId( v.template get<long long>("OpenvzVm_vm_id" ) );
		}
		if (v.get_indicator("OpenvzVm_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("OpenvzVm_sys_userid" ) );
		}
		if (v.get_indicator("OpenvzVm_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("OpenvzVm_sys_groupid" ) );
		}
		if (v.get_indicator("OpenvzVm_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("OpenvzVm_sys_perm_user" ) );
		}
		if (v.get_indicator("OpenvzVm_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("OpenvzVm_sys_perm_group" ) );
		}
		if (v.get_indicator("OpenvzVm_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("OpenvzVm_sys_perm_other" ) );
		}
		if (v.get_indicator("OpenvzVm_server_id") != i_null){
			p.setServerId( v.template get<int>("OpenvzVm_server_id" ) );
		}
		if (v.get_indicator("OpenvzVm_veid") != i_null){
			p.setVeid( v.template get<long long>("OpenvzVm_veid" ) );
		}
		if (v.get_indicator("OpenvzVm_ostemplate_id") != i_null){
			p.setOstemplateId( v.template get<int>("OpenvzVm_ostemplate_id" ) );
		}
		if (v.get_indicator("OpenvzVm_template_id") != i_null){
			p.setTemplateId( v.template get<int>("OpenvzVm_template_id" ) );
		}
		if (v.get_indicator("OpenvzVm_ip_address") != i_null){
			p.setIpAddress( v.template get<std::string>("OpenvzVm_ip_address" ) );
		}
		if (v.get_indicator("OpenvzVm_hostname") != i_null){
			p.setHostname( v.template get<std::string>("OpenvzVm_hostname" ) );
		}
		if (v.get_indicator("OpenvzVm_vm_password") != i_null){
			p.setVmPassword( v.template get<std::string>("OpenvzVm_vm_password" ) );
		}
		if (v.get_indicator("OpenvzVm_start_boot") != i_null){
			p.setStartBoot( v.template get<std::string>("OpenvzVm_start_boot" ) );
		}
		if (v.get_indicator("OpenvzVm_active") != i_null){
			p.setActive( v.template get<std::string>("OpenvzVm_active" ) );
		}
		if (v.get_indicator("OpenvzVm_active_until_date") != i_null){
			p.setActiveUntilDate( v.template get<tm>("OpenvzVm_active_until_date" ) );
		}
		if (v.get_indicator("OpenvzVm_description") != i_null){
			p.setDescription( v.template get<std::string>("OpenvzVm_description" ) );
		}
		if (v.get_indicator("OpenvzVm_diskspace") != i_null){
			p.setDiskspace( v.template get<int>("OpenvzVm_diskspace" ) );
		}
		if (v.get_indicator("OpenvzVm_traffic") != i_null){
			p.setTraffic( v.template get<int>("OpenvzVm_traffic" ) );
		}
		if (v.get_indicator("OpenvzVm_bandwidth") != i_null){
			p.setBandwidth( v.template get<int>("OpenvzVm_bandwidth" ) );
		}
		if (v.get_indicator("OpenvzVm_ram") != i_null){
			p.setRam( v.template get<int>("OpenvzVm_ram" ) );
		}
		if (v.get_indicator("OpenvzVm_ram_burst") != i_null){
			p.setRamBurst( v.template get<int>("OpenvzVm_ram_burst" ) );
		}
		if (v.get_indicator("OpenvzVm_cpu_units") != i_null){
			p.setCpuUnits( v.template get<int>("OpenvzVm_cpu_units" ) );
		}
		if (v.get_indicator("OpenvzVm_cpu_num") != i_null){
			p.setCpuNum( v.template get<int>("OpenvzVm_cpu_num" ) );
		}
		if (v.get_indicator("OpenvzVm_cpu_limit") != i_null){
			p.setCpuLimit( v.template get<int>("OpenvzVm_cpu_limit" ) );
		}
		if (v.get_indicator("OpenvzVm_io_priority") != i_null){
			p.setIoPriority( v.template get<int>("OpenvzVm_io_priority" ) );
		}
		if (v.get_indicator("OpenvzVm_nameserver") != i_null){
			p.setNameserver( v.template get<std::string>("OpenvzVm_nameserver" ) );
		}
		if (v.get_indicator("OpenvzVm_create_dns") != i_null){
			p.setCreateDns( v.template get<std::string>("OpenvzVm_create_dns" ) );
		}
		if (v.get_indicator("OpenvzVm_capability") != i_null){
			p.setCapability( v.template get<std::string>("OpenvzVm_capability" ) );
		}
		if (v.get_indicator("OpenvzVm_config") != i_null){
			p.setConfig( v.template get<std::string>("OpenvzVm_config" ) );
		}
	}
	static void to_base(const OpenvzVm & p, values & v, indicator & ind)
	{
		v.set( "OpenvzVm_vm_id", p.getVmId() );
		v.set( "OpenvzVm_sys_userid", p.getSysUserid() );
		v.set( "OpenvzVm_sys_groupid", p.getSysGroupid() );
		v.set( "OpenvzVm_sys_perm_user", p.getSysPermUser() );
		v.set( "OpenvzVm_sys_perm_group", p.getSysPermGroup() );
		v.set( "OpenvzVm_sys_perm_other", p.getSysPermOther() );
		v.set( "OpenvzVm_server_id", p.getServerId() );
		v.set( "OpenvzVm_veid", p.getVeid() );
		v.set( "OpenvzVm_ostemplate_id", p.getOstemplateId() );
		v.set( "OpenvzVm_template_id", p.getTemplateId() );
		v.set( "OpenvzVm_ip_address", p.getIpAddress() );
		v.set( "OpenvzVm_hostname", p.getHostname() );
		v.set( "OpenvzVm_vm_password", p.getVmPassword() );
		v.set( "OpenvzVm_start_boot", p.getStartBoot() );
		v.set( "OpenvzVm_active", p.getActive() );
		v.set( "OpenvzVm_active_until_date", p.getActiveUntilDate() );
		v.set( "OpenvzVm_description", p.getDescription() );
		v.set( "OpenvzVm_diskspace", p.getDiskspace() );
		v.set( "OpenvzVm_traffic", p.getTraffic() );
		v.set( "OpenvzVm_bandwidth", p.getBandwidth() );
		v.set( "OpenvzVm_ram", p.getRam() );
		v.set( "OpenvzVm_ram_burst", p.getRamBurst() );
		v.set( "OpenvzVm_cpu_units", p.getCpuUnits() );
		v.set( "OpenvzVm_cpu_num", p.getCpuNum() );
		v.set( "OpenvzVm_cpu_limit", p.getCpuLimit() );
		v.set( "OpenvzVm_io_priority", p.getIoPriority() );
		v.set( "OpenvzVm_nameserver", p.getNameserver() );
		v.set( "OpenvzVm_create_dns", p.getCreateDns() );
		v.set( "OpenvzVm_capability", p.getCapability() );
		v.set( "OpenvzVm_config", p.getConfig() );
		ind = i_ok;
	}
};
}

#endif // OPENVZVMREPOSITORY_H
