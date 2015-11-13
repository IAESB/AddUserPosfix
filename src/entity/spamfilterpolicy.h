#ifndef SPAMFILTERPOLICY_H
#define SPAMFILTERPOLICY_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SpamfilterPolicy;
typedef shared_ptr<SpamfilterPolicy> SpamfilterPolicyPtr;
typedef vector<SpamfilterPolicyPtr> SpamfilterPolicyList;

class SpamfilterPolicy
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string policy_name;
	std::string virus_lover;
	std::string spam_lover;
	std::string banned_files_lover;
	std::string bad_header_lover;
	std::string bypass_virus_checks;
	std::string bypass_spam_checks;
	std::string bypass_banned_checks;
	std::string bypass_header_checks;
	std::string spam_modifies_subj;
	std::string virus_quarantine_to;
	std::string spam_quarantine_to;
	std::string banned_quarantine_to;
	std::string bad_header_quarantine_to;
	std::string clean_quarantine_to;
	std::string other_quarantine_to;
	double spam_tag_level;
	double spam_tag2_level;
	double spam_kill_level;
	double spam_dsn_cutoff_level;
	double spam_quarantine_cutoff_level;
	std::string addr_extension_virus;
	std::string addr_extension_spam;
	std::string addr_extension_banned;
	std::string addr_extension_bad_header;
	std::string warnvirusrecip;
	std::string warnbannedrecip;
	std::string warnbadhrecip;
	std::string newvirus_admin;
	std::string virus_admin;
	std::string banned_admin;
	std::string bad_header_admin;
	std::string spam_admin;
	std::string spam_subject_tag;
	std::string spam_subject_tag2;
	long long message_size_limit;
	std::string banned_rulenames;
	int policyd_quota_in;
	int policyd_quota_in_period;
	int policyd_quota_out;
	int policyd_quota_out_period;
	std::string policyd_greylist;
public:
	SpamfilterPolicy();
	SpamfilterPolicy(long long id);
	void init();
	long long getId() const;
	void setId(long long value);
	long long getSysUserid() const;
	void setSysUserid(long long value);
	long long getSysGroupid() const;
	void setSysGroupid(long long value);
	std::string getSysPermUser() const;
	void setSysPermUser(std::string value);
	std::string getSysPermGroup() const;
	void setSysPermGroup(std::string value);
	std::string getSysPermOther() const;
	void setSysPermOther(std::string value);
	std::string getPolicyName() const;
	void setPolicyName(std::string value);
	std::string getVirusLover() const;
	void setVirusLover(std::string value);
	std::string getSpamLover() const;
	void setSpamLover(std::string value);
	std::string getBannedFilesLover() const;
	void setBannedFilesLover(std::string value);
	std::string getBadHeaderLover() const;
	void setBadHeaderLover(std::string value);
	std::string getBypassVirusChecks() const;
	void setBypassVirusChecks(std::string value);
	std::string getBypassSpamChecks() const;
	void setBypassSpamChecks(std::string value);
	std::string getBypassBannedChecks() const;
	void setBypassBannedChecks(std::string value);
	std::string getBypassHeaderChecks() const;
	void setBypassHeaderChecks(std::string value);
	std::string getSpamModifiesSubj() const;
	void setSpamModifiesSubj(std::string value);
	std::string getVirusQuarantineTo() const;
	void setVirusQuarantineTo(std::string value);
	std::string getSpamQuarantineTo() const;
	void setSpamQuarantineTo(std::string value);
	std::string getBannedQuarantineTo() const;
	void setBannedQuarantineTo(std::string value);
	std::string getBadHeaderQuarantineTo() const;
	void setBadHeaderQuarantineTo(std::string value);
	std::string getCleanQuarantineTo() const;
	void setCleanQuarantineTo(std::string value);
	std::string getOtherQuarantineTo() const;
	void setOtherQuarantineTo(std::string value);
	double getSpamTagLevel() const;
	void setSpamTagLevel(double value);
	double getSpamTag2Level() const;
	void setSpamTag2Level(double value);
	double getSpamKillLevel() const;
	void setSpamKillLevel(double value);
	double getSpamDsnCutoffLevel() const;
	void setSpamDsnCutoffLevel(double value);
	double getSpamQuarantineCutoffLevel() const;
	void setSpamQuarantineCutoffLevel(double value);
	std::string getAddrExtensionVirus() const;
	void setAddrExtensionVirus(std::string value);
	std::string getAddrExtensionSpam() const;
	void setAddrExtensionSpam(std::string value);
	std::string getAddrExtensionBanned() const;
	void setAddrExtensionBanned(std::string value);
	std::string getAddrExtensionBadHeader() const;
	void setAddrExtensionBadHeader(std::string value);
	std::string getWarnvirusrecip() const;
	void setWarnvirusrecip(std::string value);
	std::string getWarnbannedrecip() const;
	void setWarnbannedrecip(std::string value);
	std::string getWarnbadhrecip() const;
	void setWarnbadhrecip(std::string value);
	std::string getNewvirusAdmin() const;
	void setNewvirusAdmin(std::string value);
	std::string getVirusAdmin() const;
	void setVirusAdmin(std::string value);
	std::string getBannedAdmin() const;
	void setBannedAdmin(std::string value);
	std::string getBadHeaderAdmin() const;
	void setBadHeaderAdmin(std::string value);
	std::string getSpamAdmin() const;
	void setSpamAdmin(std::string value);
	std::string getSpamSubjectTag() const;
	void setSpamSubjectTag(std::string value);
	std::string getSpamSubjectTag2() const;
	void setSpamSubjectTag2(std::string value);
	long long getMessageSizeLimit() const;
	void setMessageSizeLimit(long long value);
	std::string getBannedRulenames() const;
	void setBannedRulenames(std::string value);
	int getPolicydQuotaIn() const;
	void setPolicydQuotaIn(int value);
	int getPolicydQuotaInPeriod() const;
	void setPolicydQuotaInPeriod(int value);
	int getPolicydQuotaOut() const;
	void setPolicydQuotaOut(int value);
	int getPolicydQuotaOutPeriod() const;
	void setPolicydQuotaOutPeriod(int value);
	std::string getPolicydGreylist() const;
	void setPolicydGreylist(std::string value);
};



#endif // SPAMFILTERPOLICY_H
