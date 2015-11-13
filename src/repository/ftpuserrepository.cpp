#include "ftpuserrepository.h"
#include "util.hpp"
FtpUserRepository::FtpUserRepository(soci::session& db) : dataBase(db)
{
}

FtpUserPtr FtpUserRepository::select(const FtpUser& obj)
{
	soci::row row;
	FtpUserPtr ftpuser(new FtpUser);
	dataBase << "SELECT  ftp_user.ftp_user_id as FtpUser_ftp_user_id, ftp_user.sys_userid as FtpUser_sys_userid, ftp_user.sys_groupid as FtpUser_sys_groupid, ftp_user.sys_perm_user as FtpUser_sys_perm_user, ftp_user.sys_perm_group as FtpUser_sys_perm_group, ftp_user.sys_perm_other as FtpUser_sys_perm_other, ftp_user.server_id as FtpUser_server_id, ftp_user.parent_domain_id as FtpUser_parent_domain_id, ftp_user.username as FtpUser_username, ftp_user.username_prefix as FtpUser_username_prefix, ftp_user.password as FtpUser_password, ftp_user.quota_size as FtpUser_quota_size, ftp_user.active as FtpUser_active, ftp_user.uid as FtpUser_uid, ftp_user.gid as FtpUser_gid, ftp_user.dir as FtpUser_dir, ftp_user.quota_files as FtpUser_quota_files, ftp_user.ul_ratio as FtpUser_ul_ratio, ftp_user.dl_ratio as FtpUser_dl_ratio, ftp_user.ul_bandwidth as FtpUser_ul_bandwidth, ftp_user.dl_bandwidth as FtpUser_dl_bandwidth, ftp_user.expires as FtpUser_expires"
	" FROM ftp_user "
	"WHERE ftp_user.ftp_user_id = :FtpUser_ftp_user_id AND ftp_user.server_id = :FtpUser_server_id AND ftp_user.username = :FtpUser_username AND ftp_user.active = :FtpUser_active AND ftp_user.quota_files = :FtpUser_quota_files", into(row), use(obj);
	if(!dataBase.got_data())
		ftpuser.reset();
	else
		type_conversion<FtpUser>::from_base(row, i_ok, *ftpuser);
	return ftpuser;
}
FtpUserList FtpUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  ftp_user.ftp_user_id as FtpUser_ftp_user_id, ftp_user.sys_userid as FtpUser_sys_userid, ftp_user.sys_groupid as FtpUser_sys_groupid, ftp_user.sys_perm_user as FtpUser_sys_perm_user, ftp_user.sys_perm_group as FtpUser_sys_perm_group, ftp_user.sys_perm_other as FtpUser_sys_perm_other, ftp_user.server_id as FtpUser_server_id, ftp_user.parent_domain_id as FtpUser_parent_domain_id, ftp_user.username as FtpUser_username, ftp_user.username_prefix as FtpUser_username_prefix, ftp_user.password as FtpUser_password, ftp_user.quota_size as FtpUser_quota_size, ftp_user.active as FtpUser_active, ftp_user.uid as FtpUser_uid, ftp_user.gid as FtpUser_gid, ftp_user.dir as FtpUser_dir, ftp_user.quota_files as FtpUser_quota_files, ftp_user.ul_ratio as FtpUser_ul_ratio, ftp_user.dl_ratio as FtpUser_dl_ratio, ftp_user.ul_bandwidth as FtpUser_ul_bandwidth, ftp_user.dl_bandwidth as FtpUser_dl_bandwidth, ftp_user.expires as FtpUser_expires "
	" FROM ftp_user" 
	<< (where.size()?" WHERE "+where:"");
	FtpUserList ftpuserList;
	for(row& r: rs)
	{
		FtpUserPtr ftpuser(new FtpUser);
		type_conversion<FtpUser>::from_base(r, i_ok, *ftpuser);
		ftpuserList.push_back(ftpuser);
	}
	return ftpuserList;
}

int FtpUserRepository::insert(const FtpUser& ftpuser)
{
	dataBase << "insert into ftp_user(ftp_user_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, username, username_prefix, password, quota_size, active, uid, gid, dir, quota_files, ul_ratio, dl_ratio, ul_bandwidth, dl_bandwidth, expires)\
values(:FtpUser_ftp_user_id, :FtpUser_sys_userid, :FtpUser_sys_groupid, :FtpUser_sys_perm_user, :FtpUser_sys_perm_group, :FtpUser_sys_perm_other, :FtpUser_server_id, :FtpUser_parent_domain_id, :FtpUser_username, :FtpUser_username_prefix, :FtpUser_password, :FtpUser_quota_size, :FtpUser_active, :FtpUser_uid, :FtpUser_gid, :FtpUser_dir, :FtpUser_quota_files, :FtpUser_ul_ratio, :FtpUser_dl_ratio, :FtpUser_ul_bandwidth, :FtpUser_dl_bandwidth, :FtpUser_expires)", use(ftpuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void FtpUserRepository::remove(const FtpUser& ftpuser)
{
	dataBase << "DELETE from ftp_user WHERE ftp_user_id=:FtpUser_ftp_user_id AND server_id=:FtpUser_server_id AND username=:FtpUser_username AND active=:FtpUser_active AND quota_files=:FtpUser_quota_files", use(ftpuser);
}

void FtpUserRepository::update(const FtpUser& ftpuser)
{
	dataBase << "update ftp_user set ftp_user_id=:FtpUser_ftp_user_id, sys_userid=:FtpUser_sys_userid, sys_groupid=:FtpUser_sys_groupid, sys_perm_user=:FtpUser_sys_perm_user, sys_perm_group=:FtpUser_sys_perm_group, sys_perm_other=:FtpUser_sys_perm_other, server_id=:FtpUser_server_id, parent_domain_id=:FtpUser_parent_domain_id, username=:FtpUser_username, username_prefix=:FtpUser_username_prefix, password=:FtpUser_password, quota_size=:FtpUser_quota_size, active=:FtpUser_active, uid=:FtpUser_uid, gid=:FtpUser_gid, dir=:FtpUser_dir, quota_files=:FtpUser_quota_files, ul_ratio=:FtpUser_ul_ratio, dl_ratio=:FtpUser_dl_ratio, ul_bandwidth=:FtpUser_ul_bandwidth, dl_bandwidth=:FtpUser_dl_bandwidth, expires=:FtpUser_expires WHERE ftp_user_id=:FtpUser_ftp_user_id AND server_id=:FtpUser_server_id AND username=:FtpUser_username AND active=:FtpUser_active AND quota_files=:FtpUser_quota_files", use(ftpuser);
}

void FtpUserRepository::update(const FtpUser& oldObj, const FtpUser& newObj)
{
	dataBase << "update ftp_user set ftp_user_id=:FtpUser_ftp_user_id, sys_userid=:FtpUser_sys_userid, sys_groupid=:FtpUser_sys_groupid, sys_perm_user=:FtpUser_sys_perm_user, sys_perm_group=:FtpUser_sys_perm_group, sys_perm_other=:FtpUser_sys_perm_other, server_id=:FtpUser_server_id, parent_domain_id=:FtpUser_parent_domain_id, username=:FtpUser_username, username_prefix=:FtpUser_username_prefix, password=:FtpUser_password, quota_size=:FtpUser_quota_size, active=:FtpUser_active, uid=:FtpUser_uid, gid=:FtpUser_gid, dir=:FtpUser_dir, quota_files=:FtpUser_quota_files, ul_ratio=:FtpUser_ul_ratio, dl_ratio=:FtpUser_dl_ratio, ul_bandwidth=:FtpUser_ul_bandwidth, dl_bandwidth=:FtpUser_dl_bandwidth, expires=:FtpUser_expires WHERE ftp_user_id='"<<oldObj.getFtpUserId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'' AND username='"<<oldObj.getUsername()<<"\'' AND active='"<<oldObj.getActive()<<"\'' AND quota_files='"<<oldObj.getQuotaFiles()<<"\'", use(newObj);
}

