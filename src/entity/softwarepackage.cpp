#include "softwarepackage.h"

SoftwarePackage::SoftwarePackage(){
	init();
}
SoftwarePackage::SoftwarePackage(long long package_id)
{
	init();
	this->package_id = package_id;
}

void SoftwarePackage::init()
{
}
long long SoftwarePackage::getPackageId() const
{
	return package_id;
}
void SoftwarePackage::setPackageId(long long value)
{
	package_id = value;
}
long long SoftwarePackage::getSoftwareRepoId() const
{
	return software_repo_id;
}
void SoftwarePackage::setSoftwareRepoId(long long value)
{
	software_repo_id = value;
}
std::string SoftwarePackage::getPackageName() const
{
	return package_name;
}
void SoftwarePackage::setPackageName(std::string value)
{
	package_name = value;
}
std::string SoftwarePackage::getPackageTitle() const
{
	return package_title;
}
void SoftwarePackage::setPackageTitle(std::string value)
{
	package_title = value;
}
std::string SoftwarePackage::getPackageDescription() const
{
	return package_description;
}
void SoftwarePackage::setPackageDescription(std::string value)
{
	package_description = value;
}
std::string SoftwarePackage::getPackageVersion() const
{
	return package_version;
}
void SoftwarePackage::setPackageVersion(std::string value)
{
	package_version = value;
}
std::string SoftwarePackage::getPackageType() const
{
	return package_type;
}
void SoftwarePackage::setPackageType(std::string value)
{
	package_type = value;
}
std::string SoftwarePackage::getPackageInstallable() const
{
	return package_installable;
}
void SoftwarePackage::setPackageInstallable(std::string value)
{
	package_installable = value;
}
std::string SoftwarePackage::getPackageRequiresDb() const
{
	return package_requires_db;
}
void SoftwarePackage::setPackageRequiresDb(std::string value)
{
	package_requires_db = value;
}
std::string SoftwarePackage::getPackageRemoteFunctions() const
{
	return package_remote_functions;
}
void SoftwarePackage::setPackageRemoteFunctions(std::string value)
{
	package_remote_functions = value;
}
std::string SoftwarePackage::getPackageKey() const
{
	return package_key;
}
void SoftwarePackage::setPackageKey(std::string value)
{
	package_key = value;
}
std::string SoftwarePackage::getPackageConfig() const
{
	return package_config;
}
void SoftwarePackage::setPackageConfig(std::string value)
{
	package_config = value;
}

