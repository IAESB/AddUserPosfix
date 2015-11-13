#include "mailuserrepository.h"
#include "util.hpp"
MailUserRepository::MailUserRepository(soci::session& db) : dataBase(db)
{
}

MailUserPtr MailUserRepository::select(const MailUser& obj)
{
	soci::row row;
	MailUserPtr mailuser(new MailUser);
	dataBase << "SELECT  mail_user.mailuser_id as MailUser_mailuser_id, mail_user.sys_userid as MailUser_sys_userid, mail_user.sys_groupid as MailUser_sys_groupid, mail_user.sys_perm_user as MailUser_sys_perm_user, mail_user.sys_perm_group as MailUser_sys_perm_group, mail_user.sys_perm_other as MailUser_sys_perm_other, mail_user.server_id as MailUser_server_id, mail_user.email as MailUser_email, mail_user.login as MailUser_login, mail_user.password as MailUser_password, mail_user.name as MailUser_name, mail_user.uid as MailUser_uid, mail_user.gid as MailUser_gid, mail_user.maildir as MailUser_maildir, mail_user.quota as MailUser_quota, mail_user.cc as MailUser_cc, mail_user.homedir as MailUser_homedir, mail_user.autoresponder as MailUser_autoresponder, mail_user.autoresponder_start_date as MailUser_autoresponder_start_date, mail_user.autoresponder_end_date as MailUser_autoresponder_end_date, mail_user.autoresponder_subject as MailUser_autoresponder_subject, mail_user.autoresponder_text as MailUser_autoresponder_text, mail_user.move_junk as MailUser_move_junk, mail_user.custom_mailfilter as MailUser_custom_mailfilter, mail_user.postfix as MailUser_postfix, mail_user.access as MailUser_access, mail_user.disableimap as MailUser_disableimap, mail_user.disablepop3 as MailUser_disablepop3, mail_user.disabledeliver as MailUser_disabledeliver, mail_user.disablesmtp as MailUser_disablesmtp, mail_user.disablesieve as MailUser_disablesieve, mail_user.disablesieve-filter as MailUser_disablesieve_filter, mail_user.disablelda as MailUser_disablelda, mail_user.disablelmtp as MailUser_disablelmtp, mail_user.disabledoveadm as MailUser_disabledoveadm, mail_user.last_quota_notification as MailUser_last_quota_notification, mail_user.backup_interval as MailUser_backup_interval, mail_user.backup_copies as MailUser_backup_copies"
	" FROM mail_user "
	"WHERE mail_user.mailuser_id = :MailUser_mailuser_id AND mail_user.server_id = :MailUser_server_id AND mail_user.email = :MailUser_email", into(row), use(obj);
	if(!dataBase.got_data())
		mailuser.reset();
	else
		type_conversion<MailUser>::from_base(row, i_ok, *mailuser);
	return mailuser;
}
MailUserList MailUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_user.mailuser_id as MailUser_mailuser_id, mail_user.sys_userid as MailUser_sys_userid, mail_user.sys_groupid as MailUser_sys_groupid, mail_user.sys_perm_user as MailUser_sys_perm_user, mail_user.sys_perm_group as MailUser_sys_perm_group, mail_user.sys_perm_other as MailUser_sys_perm_other, mail_user.server_id as MailUser_server_id, mail_user.email as MailUser_email, mail_user.login as MailUser_login, mail_user.password as MailUser_password, mail_user.name as MailUser_name, mail_user.uid as MailUser_uid, mail_user.gid as MailUser_gid, mail_user.maildir as MailUser_maildir, mail_user.quota as MailUser_quota, mail_user.cc as MailUser_cc, mail_user.homedir as MailUser_homedir, mail_user.autoresponder as MailUser_autoresponder, mail_user.autoresponder_start_date as MailUser_autoresponder_start_date, mail_user.autoresponder_end_date as MailUser_autoresponder_end_date, mail_user.autoresponder_subject as MailUser_autoresponder_subject, mail_user.autoresponder_text as MailUser_autoresponder_text, mail_user.move_junk as MailUser_move_junk, mail_user.custom_mailfilter as MailUser_custom_mailfilter, mail_user.postfix as MailUser_postfix, mail_user.access as MailUser_access, mail_user.disableimap as MailUser_disableimap, mail_user.disablepop3 as MailUser_disablepop3, mail_user.disabledeliver as MailUser_disabledeliver, mail_user.disablesmtp as MailUser_disablesmtp, mail_user.disablesieve as MailUser_disablesieve, mail_user.disablesieve-filter as MailUser_disablesieve_filter, mail_user.disablelda as MailUser_disablelda, mail_user.disablelmtp as MailUser_disablelmtp, mail_user.disabledoveadm as MailUser_disabledoveadm, mail_user.last_quota_notification as MailUser_last_quota_notification, mail_user.backup_interval as MailUser_backup_interval, mail_user.backup_copies as MailUser_backup_copies "
	" FROM mail_user" 
	<< (where.size()?" WHERE "+where:"");
	MailUserList mailuserList;
	for(row& r: rs)
	{
		MailUserPtr mailuser(new MailUser);
		type_conversion<MailUser>::from_base(r, i_ok, *mailuser);
		mailuserList.push_back(mailuser);
	}
	return mailuserList;
}

int MailUserRepository::insert(const MailUser& mailuser)
{
    dataBase << "insert into mail_user(mailuser_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, email, login, password, name, uid, gid, maildir, quota, cc, homedir, autoresponder, autoresponder_start_date, autoresponder_end_date, autoresponder_subject, autoresponder_text, move_junk, custom_mailfilter, postfix, access, disableimap, disablepop3, disabledeliver, disablesmtp, disablesieve, disablelda, disablelmtp, disabledoveadm, last_quota_notification, backup_interval, backup_copies)\
values(:MailUser_mailuser_id, :MailUser_sys_userid, :MailUser_sys_groupid, :MailUser_sys_perm_user, :MailUser_sys_perm_group, :MailUser_sys_perm_other, :MailUser_server_id, :MailUser_email, :MailUser_login, :MailUser_password, :MailUser_name, :MailUser_uid, :MailUser_gid, :MailUser_maildir, :MailUser_quota, :MailUser_cc, :MailUser_homedir, :MailUser_autoresponder, :MailUser_autoresponder_start_date, :MailUser_autoresponder_end_date, :MailUser_autoresponder_subject, :MailUser_autoresponder_text, :MailUser_move_junk, :MailUser_custom_mailfilter, :MailUser_postfix, :MailUser_access, :MailUser_disableimap, :MailUser_disablepop3, :MailUser_disabledeliver, :MailUser_disablesmtp, :MailUser_disablesieve, :MailUser_disablelda, :MailUser_disablelmtp, :MailUser_disabledoveadm, :MailUser_last_quota_notification, :MailUser_backup_interval, :MailUser_backup_copies)", use(mailuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailUserRepository::remove(const MailUser& mailuser)
{
	dataBase << "DELETE from mail_user WHERE mailuser_id=:MailUser_mailuser_id AND server_id=:MailUser_server_id AND email=:MailUser_email", use(mailuser);
}

void MailUserRepository::update(const MailUser& mailuser)
{
	dataBase << "update mail_user set mailuser_id=:MailUser_mailuser_id, sys_userid=:MailUser_sys_userid, sys_groupid=:MailUser_sys_groupid, sys_perm_user=:MailUser_sys_perm_user, sys_perm_group=:MailUser_sys_perm_group, sys_perm_other=:MailUser_sys_perm_other, server_id=:MailUser_server_id, email=:MailUser_email, login=:MailUser_login, password=:MailUser_password, name=:MailUser_name, uid=:MailUser_uid, gid=:MailUser_gid, maildir=:MailUser_maildir, quota=:MailUser_quota, cc=:MailUser_cc, homedir=:MailUser_homedir, autoresponder=:MailUser_autoresponder, autoresponder_start_date=:MailUser_autoresponder_start_date, autoresponder_end_date=:MailUser_autoresponder_end_date, autoresponder_subject=:MailUser_autoresponder_subject, autoresponder_text=:MailUser_autoresponder_text, move_junk=:MailUser_move_junk, custom_mailfilter=:MailUser_custom_mailfilter, postfix=:MailUser_postfix, access=:MailUser_access, disableimap=:MailUser_disableimap, disablepop3=:MailUser_disablepop3, disabledeliver=:MailUser_disabledeliver, disablesmtp=:MailUser_disablesmtp, disablesieve=:MailUser_disablesieve, disablesieve_filter=:MailUser_disablesieve_filter, disablelda=:MailUser_disablelda, disablelmtp=:MailUser_disablelmtp, disabledoveadm=:MailUser_disabledoveadm, last_quota_notification=:MailUser_last_quota_notification, backup_interval=:MailUser_backup_interval, backup_copies=:MailUser_backup_copies WHERE mailuser_id=:MailUser_mailuser_id AND server_id=:MailUser_server_id AND email=:MailUser_email", use(mailuser);
}

void MailUserRepository::update(const MailUser& oldObj, const MailUser& newObj)
{
	dataBase << "update mail_user set mailuser_id=:MailUser_mailuser_id, sys_userid=:MailUser_sys_userid, sys_groupid=:MailUser_sys_groupid, sys_perm_user=:MailUser_sys_perm_user, sys_perm_group=:MailUser_sys_perm_group, sys_perm_other=:MailUser_sys_perm_other, server_id=:MailUser_server_id, email=:MailUser_email, login=:MailUser_login, password=:MailUser_password, name=:MailUser_name, uid=:MailUser_uid, gid=:MailUser_gid, maildir=:MailUser_maildir, quota=:MailUser_quota, cc=:MailUser_cc, homedir=:MailUser_homedir, autoresponder=:MailUser_autoresponder, autoresponder_start_date=:MailUser_autoresponder_start_date, autoresponder_end_date=:MailUser_autoresponder_end_date, autoresponder_subject=:MailUser_autoresponder_subject, autoresponder_text=:MailUser_autoresponder_text, move_junk=:MailUser_move_junk, custom_mailfilter=:MailUser_custom_mailfilter, postfix=:MailUser_postfix, access=:MailUser_access, disableimap=:MailUser_disableimap, disablepop3=:MailUser_disablepop3, disabledeliver=:MailUser_disabledeliver, disablesmtp=:MailUser_disablesmtp, disablesieve=:MailUser_disablesieve, disablesieve_filter=:MailUser_disablesieve_filter, disablelda=:MailUser_disablelda, disablelmtp=:MailUser_disablelmtp, disabledoveadm=:MailUser_disabledoveadm, last_quota_notification=:MailUser_last_quota_notification, backup_interval=:MailUser_backup_interval, backup_copies=:MailUser_backup_copies WHERE mailuser_id='"<<oldObj.getMailuserId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'' AND email='"<<oldObj.getEmail()<<"\'", use(newObj);
}

