#include "clienttemplateassigned.h"

ClientTemplateAssigned::ClientTemplateAssigned(){
	init();
}
ClientTemplateAssigned::ClientTemplateAssigned(long long assigned_template_id)
{
	init();
	this->assigned_template_id = assigned_template_id;
}

void ClientTemplateAssigned::init()
{
}
long long ClientTemplateAssigned::getAssignedTemplateId() const
{
	return assigned_template_id;
}
void ClientTemplateAssigned::setAssignedTemplateId(long long value)
{
	assigned_template_id = value;
}
long long ClientTemplateAssigned::getClientId() const
{
	return client_id;
}
void ClientTemplateAssigned::setClientId(long long value)
{
	client_id = value;
}
int ClientTemplateAssigned::getClientTemplateId() const
{
	return client_template_id;
}
void ClientTemplateAssigned::setClientTemplateId(int value)
{
	client_template_id = value;
}

