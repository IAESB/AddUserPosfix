#include "mailbackuprepository.h"
#include "util.hpp"
MailBackupRepository::MailBackupRepository(soci::session& db) : dataBase(db)
{
}

MailBackupPtr MailBackupRepository::select(const MailBackup& obj)
{
	soci::row row;
	MailBackupPtr mailbackup(new MailBackup);
	dataBase << "SELECT  mail_backup.backup_id as MailBackup_backup_id, mail_backup.server_id as MailBackup_server_id, mail_backup.parent_domain_id as MailBackup_parent_domain_id, mail_backup.mailuser_id as MailBackup_mailuser_id, mail_backup.backup_mode as MailBackup_backup_mode, mail_backup.tstamp as MailBackup_tstamp, mail_backup.filename as MailBackup_filename, mail_backup.filesize as MailBackup_filesize"
	" FROM mail_backup "
	"WHERE mail_backup.backup_id = :MailBackup_backup_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailbackup.reset();
	else
		type_conversion<MailBackup>::from_base(row, i_ok, *mailbackup);
	return mailbackup;
}
MailBackupList MailBackupRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_backup.backup_id as MailBackup_backup_id, mail_backup.server_id as MailBackup_server_id, mail_backup.parent_domain_id as MailBackup_parent_domain_id, mail_backup.mailuser_id as MailBackup_mailuser_id, mail_backup.backup_mode as MailBackup_backup_mode, mail_backup.tstamp as MailBackup_tstamp, mail_backup.filename as MailBackup_filename, mail_backup.filesize as MailBackup_filesize "
	" FROM mail_backup" 
	<< (where.size()?" WHERE "+where:"");
	MailBackupList mailbackupList;
	for(row& r: rs)
	{
		MailBackupPtr mailbackup(new MailBackup);
		type_conversion<MailBackup>::from_base(r, i_ok, *mailbackup);
		mailbackupList.push_back(mailbackup);
	}
	return mailbackupList;
}

int MailBackupRepository::insert(const MailBackup& mailbackup)
{
	dataBase << "insert into mail_backup(backup_id, server_id, parent_domain_id, mailuser_id, backup_mode, tstamp, filename, filesize)\
values(:MailBackup_backup_id, :MailBackup_server_id, :MailBackup_parent_domain_id, :MailBackup_mailuser_id, :MailBackup_backup_mode, :MailBackup_tstamp, :MailBackup_filename, :MailBackup_filesize)", use(mailbackup);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailBackupRepository::remove(const MailBackup& mailbackup)
{
	dataBase << "DELETE from mail_backup WHERE backup_id=:MailBackup_backup_id", use(mailbackup);
}

void MailBackupRepository::update(const MailBackup& mailbackup)
{
	dataBase << "update mail_backup set backup_id=:MailBackup_backup_id, server_id=:MailBackup_server_id, parent_domain_id=:MailBackup_parent_domain_id, mailuser_id=:MailBackup_mailuser_id, backup_mode=:MailBackup_backup_mode, tstamp=:MailBackup_tstamp, filename=:MailBackup_filename, filesize=:MailBackup_filesize WHERE backup_id=:MailBackup_backup_id", use(mailbackup);
}

void MailBackupRepository::update(const MailBackup& oldObj, const MailBackup& newObj)
{
	dataBase << "update mail_backup set backup_id=:MailBackup_backup_id, server_id=:MailBackup_server_id, parent_domain_id=:MailBackup_parent_domain_id, mailuser_id=:MailBackup_mailuser_id, backup_mode=:MailBackup_backup_mode, tstamp=:MailBackup_tstamp, filename=:MailBackup_filename, filesize=:MailBackup_filesize WHERE backup_id='"<<oldObj.getBackupId()<<"\'", use(newObj);
}

