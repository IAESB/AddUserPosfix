#include "clienttemplate.h"

ClientTemplate::ClientTemplate(){
	init();
}
ClientTemplate::ClientTemplate(long long template_id)
{
	init();
	this->template_id = template_id;
}

void ClientTemplate::init()
{
}
long long ClientTemplate::getTemplateId() const
{
	return template_id;
}
void ClientTemplate::setTemplateId(long long value)
{
	template_id = value;
}
long long ClientTemplate::getSysUserid() const
{
	return sys_userid;
}
void ClientTemplate::setSysUserid(long long value)
{
	sys_userid = value;
}
long long ClientTemplate::getSysGroupid() const
{
	return sys_groupid;
}
void ClientTemplate::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string ClientTemplate::getSysPermUser() const
{
	return sys_perm_user;
}
void ClientTemplate::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ClientTemplate::getSysPermGroup() const
{
	return sys_perm_group;
}
void ClientTemplate::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ClientTemplate::getSysPermOther() const
{
	return sys_perm_other;
}
void ClientTemplate::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string ClientTemplate::getTemplateName() const
{
	return template_name;
}
void ClientTemplate::setTemplateName(std::string value)
{
	template_name = value;
}
std::string ClientTemplate::getTemplateType() const
{
	return template_type;
}
void ClientTemplate::setTemplateType(std::string value)
{
	template_type = value;
}
int ClientTemplate::getLimitMaildomain() const
{
	return limit_maildomain;
}
void ClientTemplate::setLimitMaildomain(int value)
{
	limit_maildomain = value;
}
int ClientTemplate::getLimitMailbox() const
{
	return limit_mailbox;
}
void ClientTemplate::setLimitMailbox(int value)
{
	limit_mailbox = value;
}
int ClientTemplate::getLimitMailalias() const
{
	return limit_mailalias;
}
void ClientTemplate::setLimitMailalias(int value)
{
	limit_mailalias = value;
}
int ClientTemplate::getLimitMailaliasdomain() const
{
	return limit_mailaliasdomain;
}
void ClientTemplate::setLimitMailaliasdomain(int value)
{
	limit_mailaliasdomain = value;
}
int ClientTemplate::getLimitMailforward() const
{
	return limit_mailforward;
}
void ClientTemplate::setLimitMailforward(int value)
{
	limit_mailforward = value;
}
int ClientTemplate::getLimitMailcatchall() const
{
	return limit_mailcatchall;
}
void ClientTemplate::setLimitMailcatchall(int value)
{
	limit_mailcatchall = value;
}
int ClientTemplate::getLimitMailrouting() const
{
	return limit_mailrouting;
}
void ClientTemplate::setLimitMailrouting(int value)
{
	limit_mailrouting = value;
}
int ClientTemplate::getLimitMailfilter() const
{
	return limit_mailfilter;
}
void ClientTemplate::setLimitMailfilter(int value)
{
	limit_mailfilter = value;
}
int ClientTemplate::getLimitFetchmail() const
{
	return limit_fetchmail;
}
void ClientTemplate::setLimitFetchmail(int value)
{
	limit_fetchmail = value;
}
int ClientTemplate::getLimitMailquota() const
{
	return limit_mailquota;
}
void ClientTemplate::setLimitMailquota(int value)
{
	limit_mailquota = value;
}
int ClientTemplate::getLimitSpamfilterWblist() const
{
	return limit_spamfilter_wblist;
}
void ClientTemplate::setLimitSpamfilterWblist(int value)
{
	limit_spamfilter_wblist = value;
}
int ClientTemplate::getLimitSpamfilterUser() const
{
	return limit_spamfilter_user;
}
void ClientTemplate::setLimitSpamfilterUser(int value)
{
	limit_spamfilter_user = value;
}
int ClientTemplate::getLimitSpamfilterPolicy() const
{
	return limit_spamfilter_policy;
}
void ClientTemplate::setLimitSpamfilterPolicy(int value)
{
	limit_spamfilter_policy = value;
}
std::string ClientTemplate::getLimitWebIp() const
{
	return limit_web_ip;
}
void ClientTemplate::setLimitWebIp(std::string value)
{
	limit_web_ip = value;
}
int ClientTemplate::getLimitWebDomain() const
{
	return limit_web_domain;
}
void ClientTemplate::setLimitWebDomain(int value)
{
	limit_web_domain = value;
}
int ClientTemplate::getLimitWebQuota() const
{
	return limit_web_quota;
}
void ClientTemplate::setLimitWebQuota(int value)
{
	limit_web_quota = value;
}
std::string ClientTemplate::getWebPhpOptions() const
{
	return web_php_options;
}
void ClientTemplate::setWebPhpOptions(std::string value)
{
	web_php_options = value;
}
std::string ClientTemplate::getLimitCgi() const
{
	return limit_cgi;
}
void ClientTemplate::setLimitCgi(std::string value)
{
	limit_cgi = value;
}
std::string ClientTemplate::getLimitSsi() const
{
	return limit_ssi;
}
void ClientTemplate::setLimitSsi(std::string value)
{
	limit_ssi = value;
}
std::string ClientTemplate::getLimitPerl() const
{
	return limit_perl;
}
void ClientTemplate::setLimitPerl(std::string value)
{
	limit_perl = value;
}
std::string ClientTemplate::getLimitRuby() const
{
	return limit_ruby;
}
void ClientTemplate::setLimitRuby(std::string value)
{
	limit_ruby = value;
}
std::string ClientTemplate::getLimitPython() const
{
	return limit_python;
}
void ClientTemplate::setLimitPython(std::string value)
{
	limit_python = value;
}
std::string ClientTemplate::getForceSuexec() const
{
	return force_suexec;
}
void ClientTemplate::setForceSuexec(std::string value)
{
	force_suexec = value;
}
std::string ClientTemplate::getLimitHterror() const
{
	return limit_hterror;
}
void ClientTemplate::setLimitHterror(std::string value)
{
	limit_hterror = value;
}
std::string ClientTemplate::getLimitWildcard() const
{
	return limit_wildcard;
}
void ClientTemplate::setLimitWildcard(std::string value)
{
	limit_wildcard = value;
}
std::string ClientTemplate::getLimitSsl() const
{
	return limit_ssl;
}
void ClientTemplate::setLimitSsl(std::string value)
{
	limit_ssl = value;
}
int ClientTemplate::getLimitWebSubdomain() const
{
	return limit_web_subdomain;
}
void ClientTemplate::setLimitWebSubdomain(int value)
{
	limit_web_subdomain = value;
}
int ClientTemplate::getLimitWebAliasdomain() const
{
	return limit_web_aliasdomain;
}
void ClientTemplate::setLimitWebAliasdomain(int value)
{
	limit_web_aliasdomain = value;
}
int ClientTemplate::getLimitFtpUser() const
{
	return limit_ftp_user;
}
void ClientTemplate::setLimitFtpUser(int value)
{
	limit_ftp_user = value;
}
int ClientTemplate::getLimitShellUser() const
{
	return limit_shell_user;
}
void ClientTemplate::setLimitShellUser(int value)
{
	limit_shell_user = value;
}
std::string ClientTemplate::getSshChroot() const
{
	return ssh_chroot;
}
void ClientTemplate::setSshChroot(std::string value)
{
	ssh_chroot = value;
}
int ClientTemplate::getLimitWebdavUser() const
{
	return limit_webdav_user;
}
void ClientTemplate::setLimitWebdavUser(int value)
{
	limit_webdav_user = value;
}
std::string ClientTemplate::getLimitBackup() const
{
	return limit_backup;
}
void ClientTemplate::setLimitBackup(std::string value)
{
	limit_backup = value;
}
int ClientTemplate::getLimitAps() const
{
	return limit_aps;
}
void ClientTemplate::setLimitAps(int value)
{
	limit_aps = value;
}
int ClientTemplate::getLimitDnsZone() const
{
	return limit_dns_zone;
}
void ClientTemplate::setLimitDnsZone(int value)
{
	limit_dns_zone = value;
}
int ClientTemplate::getLimitDnsSlaveZone() const
{
	return limit_dns_slave_zone;
}
void ClientTemplate::setLimitDnsSlaveZone(int value)
{
	limit_dns_slave_zone = value;
}
int ClientTemplate::getLimitDnsRecord() const
{
	return limit_dns_record;
}
void ClientTemplate::setLimitDnsRecord(int value)
{
	limit_dns_record = value;
}
int ClientTemplate::getLimitDatabase() const
{
	return limit_database;
}
void ClientTemplate::setLimitDatabase(int value)
{
	limit_database = value;
}
int ClientTemplate::getLimitDatabaseQuota() const
{
	return limit_database_quota;
}
void ClientTemplate::setLimitDatabaseQuota(int value)
{
	limit_database_quota = value;
}
int ClientTemplate::getLimitCron() const
{
	return limit_cron;
}
void ClientTemplate::setLimitCron(int value)
{
	limit_cron = value;
}
std::string ClientTemplate::getLimitCronType() const
{
	return limit_cron_type;
}
void ClientTemplate::setLimitCronType(std::string value)
{
	limit_cron_type = value;
}
int ClientTemplate::getLimitCronFrequency() const
{
	return limit_cron_frequency;
}
void ClientTemplate::setLimitCronFrequency(int value)
{
	limit_cron_frequency = value;
}
int ClientTemplate::getLimitTrafficQuota() const
{
	return limit_traffic_quota;
}
void ClientTemplate::setLimitTrafficQuota(int value)
{
	limit_traffic_quota = value;
}
int ClientTemplate::getLimitClient() const
{
	return limit_client;
}
void ClientTemplate::setLimitClient(int value)
{
	limit_client = value;
}
int ClientTemplate::getLimitDomainmodule() const
{
	return limit_domainmodule;
}
void ClientTemplate::setLimitDomainmodule(int value)
{
	limit_domainmodule = value;
}
int ClientTemplate::getLimitMailmailinglist() const
{
	return limit_mailmailinglist;
}
void ClientTemplate::setLimitMailmailinglist(int value)
{
	limit_mailmailinglist = value;
}
int ClientTemplate::getLimitOpenvzVm() const
{
	return limit_openvz_vm;
}
void ClientTemplate::setLimitOpenvzVm(int value)
{
	limit_openvz_vm = value;
}
int ClientTemplate::getLimitOpenvzVmTemplateId() const
{
	return limit_openvz_vm_template_id;
}
void ClientTemplate::setLimitOpenvzVmTemplateId(int value)
{
	limit_openvz_vm_template_id = value;
}

