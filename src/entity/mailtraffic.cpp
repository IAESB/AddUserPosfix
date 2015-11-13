#include "mailtraffic.h"

MailTraffic::MailTraffic(){
	init();
}
MailTraffic::MailTraffic(long long traffic_id)
{
	init();
	this->traffic_id = traffic_id;
}

void MailTraffic::init()
{
}
long long MailTraffic::getTrafficId() const
{
	return traffic_id;
}
void MailTraffic::setTrafficId(long long value)
{
	traffic_id = value;
}
long long MailTraffic::getMailuserId() const
{
	return mailuser_id;
}
void MailTraffic::setMailuserId(long long value)
{
	mailuser_id = value;
}
std::string MailTraffic::getMonth() const
{
	return month;
}
void MailTraffic::setMonth(std::string value)
{
	month = value;
}
unsigned long long MailTraffic::getTraffic() const
{
	return traffic;
}
void MailTraffic::setTraffic(unsigned long long value)
{
	traffic = value;
}

