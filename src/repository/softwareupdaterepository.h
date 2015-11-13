#ifndef SOFTWAREUPDATEREPOSITORY_H
#define SOFTWAREUPDATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/softwareupdate.h"
using namespace soci;


class SoftwareUpdateRepository
{
	soci::session& dataBase;
public:
	SoftwareUpdateRepository(soci::session& dataBase);
	int insert(const SoftwareUpdate& softwareupdate);
	SoftwareUpdatePtr select(const SoftwareUpdate& softwareupdate);
	SoftwareUpdateList select(const string& where="");
	void update(const SoftwareUpdate& softwareupdate);
	void update(const SoftwareUpdate& oldObj, const SoftwareUpdate& newObj);
	void remove(const SoftwareUpdate& softwareupdate);
};

namespace soci
{
template<>
struct type_conversion<SoftwareUpdate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SoftwareUpdate & p)
	{
		if (v.get_indicator("SoftwareUpdate_software_update_id") != i_null){
			p.setSoftwareUpdateId( v.template get<long long>("SoftwareUpdate_software_update_id" ) );
		}
		if (v.get_indicator("SoftwareUpdate_software_repo_id") != i_null){
			p.setSoftwareRepoId( v.template get<long long>("SoftwareUpdate_software_repo_id" ) );
		}
		if (v.get_indicator("SoftwareUpdate_package_name") != i_null){
			p.setPackageName( v.template get<std::string>("SoftwareUpdate_package_name" ) );
		}
		if (v.get_indicator("SoftwareUpdate_update_url") != i_null){
			p.setUpdateUrl( v.template get<std::string>("SoftwareUpdate_update_url" ) );
		}
		if (v.get_indicator("SoftwareUpdate_update_md5") != i_null){
			p.setUpdateMd5( v.template get<std::string>("SoftwareUpdate_update_md5" ) );
		}
		if (v.get_indicator("SoftwareUpdate_update_dependencies") != i_null){
			p.setUpdateDependencies( v.template get<std::string>("SoftwareUpdate_update_dependencies" ) );
		}
		if (v.get_indicator("SoftwareUpdate_update_title") != i_null){
			p.setUpdateTitle( v.template get<std::string>("SoftwareUpdate_update_title" ) );
		}
		if (v.get_indicator("SoftwareUpdate_v1") != i_null){
			p.setV1( v.template get<int>("SoftwareUpdate_v1" ) );
		}
		if (v.get_indicator("SoftwareUpdate_v2") != i_null){
			p.setV2( v.template get<int>("SoftwareUpdate_v2" ) );
		}
		if (v.get_indicator("SoftwareUpdate_v3") != i_null){
			p.setV3( v.template get<int>("SoftwareUpdate_v3" ) );
		}
		if (v.get_indicator("SoftwareUpdate_v4") != i_null){
			p.setV4( v.template get<int>("SoftwareUpdate_v4" ) );
		}
		if (v.get_indicator("SoftwareUpdate_type") != i_null){
			p.setType( v.template get<std::string>("SoftwareUpdate_type" ) );
		}
	}
	static void to_base(const SoftwareUpdate & p, values & v, indicator & ind)
	{
		v.set( "SoftwareUpdate_software_update_id", p.getSoftwareUpdateId() );
		v.set( "SoftwareUpdate_software_repo_id", p.getSoftwareRepoId() );
		v.set( "SoftwareUpdate_package_name", p.getPackageName() );
		v.set( "SoftwareUpdate_update_url", p.getUpdateUrl() );
		v.set( "SoftwareUpdate_update_md5", p.getUpdateMd5() );
		v.set( "SoftwareUpdate_update_dependencies", p.getUpdateDependencies() );
		v.set( "SoftwareUpdate_update_title", p.getUpdateTitle() );
		v.set( "SoftwareUpdate_v1", p.getV1() );
		v.set( "SoftwareUpdate_v2", p.getV2() );
		v.set( "SoftwareUpdate_v3", p.getV3() );
		v.set( "SoftwareUpdate_v4", p.getV4() );
		v.set( "SoftwareUpdate_type", p.getType() );
		ind = i_ok;
	}
};
}

#endif // SOFTWAREUPDATEREPOSITORY_H
