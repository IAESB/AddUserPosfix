#include "webdomain.h"

WebDomain::WebDomain(){
	init();
}
WebDomain::WebDomain(long long domain_id)
{
	init();
	this->domain_id = domain_id;
}

void WebDomain::init()
{
	last_quota_notification = {0};
	added_date = {0};
}
long long WebDomain::getDomainId() const
{
	return domain_id;
}
void WebDomain::setDomainId(long long value)
{
	domain_id = value;
}
long long WebDomain::getSysUserid() const
{
	return sys_userid;
}
void WebDomain::setSysUserid(long long value)
{
	sys_userid = value;
}
long long WebDomain::getSysGroupid() const
{
	return sys_groupid;
}
void WebDomain::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string WebDomain::getSysPermUser() const
{
	return sys_perm_user;
}
void WebDomain::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebDomain::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebDomain::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebDomain::getSysPermOther() const
{
	return sys_perm_other;
}
void WebDomain::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long WebDomain::getServerId() const
{
	return server_id;
}
void WebDomain::setServerId(long long value)
{
	server_id = value;
}
std::string WebDomain::getIpAddress() const
{
	return ip_address;
}
void WebDomain::setIpAddress(std::string value)
{
	ip_address = value;
}
std::string WebDomain::getIpv6Address() const
{
	return ipv6_address;
}
void WebDomain::setIpv6Address(std::string value)
{
	ipv6_address = value;
}
std::string WebDomain::getDomain() const
{
	return domain;
}
void WebDomain::setDomain(std::string value)
{
	domain = value;
}
std::string WebDomain::getType() const
{
	return type;
}
void WebDomain::setType(std::string value)
{
	type = value;
}
long long WebDomain::getParentDomainId() const
{
	return parent_domain_id;
}
void WebDomain::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string WebDomain::getVhostType() const
{
	return vhost_type;
}
void WebDomain::setVhostType(std::string value)
{
	vhost_type = value;
}
std::string WebDomain::getDocumentRoot() const
{
	return document_root;
}
void WebDomain::setDocumentRoot(std::string value)
{
	document_root = value;
}
std::string WebDomain::getWebFolder() const
{
	return web_folder;
}
void WebDomain::setWebFolder(std::string value)
{
	web_folder = value;
}
std::string WebDomain::getSystemUser() const
{
	return system_user;
}
void WebDomain::setSystemUser(std::string value)
{
	system_user = value;
}
std::string WebDomain::getSystemGroup() const
{
	return system_group;
}
void WebDomain::setSystemGroup(std::string value)
{
	system_group = value;
}
long long WebDomain::getHdQuota() const
{
	return hd_quota;
}
void WebDomain::setHdQuota(long long value)
{
	hd_quota = value;
}
long long WebDomain::getTrafficQuota() const
{
	return traffic_quota;
}
void WebDomain::setTrafficQuota(long long value)
{
	traffic_quota = value;
}
std::string WebDomain::getCgi() const
{
	return cgi;
}
void WebDomain::setCgi(std::string value)
{
	cgi = value;
}
std::string WebDomain::getSsi() const
{
	return ssi;
}
void WebDomain::setSsi(std::string value)
{
	ssi = value;
}
std::string WebDomain::getSuexec() const
{
	return suexec;
}
void WebDomain::setSuexec(std::string value)
{
	suexec = value;
}
int WebDomain::getErrordocs() const
{
	return errordocs;
}
void WebDomain::setErrordocs(int value)
{
	errordocs = value;
}
int WebDomain::getIsSubdomainwww() const
{
	return is_subdomainwww;
}
void WebDomain::setIsSubdomainwww(int value)
{
	is_subdomainwww = value;
}
std::string WebDomain::getSubdomain() const
{
	return subdomain;
}
void WebDomain::setSubdomain(std::string value)
{
	subdomain = value;
}
std::string WebDomain::getPhp() const
{
	return php;
}
void WebDomain::setPhp(std::string value)
{
	php = value;
}
std::string WebDomain::getRuby() const
{
	return ruby;
}
void WebDomain::setRuby(std::string value)
{
	ruby = value;
}
std::string WebDomain::getPython() const
{
	return python;
}
void WebDomain::setPython(std::string value)
{
	python = value;
}
std::string WebDomain::getPerl() const
{
	return perl;
}
void WebDomain::setPerl(std::string value)
{
	perl = value;
}
std::string WebDomain::getRedirectType() const
{
	return redirect_type;
}
void WebDomain::setRedirectType(std::string value)
{
	redirect_type = value;
}
std::string WebDomain::getRedirectPath() const
{
	return redirect_path;
}
void WebDomain::setRedirectPath(std::string value)
{
	redirect_path = value;
}
std::string WebDomain::getSeoRedirect() const
{
	return seo_redirect;
}
void WebDomain::setSeoRedirect(std::string value)
{
	seo_redirect = value;
}
std::string WebDomain::getSsl() const
{
	return ssl;
}
void WebDomain::setSsl(std::string value)
{
	ssl = value;
}
std::string WebDomain::getSslState() const
{
	return ssl_state;
}
void WebDomain::setSslState(std::string value)
{
	ssl_state = value;
}
std::string WebDomain::getSslLocality() const
{
	return ssl_locality;
}
void WebDomain::setSslLocality(std::string value)
{
	ssl_locality = value;
}
std::string WebDomain::getSslOrganisation() const
{
	return ssl_organisation;
}
void WebDomain::setSslOrganisation(std::string value)
{
	ssl_organisation = value;
}
std::string WebDomain::getSslOrganisationUnit() const
{
	return ssl_organisation_unit;
}
void WebDomain::setSslOrganisationUnit(std::string value)
{
	ssl_organisation_unit = value;
}
std::string WebDomain::getSslCountry() const
{
	return ssl_country;
}
void WebDomain::setSslCountry(std::string value)
{
	ssl_country = value;
}
std::string WebDomain::getSslDomain() const
{
	return ssl_domain;
}
void WebDomain::setSslDomain(std::string value)
{
	ssl_domain = value;
}
std::string WebDomain::getSslRequest() const
{
	return ssl_request;
}
void WebDomain::setSslRequest(std::string value)
{
	ssl_request = value;
}
std::string WebDomain::getSslCert() const
{
	return ssl_cert;
}
void WebDomain::setSslCert(std::string value)
{
	ssl_cert = value;
}
std::string WebDomain::getSslBundle() const
{
	return ssl_bundle;
}
void WebDomain::setSslBundle(std::string value)
{
	ssl_bundle = value;
}
std::string WebDomain::getSslKey() const
{
	return ssl_key;
}
void WebDomain::setSslKey(std::string value)
{
	ssl_key = value;
}
std::string WebDomain::getSslAction() const
{
	return ssl_action;
}
void WebDomain::setSslAction(std::string value)
{
	ssl_action = value;
}
std::string WebDomain::getStatsPassword() const
{
	return stats_password;
}
void WebDomain::setStatsPassword(std::string value)
{
	stats_password = value;
}
std::string WebDomain::getStatsType() const
{
	return stats_type;
}
void WebDomain::setStatsType(std::string value)
{
	stats_type = value;
}
std::string WebDomain::getAllowOverride() const
{
	return allow_override;
}
void WebDomain::setAllowOverride(std::string value)
{
	allow_override = value;
}
std::string WebDomain::getApacheDirectives() const
{
	return apache_directives;
}
void WebDomain::setApacheDirectives(std::string value)
{
	apache_directives = value;
}
std::string WebDomain::getNginxDirectives() const
{
	return nginx_directives;
}
void WebDomain::setNginxDirectives(std::string value)
{
	nginx_directives = value;
}
std::string WebDomain::getPhpFpmUseSocket() const
{
	return php_fpm_use_socket;
}
void WebDomain::setPhpFpmUseSocket(std::string value)
{
	php_fpm_use_socket = value;
}
std::string WebDomain::getPm() const
{
	return pm;
}
void WebDomain::setPm(std::string value)
{
	pm = value;
}
int WebDomain::getPmMaxChildren() const
{
	return pm_max_children;
}
void WebDomain::setPmMaxChildren(int value)
{
	pm_max_children = value;
}
int WebDomain::getPmStartServers() const
{
	return pm_start_servers;
}
void WebDomain::setPmStartServers(int value)
{
	pm_start_servers = value;
}
int WebDomain::getPmMinSpareServers() const
{
	return pm_min_spare_servers;
}
void WebDomain::setPmMinSpareServers(int value)
{
	pm_min_spare_servers = value;
}
int WebDomain::getPmMaxSpareServers() const
{
	return pm_max_spare_servers;
}
void WebDomain::setPmMaxSpareServers(int value)
{
	pm_max_spare_servers = value;
}
int WebDomain::getPmProcessIdleTimeout() const
{
	return pm_process_idle_timeout;
}
void WebDomain::setPmProcessIdleTimeout(int value)
{
	pm_process_idle_timeout = value;
}
int WebDomain::getPmMaxRequests() const
{
	return pm_max_requests;
}
void WebDomain::setPmMaxRequests(int value)
{
	pm_max_requests = value;
}
std::string WebDomain::getPhpOpenBasedir() const
{
	return php_open_basedir;
}
void WebDomain::setPhpOpenBasedir(std::string value)
{
	php_open_basedir = value;
}
std::string WebDomain::getCustomPhpIni() const
{
	return custom_php_ini;
}
void WebDomain::setCustomPhpIni(std::string value)
{
	custom_php_ini = value;
}
std::string WebDomain::getBackupInterval() const
{
	return backup_interval;
}
void WebDomain::setBackupInterval(std::string value)
{
	backup_interval = value;
}
int WebDomain::getBackupCopies() const
{
	return backup_copies;
}
void WebDomain::setBackupCopies(int value)
{
	backup_copies = value;
}
std::string WebDomain::getBackupExcludes() const
{
	return backup_excludes;
}
void WebDomain::setBackupExcludes(std::string value)
{
	backup_excludes = value;
}
std::string WebDomain::getActive() const
{
	return active;
}
void WebDomain::setActive(std::string value)
{
	active = value;
}
std::string WebDomain::getTrafficQuotaLock() const
{
	return traffic_quota_lock;
}
void WebDomain::setTrafficQuotaLock(std::string value)
{
	traffic_quota_lock = value;
}
std::string WebDomain::getFastcgiPhpVersion() const
{
	return fastcgi_php_version;
}
void WebDomain::setFastcgiPhpVersion(std::string value)
{
	fastcgi_php_version = value;
}
std::string WebDomain::getProxyDirectives() const
{
	return proxy_directives;
}
void WebDomain::setProxyDirectives(std::string value)
{
	proxy_directives = value;
}
tm WebDomain::getLastQuotaNotification() const
{
	return last_quota_notification;
}
void WebDomain::setLastQuotaNotification(tm value)
{
	last_quota_notification = value;
}
std::string WebDomain::getRewriteRules() const
{
	return rewrite_rules;
}
void WebDomain::setRewriteRules(std::string value)
{
	rewrite_rules = value;
}
tm WebDomain::getAddedDate() const
{
	return added_date;
}
void WebDomain::setAddedDate(tm value)
{
	added_date = value;
}
std::string WebDomain::getAddedBy() const
{
	return added_by;
}
void WebDomain::setAddedBy(std::string value)
{
	added_by = value;
}

