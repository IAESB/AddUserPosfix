#ifndef SOFTWAREUPDATEINST_H
#define SOFTWAREUPDATEINST_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SoftwareUpdateInst;
typedef shared_ptr<SoftwareUpdateInst> SoftwareUpdateInstPtr;
typedef vector<SoftwareUpdateInstPtr> SoftwareUpdateInstList;

class SoftwareUpdateInst
{
	long long software_update_inst_id; //key: PRI
	long long software_update_id; //key: MUL
	std::string package_name;
	long long server_id;
	std::string status;
public:
	SoftwareUpdateInst();
	SoftwareUpdateInst(long long software_update_inst_id);
	void init();
	long long getSoftwareUpdateInstId() const;
	void setSoftwareUpdateInstId(long long value);
	long long getSoftwareUpdateId() const;
	void setSoftwareUpdateId(long long value);
	std::string getPackageName() const;
	void setPackageName(std::string value);
	long long getServerId() const;
	void setServerId(long long value);
	std::string getStatus() const;
	void setStatus(std::string value);
};



#endif // SOFTWAREUPDATEINST_H
