#include "clienttemplateassignedrepository.h"
#include "util.hpp"
ClientTemplateAssignedRepository::ClientTemplateAssignedRepository(soci::session& db) : dataBase(db)
{
}

ClientTemplateAssignedPtr ClientTemplateAssignedRepository::select(const ClientTemplateAssigned& obj)
{
	soci::row row;
	ClientTemplateAssignedPtr clienttemplateassigned(new ClientTemplateAssigned);
	dataBase << "SELECT  client_template_assigned.assigned_template_id as ClientTemplateAssigned_assigned_template_id, client_template_assigned.client_id as ClientTemplateAssigned_client_id, client_template_assigned.client_template_id as ClientTemplateAssigned_client_template_id"
	" FROM client_template_assigned "
	"WHERE client_template_assigned.assigned_template_id = :ClientTemplateAssigned_assigned_template_id AND client_template_assigned.client_id = :ClientTemplateAssigned_client_id", into(row), use(obj);
	if(!dataBase.got_data())
		clienttemplateassigned.reset();
	else
		type_conversion<ClientTemplateAssigned>::from_base(row, i_ok, *clienttemplateassigned);
	return clienttemplateassigned;
}
ClientTemplateAssignedList ClientTemplateAssignedRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  client_template_assigned.assigned_template_id as ClientTemplateAssigned_assigned_template_id, client_template_assigned.client_id as ClientTemplateAssigned_client_id, client_template_assigned.client_template_id as ClientTemplateAssigned_client_template_id "
	" FROM client_template_assigned" 
	<< (where.size()?" WHERE "+where:"");
	ClientTemplateAssignedList clienttemplateassignedList;
	for(row& r: rs)
	{
		ClientTemplateAssignedPtr clienttemplateassigned(new ClientTemplateAssigned);
		type_conversion<ClientTemplateAssigned>::from_base(r, i_ok, *clienttemplateassigned);
		clienttemplateassignedList.push_back(clienttemplateassigned);
	}
	return clienttemplateassignedList;
}

int ClientTemplateAssignedRepository::insert(const ClientTemplateAssigned& clienttemplateassigned)
{
	dataBase << "insert into client_template_assigned(assigned_template_id, client_id, client_template_id)\
values(:ClientTemplateAssigned_assigned_template_id, :ClientTemplateAssigned_client_id, :ClientTemplateAssigned_client_template_id)", use(clienttemplateassigned);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ClientTemplateAssignedRepository::remove(const ClientTemplateAssigned& clienttemplateassigned)
{
	dataBase << "DELETE from client_template_assigned WHERE assigned_template_id=:ClientTemplateAssigned_assigned_template_id AND client_id=:ClientTemplateAssigned_client_id", use(clienttemplateassigned);
}

void ClientTemplateAssignedRepository::update(const ClientTemplateAssigned& clienttemplateassigned)
{
	dataBase << "update client_template_assigned set assigned_template_id=:ClientTemplateAssigned_assigned_template_id, client_id=:ClientTemplateAssigned_client_id, client_template_id=:ClientTemplateAssigned_client_template_id WHERE assigned_template_id=:ClientTemplateAssigned_assigned_template_id AND client_id=:ClientTemplateAssigned_client_id", use(clienttemplateassigned);
}

void ClientTemplateAssignedRepository::update(const ClientTemplateAssigned& oldObj, const ClientTemplateAssigned& newObj)
{
	dataBase << "update client_template_assigned set assigned_template_id=:ClientTemplateAssigned_assigned_template_id, client_id=:ClientTemplateAssigned_client_id, client_template_id=:ClientTemplateAssigned_client_template_id WHERE assigned_template_id='"<<oldObj.getAssignedTemplateId()<<"\'' AND client_id='"<<oldObj.getClientId()<<"\'", use(newObj);
}

