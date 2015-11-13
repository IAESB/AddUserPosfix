#ifndef SYSFILESYNCREPOSITORY_H
#define SYSFILESYNCREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysfilesync.h"
using namespace soci;


class SysFilesyncRepository
{
	soci::session& dataBase;
public:
	SysFilesyncRepository(soci::session& dataBase);
	int insert(const SysFilesync& sysfilesync);
	SysFilesyncPtr select(const SysFilesync& sysfilesync);
	SysFilesyncList select(const string& where="");
	void update(const SysFilesync& sysfilesync);
	void update(const SysFilesync& oldObj, const SysFilesync& newObj);
	void remove(const SysFilesync& sysfilesync);
};

namespace soci
{
template<>
struct type_conversion<SysFilesync>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysFilesync & p)
	{
		if (v.get_indicator("SysFilesync_id") != i_null){
			p.setId( v.template get<long long>("SysFilesync_id" ) );
		}
		if (v.get_indicator("SysFilesync_jobname") != i_null){
			p.setJobname( v.template get<std::string>("SysFilesync_jobname" ) );
		}
		if (v.get_indicator("SysFilesync_sync_interval_minutes") != i_null){
			p.setSyncIntervalMinutes( v.template get<long long>("SysFilesync_sync_interval_minutes" ) );
		}
		if (v.get_indicator("SysFilesync_ftp_host") != i_null){
			p.setFtpHost( v.template get<std::string>("SysFilesync_ftp_host" ) );
		}
		if (v.get_indicator("SysFilesync_ftp_path") != i_null){
			p.setFtpPath( v.template get<std::string>("SysFilesync_ftp_path" ) );
		}
		if (v.get_indicator("SysFilesync_ftp_username") != i_null){
			p.setFtpUsername( v.template get<std::string>("SysFilesync_ftp_username" ) );
		}
		if (v.get_indicator("SysFilesync_ftp_password") != i_null){
			p.setFtpPassword( v.template get<std::string>("SysFilesync_ftp_password" ) );
		}
		if (v.get_indicator("SysFilesync_local_path") != i_null){
			p.setLocalPath( v.template get<std::string>("SysFilesync_local_path" ) );
		}
		if (v.get_indicator("SysFilesync_wput_options") != i_null){
			p.setWputOptions( v.template get<std::string>("SysFilesync_wput_options" ) );
		}
		if (v.get_indicator("SysFilesync_active") != i_null){
			p.setActive( v.template get<int>("SysFilesync_active" ) );
		}
	}
	static void to_base(const SysFilesync & p, values & v, indicator & ind)
	{
		v.set( "SysFilesync_id", p.getId() );
		v.set( "SysFilesync_jobname", p.getJobname() );
		v.set( "SysFilesync_sync_interval_minutes", p.getSyncIntervalMinutes() );
		v.set( "SysFilesync_ftp_host", p.getFtpHost() );
		v.set( "SysFilesync_ftp_path", p.getFtpPath() );
		v.set( "SysFilesync_ftp_username", p.getFtpUsername() );
		v.set( "SysFilesync_ftp_password", p.getFtpPassword() );
		v.set( "SysFilesync_local_path", p.getLocalPath() );
		v.set( "SysFilesync_wput_options", p.getWputOptions() );
		v.set( "SysFilesync_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // SYSFILESYNCREPOSITORY_H
