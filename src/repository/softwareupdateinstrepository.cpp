#include "softwareupdateinstrepository.h"
#include "util.hpp"
SoftwareUpdateInstRepository::SoftwareUpdateInstRepository(soci::session& db) : dataBase(db)
{
}

SoftwareUpdateInstPtr SoftwareUpdateInstRepository::select(const SoftwareUpdateInst& obj)
{
	soci::row row;
	SoftwareUpdateInstPtr softwareupdateinst(new SoftwareUpdateInst);
	dataBase << "SELECT  software_update_inst.software_update_inst_id as SoftwareUpdateInst_software_update_inst_id, software_update_inst.software_update_id as SoftwareUpdateInst_software_update_id, software_update_inst.package_name as SoftwareUpdateInst_package_name, software_update_inst.server_id as SoftwareUpdateInst_server_id, software_update_inst.status as SoftwareUpdateInst_status"
	" FROM software_update_inst "
	"WHERE software_update_inst.software_update_inst_id = :SoftwareUpdateInst_software_update_inst_id AND software_update_inst.software_update_id = :SoftwareUpdateInst_software_update_id", into(row), use(obj);
	if(!dataBase.got_data())
		softwareupdateinst.reset();
	else
		type_conversion<SoftwareUpdateInst>::from_base(row, i_ok, *softwareupdateinst);
	return softwareupdateinst;
}
SoftwareUpdateInstList SoftwareUpdateInstRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  software_update_inst.software_update_inst_id as SoftwareUpdateInst_software_update_inst_id, software_update_inst.software_update_id as SoftwareUpdateInst_software_update_id, software_update_inst.package_name as SoftwareUpdateInst_package_name, software_update_inst.server_id as SoftwareUpdateInst_server_id, software_update_inst.status as SoftwareUpdateInst_status "
	" FROM software_update_inst" 
	<< (where.size()?" WHERE "+where:"");
	SoftwareUpdateInstList softwareupdateinstList;
	for(row& r: rs)
	{
		SoftwareUpdateInstPtr softwareupdateinst(new SoftwareUpdateInst);
		type_conversion<SoftwareUpdateInst>::from_base(r, i_ok, *softwareupdateinst);
		softwareupdateinstList.push_back(softwareupdateinst);
	}
	return softwareupdateinstList;
}

int SoftwareUpdateInstRepository::insert(const SoftwareUpdateInst& softwareupdateinst)
{
	dataBase << "insert into software_update_inst(software_update_inst_id, software_update_id, package_name, server_id, status)\
values(:SoftwareUpdateInst_software_update_inst_id, :SoftwareUpdateInst_software_update_id, :SoftwareUpdateInst_package_name, :SoftwareUpdateInst_server_id, :SoftwareUpdateInst_status)", use(softwareupdateinst);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SoftwareUpdateInstRepository::remove(const SoftwareUpdateInst& softwareupdateinst)
{
	dataBase << "DELETE from software_update_inst WHERE software_update_inst_id=:SoftwareUpdateInst_software_update_inst_id AND software_update_id=:SoftwareUpdateInst_software_update_id", use(softwareupdateinst);
}

void SoftwareUpdateInstRepository::update(const SoftwareUpdateInst& softwareupdateinst)
{
	dataBase << "update software_update_inst set software_update_inst_id=:SoftwareUpdateInst_software_update_inst_id, software_update_id=:SoftwareUpdateInst_software_update_id, package_name=:SoftwareUpdateInst_package_name, server_id=:SoftwareUpdateInst_server_id, status=:SoftwareUpdateInst_status WHERE software_update_inst_id=:SoftwareUpdateInst_software_update_inst_id AND software_update_id=:SoftwareUpdateInst_software_update_id", use(softwareupdateinst);
}

void SoftwareUpdateInstRepository::update(const SoftwareUpdateInst& oldObj, const SoftwareUpdateInst& newObj)
{
	dataBase << "update software_update_inst set software_update_inst_id=:SoftwareUpdateInst_software_update_inst_id, software_update_id=:SoftwareUpdateInst_software_update_id, package_name=:SoftwareUpdateInst_package_name, server_id=:SoftwareUpdateInst_server_id, status=:SoftwareUpdateInst_status WHERE software_update_inst_id='"<<oldObj.getSoftwareUpdateInstId()<<"\'' AND software_update_id='"<<oldObj.getSoftwareUpdateId()<<"\'", use(newObj);
}

