
#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(17);
        set_name( "Adventurer Keiwi","冒险家奇维" );
        add ("id", ({ "adventurer","keiwi" }) );
        set_short( "Adventurer Keiwi","冒险家奇维" );
        set("unit","位");
        set("alignment",740);
        set("weight",900);
        set("wealth/copper",3800);
        set_long(
@C_LONG
他是一位环游世界的冒险家，由於他丰富的阅历，当年毕克林老爹初
次到黑暗精灵村时，就是由他代为向导的。但是他最近似乎因为爱人
(lover) 失踪而烦恼。
C_LONG
        );
        set_perm_stat("int", 16);
        set_perm_stat("str",23);
        set("max_hp",650);
        set("hit_points",650);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1", 13);
        set ("natural_max_damage1", 22);
        set ("natural_armor_class", 78);
   set( "special_defense", ([
       "all":20, "none":12]));
        set ("race", "human");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",75);
        set_skill("parry",65);
        set( "inquiry", ([
             "snake" : ({"可帕的大蛇...禁地守卫不会让你过去的喔 ..\n"}),
             "herb" : ({
                      "喔....蛇窝草哦...我有我有，可是只有一束，不能给你..\n"
                      "除非你帮我一个忙，我就给你蛇窝草....\n"
                       }),
             "help" : ({
       "你想帮我吗？好，我在此的探险已经有数年了\n"
       "但是最近，我的油灯用完了..真糟糕...\n"
       "我正在找寻司娜可神殿的秘密，但是我需要一盏油灯，你能给我一盏吗？\n"
                       }),
             "lover" : ({
                       "爱人？？等等吧....饭岛爱小姐没空为我介绍，再等一阵子吧\n"
                        })
                   ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"ring1");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="lamp"))
     return 1;
write("奇维说：太好了！！耶！我又可以继续我的冒险了。\n");
   if (!this_object()->query("gress")) {
     write("奇维给你一束蛇窝草。\n");
     ob=new(OBJ"gress");
     ob->move(this_player());
     set("gress",1);
   }
   else
     write("奇维说：不妙！有人先来拿了，你等reboot吧...哈哈。\n");
   return 1;
}
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE
奇维高喊一声：想不到我阅历世界一生，竟败在你的手中.....

你看到奇维的背包中掉出了一件铠甲。

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_plate");
    obj->move(this_object());
   ::die(1);
   }

