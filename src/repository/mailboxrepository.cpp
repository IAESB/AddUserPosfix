#include "mailboxrepository.h"
#include "util.hpp"
MailboxRepository::MailboxRepository(soci::session& db) : dataBase(db)
{
}

MailboxPtr MailboxRepository::select(const Mailbox& obj)
{
	soci::row row;
	MailboxPtr mailbox(new Mailbox);
	dataBase << "SELECT  mailbox.username as Mailbox_username, mailbox.password as Mailbox_password, mailbox.name as Mailbox_name, mailbox.home as Mailbox_home, mailbox.maildir as Mailbox_maildir, mailbox.quota as Mailbox_quota, mailbox.domain as Mailbox_domain, mailbox.create_date as Mailbox_create_date, mailbox.change_date as Mailbox_change_date, mailbox.active as Mailbox_active, mailbox.passwd_expire as Mailbox_passwd_expire, mailbox.uid as Mailbox_uid, mailbox.gid as Mailbox_gid, mailbox.id_mentor as Mailbox_id_mentor, mailbox.tipo_conta as Mailbox_tipo_conta, mailbox.assina as Mailbox_assina, mailbox.matricula as Mailbox_matricula"
	" FROM mailbox "
	"WHERE mailbox.username = :Mailbox_username", into(row), use(obj);
	if(!dataBase.got_data())
		mailbox.reset();
	else
		type_conversion<Mailbox>::from_base(row, i_ok, *mailbox);
	return mailbox;
}
MailboxList MailboxRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mailbox.username as Mailbox_username, mailbox.password as Mailbox_password, mailbox.name as Mailbox_name, mailbox.home as Mailbox_home, mailbox.maildir as Mailbox_maildir, mailbox.quota as Mailbox_quota, mailbox.domain as Mailbox_domain, mailbox.create_date as Mailbox_create_date, mailbox.change_date as Mailbox_change_date, mailbox.active as Mailbox_active, mailbox.passwd_expire as Mailbox_passwd_expire, mailbox.uid as Mailbox_uid, mailbox.gid as Mailbox_gid, mailbox.id_mentor as Mailbox_id_mentor, mailbox.tipo_conta as Mailbox_tipo_conta, mailbox.assina as Mailbox_assina, mailbox.matricula as Mailbox_matricula "
	" FROM mailbox" 
	<< (where.size()?" WHERE "+where:"");
	MailboxList mailboxList;
	for(row& r: rs)
	{
		MailboxPtr mailbox(new Mailbox);
		type_conversion<Mailbox>::from_base(r, i_ok, *mailbox);
		mailboxList.push_back(mailbox);
	}
	return mailboxList;
}

int MailboxRepository::insert(const Mailbox& mailbox)
{
	dataBase << "insert into mailbox(username, password, name, home, maildir, quota, domain, create_date, change_date, active, passwd_expire, uid, gid, id_mentor, tipo_conta, assina, matricula)\
values(:Mailbox_username, :Mailbox_password, :Mailbox_name, :Mailbox_home, :Mailbox_maildir, :Mailbox_quota, :Mailbox_domain, :Mailbox_create_date, :Mailbox_change_date, :Mailbox_active, :Mailbox_passwd_expire, :Mailbox_uid, :Mailbox_gid, :Mailbox_id_mentor, :Mailbox_tipo_conta, :Mailbox_assina, :Mailbox_matricula)", use(mailbox);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailboxRepository::remove(const Mailbox& mailbox)
{
	dataBase << "DELETE from mailbox WHERE username=:Mailbox_username", use(mailbox);
}

void MailboxRepository::update(const Mailbox& mailbox)
{
	dataBase << "update mailbox set username=:Mailbox_username, password=:Mailbox_password, name=:Mailbox_name, home=:Mailbox_home, maildir=:Mailbox_maildir, quota=:Mailbox_quota, domain=:Mailbox_domain, create_date=:Mailbox_create_date, change_date=:Mailbox_change_date, active=:Mailbox_active, passwd_expire=:Mailbox_passwd_expire, uid=:Mailbox_uid, gid=:Mailbox_gid, id_mentor=:Mailbox_id_mentor, tipo_conta=:Mailbox_tipo_conta, assina=:Mailbox_assina, matricula=:Mailbox_matricula WHERE username=:Mailbox_username", use(mailbox);
}

void MailboxRepository::update(const Mailbox& oldObj, const Mailbox& newObj)
{
	dataBase << "update mailbox set username=:Mailbox_username, password=:Mailbox_password, name=:Mailbox_name, home=:Mailbox_home, maildir=:Mailbox_maildir, quota=:Mailbox_quota, domain=:Mailbox_domain, create_date=:Mailbox_create_date, change_date=:Mailbox_change_date, active=:Mailbox_active, passwd_expire=:Mailbox_passwd_expire, uid=:Mailbox_uid, gid=:Mailbox_gid, id_mentor=:Mailbox_id_mentor, tipo_conta=:Mailbox_tipo_conta, assina=:Mailbox_assina, matricula=:Mailbox_matricula WHERE username='"<<oldObj.getUsername()<<"\'", use(newObj);
}

