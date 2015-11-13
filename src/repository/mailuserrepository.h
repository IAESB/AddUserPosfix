#ifndef MAILUSERREPOSITORY_H
#define MAILUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailuser.h"
using namespace soci;


class MailUserRepository
{
	soci::session& dataBase;
public:
	MailUserRepository(soci::session& dataBase);
	int insert(const MailUser& mailuser);
	MailUserPtr select(const MailUser& mailuser);
	MailUserList select(const string& where="");
	void update(const MailUser& mailuser);
	void update(const MailUser& oldObj, const MailUser& newObj);
	void remove(const MailUser& mailuser);
};

namespace soci
{
template<>
struct type_conversion<MailUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailUser & p)
	{
		if (v.get_indicator("MailUser_mailuser_id") != i_null){
			p.setMailuserId( v.template get<long long>("MailUser_mailuser_id" ) );
		}
		if (v.get_indicator("MailUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailUser_sys_userid" ) );
		}
		if (v.get_indicator("MailUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailUser_sys_groupid" ) );
		}
		if (v.get_indicator("MailUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailUser_sys_perm_user" ) );
		}
		if (v.get_indicator("MailUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailUser_sys_perm_group" ) );
		}
		if (v.get_indicator("MailUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailUser_sys_perm_other" ) );
		}
		if (v.get_indicator("MailUser_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailUser_server_id" ) );
		}
		if (v.get_indicator("MailUser_email") != i_null){
			p.setEmail( v.template get<std::string>("MailUser_email" ) );
		}
		if (v.get_indicator("MailUser_login") != i_null){
			p.setLogin( v.template get<std::string>("MailUser_login" ) );
		}
		if (v.get_indicator("MailUser_password") != i_null){
			p.setPassword( v.template get<std::string>("MailUser_password" ) );
		}
		if (v.get_indicator("MailUser_name") != i_null){
			p.setName( v.template get<std::string>("MailUser_name" ) );
		}
		if (v.get_indicator("MailUser_uid") != i_null){
			p.setUid( v.template get<int>("MailUser_uid" ) );
		}
		if (v.get_indicator("MailUser_gid") != i_null){
			p.setGid( v.template get<int>("MailUser_gid" ) );
		}
		if (v.get_indicator("MailUser_maildir") != i_null){
			p.setMaildir( v.template get<std::string>("MailUser_maildir" ) );
		}
		if (v.get_indicator("MailUser_quota") != i_null){
			p.setQuota( v.template get<long long>("MailUser_quota" ) );
		}
		if (v.get_indicator("MailUser_cc") != i_null){
			p.setCc( v.template get<std::string>("MailUser_cc" ) );
		}
		if (v.get_indicator("MailUser_homedir") != i_null){
			p.setHomedir( v.template get<std::string>("MailUser_homedir" ) );
		}
		if (v.get_indicator("MailUser_autoresponder") != i_null){
			p.setAutoresponder( v.template get<std::string>("MailUser_autoresponder" ) );
		}
		if (v.get_indicator("MailUser_autoresponder_start_date") != i_null){
			p.setAutoresponderStartDate( v.template get<tm>("MailUser_autoresponder_start_date" ) );
		}
		if (v.get_indicator("MailUser_autoresponder_end_date") != i_null){
			p.setAutoresponderEndDate( v.template get<tm>("MailUser_autoresponder_end_date" ) );
		}
		if (v.get_indicator("MailUser_autoresponder_subject") != i_null){
			p.setAutoresponderSubject( v.template get<std::string>("MailUser_autoresponder_subject" ) );
		}
		if (v.get_indicator("MailUser_autoresponder_text") != i_null){
			p.setAutoresponderText( v.template get<std::string>("MailUser_autoresponder_text" ) );
		}
		if (v.get_indicator("MailUser_move_junk") != i_null){
			p.setMoveJunk( v.template get<std::string>("MailUser_move_junk" ) );
		}
		if (v.get_indicator("MailUser_custom_mailfilter") != i_null){
			p.setCustomMailfilter( v.template get<std::string>("MailUser_custom_mailfilter" ) );
		}
		if (v.get_indicator("MailUser_postfix") != i_null){
			p.setPostfix( v.template get<std::string>("MailUser_postfix" ) );
		}
		if (v.get_indicator("MailUser_access") != i_null){
			p.setAccess( v.template get<std::string>("MailUser_access" ) );
		}
		if (v.get_indicator("MailUser_disableimap") != i_null){
			p.setDisableimap( v.template get<std::string>("MailUser_disableimap" ) );
		}
		if (v.get_indicator("MailUser_disablepop3") != i_null){
			p.setDisablepop3( v.template get<std::string>("MailUser_disablepop3" ) );
		}
		if (v.get_indicator("MailUser_disabledeliver") != i_null){
			p.setDisabledeliver( v.template get<std::string>("MailUser_disabledeliver" ) );
		}
		if (v.get_indicator("MailUser_disablesmtp") != i_null){
			p.setDisablesmtp( v.template get<std::string>("MailUser_disablesmtp" ) );
		}
		if (v.get_indicator("MailUser_disablesieve") != i_null){
			p.setDisablesieve( v.template get<std::string>("MailUser_disablesieve" ) );
		}
		if (v.get_indicator("MailUser_disablesieve_filter") != i_null){
			p.setDisablesieveFilter( v.template get<std::string>("MailUser_disablesieve_filter" ) );
		}
		if (v.get_indicator("MailUser_disablelda") != i_null){
			p.setDisablelda( v.template get<std::string>("MailUser_disablelda" ) );
		}
		if (v.get_indicator("MailUser_disablelmtp") != i_null){
			p.setDisablelmtp( v.template get<std::string>("MailUser_disablelmtp" ) );
		}
		if (v.get_indicator("MailUser_disabledoveadm") != i_null){
			p.setDisabledoveadm( v.template get<std::string>("MailUser_disabledoveadm" ) );
		}
		if (v.get_indicator("MailUser_last_quota_notification") != i_null){
			p.setLastQuotaNotification( v.template get<tm>("MailUser_last_quota_notification" ) );
		}
		if (v.get_indicator("MailUser_backup_interval") != i_null){
			p.setBackupInterval( v.template get<std::string>("MailUser_backup_interval" ) );
		}
		if (v.get_indicator("MailUser_backup_copies") != i_null){
			p.setBackupCopies( v.template get<int>("MailUser_backup_copies" ) );
		}
	}
	static void to_base(const MailUser & p, values & v, indicator & ind)
	{
		v.set( "MailUser_mailuser_id", p.getMailuserId() );
		v.set( "MailUser_sys_userid", p.getSysUserid() );
		v.set( "MailUser_sys_groupid", p.getSysGroupid() );
		v.set( "MailUser_sys_perm_user", p.getSysPermUser() );
		v.set( "MailUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailUser_sys_perm_other", p.getSysPermOther() );
		v.set( "MailUser_server_id", p.getServerId() );
		v.set( "MailUser_email", p.getEmail() );
		v.set( "MailUser_login", p.getLogin() );
		v.set( "MailUser_password", p.getPassword() );
		v.set( "MailUser_name", p.getName() );
		v.set( "MailUser_uid", p.getUid() );
		v.set( "MailUser_gid", p.getGid() );
		v.set( "MailUser_maildir", p.getMaildir() );
		v.set( "MailUser_quota", p.getQuota() );
		v.set( "MailUser_cc", p.getCc() );
		v.set( "MailUser_homedir", p.getHomedir() );
		v.set( "MailUser_autoresponder", p.getAutoresponder() );
		v.set( "MailUser_autoresponder_start_date", p.getAutoresponderStartDate() );
		v.set( "MailUser_autoresponder_end_date", p.getAutoresponderEndDate() );
		v.set( "MailUser_autoresponder_subject", p.getAutoresponderSubject() );
		v.set( "MailUser_autoresponder_text", p.getAutoresponderText() );
		v.set( "MailUser_move_junk", p.getMoveJunk() );
		v.set( "MailUser_custom_mailfilter", p.getCustomMailfilter() );
		v.set( "MailUser_postfix", p.getPostfix() );
		v.set( "MailUser_access", p.getAccess() );
		v.set( "MailUser_disableimap", p.getDisableimap() );
		v.set( "MailUser_disablepop3", p.getDisablepop3() );
		v.set( "MailUser_disabledeliver", p.getDisabledeliver() );
		v.set( "MailUser_disablesmtp", p.getDisablesmtp() );
		v.set( "MailUser_disablesieve", p.getDisablesieve() );
		v.set( "MailUser_disablesieve_filter", p.getDisablesieveFilter() );
		v.set( "MailUser_disablelda", p.getDisablelda() );
		v.set( "MailUser_disablelmtp", p.getDisablelmtp() );
		v.set( "MailUser_disabledoveadm", p.getDisabledoveadm() );
		v.set( "MailUser_last_quota_notification", p.getLastQuotaNotification() );
		v.set( "MailUser_backup_interval", p.getBackupInterval() );
		v.set( "MailUser_backup_copies", p.getBackupCopies() );
		ind = i_ok;
	}
};
}

#endif // MAILUSERREPOSITORY_H
