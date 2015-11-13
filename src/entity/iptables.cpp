#include "iptables.h"

Iptables::Iptables(){
	init();
}
Iptables::Iptables(long long iptables_id)
{
	init();
	this->iptables_id = iptables_id;
}

void Iptables::init()
{
}
long long Iptables::getIptablesId() const
{
	return iptables_id;
}
void Iptables::setIptablesId(long long value)
{
	iptables_id = value;
}
long long Iptables::getServerId() const
{
	return server_id;
}
void Iptables::setServerId(long long value)
{
	server_id = value;
}
std::string Iptables::getTable() const
{
	return table;
}
void Iptables::setTable(std::string value)
{
	table = value;
}
std::string Iptables::getSourceIp() const
{
	return source_ip;
}
void Iptables::setSourceIp(std::string value)
{
	source_ip = value;
}
std::string Iptables::getDestinationIp() const
{
	return destination_ip;
}
void Iptables::setDestinationIp(std::string value)
{
	destination_ip = value;
}
std::string Iptables::getProtocol() const
{
	return protocol;
}
void Iptables::setProtocol(std::string value)
{
	protocol = value;
}
std::string Iptables::getSingleport() const
{
	return singleport;
}
void Iptables::setSingleport(std::string value)
{
	singleport = value;
}
std::string Iptables::getMultiport() const
{
	return multiport;
}
void Iptables::setMultiport(std::string value)
{
	multiport = value;
}
std::string Iptables::getState() const
{
	return state;
}
void Iptables::setState(std::string value)
{
	state = value;
}
std::string Iptables::getTarget() const
{
	return target;
}
void Iptables::setTarget(std::string value)
{
	target = value;
}
std::string Iptables::getActive() const
{
	return active;
}
void Iptables::setActive(std::string value)
{
	active = value;
}

