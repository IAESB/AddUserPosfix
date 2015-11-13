#include "webbackuprepository.h"
#include "util.hpp"
WebBackupRepository::WebBackupRepository(soci::session& db) : dataBase(db)
{
}

WebBackupPtr WebBackupRepository::select(const WebBackup& obj)
{
	soci::row row;
	WebBackupPtr webbackup(new WebBackup);
	dataBase << "SELECT  web_backup.backup_id as WebBackup_backup_id, web_backup.server_id as WebBackup_server_id, web_backup.parent_domain_id as WebBackup_parent_domain_id, web_backup.backup_type as WebBackup_backup_type, web_backup.backup_mode as WebBackup_backup_mode, web_backup.tstamp as WebBackup_tstamp, web_backup.filename as WebBackup_filename, web_backup.filesize as WebBackup_filesize"
	" FROM web_backup "
	"WHERE web_backup.backup_id = :WebBackup_backup_id", into(row), use(obj);
	if(!dataBase.got_data())
		webbackup.reset();
	else
		type_conversion<WebBackup>::from_base(row, i_ok, *webbackup);
	return webbackup;
}
WebBackupList WebBackupRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_backup.backup_id as WebBackup_backup_id, web_backup.server_id as WebBackup_server_id, web_backup.parent_domain_id as WebBackup_parent_domain_id, web_backup.backup_type as WebBackup_backup_type, web_backup.backup_mode as WebBackup_backup_mode, web_backup.tstamp as WebBackup_tstamp, web_backup.filename as WebBackup_filename, web_backup.filesize as WebBackup_filesize "
	" FROM web_backup" 
	<< (where.size()?" WHERE "+where:"");
	WebBackupList webbackupList;
	for(row& r: rs)
	{
		WebBackupPtr webbackup(new WebBackup);
		type_conversion<WebBackup>::from_base(r, i_ok, *webbackup);
		webbackupList.push_back(webbackup);
	}
	return webbackupList;
}

int WebBackupRepository::insert(const WebBackup& webbackup)
{
	dataBase << "insert into web_backup(backup_id, server_id, parent_domain_id, backup_type, backup_mode, tstamp, filename, filesize)\
values(:WebBackup_backup_id, :WebBackup_server_id, :WebBackup_parent_domain_id, :WebBackup_backup_type, :WebBackup_backup_mode, :WebBackup_tstamp, :WebBackup_filename, :WebBackup_filesize)", use(webbackup);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebBackupRepository::remove(const WebBackup& webbackup)
{
	dataBase << "DELETE from web_backup WHERE backup_id=:WebBackup_backup_id", use(webbackup);
}

void WebBackupRepository::update(const WebBackup& webbackup)
{
	dataBase << "update web_backup set backup_id=:WebBackup_backup_id, server_id=:WebBackup_server_id, parent_domain_id=:WebBackup_parent_domain_id, backup_type=:WebBackup_backup_type, backup_mode=:WebBackup_backup_mode, tstamp=:WebBackup_tstamp, filename=:WebBackup_filename, filesize=:WebBackup_filesize WHERE backup_id=:WebBackup_backup_id", use(webbackup);
}

void WebBackupRepository::update(const WebBackup& oldObj, const WebBackup& newObj)
{
	dataBase << "update web_backup set backup_id=:WebBackup_backup_id, server_id=:WebBackup_server_id, parent_domain_id=:WebBackup_parent_domain_id, backup_type=:WebBackup_backup_type, backup_mode=:WebBackup_backup_mode, tstamp=:WebBackup_tstamp, filename=:WebBackup_filename, filesize=:WebBackup_filesize WHERE backup_id='"<<oldObj.getBackupId()<<"\'", use(newObj);
}

