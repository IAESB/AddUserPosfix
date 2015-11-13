#ifndef ALTERNATIVOMAIL_H
#define ALTERNATIVOMAIL_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class AlternativoMail;
typedef shared_ptr<AlternativoMail> AlternativoMailPtr;
typedef vector<AlternativoMailPtr> AlternativoMailList;

class AlternativoMail
{
	std::string id_mentor; //key: PRI
	std::string alt_cpf;
	std::string alt_mail;
	std::string alt_active;
public:
	AlternativoMail();
	AlternativoMail(std::string id_mentor);
	void init();
	std::string getIdMentor() const;
	void setIdMentor(std::string value);
	std::string getAltCpf() const;
	void setAltCpf(std::string value);
	std::string getAltMail() const;
	void setAltMail(std::string value);
	std::string getAltActive() const;
	void setAltActive(std::string value);
};



#endif // ALTERNATIVOMAIL_H
