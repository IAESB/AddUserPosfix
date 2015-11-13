#include "serverphprepository.h"
#include "util.hpp"
ServerPhpRepository::ServerPhpRepository(soci::session& db) : dataBase(db)
{
}

ServerPhpPtr ServerPhpRepository::select(const ServerPhp& obj)
{
	soci::row row;
	ServerPhpPtr serverphp(new ServerPhp);
	dataBase << "SELECT  server_php.server_php_id as ServerPhp_server_php_id, server_php.sys_userid as ServerPhp_sys_userid, server_php.sys_groupid as ServerPhp_sys_groupid, server_php.sys_perm_user as ServerPhp_sys_perm_user, server_php.sys_perm_group as ServerPhp_sys_perm_group, server_php.sys_perm_other as ServerPhp_sys_perm_other, server_php.server_id as ServerPhp_server_id, server_php.client_id as ServerPhp_client_id, server_php.name as ServerPhp_name, server_php.php_fastcgi_binary as ServerPhp_php_fastcgi_binary, server_php.php_fastcgi_ini_dir as ServerPhp_php_fastcgi_ini_dir, server_php.php_fpm_init_script as ServerPhp_php_fpm_init_script, server_php.php_fpm_ini_dir as ServerPhp_php_fpm_ini_dir, server_php.php_fpm_pool_dir as ServerPhp_php_fpm_pool_dir"
	" FROM server_php "
	"WHERE server_php.server_php_id = :ServerPhp_server_php_id", into(row), use(obj);
	if(!dataBase.got_data())
		serverphp.reset();
	else
		type_conversion<ServerPhp>::from_base(row, i_ok, *serverphp);
	return serverphp;
}
ServerPhpList ServerPhpRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  server_php.server_php_id as ServerPhp_server_php_id, server_php.sys_userid as ServerPhp_sys_userid, server_php.sys_groupid as ServerPhp_sys_groupid, server_php.sys_perm_user as ServerPhp_sys_perm_user, server_php.sys_perm_group as ServerPhp_sys_perm_group, server_php.sys_perm_other as ServerPhp_sys_perm_other, server_php.server_id as ServerPhp_server_id, server_php.client_id as ServerPhp_client_id, server_php.name as ServerPhp_name, server_php.php_fastcgi_binary as ServerPhp_php_fastcgi_binary, server_php.php_fastcgi_ini_dir as ServerPhp_php_fastcgi_ini_dir, server_php.php_fpm_init_script as ServerPhp_php_fpm_init_script, server_php.php_fpm_ini_dir as ServerPhp_php_fpm_ini_dir, server_php.php_fpm_pool_dir as ServerPhp_php_fpm_pool_dir "
	" FROM server_php" 
	<< (where.size()?" WHERE "+where:"");
	ServerPhpList serverphpList;
	for(row& r: rs)
	{
		ServerPhpPtr serverphp(new ServerPhp);
		type_conversion<ServerPhp>::from_base(r, i_ok, *serverphp);
		serverphpList.push_back(serverphp);
	}
	return serverphpList;
}

int ServerPhpRepository::insert(const ServerPhp& serverphp)
{
	dataBase << "insert into server_php(server_php_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, client_id, name, php_fastcgi_binary, php_fastcgi_ini_dir, php_fpm_init_script, php_fpm_ini_dir, php_fpm_pool_dir)\
values(:ServerPhp_server_php_id, :ServerPhp_sys_userid, :ServerPhp_sys_groupid, :ServerPhp_sys_perm_user, :ServerPhp_sys_perm_group, :ServerPhp_sys_perm_other, :ServerPhp_server_id, :ServerPhp_client_id, :ServerPhp_name, :ServerPhp_php_fastcgi_binary, :ServerPhp_php_fastcgi_ini_dir, :ServerPhp_php_fpm_init_script, :ServerPhp_php_fpm_ini_dir, :ServerPhp_php_fpm_pool_dir)", use(serverphp);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ServerPhpRepository::remove(const ServerPhp& serverphp)
{
	dataBase << "DELETE from server_php WHERE server_php_id=:ServerPhp_server_php_id", use(serverphp);
}

void ServerPhpRepository::update(const ServerPhp& serverphp)
{
	dataBase << "update server_php set server_php_id=:ServerPhp_server_php_id, sys_userid=:ServerPhp_sys_userid, sys_groupid=:ServerPhp_sys_groupid, sys_perm_user=:ServerPhp_sys_perm_user, sys_perm_group=:ServerPhp_sys_perm_group, sys_perm_other=:ServerPhp_sys_perm_other, server_id=:ServerPhp_server_id, client_id=:ServerPhp_client_id, name=:ServerPhp_name, php_fastcgi_binary=:ServerPhp_php_fastcgi_binary, php_fastcgi_ini_dir=:ServerPhp_php_fastcgi_ini_dir, php_fpm_init_script=:ServerPhp_php_fpm_init_script, php_fpm_ini_dir=:ServerPhp_php_fpm_ini_dir, php_fpm_pool_dir=:ServerPhp_php_fpm_pool_dir WHERE server_php_id=:ServerPhp_server_php_id", use(serverphp);
}

void ServerPhpRepository::update(const ServerPhp& oldObj, const ServerPhp& newObj)
{
	dataBase << "update server_php set server_php_id=:ServerPhp_server_php_id, sys_userid=:ServerPhp_sys_userid, sys_groupid=:ServerPhp_sys_groupid, sys_perm_user=:ServerPhp_sys_perm_user, sys_perm_group=:ServerPhp_sys_perm_group, sys_perm_other=:ServerPhp_sys_perm_other, server_id=:ServerPhp_server_id, client_id=:ServerPhp_client_id, name=:ServerPhp_name, php_fastcgi_binary=:ServerPhp_php_fastcgi_binary, php_fastcgi_ini_dir=:ServerPhp_php_fastcgi_ini_dir, php_fpm_init_script=:ServerPhp_php_fpm_init_script, php_fpm_ini_dir=:ServerPhp_php_fpm_ini_dir, php_fpm_pool_dir=:ServerPhp_php_fpm_pool_dir WHERE server_php_id='"<<oldObj.getServerPhpId()<<"\'", use(newObj);
}

