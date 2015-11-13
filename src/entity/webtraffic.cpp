#include "webtraffic.h"

WebTraffic::WebTraffic(){
	init();
}
WebTraffic::WebTraffic(std::string hostname, tm traffic_date)
{
	init();
	this->hostname = hostname;
	this->traffic_date = traffic_date;
}

void WebTraffic::init()
{
	traffic_date = {0};
}
std::string WebTraffic::getHostname() const
{
	return hostname;
}
void WebTraffic::setHostname(std::string value)
{
	hostname = value;
}
tm WebTraffic::getTrafficDate() const
{
	return traffic_date;
}
void WebTraffic::setTrafficDate(tm value)
{
	traffic_date = value;
}
unsigned long long WebTraffic::getTrafficBytes() const
{
	return traffic_bytes;
}
void WebTraffic::setTrafficBytes(unsigned long long value)
{
	traffic_bytes = value;
}

