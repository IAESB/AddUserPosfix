#ifndef ATTEMPTSLOGINREPOSITORY_H
#define ATTEMPTSLOGINREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/attemptslogin.h"
using namespace soci;


class AttemptsLoginRepository
{
	soci::session& dataBase;
public:
	AttemptsLoginRepository(soci::session& dataBase);
	int insert(const AttemptsLogin& attemptslogin);
	AttemptsLoginPtr select(const AttemptsLogin& attemptslogin);
	AttemptsLoginList select(const string& where="");
	void update(const AttemptsLogin& attemptslogin);
	void update(const AttemptsLogin& oldObj, const AttemptsLogin& newObj);
	void remove(const AttemptsLogin& attemptslogin);
};

namespace soci
{
template<>
struct type_conversion<AttemptsLogin>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, AttemptsLogin & p)
	{
		if (v.get_indicator("AttemptsLogin_ip") != i_null){
			p.setIp( v.template get<std::string>("AttemptsLogin_ip" ) );
		}
		if (v.get_indicator("AttemptsLogin_times") != i_null){
			p.setTimes( v.template get<int>("AttemptsLogin_times" ) );
		}
		if (v.get_indicator("AttemptsLogin_login_time") != i_null){
			p.setLoginTime( v.template get<tm>("AttemptsLogin_login_time" ) );
		}
	}
	static void to_base(const AttemptsLogin & p, values & v, indicator & ind)
	{
		v.set( "AttemptsLogin_ip", p.getIp() );
		v.set( "AttemptsLogin_times", p.getTimes() );
		v.set( "AttemptsLogin_login_time", p.getLoginTime() );
		ind = i_ok;
	}
};
}

#endif // ATTEMPTSLOGINREPOSITORY_H
