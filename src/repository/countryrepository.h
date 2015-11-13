#ifndef COUNTRYREPOSITORY_H
#define COUNTRYREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/country.h"
using namespace soci;


class CountryRepository
{
	soci::session& dataBase;
public:
	CountryRepository(soci::session& dataBase);
	int insert(const Country& country);
	CountryPtr select(const Country& country);
	CountryList select(const string& where="");
	void update(const Country& country);
	void update(const Country& oldObj, const Country& newObj);
	void remove(const Country& country);
};

namespace soci
{
template<>
struct type_conversion<Country>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Country & p)
	{
		if (v.get_indicator("Country_iso") != i_null){
			p.setIso( v.template get<std::string>("Country_iso" ) );
		}
		if (v.get_indicator("Country_name") != i_null){
			p.setName( v.template get<std::string>("Country_name" ) );
		}
		if (v.get_indicator("Country_printable_name") != i_null){
			p.setPrintableName( v.template get<std::string>("Country_printable_name" ) );
		}
		if (v.get_indicator("Country_iso3") != i_null){
			p.setIso3( v.template get<std::string>("Country_iso3" ) );
		}
		if (v.get_indicator("Country_numcode") != i_null){
			p.setNumcode( v.template get<int>("Country_numcode" ) );
		}
		if (v.get_indicator("Country_eu") != i_null){
			p.setEu( v.template get<std::string>("Country_eu" ) );
		}
	}
	static void to_base(const Country & p, values & v, indicator & ind)
	{
		v.set( "Country_iso", p.getIso() );
		v.set( "Country_name", p.getName() );
		v.set( "Country_printable_name", p.getPrintableName() );
		v.set( "Country_iso3", p.getIso3() );
		v.set( "Country_numcode", p.getNumcode() );
		v.set( "Country_eu", p.getEu() );
		ind = i_ok;
	}
};
}

#endif // COUNTRYREPOSITORY_H
