#include "clientcirclerepository.h"
#include "util.hpp"
ClientCircleRepository::ClientCircleRepository(soci::session& db) : dataBase(db)
{
}

ClientCirclePtr ClientCircleRepository::select(const ClientCircle& obj)
{
	soci::row row;
	ClientCirclePtr clientcircle(new ClientCircle);
	dataBase << "SELECT  client_circle.circle_id as ClientCircle_circle_id, client_circle.sys_userid as ClientCircle_sys_userid, client_circle.sys_groupid as ClientCircle_sys_groupid, client_circle.sys_perm_user as ClientCircle_sys_perm_user, client_circle.sys_perm_group as ClientCircle_sys_perm_group, client_circle.sys_perm_other as ClientCircle_sys_perm_other, client_circle.circle_name as ClientCircle_circle_name, client_circle.client_ids as ClientCircle_client_ids, client_circle.description as ClientCircle_description, client_circle.active as ClientCircle_active"
	" FROM client_circle "
	"WHERE client_circle.circle_id = :ClientCircle_circle_id", into(row), use(obj);
	if(!dataBase.got_data())
		clientcircle.reset();
	else
		type_conversion<ClientCircle>::from_base(row, i_ok, *clientcircle);
	return clientcircle;
}
ClientCircleList ClientCircleRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  client_circle.circle_id as ClientCircle_circle_id, client_circle.sys_userid as ClientCircle_sys_userid, client_circle.sys_groupid as ClientCircle_sys_groupid, client_circle.sys_perm_user as ClientCircle_sys_perm_user, client_circle.sys_perm_group as ClientCircle_sys_perm_group, client_circle.sys_perm_other as ClientCircle_sys_perm_other, client_circle.circle_name as ClientCircle_circle_name, client_circle.client_ids as ClientCircle_client_ids, client_circle.description as ClientCircle_description, client_circle.active as ClientCircle_active "
	" FROM client_circle" 
	<< (where.size()?" WHERE "+where:"");
	ClientCircleList clientcircleList;
	for(row& r: rs)
	{
		ClientCirclePtr clientcircle(new ClientCircle);
		type_conversion<ClientCircle>::from_base(r, i_ok, *clientcircle);
		clientcircleList.push_back(clientcircle);
	}
	return clientcircleList;
}

int ClientCircleRepository::insert(const ClientCircle& clientcircle)
{
	dataBase << "insert into client_circle(circle_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, circle_name, client_ids, description, active)\
values(:ClientCircle_circle_id, :ClientCircle_sys_userid, :ClientCircle_sys_groupid, :ClientCircle_sys_perm_user, :ClientCircle_sys_perm_group, :ClientCircle_sys_perm_other, :ClientCircle_circle_name, :ClientCircle_client_ids, :ClientCircle_description, :ClientCircle_active)", use(clientcircle);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ClientCircleRepository::remove(const ClientCircle& clientcircle)
{
	dataBase << "DELETE from client_circle WHERE circle_id=:ClientCircle_circle_id", use(clientcircle);
}

void ClientCircleRepository::update(const ClientCircle& clientcircle)
{
	dataBase << "update client_circle set circle_id=:ClientCircle_circle_id, sys_userid=:ClientCircle_sys_userid, sys_groupid=:ClientCircle_sys_groupid, sys_perm_user=:ClientCircle_sys_perm_user, sys_perm_group=:ClientCircle_sys_perm_group, sys_perm_other=:ClientCircle_sys_perm_other, circle_name=:ClientCircle_circle_name, client_ids=:ClientCircle_client_ids, description=:ClientCircle_description, active=:ClientCircle_active WHERE circle_id=:ClientCircle_circle_id", use(clientcircle);
}

void ClientCircleRepository::update(const ClientCircle& oldObj, const ClientCircle& newObj)
{
	dataBase << "update client_circle set circle_id=:ClientCircle_circle_id, sys_userid=:ClientCircle_sys_userid, sys_groupid=:ClientCircle_sys_groupid, sys_perm_user=:ClientCircle_sys_perm_user, sys_perm_group=:ClientCircle_sys_perm_group, sys_perm_other=:ClientCircle_sys_perm_other, circle_name=:ClientCircle_circle_name, client_ids=:ClientCircle_client_ids, description=:ClientCircle_description, active=:ClientCircle_active WHERE circle_id='"<<oldObj.getCircleId()<<"\'", use(newObj);
}

