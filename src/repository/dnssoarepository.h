#ifndef DNSSOAREPOSITORY_H
#define DNSSOAREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/dnssoa.h"
using namespace soci;


class DnsSoaRepository
{
	soci::session& dataBase;
public:
	DnsSoaRepository(soci::session& dataBase);
	int insert(const DnsSoa& dnssoa);
	DnsSoaPtr select(const DnsSoa& dnssoa);
	DnsSoaList select(const string& where="");
	void update(const DnsSoa& dnssoa);
	void update(const DnsSoa& oldObj, const DnsSoa& newObj);
	void remove(const DnsSoa& dnssoa);
};

namespace soci
{
template<>
struct type_conversion<DnsSoa>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, DnsSoa & p)
	{
		if (v.get_indicator("DnsSoa_id") != i_null){
			p.setId( v.template get<long long>("DnsSoa_id" ) );
		}
		if (v.get_indicator("DnsSoa_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("DnsSoa_sys_userid" ) );
		}
		if (v.get_indicator("DnsSoa_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("DnsSoa_sys_groupid" ) );
		}
		if (v.get_indicator("DnsSoa_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("DnsSoa_sys_perm_user" ) );
		}
		if (v.get_indicator("DnsSoa_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("DnsSoa_sys_perm_group" ) );
		}
		if (v.get_indicator("DnsSoa_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("DnsSoa_sys_perm_other" ) );
		}
		if (v.get_indicator("DnsSoa_server_id") != i_null){
			p.setServerId( v.template get<int>("DnsSoa_server_id" ) );
		}
		if (v.get_indicator("DnsSoa_origin") != i_null){
			p.setOrigin( v.template get<std::string>("DnsSoa_origin" ) );
		}
		if (v.get_indicator("DnsSoa_ns") != i_null){
			p.setNs( v.template get<std::string>("DnsSoa_ns" ) );
		}
		if (v.get_indicator("DnsSoa_mbox") != i_null){
			p.setMbox( v.template get<std::string>("DnsSoa_mbox" ) );
		}
		if (v.get_indicator("DnsSoa_serial") != i_null){
			p.setSerial( v.template get<long long>("DnsSoa_serial" ) );
		}
		if (v.get_indicator("DnsSoa_refresh") != i_null){
			p.setRefresh( v.template get<long long>("DnsSoa_refresh" ) );
		}
		if (v.get_indicator("DnsSoa_retry") != i_null){
			p.setRetry( v.template get<long long>("DnsSoa_retry" ) );
		}
		if (v.get_indicator("DnsSoa_expire") != i_null){
			p.setExpire( v.template get<long long>("DnsSoa_expire" ) );
		}
		if (v.get_indicator("DnsSoa_minimum") != i_null){
			p.setMinimum( v.template get<long long>("DnsSoa_minimum" ) );
		}
		if (v.get_indicator("DnsSoa_ttl") != i_null){
			p.setTtl( v.template get<long long>("DnsSoa_ttl" ) );
		}
		if (v.get_indicator("DnsSoa_active") != i_null){
			p.setActive( v.template get<std::string>("DnsSoa_active" ) );
		}
		if (v.get_indicator("DnsSoa_xfer") != i_null){
			p.setXfer( v.template get<std::string>("DnsSoa_xfer" ) );
		}
		if (v.get_indicator("DnsSoa_also_notify") != i_null){
			p.setAlsoNotify( v.template get<std::string>("DnsSoa_also_notify" ) );
		}
		if (v.get_indicator("DnsSoa_update_acl") != i_null){
			p.setUpdateAcl( v.template get<std::string>("DnsSoa_update_acl" ) );
		}
	}
	static void to_base(const DnsSoa & p, values & v, indicator & ind)
	{
		v.set( "DnsSoa_id", p.getId() );
		v.set( "DnsSoa_sys_userid", p.getSysUserid() );
		v.set( "DnsSoa_sys_groupid", p.getSysGroupid() );
		v.set( "DnsSoa_sys_perm_user", p.getSysPermUser() );
		v.set( "DnsSoa_sys_perm_group", p.getSysPermGroup() );
		v.set( "DnsSoa_sys_perm_other", p.getSysPermOther() );
		v.set( "DnsSoa_server_id", p.getServerId() );
		v.set( "DnsSoa_origin", p.getOrigin() );
		v.set( "DnsSoa_ns", p.getNs() );
		v.set( "DnsSoa_mbox", p.getMbox() );
		v.set( "DnsSoa_serial", p.getSerial() );
		v.set( "DnsSoa_refresh", p.getRefresh() );
		v.set( "DnsSoa_retry", p.getRetry() );
		v.set( "DnsSoa_expire", p.getExpire() );
		v.set( "DnsSoa_minimum", p.getMinimum() );
		v.set( "DnsSoa_ttl", p.getTtl() );
		v.set( "DnsSoa_active", p.getActive() );
		v.set( "DnsSoa_xfer", p.getXfer() );
		v.set( "DnsSoa_also_notify", p.getAlsoNotify() );
		v.set( "DnsSoa_update_acl", p.getUpdateAcl() );
		ind = i_ok;
	}
};
}

#endif // DNSSOAREPOSITORY_H
