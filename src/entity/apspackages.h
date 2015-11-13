#ifndef APSPACKAGES_H
#define APSPACKAGES_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ApsPackages;
typedef shared_ptr<ApsPackages> ApsPackagesPtr;
typedef vector<ApsPackagesPtr> ApsPackagesList;

class ApsPackages
{
	int id; //key: PRI
	std::string path;
	std::string name;
	std::string category;
	std::string version;
	int release;
	std::string package_url;
	int package_status;
public:
	ApsPackages();
	ApsPackages(int id);
	void init();
	int getId() const;
	void setId(int value);
	std::string getPath() const;
	void setPath(std::string value);
	std::string getName() const;
	void setName(std::string value);
	std::string getCategory() const;
	void setCategory(std::string value);
	std::string getVersion() const;
	void setVersion(std::string value);
	int getRelease() const;
	void setRelease(int value);
	std::string getPackageUrl() const;
	void setPackageUrl(std::string value);
	int getPackageStatus() const;
	void setPackageStatus(int value);
};



#endif // APSPACKAGES_H
