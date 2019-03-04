#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid( getuid() );
        set_name("news plaque", "布告栏");
        set_short("布告栏");
        add( "id", ({"news","plaque",}) );
        set( "long", "@@query_long" );
        set( "unit", "块" );
        set( "weight", 10000 );
        set( "prevent_get", 1);
}

string query_long()
{
   write( "东方故事最新公告：\n" );
   cat( "/adm/news/c_motd" );
   write( @MORE
发现BUG 欲直接报告於巫师者，请前往冒险者公会地下室北边之公告
大厅，参考STATUE给予之资料，直接联系各主管之巫师，相信你能得
到更满意的答覆。

MORE
   );
   return "或者直接POST於BUG 布告栏，巫师们亦会及早处理该问题。\n";
}
