#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Mailbox;
typedef shared_ptr<Mailbox> MailboxPtr;
typedef vector<MailboxPtr> MailboxList;

class Mailbox
{
	std::string username; //key: PRI
	std::string password;
	std::string name;
	std::string home;
	std::string maildir;
	std::string quota;
	std::string domain;
	tm create_date;
	tm change_date;
	int active;
	std::string passwd_expire;
	long long uid;
	long long gid;
	std::string id_mentor;
	std::string tipo_conta;
	std::string assina;
	long long matricula;
public:
	Mailbox();
	Mailbox(std::string username);
	void init();
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	std::string getName() const;
	void setName(std::string value);
	std::string getHome() const;
	void setHome(std::string value);
	std::string getMaildir() const;
	void setMaildir(std::string value);
	std::string getQuota() const;
	void setQuota(std::string value);
	std::string getDomain() const;
	void setDomain(std::string value);
	tm getCreateDate() const;
	void setCreateDate(tm value);
	tm getChangeDate() const;
	void setChangeDate(tm value);
	int getActive() const;
	void setActive(int value);
	std::string getPasswdExpire() const;
	void setPasswdExpire(std::string value);
	long long getUid() const;
	void setUid(long long value);
	long long getGid() const;
	void setGid(long long value);
	std::string getIdMentor() const;
	void setIdMentor(std::string value);
	std::string getTipoConta() const;
	void setTipoConta(std::string value);
	std::string getAssina() const;
	void setAssina(std::string value);
	long long getMatricula() const;
	void setMatricula(long long value);
};



#endif // MAILBOX_H
