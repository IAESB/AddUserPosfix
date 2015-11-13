#ifndef SOFTWAREUPDATE_H
#define SOFTWAREUPDATE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SoftwareUpdate;
typedef shared_ptr<SoftwareUpdate> SoftwareUpdatePtr;
typedef vector<SoftwareUpdatePtr> SoftwareUpdateList;

class SoftwareUpdate
{
	long long software_update_id; //key: PRI
	long long software_repo_id;
	std::string package_name;
	std::string update_url;
	std::string update_md5;
	std::string update_dependencies;
	std::string update_title;
	int v1;
	int v2;
	int v3;
	int v4;
	std::string type;
public:
	SoftwareUpdate();
	SoftwareUpdate(long long software_update_id);
	void init();
	long long getSoftwareUpdateId() const;
	void setSoftwareUpdateId(long long value);
	long long getSoftwareRepoId() const;
	void setSoftwareRepoId(long long value);
	std::string getPackageName() const;
	void setPackageName(std::string value);
	std::string getUpdateUrl() const;
	void setUpdateUrl(std::string value);
	std::string getUpdateMd5() const;
	void setUpdateMd5(std::string value);
	std::string getUpdateDependencies() const;
	void setUpdateDependencies(std::string value);
	std::string getUpdateTitle() const;
	void setUpdateTitle(std::string value);
	int getV1() const;
	void setV1(int value);
	int getV2() const;
	void setV2(int value);
	int getV3() const;
	void setV3(int value);
	int getV4() const;
	void setV4(int value);
	std::string getType() const;
	void setType(std::string value);
};



#endif // SOFTWAREUPDATE_H
