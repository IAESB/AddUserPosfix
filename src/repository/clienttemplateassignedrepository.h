#ifndef CLIENTTEMPLATEASSIGNEDREPOSITORY_H
#define CLIENTTEMPLATEASSIGNEDREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/clienttemplateassigned.h"
using namespace soci;


class ClientTemplateAssignedRepository
{
	soci::session& dataBase;
public:
	ClientTemplateAssignedRepository(soci::session& dataBase);
	int insert(const ClientTemplateAssigned& clienttemplateassigned);
	ClientTemplateAssignedPtr select(const ClientTemplateAssigned& clienttemplateassigned);
	ClientTemplateAssignedList select(const string& where="");
	void update(const ClientTemplateAssigned& clienttemplateassigned);
	void update(const ClientTemplateAssigned& oldObj, const ClientTemplateAssigned& newObj);
	void remove(const ClientTemplateAssigned& clienttemplateassigned);
};

namespace soci
{
template<>
struct type_conversion<ClientTemplateAssigned>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ClientTemplateAssigned & p)
	{
		if (v.get_indicator("ClientTemplateAssigned_assigned_template_id") != i_null){
			p.setAssignedTemplateId( v.template get<long long>("ClientTemplateAssigned_assigned_template_id" ) );
		}
		if (v.get_indicator("ClientTemplateAssigned_client_id") != i_null){
			p.setClientId( v.template get<long long>("ClientTemplateAssigned_client_id" ) );
		}
		if (v.get_indicator("ClientTemplateAssigned_client_template_id") != i_null){
			p.setClientTemplateId( v.template get<int>("ClientTemplateAssigned_client_template_id" ) );
		}
	}
	static void to_base(const ClientTemplateAssigned & p, values & v, indicator & ind)
	{
		v.set( "ClientTemplateAssigned_assigned_template_id", p.getAssignedTemplateId() );
		v.set( "ClientTemplateAssigned_client_id", p.getClientId() );
		v.set( "ClientTemplateAssigned_client_template_id", p.getClientTemplateId() );
		ind = i_ok;
	}
};
}

#endif // CLIENTTEMPLATEASSIGNEDREPOSITORY_H
