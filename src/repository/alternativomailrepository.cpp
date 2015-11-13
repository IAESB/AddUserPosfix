#include "alternativomailrepository.h"
#include "util.hpp"
AlternativoMailRepository::AlternativoMailRepository(soci::session& db) : dataBase(db)
{
}

AlternativoMailPtr AlternativoMailRepository::select(const AlternativoMail& obj)
{
	soci::row row;
	AlternativoMailPtr alternativomail(new AlternativoMail);
	dataBase << "SELECT  alternativo_mail.id_mentor as AlternativoMail_id_mentor, alternativo_mail.alt_cpf as AlternativoMail_alt_cpf, alternativo_mail.alt_mail as AlternativoMail_alt_mail, alternativo_mail.alt_active as AlternativoMail_alt_active"
	" FROM alternativo_mail "
	"WHERE alternativo_mail.id_mentor = :AlternativoMail_id_mentor", into(row), use(obj);
	if(!dataBase.got_data())
		alternativomail.reset();
	else
		type_conversion<AlternativoMail>::from_base(row, i_ok, *alternativomail);
	return alternativomail;
}
AlternativoMailList AlternativoMailRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  alternativo_mail.id_mentor as AlternativoMail_id_mentor, alternativo_mail.alt_cpf as AlternativoMail_alt_cpf, alternativo_mail.alt_mail as AlternativoMail_alt_mail, alternativo_mail.alt_active as AlternativoMail_alt_active "
	" FROM alternativo_mail" 
	<< (where.size()?" WHERE "+where:"");
	AlternativoMailList alternativomailList;
	for(row& r: rs)
	{
		AlternativoMailPtr alternativomail(new AlternativoMail);
		type_conversion<AlternativoMail>::from_base(r, i_ok, *alternativomail);
		alternativomailList.push_back(alternativomail);
	}
	return alternativomailList;
}

int AlternativoMailRepository::insert(const AlternativoMail& alternativomail)
{
	dataBase << "insert into alternativo_mail(id_mentor, alt_cpf, alt_mail, alt_active)\
values(:AlternativoMail_id_mentor, :AlternativoMail_alt_cpf, :AlternativoMail_alt_mail, :AlternativoMail_alt_active)", use(alternativomail);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void AlternativoMailRepository::remove(const AlternativoMail& alternativomail)
{
	dataBase << "DELETE from alternativo_mail WHERE id_mentor=:AlternativoMail_id_mentor", use(alternativomail);
}

void AlternativoMailRepository::update(const AlternativoMail& alternativomail)
{
	dataBase << "update alternativo_mail set id_mentor=:AlternativoMail_id_mentor, alt_cpf=:AlternativoMail_alt_cpf, alt_mail=:AlternativoMail_alt_mail, alt_active=:AlternativoMail_alt_active WHERE id_mentor=:AlternativoMail_id_mentor", use(alternativomail);
}

void AlternativoMailRepository::update(const AlternativoMail& oldObj, const AlternativoMail& newObj)
{
	dataBase << "update alternativo_mail set id_mentor=:AlternativoMail_id_mentor, alt_cpf=:AlternativoMail_alt_cpf, alt_mail=:AlternativoMail_alt_mail, alt_active=:AlternativoMail_alt_active WHERE id_mentor='"<<oldObj.getIdMentor()<<"\'", use(newObj);
}

