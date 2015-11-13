#include "softwareupdate.h"

SoftwareUpdate::SoftwareUpdate(){
	init();
}
SoftwareUpdate::SoftwareUpdate(long long software_update_id)
{
	init();
	this->software_update_id = software_update_id;
}

void SoftwareUpdate::init()
{
}
long long SoftwareUpdate::getSoftwareUpdateId() const
{
	return software_update_id;
}
void SoftwareUpdate::setSoftwareUpdateId(long long value)
{
	software_update_id = value;
}
long long SoftwareUpdate::getSoftwareRepoId() const
{
	return software_repo_id;
}
void SoftwareUpdate::setSoftwareRepoId(long long value)
{
	software_repo_id = value;
}
std::string SoftwareUpdate::getPackageName() const
{
	return package_name;
}
void SoftwareUpdate::setPackageName(std::string value)
{
	package_name = value;
}
std::string SoftwareUpdate::getUpdateUrl() const
{
	return update_url;
}
void SoftwareUpdate::setUpdateUrl(std::string value)
{
	update_url = value;
}
std::string SoftwareUpdate::getUpdateMd5() const
{
	return update_md5;
}
void SoftwareUpdate::setUpdateMd5(std::string value)
{
	update_md5 = value;
}
std::string SoftwareUpdate::getUpdateDependencies() const
{
	return update_dependencies;
}
void SoftwareUpdate::setUpdateDependencies(std::string value)
{
	update_dependencies = value;
}
std::string SoftwareUpdate::getUpdateTitle() const
{
	return update_title;
}
void SoftwareUpdate::setUpdateTitle(std::string value)
{
	update_title = value;
}
int SoftwareUpdate::getV1() const
{
	return v1;
}
void SoftwareUpdate::setV1(int value)
{
	v1 = value;
}
int SoftwareUpdate::getV2() const
{
	return v2;
}
void SoftwareUpdate::setV2(int value)
{
	v2 = value;
}
int SoftwareUpdate::getV3() const
{
	return v3;
}
void SoftwareUpdate::setV3(int value)
{
	v3 = value;
}
int SoftwareUpdate::getV4() const
{
	return v4;
}
void SoftwareUpdate::setV4(int value)
{
	v4 = value;
}
std::string SoftwareUpdate::getType() const
{
	return type;
}
void SoftwareUpdate::setType(std::string value)
{
	type = value;
}

