#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Andromeda", "安杜露美妲" );
	add("id",({"administrater","halfling","andromeda"}) );
   set_short( "图书馆馆长安杜露美妲" );
	set_long(
		"天下居然有这麽美丽的绝世美女 !! 虽然她的身裁小了一号,\n"
                "但是却是你曾见过的女子中最美的。就在你瞠瞠地望著她时,\n"
                "她突然抬头看了看你,对你笑了笑。\n"
	);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 12 );
	set_natural_weapon( 17 , 5 , 8 );
	set("max_hp",350);
	set("hit_points",350);
        set("inquiry",([         
                         "优波罗花": "@@quest1a",
                      ]) ) ;

	set_perm_stat( "kar", 24 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 12 ]) );


}

void quest1a(object who)
{
   int a,b ;
   string cmsg,msg ;
     
   a = this_player()->query("astr/questa");
   b = this_player()->query_temp("astr/quest1");
      
   if(!a || !b || b < 3 )
      return notify_fail(can_read_chinese()?
             "你在说什麽 ?? 我一句都听不懂。\n" :
             ""  ) ;
   

        who->set_temp("astr/quest1",41);  
        cmsg =
            "安杜露美妲用银铃般的声音说道 :\n"
            "      我记得馆藏的藏书中有一本关於罕见花卉的,\n"
            "      你去找找看,也许会有些帮助。\n" ;
        msg  = "" ;
            
   write(can_read_chinese()?
           cmsg : msg );
   return ;
}


