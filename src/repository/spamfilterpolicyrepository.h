#ifndef SPAMFILTERPOLICYREPOSITORY_H
#define SPAMFILTERPOLICYREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/spamfilterpolicy.h"
using namespace soci;


class SpamfilterPolicyRepository
{
	soci::session& dataBase;
public:
	SpamfilterPolicyRepository(soci::session& dataBase);
	int insert(const SpamfilterPolicy& spamfilterpolicy);
	SpamfilterPolicyPtr select(const SpamfilterPolicy& spamfilterpolicy);
	SpamfilterPolicyList select(const string& where="");
	void update(const SpamfilterPolicy& spamfilterpolicy);
	void update(const SpamfilterPolicy& oldObj, const SpamfilterPolicy& newObj);
	void remove(const SpamfilterPolicy& spamfilterpolicy);
};

namespace soci
{
template<>
struct type_conversion<SpamfilterPolicy>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SpamfilterPolicy & p)
	{
		if (v.get_indicator("SpamfilterPolicy_id") != i_null){
			p.setId( v.template get<long long>("SpamfilterPolicy_id" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SpamfilterPolicy_sys_userid" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SpamfilterPolicy_sys_groupid" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SpamfilterPolicy_sys_perm_user" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SpamfilterPolicy_sys_perm_group" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SpamfilterPolicy_sys_perm_other" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policy_name") != i_null){
			p.setPolicyName( v.template get<std::string>("SpamfilterPolicy_policy_name" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_virus_lover") != i_null){
			p.setVirusLover( v.template get<std::string>("SpamfilterPolicy_virus_lover" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_lover") != i_null){
			p.setSpamLover( v.template get<std::string>("SpamfilterPolicy_spam_lover" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_banned_files_lover") != i_null){
			p.setBannedFilesLover( v.template get<std::string>("SpamfilterPolicy_banned_files_lover" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bad_header_lover") != i_null){
			p.setBadHeaderLover( v.template get<std::string>("SpamfilterPolicy_bad_header_lover" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bypass_virus_checks") != i_null){
			p.setBypassVirusChecks( v.template get<std::string>("SpamfilterPolicy_bypass_virus_checks" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bypass_spam_checks") != i_null){
			p.setBypassSpamChecks( v.template get<std::string>("SpamfilterPolicy_bypass_spam_checks" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bypass_banned_checks") != i_null){
			p.setBypassBannedChecks( v.template get<std::string>("SpamfilterPolicy_bypass_banned_checks" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bypass_header_checks") != i_null){
			p.setBypassHeaderChecks( v.template get<std::string>("SpamfilterPolicy_bypass_header_checks" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_modifies_subj") != i_null){
			p.setSpamModifiesSubj( v.template get<std::string>("SpamfilterPolicy_spam_modifies_subj" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_virus_quarantine_to") != i_null){
			p.setVirusQuarantineTo( v.template get<std::string>("SpamfilterPolicy_virus_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_quarantine_to") != i_null){
			p.setSpamQuarantineTo( v.template get<std::string>("SpamfilterPolicy_spam_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_banned_quarantine_to") != i_null){
			p.setBannedQuarantineTo( v.template get<std::string>("SpamfilterPolicy_banned_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bad_header_quarantine_to") != i_null){
			p.setBadHeaderQuarantineTo( v.template get<std::string>("SpamfilterPolicy_bad_header_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_clean_quarantine_to") != i_null){
			p.setCleanQuarantineTo( v.template get<std::string>("SpamfilterPolicy_clean_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_other_quarantine_to") != i_null){
			p.setOtherQuarantineTo( v.template get<std::string>("SpamfilterPolicy_other_quarantine_to" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_tag_level") != i_null){
			p.setSpamTagLevel( v.template get<double>("SpamfilterPolicy_spam_tag_level" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_tag2_level") != i_null){
			p.setSpamTag2Level( v.template get<double>("SpamfilterPolicy_spam_tag2_level" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_kill_level") != i_null){
			p.setSpamKillLevel( v.template get<double>("SpamfilterPolicy_spam_kill_level" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_dsn_cutoff_level") != i_null){
			p.setSpamDsnCutoffLevel( v.template get<double>("SpamfilterPolicy_spam_dsn_cutoff_level" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_quarantine_cutoff_level") != i_null){
			p.setSpamQuarantineCutoffLevel( v.template get<double>("SpamfilterPolicy_spam_quarantine_cutoff_level" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_addr_extension_virus") != i_null){
			p.setAddrExtensionVirus( v.template get<std::string>("SpamfilterPolicy_addr_extension_virus" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_addr_extension_spam") != i_null){
			p.setAddrExtensionSpam( v.template get<std::string>("SpamfilterPolicy_addr_extension_spam" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_addr_extension_banned") != i_null){
			p.setAddrExtensionBanned( v.template get<std::string>("SpamfilterPolicy_addr_extension_banned" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_addr_extension_bad_header") != i_null){
			p.setAddrExtensionBadHeader( v.template get<std::string>("SpamfilterPolicy_addr_extension_bad_header" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_warnvirusrecip") != i_null){
			p.setWarnvirusrecip( v.template get<std::string>("SpamfilterPolicy_warnvirusrecip" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_warnbannedrecip") != i_null){
			p.setWarnbannedrecip( v.template get<std::string>("SpamfilterPolicy_warnbannedrecip" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_warnbadhrecip") != i_null){
			p.setWarnbadhrecip( v.template get<std::string>("SpamfilterPolicy_warnbadhrecip" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_newvirus_admin") != i_null){
			p.setNewvirusAdmin( v.template get<std::string>("SpamfilterPolicy_newvirus_admin" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_virus_admin") != i_null){
			p.setVirusAdmin( v.template get<std::string>("SpamfilterPolicy_virus_admin" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_banned_admin") != i_null){
			p.setBannedAdmin( v.template get<std::string>("SpamfilterPolicy_banned_admin" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_bad_header_admin") != i_null){
			p.setBadHeaderAdmin( v.template get<std::string>("SpamfilterPolicy_bad_header_admin" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_admin") != i_null){
			p.setSpamAdmin( v.template get<std::string>("SpamfilterPolicy_spam_admin" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_subject_tag") != i_null){
			p.setSpamSubjectTag( v.template get<std::string>("SpamfilterPolicy_spam_subject_tag" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_spam_subject_tag2") != i_null){
			p.setSpamSubjectTag2( v.template get<std::string>("SpamfilterPolicy_spam_subject_tag2" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_message_size_limit") != i_null){
			p.setMessageSizeLimit( v.template get<long long>("SpamfilterPolicy_message_size_limit" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_banned_rulenames") != i_null){
			p.setBannedRulenames( v.template get<std::string>("SpamfilterPolicy_banned_rulenames" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policyd_quota_in") != i_null){
			p.setPolicydQuotaIn( v.template get<int>("SpamfilterPolicy_policyd_quota_in" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policyd_quota_in_period") != i_null){
			p.setPolicydQuotaInPeriod( v.template get<int>("SpamfilterPolicy_policyd_quota_in_period" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policyd_quota_out") != i_null){
			p.setPolicydQuotaOut( v.template get<int>("SpamfilterPolicy_policyd_quota_out" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policyd_quota_out_period") != i_null){
			p.setPolicydQuotaOutPeriod( v.template get<int>("SpamfilterPolicy_policyd_quota_out_period" ) );
		}
		if (v.get_indicator("SpamfilterPolicy_policyd_greylist") != i_null){
			p.setPolicydGreylist( v.template get<std::string>("SpamfilterPolicy_policyd_greylist" ) );
		}
	}
	static void to_base(const SpamfilterPolicy & p, values & v, indicator & ind)
	{
		v.set( "SpamfilterPolicy_id", p.getId() );
		v.set( "SpamfilterPolicy_sys_userid", p.getSysUserid() );
		v.set( "SpamfilterPolicy_sys_groupid", p.getSysGroupid() );
		v.set( "SpamfilterPolicy_sys_perm_user", p.getSysPermUser() );
		v.set( "SpamfilterPolicy_sys_perm_group", p.getSysPermGroup() );
		v.set( "SpamfilterPolicy_sys_perm_other", p.getSysPermOther() );
		v.set( "SpamfilterPolicy_policy_name", p.getPolicyName() );
		v.set( "SpamfilterPolicy_virus_lover", p.getVirusLover() );
		v.set( "SpamfilterPolicy_spam_lover", p.getSpamLover() );
		v.set( "SpamfilterPolicy_banned_files_lover", p.getBannedFilesLover() );
		v.set( "SpamfilterPolicy_bad_header_lover", p.getBadHeaderLover() );
		v.set( "SpamfilterPolicy_bypass_virus_checks", p.getBypassVirusChecks() );
		v.set( "SpamfilterPolicy_bypass_spam_checks", p.getBypassSpamChecks() );
		v.set( "SpamfilterPolicy_bypass_banned_checks", p.getBypassBannedChecks() );
		v.set( "SpamfilterPolicy_bypass_header_checks", p.getBypassHeaderChecks() );
		v.set( "SpamfilterPolicy_spam_modifies_subj", p.getSpamModifiesSubj() );
		v.set( "SpamfilterPolicy_virus_quarantine_to", p.getVirusQuarantineTo() );
		v.set( "SpamfilterPolicy_spam_quarantine_to", p.getSpamQuarantineTo() );
		v.set( "SpamfilterPolicy_banned_quarantine_to", p.getBannedQuarantineTo() );
		v.set( "SpamfilterPolicy_bad_header_quarantine_to", p.getBadHeaderQuarantineTo() );
		v.set( "SpamfilterPolicy_clean_quarantine_to", p.getCleanQuarantineTo() );
		v.set( "SpamfilterPolicy_other_quarantine_to", p.getOtherQuarantineTo() );
		v.set( "SpamfilterPolicy_spam_tag_level", p.getSpamTagLevel() );
		v.set( "SpamfilterPolicy_spam_tag2_level", p.getSpamTag2Level() );
		v.set( "SpamfilterPolicy_spam_kill_level", p.getSpamKillLevel() );
		v.set( "SpamfilterPolicy_spam_dsn_cutoff_level", p.getSpamDsnCutoffLevel() );
		v.set( "SpamfilterPolicy_spam_quarantine_cutoff_level", p.getSpamQuarantineCutoffLevel() );
		v.set( "SpamfilterPolicy_addr_extension_virus", p.getAddrExtensionVirus() );
		v.set( "SpamfilterPolicy_addr_extension_spam", p.getAddrExtensionSpam() );
		v.set( "SpamfilterPolicy_addr_extension_banned", p.getAddrExtensionBanned() );
		v.set( "SpamfilterPolicy_addr_extension_bad_header", p.getAddrExtensionBadHeader() );
		v.set( "SpamfilterPolicy_warnvirusrecip", p.getWarnvirusrecip() );
		v.set( "SpamfilterPolicy_warnbannedrecip", p.getWarnbannedrecip() );
		v.set( "SpamfilterPolicy_warnbadhrecip", p.getWarnbadhrecip() );
		v.set( "SpamfilterPolicy_newvirus_admin", p.getNewvirusAdmin() );
		v.set( "SpamfilterPolicy_virus_admin", p.getVirusAdmin() );
		v.set( "SpamfilterPolicy_banned_admin", p.getBannedAdmin() );
		v.set( "SpamfilterPolicy_bad_header_admin", p.getBadHeaderAdmin() );
		v.set( "SpamfilterPolicy_spam_admin", p.getSpamAdmin() );
		v.set( "SpamfilterPolicy_spam_subject_tag", p.getSpamSubjectTag() );
		v.set( "SpamfilterPolicy_spam_subject_tag2", p.getSpamSubjectTag2() );
		v.set( "SpamfilterPolicy_message_size_limit", p.getMessageSizeLimit() );
		v.set( "SpamfilterPolicy_banned_rulenames", p.getBannedRulenames() );
		v.set( "SpamfilterPolicy_policyd_quota_in", p.getPolicydQuotaIn() );
		v.set( "SpamfilterPolicy_policyd_quota_in_period", p.getPolicydQuotaInPeriod() );
		v.set( "SpamfilterPolicy_policyd_quota_out", p.getPolicydQuotaOut() );
		v.set( "SpamfilterPolicy_policyd_quota_out_period", p.getPolicydQuotaOutPeriod() );
		v.set( "SpamfilterPolicy_policyd_greylist", p.getPolicydGreylist() );
		ind = i_ok;
	}
};
}

#endif // SPAMFILTERPOLICYREPOSITORY_H
