#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Gardener","老园丁");
    set_short("老园丁");
    set_long(@LONG
    一个魔族的老公公，全身皮肤都晒得黑黝黝的，正辛勤的清除御花园中
的落叶及杂草；如果你有什麽罕见的植物想要种，那麽他会很乐意为你服务
的，因为，收集稀有植物来充实御花园，正是他的工作！
LONG
            );
    set("unit","位");
    set("race","daemon");
    set("gender","male");
    set("alignment",200);
    set_perm_stat("dex",7);
    set_perm_stat("str",5);
    set("max_hp",125);
    set("hit_points",125);
    set_skill("unarmed",30);
} 

int accept_item(object player,object obj)
{
    if( !obj || !(obj->query("luoko_seed"))) return 0;
      if( (string)obj->query("getter") != (string)player->query("name") ){
      write(@GET
老园丁奸笑道：哦，小子，你这种子是偷来的吧？没收！！就把种子收起来了！！
GET
           );
      return 1;
      }
    tell_room(environment(),
    "老园丁瞪大著眼睛，用颤抖著的双手接过种子，急忙把它种入泥土中！\n");
    obj->remove();
    call_out("grow_up",5,this_player() );
    return 1;
} 

int grow_up()
{
    if( present("luoky")) {
    tell_room(environment(),@ALONG

魉皇鬼以为园丁种的是萝卜，以迅雷不及掩耳的速度把种子挖走了.........
天啊，你都还没反应过来勒！！！

老园丁叹气道：小子，只好再去找一颗种子了............
ALONG
             );
    return 1;
    }
    tell_room(environment(),@BLONG
老园丁说道：小伙子，这样就行了；请转告(report)阿重霞公主，就说龙皇没事了，
好吗？
BLONG
             ); 
    this_player()->set_temp("seed_ok",1);
    return 1;
}  
