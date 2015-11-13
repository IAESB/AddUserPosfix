#include "mailbox.h"

Mailbox::Mailbox(){
	init();
}
Mailbox::Mailbox(std::string username)
{
	init();
	this->username = username;
}

void Mailbox::init()
{
	create_date = {0};
	change_date = {0};
}
std::string Mailbox::getUsername() const
{
	return username;
}
void Mailbox::setUsername(std::string value)
{
	username = value;
}
std::string Mailbox::getPassword() const
{
	return password;
}
void Mailbox::setPassword(std::string value)
{
	password = value;
}
std::string Mailbox::getName() const
{
	return name;
}
void Mailbox::setName(std::string value)
{
	name = value;
}
std::string Mailbox::getHome() const
{
	return home;
}
void Mailbox::setHome(std::string value)
{
	home = value;
}
std::string Mailbox::getMaildir() const
{
	return maildir;
}
void Mailbox::setMaildir(std::string value)
{
	maildir = value;
}
std::string Mailbox::getQuota() const
{
	return quota;
}
void Mailbox::setQuota(std::string value)
{
	quota = value;
}
std::string Mailbox::getDomain() const
{
	return domain;
}
void Mailbox::setDomain(std::string value)
{
	domain = value;
}
tm Mailbox::getCreateDate() const
{
	return create_date;
}
void Mailbox::setCreateDate(tm value)
{
	create_date = value;
}
tm Mailbox::getChangeDate() const
{
	return change_date;
}
void Mailbox::setChangeDate(tm value)
{
	change_date = value;
}
int Mailbox::getActive() const
{
	return active;
}
void Mailbox::setActive(int value)
{
	active = value;
}
std::string Mailbox::getPasswdExpire() const
{
	return passwd_expire;
}
void Mailbox::setPasswdExpire(std::string value)
{
	passwd_expire = value;
}
long long Mailbox::getUid() const
{
	return uid;
}
void Mailbox::setUid(long long value)
{
	uid = value;
}
long long Mailbox::getGid() const
{
	return gid;
}
void Mailbox::setGid(long long value)
{
	gid = value;
}
std::string Mailbox::getIdMentor() const
{
	return id_mentor;
}
void Mailbox::setIdMentor(std::string value)
{
	id_mentor = value;
}
std::string Mailbox::getTipoConta() const
{
	return tipo_conta;
}
void Mailbox::setTipoConta(std::string value)
{
	tipo_conta = value;
}
std::string Mailbox::getAssina() const
{
	return assina;
}
void Mailbox::setAssina(std::string value)
{
	assina = value;
}
long long Mailbox::getMatricula() const
{
	return matricula;
}
void Mailbox::setMatricula(long long value)
{
	matricula = value;
}

