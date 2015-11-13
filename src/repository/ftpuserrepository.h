#ifndef FTPUSERREPOSITORY_H
#define FTPUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/ftpuser.h"
using namespace soci;


class FtpUserRepository
{
	soci::session& dataBase;
public:
	FtpUserRepository(soci::session& dataBase);
	int insert(const FtpUser& ftpuser);
	FtpUserPtr select(const FtpUser& ftpuser);
	FtpUserList select(const string& where="");
	void update(const FtpUser& ftpuser);
	void update(const FtpUser& oldObj, const FtpUser& newObj);
	void remove(const FtpUser& ftpuser);
};

namespace soci
{
template<>
struct type_conversion<FtpUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, FtpUser & p)
	{
		if (v.get_indicator("FtpUser_ftp_user_id") != i_null){
			p.setFtpUserId( v.template get<long long>("FtpUser_ftp_user_id" ) );
		}
		if (v.get_indicator("FtpUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("FtpUser_sys_userid" ) );
		}
		if (v.get_indicator("FtpUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("FtpUser_sys_groupid" ) );
		}
		if (v.get_indicator("FtpUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("FtpUser_sys_perm_user" ) );
		}
		if (v.get_indicator("FtpUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("FtpUser_sys_perm_group" ) );
		}
		if (v.get_indicator("FtpUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("FtpUser_sys_perm_other" ) );
		}
		if (v.get_indicator("FtpUser_server_id") != i_null){
			p.setServerId( v.template get<long long>("FtpUser_server_id" ) );
		}
		if (v.get_indicator("FtpUser_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("FtpUser_parent_domain_id" ) );
		}
		if (v.get_indicator("FtpUser_username") != i_null){
			p.setUsername( v.template get<std::string>("FtpUser_username" ) );
		}
		if (v.get_indicator("FtpUser_username_prefix") != i_null){
			p.setUsernamePrefix( v.template get<std::string>("FtpUser_username_prefix" ) );
		}
		if (v.get_indicator("FtpUser_password") != i_null){
			p.setPassword( v.template get<std::string>("FtpUser_password" ) );
		}
		if (v.get_indicator("FtpUser_quota_size") != i_null){
			p.setQuotaSize( v.template get<long long>("FtpUser_quota_size" ) );
		}
		if (v.get_indicator("FtpUser_active") != i_null){
			p.setActive( v.template get<std::string>("FtpUser_active" ) );
		}
		if (v.get_indicator("FtpUser_uid") != i_null){
			p.setUid( v.template get<std::string>("FtpUser_uid" ) );
		}
		if (v.get_indicator("FtpUser_gid") != i_null){
			p.setGid( v.template get<std::string>("FtpUser_gid" ) );
		}
		if (v.get_indicator("FtpUser_dir") != i_null){
			p.setDir( v.template get<std::string>("FtpUser_dir" ) );
		}
		if (v.get_indicator("FtpUser_quota_files") != i_null){
			p.setQuotaFiles( v.template get<long long>("FtpUser_quota_files" ) );
		}
		if (v.get_indicator("FtpUser_ul_ratio") != i_null){
			p.setUlRatio( v.template get<int>("FtpUser_ul_ratio" ) );
		}
		if (v.get_indicator("FtpUser_dl_ratio") != i_null){
			p.setDlRatio( v.template get<int>("FtpUser_dl_ratio" ) );
		}
		if (v.get_indicator("FtpUser_ul_bandwidth") != i_null){
			p.setUlBandwidth( v.template get<int>("FtpUser_ul_bandwidth" ) );
		}
		if (v.get_indicator("FtpUser_dl_bandwidth") != i_null){
			p.setDlBandwidth( v.template get<int>("FtpUser_dl_bandwidth" ) );
		}
		if (v.get_indicator("FtpUser_expires") != i_null){
			p.setExpires( v.template get<tm>("FtpUser_expires" ) );
		}
	}
	static void to_base(const FtpUser & p, values & v, indicator & ind)
	{
		v.set( "FtpUser_ftp_user_id", p.getFtpUserId() );
		v.set( "FtpUser_sys_userid", p.getSysUserid() );
		v.set( "FtpUser_sys_groupid", p.getSysGroupid() );
		v.set( "FtpUser_sys_perm_user", p.getSysPermUser() );
		v.set( "FtpUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "FtpUser_sys_perm_other", p.getSysPermOther() );
		v.set( "FtpUser_server_id", p.getServerId() );
		v.set( "FtpUser_parent_domain_id", p.getParentDomainId() );
		v.set( "FtpUser_username", p.getUsername() );
		v.set( "FtpUser_username_prefix", p.getUsernamePrefix() );
		v.set( "FtpUser_password", p.getPassword() );
		v.set( "FtpUser_quota_size", p.getQuotaSize() );
		v.set( "FtpUser_active", p.getActive() );
		v.set( "FtpUser_uid", p.getUid() );
		v.set( "FtpUser_gid", p.getGid() );
		v.set( "FtpUser_dir", p.getDir() );
		v.set( "FtpUser_quota_files", p.getQuotaFiles() );
		v.set( "FtpUser_ul_ratio", p.getUlRatio() );
		v.set( "FtpUser_dl_ratio", p.getDlRatio() );
		v.set( "FtpUser_ul_bandwidth", p.getUlBandwidth() );
		v.set( "FtpUser_dl_bandwidth", p.getDlBandwidth() );
		v.set( "FtpUser_expires", p.getExpires() );
		ind = i_ok;
	}
};
}

#endif // FTPUSERREPOSITORY_H
