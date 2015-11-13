#include "mailtrafficrepository.h"
#include "util.hpp"
MailTrafficRepository::MailTrafficRepository(soci::session& db) : dataBase(db)
{
}

MailTrafficPtr MailTrafficRepository::select(const MailTraffic& obj)
{
	soci::row row;
	MailTrafficPtr mailtraffic(new MailTraffic);
	dataBase << "SELECT  mail_traffic.traffic_id as MailTraffic_traffic_id, mail_traffic.mailuser_id as MailTraffic_mailuser_id, mail_traffic.month as MailTraffic_month, mail_traffic.traffic as MailTraffic_traffic"
	" FROM mail_traffic "
	"WHERE mail_traffic.traffic_id = :MailTraffic_traffic_id AND mail_traffic.mailuser_id = :MailTraffic_mailuser_id", into(row), use(obj);
	if(!dataBase.got_data())
		mailtraffic.reset();
	else
		type_conversion<MailTraffic>::from_base(row, i_ok, *mailtraffic);
	return mailtraffic;
}
MailTrafficList MailTrafficRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  mail_traffic.traffic_id as MailTraffic_traffic_id, mail_traffic.mailuser_id as MailTraffic_mailuser_id, mail_traffic.month as MailTraffic_month, mail_traffic.traffic as MailTraffic_traffic "
	" FROM mail_traffic" 
	<< (where.size()?" WHERE "+where:"");
	MailTrafficList mailtrafficList;
	for(row& r: rs)
	{
		MailTrafficPtr mailtraffic(new MailTraffic);
		type_conversion<MailTraffic>::from_base(r, i_ok, *mailtraffic);
		mailtrafficList.push_back(mailtraffic);
	}
	return mailtrafficList;
}

int MailTrafficRepository::insert(const MailTraffic& mailtraffic)
{
	dataBase << "insert into mail_traffic(traffic_id, mailuser_id, month, traffic)\
values(:MailTraffic_traffic_id, :MailTraffic_mailuser_id, :MailTraffic_month, :MailTraffic_traffic)", use(mailtraffic);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MailTrafficRepository::remove(const MailTraffic& mailtraffic)
{
	dataBase << "DELETE from mail_traffic WHERE traffic_id=:MailTraffic_traffic_id AND mailuser_id=:MailTraffic_mailuser_id", use(mailtraffic);
}

void MailTrafficRepository::update(const MailTraffic& mailtraffic)
{
	dataBase << "update mail_traffic set traffic_id=:MailTraffic_traffic_id, mailuser_id=:MailTraffic_mailuser_id, month=:MailTraffic_month, traffic=:MailTraffic_traffic WHERE traffic_id=:MailTraffic_traffic_id AND mailuser_id=:MailTraffic_mailuser_id", use(mailtraffic);
}

void MailTrafficRepository::update(const MailTraffic& oldObj, const MailTraffic& newObj)
{
	dataBase << "update mail_traffic set traffic_id=:MailTraffic_traffic_id, mailuser_id=:MailTraffic_mailuser_id, month=:MailTraffic_month, traffic=:MailTraffic_traffic WHERE traffic_id='"<<oldObj.getTrafficId()<<"\'' AND mailuser_id='"<<oldObj.getMailuserId()<<"\'", use(newObj);
}

