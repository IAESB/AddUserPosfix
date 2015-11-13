#include "helpfaqrepository.h"
#include "util.hpp"
HelpFaqRepository::HelpFaqRepository(soci::session& db) : dataBase(db)
{
}

HelpFaqPtr HelpFaqRepository::select(const HelpFaq& obj)
{
	soci::row row;
	HelpFaqPtr helpfaq(new HelpFaq);
	dataBase << "SELECT  help_faq.hf_id as HelpFaq_hf_id, help_faq.hf_section as HelpFaq_hf_section, help_faq.hf_order as HelpFaq_hf_order, help_faq.hf_question as HelpFaq_hf_question, help_faq.hf_answer as HelpFaq_hf_answer, help_faq.sys_userid as HelpFaq_sys_userid, help_faq.sys_groupid as HelpFaq_sys_groupid, help_faq.sys_perm_user as HelpFaq_sys_perm_user, help_faq.sys_perm_group as HelpFaq_sys_perm_group, help_faq.sys_perm_other as HelpFaq_sys_perm_other"
	" FROM help_faq "
	"WHERE help_faq.hf_id = :HelpFaq_hf_id", into(row), use(obj);
	if(!dataBase.got_data())
		helpfaq.reset();
	else
		type_conversion<HelpFaq>::from_base(row, i_ok, *helpfaq);
	return helpfaq;
}
HelpFaqList HelpFaqRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  help_faq.hf_id as HelpFaq_hf_id, help_faq.hf_section as HelpFaq_hf_section, help_faq.hf_order as HelpFaq_hf_order, help_faq.hf_question as HelpFaq_hf_question, help_faq.hf_answer as HelpFaq_hf_answer, help_faq.sys_userid as HelpFaq_sys_userid, help_faq.sys_groupid as HelpFaq_sys_groupid, help_faq.sys_perm_user as HelpFaq_sys_perm_user, help_faq.sys_perm_group as HelpFaq_sys_perm_group, help_faq.sys_perm_other as HelpFaq_sys_perm_other "
	" FROM help_faq" 
	<< (where.size()?" WHERE "+where:"");
	HelpFaqList helpfaqList;
	for(row& r: rs)
	{
		HelpFaqPtr helpfaq(new HelpFaq);
		type_conversion<HelpFaq>::from_base(r, i_ok, *helpfaq);
		helpfaqList.push_back(helpfaq);
	}
	return helpfaqList;
}

int HelpFaqRepository::insert(const HelpFaq& helpfaq)
{
	dataBase << "insert into help_faq(hf_id, hf_section, hf_order, hf_question, hf_answer, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other)\
values(:HelpFaq_hf_id, :HelpFaq_hf_section, :HelpFaq_hf_order, :HelpFaq_hf_question, :HelpFaq_hf_answer, :HelpFaq_sys_userid, :HelpFaq_sys_groupid, :HelpFaq_sys_perm_user, :HelpFaq_sys_perm_group, :HelpFaq_sys_perm_other)", use(helpfaq);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void HelpFaqRepository::remove(const HelpFaq& helpfaq)
{
	dataBase << "DELETE from help_faq WHERE hf_id=:HelpFaq_hf_id", use(helpfaq);
}

void HelpFaqRepository::update(const HelpFaq& helpfaq)
{
	dataBase << "update help_faq set hf_id=:HelpFaq_hf_id, hf_section=:HelpFaq_hf_section, hf_order=:HelpFaq_hf_order, hf_question=:HelpFaq_hf_question, hf_answer=:HelpFaq_hf_answer, sys_userid=:HelpFaq_sys_userid, sys_groupid=:HelpFaq_sys_groupid, sys_perm_user=:HelpFaq_sys_perm_user, sys_perm_group=:HelpFaq_sys_perm_group, sys_perm_other=:HelpFaq_sys_perm_other WHERE hf_id=:HelpFaq_hf_id", use(helpfaq);
}

void HelpFaqRepository::update(const HelpFaq& oldObj, const HelpFaq& newObj)
{
	dataBase << "update help_faq set hf_id=:HelpFaq_hf_id, hf_section=:HelpFaq_hf_section, hf_order=:HelpFaq_hf_order, hf_question=:HelpFaq_hf_question, hf_answer=:HelpFaq_hf_answer, sys_userid=:HelpFaq_sys_userid, sys_groupid=:HelpFaq_sys_groupid, sys_perm_user=:HelpFaq_sys_perm_user, sys_perm_group=:HelpFaq_sys_perm_group, sys_perm_other=:HelpFaq_sys_perm_other WHERE hf_id='"<<oldObj.getHfId()<<"\'", use(newObj);
}

