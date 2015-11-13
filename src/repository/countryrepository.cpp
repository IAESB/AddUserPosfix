#include "countryrepository.h"
#include "util.hpp"
CountryRepository::CountryRepository(soci::session& db) : dataBase(db)
{
}

CountryPtr CountryRepository::select(const Country& obj)
{
	soci::row row;
	CountryPtr country(new Country);
	dataBase << "SELECT  country.iso as Country_iso, country.name as Country_name, country.printable_name as Country_printable_name, country.iso3 as Country_iso3, country.numcode as Country_numcode, country.eu as Country_eu"
	" FROM country "
	"WHERE country.iso = :Country_iso", into(row), use(obj);
	if(!dataBase.got_data())
		country.reset();
	else
		type_conversion<Country>::from_base(row, i_ok, *country);
	return country;
}
CountryList CountryRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  country.iso as Country_iso, country.name as Country_name, country.printable_name as Country_printable_name, country.iso3 as Country_iso3, country.numcode as Country_numcode, country.eu as Country_eu "
	" FROM country" 
	<< (where.size()?" WHERE "+where:"");
	CountryList countryList;
	for(row& r: rs)
	{
		CountryPtr country(new Country);
		type_conversion<Country>::from_base(r, i_ok, *country);
		countryList.push_back(country);
	}
	return countryList;
}

int CountryRepository::insert(const Country& country)
{
	dataBase << "insert into country(iso, name, printable_name, iso3, numcode, eu)\
values(:Country_iso, :Country_name, :Country_printable_name, :Country_iso3, :Country_numcode, :Country_eu)", use(country);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void CountryRepository::remove(const Country& country)
{
	dataBase << "DELETE from country WHERE iso=:Country_iso", use(country);
}

void CountryRepository::update(const Country& country)
{
	dataBase << "update country set iso=:Country_iso, name=:Country_name, printable_name=:Country_printable_name, iso3=:Country_iso3, numcode=:Country_numcode, eu=:Country_eu WHERE iso=:Country_iso", use(country);
}

void CountryRepository::update(const Country& oldObj, const Country& newObj)
{
	dataBase << "update country set iso=:Country_iso, name=:Country_name, printable_name=:Country_printable_name, iso3=:Country_iso3, numcode=:Country_numcode, eu=:Country_eu WHERE iso='"<<oldObj.getIso()<<"\'", use(newObj);
}

