#include "webfolderrepository.h"
#include "util.hpp"
WebFolderRepository::WebFolderRepository(soci::session& db) : dataBase(db)
{
}

WebFolderPtr WebFolderRepository::select(const WebFolder& obj)
{
	soci::row row;
	WebFolderPtr webfolder(new WebFolder);
	dataBase << "SELECT  web_folder.web_folder_id as WebFolder_web_folder_id, web_folder.sys_userid as WebFolder_sys_userid, web_folder.sys_groupid as WebFolder_sys_groupid, web_folder.sys_perm_user as WebFolder_sys_perm_user, web_folder.sys_perm_group as WebFolder_sys_perm_group, web_folder.sys_perm_other as WebFolder_sys_perm_other, web_folder.server_id as WebFolder_server_id, web_folder.parent_domain_id as WebFolder_parent_domain_id, web_folder.path as WebFolder_path, web_folder.active as WebFolder_active"
	" FROM web_folder "
	"WHERE web_folder.web_folder_id = :WebFolder_web_folder_id", into(row), use(obj);
	if(!dataBase.got_data())
		webfolder.reset();
	else
		type_conversion<WebFolder>::from_base(row, i_ok, *webfolder);
	return webfolder;
}
WebFolderList WebFolderRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_folder.web_folder_id as WebFolder_web_folder_id, web_folder.sys_userid as WebFolder_sys_userid, web_folder.sys_groupid as WebFolder_sys_groupid, web_folder.sys_perm_user as WebFolder_sys_perm_user, web_folder.sys_perm_group as WebFolder_sys_perm_group, web_folder.sys_perm_other as WebFolder_sys_perm_other, web_folder.server_id as WebFolder_server_id, web_folder.parent_domain_id as WebFolder_parent_domain_id, web_folder.path as WebFolder_path, web_folder.active as WebFolder_active "
	" FROM web_folder" 
	<< (where.size()?" WHERE "+where:"");
	WebFolderList webfolderList;
	for(row& r: rs)
	{
		WebFolderPtr webfolder(new WebFolder);
		type_conversion<WebFolder>::from_base(r, i_ok, *webfolder);
		webfolderList.push_back(webfolder);
	}
	return webfolderList;
}

int WebFolderRepository::insert(const WebFolder& webfolder)
{
	dataBase << "insert into web_folder(web_folder_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, path, active)\
values(:WebFolder_web_folder_id, :WebFolder_sys_userid, :WebFolder_sys_groupid, :WebFolder_sys_perm_user, :WebFolder_sys_perm_group, :WebFolder_sys_perm_other, :WebFolder_server_id, :WebFolder_parent_domain_id, :WebFolder_path, :WebFolder_active)", use(webfolder);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebFolderRepository::remove(const WebFolder& webfolder)
{
	dataBase << "DELETE from web_folder WHERE web_folder_id=:WebFolder_web_folder_id", use(webfolder);
}

void WebFolderRepository::update(const WebFolder& webfolder)
{
	dataBase << "update web_folder set web_folder_id=:WebFolder_web_folder_id, sys_userid=:WebFolder_sys_userid, sys_groupid=:WebFolder_sys_groupid, sys_perm_user=:WebFolder_sys_perm_user, sys_perm_group=:WebFolder_sys_perm_group, sys_perm_other=:WebFolder_sys_perm_other, server_id=:WebFolder_server_id, parent_domain_id=:WebFolder_parent_domain_id, path=:WebFolder_path, active=:WebFolder_active WHERE web_folder_id=:WebFolder_web_folder_id", use(webfolder);
}

void WebFolderRepository::update(const WebFolder& oldObj, const WebFolder& newObj)
{
	dataBase << "update web_folder set web_folder_id=:WebFolder_web_folder_id, sys_userid=:WebFolder_sys_userid, sys_groupid=:WebFolder_sys_groupid, sys_perm_user=:WebFolder_sys_perm_user, sys_perm_group=:WebFolder_sys_perm_group, sys_perm_other=:WebFolder_sys_perm_other, server_id=:WebFolder_server_id, parent_domain_id=:WebFolder_parent_domain_id, path=:WebFolder_path, active=:WebFolder_active WHERE web_folder_id='"<<oldObj.getWebFolderId()<<"\'", use(newObj);
}

