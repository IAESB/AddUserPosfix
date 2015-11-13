#include <iostream>
#include "util.hpp"
#include "repository/repositoryIsp.h"
#include "repository/repositoryPf.h"

using namespace std;

int main()
{
    RepositoryIsp repoIsp;
    repoIsp.open("mysql://host=192.168.9.99 db=ispconfig user=root password=carteiro");
    RepositoryPf repoPf;
    repoPf.open("mysql://host=192.168.56.1 db=postfix user=root password=root");
    MailboxList mailboxList = repoPf.select<MailboxList>();
    MailUser mailUser;
    mailUser.setSysUserid(1);
    mailUser.setSysGroupid(3);
    mailUser.setSysPermUser("riud");
    mailUser.setSysPermGroup("riud");
    mailUser.setSysPermOther("");
    mailUser.setServerId(1);
    mailUser.setHomedir("/var/vmail");
    mailUser.setBackupCopies(1);
    mailUser.setMailuserId(0);
    mailUser.setUid(5000);
    mailUser.setGid(5000);
    mailUser.setAutoresponder("n");
    mailUser.setMoveJunk("n");
    mailUser.setPostfix("y");
    mailUser.setAccess("y");
    mailUser.setDisableimap("n");
    mailUser.setDisablepop3("n");
    mailUser.setDisabledeliver("n");
    mailUser.setDisablesmtp("n");
    mailUser.setDisablesieve("y");
    mailUser.setDisablesieveFilter("y");
    mailUser.setDisablelda("n");
    mailUser.setDisablelmtp("n");
    mailUser.setDisabledoveadm("n");
    mailUser.setBackupInterval("none");
    mailUser.setBackupCopies(1);

    int cont=0;
    for(MailboxPtr mailBox: mailboxList)
    {
        mailUser.setName(mailBox->getName());
        mailUser.setEmail(mailBox->getUsername());
        mailUser.setLogin(mailBox->getUsername());
        mailUser.setPassword(mailBox->getPassword());
        const string& mailDir = mailBox->getMaildir();
        mailUser.setMaildir("/var/vmail/"+mailDir.substr(0, mailDir.rfind("/Maildir")));
        if(mailBox->getDomain()=="alunos.fasb.edu.br")
            mailUser.setQuota(100*1024*1024);
        else
            mailUser.setQuota(1024*1024*1024);

        repoIsp.insert(mailUser);
        printf("\rinserido %d de %d", ++cont, mailboxList.size());
    }
    cout << "\nCompleto!" << endl;
    return 0;
}

