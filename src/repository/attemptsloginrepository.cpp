#include "attemptsloginrepository.h"
#include "util.hpp"
AttemptsLoginRepository::AttemptsLoginRepository(soci::session& db) : dataBase(db)
{
}

AttemptsLoginPtr AttemptsLoginRepository::select(const AttemptsLogin& obj)
{
	soci::row row;
	AttemptsLoginPtr attemptslogin(new AttemptsLogin);
	dataBase << "SELECT  attempts_login.ip as AttemptsLogin_ip, attempts_login.times as AttemptsLogin_times, attempts_login.login_time as AttemptsLogin_login_time"
	" FROM attempts_login "
	"WHERE ", into(row), use(obj);
	if(!dataBase.got_data())
		attemptslogin.reset();
	else
		type_conversion<AttemptsLogin>::from_base(row, i_ok, *attemptslogin);
	return attemptslogin;
}
AttemptsLoginList AttemptsLoginRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  attempts_login.ip as AttemptsLogin_ip, attempts_login.times as AttemptsLogin_times, attempts_login.login_time as AttemptsLogin_login_time "
	" FROM attempts_login" 
	<< (where.size()?" WHERE "+where:"");
	AttemptsLoginList attemptsloginList;
	for(row& r: rs)
	{
		AttemptsLoginPtr attemptslogin(new AttemptsLogin);
		type_conversion<AttemptsLogin>::from_base(r, i_ok, *attemptslogin);
		attemptsloginList.push_back(attemptslogin);
	}
	return attemptsloginList;
}

int AttemptsLoginRepository::insert(const AttemptsLogin& attemptslogin)
{
	dataBase << "insert into attempts_login(ip, times, login_time)\
values(:AttemptsLogin_ip, :AttemptsLogin_times, :AttemptsLogin_login_time)", use(attemptslogin);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void AttemptsLoginRepository::remove(const AttemptsLogin& attemptslogin)
{
	dataBase << "DELETE from attempts_login WHERE ", use(attemptslogin);
}

void AttemptsLoginRepository::update(const AttemptsLogin& attemptslogin)
{
	dataBase << "update attempts_login set ip=:AttemptsLogin_ip, times=:AttemptsLogin_times, login_time=:AttemptsLogin_login_time WHERE ", use(attemptslogin);
}

void AttemptsLoginRepository::update(const AttemptsLogin& oldObj, const AttemptsLogin& newObj)
{
	dataBase << "update attempts_login set ip=:AttemptsLogin_ip, times=:AttemptsLogin_times, login_time=:AttemptsLogin_login_time WHERE ", use(newObj);
}

