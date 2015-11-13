#include "openvztraffic.h"

OpenvzTraffic::OpenvzTraffic(){
	init();
}
OpenvzTraffic::OpenvzTraffic(int veid, tm traffic_date)
{
	init();
	this->veid = veid;
	this->traffic_date = traffic_date;
}

void OpenvzTraffic::init()
{
	traffic_date = {0};
}
int OpenvzTraffic::getVeid() const
{
	return veid;
}
void OpenvzTraffic::setVeid(int value)
{
	veid = value;
}
tm OpenvzTraffic::getTrafficDate() const
{
	return traffic_date;
}
void OpenvzTraffic::setTrafficDate(tm value)
{
	traffic_date = value;
}
unsigned long long OpenvzTraffic::getTrafficBytes() const
{
	return traffic_bytes;
}
void OpenvzTraffic::setTrafficBytes(unsigned long long value)
{
	traffic_bytes = value;
}

