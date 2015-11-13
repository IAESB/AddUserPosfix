#include "syscron.h"

SysCron::SysCron(){
	init();
}
SysCron::SysCron(std::string name)
{
	init();
	this->name = name;
}

void SysCron::init()
{
	last_run = {0};
	next_run = {0};
}
std::string SysCron::getName() const
{
	return name;
}
void SysCron::setName(std::string value)
{
	name = value;
}
tm SysCron::getLastRun() const
{
	return last_run;
}
void SysCron::setLastRun(tm value)
{
	last_run = value;
}
tm SysCron::getNextRun() const
{
	return next_run;
}
void SysCron::setNextRun(tm value)
{
	next_run = value;
}
int SysCron::getRunning() const
{
	return running;
}
void SysCron::setRunning(int value)
{
	running = value;
}

