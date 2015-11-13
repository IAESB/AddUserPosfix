#ifndef WEBBACKUPREPOSITORY_H
#define WEBBACKUPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webbackup.h"
using namespace soci;


class WebBackupRepository
{
	soci::session& dataBase;
public:
	WebBackupRepository(soci::session& dataBase);
	int insert(const WebBackup& webbackup);
	WebBackupPtr select(const WebBackup& webbackup);
	WebBackupList select(const string& where="");
	void update(const WebBackup& webbackup);
	void update(const WebBackup& oldObj, const WebBackup& newObj);
	void remove(const WebBackup& webbackup);
};

namespace soci
{
template<>
struct type_conversion<WebBackup>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebBackup & p)
	{
		if (v.get_indicator("WebBackup_backup_id") != i_null){
			p.setBackupId( v.template get<long long>("WebBackup_backup_id" ) );
		}
		if (v.get_indicator("WebBackup_server_id") != i_null){
			p.setServerId( v.template get<long long>("WebBackup_server_id" ) );
		}
		if (v.get_indicator("WebBackup_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("WebBackup_parent_domain_id" ) );
		}
		if (v.get_indicator("WebBackup_backup_type") != i_null){
			p.setBackupType( v.template get<std::string>("WebBackup_backup_type" ) );
		}
		if (v.get_indicator("WebBackup_backup_mode") != i_null){
			p.setBackupMode( v.template get<std::string>("WebBackup_backup_mode" ) );
		}
		if (v.get_indicator("WebBackup_tstamp") != i_null){
			p.setTstamp( v.template get<long long>("WebBackup_tstamp" ) );
		}
		if (v.get_indicator("WebBackup_filename") != i_null){
			p.setFilename( v.template get<std::string>("WebBackup_filename" ) );
		}
		if (v.get_indicator("WebBackup_filesize") != i_null){
			p.setFilesize( v.template get<std::string>("WebBackup_filesize" ) );
		}
	}
	static void to_base(const WebBackup & p, values & v, indicator & ind)
	{
		v.set( "WebBackup_backup_id", p.getBackupId() );
		v.set( "WebBackup_server_id", p.getServerId() );
		v.set( "WebBackup_parent_domain_id", p.getParentDomainId() );
		v.set( "WebBackup_backup_type", p.getBackupType() );
		v.set( "WebBackup_backup_mode", p.getBackupMode() );
		v.set( "WebBackup_tstamp", p.getTstamp() );
		v.set( "WebBackup_filename", p.getFilename() );
		v.set( "WebBackup_filesize", p.getFilesize() );
		ind = i_ok;
	}
};
}

#endif // WEBBACKUPREPOSITORY_H
