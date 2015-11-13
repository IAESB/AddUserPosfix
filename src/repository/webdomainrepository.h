#ifndef WEBDOMAINREPOSITORY_H
#define WEBDOMAINREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webdomain.h"
using namespace soci;


class WebDomainRepository
{
	soci::session& dataBase;
public:
	WebDomainRepository(soci::session& dataBase);
	int insert(const WebDomain& webdomain);
	WebDomainPtr select(const WebDomain& webdomain);
	WebDomainList select(const string& where="");
	void update(const WebDomain& webdomain);
	void update(const WebDomain& oldObj, const WebDomain& newObj);
	void remove(const WebDomain& webdomain);
};

namespace soci
{
template<>
struct type_conversion<WebDomain>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebDomain & p)
	{
		if (v.get_indicator("WebDomain_domain_id") != i_null){
			p.setDomainId( v.template get<long long>("WebDomain_domain_id" ) );
		}
		if (v.get_indicator("WebDomain_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("WebDomain_sys_userid" ) );
		}
		if (v.get_indicator("WebDomain_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("WebDomain_sys_groupid" ) );
		}
		if (v.get_indicator("WebDomain_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebDomain_sys_perm_user" ) );
		}
		if (v.get_indicator("WebDomain_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebDomain_sys_perm_group" ) );
		}
		if (v.get_indicator("WebDomain_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebDomain_sys_perm_other" ) );
		}
		if (v.get_indicator("WebDomain_server_id") != i_null){
			p.setServerId( v.template get<long long>("WebDomain_server_id" ) );
		}
		if (v.get_indicator("WebDomain_ip_address") != i_null){
			p.setIpAddress( v.template get<std::string>("WebDomain_ip_address" ) );
		}
		if (v.get_indicator("WebDomain_ipv6_address") != i_null){
			p.setIpv6Address( v.template get<std::string>("WebDomain_ipv6_address" ) );
		}
		if (v.get_indicator("WebDomain_domain") != i_null){
			p.setDomain( v.template get<std::string>("WebDomain_domain" ) );
		}
		if (v.get_indicator("WebDomain_type") != i_null){
			p.setType( v.template get<std::string>("WebDomain_type" ) );
		}
		if (v.get_indicator("WebDomain_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("WebDomain_parent_domain_id" ) );
		}
		if (v.get_indicator("WebDomain_vhost_type") != i_null){
			p.setVhostType( v.template get<std::string>("WebDomain_vhost_type" ) );
		}
		if (v.get_indicator("WebDomain_document_root") != i_null){
			p.setDocumentRoot( v.template get<std::string>("WebDomain_document_root" ) );
		}
		if (v.get_indicator("WebDomain_web_folder") != i_null){
			p.setWebFolder( v.template get<std::string>("WebDomain_web_folder" ) );
		}
		if (v.get_indicator("WebDomain_system_user") != i_null){
			p.setSystemUser( v.template get<std::string>("WebDomain_system_user" ) );
		}
		if (v.get_indicator("WebDomain_system_group") != i_null){
			p.setSystemGroup( v.template get<std::string>("WebDomain_system_group" ) );
		}
		if (v.get_indicator("WebDomain_hd_quota") != i_null){
			p.setHdQuota( v.template get<long long>("WebDomain_hd_quota" ) );
		}
		if (v.get_indicator("WebDomain_traffic_quota") != i_null){
			p.setTrafficQuota( v.template get<long long>("WebDomain_traffic_quota" ) );
		}
		if (v.get_indicator("WebDomain_cgi") != i_null){
			p.setCgi( v.template get<std::string>("WebDomain_cgi" ) );
		}
		if (v.get_indicator("WebDomain_ssi") != i_null){
			p.setSsi( v.template get<std::string>("WebDomain_ssi" ) );
		}
		if (v.get_indicator("WebDomain_suexec") != i_null){
			p.setSuexec( v.template get<std::string>("WebDomain_suexec" ) );
		}
		if (v.get_indicator("WebDomain_errordocs") != i_null){
			p.setErrordocs( v.template get<int>("WebDomain_errordocs" ) );
		}
		if (v.get_indicator("WebDomain_is_subdomainwww") != i_null){
			p.setIsSubdomainwww( v.template get<int>("WebDomain_is_subdomainwww" ) );
		}
		if (v.get_indicator("WebDomain_subdomain") != i_null){
			p.setSubdomain( v.template get<std::string>("WebDomain_subdomain" ) );
		}
		if (v.get_indicator("WebDomain_php") != i_null){
			p.setPhp( v.template get<std::string>("WebDomain_php" ) );
		}
		if (v.get_indicator("WebDomain_ruby") != i_null){
			p.setRuby( v.template get<std::string>("WebDomain_ruby" ) );
		}
		if (v.get_indicator("WebDomain_python") != i_null){
			p.setPython( v.template get<std::string>("WebDomain_python" ) );
		}
		if (v.get_indicator("WebDomain_perl") != i_null){
			p.setPerl( v.template get<std::string>("WebDomain_perl" ) );
		}
		if (v.get_indicator("WebDomain_redirect_type") != i_null){
			p.setRedirectType( v.template get<std::string>("WebDomain_redirect_type" ) );
		}
		if (v.get_indicator("WebDomain_redirect_path") != i_null){
			p.setRedirectPath( v.template get<std::string>("WebDomain_redirect_path" ) );
		}
		if (v.get_indicator("WebDomain_seo_redirect") != i_null){
			p.setSeoRedirect( v.template get<std::string>("WebDomain_seo_redirect" ) );
		}
		if (v.get_indicator("WebDomain_ssl") != i_null){
			p.setSsl( v.template get<std::string>("WebDomain_ssl" ) );
		}
		if (v.get_indicator("WebDomain_ssl_state") != i_null){
			p.setSslState( v.template get<std::string>("WebDomain_ssl_state" ) );
		}
		if (v.get_indicator("WebDomain_ssl_locality") != i_null){
			p.setSslLocality( v.template get<std::string>("WebDomain_ssl_locality" ) );
		}
		if (v.get_indicator("WebDomain_ssl_organisation") != i_null){
			p.setSslOrganisation( v.template get<std::string>("WebDomain_ssl_organisation" ) );
		}
		if (v.get_indicator("WebDomain_ssl_organisation_unit") != i_null){
			p.setSslOrganisationUnit( v.template get<std::string>("WebDomain_ssl_organisation_unit" ) );
		}
		if (v.get_indicator("WebDomain_ssl_country") != i_null){
			p.setSslCountry( v.template get<std::string>("WebDomain_ssl_country" ) );
		}
		if (v.get_indicator("WebDomain_ssl_domain") != i_null){
			p.setSslDomain( v.template get<std::string>("WebDomain_ssl_domain" ) );
		}
		if (v.get_indicator("WebDomain_ssl_request") != i_null){
			p.setSslRequest( v.template get<std::string>("WebDomain_ssl_request" ) );
		}
		if (v.get_indicator("WebDomain_ssl_cert") != i_null){
			p.setSslCert( v.template get<std::string>("WebDomain_ssl_cert" ) );
		}
		if (v.get_indicator("WebDomain_ssl_bundle") != i_null){
			p.setSslBundle( v.template get<std::string>("WebDomain_ssl_bundle" ) );
		}
		if (v.get_indicator("WebDomain_ssl_key") != i_null){
			p.setSslKey( v.template get<std::string>("WebDomain_ssl_key" ) );
		}
		if (v.get_indicator("WebDomain_ssl_action") != i_null){
			p.setSslAction( v.template get<std::string>("WebDomain_ssl_action" ) );
		}
		if (v.get_indicator("WebDomain_stats_password") != i_null){
			p.setStatsPassword( v.template get<std::string>("WebDomain_stats_password" ) );
		}
		if (v.get_indicator("WebDomain_stats_type") != i_null){
			p.setStatsType( v.template get<std::string>("WebDomain_stats_type" ) );
		}
		if (v.get_indicator("WebDomain_allow_override") != i_null){
			p.setAllowOverride( v.template get<std::string>("WebDomain_allow_override" ) );
		}
		if (v.get_indicator("WebDomain_apache_directives") != i_null){
			p.setApacheDirectives( v.template get<std::string>("WebDomain_apache_directives" ) );
		}
		if (v.get_indicator("WebDomain_nginx_directives") != i_null){
			p.setNginxDirectives( v.template get<std::string>("WebDomain_nginx_directives" ) );
		}
		if (v.get_indicator("WebDomain_php_fpm_use_socket") != i_null){
			p.setPhpFpmUseSocket( v.template get<std::string>("WebDomain_php_fpm_use_socket" ) );
		}
		if (v.get_indicator("WebDomain_pm") != i_null){
			p.setPm( v.template get<std::string>("WebDomain_pm" ) );
		}
		if (v.get_indicator("WebDomain_pm_max_children") != i_null){
			p.setPmMaxChildren( v.template get<int>("WebDomain_pm_max_children" ) );
		}
		if (v.get_indicator("WebDomain_pm_start_servers") != i_null){
			p.setPmStartServers( v.template get<int>("WebDomain_pm_start_servers" ) );
		}
		if (v.get_indicator("WebDomain_pm_min_spare_servers") != i_null){
			p.setPmMinSpareServers( v.template get<int>("WebDomain_pm_min_spare_servers" ) );
		}
		if (v.get_indicator("WebDomain_pm_max_spare_servers") != i_null){
			p.setPmMaxSpareServers( v.template get<int>("WebDomain_pm_max_spare_servers" ) );
		}
		if (v.get_indicator("WebDomain_pm_process_idle_timeout") != i_null){
			p.setPmProcessIdleTimeout( v.template get<int>("WebDomain_pm_process_idle_timeout" ) );
		}
		if (v.get_indicator("WebDomain_pm_max_requests") != i_null){
			p.setPmMaxRequests( v.template get<int>("WebDomain_pm_max_requests" ) );
		}
		if (v.get_indicator("WebDomain_php_open_basedir") != i_null){
			p.setPhpOpenBasedir( v.template get<std::string>("WebDomain_php_open_basedir" ) );
		}
		if (v.get_indicator("WebDomain_custom_php_ini") != i_null){
			p.setCustomPhpIni( v.template get<std::string>("WebDomain_custom_php_ini" ) );
		}
		if (v.get_indicator("WebDomain_backup_interval") != i_null){
			p.setBackupInterval( v.template get<std::string>("WebDomain_backup_interval" ) );
		}
		if (v.get_indicator("WebDomain_backup_copies") != i_null){
			p.setBackupCopies( v.template get<int>("WebDomain_backup_copies" ) );
		}
		if (v.get_indicator("WebDomain_backup_excludes") != i_null){
			p.setBackupExcludes( v.template get<std::string>("WebDomain_backup_excludes" ) );
		}
		if (v.get_indicator("WebDomain_active") != i_null){
			p.setActive( v.template get<std::string>("WebDomain_active" ) );
		}
		if (v.get_indicator("WebDomain_traffic_quota_lock") != i_null){
			p.setTrafficQuotaLock( v.template get<std::string>("WebDomain_traffic_quota_lock" ) );
		}
		if (v.get_indicator("WebDomain_fastcgi_php_version") != i_null){
			p.setFastcgiPhpVersion( v.template get<std::string>("WebDomain_fastcgi_php_version" ) );
		}
		if (v.get_indicator("WebDomain_proxy_directives") != i_null){
			p.setProxyDirectives( v.template get<std::string>("WebDomain_proxy_directives" ) );
		}
		if (v.get_indicator("WebDomain_last_quota_notification") != i_null){
			p.setLastQuotaNotification( v.template get<tm>("WebDomain_last_quota_notification" ) );
		}
		if (v.get_indicator("WebDomain_rewrite_rules") != i_null){
			p.setRewriteRules( v.template get<std::string>("WebDomain_rewrite_rules" ) );
		}
		if (v.get_indicator("WebDomain_added_date") != i_null){
			p.setAddedDate( v.template get<tm>("WebDomain_added_date" ) );
		}
		if (v.get_indicator("WebDomain_added_by") != i_null){
			p.setAddedBy( v.template get<std::string>("WebDomain_added_by" ) );
		}
	}
	static void to_base(const WebDomain & p, values & v, indicator & ind)
	{
		v.set( "WebDomain_domain_id", p.getDomainId() );
		v.set( "WebDomain_sys_userid", p.getSysUserid() );
		v.set( "WebDomain_sys_groupid", p.getSysGroupid() );
		v.set( "WebDomain_sys_perm_user", p.getSysPermUser() );
		v.set( "WebDomain_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebDomain_sys_perm_other", p.getSysPermOther() );
		v.set( "WebDomain_server_id", p.getServerId() );
		v.set( "WebDomain_ip_address", p.getIpAddress() );
		v.set( "WebDomain_ipv6_address", p.getIpv6Address() );
		v.set( "WebDomain_domain", p.getDomain() );
		v.set( "WebDomain_type", p.getType() );
		v.set( "WebDomain_parent_domain_id", p.getParentDomainId() );
		v.set( "WebDomain_vhost_type", p.getVhostType() );
		v.set( "WebDomain_document_root", p.getDocumentRoot() );
		v.set( "WebDomain_web_folder", p.getWebFolder() );
		v.set( "WebDomain_system_user", p.getSystemUser() );
		v.set( "WebDomain_system_group", p.getSystemGroup() );
		v.set( "WebDomain_hd_quota", p.getHdQuota() );
		v.set( "WebDomain_traffic_quota", p.getTrafficQuota() );
		v.set( "WebDomain_cgi", p.getCgi() );
		v.set( "WebDomain_ssi", p.getSsi() );
		v.set( "WebDomain_suexec", p.getSuexec() );
		v.set( "WebDomain_errordocs", p.getErrordocs() );
		v.set( "WebDomain_is_subdomainwww", p.getIsSubdomainwww() );
		v.set( "WebDomain_subdomain", p.getSubdomain() );
		v.set( "WebDomain_php", p.getPhp() );
		v.set( "WebDomain_ruby", p.getRuby() );
		v.set( "WebDomain_python", p.getPython() );
		v.set( "WebDomain_perl", p.getPerl() );
		v.set( "WebDomain_redirect_type", p.getRedirectType() );
		v.set( "WebDomain_redirect_path", p.getRedirectPath() );
		v.set( "WebDomain_seo_redirect", p.getSeoRedirect() );
		v.set( "WebDomain_ssl", p.getSsl() );
		v.set( "WebDomain_ssl_state", p.getSslState() );
		v.set( "WebDomain_ssl_locality", p.getSslLocality() );
		v.set( "WebDomain_ssl_organisation", p.getSslOrganisation() );
		v.set( "WebDomain_ssl_organisation_unit", p.getSslOrganisationUnit() );
		v.set( "WebDomain_ssl_country", p.getSslCountry() );
		v.set( "WebDomain_ssl_domain", p.getSslDomain() );
		v.set( "WebDomain_ssl_request", p.getSslRequest() );
		v.set( "WebDomain_ssl_cert", p.getSslCert() );
		v.set( "WebDomain_ssl_bundle", p.getSslBundle() );
		v.set( "WebDomain_ssl_key", p.getSslKey() );
		v.set( "WebDomain_ssl_action", p.getSslAction() );
		v.set( "WebDomain_stats_password", p.getStatsPassword() );
		v.set( "WebDomain_stats_type", p.getStatsType() );
		v.set( "WebDomain_allow_override", p.getAllowOverride() );
		v.set( "WebDomain_apache_directives", p.getApacheDirectives() );
		v.set( "WebDomain_nginx_directives", p.getNginxDirectives() );
		v.set( "WebDomain_php_fpm_use_socket", p.getPhpFpmUseSocket() );
		v.set( "WebDomain_pm", p.getPm() );
		v.set( "WebDomain_pm_max_children", p.getPmMaxChildren() );
		v.set( "WebDomain_pm_start_servers", p.getPmStartServers() );
		v.set( "WebDomain_pm_min_spare_servers", p.getPmMinSpareServers() );
		v.set( "WebDomain_pm_max_spare_servers", p.getPmMaxSpareServers() );
		v.set( "WebDomain_pm_process_idle_timeout", p.getPmProcessIdleTimeout() );
		v.set( "WebDomain_pm_max_requests", p.getPmMaxRequests() );
		v.set( "WebDomain_php_open_basedir", p.getPhpOpenBasedir() );
		v.set( "WebDomain_custom_php_ini", p.getCustomPhpIni() );
		v.set( "WebDomain_backup_interval", p.getBackupInterval() );
		v.set( "WebDomain_backup_copies", p.getBackupCopies() );
		v.set( "WebDomain_backup_excludes", p.getBackupExcludes() );
		v.set( "WebDomain_active", p.getActive() );
		v.set( "WebDomain_traffic_quota_lock", p.getTrafficQuotaLock() );
		v.set( "WebDomain_fastcgi_php_version", p.getFastcgiPhpVersion() );
		v.set( "WebDomain_proxy_directives", p.getProxyDirectives() );
		v.set( "WebDomain_last_quota_notification", p.getLastQuotaNotification() );
		v.set( "WebDomain_rewrite_rules", p.getRewriteRules() );
		v.set( "WebDomain_added_date", p.getAddedDate() );
		v.set( "WebDomain_added_by", p.getAddedBy() );
		ind = i_ok;
	}
};
}

#endif // WEBDOMAINREPOSITORY_H
