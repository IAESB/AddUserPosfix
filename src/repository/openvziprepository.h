#ifndef OPENVZIPREPOSITORY_H
#define OPENVZIPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/openvzip.h"
using namespace soci;


class OpenvzIpRepository
{
	soci::session& dataBase;
public:
	OpenvzIpRepository(soci::session& dataBase);
	int insert(const OpenvzIp& openvzip);
	OpenvzIpPtr select(const OpenvzIp& openvzip);
	OpenvzIpList select(const string& where="");
	void update(const OpenvzIp& openvzip);
	void update(const OpenvzIp& oldObj, const OpenvzIp& newObj);
	void remove(const OpenvzIp& openvzip);
};

namespace soci
{
template<>
struct type_conversion<OpenvzIp>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, OpenvzIp & p)
	{
		if (v.get_indicator("OpenvzIp_ip_address_id") != i_null){
			p.setIpAddressId( v.template get<long long>("OpenvzIp_ip_address_id" ) );
		}
		if (v.get_indicator("OpenvzIp_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("OpenvzIp_sys_userid" ) );
		}
		if (v.get_indicator("OpenvzIp_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("OpenvzIp_sys_groupid" ) );
		}
		if (v.get_indicator("OpenvzIp_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("OpenvzIp_sys_perm_user" ) );
		}
		if (v.get_indicator("OpenvzIp_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("OpenvzIp_sys_perm_group" ) );
		}
		if (v.get_indicator("OpenvzIp_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("OpenvzIp_sys_perm_other" ) );
		}
		if (v.get_indicator("OpenvzIp_server_id") != i_null){
			p.setServerId( v.template get<int>("OpenvzIp_server_id" ) );
		}
		if (v.get_indicator("OpenvzIp_ip_address") != i_null){
			p.setIpAddress( v.template get<std::string>("OpenvzIp_ip_address" ) );
		}
		if (v.get_indicator("OpenvzIp_vm_id") != i_null){
			p.setVmId( v.template get<int>("OpenvzIp_vm_id" ) );
		}
		if (v.get_indicator("OpenvzIp_reserved") != i_null){
			p.setReserved( v.template get<std::string>("OpenvzIp_reserved" ) );
		}
	}
	static void to_base(const OpenvzIp & p, values & v, indicator & ind)
	{
		v.set( "OpenvzIp_ip_address_id", p.getIpAddressId() );
		v.set( "OpenvzIp_sys_userid", p.getSysUserid() );
		v.set( "OpenvzIp_sys_groupid", p.getSysGroupid() );
		v.set( "OpenvzIp_sys_perm_user", p.getSysPermUser() );
		v.set( "OpenvzIp_sys_perm_group", p.getSysPermGroup() );
		v.set( "OpenvzIp_sys_perm_other", p.getSysPermOther() );
		v.set( "OpenvzIp_server_id", p.getServerId() );
		v.set( "OpenvzIp_ip_address", p.getIpAddress() );
		v.set( "OpenvzIp_vm_id", p.getVmId() );
		v.set( "OpenvzIp_reserved", p.getReserved() );
		ind = i_ok;
	}
};
}

#endif // OPENVZIPREPOSITORY_H
