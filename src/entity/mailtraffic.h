#ifndef MAILTRAFFIC_H
#define MAILTRAFFIC_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailTraffic;
typedef shared_ptr<MailTraffic> MailTrafficPtr;
typedef vector<MailTrafficPtr> MailTrafficList;

class MailTraffic
{
	long long traffic_id; //key: PRI
	long long mailuser_id; //key: MUL
	std::string month;
	unsigned long long traffic;
public:
	MailTraffic();
	MailTraffic(long long traffic_id);
	void init();
	long long getTrafficId() const;
	void setTrafficId(long long value);
	long long getMailuserId() const;
	void setMailuserId(long long value);
	std::string getMonth() const;
	void setMonth(std::string value);
	unsigned long long getTraffic() const;
	void setTraffic(unsigned long long value);
};



#endif // MAILTRAFFIC_H
