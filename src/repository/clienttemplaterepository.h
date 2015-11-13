#ifndef CLIENTTEMPLATEREPOSITORY_H
#define CLIENTTEMPLATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/clienttemplate.h"
using namespace soci;


class ClientTemplateRepository
{
	soci::session& dataBase;
public:
	ClientTemplateRepository(soci::session& dataBase);
	int insert(const ClientTemplate& clienttemplate);
	ClientTemplatePtr select(const ClientTemplate& clienttemplate);
	ClientTemplateList select(const string& where="");
	void update(const ClientTemplate& clienttemplate);
	void update(const ClientTemplate& oldObj, const ClientTemplate& newObj);
	void remove(const ClientTemplate& clienttemplate);
};

namespace soci
{
template<>
struct type_conversion<ClientTemplate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ClientTemplate & p)
	{
		if (v.get_indicator("ClientTemplate_template_id") != i_null){
			p.setTemplateId( v.template get<long long>("ClientTemplate_template_id" ) );
		}
		if (v.get_indicator("ClientTemplate_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("ClientTemplate_sys_userid" ) );
		}
		if (v.get_indicator("ClientTemplate_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("ClientTemplate_sys_groupid" ) );
		}
		if (v.get_indicator("ClientTemplate_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ClientTemplate_sys_perm_user" ) );
		}
		if (v.get_indicator("ClientTemplate_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ClientTemplate_sys_perm_group" ) );
		}
		if (v.get_indicator("ClientTemplate_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ClientTemplate_sys_perm_other" ) );
		}
		if (v.get_indicator("ClientTemplate_template_name") != i_null){
			p.setTemplateName( v.template get<std::string>("ClientTemplate_template_name" ) );
		}
		if (v.get_indicator("ClientTemplate_template_type") != i_null){
			p.setTemplateType( v.template get<std::string>("ClientTemplate_template_type" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_maildomain") != i_null){
			p.setLimitMaildomain( v.template get<int>("ClientTemplate_limit_maildomain" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailbox") != i_null){
			p.setLimitMailbox( v.template get<int>("ClientTemplate_limit_mailbox" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailalias") != i_null){
			p.setLimitMailalias( v.template get<int>("ClientTemplate_limit_mailalias" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailaliasdomain") != i_null){
			p.setLimitMailaliasdomain( v.template get<int>("ClientTemplate_limit_mailaliasdomain" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailforward") != i_null){
			p.setLimitMailforward( v.template get<int>("ClientTemplate_limit_mailforward" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailcatchall") != i_null){
			p.setLimitMailcatchall( v.template get<int>("ClientTemplate_limit_mailcatchall" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailrouting") != i_null){
			p.setLimitMailrouting( v.template get<int>("ClientTemplate_limit_mailrouting" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailfilter") != i_null){
			p.setLimitMailfilter( v.template get<int>("ClientTemplate_limit_mailfilter" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_fetchmail") != i_null){
			p.setLimitFetchmail( v.template get<int>("ClientTemplate_limit_fetchmail" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailquota") != i_null){
			p.setLimitMailquota( v.template get<int>("ClientTemplate_limit_mailquota" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_spamfilter_wblist") != i_null){
			p.setLimitSpamfilterWblist( v.template get<int>("ClientTemplate_limit_spamfilter_wblist" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_spamfilter_user") != i_null){
			p.setLimitSpamfilterUser( v.template get<int>("ClientTemplate_limit_spamfilter_user" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_spamfilter_policy") != i_null){
			p.setLimitSpamfilterPolicy( v.template get<int>("ClientTemplate_limit_spamfilter_policy" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_web_ip") != i_null){
			p.setLimitWebIp( v.template get<std::string>("ClientTemplate_limit_web_ip" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_web_domain") != i_null){
			p.setLimitWebDomain( v.template get<int>("ClientTemplate_limit_web_domain" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_web_quota") != i_null){
			p.setLimitWebQuota( v.template get<int>("ClientTemplate_limit_web_quota" ) );
		}
		if (v.get_indicator("ClientTemplate_web_php_options") != i_null){
			p.setWebPhpOptions( v.template get<std::string>("ClientTemplate_web_php_options" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_cgi") != i_null){
			p.setLimitCgi( v.template get<std::string>("ClientTemplate_limit_cgi" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_ssi") != i_null){
			p.setLimitSsi( v.template get<std::string>("ClientTemplate_limit_ssi" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_perl") != i_null){
			p.setLimitPerl( v.template get<std::string>("ClientTemplate_limit_perl" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_ruby") != i_null){
			p.setLimitRuby( v.template get<std::string>("ClientTemplate_limit_ruby" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_python") != i_null){
			p.setLimitPython( v.template get<std::string>("ClientTemplate_limit_python" ) );
		}
		if (v.get_indicator("ClientTemplate_force_suexec") != i_null){
			p.setForceSuexec( v.template get<std::string>("ClientTemplate_force_suexec" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_hterror") != i_null){
			p.setLimitHterror( v.template get<std::string>("ClientTemplate_limit_hterror" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_wildcard") != i_null){
			p.setLimitWildcard( v.template get<std::string>("ClientTemplate_limit_wildcard" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_ssl") != i_null){
			p.setLimitSsl( v.template get<std::string>("ClientTemplate_limit_ssl" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_web_subdomain") != i_null){
			p.setLimitWebSubdomain( v.template get<int>("ClientTemplate_limit_web_subdomain" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_web_aliasdomain") != i_null){
			p.setLimitWebAliasdomain( v.template get<int>("ClientTemplate_limit_web_aliasdomain" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_ftp_user") != i_null){
			p.setLimitFtpUser( v.template get<int>("ClientTemplate_limit_ftp_user" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_shell_user") != i_null){
			p.setLimitShellUser( v.template get<int>("ClientTemplate_limit_shell_user" ) );
		}
		if (v.get_indicator("ClientTemplate_ssh_chroot") != i_null){
			p.setSshChroot( v.template get<std::string>("ClientTemplate_ssh_chroot" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_webdav_user") != i_null){
			p.setLimitWebdavUser( v.template get<int>("ClientTemplate_limit_webdav_user" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_backup") != i_null){
			p.setLimitBackup( v.template get<std::string>("ClientTemplate_limit_backup" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_aps") != i_null){
			p.setLimitAps( v.template get<int>("ClientTemplate_limit_aps" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_dns_zone") != i_null){
			p.setLimitDnsZone( v.template get<int>("ClientTemplate_limit_dns_zone" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_dns_slave_zone") != i_null){
			p.setLimitDnsSlaveZone( v.template get<int>("ClientTemplate_limit_dns_slave_zone" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_dns_record") != i_null){
			p.setLimitDnsRecord( v.template get<int>("ClientTemplate_limit_dns_record" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_database") != i_null){
			p.setLimitDatabase( v.template get<int>("ClientTemplate_limit_database" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_database_quota") != i_null){
			p.setLimitDatabaseQuota( v.template get<int>("ClientTemplate_limit_database_quota" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_cron") != i_null){
			p.setLimitCron( v.template get<int>("ClientTemplate_limit_cron" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_cron_type") != i_null){
			p.setLimitCronType( v.template get<std::string>("ClientTemplate_limit_cron_type" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_cron_frequency") != i_null){
			p.setLimitCronFrequency( v.template get<int>("ClientTemplate_limit_cron_frequency" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_traffic_quota") != i_null){
			p.setLimitTrafficQuota( v.template get<int>("ClientTemplate_limit_traffic_quota" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_client") != i_null){
			p.setLimitClient( v.template get<int>("ClientTemplate_limit_client" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_domainmodule") != i_null){
			p.setLimitDomainmodule( v.template get<int>("ClientTemplate_limit_domainmodule" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_mailmailinglist") != i_null){
			p.setLimitMailmailinglist( v.template get<int>("ClientTemplate_limit_mailmailinglist" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_openvz_vm") != i_null){
			p.setLimitOpenvzVm( v.template get<int>("ClientTemplate_limit_openvz_vm" ) );
		}
		if (v.get_indicator("ClientTemplate_limit_openvz_vm_template_id") != i_null){
			p.setLimitOpenvzVmTemplateId( v.template get<int>("ClientTemplate_limit_openvz_vm_template_id" ) );
		}
	}
	static void to_base(const ClientTemplate & p, values & v, indicator & ind)
	{
		v.set( "ClientTemplate_template_id", p.getTemplateId() );
		v.set( "ClientTemplate_sys_userid", p.getSysUserid() );
		v.set( "ClientTemplate_sys_groupid", p.getSysGroupid() );
		v.set( "ClientTemplate_sys_perm_user", p.getSysPermUser() );
		v.set( "ClientTemplate_sys_perm_group", p.getSysPermGroup() );
		v.set( "ClientTemplate_sys_perm_other", p.getSysPermOther() );
		v.set( "ClientTemplate_template_name", p.getTemplateName() );
		v.set( "ClientTemplate_template_type", p.getTemplateType() );
		v.set( "ClientTemplate_limit_maildomain", p.getLimitMaildomain() );
		v.set( "ClientTemplate_limit_mailbox", p.getLimitMailbox() );
		v.set( "ClientTemplate_limit_mailalias", p.getLimitMailalias() );
		v.set( "ClientTemplate_limit_mailaliasdomain", p.getLimitMailaliasdomain() );
		v.set( "ClientTemplate_limit_mailforward", p.getLimitMailforward() );
		v.set( "ClientTemplate_limit_mailcatchall", p.getLimitMailcatchall() );
		v.set( "ClientTemplate_limit_mailrouting", p.getLimitMailrouting() );
		v.set( "ClientTemplate_limit_mailfilter", p.getLimitMailfilter() );
		v.set( "ClientTemplate_limit_fetchmail", p.getLimitFetchmail() );
		v.set( "ClientTemplate_limit_mailquota", p.getLimitMailquota() );
		v.set( "ClientTemplate_limit_spamfilter_wblist", p.getLimitSpamfilterWblist() );
		v.set( "ClientTemplate_limit_spamfilter_user", p.getLimitSpamfilterUser() );
		v.set( "ClientTemplate_limit_spamfilter_policy", p.getLimitSpamfilterPolicy() );
		v.set( "ClientTemplate_limit_web_ip", p.getLimitWebIp() );
		v.set( "ClientTemplate_limit_web_domain", p.getLimitWebDomain() );
		v.set( "ClientTemplate_limit_web_quota", p.getLimitWebQuota() );
		v.set( "ClientTemplate_web_php_options", p.getWebPhpOptions() );
		v.set( "ClientTemplate_limit_cgi", p.getLimitCgi() );
		v.set( "ClientTemplate_limit_ssi", p.getLimitSsi() );
		v.set( "ClientTemplate_limit_perl", p.getLimitPerl() );
		v.set( "ClientTemplate_limit_ruby", p.getLimitRuby() );
		v.set( "ClientTemplate_limit_python", p.getLimitPython() );
		v.set( "ClientTemplate_force_suexec", p.getForceSuexec() );
		v.set( "ClientTemplate_limit_hterror", p.getLimitHterror() );
		v.set( "ClientTemplate_limit_wildcard", p.getLimitWildcard() );
		v.set( "ClientTemplate_limit_ssl", p.getLimitSsl() );
		v.set( "ClientTemplate_limit_web_subdomain", p.getLimitWebSubdomain() );
		v.set( "ClientTemplate_limit_web_aliasdomain", p.getLimitWebAliasdomain() );
		v.set( "ClientTemplate_limit_ftp_user", p.getLimitFtpUser() );
		v.set( "ClientTemplate_limit_shell_user", p.getLimitShellUser() );
		v.set( "ClientTemplate_ssh_chroot", p.getSshChroot() );
		v.set( "ClientTemplate_limit_webdav_user", p.getLimitWebdavUser() );
		v.set( "ClientTemplate_limit_backup", p.getLimitBackup() );
		v.set( "ClientTemplate_limit_aps", p.getLimitAps() );
		v.set( "ClientTemplate_limit_dns_zone", p.getLimitDnsZone() );
		v.set( "ClientTemplate_limit_dns_slave_zone", p.getLimitDnsSlaveZone() );
		v.set( "ClientTemplate_limit_dns_record", p.getLimitDnsRecord() );
		v.set( "ClientTemplate_limit_database", p.getLimitDatabase() );
		v.set( "ClientTemplate_limit_database_quota", p.getLimitDatabaseQuota() );
		v.set( "ClientTemplate_limit_cron", p.getLimitCron() );
		v.set( "ClientTemplate_limit_cron_type", p.getLimitCronType() );
		v.set( "ClientTemplate_limit_cron_frequency", p.getLimitCronFrequency() );
		v.set( "ClientTemplate_limit_traffic_quota", p.getLimitTrafficQuota() );
		v.set( "ClientTemplate_limit_client", p.getLimitClient() );
		v.set( "ClientTemplate_limit_domainmodule", p.getLimitDomainmodule() );
		v.set( "ClientTemplate_limit_mailmailinglist", p.getLimitMailmailinglist() );
		v.set( "ClientTemplate_limit_openvz_vm", p.getLimitOpenvzVm() );
		v.set( "ClientTemplate_limit_openvz_vm_template_id", p.getLimitOpenvzVmTemplateId() );
		ind = i_ok;
	}
};
}

#endif // CLIENTTEMPLATEREPOSITORY_H
