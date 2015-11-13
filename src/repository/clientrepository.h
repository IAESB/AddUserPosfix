#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/client.h"
using namespace soci;


class ClientRepository
{
	soci::session& dataBase;
public:
	ClientRepository(soci::session& dataBase);
	int insert(const Client& client);
	ClientPtr select(const Client& client);
	ClientList select(const string& where="");
	void update(const Client& client);
	void update(const Client& oldObj, const Client& newObj);
	void remove(const Client& client);
};

namespace soci
{
template<>
struct type_conversion<Client>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Client & p)
	{
		if (v.get_indicator("Client_client_id") != i_null){
			p.setClientId( v.template get<long long>("Client_client_id" ) );
		}
		if (v.get_indicator("Client_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("Client_sys_userid" ) );
		}
		if (v.get_indicator("Client_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("Client_sys_groupid" ) );
		}
		if (v.get_indicator("Client_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("Client_sys_perm_user" ) );
		}
		if (v.get_indicator("Client_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("Client_sys_perm_group" ) );
		}
		if (v.get_indicator("Client_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("Client_sys_perm_other" ) );
		}
		if (v.get_indicator("Client_company_name") != i_null){
			p.setCompanyName( v.template get<std::string>("Client_company_name" ) );
		}
		if (v.get_indicator("Client_company_id") != i_null){
			p.setCompanyId( v.template get<std::string>("Client_company_id" ) );
		}
		if (v.get_indicator("Client_gender") != i_null){
			p.setGender( v.template get<std::string>("Client_gender" ) );
		}
		if (v.get_indicator("Client_contact_name") != i_null){
			p.setContactName( v.template get<std::string>("Client_contact_name" ) );
		}
		if (v.get_indicator("Client_customer_no") != i_null){
			p.setCustomerNo( v.template get<std::string>("Client_customer_no" ) );
		}
		if (v.get_indicator("Client_vat_id") != i_null){
			p.setVatId( v.template get<std::string>("Client_vat_id" ) );
		}
		if (v.get_indicator("Client_street") != i_null){
			p.setStreet( v.template get<std::string>("Client_street" ) );
		}
		if (v.get_indicator("Client_zip") != i_null){
			p.setZip( v.template get<std::string>("Client_zip" ) );
		}
		if (v.get_indicator("Client_city") != i_null){
			p.setCity( v.template get<std::string>("Client_city" ) );
		}
		if (v.get_indicator("Client_state") != i_null){
			p.setState( v.template get<std::string>("Client_state" ) );
		}
		if (v.get_indicator("Client_country") != i_null){
			p.setCountry( v.template get<std::string>("Client_country" ) );
		}
		if (v.get_indicator("Client_telephone") != i_null){
			p.setTelephone( v.template get<std::string>("Client_telephone" ) );
		}
		if (v.get_indicator("Client_mobile") != i_null){
			p.setMobile( v.template get<std::string>("Client_mobile" ) );
		}
		if (v.get_indicator("Client_fax") != i_null){
			p.setFax( v.template get<std::string>("Client_fax" ) );
		}
		if (v.get_indicator("Client_email") != i_null){
			p.setEmail( v.template get<std::string>("Client_email" ) );
		}
		if (v.get_indicator("Client_internet") != i_null){
			p.setInternet( v.template get<std::string>("Client_internet" ) );
		}
		if (v.get_indicator("Client_icq") != i_null){
			p.setIcq( v.template get<std::string>("Client_icq" ) );
		}
		if (v.get_indicator("Client_notes") != i_null){
			p.setNotes( v.template get<std::string>("Client_notes" ) );
		}
		if (v.get_indicator("Client_bank_account_owner") != i_null){
			p.setBankAccountOwner( v.template get<std::string>("Client_bank_account_owner" ) );
		}
		if (v.get_indicator("Client_bank_account_number") != i_null){
			p.setBankAccountNumber( v.template get<std::string>("Client_bank_account_number" ) );
		}
		if (v.get_indicator("Client_bank_code") != i_null){
			p.setBankCode( v.template get<std::string>("Client_bank_code" ) );
		}
		if (v.get_indicator("Client_bank_name") != i_null){
			p.setBankName( v.template get<std::string>("Client_bank_name" ) );
		}
		if (v.get_indicator("Client_bank_account_iban") != i_null){
			p.setBankAccountIban( v.template get<std::string>("Client_bank_account_iban" ) );
		}
		if (v.get_indicator("Client_bank_account_swift") != i_null){
			p.setBankAccountSwift( v.template get<std::string>("Client_bank_account_swift" ) );
		}
		if (v.get_indicator("Client_paypal_email") != i_null){
			p.setPaypalEmail( v.template get<std::string>("Client_paypal_email" ) );
		}
		if (v.get_indicator("Client_default_mailserver") != i_null){
			p.setDefaultMailserver( v.template get<long long>("Client_default_mailserver" ) );
		}
		if (v.get_indicator("Client_mail_servers") != i_null){
			p.setMailServers( v.template get<std::string>("Client_mail_servers" ) );
		}
		if (v.get_indicator("Client_limit_maildomain") != i_null){
			p.setLimitMaildomain( v.template get<int>("Client_limit_maildomain" ) );
		}
		if (v.get_indicator("Client_limit_mailbox") != i_null){
			p.setLimitMailbox( v.template get<int>("Client_limit_mailbox" ) );
		}
		if (v.get_indicator("Client_limit_mailalias") != i_null){
			p.setLimitMailalias( v.template get<int>("Client_limit_mailalias" ) );
		}
		if (v.get_indicator("Client_limit_mailaliasdomain") != i_null){
			p.setLimitMailaliasdomain( v.template get<int>("Client_limit_mailaliasdomain" ) );
		}
		if (v.get_indicator("Client_limit_mailforward") != i_null){
			p.setLimitMailforward( v.template get<int>("Client_limit_mailforward" ) );
		}
		if (v.get_indicator("Client_limit_mailcatchall") != i_null){
			p.setLimitMailcatchall( v.template get<int>("Client_limit_mailcatchall" ) );
		}
		if (v.get_indicator("Client_limit_mailrouting") != i_null){
			p.setLimitMailrouting( v.template get<int>("Client_limit_mailrouting" ) );
		}
		if (v.get_indicator("Client_limit_mailfilter") != i_null){
			p.setLimitMailfilter( v.template get<int>("Client_limit_mailfilter" ) );
		}
		if (v.get_indicator("Client_limit_fetchmail") != i_null){
			p.setLimitFetchmail( v.template get<int>("Client_limit_fetchmail" ) );
		}
		if (v.get_indicator("Client_limit_mailquota") != i_null){
			p.setLimitMailquota( v.template get<int>("Client_limit_mailquota" ) );
		}
		if (v.get_indicator("Client_limit_spamfilter_wblist") != i_null){
			p.setLimitSpamfilterWblist( v.template get<int>("Client_limit_spamfilter_wblist" ) );
		}
		if (v.get_indicator("Client_limit_spamfilter_user") != i_null){
			p.setLimitSpamfilterUser( v.template get<int>("Client_limit_spamfilter_user" ) );
		}
		if (v.get_indicator("Client_limit_spamfilter_policy") != i_null){
			p.setLimitSpamfilterPolicy( v.template get<int>("Client_limit_spamfilter_policy" ) );
		}
		if (v.get_indicator("Client_default_webserver") != i_null){
			p.setDefaultWebserver( v.template get<long long>("Client_default_webserver" ) );
		}
		if (v.get_indicator("Client_web_servers") != i_null){
			p.setWebServers( v.template get<std::string>("Client_web_servers" ) );
		}
		if (v.get_indicator("Client_limit_web_ip") != i_null){
			p.setLimitWebIp( v.template get<std::string>("Client_limit_web_ip" ) );
		}
		if (v.get_indicator("Client_limit_web_domain") != i_null){
			p.setLimitWebDomain( v.template get<int>("Client_limit_web_domain" ) );
		}
		if (v.get_indicator("Client_limit_web_quota") != i_null){
			p.setLimitWebQuota( v.template get<int>("Client_limit_web_quota" ) );
		}
		if (v.get_indicator("Client_web_php_options") != i_null){
			p.setWebPhpOptions( v.template get<std::string>("Client_web_php_options" ) );
		}
		if (v.get_indicator("Client_limit_cgi") != i_null){
			p.setLimitCgi( v.template get<std::string>("Client_limit_cgi" ) );
		}
		if (v.get_indicator("Client_limit_ssi") != i_null){
			p.setLimitSsi( v.template get<std::string>("Client_limit_ssi" ) );
		}
		if (v.get_indicator("Client_limit_perl") != i_null){
			p.setLimitPerl( v.template get<std::string>("Client_limit_perl" ) );
		}
		if (v.get_indicator("Client_limit_ruby") != i_null){
			p.setLimitRuby( v.template get<std::string>("Client_limit_ruby" ) );
		}
		if (v.get_indicator("Client_limit_python") != i_null){
			p.setLimitPython( v.template get<std::string>("Client_limit_python" ) );
		}
		if (v.get_indicator("Client_force_suexec") != i_null){
			p.setForceSuexec( v.template get<std::string>("Client_force_suexec" ) );
		}
		if (v.get_indicator("Client_limit_hterror") != i_null){
			p.setLimitHterror( v.template get<std::string>("Client_limit_hterror" ) );
		}
		if (v.get_indicator("Client_limit_wildcard") != i_null){
			p.setLimitWildcard( v.template get<std::string>("Client_limit_wildcard" ) );
		}
		if (v.get_indicator("Client_limit_ssl") != i_null){
			p.setLimitSsl( v.template get<std::string>("Client_limit_ssl" ) );
		}
		if (v.get_indicator("Client_limit_web_subdomain") != i_null){
			p.setLimitWebSubdomain( v.template get<int>("Client_limit_web_subdomain" ) );
		}
		if (v.get_indicator("Client_limit_web_aliasdomain") != i_null){
			p.setLimitWebAliasdomain( v.template get<int>("Client_limit_web_aliasdomain" ) );
		}
		if (v.get_indicator("Client_limit_ftp_user") != i_null){
			p.setLimitFtpUser( v.template get<int>("Client_limit_ftp_user" ) );
		}
		if (v.get_indicator("Client_limit_shell_user") != i_null){
			p.setLimitShellUser( v.template get<int>("Client_limit_shell_user" ) );
		}
		if (v.get_indicator("Client_ssh_chroot") != i_null){
			p.setSshChroot( v.template get<std::string>("Client_ssh_chroot" ) );
		}
		if (v.get_indicator("Client_limit_webdav_user") != i_null){
			p.setLimitWebdavUser( v.template get<int>("Client_limit_webdav_user" ) );
		}
		if (v.get_indicator("Client_limit_backup") != i_null){
			p.setLimitBackup( v.template get<std::string>("Client_limit_backup" ) );
		}
		if (v.get_indicator("Client_limit_aps") != i_null){
			p.setLimitAps( v.template get<int>("Client_limit_aps" ) );
		}
		if (v.get_indicator("Client_default_dnsserver") != i_null){
			p.setDefaultDnsserver( v.template get<long long>("Client_default_dnsserver" ) );
		}
		if (v.get_indicator("Client_db_servers") != i_null){
			p.setDbServers( v.template get<std::string>("Client_db_servers" ) );
		}
		if (v.get_indicator("Client_limit_dns_zone") != i_null){
			p.setLimitDnsZone( v.template get<int>("Client_limit_dns_zone" ) );
		}
		if (v.get_indicator("Client_default_slave_dnsserver") != i_null){
			p.setDefaultSlaveDnsserver( v.template get<long long>("Client_default_slave_dnsserver" ) );
		}
		if (v.get_indicator("Client_limit_dns_slave_zone") != i_null){
			p.setLimitDnsSlaveZone( v.template get<int>("Client_limit_dns_slave_zone" ) );
		}
		if (v.get_indicator("Client_limit_dns_record") != i_null){
			p.setLimitDnsRecord( v.template get<int>("Client_limit_dns_record" ) );
		}
		if (v.get_indicator("Client_default_dbserver") != i_null){
			p.setDefaultDbserver( v.template get<int>("Client_default_dbserver" ) );
		}
		if (v.get_indicator("Client_dns_servers") != i_null){
			p.setDnsServers( v.template get<std::string>("Client_dns_servers" ) );
		}
		if (v.get_indicator("Client_limit_database") != i_null){
			p.setLimitDatabase( v.template get<int>("Client_limit_database" ) );
		}
		if (v.get_indicator("Client_limit_database_quota") != i_null){
			p.setLimitDatabaseQuota( v.template get<int>("Client_limit_database_quota" ) );
		}
		if (v.get_indicator("Client_limit_cron") != i_null){
			p.setLimitCron( v.template get<int>("Client_limit_cron" ) );
		}
		if (v.get_indicator("Client_limit_cron_type") != i_null){
			p.setLimitCronType( v.template get<std::string>("Client_limit_cron_type" ) );
		}
		if (v.get_indicator("Client_limit_cron_frequency") != i_null){
			p.setLimitCronFrequency( v.template get<int>("Client_limit_cron_frequency" ) );
		}
		if (v.get_indicator("Client_limit_traffic_quota") != i_null){
			p.setLimitTrafficQuota( v.template get<int>("Client_limit_traffic_quota" ) );
		}
		if (v.get_indicator("Client_limit_client") != i_null){
			p.setLimitClient( v.template get<int>("Client_limit_client" ) );
		}
		if (v.get_indicator("Client_limit_domainmodule") != i_null){
			p.setLimitDomainmodule( v.template get<int>("Client_limit_domainmodule" ) );
		}
		if (v.get_indicator("Client_limit_mailmailinglist") != i_null){
			p.setLimitMailmailinglist( v.template get<int>("Client_limit_mailmailinglist" ) );
		}
		if (v.get_indicator("Client_limit_openvz_vm") != i_null){
			p.setLimitOpenvzVm( v.template get<int>("Client_limit_openvz_vm" ) );
		}
		if (v.get_indicator("Client_limit_openvz_vm_template_id") != i_null){
			p.setLimitOpenvzVmTemplateId( v.template get<int>("Client_limit_openvz_vm_template_id" ) );
		}
		if (v.get_indicator("Client_parent_client_id") != i_null){
			p.setParentClientId( v.template get<long long>("Client_parent_client_id" ) );
		}
		if (v.get_indicator("Client_username") != i_null){
			p.setUsername( v.template get<std::string>("Client_username" ) );
		}
		if (v.get_indicator("Client_password") != i_null){
			p.setPassword( v.template get<std::string>("Client_password" ) );
		}
		if (v.get_indicator("Client_language") != i_null){
			p.setLanguage( v.template get<std::string>("Client_language" ) );
		}
		if (v.get_indicator("Client_usertheme") != i_null){
			p.setUsertheme( v.template get<std::string>("Client_usertheme" ) );
		}
		if (v.get_indicator("Client_template_master") != i_null){
			p.setTemplateMaster( v.template get<long long>("Client_template_master" ) );
		}
		if (v.get_indicator("Client_template_additional") != i_null){
			p.setTemplateAdditional( v.template get<std::string>("Client_template_additional" ) );
		}
		if (v.get_indicator("Client_created_at") != i_null){
			p.setCreatedAt( v.template get<long long>("Client_created_at" ) );
		}
		if (v.get_indicator("Client_locked") != i_null){
			p.setLocked( v.template get<std::string>("Client_locked" ) );
		}
		if (v.get_indicator("Client_canceled") != i_null){
			p.setCanceled( v.template get<std::string>("Client_canceled" ) );
		}
		if (v.get_indicator("Client_can_use_api") != i_null){
			p.setCanUseApi( v.template get<std::string>("Client_can_use_api" ) );
		}
		if (v.get_indicator("Client_tmp_data") != i_null){
			p.setTmpData( v.template get<std::string>("Client_tmp_data" ) );
		}
		if (v.get_indicator("Client_id_rsa") != i_null){
			p.setIdRsa( v.template get<std::string>("Client_id_rsa" ) );
		}
		if (v.get_indicator("Client_ssh_rsa") != i_null){
			p.setSshRsa( v.template get<std::string>("Client_ssh_rsa" ) );
		}
		if (v.get_indicator("Client_customer_no_template") != i_null){
			p.setCustomerNoTemplate( v.template get<std::string>("Client_customer_no_template" ) );
		}
		if (v.get_indicator("Client_customer_no_start") != i_null){
			p.setCustomerNoStart( v.template get<int>("Client_customer_no_start" ) );
		}
		if (v.get_indicator("Client_customer_no_counter") != i_null){
			p.setCustomerNoCounter( v.template get<int>("Client_customer_no_counter" ) );
		}
		if (v.get_indicator("Client_added_date") != i_null){
			p.setAddedDate( v.template get<tm>("Client_added_date" ) );
		}
		if (v.get_indicator("Client_added_by") != i_null){
			p.setAddedBy( v.template get<std::string>("Client_added_by" ) );
		}
	}
	static void to_base(const Client & p, values & v, indicator & ind)
	{
		v.set( "Client_client_id", p.getClientId() );
		v.set( "Client_sys_userid", p.getSysUserid() );
		v.set( "Client_sys_groupid", p.getSysGroupid() );
		v.set( "Client_sys_perm_user", p.getSysPermUser() );
		v.set( "Client_sys_perm_group", p.getSysPermGroup() );
		v.set( "Client_sys_perm_other", p.getSysPermOther() );
		v.set( "Client_company_name", p.getCompanyName() );
		v.set( "Client_company_id", p.getCompanyId() );
		v.set( "Client_gender", p.getGender() );
		v.set( "Client_contact_name", p.getContactName() );
		v.set( "Client_customer_no", p.getCustomerNo() );
		v.set( "Client_vat_id", p.getVatId() );
		v.set( "Client_street", p.getStreet() );
		v.set( "Client_zip", p.getZip() );
		v.set( "Client_city", p.getCity() );
		v.set( "Client_state", p.getState() );
		v.set( "Client_country", p.getCountry() );
		v.set( "Client_telephone", p.getTelephone() );
		v.set( "Client_mobile", p.getMobile() );
		v.set( "Client_fax", p.getFax() );
		v.set( "Client_email", p.getEmail() );
		v.set( "Client_internet", p.getInternet() );
		v.set( "Client_icq", p.getIcq() );
		v.set( "Client_notes", p.getNotes() );
		v.set( "Client_bank_account_owner", p.getBankAccountOwner() );
		v.set( "Client_bank_account_number", p.getBankAccountNumber() );
		v.set( "Client_bank_code", p.getBankCode() );
		v.set( "Client_bank_name", p.getBankName() );
		v.set( "Client_bank_account_iban", p.getBankAccountIban() );
		v.set( "Client_bank_account_swift", p.getBankAccountSwift() );
		v.set( "Client_paypal_email", p.getPaypalEmail() );
		v.set( "Client_default_mailserver", p.getDefaultMailserver() );
		v.set( "Client_mail_servers", p.getMailServers() );
		v.set( "Client_limit_maildomain", p.getLimitMaildomain() );
		v.set( "Client_limit_mailbox", p.getLimitMailbox() );
		v.set( "Client_limit_mailalias", p.getLimitMailalias() );
		v.set( "Client_limit_mailaliasdomain", p.getLimitMailaliasdomain() );
		v.set( "Client_limit_mailforward", p.getLimitMailforward() );
		v.set( "Client_limit_mailcatchall", p.getLimitMailcatchall() );
		v.set( "Client_limit_mailrouting", p.getLimitMailrouting() );
		v.set( "Client_limit_mailfilter", p.getLimitMailfilter() );
		v.set( "Client_limit_fetchmail", p.getLimitFetchmail() );
		v.set( "Client_limit_mailquota", p.getLimitMailquota() );
		v.set( "Client_limit_spamfilter_wblist", p.getLimitSpamfilterWblist() );
		v.set( "Client_limit_spamfilter_user", p.getLimitSpamfilterUser() );
		v.set( "Client_limit_spamfilter_policy", p.getLimitSpamfilterPolicy() );
		v.set( "Client_default_webserver", p.getDefaultWebserver() );
		v.set( "Client_web_servers", p.getWebServers() );
		v.set( "Client_limit_web_ip", p.getLimitWebIp() );
		v.set( "Client_limit_web_domain", p.getLimitWebDomain() );
		v.set( "Client_limit_web_quota", p.getLimitWebQuota() );
		v.set( "Client_web_php_options", p.getWebPhpOptions() );
		v.set( "Client_limit_cgi", p.getLimitCgi() );
		v.set( "Client_limit_ssi", p.getLimitSsi() );
		v.set( "Client_limit_perl", p.getLimitPerl() );
		v.set( "Client_limit_ruby", p.getLimitRuby() );
		v.set( "Client_limit_python", p.getLimitPython() );
		v.set( "Client_force_suexec", p.getForceSuexec() );
		v.set( "Client_limit_hterror", p.getLimitHterror() );
		v.set( "Client_limit_wildcard", p.getLimitWildcard() );
		v.set( "Client_limit_ssl", p.getLimitSsl() );
		v.set( "Client_limit_web_subdomain", p.getLimitWebSubdomain() );
		v.set( "Client_limit_web_aliasdomain", p.getLimitWebAliasdomain() );
		v.set( "Client_limit_ftp_user", p.getLimitFtpUser() );
		v.set( "Client_limit_shell_user", p.getLimitShellUser() );
		v.set( "Client_ssh_chroot", p.getSshChroot() );
		v.set( "Client_limit_webdav_user", p.getLimitWebdavUser() );
		v.set( "Client_limit_backup", p.getLimitBackup() );
		v.set( "Client_limit_aps", p.getLimitAps() );
		v.set( "Client_default_dnsserver", p.getDefaultDnsserver() );
		v.set( "Client_db_servers", p.getDbServers() );
		v.set( "Client_limit_dns_zone", p.getLimitDnsZone() );
		v.set( "Client_default_slave_dnsserver", p.getDefaultSlaveDnsserver() );
		v.set( "Client_limit_dns_slave_zone", p.getLimitDnsSlaveZone() );
		v.set( "Client_limit_dns_record", p.getLimitDnsRecord() );
		v.set( "Client_default_dbserver", p.getDefaultDbserver() );
		v.set( "Client_dns_servers", p.getDnsServers() );
		v.set( "Client_limit_database", p.getLimitDatabase() );
		v.set( "Client_limit_database_quota", p.getLimitDatabaseQuota() );
		v.set( "Client_limit_cron", p.getLimitCron() );
		v.set( "Client_limit_cron_type", p.getLimitCronType() );
		v.set( "Client_limit_cron_frequency", p.getLimitCronFrequency() );
		v.set( "Client_limit_traffic_quota", p.getLimitTrafficQuota() );
		v.set( "Client_limit_client", p.getLimitClient() );
		v.set( "Client_limit_domainmodule", p.getLimitDomainmodule() );
		v.set( "Client_limit_mailmailinglist", p.getLimitMailmailinglist() );
		v.set( "Client_limit_openvz_vm", p.getLimitOpenvzVm() );
		v.set( "Client_limit_openvz_vm_template_id", p.getLimitOpenvzVmTemplateId() );
		v.set( "Client_parent_client_id", p.getParentClientId() );
		v.set( "Client_username", p.getUsername() );
		v.set( "Client_password", p.getPassword() );
		v.set( "Client_language", p.getLanguage() );
		v.set( "Client_usertheme", p.getUsertheme() );
		v.set( "Client_template_master", p.getTemplateMaster() );
		v.set( "Client_template_additional", p.getTemplateAdditional() );
		v.set( "Client_created_at", p.getCreatedAt() );
		v.set( "Client_locked", p.getLocked() );
		v.set( "Client_canceled", p.getCanceled() );
		v.set( "Client_can_use_api", p.getCanUseApi() );
		v.set( "Client_tmp_data", p.getTmpData() );
		v.set( "Client_id_rsa", p.getIdRsa() );
		v.set( "Client_ssh_rsa", p.getSshRsa() );
		v.set( "Client_customer_no_template", p.getCustomerNoTemplate() );
		v.set( "Client_customer_no_start", p.getCustomerNoStart() );
		v.set( "Client_customer_no_counter", p.getCustomerNoCounter() );
		v.set( "Client_added_date", p.getAddedDate() );
		v.set( "Client_added_by", p.getAddedBy() );
		ind = i_ok;
	}
};
}

#endif // CLIENTREPOSITORY_H
