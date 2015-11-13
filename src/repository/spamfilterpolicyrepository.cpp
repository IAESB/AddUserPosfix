#include "spamfilterpolicyrepository.h"
#include "util.hpp"
SpamfilterPolicyRepository::SpamfilterPolicyRepository(soci::session& db) : dataBase(db)
{
}

SpamfilterPolicyPtr SpamfilterPolicyRepository::select(const SpamfilterPolicy& obj)
{
	soci::row row;
	SpamfilterPolicyPtr spamfilterpolicy(new SpamfilterPolicy);
	dataBase << "SELECT  spamfilter_policy.id as SpamfilterPolicy_id, spamfilter_policy.sys_userid as SpamfilterPolicy_sys_userid, spamfilter_policy.sys_groupid as SpamfilterPolicy_sys_groupid, spamfilter_policy.sys_perm_user as SpamfilterPolicy_sys_perm_user, spamfilter_policy.sys_perm_group as SpamfilterPolicy_sys_perm_group, spamfilter_policy.sys_perm_other as SpamfilterPolicy_sys_perm_other, spamfilter_policy.policy_name as SpamfilterPolicy_policy_name, spamfilter_policy.virus_lover as SpamfilterPolicy_virus_lover, spamfilter_policy.spam_lover as SpamfilterPolicy_spam_lover, spamfilter_policy.banned_files_lover as SpamfilterPolicy_banned_files_lover, spamfilter_policy.bad_header_lover as SpamfilterPolicy_bad_header_lover, spamfilter_policy.bypass_virus_checks as SpamfilterPolicy_bypass_virus_checks, spamfilter_policy.bypass_spam_checks as SpamfilterPolicy_bypass_spam_checks, spamfilter_policy.bypass_banned_checks as SpamfilterPolicy_bypass_banned_checks, spamfilter_policy.bypass_header_checks as SpamfilterPolicy_bypass_header_checks, spamfilter_policy.spam_modifies_subj as SpamfilterPolicy_spam_modifies_subj, spamfilter_policy.virus_quarantine_to as SpamfilterPolicy_virus_quarantine_to, spamfilter_policy.spam_quarantine_to as SpamfilterPolicy_spam_quarantine_to, spamfilter_policy.banned_quarantine_to as SpamfilterPolicy_banned_quarantine_to, spamfilter_policy.bad_header_quarantine_to as SpamfilterPolicy_bad_header_quarantine_to, spamfilter_policy.clean_quarantine_to as SpamfilterPolicy_clean_quarantine_to, spamfilter_policy.other_quarantine_to as SpamfilterPolicy_other_quarantine_to, spamfilter_policy.spam_tag_level as SpamfilterPolicy_spam_tag_level, spamfilter_policy.spam_tag2_level as SpamfilterPolicy_spam_tag2_level, spamfilter_policy.spam_kill_level as SpamfilterPolicy_spam_kill_level, spamfilter_policy.spam_dsn_cutoff_level as SpamfilterPolicy_spam_dsn_cutoff_level, spamfilter_policy.spam_quarantine_cutoff_level as SpamfilterPolicy_spam_quarantine_cutoff_level, spamfilter_policy.addr_extension_virus as SpamfilterPolicy_addr_extension_virus, spamfilter_policy.addr_extension_spam as SpamfilterPolicy_addr_extension_spam, spamfilter_policy.addr_extension_banned as SpamfilterPolicy_addr_extension_banned, spamfilter_policy.addr_extension_bad_header as SpamfilterPolicy_addr_extension_bad_header, spamfilter_policy.warnvirusrecip as SpamfilterPolicy_warnvirusrecip, spamfilter_policy.warnbannedrecip as SpamfilterPolicy_warnbannedrecip, spamfilter_policy.warnbadhrecip as SpamfilterPolicy_warnbadhrecip, spamfilter_policy.newvirus_admin as SpamfilterPolicy_newvirus_admin, spamfilter_policy.virus_admin as SpamfilterPolicy_virus_admin, spamfilter_policy.banned_admin as SpamfilterPolicy_banned_admin, spamfilter_policy.bad_header_admin as SpamfilterPolicy_bad_header_admin, spamfilter_policy.spam_admin as SpamfilterPolicy_spam_admin, spamfilter_policy.spam_subject_tag as SpamfilterPolicy_spam_subject_tag, spamfilter_policy.spam_subject_tag2 as SpamfilterPolicy_spam_subject_tag2, spamfilter_policy.message_size_limit as SpamfilterPolicy_message_size_limit, spamfilter_policy.banned_rulenames as SpamfilterPolicy_banned_rulenames, spamfilter_policy.policyd_quota_in as SpamfilterPolicy_policyd_quota_in, spamfilter_policy.policyd_quota_in_period as SpamfilterPolicy_policyd_quota_in_period, spamfilter_policy.policyd_quota_out as SpamfilterPolicy_policyd_quota_out, spamfilter_policy.policyd_quota_out_period as SpamfilterPolicy_policyd_quota_out_period, spamfilter_policy.policyd_greylist as SpamfilterPolicy_policyd_greylist"
	" FROM spamfilter_policy "
	"WHERE spamfilter_policy.id = :SpamfilterPolicy_id", into(row), use(obj);
	if(!dataBase.got_data())
		spamfilterpolicy.reset();
	else
		type_conversion<SpamfilterPolicy>::from_base(row, i_ok, *spamfilterpolicy);
	return spamfilterpolicy;
}
SpamfilterPolicyList SpamfilterPolicyRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  spamfilter_policy.id as SpamfilterPolicy_id, spamfilter_policy.sys_userid as SpamfilterPolicy_sys_userid, spamfilter_policy.sys_groupid as SpamfilterPolicy_sys_groupid, spamfilter_policy.sys_perm_user as SpamfilterPolicy_sys_perm_user, spamfilter_policy.sys_perm_group as SpamfilterPolicy_sys_perm_group, spamfilter_policy.sys_perm_other as SpamfilterPolicy_sys_perm_other, spamfilter_policy.policy_name as SpamfilterPolicy_policy_name, spamfilter_policy.virus_lover as SpamfilterPolicy_virus_lover, spamfilter_policy.spam_lover as SpamfilterPolicy_spam_lover, spamfilter_policy.banned_files_lover as SpamfilterPolicy_banned_files_lover, spamfilter_policy.bad_header_lover as SpamfilterPolicy_bad_header_lover, spamfilter_policy.bypass_virus_checks as SpamfilterPolicy_bypass_virus_checks, spamfilter_policy.bypass_spam_checks as SpamfilterPolicy_bypass_spam_checks, spamfilter_policy.bypass_banned_checks as SpamfilterPolicy_bypass_banned_checks, spamfilter_policy.bypass_header_checks as SpamfilterPolicy_bypass_header_checks, spamfilter_policy.spam_modifies_subj as SpamfilterPolicy_spam_modifies_subj, spamfilter_policy.virus_quarantine_to as SpamfilterPolicy_virus_quarantine_to, spamfilter_policy.spam_quarantine_to as SpamfilterPolicy_spam_quarantine_to, spamfilter_policy.banned_quarantine_to as SpamfilterPolicy_banned_quarantine_to, spamfilter_policy.bad_header_quarantine_to as SpamfilterPolicy_bad_header_quarantine_to, spamfilter_policy.clean_quarantine_to as SpamfilterPolicy_clean_quarantine_to, spamfilter_policy.other_quarantine_to as SpamfilterPolicy_other_quarantine_to, spamfilter_policy.spam_tag_level as SpamfilterPolicy_spam_tag_level, spamfilter_policy.spam_tag2_level as SpamfilterPolicy_spam_tag2_level, spamfilter_policy.spam_kill_level as SpamfilterPolicy_spam_kill_level, spamfilter_policy.spam_dsn_cutoff_level as SpamfilterPolicy_spam_dsn_cutoff_level, spamfilter_policy.spam_quarantine_cutoff_level as SpamfilterPolicy_spam_quarantine_cutoff_level, spamfilter_policy.addr_extension_virus as SpamfilterPolicy_addr_extension_virus, spamfilter_policy.addr_extension_spam as SpamfilterPolicy_addr_extension_spam, spamfilter_policy.addr_extension_banned as SpamfilterPolicy_addr_extension_banned, spamfilter_policy.addr_extension_bad_header as SpamfilterPolicy_addr_extension_bad_header, spamfilter_policy.warnvirusrecip as SpamfilterPolicy_warnvirusrecip, spamfilter_policy.warnbannedrecip as SpamfilterPolicy_warnbannedrecip, spamfilter_policy.warnbadhrecip as SpamfilterPolicy_warnbadhrecip, spamfilter_policy.newvirus_admin as SpamfilterPolicy_newvirus_admin, spamfilter_policy.virus_admin as SpamfilterPolicy_virus_admin, spamfilter_policy.banned_admin as SpamfilterPolicy_banned_admin, spamfilter_policy.bad_header_admin as SpamfilterPolicy_bad_header_admin, spamfilter_policy.spam_admin as SpamfilterPolicy_spam_admin, spamfilter_policy.spam_subject_tag as SpamfilterPolicy_spam_subject_tag, spamfilter_policy.spam_subject_tag2 as SpamfilterPolicy_spam_subject_tag2, spamfilter_policy.message_size_limit as SpamfilterPolicy_message_size_limit, spamfilter_policy.banned_rulenames as SpamfilterPolicy_banned_rulenames, spamfilter_policy.policyd_quota_in as SpamfilterPolicy_policyd_quota_in, spamfilter_policy.policyd_quota_in_period as SpamfilterPolicy_policyd_quota_in_period, spamfilter_policy.policyd_quota_out as SpamfilterPolicy_policyd_quota_out, spamfilter_policy.policyd_quota_out_period as SpamfilterPolicy_policyd_quota_out_period, spamfilter_policy.policyd_greylist as SpamfilterPolicy_policyd_greylist "
	" FROM spamfilter_policy" 
	<< (where.size()?" WHERE "+where:"");
	SpamfilterPolicyList spamfilterpolicyList;
	for(row& r: rs)
	{
		SpamfilterPolicyPtr spamfilterpolicy(new SpamfilterPolicy);
		type_conversion<SpamfilterPolicy>::from_base(r, i_ok, *spamfilterpolicy);
		spamfilterpolicyList.push_back(spamfilterpolicy);
	}
	return spamfilterpolicyList;
}

int SpamfilterPolicyRepository::insert(const SpamfilterPolicy& spamfilterpolicy)
{
	dataBase << "insert into spamfilter_policy(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, policy_name, virus_lover, spam_lover, banned_files_lover, bad_header_lover, bypass_virus_checks, bypass_spam_checks, bypass_banned_checks, bypass_header_checks, spam_modifies_subj, virus_quarantine_to, spam_quarantine_to, banned_quarantine_to, bad_header_quarantine_to, clean_quarantine_to, other_quarantine_to, spam_tag_level, spam_tag2_level, spam_kill_level, spam_dsn_cutoff_level, spam_quarantine_cutoff_level, addr_extension_virus, addr_extension_spam, addr_extension_banned, addr_extension_bad_header, warnvirusrecip, warnbannedrecip, warnbadhrecip, newvirus_admin, virus_admin, banned_admin, bad_header_admin, spam_admin, spam_subject_tag, spam_subject_tag2, message_size_limit, banned_rulenames, policyd_quota_in, policyd_quota_in_period, policyd_quota_out, policyd_quota_out_period, policyd_greylist)\
values(:SpamfilterPolicy_sys_userid, :SpamfilterPolicy_sys_groupid, :SpamfilterPolicy_sys_perm_user, :SpamfilterPolicy_sys_perm_group, :SpamfilterPolicy_sys_perm_other, :SpamfilterPolicy_policy_name, :SpamfilterPolicy_virus_lover, :SpamfilterPolicy_spam_lover, :SpamfilterPolicy_banned_files_lover, :SpamfilterPolicy_bad_header_lover, :SpamfilterPolicy_bypass_virus_checks, :SpamfilterPolicy_bypass_spam_checks, :SpamfilterPolicy_bypass_banned_checks, :SpamfilterPolicy_bypass_header_checks, :SpamfilterPolicy_spam_modifies_subj, :SpamfilterPolicy_virus_quarantine_to, :SpamfilterPolicy_spam_quarantine_to, :SpamfilterPolicy_banned_quarantine_to, :SpamfilterPolicy_bad_header_quarantine_to, :SpamfilterPolicy_clean_quarantine_to, :SpamfilterPolicy_other_quarantine_to, :SpamfilterPolicy_spam_tag_level, :SpamfilterPolicy_spam_tag2_level, :SpamfilterPolicy_spam_kill_level, :SpamfilterPolicy_spam_dsn_cutoff_level, :SpamfilterPolicy_spam_quarantine_cutoff_level, :SpamfilterPolicy_addr_extension_virus, :SpamfilterPolicy_addr_extension_spam, :SpamfilterPolicy_addr_extension_banned, :SpamfilterPolicy_addr_extension_bad_header, :SpamfilterPolicy_warnvirusrecip, :SpamfilterPolicy_warnbannedrecip, :SpamfilterPolicy_warnbadhrecip, :SpamfilterPolicy_newvirus_admin, :SpamfilterPolicy_virus_admin, :SpamfilterPolicy_banned_admin, :SpamfilterPolicy_bad_header_admin, :SpamfilterPolicy_spam_admin, :SpamfilterPolicy_spam_subject_tag, :SpamfilterPolicy_spam_subject_tag2, :SpamfilterPolicy_message_size_limit, :SpamfilterPolicy_banned_rulenames, :SpamfilterPolicy_policyd_quota_in, :SpamfilterPolicy_policyd_quota_in_period, :SpamfilterPolicy_policyd_quota_out, :SpamfilterPolicy_policyd_quota_out_period, :SpamfilterPolicy_policyd_greylist)", use(spamfilterpolicy);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SpamfilterPolicyRepository::remove(const SpamfilterPolicy& spamfilterpolicy)
{
	dataBase << "DELETE from spamfilter_policy WHERE id=:SpamfilterPolicy_id", use(spamfilterpolicy);
}

void SpamfilterPolicyRepository::update(const SpamfilterPolicy& spamfilterpolicy)
{
	dataBase << "update spamfilter_policy set sys_userid=:SpamfilterPolicy_sys_userid, sys_groupid=:SpamfilterPolicy_sys_groupid, sys_perm_user=:SpamfilterPolicy_sys_perm_user, sys_perm_group=:SpamfilterPolicy_sys_perm_group, sys_perm_other=:SpamfilterPolicy_sys_perm_other, policy_name=:SpamfilterPolicy_policy_name, virus_lover=:SpamfilterPolicy_virus_lover, spam_lover=:SpamfilterPolicy_spam_lover, banned_files_lover=:SpamfilterPolicy_banned_files_lover, bad_header_lover=:SpamfilterPolicy_bad_header_lover, bypass_virus_checks=:SpamfilterPolicy_bypass_virus_checks, bypass_spam_checks=:SpamfilterPolicy_bypass_spam_checks, bypass_banned_checks=:SpamfilterPolicy_bypass_banned_checks, bypass_header_checks=:SpamfilterPolicy_bypass_header_checks, spam_modifies_subj=:SpamfilterPolicy_spam_modifies_subj, virus_quarantine_to=:SpamfilterPolicy_virus_quarantine_to, spam_quarantine_to=:SpamfilterPolicy_spam_quarantine_to, banned_quarantine_to=:SpamfilterPolicy_banned_quarantine_to, bad_header_quarantine_to=:SpamfilterPolicy_bad_header_quarantine_to, clean_quarantine_to=:SpamfilterPolicy_clean_quarantine_to, other_quarantine_to=:SpamfilterPolicy_other_quarantine_to, spam_tag_level=:SpamfilterPolicy_spam_tag_level, spam_tag2_level=:SpamfilterPolicy_spam_tag2_level, spam_kill_level=:SpamfilterPolicy_spam_kill_level, spam_dsn_cutoff_level=:SpamfilterPolicy_spam_dsn_cutoff_level, spam_quarantine_cutoff_level=:SpamfilterPolicy_spam_quarantine_cutoff_level, addr_extension_virus=:SpamfilterPolicy_addr_extension_virus, addr_extension_spam=:SpamfilterPolicy_addr_extension_spam, addr_extension_banned=:SpamfilterPolicy_addr_extension_banned, addr_extension_bad_header=:SpamfilterPolicy_addr_extension_bad_header, warnvirusrecip=:SpamfilterPolicy_warnvirusrecip, warnbannedrecip=:SpamfilterPolicy_warnbannedrecip, warnbadhrecip=:SpamfilterPolicy_warnbadhrecip, newvirus_admin=:SpamfilterPolicy_newvirus_admin, virus_admin=:SpamfilterPolicy_virus_admin, banned_admin=:SpamfilterPolicy_banned_admin, bad_header_admin=:SpamfilterPolicy_bad_header_admin, spam_admin=:SpamfilterPolicy_spam_admin, spam_subject_tag=:SpamfilterPolicy_spam_subject_tag, spam_subject_tag2=:SpamfilterPolicy_spam_subject_tag2, message_size_limit=:SpamfilterPolicy_message_size_limit, banned_rulenames=:SpamfilterPolicy_banned_rulenames, policyd_quota_in=:SpamfilterPolicy_policyd_quota_in, policyd_quota_in_period=:SpamfilterPolicy_policyd_quota_in_period, policyd_quota_out=:SpamfilterPolicy_policyd_quota_out, policyd_quota_out_period=:SpamfilterPolicy_policyd_quota_out_period, policyd_greylist=:SpamfilterPolicy_policyd_greylist WHERE id=:SpamfilterPolicy_id", use(spamfilterpolicy);
}

void SpamfilterPolicyRepository::update(const SpamfilterPolicy& oldObj, const SpamfilterPolicy& newObj)
{
	dataBase << "update spamfilter_policy set sys_userid=:SpamfilterPolicy_sys_userid, sys_groupid=:SpamfilterPolicy_sys_groupid, sys_perm_user=:SpamfilterPolicy_sys_perm_user, sys_perm_group=:SpamfilterPolicy_sys_perm_group, sys_perm_other=:SpamfilterPolicy_sys_perm_other, policy_name=:SpamfilterPolicy_policy_name, virus_lover=:SpamfilterPolicy_virus_lover, spam_lover=:SpamfilterPolicy_spam_lover, banned_files_lover=:SpamfilterPolicy_banned_files_lover, bad_header_lover=:SpamfilterPolicy_bad_header_lover, bypass_virus_checks=:SpamfilterPolicy_bypass_virus_checks, bypass_spam_checks=:SpamfilterPolicy_bypass_spam_checks, bypass_banned_checks=:SpamfilterPolicy_bypass_banned_checks, bypass_header_checks=:SpamfilterPolicy_bypass_header_checks, spam_modifies_subj=:SpamfilterPolicy_spam_modifies_subj, virus_quarantine_to=:SpamfilterPolicy_virus_quarantine_to, spam_quarantine_to=:SpamfilterPolicy_spam_quarantine_to, banned_quarantine_to=:SpamfilterPolicy_banned_quarantine_to, bad_header_quarantine_to=:SpamfilterPolicy_bad_header_quarantine_to, clean_quarantine_to=:SpamfilterPolicy_clean_quarantine_to, other_quarantine_to=:SpamfilterPolicy_other_quarantine_to, spam_tag_level=:SpamfilterPolicy_spam_tag_level, spam_tag2_level=:SpamfilterPolicy_spam_tag2_level, spam_kill_level=:SpamfilterPolicy_spam_kill_level, spam_dsn_cutoff_level=:SpamfilterPolicy_spam_dsn_cutoff_level, spam_quarantine_cutoff_level=:SpamfilterPolicy_spam_quarantine_cutoff_level, addr_extension_virus=:SpamfilterPolicy_addr_extension_virus, addr_extension_spam=:SpamfilterPolicy_addr_extension_spam, addr_extension_banned=:SpamfilterPolicy_addr_extension_banned, addr_extension_bad_header=:SpamfilterPolicy_addr_extension_bad_header, warnvirusrecip=:SpamfilterPolicy_warnvirusrecip, warnbannedrecip=:SpamfilterPolicy_warnbannedrecip, warnbadhrecip=:SpamfilterPolicy_warnbadhrecip, newvirus_admin=:SpamfilterPolicy_newvirus_admin, virus_admin=:SpamfilterPolicy_virus_admin, banned_admin=:SpamfilterPolicy_banned_admin, bad_header_admin=:SpamfilterPolicy_bad_header_admin, spam_admin=:SpamfilterPolicy_spam_admin, spam_subject_tag=:SpamfilterPolicy_spam_subject_tag, spam_subject_tag2=:SpamfilterPolicy_spam_subject_tag2, message_size_limit=:SpamfilterPolicy_message_size_limit, banned_rulenames=:SpamfilterPolicy_banned_rulenames, policyd_quota_in=:SpamfilterPolicy_policyd_quota_in, policyd_quota_in_period=:SpamfilterPolicy_policyd_quota_in_period, policyd_quota_out=:SpamfilterPolicy_policyd_quota_out, policyd_quota_out_period=:SpamfilterPolicy_policyd_quota_out_period, policyd_greylist=:SpamfilterPolicy_policyd_greylist WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}
