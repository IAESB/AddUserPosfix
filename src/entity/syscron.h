#ifndef SYSCRON_H
#define SYSCRON_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysCron;
typedef shared_ptr<SysCron> SysCronPtr;
typedef vector<SysCronPtr> SysCronList;

class SysCron
{
	std::string name; //key: PRI
	tm last_run;
	tm next_run;
	int running;
public:
	SysCron();
	SysCron(std::string name);
	void init();
	std::string getName() const;
	void setName(std::string value);
	tm getLastRun() const;
	void setLastRun(tm value);
	tm getNextRun() const;
	void setNextRun(tm value);
	int getRunning() const;
	void setRunning(int value);
};



#endif // SYSCRON_H
