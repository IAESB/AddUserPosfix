#include "softwareupdateinst.h"

SoftwareUpdateInst::SoftwareUpdateInst(){
	init();
}
SoftwareUpdateInst::SoftwareUpdateInst(long long software_update_inst_id)
{
	init();
	this->software_update_inst_id = software_update_inst_id;
}

void SoftwareUpdateInst::init()
{
}
long long SoftwareUpdateInst::getSoftwareUpdateInstId() const
{
	return software_update_inst_id;
}
void SoftwareUpdateInst::setSoftwareUpdateInstId(long long value)
{
	software_update_inst_id = value;
}
long long SoftwareUpdateInst::getSoftwareUpdateId() const
{
	return software_update_id;
}
void SoftwareUpdateInst::setSoftwareUpdateId(long long value)
{
	software_update_id = value;
}
std::string SoftwareUpdateInst::getPackageName() const
{
	return package_name;
}
void SoftwareUpdateInst::setPackageName(std::string value)
{
	package_name = value;
}
long long SoftwareUpdateInst::getServerId() const
{
	return server_id;
}
void SoftwareUpdateInst::setServerId(long long value)
{
	server_id = value;
}
std::string SoftwareUpdateInst::getStatus() const
{
	return status;
}
void SoftwareUpdateInst::setStatus(std::string value)
{
	status = value;
}

