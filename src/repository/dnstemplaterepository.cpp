#include "dnstemplaterepository.h"
#include "util.hpp"
DnsTemplateRepository::DnsTemplateRepository(soci::session& db) : dataBase(db)
{
}

DnsTemplatePtr DnsTemplateRepository::select(const DnsTemplate& obj)
{
	soci::row row;
	DnsTemplatePtr dnstemplate(new DnsTemplate);
	dataBase << "SELECT  dns_template.template_id as DnsTemplate_template_id, dns_template.sys_userid as DnsTemplate_sys_userid, dns_template.sys_groupid as DnsTemplate_sys_groupid, dns_template.sys_perm_user as DnsTemplate_sys_perm_user, dns_template.sys_perm_group as DnsTemplate_sys_perm_group, dns_template.sys_perm_other as DnsTemplate_sys_perm_other, dns_template.name as DnsTemplate_name, dns_template.fields as DnsTemplate_fields, dns_template.template as DnsTemplate_template_, dns_template.visible as DnsTemplate_visible"
	" FROM dns_template "
	"WHERE dns_template.template_id = :DnsTemplate_template_id", into(row), use(obj);
	if(!dataBase.got_data())
		dnstemplate.reset();
	else
		type_conversion<DnsTemplate>::from_base(row, i_ok, *dnstemplate);
	return dnstemplate;
}
DnsTemplateList DnsTemplateRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  dns_template.template_id as DnsTemplate_template_id, dns_template.sys_userid as DnsTemplate_sys_userid, dns_template.sys_groupid as DnsTemplate_sys_groupid, dns_template.sys_perm_user as DnsTemplate_sys_perm_user, dns_template.sys_perm_group as DnsTemplate_sys_perm_group, dns_template.sys_perm_other as DnsTemplate_sys_perm_other, dns_template.name as DnsTemplate_name, dns_template.fields as DnsTemplate_fields, dns_template.template as DnsTemplate_template_, dns_template.visible as DnsTemplate_visible "
	" FROM dns_template" 
	<< (where.size()?" WHERE "+where:"");
	DnsTemplateList dnstemplateList;
	for(row& r: rs)
	{
		DnsTemplatePtr dnstemplate(new DnsTemplate);
		type_conversion<DnsTemplate>::from_base(r, i_ok, *dnstemplate);
		dnstemplateList.push_back(dnstemplate);
	}
	return dnstemplateList;
}

int DnsTemplateRepository::insert(const DnsTemplate& dnstemplate)
{
	dataBase << "insert into dns_template(template_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, name, fields, template, visible)\
values(:DnsTemplate_template_id, :DnsTemplate_sys_userid, :DnsTemplate_sys_groupid, :DnsTemplate_sys_perm_user, :DnsTemplate_sys_perm_group, :DnsTemplate_sys_perm_other, :DnsTemplate_name, :DnsTemplate_fields, :DnsTemplate_template_, :DnsTemplate_visible)", use(dnstemplate);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void DnsTemplateRepository::remove(const DnsTemplate& dnstemplate)
{
	dataBase << "DELETE from dns_template WHERE template_id=:DnsTemplate_template_id", use(dnstemplate);
}

void DnsTemplateRepository::update(const DnsTemplate& dnstemplate)
{
	dataBase << "update dns_template set template_id=:DnsTemplate_template_id, sys_userid=:DnsTemplate_sys_userid, sys_groupid=:DnsTemplate_sys_groupid, sys_perm_user=:DnsTemplate_sys_perm_user, sys_perm_group=:DnsTemplate_sys_perm_group, sys_perm_other=:DnsTemplate_sys_perm_other, name=:DnsTemplate_name, fields=:DnsTemplate_fields, template_=:DnsTemplate_template_, visible=:DnsTemplate_visible WHERE template_id=:DnsTemplate_template_id", use(dnstemplate);
}

void DnsTemplateRepository::update(const DnsTemplate& oldObj, const DnsTemplate& newObj)
{
	dataBase << "update dns_template set template_id=:DnsTemplate_template_id, sys_userid=:DnsTemplate_sys_userid, sys_groupid=:DnsTemplate_sys_groupid, sys_perm_user=:DnsTemplate_sys_perm_user, sys_perm_group=:DnsTemplate_sys_perm_group, sys_perm_other=:DnsTemplate_sys_perm_other, name=:DnsTemplate_name, fields=:DnsTemplate_fields, template_=:DnsTemplate_template_, visible=:DnsTemplate_visible WHERE template_id='"<<oldObj.getTemplateId()<<"\'", use(newObj);
}

