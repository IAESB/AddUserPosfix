#ifndef MAILBACKUPREPOSITORY_H
#define MAILBACKUPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailbackup.h"
using namespace soci;


class MailBackupRepository
{
	soci::session& dataBase;
public:
	MailBackupRepository(soci::session& dataBase);
	int insert(const MailBackup& mailbackup);
	MailBackupPtr select(const MailBackup& mailbackup);
	MailBackupList select(const string& where="");
	void update(const MailBackup& mailbackup);
	void update(const MailBackup& oldObj, const MailBackup& newObj);
	void remove(const MailBackup& mailbackup);
};

namespace soci
{
template<>
struct type_conversion<MailBackup>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailBackup & p)
	{
		if (v.get_indicator("MailBackup_backup_id") != i_null){
			p.setBackupId( v.template get<long long>("MailBackup_backup_id" ) );
		}
		if (v.get_indicator("MailBackup_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailBackup_server_id" ) );
		}
		if (v.get_indicator("MailBackup_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("MailBackup_parent_domain_id" ) );
		}
		if (v.get_indicator("MailBackup_mailuser_id") != i_null){
			p.setMailuserId( v.template get<long long>("MailBackup_mailuser_id" ) );
		}
		if (v.get_indicator("MailBackup_backup_mode") != i_null){
			p.setBackupMode( v.template get<std::string>("MailBackup_backup_mode" ) );
		}
		if (v.get_indicator("MailBackup_tstamp") != i_null){
			p.setTstamp( v.template get<long long>("MailBackup_tstamp" ) );
		}
		if (v.get_indicator("MailBackup_filename") != i_null){
			p.setFilename( v.template get<std::string>("MailBackup_filename" ) );
		}
		if (v.get_indicator("MailBackup_filesize") != i_null){
			p.setFilesize( v.template get<std::string>("MailBackup_filesize" ) );
		}
	}
	static void to_base(const MailBackup & p, values & v, indicator & ind)
	{
		v.set( "MailBackup_backup_id", p.getBackupId() );
		v.set( "MailBackup_server_id", p.getServerId() );
		v.set( "MailBackup_parent_domain_id", p.getParentDomainId() );
		v.set( "MailBackup_mailuser_id", p.getMailuserId() );
		v.set( "MailBackup_backup_mode", p.getBackupMode() );
		v.set( "MailBackup_tstamp", p.getTstamp() );
		v.set( "MailBackup_filename", p.getFilename() );
		v.set( "MailBackup_filesize", p.getFilesize() );
		ind = i_ok;
	}
};
}

#endif // MAILBACKUPREPOSITORY_H
