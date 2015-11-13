#include "openvztemplaterepository.h"
#include "util.hpp"
OpenvzTemplateRepository::OpenvzTemplateRepository(soci::session& db) : dataBase(db)
{
}

OpenvzTemplatePtr OpenvzTemplateRepository::select(const OpenvzTemplate& obj)
{
	soci::row row;
	OpenvzTemplatePtr openvztemplate(new OpenvzTemplate);
	dataBase << "SELECT  openvz_template.template_id as OpenvzTemplate_template_id, openvz_template.sys_userid as OpenvzTemplate_sys_userid, openvz_template.sys_groupid as OpenvzTemplate_sys_groupid, openvz_template.sys_perm_user as OpenvzTemplate_sys_perm_user, openvz_template.sys_perm_group as OpenvzTemplate_sys_perm_group, openvz_template.sys_perm_other as OpenvzTemplate_sys_perm_other, openvz_template.template_name as OpenvzTemplate_template_name, openvz_template.diskspace as OpenvzTemplate_diskspace, openvz_template.traffic as OpenvzTemplate_traffic, openvz_template.bandwidth as OpenvzTemplate_bandwidth, openvz_template.ram as OpenvzTemplate_ram, openvz_template.ram_burst as OpenvzTemplate_ram_burst, openvz_template.cpu_units as OpenvzTemplate_cpu_units, openvz_template.cpu_num as OpenvzTemplate_cpu_num, openvz_template.cpu_limit as OpenvzTemplate_cpu_limit, openvz_template.io_priority as OpenvzTemplate_io_priority, openvz_template.active as OpenvzTemplate_active, openvz_template.description as OpenvzTemplate_description, openvz_template.numproc as OpenvzTemplate_numproc, openvz_template.numtcpsock as OpenvzTemplate_numtcpsock, openvz_template.numothersock as OpenvzTemplate_numothersock, openvz_template.vmguarpages as OpenvzTemplate_vmguarpages, openvz_template.kmemsize as OpenvzTemplate_kmemsize, openvz_template.tcpsndbuf as OpenvzTemplate_tcpsndbuf, openvz_template.tcprcvbuf as OpenvzTemplate_tcprcvbuf, openvz_template.othersockbuf as OpenvzTemplate_othersockbuf, openvz_template.dgramrcvbuf as OpenvzTemplate_dgramrcvbuf, openvz_template.oomguarpages as OpenvzTemplate_oomguarpages, openvz_template.privvmpages as OpenvzTemplate_privvmpages, openvz_template.lockedpages as OpenvzTemplate_lockedpages, openvz_template.shmpages as OpenvzTemplate_shmpages, openvz_template.physpages as OpenvzTemplate_physpages, openvz_template.numfile as OpenvzTemplate_numfile, openvz_template.avnumproc as OpenvzTemplate_avnumproc, openvz_template.numflock as OpenvzTemplate_numflock, openvz_template.numpty as OpenvzTemplate_numpty, openvz_template.numsiginfo as OpenvzTemplate_numsiginfo, openvz_template.dcachesize as OpenvzTemplate_dcachesize, openvz_template.numiptent as OpenvzTemplate_numiptent, openvz_template.swappages as OpenvzTemplate_swappages, openvz_template.hostname as OpenvzTemplate_hostname, openvz_template.nameserver as OpenvzTemplate_nameserver, openvz_template.create_dns as OpenvzTemplate_create_dns, openvz_template.capability as OpenvzTemplate_capability"
	" FROM openvz_template "
	"WHERE openvz_template.template_id = :OpenvzTemplate_template_id", into(row), use(obj);
	if(!dataBase.got_data())
		openvztemplate.reset();
	else
		type_conversion<OpenvzTemplate>::from_base(row, i_ok, *openvztemplate);
	return openvztemplate;
}
OpenvzTemplateList OpenvzTemplateRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  openvz_template.template_id as OpenvzTemplate_template_id, openvz_template.sys_userid as OpenvzTemplate_sys_userid, openvz_template.sys_groupid as OpenvzTemplate_sys_groupid, openvz_template.sys_perm_user as OpenvzTemplate_sys_perm_user, openvz_template.sys_perm_group as OpenvzTemplate_sys_perm_group, openvz_template.sys_perm_other as OpenvzTemplate_sys_perm_other, openvz_template.template_name as OpenvzTemplate_template_name, openvz_template.diskspace as OpenvzTemplate_diskspace, openvz_template.traffic as OpenvzTemplate_traffic, openvz_template.bandwidth as OpenvzTemplate_bandwidth, openvz_template.ram as OpenvzTemplate_ram, openvz_template.ram_burst as OpenvzTemplate_ram_burst, openvz_template.cpu_units as OpenvzTemplate_cpu_units, openvz_template.cpu_num as OpenvzTemplate_cpu_num, openvz_template.cpu_limit as OpenvzTemplate_cpu_limit, openvz_template.io_priority as OpenvzTemplate_io_priority, openvz_template.active as OpenvzTemplate_active, openvz_template.description as OpenvzTemplate_description, openvz_template.numproc as OpenvzTemplate_numproc, openvz_template.numtcpsock as OpenvzTemplate_numtcpsock, openvz_template.numothersock as OpenvzTemplate_numothersock, openvz_template.vmguarpages as OpenvzTemplate_vmguarpages, openvz_template.kmemsize as OpenvzTemplate_kmemsize, openvz_template.tcpsndbuf as OpenvzTemplate_tcpsndbuf, openvz_template.tcprcvbuf as OpenvzTemplate_tcprcvbuf, openvz_template.othersockbuf as OpenvzTemplate_othersockbuf, openvz_template.dgramrcvbuf as OpenvzTemplate_dgramrcvbuf, openvz_template.oomguarpages as OpenvzTemplate_oomguarpages, openvz_template.privvmpages as OpenvzTemplate_privvmpages, openvz_template.lockedpages as OpenvzTemplate_lockedpages, openvz_template.shmpages as OpenvzTemplate_shmpages, openvz_template.physpages as OpenvzTemplate_physpages, openvz_template.numfile as OpenvzTemplate_numfile, openvz_template.avnumproc as OpenvzTemplate_avnumproc, openvz_template.numflock as OpenvzTemplate_numflock, openvz_template.numpty as OpenvzTemplate_numpty, openvz_template.numsiginfo as OpenvzTemplate_numsiginfo, openvz_template.dcachesize as OpenvzTemplate_dcachesize, openvz_template.numiptent as OpenvzTemplate_numiptent, openvz_template.swappages as OpenvzTemplate_swappages, openvz_template.hostname as OpenvzTemplate_hostname, openvz_template.nameserver as OpenvzTemplate_nameserver, openvz_template.create_dns as OpenvzTemplate_create_dns, openvz_template.capability as OpenvzTemplate_capability "
	" FROM openvz_template" 
	<< (where.size()?" WHERE "+where:"");
	OpenvzTemplateList openvztemplateList;
	for(row& r: rs)
	{
		OpenvzTemplatePtr openvztemplate(new OpenvzTemplate);
		type_conversion<OpenvzTemplate>::from_base(r, i_ok, *openvztemplate);
		openvztemplateList.push_back(openvztemplate);
	}
	return openvztemplateList;
}

int OpenvzTemplateRepository::insert(const OpenvzTemplate& openvztemplate)
{
	dataBase << "insert into openvz_template(template_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, template_name, diskspace, traffic, bandwidth, ram, ram_burst, cpu_units, cpu_num, cpu_limit, io_priority, active, description, numproc, numtcpsock, numothersock, vmguarpages, kmemsize, tcpsndbuf, tcprcvbuf, othersockbuf, dgramrcvbuf, oomguarpages, privvmpages, lockedpages, shmpages, physpages, numfile, avnumproc, numflock, numpty, numsiginfo, dcachesize, numiptent, swappages, hostname, nameserver, create_dns, capability)\
values(:OpenvzTemplate_template_id, :OpenvzTemplate_sys_userid, :OpenvzTemplate_sys_groupid, :OpenvzTemplate_sys_perm_user, :OpenvzTemplate_sys_perm_group, :OpenvzTemplate_sys_perm_other, :OpenvzTemplate_template_name, :OpenvzTemplate_diskspace, :OpenvzTemplate_traffic, :OpenvzTemplate_bandwidth, :OpenvzTemplate_ram, :OpenvzTemplate_ram_burst, :OpenvzTemplate_cpu_units, :OpenvzTemplate_cpu_num, :OpenvzTemplate_cpu_limit, :OpenvzTemplate_io_priority, :OpenvzTemplate_active, :OpenvzTemplate_description, :OpenvzTemplate_numproc, :OpenvzTemplate_numtcpsock, :OpenvzTemplate_numothersock, :OpenvzTemplate_vmguarpages, :OpenvzTemplate_kmemsize, :OpenvzTemplate_tcpsndbuf, :OpenvzTemplate_tcprcvbuf, :OpenvzTemplate_othersockbuf, :OpenvzTemplate_dgramrcvbuf, :OpenvzTemplate_oomguarpages, :OpenvzTemplate_privvmpages, :OpenvzTemplate_lockedpages, :OpenvzTemplate_shmpages, :OpenvzTemplate_physpages, :OpenvzTemplate_numfile, :OpenvzTemplate_avnumproc, :OpenvzTemplate_numflock, :OpenvzTemplate_numpty, :OpenvzTemplate_numsiginfo, :OpenvzTemplate_dcachesize, :OpenvzTemplate_numiptent, :OpenvzTemplate_swappages, :OpenvzTemplate_hostname, :OpenvzTemplate_nameserver, :OpenvzTemplate_create_dns, :OpenvzTemplate_capability)", use(openvztemplate);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void OpenvzTemplateRepository::remove(const OpenvzTemplate& openvztemplate)
{
	dataBase << "DELETE from openvz_template WHERE template_id=:OpenvzTemplate_template_id", use(openvztemplate);
}

void OpenvzTemplateRepository::update(const OpenvzTemplate& openvztemplate)
{
	dataBase << "update openvz_template set template_id=:OpenvzTemplate_template_id, sys_userid=:OpenvzTemplate_sys_userid, sys_groupid=:OpenvzTemplate_sys_groupid, sys_perm_user=:OpenvzTemplate_sys_perm_user, sys_perm_group=:OpenvzTemplate_sys_perm_group, sys_perm_other=:OpenvzTemplate_sys_perm_other, template_name=:OpenvzTemplate_template_name, diskspace=:OpenvzTemplate_diskspace, traffic=:OpenvzTemplate_traffic, bandwidth=:OpenvzTemplate_bandwidth, ram=:OpenvzTemplate_ram, ram_burst=:OpenvzTemplate_ram_burst, cpu_units=:OpenvzTemplate_cpu_units, cpu_num=:OpenvzTemplate_cpu_num, cpu_limit=:OpenvzTemplate_cpu_limit, io_priority=:OpenvzTemplate_io_priority, active=:OpenvzTemplate_active, description=:OpenvzTemplate_description, numproc=:OpenvzTemplate_numproc, numtcpsock=:OpenvzTemplate_numtcpsock, numothersock=:OpenvzTemplate_numothersock, vmguarpages=:OpenvzTemplate_vmguarpages, kmemsize=:OpenvzTemplate_kmemsize, tcpsndbuf=:OpenvzTemplate_tcpsndbuf, tcprcvbuf=:OpenvzTemplate_tcprcvbuf, othersockbuf=:OpenvzTemplate_othersockbuf, dgramrcvbuf=:OpenvzTemplate_dgramrcvbuf, oomguarpages=:OpenvzTemplate_oomguarpages, privvmpages=:OpenvzTemplate_privvmpages, lockedpages=:OpenvzTemplate_lockedpages, shmpages=:OpenvzTemplate_shmpages, physpages=:OpenvzTemplate_physpages, numfile=:OpenvzTemplate_numfile, avnumproc=:OpenvzTemplate_avnumproc, numflock=:OpenvzTemplate_numflock, numpty=:OpenvzTemplate_numpty, numsiginfo=:OpenvzTemplate_numsiginfo, dcachesize=:OpenvzTemplate_dcachesize, numiptent=:OpenvzTemplate_numiptent, swappages=:OpenvzTemplate_swappages, hostname=:OpenvzTemplate_hostname, nameserver=:OpenvzTemplate_nameserver, create_dns=:OpenvzTemplate_create_dns, capability=:OpenvzTemplate_capability WHERE template_id=:OpenvzTemplate_template_id", use(openvztemplate);
}

void OpenvzTemplateRepository::update(const OpenvzTemplate& oldObj, const OpenvzTemplate& newObj)
{
	dataBase << "update openvz_template set template_id=:OpenvzTemplate_template_id, sys_userid=:OpenvzTemplate_sys_userid, sys_groupid=:OpenvzTemplate_sys_groupid, sys_perm_user=:OpenvzTemplate_sys_perm_user, sys_perm_group=:OpenvzTemplate_sys_perm_group, sys_perm_other=:OpenvzTemplate_sys_perm_other, template_name=:OpenvzTemplate_template_name, diskspace=:OpenvzTemplate_diskspace, traffic=:OpenvzTemplate_traffic, bandwidth=:OpenvzTemplate_bandwidth, ram=:OpenvzTemplate_ram, ram_burst=:OpenvzTemplate_ram_burst, cpu_units=:OpenvzTemplate_cpu_units, cpu_num=:OpenvzTemplate_cpu_num, cpu_limit=:OpenvzTemplate_cpu_limit, io_priority=:OpenvzTemplate_io_priority, active=:OpenvzTemplate_active, description=:OpenvzTemplate_description, numproc=:OpenvzTemplate_numproc, numtcpsock=:OpenvzTemplate_numtcpsock, numothersock=:OpenvzTemplate_numothersock, vmguarpages=:OpenvzTemplate_vmguarpages, kmemsize=:OpenvzTemplate_kmemsize, tcpsndbuf=:OpenvzTemplate_tcpsndbuf, tcprcvbuf=:OpenvzTemplate_tcprcvbuf, othersockbuf=:OpenvzTemplate_othersockbuf, dgramrcvbuf=:OpenvzTemplate_dgramrcvbuf, oomguarpages=:OpenvzTemplate_oomguarpages, privvmpages=:OpenvzTemplate_privvmpages, lockedpages=:OpenvzTemplate_lockedpages, shmpages=:OpenvzTemplate_shmpages, physpages=:OpenvzTemplate_physpages, numfile=:OpenvzTemplate_numfile, avnumproc=:OpenvzTemplate_avnumproc, numflock=:OpenvzTemplate_numflock, numpty=:OpenvzTemplate_numpty, numsiginfo=:OpenvzTemplate_numsiginfo, dcachesize=:OpenvzTemplate_dcachesize, numiptent=:OpenvzTemplate_numiptent, swappages=:OpenvzTemplate_swappages, hostname=:OpenvzTemplate_hostname, nameserver=:OpenvzTemplate_nameserver, create_dns=:OpenvzTemplate_create_dns, capability=:OpenvzTemplate_capability WHERE template_id='"<<oldObj.getTemplateId()<<"\'", use(newObj);
}

