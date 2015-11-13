#include "attemptslogin.h"

AttemptsLogin::AttemptsLogin(){
	init();
}
void AttemptsLogin::init()
{
	login_time = {0};
}
std::string AttemptsLogin::getIp() const
{
	return ip;
}
void AttemptsLogin::setIp(std::string value)
{
	ip = value;
}
int AttemptsLogin::getTimes() const
{
	return times;
}
void AttemptsLogin::setTimes(int value)
{
	times = value;
}
tm AttemptsLogin::getLoginTime() const
{
	return login_time;
}
void AttemptsLogin::setLoginTime(tm value)
{
	login_time = value;
}

