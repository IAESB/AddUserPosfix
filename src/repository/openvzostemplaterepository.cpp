#include "openvzostemplaterepository.h"
#include "util.hpp"
OpenvzOstemplateRepository::OpenvzOstemplateRepository(soci::session& db) : dataBase(db)
{
}

OpenvzOstemplatePtr OpenvzOstemplateRepository::select(const OpenvzOstemplate& obj)
{
	soci::row row;
	OpenvzOstemplatePtr openvzostemplate(new OpenvzOstemplate);
	dataBase << "SELECT  openvz_ostemplate.ostemplate_id as OpenvzOstemplate_ostemplate_id, openvz_ostemplate.sys_userid as OpenvzOstemplate_sys_userid, openvz_ostemplate.sys_groupid as OpenvzOstemplate_sys_groupid, openvz_ostemplate.sys_perm_user as OpenvzOstemplate_sys_perm_user, openvz_ostemplate.sys_perm_group as OpenvzOstemplate_sys_perm_group, openvz_ostemplate.sys_perm_other as OpenvzOstemplate_sys_perm_other, openvz_ostemplate.template_name as OpenvzOstemplate_template_name, openvz_ostemplate.template_file as OpenvzOstemplate_template_file, openvz_ostemplate.server_id as OpenvzOstemplate_server_id, openvz_ostemplate.allservers as OpenvzOstemplate_allservers, openvz_ostemplate.active as OpenvzOstemplate_active, openvz_ostemplate.description as OpenvzOstemplate_description"
	" FROM openvz_ostemplate "
	"WHERE openvz_ostemplate.ostemplate_id = :OpenvzOstemplate_ostemplate_id", into(row), use(obj);
	if(!dataBase.got_data())
		openvzostemplate.reset();
	else
		type_conversion<OpenvzOstemplate>::from_base(row, i_ok, *openvzostemplate);
	return openvzostemplate;
}
OpenvzOstemplateList OpenvzOstemplateRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  openvz_ostemplate.ostemplate_id as OpenvzOstemplate_ostemplate_id, openvz_ostemplate.sys_userid as OpenvzOstemplate_sys_userid, openvz_ostemplate.sys_groupid as OpenvzOstemplate_sys_groupid, openvz_ostemplate.sys_perm_user as OpenvzOstemplate_sys_perm_user, openvz_ostemplate.sys_perm_group as OpenvzOstemplate_sys_perm_group, openvz_ostemplate.sys_perm_other as OpenvzOstemplate_sys_perm_other, openvz_ostemplate.template_name as OpenvzOstemplate_template_name, openvz_ostemplate.template_file as OpenvzOstemplate_template_file, openvz_ostemplate.server_id as OpenvzOstemplate_server_id, openvz_ostemplate.allservers as OpenvzOstemplate_allservers, openvz_ostemplate.active as OpenvzOstemplate_active, openvz_ostemplate.description as OpenvzOstemplate_description "
	" FROM openvz_ostemplate" 
	<< (where.size()?" WHERE "+where:"");
	OpenvzOstemplateList openvzostemplateList;
	for(row& r: rs)
	{
		OpenvzOstemplatePtr openvzostemplate(new OpenvzOstemplate);
		type_conversion<OpenvzOstemplate>::from_base(r, i_ok, *openvzostemplate);
		openvzostemplateList.push_back(openvzostemplate);
	}
	return openvzostemplateList;
}

int OpenvzOstemplateRepository::insert(const OpenvzOstemplate& openvzostemplate)
{
	dataBase << "insert into openvz_ostemplate(ostemplate_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, template_name, template_file, server_id, allservers, active, description)\
values(:OpenvzOstemplate_ostemplate_id, :OpenvzOstemplate_sys_userid, :OpenvzOstemplate_sys_groupid, :OpenvzOstemplate_sys_perm_user, :OpenvzOstemplate_sys_perm_group, :OpenvzOstemplate_sys_perm_other, :OpenvzOstemplate_template_name, :OpenvzOstemplate_template_file, :OpenvzOstemplate_server_id, :OpenvzOstemplate_allservers, :OpenvzOstemplate_active, :OpenvzOstemplate_description)", use(openvzostemplate);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void OpenvzOstemplateRepository::remove(const OpenvzOstemplate& openvzostemplate)
{
	dataBase << "DELETE from openvz_ostemplate WHERE ostemplate_id=:OpenvzOstemplate_ostemplate_id", use(openvzostemplate);
}

void OpenvzOstemplateRepository::update(const OpenvzOstemplate& openvzostemplate)
{
	dataBase << "update openvz_ostemplate set ostemplate_id=:OpenvzOstemplate_ostemplate_id, sys_userid=:OpenvzOstemplate_sys_userid, sys_groupid=:OpenvzOstemplate_sys_groupid, sys_perm_user=:OpenvzOstemplate_sys_perm_user, sys_perm_group=:OpenvzOstemplate_sys_perm_group, sys_perm_other=:OpenvzOstemplate_sys_perm_other, template_name=:OpenvzOstemplate_template_name, template_file=:OpenvzOstemplate_template_file, server_id=:OpenvzOstemplate_server_id, allservers=:OpenvzOstemplate_allservers, active=:OpenvzOstemplate_active, description=:OpenvzOstemplate_description WHERE ostemplate_id=:OpenvzOstemplate_ostemplate_id", use(openvzostemplate);
}

void OpenvzOstemplateRepository::update(const OpenvzOstemplate& oldObj, const OpenvzOstemplate& newObj)
{
	dataBase << "update openvz_ostemplate set ostemplate_id=:OpenvzOstemplate_ostemplate_id, sys_userid=:OpenvzOstemplate_sys_userid, sys_groupid=:OpenvzOstemplate_sys_groupid, sys_perm_user=:OpenvzOstemplate_sys_perm_user, sys_perm_group=:OpenvzOstemplate_sys_perm_group, sys_perm_other=:OpenvzOstemplate_sys_perm_other, template_name=:OpenvzOstemplate_template_name, template_file=:OpenvzOstemplate_template_file, server_id=:OpenvzOstemplate_server_id, allservers=:OpenvzOstemplate_allservers, active=:OpenvzOstemplate_active, description=:OpenvzOstemplate_description WHERE ostemplate_id='"<<oldObj.getOstemplateId()<<"\'", use(newObj);
}

