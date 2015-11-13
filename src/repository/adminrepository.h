#ifndef ADMINREPOSITORY_H
#define ADMINREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/admin.h"
using namespace soci;


class AdminRepository
{
	soci::session& dataBase;
public:
	AdminRepository(soci::session& dataBase);
	int insert(const Admin& admin);
	AdminPtr select(const Admin& admin);
	AdminList select(const string& where="");
	void update(const Admin& admin);
	void update(const Admin& oldObj, const Admin& newObj);
	void remove(const Admin& admin);
};

namespace soci
{
template<>
struct type_conversion<Admin>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Admin & p)
	{
		if (v.get_indicator("Admin_username") != i_null){
			p.setUsername( v.template get<std::string>("Admin_username" ) );
		}
		if (v.get_indicator("Admin_password") != i_null){
			p.setPassword( v.template get<std::string>("Admin_password" ) );
		}
		if (v.get_indicator("Admin_domain") != i_null){
			p.setDomain( v.template get<std::string>("Admin_domain" ) );
		}
		if (v.get_indicator("Admin_create_date") != i_null){
			p.setCreateDate( v.template get<tm>("Admin_create_date" ) );
		}
		if (v.get_indicator("Admin_change_date") != i_null){
			p.setChangeDate( v.template get<tm>("Admin_change_date" ) );
		}
		if (v.get_indicator("Admin_permite") != i_null){
			p.setPermite( v.template get<std::string>("Admin_permite" ) );
		}
		if (v.get_indicator("Admin_active") != i_null){
			p.setActive( v.template get<int>("Admin_active" ) );
		}
	}
	static void to_base(const Admin & p, values & v, indicator & ind)
	{
		v.set( "Admin_username", p.getUsername() );
		v.set( "Admin_password", p.getPassword() );
		v.set( "Admin_domain", p.getDomain() );
		v.set( "Admin_create_date", p.getCreateDate() );
		v.set( "Admin_change_date", p.getChangeDate() );
		v.set( "Admin_permite", p.getPermite() );
		v.set( "Admin_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // ADMINREPOSITORY_H
