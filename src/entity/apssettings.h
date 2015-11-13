#ifndef APSSETTINGS_H
#define APSSETTINGS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ApsSettings;
typedef shared_ptr<ApsSettings> ApsSettingsPtr;
typedef vector<ApsSettingsPtr> ApsSettingsList;

class ApsSettings
{
	int id; //key: PRI
	std::string name; //key: UNI
	std::string value;
public:
	ApsSettings();
	ApsSettings(int id);
	void init();
	int getId() const;
	void setId(int value);
	std::string getName() const;
	void setName(std::string value);
	std::string getValue() const;
	void setValue(std::string value);
};



#endif // APSSETTINGS_H
