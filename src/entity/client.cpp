#include "client.h"

Client::Client(){
	init();
}
Client::Client(long long client_id)
{
	init();
	this->client_id = client_id;
}

void Client::init()
{
	added_date = {0};
}
long long Client::getClientId() const
{
	return client_id;
}
void Client::setClientId(long long value)
{
	client_id = value;
}
long long Client::getSysUserid() const
{
	return sys_userid;
}
void Client::setSysUserid(long long value)
{
	sys_userid = value;
}
long long Client::getSysGroupid() const
{
	return sys_groupid;
}
void Client::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string Client::getSysPermUser() const
{
	return sys_perm_user;
}
void Client::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string Client::getSysPermGroup() const
{
	return sys_perm_group;
}
void Client::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string Client::getSysPermOther() const
{
	return sys_perm_other;
}
void Client::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string Client::getCompanyName() const
{
	return company_name;
}
void Client::setCompanyName(std::string value)
{
	company_name = value;
}
std::string Client::getCompanyId() const
{
	return company_id;
}
void Client::setCompanyId(std::string value)
{
	company_id = value;
}
std::string Client::getGender() const
{
	return gender;
}
void Client::setGender(std::string value)
{
	gender = value;
}
std::string Client::getContactName() const
{
	return contact_name;
}
void Client::setContactName(std::string value)
{
	contact_name = value;
}
std::string Client::getCustomerNo() const
{
	return customer_no;
}
void Client::setCustomerNo(std::string value)
{
	customer_no = value;
}
std::string Client::getVatId() const
{
	return vat_id;
}
void Client::setVatId(std::string value)
{
	vat_id = value;
}
std::string Client::getStreet() const
{
	return street;
}
void Client::setStreet(std::string value)
{
	street = value;
}
std::string Client::getZip() const
{
	return zip;
}
void Client::setZip(std::string value)
{
	zip = value;
}
std::string Client::getCity() const
{
	return city;
}
void Client::setCity(std::string value)
{
	city = value;
}
std::string Client::getState() const
{
	return state;
}
void Client::setState(std::string value)
{
	state = value;
}
std::string Client::getCountry() const
{
	return country;
}
void Client::setCountry(std::string value)
{
	country = value;
}
std::string Client::getTelephone() const
{
	return telephone;
}
void Client::setTelephone(std::string value)
{
	telephone = value;
}
std::string Client::getMobile() const
{
	return mobile;
}
void Client::setMobile(std::string value)
{
	mobile = value;
}
std::string Client::getFax() const
{
	return fax;
}
void Client::setFax(std::string value)
{
	fax = value;
}
std::string Client::getEmail() const
{
	return email;
}
void Client::setEmail(std::string value)
{
	email = value;
}
std::string Client::getInternet() const
{
	return internet;
}
void Client::setInternet(std::string value)
{
	internet = value;
}
std::string Client::getIcq() const
{
	return icq;
}
void Client::setIcq(std::string value)
{
	icq = value;
}
std::string Client::getNotes() const
{
	return notes;
}
void Client::setNotes(std::string value)
{
	notes = value;
}
std::string Client::getBankAccountOwner() const
{
	return bank_account_owner;
}
void Client::setBankAccountOwner(std::string value)
{
	bank_account_owner = value;
}
std::string Client::getBankAccountNumber() const
{
	return bank_account_number;
}
void Client::setBankAccountNumber(std::string value)
{
	bank_account_number = value;
}
std::string Client::getBankCode() const
{
	return bank_code;
}
void Client::setBankCode(std::string value)
{
	bank_code = value;
}
std::string Client::getBankName() const
{
	return bank_name;
}
void Client::setBankName(std::string value)
{
	bank_name = value;
}
std::string Client::getBankAccountIban() const
{
	return bank_account_iban;
}
void Client::setBankAccountIban(std::string value)
{
	bank_account_iban = value;
}
std::string Client::getBankAccountSwift() const
{
	return bank_account_swift;
}
void Client::setBankAccountSwift(std::string value)
{
	bank_account_swift = value;
}
std::string Client::getPaypalEmail() const
{
	return paypal_email;
}
void Client::setPaypalEmail(std::string value)
{
	paypal_email = value;
}
long long Client::getDefaultMailserver() const
{
	return default_mailserver;
}
void Client::setDefaultMailserver(long long value)
{
	default_mailserver = value;
}
std::string Client::getMailServers() const
{
	return mail_servers;
}
void Client::setMailServers(std::string value)
{
	mail_servers = value;
}
int Client::getLimitMaildomain() const
{
	return limit_maildomain;
}
void Client::setLimitMaildomain(int value)
{
	limit_maildomain = value;
}
int Client::getLimitMailbox() const
{
	return limit_mailbox;
}
void Client::setLimitMailbox(int value)
{
	limit_mailbox = value;
}
int Client::getLimitMailalias() const
{
	return limit_mailalias;
}
void Client::setLimitMailalias(int value)
{
	limit_mailalias = value;
}
int Client::getLimitMailaliasdomain() const
{
	return limit_mailaliasdomain;
}
void Client::setLimitMailaliasdomain(int value)
{
	limit_mailaliasdomain = value;
}
int Client::getLimitMailforward() const
{
	return limit_mailforward;
}
void Client::setLimitMailforward(int value)
{
	limit_mailforward = value;
}
int Client::getLimitMailcatchall() const
{
	return limit_mailcatchall;
}
void Client::setLimitMailcatchall(int value)
{
	limit_mailcatchall = value;
}
int Client::getLimitMailrouting() const
{
	return limit_mailrouting;
}
void Client::setLimitMailrouting(int value)
{
	limit_mailrouting = value;
}
int Client::getLimitMailfilter() const
{
	return limit_mailfilter;
}
void Client::setLimitMailfilter(int value)
{
	limit_mailfilter = value;
}
int Client::getLimitFetchmail() const
{
	return limit_fetchmail;
}
void Client::setLimitFetchmail(int value)
{
	limit_fetchmail = value;
}
int Client::getLimitMailquota() const
{
	return limit_mailquota;
}
void Client::setLimitMailquota(int value)
{
	limit_mailquota = value;
}
int Client::getLimitSpamfilterWblist() const
{
	return limit_spamfilter_wblist;
}
void Client::setLimitSpamfilterWblist(int value)
{
	limit_spamfilter_wblist = value;
}
int Client::getLimitSpamfilterUser() const
{
	return limit_spamfilter_user;
}
void Client::setLimitSpamfilterUser(int value)
{
	limit_spamfilter_user = value;
}
int Client::getLimitSpamfilterPolicy() const
{
	return limit_spamfilter_policy;
}
void Client::setLimitSpamfilterPolicy(int value)
{
	limit_spamfilter_policy = value;
}
long long Client::getDefaultWebserver() const
{
	return default_webserver;
}
void Client::setDefaultWebserver(long long value)
{
	default_webserver = value;
}
std::string Client::getWebServers() const
{
	return web_servers;
}
void Client::setWebServers(std::string value)
{
	web_servers = value;
}
std::string Client::getLimitWebIp() const
{
	return limit_web_ip;
}
void Client::setLimitWebIp(std::string value)
{
	limit_web_ip = value;
}
int Client::getLimitWebDomain() const
{
	return limit_web_domain;
}
void Client::setLimitWebDomain(int value)
{
	limit_web_domain = value;
}
int Client::getLimitWebQuota() const
{
	return limit_web_quota;
}
void Client::setLimitWebQuota(int value)
{
	limit_web_quota = value;
}
std::string Client::getWebPhpOptions() const
{
	return web_php_options;
}
void Client::setWebPhpOptions(std::string value)
{
	web_php_options = value;
}
std::string Client::getLimitCgi() const
{
	return limit_cgi;
}
void Client::setLimitCgi(std::string value)
{
	limit_cgi = value;
}
std::string Client::getLimitSsi() const
{
	return limit_ssi;
}
void Client::setLimitSsi(std::string value)
{
	limit_ssi = value;
}
std::string Client::getLimitPerl() const
{
	return limit_perl;
}
void Client::setLimitPerl(std::string value)
{
	limit_perl = value;
}
std::string Client::getLimitRuby() const
{
	return limit_ruby;
}
void Client::setLimitRuby(std::string value)
{
	limit_ruby = value;
}
std::string Client::getLimitPython() const
{
	return limit_python;
}
void Client::setLimitPython(std::string value)
{
	limit_python = value;
}
std::string Client::getForceSuexec() const
{
	return force_suexec;
}
void Client::setForceSuexec(std::string value)
{
	force_suexec = value;
}
std::string Client::getLimitHterror() const
{
	return limit_hterror;
}
void Client::setLimitHterror(std::string value)
{
	limit_hterror = value;
}
std::string Client::getLimitWildcard() const
{
	return limit_wildcard;
}
void Client::setLimitWildcard(std::string value)
{
	limit_wildcard = value;
}
std::string Client::getLimitSsl() const
{
	return limit_ssl;
}
void Client::setLimitSsl(std::string value)
{
	limit_ssl = value;
}
int Client::getLimitWebSubdomain() const
{
	return limit_web_subdomain;
}
void Client::setLimitWebSubdomain(int value)
{
	limit_web_subdomain = value;
}
int Client::getLimitWebAliasdomain() const
{
	return limit_web_aliasdomain;
}
void Client::setLimitWebAliasdomain(int value)
{
	limit_web_aliasdomain = value;
}
int Client::getLimitFtpUser() const
{
	return limit_ftp_user;
}
void Client::setLimitFtpUser(int value)
{
	limit_ftp_user = value;
}
int Client::getLimitShellUser() const
{
	return limit_shell_user;
}
void Client::setLimitShellUser(int value)
{
	limit_shell_user = value;
}
std::string Client::getSshChroot() const
{
	return ssh_chroot;
}
void Client::setSshChroot(std::string value)
{
	ssh_chroot = value;
}
int Client::getLimitWebdavUser() const
{
	return limit_webdav_user;
}
void Client::setLimitWebdavUser(int value)
{
	limit_webdav_user = value;
}
std::string Client::getLimitBackup() const
{
	return limit_backup;
}
void Client::setLimitBackup(std::string value)
{
	limit_backup = value;
}
int Client::getLimitAps() const
{
	return limit_aps;
}
void Client::setLimitAps(int value)
{
	limit_aps = value;
}
long long Client::getDefaultDnsserver() const
{
	return default_dnsserver;
}
void Client::setDefaultDnsserver(long long value)
{
	default_dnsserver = value;
}
std::string Client::getDbServers() const
{
	return db_servers;
}
void Client::setDbServers(std::string value)
{
	db_servers = value;
}
int Client::getLimitDnsZone() const
{
	return limit_dns_zone;
}
void Client::setLimitDnsZone(int value)
{
	limit_dns_zone = value;
}
long long Client::getDefaultSlaveDnsserver() const
{
	return default_slave_dnsserver;
}
void Client::setDefaultSlaveDnsserver(long long value)
{
	default_slave_dnsserver = value;
}
int Client::getLimitDnsSlaveZone() const
{
	return limit_dns_slave_zone;
}
void Client::setLimitDnsSlaveZone(int value)
{
	limit_dns_slave_zone = value;
}
int Client::getLimitDnsRecord() const
{
	return limit_dns_record;
}
void Client::setLimitDnsRecord(int value)
{
	limit_dns_record = value;
}
int Client::getDefaultDbserver() const
{
	return default_dbserver;
}
void Client::setDefaultDbserver(int value)
{
	default_dbserver = value;
}
std::string Client::getDnsServers() const
{
	return dns_servers;
}
void Client::setDnsServers(std::string value)
{
	dns_servers = value;
}
int Client::getLimitDatabase() const
{
	return limit_database;
}
void Client::setLimitDatabase(int value)
{
	limit_database = value;
}
int Client::getLimitDatabaseQuota() const
{
	return limit_database_quota;
}
void Client::setLimitDatabaseQuota(int value)
{
	limit_database_quota = value;
}
int Client::getLimitCron() const
{
	return limit_cron;
}
void Client::setLimitCron(int value)
{
	limit_cron = value;
}
std::string Client::getLimitCronType() const
{
	return limit_cron_type;
}
void Client::setLimitCronType(std::string value)
{
	limit_cron_type = value;
}
int Client::getLimitCronFrequency() const
{
	return limit_cron_frequency;
}
void Client::setLimitCronFrequency(int value)
{
	limit_cron_frequency = value;
}
int Client::getLimitTrafficQuota() const
{
	return limit_traffic_quota;
}
void Client::setLimitTrafficQuota(int value)
{
	limit_traffic_quota = value;
}
int Client::getLimitClient() const
{
	return limit_client;
}
void Client::setLimitClient(int value)
{
	limit_client = value;
}
int Client::getLimitDomainmodule() const
{
	return limit_domainmodule;
}
void Client::setLimitDomainmodule(int value)
{
	limit_domainmodule = value;
}
int Client::getLimitMailmailinglist() const
{
	return limit_mailmailinglist;
}
void Client::setLimitMailmailinglist(int value)
{
	limit_mailmailinglist = value;
}
int Client::getLimitOpenvzVm() const
{
	return limit_openvz_vm;
}
void Client::setLimitOpenvzVm(int value)
{
	limit_openvz_vm = value;
}
int Client::getLimitOpenvzVmTemplateId() const
{
	return limit_openvz_vm_template_id;
}
void Client::setLimitOpenvzVmTemplateId(int value)
{
	limit_openvz_vm_template_id = value;
}
long long Client::getParentClientId() const
{
	return parent_client_id;
}
void Client::setParentClientId(long long value)
{
	parent_client_id = value;
}
std::string Client::getUsername() const
{
	return username;
}
void Client::setUsername(std::string value)
{
	username = value;
}
std::string Client::getPassword() const
{
	return password;
}
void Client::setPassword(std::string value)
{
	password = value;
}
std::string Client::getLanguage() const
{
	return language;
}
void Client::setLanguage(std::string value)
{
	language = value;
}
std::string Client::getUsertheme() const
{
	return usertheme;
}
void Client::setUsertheme(std::string value)
{
	usertheme = value;
}
long long Client::getTemplateMaster() const
{
	return template_master;
}
void Client::setTemplateMaster(long long value)
{
	template_master = value;
}
std::string Client::getTemplateAdditional() const
{
	return template_additional;
}
void Client::setTemplateAdditional(std::string value)
{
	template_additional = value;
}
long long Client::getCreatedAt() const
{
	return created_at;
}
void Client::setCreatedAt(long long value)
{
	created_at = value;
}
std::string Client::getLocked() const
{
	return locked;
}
void Client::setLocked(std::string value)
{
	locked = value;
}
std::string Client::getCanceled() const
{
	return canceled;
}
void Client::setCanceled(std::string value)
{
	canceled = value;
}
std::string Client::getCanUseApi() const
{
	return can_use_api;
}
void Client::setCanUseApi(std::string value)
{
	can_use_api = value;
}
std::string Client::getTmpData() const
{
	return tmp_data;
}
void Client::setTmpData(std::string value)
{
	tmp_data = value;
}
std::string Client::getIdRsa() const
{
	return id_rsa;
}
void Client::setIdRsa(std::string value)
{
	id_rsa = value;
}
std::string Client::getSshRsa() const
{
	return ssh_rsa;
}
void Client::setSshRsa(std::string value)
{
	ssh_rsa = value;
}
std::string Client::getCustomerNoTemplate() const
{
	return customer_no_template;
}
void Client::setCustomerNoTemplate(std::string value)
{
	customer_no_template = value;
}
int Client::getCustomerNoStart() const
{
	return customer_no_start;
}
void Client::setCustomerNoStart(int value)
{
	customer_no_start = value;
}
int Client::getCustomerNoCounter() const
{
	return customer_no_counter;
}
void Client::setCustomerNoCounter(int value)
{
	customer_no_counter = value;
}
tm Client::getAddedDate() const
{
	return added_date;
}
void Client::setAddedDate(tm value)
{
	added_date = value;
}
std::string Client::getAddedBy() const
{
	return added_by;
}
void Client::setAddedBy(std::string value)
{
	added_by = value;
}

