#include "aliasrepository.h"
#include "util.hpp"
AliasRepository::AliasRepository(soci::session& db) : dataBase(db)
{
}

AliasPtr AliasRepository::select(const Alias& obj)
{
	soci::row row;
	AliasPtr alias(new Alias);
	dataBase << "SELECT  alias.address as Alias_address, alias.goto as Alias_goto_, alias.domain as Alias_domain, alias.create_date as Alias_create_date, alias.change_date as Alias_change_date, alias.add_info as Alias_add_info, alias.active as Alias_active"
	" FROM alias "
	"WHERE alias.address = :Alias_address", into(row), use(obj);
	if(!dataBase.got_data())
		alias.reset();
	else
		type_conversion<Alias>::from_base(row, i_ok, *alias);
	return alias;
}
AliasList AliasRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  alias.address as Alias_address, alias.goto as Alias_goto_, alias.domain as Alias_domain, alias.create_date as Alias_create_date, alias.change_date as Alias_change_date, alias.add_info as Alias_add_info, alias.active as Alias_active "
	" FROM alias" 
	<< (where.size()?" WHERE "+where:"");
	AliasList aliasList;
	for(row& r: rs)
	{
		AliasPtr alias(new Alias);
		type_conversion<Alias>::from_base(r, i_ok, *alias);
		aliasList.push_back(alias);
	}
	return aliasList;
}

int AliasRepository::insert(const Alias& alias)
{
	dataBase << "insert into alias(address, goto_, domain, create_date, change_date, add_info, active)\
values(:Alias_address, :Alias_goto_, :Alias_domain, :Alias_create_date, :Alias_change_date, :Alias_add_info, :Alias_active)", use(alias);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void AliasRepository::remove(const Alias& alias)
{
	dataBase << "DELETE from alias WHERE address=:Alias_address", use(alias);
}

void AliasRepository::update(const Alias& alias)
{
	dataBase << "update alias set address=:Alias_address, goto_=:Alias_goto_, domain=:Alias_domain, create_date=:Alias_create_date, change_date=:Alias_change_date, add_info=:Alias_add_info, active=:Alias_active WHERE address=:Alias_address", use(alias);
}

void AliasRepository::update(const Alias& oldObj, const Alias& newObj)
{
	dataBase << "update alias set address=:Alias_address, goto_=:Alias_goto_, domain=:Alias_domain, create_date=:Alias_create_date, change_date=:Alias_change_date, add_info=:Alias_add_info, active=:Alias_active WHERE address='"<<oldObj.getAddress()<<"\'", use(newObj);
}

