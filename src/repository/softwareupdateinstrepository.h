#ifndef SOFTWAREUPDATEINSTREPOSITORY_H
#define SOFTWAREUPDATEINSTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/softwareupdateinst.h"
using namespace soci;


class SoftwareUpdateInstRepository
{
	soci::session& dataBase;
public:
	SoftwareUpdateInstRepository(soci::session& dataBase);
	int insert(const SoftwareUpdateInst& softwareupdateinst);
	SoftwareUpdateInstPtr select(const SoftwareUpdateInst& softwareupdateinst);
	SoftwareUpdateInstList select(const string& where="");
	void update(const SoftwareUpdateInst& softwareupdateinst);
	void update(const SoftwareUpdateInst& oldObj, const SoftwareUpdateInst& newObj);
	void remove(const SoftwareUpdateInst& softwareupdateinst);
};

namespace soci
{
template<>
struct type_conversion<SoftwareUpdateInst>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SoftwareUpdateInst & p)
	{
		if (v.get_indicator("SoftwareUpdateInst_software_update_inst_id") != i_null){
			p.setSoftwareUpdateInstId( v.template get<long long>("SoftwareUpdateInst_software_update_inst_id" ) );
		}
		if (v.get_indicator("SoftwareUpdateInst_software_update_id") != i_null){
			p.setSoftwareUpdateId( v.template get<long long>("SoftwareUpdateInst_software_update_id" ) );
		}
		if (v.get_indicator("SoftwareUpdateInst_package_name") != i_null){
			p.setPackageName( v.template get<std::string>("SoftwareUpdateInst_package_name" ) );
		}
		if (v.get_indicator("SoftwareUpdateInst_server_id") != i_null){
			p.setServerId( v.template get<long long>("SoftwareUpdateInst_server_id" ) );
		}
		if (v.get_indicator("SoftwareUpdateInst_status") != i_null){
			p.setStatus( v.template get<std::string>("SoftwareUpdateInst_status" ) );
		}
	}
	static void to_base(const SoftwareUpdateInst & p, values & v, indicator & ind)
	{
		v.set( "SoftwareUpdateInst_software_update_inst_id", p.getSoftwareUpdateInstId() );
		v.set( "SoftwareUpdateInst_software_update_id", p.getSoftwareUpdateId() );
		v.set( "SoftwareUpdateInst_package_name", p.getPackageName() );
		v.set( "SoftwareUpdateInst_server_id", p.getServerId() );
		v.set( "SoftwareUpdateInst_status", p.getStatus() );
		ind = i_ok;
	}
};
}

#endif // SOFTWAREUPDATEINSTREPOSITORY_H
