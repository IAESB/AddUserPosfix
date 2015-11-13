#ifndef MAILBOXREPOSITORY_H
#define MAILBOXREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailbox.h"
using namespace soci;


class MailboxRepository
{
	soci::session& dataBase;
public:
	MailboxRepository(soci::session& dataBase);
	int insert(const Mailbox& mailbox);
	MailboxPtr select(const Mailbox& mailbox);
	MailboxList select(const string& where="");
	void update(const Mailbox& mailbox);
	void update(const Mailbox& oldObj, const Mailbox& newObj);
	void remove(const Mailbox& mailbox);
};

namespace soci
{
template<>
struct type_conversion<Mailbox>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Mailbox & p)
	{
		if (v.get_indicator("Mailbox_username") != i_null){
			p.setUsername( v.template get<std::string>("Mailbox_username" ) );
		}
		if (v.get_indicator("Mailbox_password") != i_null){
			p.setPassword( v.template get<std::string>("Mailbox_password" ) );
		}
		if (v.get_indicator("Mailbox_name") != i_null){
			p.setName( v.template get<std::string>("Mailbox_name" ) );
		}
		if (v.get_indicator("Mailbox_home") != i_null){
			p.setHome( v.template get<std::string>("Mailbox_home" ) );
		}
		if (v.get_indicator("Mailbox_maildir") != i_null){
			p.setMaildir( v.template get<std::string>("Mailbox_maildir" ) );
		}
		if (v.get_indicator("Mailbox_quota") != i_null){
			p.setQuota( v.template get<std::string>("Mailbox_quota" ) );
		}
		if (v.get_indicator("Mailbox_domain") != i_null){
			p.setDomain( v.template get<std::string>("Mailbox_domain" ) );
		}
		if (v.get_indicator("Mailbox_create_date") != i_null){
			p.setCreateDate( v.template get<tm>("Mailbox_create_date" ) );
		}
		if (v.get_indicator("Mailbox_change_date") != i_null){
			p.setChangeDate( v.template get<tm>("Mailbox_change_date" ) );
		}
		if (v.get_indicator("Mailbox_active") != i_null){
			p.setActive( v.template get<int>("Mailbox_active" ) );
		}
		if (v.get_indicator("Mailbox_passwd_expire") != i_null){
			p.setPasswdExpire( v.template get<std::string>("Mailbox_passwd_expire" ) );
		}
		if (v.get_indicator("Mailbox_uid") != i_null){
			p.setUid( v.template get<long long>("Mailbox_uid" ) );
		}
		if (v.get_indicator("Mailbox_gid") != i_null){
			p.setGid( v.template get<long long>("Mailbox_gid" ) );
		}
		if (v.get_indicator("Mailbox_id_mentor") != i_null){
			p.setIdMentor( v.template get<std::string>("Mailbox_id_mentor" ) );
		}
		if (v.get_indicator("Mailbox_tipo_conta") != i_null){
			p.setTipoConta( v.template get<std::string>("Mailbox_tipo_conta" ) );
		}
		if (v.get_indicator("Mailbox_assina") != i_null){
			p.setAssina( v.template get<std::string>("Mailbox_assina" ) );
		}
		if (v.get_indicator("Mailbox_matricula") != i_null){
			p.setMatricula( v.template get<long long>("Mailbox_matricula" ) );
		}
	}
	static void to_base(const Mailbox & p, values & v, indicator & ind)
	{
		v.set( "Mailbox_username", p.getUsername() );
		v.set( "Mailbox_password", p.getPassword() );
		v.set( "Mailbox_name", p.getName() );
		v.set( "Mailbox_home", p.getHome() );
		v.set( "Mailbox_maildir", p.getMaildir() );
		v.set( "Mailbox_quota", p.getQuota() );
		v.set( "Mailbox_domain", p.getDomain() );
		v.set( "Mailbox_create_date", p.getCreateDate() );
		v.set( "Mailbox_change_date", p.getChangeDate() );
		v.set( "Mailbox_active", p.getActive() );
		v.set( "Mailbox_passwd_expire", p.getPasswdExpire() );
		v.set( "Mailbox_uid", p.getUid() );
		v.set( "Mailbox_gid", p.getGid() );
		v.set( "Mailbox_id_mentor", p.getIdMentor() );
		v.set( "Mailbox_tipo_conta", p.getTipoConta() );
		v.set( "Mailbox_assina", p.getAssina() );
		v.set( "Mailbox_matricula", p.getMatricula() );
		ind = i_ok;
	}
};
}

#endif // MAILBOXREPOSITORY_H
