#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Shopkeeper","钱老板");
    add("id",({"keeper"}) );
    set_short("钱老板");
    set_long(@LONG
钱老板是为约莫四十出头的中年男子，嘴边挂著一撮小胡子，
外加两颗咪咪眼，十足的精明干练模样。不过他的脾气有点古怪，
外传他曾是风闻一时的大盗，所以最好不要问他有关小偷(thief)
的事情哦，免得他动怒！另外呀，他观察力可是一流的哦，能在短
时间内算清你身上所有的伤痕(scar)哦，那怕是衣服遮住的，一样
无法逃出他的慧眼！
LONG
             );
    set("unit","个");
    set("gender","male");
    set("alignment",-500);
    set("race","daemon");
    set("no_attack",1);
    set("inquiry",([
          "thief":"@@ask_thief",
          "scar" :"@@ask_scar",
          ]) );
}
    
void ask_thief(object victim)
{
    write("钱老板突然脸色一沉，一道烟雾後只见一团黑影向你冲了过来！！\n");
    tell_room( environment(victim),
    "\n突然一阵烟雾，只见一道黑影向"+victim->query("c_name")+"扑了过来！\n"
    , victim);
    kill_ob( victim);
    set_level(12);
    set_name("Great Thief","钱形次郎");
    add("id",({"thief"}) );
    set_short("大盗  钱形次郎");
    set_long(@LONG
    原来钱老板果真是风闻一时的妙手大盗啊，只见他全身劲装，一幅
气急败坏的模样。
LONG
            );
    set("no_attack",0);
    set("c_killer_msg","\n突然一阵烟雾，只见一道黑影向你扑了过来！\n");
    set("killer",1);
    set("tactic_func","my_tactic");
    
    set("chat_chance",20);
    set("att_chat_out",({
        "臭小子，竟敢道破我最不想让人知道的过去，我给你″死″！！\n"
        }) );
    set_natural_weapon(18,13,17);
    set_natural_armor(35,15);
} 

int my_tactic()
{
    object victim;
    
    if( !(victim=query_attacker()) ) return 0;
    if( random(20) < 2){
      tell_object(victim,
      "次郎顺手一挥，数枚暗器向你射了过来，但都被你接住了.......\n"
      "哇～～！是五枚金币耶，快收起来！\n"
                 );
       tell_room( environment(victim),
       "次郎偷偷地向 "+victim->query("c_name")+" 放暗器，但都被接住了！\n"
       ,victim );
       victim->add("wealth/gold",5);
       return 1;
        }
     else if( random(20) < 5){
       tell_object(victim,
       "突然「咻咻咻」数声，次郎手中射出几件暗器打在你身上，哇！好痛！！\n");
       tell_room( environment(victim),
       "次郎顺手一扬，数件暗器激射而出，全打在 "
       +victim->query("c_name")+" 身上！\n"
       ,victim );
       victim->receive_special_damage("evil",15);
       report( this_object(),victim );
       return 1;
      }
     else return 0;
} 

void ask_scar()
{
    int jus;
    jus = (int)this_player()->query("justice");
    if(!jus) write("钱掌柜指著你大笑道：你全身乾乾净净的, 一点伤痕也没有, 你真是勇者吗?????\n");
    else write("钱掌柜拍手称赞说：哇!!阁下全身上下布满大小伤痕"+jus+"道, 乃真神人是也!!\n");
    return 1;
}    
    
