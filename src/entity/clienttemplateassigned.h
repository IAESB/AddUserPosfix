#ifndef CLIENTTEMPLATEASSIGNED_H
#define CLIENTTEMPLATEASSIGNED_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ClientTemplateAssigned;
typedef shared_ptr<ClientTemplateAssigned> ClientTemplateAssignedPtr;
typedef vector<ClientTemplateAssignedPtr> ClientTemplateAssignedList;

class ClientTemplateAssigned
{
	long long assigned_template_id; //key: PRI
	long long client_id; //key: MUL
	int client_template_id;
public:
	ClientTemplateAssigned();
	ClientTemplateAssigned(long long assigned_template_id);
	void init();
	long long getAssignedTemplateId() const;
	void setAssignedTemplateId(long long value);
	long long getClientId() const;
	void setClientId(long long value);
	int getClientTemplateId() const;
	void setClientTemplateId(int value);
};



#endif // CLIENTTEMPLATEASSIGNED_H
