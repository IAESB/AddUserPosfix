#ifndef MONITORDATA_H
#define MONITORDATA_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MonitorData;
typedef shared_ptr<MonitorData> MonitorDataPtr;
typedef vector<MonitorDataPtr> MonitorDataList;

class MonitorData
{
	long long server_id; //key: PRI
	std::string type; //key: PRI
	long long created; //key: PRI
	std::string data;
	std::string state;
public:
	MonitorData();
	MonitorData(long long server_id, std::string type, long long created);
	void init();
	long long getServerId() const;
	void setServerId(long long value);
	std::string getType() const;
	void setType(std::string value);
	long long getCreated() const;
	void setCreated(long long value);
	std::string getData() const;
	void setData(std::string value);
	std::string getState() const;
	void setState(std::string value);
};



#endif // MONITORDATA_H
