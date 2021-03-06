#include "../story.h"
#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define CNAME(x) (string)x->query("c_name")

inherit OBJECT;
void create()     
{
	set("short", "@@query_short");
	set("long",@LONG
这是「羽民族」之宝－飞翔之笛，它能带你飞往天都(cast-me)。
LONG
);
 	set_name( "fly flute", "飞翔之笛" );
        add("id",({"flute"}));
	set( "unit", "个" );
	set("weight", 40);
	set("value", ({ 100, "silver" }));
}
void init()
{
	add_action("cast_me", "cast-me");
}
void sent(object traveller,string target,string msg)
{
    tell_object(traveller,set_color(msg,"HIW"));
    traveller->move_player(target,"SNEAK");
} 
int who_in_party(object obj, string me)
{
     if( !living(obj) ) return 0;
     if( LEADER(obj)!= me ) return 0;
        return 1;
}
int cast_me(string arg)
{
     object player,env,*party;
     string target,msg;     
     int i;
     player=environment(this_object());
     if ( !living(player) )
        return notify_fail("请捡起来再使用。\n");
     if ( !query("flute_left") )
        return notify_fail("此飞翔之笛的能源已经用尽了。\n");
     env=environment(player);
     if ( !env->query("can_use_flute") )
        return notify_fail("你无法在这个地方使用飞翔之笛！\n");
     tell_object(player,set_color(
        "\n你手中的「飞翔之笛」发出嗡嗡嗡的鸣声，闪烁著银光，并且长出了巨大的双翼！\n\n","HIW"));
     tell_room(env,set_color(sprintf(
        "\n%s手中的「飞翔之笛」发出嗡嗡嗡的鸣声，闪烁著银光，并且长出了巨大的双翼。\n\n",
        CNAME(player)),"HIW"),player);
     if ( env->query("goto_palace") ) {
       target=SPALACE"plain1";
       msg="一阵刺眼的银光之後，「飞翔之笛」把你带到了天都！\n\n";
     }
     else {
        target=SAREA"mountain2";   
        msg="一阵刺眼的银光之後，「飞翔之笛」把你带离开了天都。\n\n";
     }
     if (!LEADER(player)||LEADER(player)!=NAME(player)) {
         sent(player,target,msg);
         return 1;    
     } 
     party=filter_array(all_inventory(env),"who_in_party",this_object(),NAME(player));
     for (i=0;i<sizeof(party);i++) 
        sent(party[i],target,msg);                                
     return 1;
}

string query_short()
{
     return sprintf("飞翔之笛%s", (!query("flute_left") ? " (能源耗尽)" : "") );
}

