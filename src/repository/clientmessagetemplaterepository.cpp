#include "clientmessagetemplaterepository.h"
#include "util.hpp"
ClientMessageTemplateRepository::ClientMessageTemplateRepository(soci::session& db) : dataBase(db)
{
}

ClientMessageTemplatePtr ClientMessageTemplateRepository::select(const ClientMessageTemplate& obj)
{
	soci::row row;
	ClientMessageTemplatePtr clientmessagetemplate(new ClientMessageTemplate);
	dataBase << "SELECT  client_message_template.client_message_template_id as ClientMessageTemplate_client_message_template_id, client_message_template.sys_userid as ClientMessageTemplate_sys_userid, client_message_template.sys_groupid as ClientMessageTemplate_sys_groupid, client_message_template.sys_perm_user as ClientMessageTemplate_sys_perm_user, client_message_template.sys_perm_group as ClientMessageTemplate_sys_perm_group, client_message_template.sys_perm_other as ClientMessageTemplate_sys_perm_other, client_message_template.template_type as ClientMessageTemplate_template_type, client_message_template.template_name as ClientMessageTemplate_template_name, client_message_template.subject as ClientMessageTemplate_subject, client_message_template.message as ClientMessageTemplate_message"
	" FROM client_message_template "
	"WHERE client_message_template.client_message_template_id = :ClientMessageTemplate_client_message_template_id", into(row), use(obj);
	if(!dataBase.got_data())
		clientmessagetemplate.reset();
	else
		type_conversion<ClientMessageTemplate>::from_base(row, i_ok, *clientmessagetemplate);
	return clientmessagetemplate;
}
ClientMessageTemplateList ClientMessageTemplateRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  client_message_template.client_message_template_id as ClientMessageTemplate_client_message_template_id, client_message_template.sys_userid as ClientMessageTemplate_sys_userid, client_message_template.sys_groupid as ClientMessageTemplate_sys_groupid, client_message_template.sys_perm_user as ClientMessageTemplate_sys_perm_user, client_message_template.sys_perm_group as ClientMessageTemplate_sys_perm_group, client_message_template.sys_perm_other as ClientMessageTemplate_sys_perm_other, client_message_template.template_type as ClientMessageTemplate_template_type, client_message_template.template_name as ClientMessageTemplate_template_name, client_message_template.subject as ClientMessageTemplate_subject, client_message_template.message as ClientMessageTemplate_message "
	" FROM client_message_template" 
	<< (where.size()?" WHERE "+where:"");
	ClientMessageTemplateList clientmessagetemplateList;
	for(row& r: rs)
	{
		ClientMessageTemplatePtr clientmessagetemplate(new ClientMessageTemplate);
		type_conversion<ClientMessageTemplate>::from_base(r, i_ok, *clientmessagetemplate);
		clientmessagetemplateList.push_back(clientmessagetemplate);
	}
	return clientmessagetemplateList;
}

int ClientMessageTemplateRepository::insert(const ClientMessageTemplate& clientmessagetemplate)
{
	dataBase << "insert into client_message_template(client_message_template_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, template_type, template_name, subject, message)\
values(:ClientMessageTemplate_client_message_template_id, :ClientMessageTemplate_sys_userid, :ClientMessageTemplate_sys_groupid, :ClientMessageTemplate_sys_perm_user, :ClientMessageTemplate_sys_perm_group, :ClientMessageTemplate_sys_perm_other, :ClientMessageTemplate_template_type, :ClientMessageTemplate_template_name, :ClientMessageTemplate_subject, :ClientMessageTemplate_message)", use(clientmessagetemplate);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ClientMessageTemplateRepository::remove(const ClientMessageTemplate& clientmessagetemplate)
{
	dataBase << "DELETE from client_message_template WHERE client_message_template_id=:ClientMessageTemplate_client_message_template_id", use(clientmessagetemplate);
}

void ClientMessageTemplateRepository::update(const ClientMessageTemplate& clientmessagetemplate)
{
	dataBase << "update client_message_template set client_message_template_id=:ClientMessageTemplate_client_message_template_id, sys_userid=:ClientMessageTemplate_sys_userid, sys_groupid=:ClientMessageTemplate_sys_groupid, sys_perm_user=:ClientMessageTemplate_sys_perm_user, sys_perm_group=:ClientMessageTemplate_sys_perm_group, sys_perm_other=:ClientMessageTemplate_sys_perm_other, template_type=:ClientMessageTemplate_template_type, template_name=:ClientMessageTemplate_template_name, subject=:ClientMessageTemplate_subject, message=:ClientMessageTemplate_message WHERE client_message_template_id=:ClientMessageTemplate_client_message_template_id", use(clientmessagetemplate);
}

void ClientMessageTemplateRepository::update(const ClientMessageTemplate& oldObj, const ClientMessageTemplate& newObj)
{
	dataBase << "update client_message_template set client_message_template_id=:ClientMessageTemplate_client_message_template_id, sys_userid=:ClientMessageTemplate_sys_userid, sys_groupid=:ClientMessageTemplate_sys_groupid, sys_perm_user=:ClientMessageTemplate_sys_perm_user, sys_perm_group=:ClientMessageTemplate_sys_perm_group, sys_perm_other=:ClientMessageTemplate_sys_perm_other, template_type=:ClientMessageTemplate_template_type, template_name=:ClientMessageTemplate_template_name, subject=:ClientMessageTemplate_subject, message=:ClientMessageTemplate_message WHERE client_message_template_id='"<<oldObj.getClientMessageTemplateId()<<"\'", use(newObj);
}

