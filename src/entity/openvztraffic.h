#ifndef OPENVZTRAFFIC_H
#define OPENVZTRAFFIC_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class OpenvzTraffic;
typedef shared_ptr<OpenvzTraffic> OpenvzTrafficPtr;
typedef vector<OpenvzTrafficPtr> OpenvzTrafficList;

class OpenvzTraffic
{
	int veid; //key: PRI
	tm traffic_date; //key: PRI
	unsigned long long traffic_bytes;
public:
	OpenvzTraffic();
	OpenvzTraffic(int veid, tm traffic_date);
	void init();
	int getVeid() const;
	void setVeid(int value);
	tm getTrafficDate() const;
	void setTrafficDate(tm value);
	unsigned long long getTrafficBytes() const;
	void setTrafficBytes(unsigned long long value);
};



#endif // OPENVZTRAFFIC_H
