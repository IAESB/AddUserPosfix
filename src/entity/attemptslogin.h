#ifndef ATTEMPTSLOGIN_H
#define ATTEMPTSLOGIN_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class AttemptsLogin;
typedef shared_ptr<AttemptsLogin> AttemptsLoginPtr;
typedef vector<AttemptsLoginPtr> AttemptsLoginList;

class AttemptsLogin
{
	std::string ip;
	int times;
	tm login_time;
public:
	AttemptsLogin();
	void init();
	std::string getIp() const;
	void setIp(std::string value);
	int getTimes() const;
	void setTimes(int value);
	tm getLoginTime() const;
	void setLoginTime(tm value);
};



#endif // ATTEMPTSLOGIN_H
