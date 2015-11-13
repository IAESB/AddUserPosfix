#include "repositoryPf.h"
RepositoryPf::RepositoryPf() :admin(dataBase) ,alias(dataBase) ,alternativomail(dataBase) ,domain(dataBase) ,mailbox(dataBase) 
{}
void RepositoryPf::open(const std::string& connectStringDataBase)
{
	if(connectStringDataBase.size())
		dataBase.open(connectStringDataBase);
	else
		throw runtime_error("connectStringDataBase is EMPTY, info a url to connect in data base");
}

template<> AdminPtr RepositoryPf::select(const Admin& obj)
{
	return admin.select(obj);
}
template<> AdminList RepositoryPf::select(const string& where)
{
	return admin.select(where);
}
template<> int RepositoryPf::insert(const Admin& obj)
{
	return admin.insert(obj);
}
template<> void RepositoryPf::update(const Admin& obj)
{
	admin.update(obj);
}
template<> void RepositoryPf::update(const Admin& oldObj, const Admin& newObj)
{
	admin.update(oldObj, newObj);
}
template<> void RepositoryPf::remove(const Admin& obj)
{
	admin.remove(obj);
}

template<> AliasPtr RepositoryPf::select(const Alias& obj)
{
	return alias.select(obj);
}
template<> AliasList RepositoryPf::select(const string& where)
{
	return alias.select(where);
}
template<> int RepositoryPf::insert(const Alias& obj)
{
	return alias.insert(obj);
}
template<> void RepositoryPf::update(const Alias& obj)
{
	alias.update(obj);
}
template<> void RepositoryPf::update(const Alias& oldObj, const Alias& newObj)
{
	alias.update(oldObj, newObj);
}
template<> void RepositoryPf::remove(const Alias& obj)
{
	alias.remove(obj);
}

template<> AlternativoMailPtr RepositoryPf::select(const AlternativoMail& obj)
{
	return alternativomail.select(obj);
}
template<> AlternativoMailList RepositoryPf::select(const string& where)
{
	return alternativomail.select(where);
}
template<> int RepositoryPf::insert(const AlternativoMail& obj)
{
	return alternativomail.insert(obj);
}
template<> void RepositoryPf::update(const AlternativoMail& obj)
{
	alternativomail.update(obj);
}
template<> void RepositoryPf::update(const AlternativoMail& oldObj, const AlternativoMail& newObj)
{
	alternativomail.update(oldObj, newObj);
}
template<> void RepositoryPf::remove(const AlternativoMail& obj)
{
	alternativomail.remove(obj);
}

template<> DomainPtr RepositoryPf::select(const Domain& obj)
{
	return domain.select(obj);
}
template<> DomainList RepositoryPf::select(const string& where)
{
	return domain.select(where);
}
template<> int RepositoryPf::insert(const Domain& obj)
{
	return domain.insert(obj);
}
template<> void RepositoryPf::update(const Domain& obj)
{
	domain.update(obj);
}
template<> void RepositoryPf::update(const Domain& oldObj, const Domain& newObj)
{
	domain.update(oldObj, newObj);
}
template<> void RepositoryPf::remove(const Domain& obj)
{
	domain.remove(obj);
}

template<> MailboxPtr RepositoryPf::select(const Mailbox& obj)
{
	return mailbox.select(obj);
}
template<> MailboxList RepositoryPf::select(const string& where)
{
	return mailbox.select(where);
}
template<> int RepositoryPf::insert(const Mailbox& obj)
{
	return mailbox.insert(obj);
}
template<> void RepositoryPf::update(const Mailbox& obj)
{
	mailbox.update(obj);
}
template<> void RepositoryPf::update(const Mailbox& oldObj, const Mailbox& newObj)
{
	mailbox.update(oldObj, newObj);
}
template<> void RepositoryPf::remove(const Mailbox& obj)
{
	mailbox.remove(obj);
}
