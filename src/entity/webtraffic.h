#ifndef WEBTRAFFIC_H
#define WEBTRAFFIC_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebTraffic;
typedef shared_ptr<WebTraffic> WebTrafficPtr;
typedef vector<WebTrafficPtr> WebTrafficList;

class WebTraffic
{
	std::string hostname; //key: PRI
	tm traffic_date; //key: PRI
	unsigned long long traffic_bytes;
public:
	WebTraffic();
	WebTraffic(std::string hostname, tm traffic_date);
	void init();
	std::string getHostname() const;
	void setHostname(std::string value);
	tm getTrafficDate() const;
	void setTrafficDate(tm value);
	unsigned long long getTrafficBytes() const;
	void setTrafficBytes(unsigned long long value);
};



#endif // WEBTRAFFIC_H
