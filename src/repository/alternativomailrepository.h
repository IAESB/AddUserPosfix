#ifndef ALTERNATIVOMAILREPOSITORY_H
#define ALTERNATIVOMAILREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/alternativomail.h"
using namespace soci;


class AlternativoMailRepository
{
	soci::session& dataBase;
public:
	AlternativoMailRepository(soci::session& dataBase);
	int insert(const AlternativoMail& alternativomail);
	AlternativoMailPtr select(const AlternativoMail& alternativomail);
	AlternativoMailList select(const string& where="");
	void update(const AlternativoMail& alternativomail);
	void update(const AlternativoMail& oldObj, const AlternativoMail& newObj);
	void remove(const AlternativoMail& alternativomail);
};

namespace soci
{
template<>
struct type_conversion<AlternativoMail>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, AlternativoMail & p)
	{
		if (v.get_indicator("AlternativoMail_id_mentor") != i_null){
			p.setIdMentor( v.template get<std::string>("AlternativoMail_id_mentor" ) );
		}
		if (v.get_indicator("AlternativoMail_alt_cpf") != i_null){
			p.setAltCpf( v.template get<std::string>("AlternativoMail_alt_cpf" ) );
		}
		if (v.get_indicator("AlternativoMail_alt_mail") != i_null){
			p.setAltMail( v.template get<std::string>("AlternativoMail_alt_mail" ) );
		}
		if (v.get_indicator("AlternativoMail_alt_active") != i_null){
			p.setAltActive( v.template get<std::string>("AlternativoMail_alt_active" ) );
		}
	}
	static void to_base(const AlternativoMail & p, values & v, indicator & ind)
	{
		v.set( "AlternativoMail_id_mentor", p.getIdMentor() );
		v.set( "AlternativoMail_alt_cpf", p.getAltCpf() );
		v.set( "AlternativoMail_alt_mail", p.getAltMail() );
		v.set( "AlternativoMail_alt_active", p.getAltActive() );
		ind = i_ok;
	}
};
}

#endif // ALTERNATIVOMAILREPOSITORY_H
