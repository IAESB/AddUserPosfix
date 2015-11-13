#ifndef APSINSTANCESSETTINGS_H
#define APSINSTANCESSETTINGS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ApsInstancesSettings;
typedef shared_ptr<ApsInstancesSettings> ApsInstancesSettingsPtr;
typedef vector<ApsInstancesSettingsPtr> ApsInstancesSettingsList;

class ApsInstancesSettings
{
	int id; //key: PRI
	int server_id;
	int instance_id;
	std::string name;
	std::string value;
public:
	ApsInstancesSettings();
	ApsInstancesSettings(int id);
	void init();
	int getId() const;
	void setId(int value);
	int getServerId() const;
	void setServerId(int value);
	int getInstanceId() const;
	void setInstanceId(int value);
	std::string getName() const;
	void setName(std::string value);
	std::string getValue() const;
	void setValue(std::string value);
};



#endif // APSINSTANCESSETTINGS_H
