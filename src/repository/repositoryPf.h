#ifndef REPOSITORYPf_H
#define REPOSITORYPf_H
#include <soci/soci.h>
#include <typeinfo>
#include "adminrepository.h"
#include "aliasrepository.h"
#include "alternativomailrepository.h"
#include "domainrepository.h"
#include "mailboxrepository.h"

class RepositoryPf
{
	soci::session dataBase;
	AdminRepository admin;
	AliasRepository alias;
	AlternativoMailRepository alternativomail;
	DomainRepository domain;
	MailboxRepository mailbox;
public:
	RepositoryPf();

	void open(const std::string& connectStringDataBase);
	template<class R, class T> R select(const T& obj);
	template<class T> T select(const string& where="");
	template<class T> int insert(const T& obj);
	template<class T> void update(const T& obj);
	template<class T> void update(const T& oldObj, const T& newObj);
	template<class T> void remove(const T& obj);

};

#endif // REPOSITORYPf_H
