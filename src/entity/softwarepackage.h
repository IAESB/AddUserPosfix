#ifndef SOFTWAREPACKAGE_H
#define SOFTWAREPACKAGE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SoftwarePackage;
typedef shared_ptr<SoftwarePackage> SoftwarePackagePtr;
typedef vector<SoftwarePackagePtr> SoftwarePackageList;

class SoftwarePackage
{
	long long package_id; //key: PRI
	long long software_repo_id;
	std::string package_name; //key: UNI
	std::string package_title;
	std::string package_description;
	std::string package_version;
	std::string package_type;
	std::string package_installable;
	std::string package_requires_db;
	std::string package_remote_functions;
	std::string package_key;
	std::string package_config;
public:
	SoftwarePackage();
	SoftwarePackage(long long package_id);
	void init();
	long long getPackageId() const;
	void setPackageId(long long value);
	long long getSoftwareRepoId() const;
	void setSoftwareRepoId(long long value);
	std::string getPackageName() const;
	void setPackageName(std::string value);
	std::string getPackageTitle() const;
	void setPackageTitle(std::string value);
	std::string getPackageDescription() const;
	void setPackageDescription(std::string value);
	std::string getPackageVersion() const;
	void setPackageVersion(std::string value);
	std::string getPackageType() const;
	void setPackageType(std::string value);
	std::string getPackageInstallable() const;
	void setPackageInstallable(std::string value);
	std::string getPackageRequiresDb() const;
	void setPackageRequiresDb(std::string value);
	std::string getPackageRemoteFunctions() const;
	void setPackageRemoteFunctions(std::string value);
	std::string getPackageKey() const;
	void setPackageKey(std::string value);
	std::string getPackageConfig() const;
	void setPackageConfig(std::string value);
};



#endif // SOFTWAREPACKAGE_H
