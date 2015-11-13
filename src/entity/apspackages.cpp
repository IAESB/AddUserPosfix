#include "apspackages.h"

ApsPackages::ApsPackages(){
	init();
}
ApsPackages::ApsPackages(int id)
{
	init();
	this->id = id;
}

void ApsPackages::init()
{
}
int ApsPackages::getId() const
{
	return id;
}
void ApsPackages::setId(int value)
{
	id = value;
}
std::string ApsPackages::getPath() const
{
	return path;
}
void ApsPackages::setPath(std::string value)
{
	path = value;
}
std::string ApsPackages::getName() const
{
	return name;
}
void ApsPackages::setName(std::string value)
{
	name = value;
}
std::string ApsPackages::getCategory() const
{
	return category;
}
void ApsPackages::setCategory(std::string value)
{
	category = value;
}
std::string ApsPackages::getVersion() const
{
	return version;
}
void ApsPackages::setVersion(std::string value)
{
	version = value;
}
int ApsPackages::getRelease() const
{
	return release;
}
void ApsPackages::setRelease(int value)
{
	release = value;
}
std::string ApsPackages::getPackageUrl() const
{
	return package_url;
}
void ApsPackages::setPackageUrl(std::string value)
{
	package_url = value;
}
int ApsPackages::getPackageStatus() const
{
	return package_status;
}
void ApsPackages::setPackageStatus(int value)
{
	package_status = value;
}

