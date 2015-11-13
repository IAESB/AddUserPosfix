#include "alternativomail.h"

AlternativoMail::AlternativoMail(){
	init();
}
AlternativoMail::AlternativoMail(std::string id_mentor)
{
	init();
	this->id_mentor = id_mentor;
}

void AlternativoMail::init()
{
}
std::string AlternativoMail::getIdMentor() const
{
	return id_mentor;
}
void AlternativoMail::setIdMentor(std::string value)
{
	id_mentor = value;
}
std::string AlternativoMail::getAltCpf() const
{
	return alt_cpf;
}
void AlternativoMail::setAltCpf(std::string value)
{
	alt_cpf = value;
}
std::string AlternativoMail::getAltMail() const
{
	return alt_mail;
}
void AlternativoMail::setAltMail(std::string value)
{
	alt_mail = value;
}
std::string AlternativoMail::getAltActive() const
{
	return alt_active;
}
void AlternativoMail::setAltActive(std::string value)
{
	alt_active = value;
}

