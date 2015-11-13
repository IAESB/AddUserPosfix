#include "monitordata.h"

MonitorData::MonitorData(){
	init();
}
MonitorData::MonitorData(long long server_id, std::string type, long long created)
{
	init();
	this->server_id = server_id;
	this->type = type;
	this->created = created;
}

void MonitorData::init()
{
}
long long MonitorData::getServerId() const
{
	return server_id;
}
void MonitorData::setServerId(long long value)
{
	server_id = value;
}
std::string MonitorData::getType() const
{
	return type;
}
void MonitorData::setType(std::string value)
{
	type = value;
}
long long MonitorData::getCreated() const
{
	return created;
}
void MonitorData::setCreated(long long value)
{
	created = value;
}
std::string MonitorData::getData() const
{
	return data;
}
void MonitorData::setData(std::string value)
{
	data = value;
}
std::string MonitorData::getState() const
{
	return state;
}
void MonitorData::setState(std::string value)
{
	state = value;
}

