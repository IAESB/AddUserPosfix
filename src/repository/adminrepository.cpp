#include "adminrepository.h"
#include "util.hpp"
AdminRepository::AdminRepository(soci::session& db) : dataBase(db)
{
}

AdminPtr AdminRepository::select(const Admin& obj)
{
	soci::row row;
	AdminPtr admin(new Admin);
	dataBase << "SELECT  admin.username as Admin_username, admin.password as Admin_password, admin.domain as Admin_domain, admin.create_date as Admin_create_date, admin.change_date as Admin_change_date, admin.permite as Admin_permite, admin.active as Admin_active"
	" FROM admin "
	"WHERE admin.username = :Admin_username", into(row), use(obj);
	if(!dataBase.got_data())
		admin.reset();
	else
		type_conversion<Admin>::from_base(row, i_ok, *admin);
	return admin;
}
AdminList AdminRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  admin.username as Admin_username, admin.password as Admin_password, admin.domain as Admin_domain, admin.create_date as Admin_create_date, admin.change_date as Admin_change_date, admin.permite as Admin_permite, admin.active as Admin_active "
	" FROM admin" 
	<< (where.size()?" WHERE "+where:"");
	AdminList adminList;
	for(row& r: rs)
	{
		AdminPtr admin(new Admin);
		type_conversion<Admin>::from_base(r, i_ok, *admin);
		adminList.push_back(admin);
	}
	return adminList;
}

int AdminRepository::insert(const Admin& admin)
{
	dataBase << "insert into admin(username, password, domain, create_date, change_date, permite, active)\
values(:Admin_username, :Admin_password, :Admin_domain, :Admin_create_date, :Admin_change_date, :Admin_permite, :Admin_active)", use(admin);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void AdminRepository::remove(const Admin& admin)
{
	dataBase << "DELETE from admin WHERE username=:Admin_username", use(admin);
}

void AdminRepository::update(const Admin& admin)
{
	dataBase << "update admin set username=:Admin_username, password=:Admin_password, domain=:Admin_domain, create_date=:Admin_create_date, change_date=:Admin_change_date, permite=:Admin_permite, active=:Admin_active WHERE username=:Admin_username", use(admin);
}

void AdminRepository::update(const Admin& oldObj, const Admin& newObj)
{
	dataBase << "update admin set username=:Admin_username, password=:Admin_password, domain=:Admin_domain, create_date=:Admin_create_date, change_date=:Admin_change_date, permite=:Admin_permite, active=:Admin_active WHERE username='"<<oldObj.getUsername()<<"\'", use(newObj);
}

