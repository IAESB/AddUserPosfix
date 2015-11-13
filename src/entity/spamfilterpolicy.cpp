#include "spamfilterpolicy.h"

SpamfilterPolicy::SpamfilterPolicy(){
	init();
}
SpamfilterPolicy::SpamfilterPolicy(long long id)
{
	init();
	this->id = id;
}

void SpamfilterPolicy::init()
{
}
long long SpamfilterPolicy::getId() const
{
	return id;
}
void SpamfilterPolicy::setId(long long value)
{
	id = value;
}
long long SpamfilterPolicy::getSysUserid() const
{
	return sys_userid;
}
void SpamfilterPolicy::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SpamfilterPolicy::getSysGroupid() const
{
	return sys_groupid;
}
void SpamfilterPolicy::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SpamfilterPolicy::getSysPermUser() const
{
	return sys_perm_user;
}
void SpamfilterPolicy::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SpamfilterPolicy::getSysPermGroup() const
{
	return sys_perm_group;
}
void SpamfilterPolicy::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SpamfilterPolicy::getSysPermOther() const
{
	return sys_perm_other;
}
void SpamfilterPolicy::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string SpamfilterPolicy::getPolicyName() const
{
	return policy_name;
}
void SpamfilterPolicy::setPolicyName(std::string value)
{
	policy_name = value;
}
std::string SpamfilterPolicy::getVirusLover() const
{
	return virus_lover;
}
void SpamfilterPolicy::setVirusLover(std::string value)
{
	virus_lover = value;
}
std::string SpamfilterPolicy::getSpamLover() const
{
	return spam_lover;
}
void SpamfilterPolicy::setSpamLover(std::string value)
{
	spam_lover = value;
}
std::string SpamfilterPolicy::getBannedFilesLover() const
{
	return banned_files_lover;
}
void SpamfilterPolicy::setBannedFilesLover(std::string value)
{
	banned_files_lover = value;
}
std::string SpamfilterPolicy::getBadHeaderLover() const
{
	return bad_header_lover;
}
void SpamfilterPolicy::setBadHeaderLover(std::string value)
{
	bad_header_lover = value;
}
std::string SpamfilterPolicy::getBypassVirusChecks() const
{
	return bypass_virus_checks;
}
void SpamfilterPolicy::setBypassVirusChecks(std::string value)
{
	bypass_virus_checks = value;
}
std::string SpamfilterPolicy::getBypassSpamChecks() const
{
	return bypass_spam_checks;
}
void SpamfilterPolicy::setBypassSpamChecks(std::string value)
{
	bypass_spam_checks = value;
}
std::string SpamfilterPolicy::getBypassBannedChecks() const
{
	return bypass_banned_checks;
}
void SpamfilterPolicy::setBypassBannedChecks(std::string value)
{
	bypass_banned_checks = value;
}
std::string SpamfilterPolicy::getBypassHeaderChecks() const
{
	return bypass_header_checks;
}
void SpamfilterPolicy::setBypassHeaderChecks(std::string value)
{
	bypass_header_checks = value;
}
std::string SpamfilterPolicy::getSpamModifiesSubj() const
{
	return spam_modifies_subj;
}
void SpamfilterPolicy::setSpamModifiesSubj(std::string value)
{
	spam_modifies_subj = value;
}
std::string SpamfilterPolicy::getVirusQuarantineTo() const
{
	return virus_quarantine_to;
}
void SpamfilterPolicy::setVirusQuarantineTo(std::string value)
{
	virus_quarantine_to = value;
}
std::string SpamfilterPolicy::getSpamQuarantineTo() const
{
	return spam_quarantine_to;
}
void SpamfilterPolicy::setSpamQuarantineTo(std::string value)
{
	spam_quarantine_to = value;
}
std::string SpamfilterPolicy::getBannedQuarantineTo() const
{
	return banned_quarantine_to;
}
void SpamfilterPolicy::setBannedQuarantineTo(std::string value)
{
	banned_quarantine_to = value;
}
std::string SpamfilterPolicy::getBadHeaderQuarantineTo() const
{
	return bad_header_quarantine_to;
}
void SpamfilterPolicy::setBadHeaderQuarantineTo(std::string value)
{
	bad_header_quarantine_to = value;
}
std::string SpamfilterPolicy::getCleanQuarantineTo() const
{
	return clean_quarantine_to;
}
void SpamfilterPolicy::setCleanQuarantineTo(std::string value)
{
	clean_quarantine_to = value;
}
std::string SpamfilterPolicy::getOtherQuarantineTo() const
{
	return other_quarantine_to;
}
void SpamfilterPolicy::setOtherQuarantineTo(std::string value)
{
	other_quarantine_to = value;
}
double SpamfilterPolicy::getSpamTagLevel() const
{
	return spam_tag_level;
}
void SpamfilterPolicy::setSpamTagLevel(double value)
{
	spam_tag_level = value;
}
double SpamfilterPolicy::getSpamTag2Level() const
{
	return spam_tag2_level;
}
void SpamfilterPolicy::setSpamTag2Level(double value)
{
	spam_tag2_level = value;
}
double SpamfilterPolicy::getSpamKillLevel() const
{
	return spam_kill_level;
}
void SpamfilterPolicy::setSpamKillLevel(double value)
{
	spam_kill_level = value;
}
double SpamfilterPolicy::getSpamDsnCutoffLevel() const
{
	return spam_dsn_cutoff_level;
}
void SpamfilterPolicy::setSpamDsnCutoffLevel(double value)
{
	spam_dsn_cutoff_level = value;
}
double SpamfilterPolicy::getSpamQuarantineCutoffLevel() const
{
	return spam_quarantine_cutoff_level;
}
void SpamfilterPolicy::setSpamQuarantineCutoffLevel(double value)
{
	spam_quarantine_cutoff_level = value;
}
std::string SpamfilterPolicy::getAddrExtensionVirus() const
{
	return addr_extension_virus;
}
void SpamfilterPolicy::setAddrExtensionVirus(std::string value)
{
	addr_extension_virus = value;
}
std::string SpamfilterPolicy::getAddrExtensionSpam() const
{
	return addr_extension_spam;
}
void SpamfilterPolicy::setAddrExtensionSpam(std::string value)
{
	addr_extension_spam = value;
}
std::string SpamfilterPolicy::getAddrExtensionBanned() const
{
	return addr_extension_banned;
}
void SpamfilterPolicy::setAddrExtensionBanned(std::string value)
{
	addr_extension_banned = value;
}
std::string SpamfilterPolicy::getAddrExtensionBadHeader() const
{
	return addr_extension_bad_header;
}
void SpamfilterPolicy::setAddrExtensionBadHeader(std::string value)
{
	addr_extension_bad_header = value;
}
std::string SpamfilterPolicy::getWarnvirusrecip() const
{
	return warnvirusrecip;
}
void SpamfilterPolicy::setWarnvirusrecip(std::string value)
{
	warnvirusrecip = value;
}
std::string SpamfilterPolicy::getWarnbannedrecip() const
{
	return warnbannedrecip;
}
void SpamfilterPolicy::setWarnbannedrecip(std::string value)
{
	warnbannedrecip = value;
}
std::string SpamfilterPolicy::getWarnbadhrecip() const
{
	return warnbadhrecip;
}
void SpamfilterPolicy::setWarnbadhrecip(std::string value)
{
	warnbadhrecip = value;
}
std::string SpamfilterPolicy::getNewvirusAdmin() const
{
	return newvirus_admin;
}
void SpamfilterPolicy::setNewvirusAdmin(std::string value)
{
	newvirus_admin = value;
}
std::string SpamfilterPolicy::getVirusAdmin() const
{
	return virus_admin;
}
void SpamfilterPolicy::setVirusAdmin(std::string value)
{
	virus_admin = value;
}
std::string SpamfilterPolicy::getBannedAdmin() const
{
	return banned_admin;
}
void SpamfilterPolicy::setBannedAdmin(std::string value)
{
	banned_admin = value;
}
std::string SpamfilterPolicy::getBadHeaderAdmin() const
{
	return bad_header_admin;
}
void SpamfilterPolicy::setBadHeaderAdmin(std::string value)
{
	bad_header_admin = value;
}
std::string SpamfilterPolicy::getSpamAdmin() const
{
	return spam_admin;
}
void SpamfilterPolicy::setSpamAdmin(std::string value)
{
	spam_admin = value;
}
std::string SpamfilterPolicy::getSpamSubjectTag() const
{
	return spam_subject_tag;
}
void SpamfilterPolicy::setSpamSubjectTag(std::string value)
{
	spam_subject_tag = value;
}
std::string SpamfilterPolicy::getSpamSubjectTag2() const
{
	return spam_subject_tag2;
}
void SpamfilterPolicy::setSpamSubjectTag2(std::string value)
{
	spam_subject_tag2 = value;
}
long long SpamfilterPolicy::getMessageSizeLimit() const
{
	return message_size_limit;
}
void SpamfilterPolicy::setMessageSizeLimit(long long value)
{
	message_size_limit = value;
}
std::string SpamfilterPolicy::getBannedRulenames() const
{
	return banned_rulenames;
}
void SpamfilterPolicy::setBannedRulenames(std::string value)
{
	banned_rulenames = value;
}
int SpamfilterPolicy::getPolicydQuotaIn() const
{
	return policyd_quota_in;
}
void SpamfilterPolicy::setPolicydQuotaIn(int value)
{
	policyd_quota_in = value;
}
int SpamfilterPolicy::getPolicydQuotaInPeriod() const
{
	return policyd_quota_in_period;
}
void SpamfilterPolicy::setPolicydQuotaInPeriod(int value)
{
	policyd_quota_in_period = value;
}
int SpamfilterPolicy::getPolicydQuotaOut() const
{
	return policyd_quota_out;
}
void SpamfilterPolicy::setPolicydQuotaOut(int value)
{
	policyd_quota_out = value;
}
int SpamfilterPolicy::getPolicydQuotaOutPeriod() const
{
	return policyd_quota_out_period;
}
void SpamfilterPolicy::setPolicydQuotaOutPeriod(int value)
{
	policyd_quota_out_period = value;
}
std::string SpamfilterPolicy::getPolicydGreylist() const
{
	return policyd_greylist;
}
void SpamfilterPolicy::setPolicydGreylist(std::string value)
{
	policyd_greylist = value;
}

