#include "helpfaqsectionsrepository.h"
#include "util.hpp"
HelpFaqSectionsRepository::HelpFaqSectionsRepository(soci::session& db) : dataBase(db)
{
}

HelpFaqSectionsPtr HelpFaqSectionsRepository::select(const HelpFaqSections& obj)
{
	soci::row row;
	HelpFaqSectionsPtr helpfaqsections(new HelpFaqSections);
	dataBase << "SELECT  help_faq_sections.hfs_id as HelpFaqSections_hfs_id, help_faq_sections.hfs_name as HelpFaqSections_hfs_name, help_faq_sections.hfs_order as HelpFaqSections_hfs_order, help_faq_sections.sys_userid as HelpFaqSections_sys_userid, help_faq_sections.sys_groupid as HelpFaqSections_sys_groupid, help_faq_sections.sys_perm_user as HelpFaqSections_sys_perm_user, help_faq_sections.sys_perm_group as HelpFaqSections_sys_perm_group, help_faq_sections.sys_perm_other as HelpFaqSections_sys_perm_other"
	" FROM help_faq_sections "
	"WHERE help_faq_sections.hfs_id = :HelpFaqSections_hfs_id", into(row), use(obj);
	if(!dataBase.got_data())
		helpfaqsections.reset();
	else
		type_conversion<HelpFaqSections>::from_base(row, i_ok, *helpfaqsections);
	return helpfaqsections;
}
HelpFaqSectionsList HelpFaqSectionsRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  help_faq_sections.hfs_id as HelpFaqSections_hfs_id, help_faq_sections.hfs_name as HelpFaqSections_hfs_name, help_faq_sections.hfs_order as HelpFaqSections_hfs_order, help_faq_sections.sys_userid as HelpFaqSections_sys_userid, help_faq_sections.sys_groupid as HelpFaqSections_sys_groupid, help_faq_sections.sys_perm_user as HelpFaqSections_sys_perm_user, help_faq_sections.sys_perm_group as HelpFaqSections_sys_perm_group, help_faq_sections.sys_perm_other as HelpFaqSections_sys_perm_other "
	" FROM help_faq_sections" 
	<< (where.size()?" WHERE "+where:"");
	HelpFaqSectionsList helpfaqsectionsList;
	for(row& r: rs)
	{
		HelpFaqSectionsPtr helpfaqsections(new HelpFaqSections);
		type_conversion<HelpFaqSections>::from_base(r, i_ok, *helpfaqsections);
		helpfaqsectionsList.push_back(helpfaqsections);
	}
	return helpfaqsectionsList;
}

int HelpFaqSectionsRepository::insert(const HelpFaqSections& helpfaqsections)
{
	dataBase << "insert into help_faq_sections(hfs_id, hfs_name, hfs_order, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other)\
values(:HelpFaqSections_hfs_id, :HelpFaqSections_hfs_name, :HelpFaqSections_hfs_order, :HelpFaqSections_sys_userid, :HelpFaqSections_sys_groupid, :HelpFaqSections_sys_perm_user, :HelpFaqSections_sys_perm_group, :HelpFaqSections_sys_perm_other)", use(helpfaqsections);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void HelpFaqSectionsRepository::remove(const HelpFaqSections& helpfaqsections)
{
	dataBase << "DELETE from help_faq_sections WHERE hfs_id=:HelpFaqSections_hfs_id", use(helpfaqsections);
}

void HelpFaqSectionsRepository::update(const HelpFaqSections& helpfaqsections)
{
	dataBase << "update help_faq_sections set hfs_id=:HelpFaqSections_hfs_id, hfs_name=:HelpFaqSections_hfs_name, hfs_order=:HelpFaqSections_hfs_order, sys_userid=:HelpFaqSections_sys_userid, sys_groupid=:HelpFaqSections_sys_groupid, sys_perm_user=:HelpFaqSections_sys_perm_user, sys_perm_group=:HelpFaqSections_sys_perm_group, sys_perm_other=:HelpFaqSections_sys_perm_other WHERE hfs_id=:HelpFaqSections_hfs_id", use(helpfaqsections);
}

void HelpFaqSectionsRepository::update(const HelpFaqSections& oldObj, const HelpFaqSections& newObj)
{
	dataBase << "update help_faq_sections set hfs_id=:HelpFaqSections_hfs_id, hfs_name=:HelpFaqSections_hfs_name, hfs_order=:HelpFaqSections_hfs_order, sys_userid=:HelpFaqSections_sys_userid, sys_groupid=:HelpFaqSections_sys_groupid, sys_perm_user=:HelpFaqSections_sys_perm_user, sys_perm_group=:HelpFaqSections_sys_perm_group, sys_perm_other=:HelpFaqSections_sys_perm_other WHERE hfs_id='"<<oldObj.getHfsId()<<"\'", use(newObj);
}

