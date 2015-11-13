#ifndef OPENVZTEMPLATEREPOSITORY_H
#define OPENVZTEMPLATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/openvztemplate.h"
using namespace soci;


class OpenvzTemplateRepository
{
	soci::session& dataBase;
public:
	OpenvzTemplateRepository(soci::session& dataBase);
	int insert(const OpenvzTemplate& openvztemplate);
	OpenvzTemplatePtr select(const OpenvzTemplate& openvztemplate);
	OpenvzTemplateList select(const string& where="");
	void update(const OpenvzTemplate& openvztemplate);
	void update(const OpenvzTemplate& oldObj, const OpenvzTemplate& newObj);
	void remove(const OpenvzTemplate& openvztemplate);
};

namespace soci
{
template<>
struct type_conversion<OpenvzTemplate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, OpenvzTemplate & p)
	{
		if (v.get_indicator("OpenvzTemplate_template_id") != i_null){
			p.setTemplateId( v.template get<long long>("OpenvzTemplate_template_id" ) );
		}
		if (v.get_indicator("OpenvzTemplate_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("OpenvzTemplate_sys_userid" ) );
		}
		if (v.get_indicator("OpenvzTemplate_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("OpenvzTemplate_sys_groupid" ) );
		}
		if (v.get_indicator("OpenvzTemplate_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("OpenvzTemplate_sys_perm_user" ) );
		}
		if (v.get_indicator("OpenvzTemplate_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("OpenvzTemplate_sys_perm_group" ) );
		}
		if (v.get_indicator("OpenvzTemplate_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("OpenvzTemplate_sys_perm_other" ) );
		}
		if (v.get_indicator("OpenvzTemplate_template_name") != i_null){
			p.setTemplateName( v.template get<std::string>("OpenvzTemplate_template_name" ) );
		}
		if (v.get_indicator("OpenvzTemplate_diskspace") != i_null){
			p.setDiskspace( v.template get<int>("OpenvzTemplate_diskspace" ) );
		}
		if (v.get_indicator("OpenvzTemplate_traffic") != i_null){
			p.setTraffic( v.template get<int>("OpenvzTemplate_traffic" ) );
		}
		if (v.get_indicator("OpenvzTemplate_bandwidth") != i_null){
			p.setBandwidth( v.template get<int>("OpenvzTemplate_bandwidth" ) );
		}
		if (v.get_indicator("OpenvzTemplate_ram") != i_null){
			p.setRam( v.template get<int>("OpenvzTemplate_ram" ) );
		}
		if (v.get_indicator("OpenvzTemplate_ram_burst") != i_null){
			p.setRamBurst( v.template get<int>("OpenvzTemplate_ram_burst" ) );
		}
		if (v.get_indicator("OpenvzTemplate_cpu_units") != i_null){
			p.setCpuUnits( v.template get<int>("OpenvzTemplate_cpu_units" ) );
		}
		if (v.get_indicator("OpenvzTemplate_cpu_num") != i_null){
			p.setCpuNum( v.template get<int>("OpenvzTemplate_cpu_num" ) );
		}
		if (v.get_indicator("OpenvzTemplate_cpu_limit") != i_null){
			p.setCpuLimit( v.template get<int>("OpenvzTemplate_cpu_limit" ) );
		}
		if (v.get_indicator("OpenvzTemplate_io_priority") != i_null){
			p.setIoPriority( v.template get<int>("OpenvzTemplate_io_priority" ) );
		}
		if (v.get_indicator("OpenvzTemplate_active") != i_null){
			p.setActive( v.template get<std::string>("OpenvzTemplate_active" ) );
		}
		if (v.get_indicator("OpenvzTemplate_description") != i_null){
			p.setDescription( v.template get<std::string>("OpenvzTemplate_description" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numproc") != i_null){
			p.setNumproc( v.template get<std::string>("OpenvzTemplate_numproc" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numtcpsock") != i_null){
			p.setNumtcpsock( v.template get<std::string>("OpenvzTemplate_numtcpsock" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numothersock") != i_null){
			p.setNumothersock( v.template get<std::string>("OpenvzTemplate_numothersock" ) );
		}
		if (v.get_indicator("OpenvzTemplate_vmguarpages") != i_null){
			p.setVmguarpages( v.template get<std::string>("OpenvzTemplate_vmguarpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_kmemsize") != i_null){
			p.setKmemsize( v.template get<std::string>("OpenvzTemplate_kmemsize" ) );
		}
		if (v.get_indicator("OpenvzTemplate_tcpsndbuf") != i_null){
			p.setTcpsndbuf( v.template get<std::string>("OpenvzTemplate_tcpsndbuf" ) );
		}
		if (v.get_indicator("OpenvzTemplate_tcprcvbuf") != i_null){
			p.setTcprcvbuf( v.template get<std::string>("OpenvzTemplate_tcprcvbuf" ) );
		}
		if (v.get_indicator("OpenvzTemplate_othersockbuf") != i_null){
			p.setOthersockbuf( v.template get<std::string>("OpenvzTemplate_othersockbuf" ) );
		}
		if (v.get_indicator("OpenvzTemplate_dgramrcvbuf") != i_null){
			p.setDgramrcvbuf( v.template get<std::string>("OpenvzTemplate_dgramrcvbuf" ) );
		}
		if (v.get_indicator("OpenvzTemplate_oomguarpages") != i_null){
			p.setOomguarpages( v.template get<std::string>("OpenvzTemplate_oomguarpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_privvmpages") != i_null){
			p.setPrivvmpages( v.template get<std::string>("OpenvzTemplate_privvmpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_lockedpages") != i_null){
			p.setLockedpages( v.template get<std::string>("OpenvzTemplate_lockedpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_shmpages") != i_null){
			p.setShmpages( v.template get<std::string>("OpenvzTemplate_shmpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_physpages") != i_null){
			p.setPhyspages( v.template get<std::string>("OpenvzTemplate_physpages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numfile") != i_null){
			p.setNumfile( v.template get<std::string>("OpenvzTemplate_numfile" ) );
		}
		if (v.get_indicator("OpenvzTemplate_avnumproc") != i_null){
			p.setAvnumproc( v.template get<std::string>("OpenvzTemplate_avnumproc" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numflock") != i_null){
			p.setNumflock( v.template get<std::string>("OpenvzTemplate_numflock" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numpty") != i_null){
			p.setNumpty( v.template get<std::string>("OpenvzTemplate_numpty" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numsiginfo") != i_null){
			p.setNumsiginfo( v.template get<std::string>("OpenvzTemplate_numsiginfo" ) );
		}
		if (v.get_indicator("OpenvzTemplate_dcachesize") != i_null){
			p.setDcachesize( v.template get<std::string>("OpenvzTemplate_dcachesize" ) );
		}
		if (v.get_indicator("OpenvzTemplate_numiptent") != i_null){
			p.setNumiptent( v.template get<std::string>("OpenvzTemplate_numiptent" ) );
		}
		if (v.get_indicator("OpenvzTemplate_swappages") != i_null){
			p.setSwappages( v.template get<std::string>("OpenvzTemplate_swappages" ) );
		}
		if (v.get_indicator("OpenvzTemplate_hostname") != i_null){
			p.setHostname( v.template get<std::string>("OpenvzTemplate_hostname" ) );
		}
		if (v.get_indicator("OpenvzTemplate_nameserver") != i_null){
			p.setNameserver( v.template get<std::string>("OpenvzTemplate_nameserver" ) );
		}
		if (v.get_indicator("OpenvzTemplate_create_dns") != i_null){
			p.setCreateDns( v.template get<std::string>("OpenvzTemplate_create_dns" ) );
		}
		if (v.get_indicator("OpenvzTemplate_capability") != i_null){
			p.setCapability( v.template get<std::string>("OpenvzTemplate_capability" ) );
		}
	}
	static void to_base(const OpenvzTemplate & p, values & v, indicator & ind)
	{
		v.set( "OpenvzTemplate_template_id", p.getTemplateId() );
		v.set( "OpenvzTemplate_sys_userid", p.getSysUserid() );
		v.set( "OpenvzTemplate_sys_groupid", p.getSysGroupid() );
		v.set( "OpenvzTemplate_sys_perm_user", p.getSysPermUser() );
		v.set( "OpenvzTemplate_sys_perm_group", p.getSysPermGroup() );
		v.set( "OpenvzTemplate_sys_perm_other", p.getSysPermOther() );
		v.set( "OpenvzTemplate_template_name", p.getTemplateName() );
		v.set( "OpenvzTemplate_diskspace", p.getDiskspace() );
		v.set( "OpenvzTemplate_traffic", p.getTraffic() );
		v.set( "OpenvzTemplate_bandwidth", p.getBandwidth() );
		v.set( "OpenvzTemplate_ram", p.getRam() );
		v.set( "OpenvzTemplate_ram_burst", p.getRamBurst() );
		v.set( "OpenvzTemplate_cpu_units", p.getCpuUnits() );
		v.set( "OpenvzTemplate_cpu_num", p.getCpuNum() );
		v.set( "OpenvzTemplate_cpu_limit", p.getCpuLimit() );
		v.set( "OpenvzTemplate_io_priority", p.getIoPriority() );
		v.set( "OpenvzTemplate_active", p.getActive() );
		v.set( "OpenvzTemplate_description", p.getDescription() );
		v.set( "OpenvzTemplate_numproc", p.getNumproc() );
		v.set( "OpenvzTemplate_numtcpsock", p.getNumtcpsock() );
		v.set( "OpenvzTemplate_numothersock", p.getNumothersock() );
		v.set( "OpenvzTemplate_vmguarpages", p.getVmguarpages() );
		v.set( "OpenvzTemplate_kmemsize", p.getKmemsize() );
		v.set( "OpenvzTemplate_tcpsndbuf", p.getTcpsndbuf() );
		v.set( "OpenvzTemplate_tcprcvbuf", p.getTcprcvbuf() );
		v.set( "OpenvzTemplate_othersockbuf", p.getOthersockbuf() );
		v.set( "OpenvzTemplate_dgramrcvbuf", p.getDgramrcvbuf() );
		v.set( "OpenvzTemplate_oomguarpages", p.getOomguarpages() );
		v.set( "OpenvzTemplate_privvmpages", p.getPrivvmpages() );
		v.set( "OpenvzTemplate_lockedpages", p.getLockedpages() );
		v.set( "OpenvzTemplate_shmpages", p.getShmpages() );
		v.set( "OpenvzTemplate_physpages", p.getPhyspages() );
		v.set( "OpenvzTemplate_numfile", p.getNumfile() );
		v.set( "OpenvzTemplate_avnumproc", p.getAvnumproc() );
		v.set( "OpenvzTemplate_numflock", p.getNumflock() );
		v.set( "OpenvzTemplate_numpty", p.getNumpty() );
		v.set( "OpenvzTemplate_numsiginfo", p.getNumsiginfo() );
		v.set( "OpenvzTemplate_dcachesize", p.getDcachesize() );
		v.set( "OpenvzTemplate_numiptent", p.getNumiptent() );
		v.set( "OpenvzTemplate_swappages", p.getSwappages() );
		v.set( "OpenvzTemplate_hostname", p.getHostname() );
		v.set( "OpenvzTemplate_nameserver", p.getNameserver() );
		v.set( "OpenvzTemplate_create_dns", p.getCreateDns() );
		v.set( "OpenvzTemplate_capability", p.getCapability() );
		ind = i_ok;
	}
};
}

#endif // OPENVZTEMPLATEREPOSITORY_H
