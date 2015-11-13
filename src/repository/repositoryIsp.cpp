#include "repositoryIsp.h"
RepositoryIsp::RepositoryIsp() :apsinstances(dataBase) ,apsinstancessettings(dataBase) ,apspackages(dataBase) ,apssettings(dataBase) ,attemptslogin(dataBase) ,client(dataBase) ,clientcircle(dataBase) ,clientmessagetemplate(dataBase) ,clienttemplate(dataBase) ,clienttemplateassigned(dataBase) ,country(dataBase) ,cron(dataBase) ,directivesnippets(dataBase) ,dnsrr(dataBase) ,dnsslave(dataBase) ,dnssoa(dataBase) ,dnstemplate(dataBase) ,domain(dataBase) ,firewall(dataBase) ,ftpuser(dataBase) ,helpfaq(dataBase) ,helpfaqsections(dataBase) ,iptables(dataBase) ,mailaccess(dataBase) ,mailbackup(dataBase) ,mailcontentfilter(dataBase) ,maildomain(dataBase) ,mailforwarding(dataBase) ,mailget(dataBase) ,mailmailinglist(dataBase) ,mailrelayrecipient(dataBase) ,mailtraffic(dataBase) ,mailtransport(dataBase) ,mailuser(dataBase) ,mailuserfilter(dataBase) ,monitordata(dataBase) ,openvzip(dataBase) ,openvzostemplate(dataBase) ,openvztemplate(dataBase) ,openvztraffic(dataBase) ,openvzvm(dataBase) ,remotesession(dataBase) ,remoteuser(dataBase) ,server(dataBase) ,serverip(dataBase) ,serverphp(dataBase) ,shelluser(dataBase) ,softwarepackage(dataBase) ,softwarerepo(dataBase) ,softwareupdate(dataBase) ,softwareupdateinst(dataBase) ,spamfilterpolicy(dataBase) ,spamfilterusers(dataBase) ,spamfilterwblist(dataBase) ,supportmessage(dataBase) ,sysconfig(dataBase) ,syscron(dataBase) ,sysdatalog(dataBase) ,sysdbsync(dataBase) ,sysfilesync(dataBase) ,sysgroup(dataBase) ,sysini(dataBase) ,syslog(dataBase) ,sysremoteaction(dataBase) ,syssession(dataBase) ,systheme(dataBase) ,sysuser(dataBase) ,webbackup(dataBase) ,webdatabase(dataBase) ,webdatabaseuser(dataBase) ,webdomain(dataBase) ,webfolder(dataBase) ,webfolderuser(dataBase) ,webtraffic(dataBase) ,webdavuser(dataBase) 
{}
void RepositoryIsp::open(const std::string& connectStringDataBase)
{
	if(connectStringDataBase.size())
		dataBase.open(connectStringDataBase);
	else
		throw runtime_error("connectStringDataBase is EMPTY, info a url to connect in data base");
}

template<> ApsInstancesPtr RepositoryIsp::select(const ApsInstances& obj)
{
	return apsinstances.select(obj);
}
template<> ApsInstancesList RepositoryIsp::select(const string& where)
{
	return apsinstances.select(where);
}
template<> int RepositoryIsp::insert(const ApsInstances& obj)
{
	return apsinstances.insert(obj);
}
template<> void RepositoryIsp::update(const ApsInstances& obj)
{
	apsinstances.update(obj);
}
template<> void RepositoryIsp::update(const ApsInstances& oldObj, const ApsInstances& newObj)
{
	apsinstances.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ApsInstances& obj)
{
	apsinstances.remove(obj);
}

template<> ApsInstancesSettingsPtr RepositoryIsp::select(const ApsInstancesSettings& obj)
{
	return apsinstancessettings.select(obj);
}
template<> ApsInstancesSettingsList RepositoryIsp::select(const string& where)
{
	return apsinstancessettings.select(where);
}
template<> int RepositoryIsp::insert(const ApsInstancesSettings& obj)
{
	return apsinstancessettings.insert(obj);
}
template<> void RepositoryIsp::update(const ApsInstancesSettings& obj)
{
	apsinstancessettings.update(obj);
}
template<> void RepositoryIsp::update(const ApsInstancesSettings& oldObj, const ApsInstancesSettings& newObj)
{
	apsinstancessettings.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ApsInstancesSettings& obj)
{
	apsinstancessettings.remove(obj);
}

template<> ApsPackagesPtr RepositoryIsp::select(const ApsPackages& obj)
{
	return apspackages.select(obj);
}
template<> ApsPackagesList RepositoryIsp::select(const string& where)
{
	return apspackages.select(where);
}
template<> int RepositoryIsp::insert(const ApsPackages& obj)
{
	return apspackages.insert(obj);
}
template<> void RepositoryIsp::update(const ApsPackages& obj)
{
	apspackages.update(obj);
}
template<> void RepositoryIsp::update(const ApsPackages& oldObj, const ApsPackages& newObj)
{
	apspackages.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ApsPackages& obj)
{
	apspackages.remove(obj);
}

template<> ApsSettingsPtr RepositoryIsp::select(const ApsSettings& obj)
{
	return apssettings.select(obj);
}
template<> ApsSettingsList RepositoryIsp::select(const string& where)
{
	return apssettings.select(where);
}
template<> int RepositoryIsp::insert(const ApsSettings& obj)
{
	return apssettings.insert(obj);
}
template<> void RepositoryIsp::update(const ApsSettings& obj)
{
	apssettings.update(obj);
}
template<> void RepositoryIsp::update(const ApsSettings& oldObj, const ApsSettings& newObj)
{
	apssettings.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ApsSettings& obj)
{
	apssettings.remove(obj);
}

template<> AttemptsLoginPtr RepositoryIsp::select(const AttemptsLogin& obj)
{
	return attemptslogin.select(obj);
}
template<> AttemptsLoginList RepositoryIsp::select(const string& where)
{
	return attemptslogin.select(where);
}
template<> int RepositoryIsp::insert(const AttemptsLogin& obj)
{
	return attemptslogin.insert(obj);
}
template<> void RepositoryIsp::update(const AttemptsLogin& obj)
{
	attemptslogin.update(obj);
}
template<> void RepositoryIsp::update(const AttemptsLogin& oldObj, const AttemptsLogin& newObj)
{
	attemptslogin.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const AttemptsLogin& obj)
{
	attemptslogin.remove(obj);
}

template<> ClientPtr RepositoryIsp::select(const Client& obj)
{
	return client.select(obj);
}
template<> ClientList RepositoryIsp::select(const string& where)
{
	return client.select(where);
}
template<> int RepositoryIsp::insert(const Client& obj)
{
	return client.insert(obj);
}
template<> void RepositoryIsp::update(const Client& obj)
{
	client.update(obj);
}
template<> void RepositoryIsp::update(const Client& oldObj, const Client& newObj)
{
	client.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Client& obj)
{
	client.remove(obj);
}

template<> ClientCirclePtr RepositoryIsp::select(const ClientCircle& obj)
{
	return clientcircle.select(obj);
}
template<> ClientCircleList RepositoryIsp::select(const string& where)
{
	return clientcircle.select(where);
}
template<> int RepositoryIsp::insert(const ClientCircle& obj)
{
	return clientcircle.insert(obj);
}
template<> void RepositoryIsp::update(const ClientCircle& obj)
{
	clientcircle.update(obj);
}
template<> void RepositoryIsp::update(const ClientCircle& oldObj, const ClientCircle& newObj)
{
	clientcircle.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ClientCircle& obj)
{
	clientcircle.remove(obj);
}

template<> ClientMessageTemplatePtr RepositoryIsp::select(const ClientMessageTemplate& obj)
{
	return clientmessagetemplate.select(obj);
}
template<> ClientMessageTemplateList RepositoryIsp::select(const string& where)
{
	return clientmessagetemplate.select(where);
}
template<> int RepositoryIsp::insert(const ClientMessageTemplate& obj)
{
	return clientmessagetemplate.insert(obj);
}
template<> void RepositoryIsp::update(const ClientMessageTemplate& obj)
{
	clientmessagetemplate.update(obj);
}
template<> void RepositoryIsp::update(const ClientMessageTemplate& oldObj, const ClientMessageTemplate& newObj)
{
	clientmessagetemplate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ClientMessageTemplate& obj)
{
	clientmessagetemplate.remove(obj);
}

template<> ClientTemplatePtr RepositoryIsp::select(const ClientTemplate& obj)
{
	return clienttemplate.select(obj);
}
template<> ClientTemplateList RepositoryIsp::select(const string& where)
{
	return clienttemplate.select(where);
}
template<> int RepositoryIsp::insert(const ClientTemplate& obj)
{
	return clienttemplate.insert(obj);
}
template<> void RepositoryIsp::update(const ClientTemplate& obj)
{
	clienttemplate.update(obj);
}
template<> void RepositoryIsp::update(const ClientTemplate& oldObj, const ClientTemplate& newObj)
{
	clienttemplate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ClientTemplate& obj)
{
	clienttemplate.remove(obj);
}

template<> ClientTemplateAssignedPtr RepositoryIsp::select(const ClientTemplateAssigned& obj)
{
	return clienttemplateassigned.select(obj);
}
template<> ClientTemplateAssignedList RepositoryIsp::select(const string& where)
{
	return clienttemplateassigned.select(where);
}
template<> int RepositoryIsp::insert(const ClientTemplateAssigned& obj)
{
	return clienttemplateassigned.insert(obj);
}
template<> void RepositoryIsp::update(const ClientTemplateAssigned& obj)
{
	clienttemplateassigned.update(obj);
}
template<> void RepositoryIsp::update(const ClientTemplateAssigned& oldObj, const ClientTemplateAssigned& newObj)
{
	clienttemplateassigned.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ClientTemplateAssigned& obj)
{
	clienttemplateassigned.remove(obj);
}

template<> CountryPtr RepositoryIsp::select(const Country& obj)
{
	return country.select(obj);
}
template<> CountryList RepositoryIsp::select(const string& where)
{
	return country.select(where);
}
template<> int RepositoryIsp::insert(const Country& obj)
{
	return country.insert(obj);
}
template<> void RepositoryIsp::update(const Country& obj)
{
	country.update(obj);
}
template<> void RepositoryIsp::update(const Country& oldObj, const Country& newObj)
{
	country.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Country& obj)
{
	country.remove(obj);
}

template<> CronPtr RepositoryIsp::select(const Cron& obj)
{
	return cron.select(obj);
}
template<> CronList RepositoryIsp::select(const string& where)
{
	return cron.select(where);
}
template<> int RepositoryIsp::insert(const Cron& obj)
{
	return cron.insert(obj);
}
template<> void RepositoryIsp::update(const Cron& obj)
{
	cron.update(obj);
}
template<> void RepositoryIsp::update(const Cron& oldObj, const Cron& newObj)
{
	cron.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Cron& obj)
{
	cron.remove(obj);
}

template<> DirectiveSnippetsPtr RepositoryIsp::select(const DirectiveSnippets& obj)
{
	return directivesnippets.select(obj);
}
template<> DirectiveSnippetsList RepositoryIsp::select(const string& where)
{
	return directivesnippets.select(where);
}
template<> int RepositoryIsp::insert(const DirectiveSnippets& obj)
{
	return directivesnippets.insert(obj);
}
template<> void RepositoryIsp::update(const DirectiveSnippets& obj)
{
	directivesnippets.update(obj);
}
template<> void RepositoryIsp::update(const DirectiveSnippets& oldObj, const DirectiveSnippets& newObj)
{
	directivesnippets.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const DirectiveSnippets& obj)
{
	directivesnippets.remove(obj);
}

template<> DnsRrPtr RepositoryIsp::select(const DnsRr& obj)
{
	return dnsrr.select(obj);
}
template<> DnsRrList RepositoryIsp::select(const string& where)
{
	return dnsrr.select(where);
}
template<> int RepositoryIsp::insert(const DnsRr& obj)
{
	return dnsrr.insert(obj);
}
template<> void RepositoryIsp::update(const DnsRr& obj)
{
	dnsrr.update(obj);
}
template<> void RepositoryIsp::update(const DnsRr& oldObj, const DnsRr& newObj)
{
	dnsrr.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const DnsRr& obj)
{
	dnsrr.remove(obj);
}

template<> DnsSlavePtr RepositoryIsp::select(const DnsSlave& obj)
{
	return dnsslave.select(obj);
}
template<> DnsSlaveList RepositoryIsp::select(const string& where)
{
	return dnsslave.select(where);
}
template<> int RepositoryIsp::insert(const DnsSlave& obj)
{
	return dnsslave.insert(obj);
}
template<> void RepositoryIsp::update(const DnsSlave& obj)
{
	dnsslave.update(obj);
}
template<> void RepositoryIsp::update(const DnsSlave& oldObj, const DnsSlave& newObj)
{
	dnsslave.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const DnsSlave& obj)
{
	dnsslave.remove(obj);
}

template<> DnsSoaPtr RepositoryIsp::select(const DnsSoa& obj)
{
	return dnssoa.select(obj);
}
template<> DnsSoaList RepositoryIsp::select(const string& where)
{
	return dnssoa.select(where);
}
template<> int RepositoryIsp::insert(const DnsSoa& obj)
{
	return dnssoa.insert(obj);
}
template<> void RepositoryIsp::update(const DnsSoa& obj)
{
	dnssoa.update(obj);
}
template<> void RepositoryIsp::update(const DnsSoa& oldObj, const DnsSoa& newObj)
{
	dnssoa.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const DnsSoa& obj)
{
	dnssoa.remove(obj);
}

template<> DnsTemplatePtr RepositoryIsp::select(const DnsTemplate& obj)
{
	return dnstemplate.select(obj);
}
template<> DnsTemplateList RepositoryIsp::select(const string& where)
{
	return dnstemplate.select(where);
}
template<> int RepositoryIsp::insert(const DnsTemplate& obj)
{
	return dnstemplate.insert(obj);
}
template<> void RepositoryIsp::update(const DnsTemplate& obj)
{
	dnstemplate.update(obj);
}
template<> void RepositoryIsp::update(const DnsTemplate& oldObj, const DnsTemplate& newObj)
{
	dnstemplate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const DnsTemplate& obj)
{
	dnstemplate.remove(obj);
}

template<> DomainPtr RepositoryIsp::select(const Domain& obj)
{
	return domain.select(obj);
}
template<> DomainList RepositoryIsp::select(const string& where)
{
	return domain.select(where);
}
template<> int RepositoryIsp::insert(const Domain& obj)
{
	return domain.insert(obj);
}
template<> void RepositoryIsp::update(const Domain& obj)
{
	domain.update(obj);
}
template<> void RepositoryIsp::update(const Domain& oldObj, const Domain& newObj)
{
	domain.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Domain& obj)
{
	domain.remove(obj);
}

template<> FirewallPtr RepositoryIsp::select(const Firewall& obj)
{
	return firewall.select(obj);
}
template<> FirewallList RepositoryIsp::select(const string& where)
{
	return firewall.select(where);
}
template<> int RepositoryIsp::insert(const Firewall& obj)
{
	return firewall.insert(obj);
}
template<> void RepositoryIsp::update(const Firewall& obj)
{
	firewall.update(obj);
}
template<> void RepositoryIsp::update(const Firewall& oldObj, const Firewall& newObj)
{
	firewall.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Firewall& obj)
{
	firewall.remove(obj);
}

template<> FtpUserPtr RepositoryIsp::select(const FtpUser& obj)
{
	return ftpuser.select(obj);
}
template<> FtpUserList RepositoryIsp::select(const string& where)
{
	return ftpuser.select(where);
}
template<> int RepositoryIsp::insert(const FtpUser& obj)
{
	return ftpuser.insert(obj);
}
template<> void RepositoryIsp::update(const FtpUser& obj)
{
	ftpuser.update(obj);
}
template<> void RepositoryIsp::update(const FtpUser& oldObj, const FtpUser& newObj)
{
	ftpuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const FtpUser& obj)
{
	ftpuser.remove(obj);
}

template<> HelpFaqPtr RepositoryIsp::select(const HelpFaq& obj)
{
	return helpfaq.select(obj);
}
template<> HelpFaqList RepositoryIsp::select(const string& where)
{
	return helpfaq.select(where);
}
template<> int RepositoryIsp::insert(const HelpFaq& obj)
{
	return helpfaq.insert(obj);
}
template<> void RepositoryIsp::update(const HelpFaq& obj)
{
	helpfaq.update(obj);
}
template<> void RepositoryIsp::update(const HelpFaq& oldObj, const HelpFaq& newObj)
{
	helpfaq.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const HelpFaq& obj)
{
	helpfaq.remove(obj);
}

template<> HelpFaqSectionsPtr RepositoryIsp::select(const HelpFaqSections& obj)
{
	return helpfaqsections.select(obj);
}
template<> HelpFaqSectionsList RepositoryIsp::select(const string& where)
{
	return helpfaqsections.select(where);
}
template<> int RepositoryIsp::insert(const HelpFaqSections& obj)
{
	return helpfaqsections.insert(obj);
}
template<> void RepositoryIsp::update(const HelpFaqSections& obj)
{
	helpfaqsections.update(obj);
}
template<> void RepositoryIsp::update(const HelpFaqSections& oldObj, const HelpFaqSections& newObj)
{
	helpfaqsections.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const HelpFaqSections& obj)
{
	helpfaqsections.remove(obj);
}

template<> IptablesPtr RepositoryIsp::select(const Iptables& obj)
{
	return iptables.select(obj);
}
template<> IptablesList RepositoryIsp::select(const string& where)
{
	return iptables.select(where);
}
template<> int RepositoryIsp::insert(const Iptables& obj)
{
	return iptables.insert(obj);
}
template<> void RepositoryIsp::update(const Iptables& obj)
{
	iptables.update(obj);
}
template<> void RepositoryIsp::update(const Iptables& oldObj, const Iptables& newObj)
{
	iptables.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Iptables& obj)
{
	iptables.remove(obj);
}

template<> MailAccessPtr RepositoryIsp::select(const MailAccess& obj)
{
	return mailaccess.select(obj);
}
template<> MailAccessList RepositoryIsp::select(const string& where)
{
	return mailaccess.select(where);
}
template<> int RepositoryIsp::insert(const MailAccess& obj)
{
	return mailaccess.insert(obj);
}
template<> void RepositoryIsp::update(const MailAccess& obj)
{
	mailaccess.update(obj);
}
template<> void RepositoryIsp::update(const MailAccess& oldObj, const MailAccess& newObj)
{
	mailaccess.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailAccess& obj)
{
	mailaccess.remove(obj);
}

template<> MailBackupPtr RepositoryIsp::select(const MailBackup& obj)
{
	return mailbackup.select(obj);
}
template<> MailBackupList RepositoryIsp::select(const string& where)
{
	return mailbackup.select(where);
}
template<> int RepositoryIsp::insert(const MailBackup& obj)
{
	return mailbackup.insert(obj);
}
template<> void RepositoryIsp::update(const MailBackup& obj)
{
	mailbackup.update(obj);
}
template<> void RepositoryIsp::update(const MailBackup& oldObj, const MailBackup& newObj)
{
	mailbackup.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailBackup& obj)
{
	mailbackup.remove(obj);
}

template<> MailContentFilterPtr RepositoryIsp::select(const MailContentFilter& obj)
{
	return mailcontentfilter.select(obj);
}
template<> MailContentFilterList RepositoryIsp::select(const string& where)
{
	return mailcontentfilter.select(where);
}
template<> int RepositoryIsp::insert(const MailContentFilter& obj)
{
	return mailcontentfilter.insert(obj);
}
template<> void RepositoryIsp::update(const MailContentFilter& obj)
{
	mailcontentfilter.update(obj);
}
template<> void RepositoryIsp::update(const MailContentFilter& oldObj, const MailContentFilter& newObj)
{
	mailcontentfilter.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailContentFilter& obj)
{
	mailcontentfilter.remove(obj);
}

template<> MailDomainPtr RepositoryIsp::select(const MailDomain& obj)
{
	return maildomain.select(obj);
}
template<> MailDomainList RepositoryIsp::select(const string& where)
{
	return maildomain.select(where);
}
template<> int RepositoryIsp::insert(const MailDomain& obj)
{
	return maildomain.insert(obj);
}
template<> void RepositoryIsp::update(const MailDomain& obj)
{
	maildomain.update(obj);
}
template<> void RepositoryIsp::update(const MailDomain& oldObj, const MailDomain& newObj)
{
	maildomain.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailDomain& obj)
{
	maildomain.remove(obj);
}

template<> MailForwardingPtr RepositoryIsp::select(const MailForwarding& obj)
{
	return mailforwarding.select(obj);
}
template<> MailForwardingList RepositoryIsp::select(const string& where)
{
	return mailforwarding.select(where);
}
template<> int RepositoryIsp::insert(const MailForwarding& obj)
{
	return mailforwarding.insert(obj);
}
template<> void RepositoryIsp::update(const MailForwarding& obj)
{
	mailforwarding.update(obj);
}
template<> void RepositoryIsp::update(const MailForwarding& oldObj, const MailForwarding& newObj)
{
	mailforwarding.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailForwarding& obj)
{
	mailforwarding.remove(obj);
}

template<> MailGetPtr RepositoryIsp::select(const MailGet& obj)
{
	return mailget.select(obj);
}
template<> MailGetList RepositoryIsp::select(const string& where)
{
	return mailget.select(where);
}
template<> int RepositoryIsp::insert(const MailGet& obj)
{
	return mailget.insert(obj);
}
template<> void RepositoryIsp::update(const MailGet& obj)
{
	mailget.update(obj);
}
template<> void RepositoryIsp::update(const MailGet& oldObj, const MailGet& newObj)
{
	mailget.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailGet& obj)
{
	mailget.remove(obj);
}

template<> MailMailinglistPtr RepositoryIsp::select(const MailMailinglist& obj)
{
	return mailmailinglist.select(obj);
}
template<> MailMailinglistList RepositoryIsp::select(const string& where)
{
	return mailmailinglist.select(where);
}
template<> int RepositoryIsp::insert(const MailMailinglist& obj)
{
	return mailmailinglist.insert(obj);
}
template<> void RepositoryIsp::update(const MailMailinglist& obj)
{
	mailmailinglist.update(obj);
}
template<> void RepositoryIsp::update(const MailMailinglist& oldObj, const MailMailinglist& newObj)
{
	mailmailinglist.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailMailinglist& obj)
{
	mailmailinglist.remove(obj);
}

template<> MailRelayRecipientPtr RepositoryIsp::select(const MailRelayRecipient& obj)
{
	return mailrelayrecipient.select(obj);
}
template<> MailRelayRecipientList RepositoryIsp::select(const string& where)
{
	return mailrelayrecipient.select(where);
}
template<> int RepositoryIsp::insert(const MailRelayRecipient& obj)
{
	return mailrelayrecipient.insert(obj);
}
template<> void RepositoryIsp::update(const MailRelayRecipient& obj)
{
	mailrelayrecipient.update(obj);
}
template<> void RepositoryIsp::update(const MailRelayRecipient& oldObj, const MailRelayRecipient& newObj)
{
	mailrelayrecipient.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailRelayRecipient& obj)
{
	mailrelayrecipient.remove(obj);
}

template<> MailTrafficPtr RepositoryIsp::select(const MailTraffic& obj)
{
	return mailtraffic.select(obj);
}
template<> MailTrafficList RepositoryIsp::select(const string& where)
{
	return mailtraffic.select(where);
}
template<> int RepositoryIsp::insert(const MailTraffic& obj)
{
	return mailtraffic.insert(obj);
}
template<> void RepositoryIsp::update(const MailTraffic& obj)
{
	mailtraffic.update(obj);
}
template<> void RepositoryIsp::update(const MailTraffic& oldObj, const MailTraffic& newObj)
{
	mailtraffic.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailTraffic& obj)
{
	mailtraffic.remove(obj);
}

template<> MailTransportPtr RepositoryIsp::select(const MailTransport& obj)
{
	return mailtransport.select(obj);
}
template<> MailTransportList RepositoryIsp::select(const string& where)
{
	return mailtransport.select(where);
}
template<> int RepositoryIsp::insert(const MailTransport& obj)
{
	return mailtransport.insert(obj);
}
template<> void RepositoryIsp::update(const MailTransport& obj)
{
	mailtransport.update(obj);
}
template<> void RepositoryIsp::update(const MailTransport& oldObj, const MailTransport& newObj)
{
	mailtransport.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailTransport& obj)
{
	mailtransport.remove(obj);
}

template<> MailUserPtr RepositoryIsp::select(const MailUser& obj)
{
	return mailuser.select(obj);
}
template<> MailUserList RepositoryIsp::select(const string& where)
{
	return mailuser.select(where);
}
template<> int RepositoryIsp::insert(const MailUser& obj)
{
	return mailuser.insert(obj);
}
template<> void RepositoryIsp::update(const MailUser& obj)
{
	mailuser.update(obj);
}
template<> void RepositoryIsp::update(const MailUser& oldObj, const MailUser& newObj)
{
	mailuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailUser& obj)
{
	mailuser.remove(obj);
}

template<> MailUserFilterPtr RepositoryIsp::select(const MailUserFilter& obj)
{
	return mailuserfilter.select(obj);
}
template<> MailUserFilterList RepositoryIsp::select(const string& where)
{
	return mailuserfilter.select(where);
}
template<> int RepositoryIsp::insert(const MailUserFilter& obj)
{
	return mailuserfilter.insert(obj);
}
template<> void RepositoryIsp::update(const MailUserFilter& obj)
{
	mailuserfilter.update(obj);
}
template<> void RepositoryIsp::update(const MailUserFilter& oldObj, const MailUserFilter& newObj)
{
	mailuserfilter.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MailUserFilter& obj)
{
	mailuserfilter.remove(obj);
}

template<> MonitorDataPtr RepositoryIsp::select(const MonitorData& obj)
{
	return monitordata.select(obj);
}
template<> MonitorDataList RepositoryIsp::select(const string& where)
{
	return monitordata.select(where);
}
template<> int RepositoryIsp::insert(const MonitorData& obj)
{
	return monitordata.insert(obj);
}
template<> void RepositoryIsp::update(const MonitorData& obj)
{
	monitordata.update(obj);
}
template<> void RepositoryIsp::update(const MonitorData& oldObj, const MonitorData& newObj)
{
	monitordata.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const MonitorData& obj)
{
	monitordata.remove(obj);
}

template<> OpenvzIpPtr RepositoryIsp::select(const OpenvzIp& obj)
{
	return openvzip.select(obj);
}
template<> OpenvzIpList RepositoryIsp::select(const string& where)
{
	return openvzip.select(where);
}
template<> int RepositoryIsp::insert(const OpenvzIp& obj)
{
	return openvzip.insert(obj);
}
template<> void RepositoryIsp::update(const OpenvzIp& obj)
{
	openvzip.update(obj);
}
template<> void RepositoryIsp::update(const OpenvzIp& oldObj, const OpenvzIp& newObj)
{
	openvzip.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const OpenvzIp& obj)
{
	openvzip.remove(obj);
}

template<> OpenvzOstemplatePtr RepositoryIsp::select(const OpenvzOstemplate& obj)
{
	return openvzostemplate.select(obj);
}
template<> OpenvzOstemplateList RepositoryIsp::select(const string& where)
{
	return openvzostemplate.select(where);
}
template<> int RepositoryIsp::insert(const OpenvzOstemplate& obj)
{
	return openvzostemplate.insert(obj);
}
template<> void RepositoryIsp::update(const OpenvzOstemplate& obj)
{
	openvzostemplate.update(obj);
}
template<> void RepositoryIsp::update(const OpenvzOstemplate& oldObj, const OpenvzOstemplate& newObj)
{
	openvzostemplate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const OpenvzOstemplate& obj)
{
	openvzostemplate.remove(obj);
}

template<> OpenvzTemplatePtr RepositoryIsp::select(const OpenvzTemplate& obj)
{
	return openvztemplate.select(obj);
}
template<> OpenvzTemplateList RepositoryIsp::select(const string& where)
{
	return openvztemplate.select(where);
}
template<> int RepositoryIsp::insert(const OpenvzTemplate& obj)
{
	return openvztemplate.insert(obj);
}
template<> void RepositoryIsp::update(const OpenvzTemplate& obj)
{
	openvztemplate.update(obj);
}
template<> void RepositoryIsp::update(const OpenvzTemplate& oldObj, const OpenvzTemplate& newObj)
{
	openvztemplate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const OpenvzTemplate& obj)
{
	openvztemplate.remove(obj);
}

template<> OpenvzTrafficPtr RepositoryIsp::select(const OpenvzTraffic& obj)
{
	return openvztraffic.select(obj);
}
template<> OpenvzTrafficList RepositoryIsp::select(const string& where)
{
	return openvztraffic.select(where);
}
template<> int RepositoryIsp::insert(const OpenvzTraffic& obj)
{
	return openvztraffic.insert(obj);
}
template<> void RepositoryIsp::update(const OpenvzTraffic& obj)
{
	openvztraffic.update(obj);
}
template<> void RepositoryIsp::update(const OpenvzTraffic& oldObj, const OpenvzTraffic& newObj)
{
	openvztraffic.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const OpenvzTraffic& obj)
{
	openvztraffic.remove(obj);
}

template<> OpenvzVmPtr RepositoryIsp::select(const OpenvzVm& obj)
{
	return openvzvm.select(obj);
}
template<> OpenvzVmList RepositoryIsp::select(const string& where)
{
	return openvzvm.select(where);
}
template<> int RepositoryIsp::insert(const OpenvzVm& obj)
{
	return openvzvm.insert(obj);
}
template<> void RepositoryIsp::update(const OpenvzVm& obj)
{
	openvzvm.update(obj);
}
template<> void RepositoryIsp::update(const OpenvzVm& oldObj, const OpenvzVm& newObj)
{
	openvzvm.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const OpenvzVm& obj)
{
	openvzvm.remove(obj);
}

template<> RemoteSessionPtr RepositoryIsp::select(const RemoteSession& obj)
{
	return remotesession.select(obj);
}
template<> RemoteSessionList RepositoryIsp::select(const string& where)
{
	return remotesession.select(where);
}
template<> int RepositoryIsp::insert(const RemoteSession& obj)
{
	return remotesession.insert(obj);
}
template<> void RepositoryIsp::update(const RemoteSession& obj)
{
	remotesession.update(obj);
}
template<> void RepositoryIsp::update(const RemoteSession& oldObj, const RemoteSession& newObj)
{
	remotesession.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const RemoteSession& obj)
{
	remotesession.remove(obj);
}

template<> RemoteUserPtr RepositoryIsp::select(const RemoteUser& obj)
{
	return remoteuser.select(obj);
}
template<> RemoteUserList RepositoryIsp::select(const string& where)
{
	return remoteuser.select(where);
}
template<> int RepositoryIsp::insert(const RemoteUser& obj)
{
	return remoteuser.insert(obj);
}
template<> void RepositoryIsp::update(const RemoteUser& obj)
{
	remoteuser.update(obj);
}
template<> void RepositoryIsp::update(const RemoteUser& oldObj, const RemoteUser& newObj)
{
	remoteuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const RemoteUser& obj)
{
	remoteuser.remove(obj);
}

template<> ServerPtr RepositoryIsp::select(const Server& obj)
{
	return server.select(obj);
}
template<> ServerList RepositoryIsp::select(const string& where)
{
	return server.select(where);
}
template<> int RepositoryIsp::insert(const Server& obj)
{
	return server.insert(obj);
}
template<> void RepositoryIsp::update(const Server& obj)
{
	server.update(obj);
}
template<> void RepositoryIsp::update(const Server& oldObj, const Server& newObj)
{
	server.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const Server& obj)
{
	server.remove(obj);
}

template<> ServerIpPtr RepositoryIsp::select(const ServerIp& obj)
{
	return serverip.select(obj);
}
template<> ServerIpList RepositoryIsp::select(const string& where)
{
	return serverip.select(where);
}
template<> int RepositoryIsp::insert(const ServerIp& obj)
{
	return serverip.insert(obj);
}
template<> void RepositoryIsp::update(const ServerIp& obj)
{
	serverip.update(obj);
}
template<> void RepositoryIsp::update(const ServerIp& oldObj, const ServerIp& newObj)
{
	serverip.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ServerIp& obj)
{
	serverip.remove(obj);
}

template<> ServerPhpPtr RepositoryIsp::select(const ServerPhp& obj)
{
	return serverphp.select(obj);
}
template<> ServerPhpList RepositoryIsp::select(const string& where)
{
	return serverphp.select(where);
}
template<> int RepositoryIsp::insert(const ServerPhp& obj)
{
	return serverphp.insert(obj);
}
template<> void RepositoryIsp::update(const ServerPhp& obj)
{
	serverphp.update(obj);
}
template<> void RepositoryIsp::update(const ServerPhp& oldObj, const ServerPhp& newObj)
{
	serverphp.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ServerPhp& obj)
{
	serverphp.remove(obj);
}

template<> ShellUserPtr RepositoryIsp::select(const ShellUser& obj)
{
	return shelluser.select(obj);
}
template<> ShellUserList RepositoryIsp::select(const string& where)
{
	return shelluser.select(where);
}
template<> int RepositoryIsp::insert(const ShellUser& obj)
{
	return shelluser.insert(obj);
}
template<> void RepositoryIsp::update(const ShellUser& obj)
{
	shelluser.update(obj);
}
template<> void RepositoryIsp::update(const ShellUser& oldObj, const ShellUser& newObj)
{
	shelluser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const ShellUser& obj)
{
	shelluser.remove(obj);
}

template<> SoftwarePackagePtr RepositoryIsp::select(const SoftwarePackage& obj)
{
	return softwarepackage.select(obj);
}
template<> SoftwarePackageList RepositoryIsp::select(const string& where)
{
	return softwarepackage.select(where);
}
template<> int RepositoryIsp::insert(const SoftwarePackage& obj)
{
	return softwarepackage.insert(obj);
}
template<> void RepositoryIsp::update(const SoftwarePackage& obj)
{
	softwarepackage.update(obj);
}
template<> void RepositoryIsp::update(const SoftwarePackage& oldObj, const SoftwarePackage& newObj)
{
	softwarepackage.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SoftwarePackage& obj)
{
	softwarepackage.remove(obj);
}

template<> SoftwareRepoPtr RepositoryIsp::select(const SoftwareRepo& obj)
{
	return softwarerepo.select(obj);
}
template<> SoftwareRepoList RepositoryIsp::select(const string& where)
{
	return softwarerepo.select(where);
}
template<> int RepositoryIsp::insert(const SoftwareRepo& obj)
{
	return softwarerepo.insert(obj);
}
template<> void RepositoryIsp::update(const SoftwareRepo& obj)
{
	softwarerepo.update(obj);
}
template<> void RepositoryIsp::update(const SoftwareRepo& oldObj, const SoftwareRepo& newObj)
{
	softwarerepo.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SoftwareRepo& obj)
{
	softwarerepo.remove(obj);
}

template<> SoftwareUpdatePtr RepositoryIsp::select(const SoftwareUpdate& obj)
{
	return softwareupdate.select(obj);
}
template<> SoftwareUpdateList RepositoryIsp::select(const string& where)
{
	return softwareupdate.select(where);
}
template<> int RepositoryIsp::insert(const SoftwareUpdate& obj)
{
	return softwareupdate.insert(obj);
}
template<> void RepositoryIsp::update(const SoftwareUpdate& obj)
{
	softwareupdate.update(obj);
}
template<> void RepositoryIsp::update(const SoftwareUpdate& oldObj, const SoftwareUpdate& newObj)
{
	softwareupdate.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SoftwareUpdate& obj)
{
	softwareupdate.remove(obj);
}

template<> SoftwareUpdateInstPtr RepositoryIsp::select(const SoftwareUpdateInst& obj)
{
	return softwareupdateinst.select(obj);
}
template<> SoftwareUpdateInstList RepositoryIsp::select(const string& where)
{
	return softwareupdateinst.select(where);
}
template<> int RepositoryIsp::insert(const SoftwareUpdateInst& obj)
{
	return softwareupdateinst.insert(obj);
}
template<> void RepositoryIsp::update(const SoftwareUpdateInst& obj)
{
	softwareupdateinst.update(obj);
}
template<> void RepositoryIsp::update(const SoftwareUpdateInst& oldObj, const SoftwareUpdateInst& newObj)
{
	softwareupdateinst.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SoftwareUpdateInst& obj)
{
	softwareupdateinst.remove(obj);
}

template<> SpamfilterPolicyPtr RepositoryIsp::select(const SpamfilterPolicy& obj)
{
	return spamfilterpolicy.select(obj);
}
template<> SpamfilterPolicyList RepositoryIsp::select(const string& where)
{
	return spamfilterpolicy.select(where);
}
template<> int RepositoryIsp::insert(const SpamfilterPolicy& obj)
{
	return spamfilterpolicy.insert(obj);
}
template<> void RepositoryIsp::update(const SpamfilterPolicy& obj)
{
	spamfilterpolicy.update(obj);
}
template<> void RepositoryIsp::update(const SpamfilterPolicy& oldObj, const SpamfilterPolicy& newObj)
{
	spamfilterpolicy.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SpamfilterPolicy& obj)
{
	spamfilterpolicy.remove(obj);
}

template<> SpamfilterUsersPtr RepositoryIsp::select(const SpamfilterUsers& obj)
{
	return spamfilterusers.select(obj);
}
template<> SpamfilterUsersList RepositoryIsp::select(const string& where)
{
	return spamfilterusers.select(where);
}
template<> int RepositoryIsp::insert(const SpamfilterUsers& obj)
{
	return spamfilterusers.insert(obj);
}
template<> void RepositoryIsp::update(const SpamfilterUsers& obj)
{
	spamfilterusers.update(obj);
}
template<> void RepositoryIsp::update(const SpamfilterUsers& oldObj, const SpamfilterUsers& newObj)
{
	spamfilterusers.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SpamfilterUsers& obj)
{
	spamfilterusers.remove(obj);
}

template<> SpamfilterWblistPtr RepositoryIsp::select(const SpamfilterWblist& obj)
{
	return spamfilterwblist.select(obj);
}
template<> SpamfilterWblistList RepositoryIsp::select(const string& where)
{
	return spamfilterwblist.select(where);
}
template<> int RepositoryIsp::insert(const SpamfilterWblist& obj)
{
	return spamfilterwblist.insert(obj);
}
template<> void RepositoryIsp::update(const SpamfilterWblist& obj)
{
	spamfilterwblist.update(obj);
}
template<> void RepositoryIsp::update(const SpamfilterWblist& oldObj, const SpamfilterWblist& newObj)
{
	spamfilterwblist.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SpamfilterWblist& obj)
{
	spamfilterwblist.remove(obj);
}

template<> SupportMessagePtr RepositoryIsp::select(const SupportMessage& obj)
{
	return supportmessage.select(obj);
}
template<> SupportMessageList RepositoryIsp::select(const string& where)
{
	return supportmessage.select(where);
}
template<> int RepositoryIsp::insert(const SupportMessage& obj)
{
	return supportmessage.insert(obj);
}
template<> void RepositoryIsp::update(const SupportMessage& obj)
{
	supportmessage.update(obj);
}
template<> void RepositoryIsp::update(const SupportMessage& oldObj, const SupportMessage& newObj)
{
	supportmessage.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SupportMessage& obj)
{
	supportmessage.remove(obj);
}

template<> SysConfigPtr RepositoryIsp::select(const SysConfig& obj)
{
	return sysconfig.select(obj);
}
template<> SysConfigList RepositoryIsp::select(const string& where)
{
	return sysconfig.select(where);
}
template<> int RepositoryIsp::insert(const SysConfig& obj)
{
	return sysconfig.insert(obj);
}
template<> void RepositoryIsp::update(const SysConfig& obj)
{
	sysconfig.update(obj);
}
template<> void RepositoryIsp::update(const SysConfig& oldObj, const SysConfig& newObj)
{
	sysconfig.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysConfig& obj)
{
	sysconfig.remove(obj);
}

template<> SysCronPtr RepositoryIsp::select(const SysCron& obj)
{
	return syscron.select(obj);
}
template<> SysCronList RepositoryIsp::select(const string& where)
{
	return syscron.select(where);
}
template<> int RepositoryIsp::insert(const SysCron& obj)
{
	return syscron.insert(obj);
}
template<> void RepositoryIsp::update(const SysCron& obj)
{
	syscron.update(obj);
}
template<> void RepositoryIsp::update(const SysCron& oldObj, const SysCron& newObj)
{
	syscron.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysCron& obj)
{
	syscron.remove(obj);
}

template<> SysDatalogPtr RepositoryIsp::select(const SysDatalog& obj)
{
	return sysdatalog.select(obj);
}
template<> SysDatalogList RepositoryIsp::select(const string& where)
{
	return sysdatalog.select(where);
}
template<> int RepositoryIsp::insert(const SysDatalog& obj)
{
	return sysdatalog.insert(obj);
}
template<> void RepositoryIsp::update(const SysDatalog& obj)
{
	sysdatalog.update(obj);
}
template<> void RepositoryIsp::update(const SysDatalog& oldObj, const SysDatalog& newObj)
{
	sysdatalog.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysDatalog& obj)
{
	sysdatalog.remove(obj);
}

template<> SysDbsyncPtr RepositoryIsp::select(const SysDbsync& obj)
{
	return sysdbsync.select(obj);
}
template<> SysDbsyncList RepositoryIsp::select(const string& where)
{
	return sysdbsync.select(where);
}
template<> int RepositoryIsp::insert(const SysDbsync& obj)
{
	return sysdbsync.insert(obj);
}
template<> void RepositoryIsp::update(const SysDbsync& obj)
{
	sysdbsync.update(obj);
}
template<> void RepositoryIsp::update(const SysDbsync& oldObj, const SysDbsync& newObj)
{
	sysdbsync.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysDbsync& obj)
{
	sysdbsync.remove(obj);
}

template<> SysFilesyncPtr RepositoryIsp::select(const SysFilesync& obj)
{
	return sysfilesync.select(obj);
}
template<> SysFilesyncList RepositoryIsp::select(const string& where)
{
	return sysfilesync.select(where);
}
template<> int RepositoryIsp::insert(const SysFilesync& obj)
{
	return sysfilesync.insert(obj);
}
template<> void RepositoryIsp::update(const SysFilesync& obj)
{
	sysfilesync.update(obj);
}
template<> void RepositoryIsp::update(const SysFilesync& oldObj, const SysFilesync& newObj)
{
	sysfilesync.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysFilesync& obj)
{
	sysfilesync.remove(obj);
}

template<> SysGroupPtr RepositoryIsp::select(const SysGroup& obj)
{
	return sysgroup.select(obj);
}
template<> SysGroupList RepositoryIsp::select(const string& where)
{
	return sysgroup.select(where);
}
template<> int RepositoryIsp::insert(const SysGroup& obj)
{
	return sysgroup.insert(obj);
}
template<> void RepositoryIsp::update(const SysGroup& obj)
{
	sysgroup.update(obj);
}
template<> void RepositoryIsp::update(const SysGroup& oldObj, const SysGroup& newObj)
{
	sysgroup.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysGroup& obj)
{
	sysgroup.remove(obj);
}

template<> SysIniPtr RepositoryIsp::select(const SysIni& obj)
{
	return sysini.select(obj);
}
template<> SysIniList RepositoryIsp::select(const string& where)
{
	return sysini.select(where);
}
template<> int RepositoryIsp::insert(const SysIni& obj)
{
	return sysini.insert(obj);
}
template<> void RepositoryIsp::update(const SysIni& obj)
{
	sysini.update(obj);
}
template<> void RepositoryIsp::update(const SysIni& oldObj, const SysIni& newObj)
{
	sysini.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysIni& obj)
{
	sysini.remove(obj);
}

template<> SysLogPtr RepositoryIsp::select(const SysLog& obj)
{
	return syslog.select(obj);
}
template<> SysLogList RepositoryIsp::select(const string& where)
{
	return syslog.select(where);
}
template<> int RepositoryIsp::insert(const SysLog& obj)
{
	return syslog.insert(obj);
}
template<> void RepositoryIsp::update(const SysLog& obj)
{
	syslog.update(obj);
}
template<> void RepositoryIsp::update(const SysLog& oldObj, const SysLog& newObj)
{
	syslog.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysLog& obj)
{
	syslog.remove(obj);
}

template<> SysRemoteactionPtr RepositoryIsp::select(const SysRemoteaction& obj)
{
	return sysremoteaction.select(obj);
}
template<> SysRemoteactionList RepositoryIsp::select(const string& where)
{
	return sysremoteaction.select(where);
}
template<> int RepositoryIsp::insert(const SysRemoteaction& obj)
{
	return sysremoteaction.insert(obj);
}
template<> void RepositoryIsp::update(const SysRemoteaction& obj)
{
	sysremoteaction.update(obj);
}
template<> void RepositoryIsp::update(const SysRemoteaction& oldObj, const SysRemoteaction& newObj)
{
	sysremoteaction.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysRemoteaction& obj)
{
	sysremoteaction.remove(obj);
}

template<> SysSessionPtr RepositoryIsp::select(const SysSession& obj)
{
	return syssession.select(obj);
}
template<> SysSessionList RepositoryIsp::select(const string& where)
{
	return syssession.select(where);
}
template<> int RepositoryIsp::insert(const SysSession& obj)
{
	return syssession.insert(obj);
}
template<> void RepositoryIsp::update(const SysSession& obj)
{
	syssession.update(obj);
}
template<> void RepositoryIsp::update(const SysSession& oldObj, const SysSession& newObj)
{
	syssession.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysSession& obj)
{
	syssession.remove(obj);
}

template<> SysThemePtr RepositoryIsp::select(const SysTheme& obj)
{
	return systheme.select(obj);
}
template<> SysThemeList RepositoryIsp::select(const string& where)
{
	return systheme.select(where);
}
template<> int RepositoryIsp::insert(const SysTheme& obj)
{
	return systheme.insert(obj);
}
template<> void RepositoryIsp::update(const SysTheme& obj)
{
	systheme.update(obj);
}
template<> void RepositoryIsp::update(const SysTheme& oldObj, const SysTheme& newObj)
{
	systheme.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysTheme& obj)
{
	systheme.remove(obj);
}

template<> SysUserPtr RepositoryIsp::select(const SysUser& obj)
{
	return sysuser.select(obj);
}
template<> SysUserList RepositoryIsp::select(const string& where)
{
	return sysuser.select(where);
}
template<> int RepositoryIsp::insert(const SysUser& obj)
{
	return sysuser.insert(obj);
}
template<> void RepositoryIsp::update(const SysUser& obj)
{
	sysuser.update(obj);
}
template<> void RepositoryIsp::update(const SysUser& oldObj, const SysUser& newObj)
{
	sysuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const SysUser& obj)
{
	sysuser.remove(obj);
}

template<> WebBackupPtr RepositoryIsp::select(const WebBackup& obj)
{
	return webbackup.select(obj);
}
template<> WebBackupList RepositoryIsp::select(const string& where)
{
	return webbackup.select(where);
}
template<> int RepositoryIsp::insert(const WebBackup& obj)
{
	return webbackup.insert(obj);
}
template<> void RepositoryIsp::update(const WebBackup& obj)
{
	webbackup.update(obj);
}
template<> void RepositoryIsp::update(const WebBackup& oldObj, const WebBackup& newObj)
{
	webbackup.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebBackup& obj)
{
	webbackup.remove(obj);
}

template<> WebDatabasePtr RepositoryIsp::select(const WebDatabase& obj)
{
	return webdatabase.select(obj);
}
template<> WebDatabaseList RepositoryIsp::select(const string& where)
{
	return webdatabase.select(where);
}
template<> int RepositoryIsp::insert(const WebDatabase& obj)
{
	return webdatabase.insert(obj);
}
template<> void RepositoryIsp::update(const WebDatabase& obj)
{
	webdatabase.update(obj);
}
template<> void RepositoryIsp::update(const WebDatabase& oldObj, const WebDatabase& newObj)
{
	webdatabase.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebDatabase& obj)
{
	webdatabase.remove(obj);
}

template<> WebDatabaseUserPtr RepositoryIsp::select(const WebDatabaseUser& obj)
{
	return webdatabaseuser.select(obj);
}
template<> WebDatabaseUserList RepositoryIsp::select(const string& where)
{
	return webdatabaseuser.select(where);
}
template<> int RepositoryIsp::insert(const WebDatabaseUser& obj)
{
	return webdatabaseuser.insert(obj);
}
template<> void RepositoryIsp::update(const WebDatabaseUser& obj)
{
	webdatabaseuser.update(obj);
}
template<> void RepositoryIsp::update(const WebDatabaseUser& oldObj, const WebDatabaseUser& newObj)
{
	webdatabaseuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebDatabaseUser& obj)
{
	webdatabaseuser.remove(obj);
}

template<> WebDomainPtr RepositoryIsp::select(const WebDomain& obj)
{
	return webdomain.select(obj);
}
template<> WebDomainList RepositoryIsp::select(const string& where)
{
	return webdomain.select(where);
}
template<> int RepositoryIsp::insert(const WebDomain& obj)
{
	return webdomain.insert(obj);
}
template<> void RepositoryIsp::update(const WebDomain& obj)
{
	webdomain.update(obj);
}
template<> void RepositoryIsp::update(const WebDomain& oldObj, const WebDomain& newObj)
{
	webdomain.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebDomain& obj)
{
	webdomain.remove(obj);
}

template<> WebFolderPtr RepositoryIsp::select(const WebFolder& obj)
{
	return webfolder.select(obj);
}
template<> WebFolderList RepositoryIsp::select(const string& where)
{
	return webfolder.select(where);
}
template<> int RepositoryIsp::insert(const WebFolder& obj)
{
	return webfolder.insert(obj);
}
template<> void RepositoryIsp::update(const WebFolder& obj)
{
	webfolder.update(obj);
}
template<> void RepositoryIsp::update(const WebFolder& oldObj, const WebFolder& newObj)
{
	webfolder.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebFolder& obj)
{
	webfolder.remove(obj);
}

template<> WebFolderUserPtr RepositoryIsp::select(const WebFolderUser& obj)
{
	return webfolderuser.select(obj);
}
template<> WebFolderUserList RepositoryIsp::select(const string& where)
{
	return webfolderuser.select(where);
}
template<> int RepositoryIsp::insert(const WebFolderUser& obj)
{
	return webfolderuser.insert(obj);
}
template<> void RepositoryIsp::update(const WebFolderUser& obj)
{
	webfolderuser.update(obj);
}
template<> void RepositoryIsp::update(const WebFolderUser& oldObj, const WebFolderUser& newObj)
{
	webfolderuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebFolderUser& obj)
{
	webfolderuser.remove(obj);
}

template<> WebTrafficPtr RepositoryIsp::select(const WebTraffic& obj)
{
	return webtraffic.select(obj);
}
template<> WebTrafficList RepositoryIsp::select(const string& where)
{
	return webtraffic.select(where);
}
template<> int RepositoryIsp::insert(const WebTraffic& obj)
{
	return webtraffic.insert(obj);
}
template<> void RepositoryIsp::update(const WebTraffic& obj)
{
	webtraffic.update(obj);
}
template<> void RepositoryIsp::update(const WebTraffic& oldObj, const WebTraffic& newObj)
{
	webtraffic.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebTraffic& obj)
{
	webtraffic.remove(obj);
}

template<> WebdavUserPtr RepositoryIsp::select(const WebdavUser& obj)
{
	return webdavuser.select(obj);
}
template<> WebdavUserList RepositoryIsp::select(const string& where)
{
	return webdavuser.select(where);
}
template<> int RepositoryIsp::insert(const WebdavUser& obj)
{
	return webdavuser.insert(obj);
}
template<> void RepositoryIsp::update(const WebdavUser& obj)
{
	webdavuser.update(obj);
}
template<> void RepositoryIsp::update(const WebdavUser& oldObj, const WebdavUser& newObj)
{
	webdavuser.update(oldObj, newObj);
}
template<> void RepositoryIsp::remove(const WebdavUser& obj)
{
	webdavuser.remove(obj);
}
