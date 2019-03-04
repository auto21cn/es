#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name("unknow armor","未知防具");
	set_short("未知防具");
	set( "long","@@query_long");
	set( "weight","@@query_weight");
	set( "no_sale", 1);
	set( "c_skin_name","毛皮");
	set( "extra_ids",({}));
}

string query_long()
{
	if ( (string) this_object()->query("c_skin_name") != "skin" )
		return "这是一" + (string) this_object()->query("unit") + "用" + (string)this_object()->query("c_skin_name") +"的皮做成的"
		 +(string)this_object()->query("add_name")+ "。\n";
	else
		return "这是一件未完成的防具。\n";	
}
