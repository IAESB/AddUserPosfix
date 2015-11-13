#include "apsinstancessettings.h"

ApsInstancesSettings::ApsInstancesSettings(){
	init();
}
ApsInstancesSettings::ApsInstancesSettings(int id)
{
	init();
	this->id = id;
}

void ApsInstancesSettings::init()
{
}
int ApsInstancesSettings::getId() const
{
	return id;
}
void ApsInstancesSettings::setId(int value)
{
	id = value;
}
int ApsInstancesSettings::getServerId() const
{
	return server_id;
}
void ApsInstancesSettings::setServerId(int value)
{
	server_id = value;
}
int ApsInstancesSettings::getInstanceId() const
{
	return instance_id;
}
void ApsInstancesSettings::setInstanceId(int value)
{
	instance_id = value;
}
std::string ApsInstancesSettings::getName() const
{
	return name;
}
void ApsInstancesSettings::setName(std::string value)
{
	name = value;
}
std::string ApsInstancesSettings::getValue() const
{
	return value;
}
void ApsInstancesSettings::setValue(std::string value)
{
	value = value;
}

