#include "../iigima.h"
#include <stats.h>

#include <conditions.h>
inherit MONSTER ;

void create ()
{

        ::create();
        set_level(14);
        set_name( "Evil mage Chim","邪术师奇姆" );
        add ("id", ({ "drow","mage","chim" }) );
        set_short( "Evil mage Chim","邪术师奇姆" );
        set("unit","位");
        set("alignment",100);
        set("weight",500);
        set("wealth/copper",3800);
        set_long(
@C_LONG
看他瘦小的身驱和驼背的样子令你感觉他好像很可怜，他是黑暗精灵
村的邪术师，也是老村长的胞弟，年轻的时候曾经周游四方，得到了许多
宝物，尤其是头上所戴的头巾，更是极品。虽然名为邪术师，但是他却很
乐意帮助(help)人。
C_LONG
        );
        set_skill( "dodge", 70 );
        set_skill( "dagger", 70 );
        set_skill( "anatomlogy", 67 );
        set("defense_type","dodge");
        set( "aim_difficulty",([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "special_defense", ([
                "all":30, "fire":-10, "cold":-10, "evil":60, "divine":-30 ]) );
        set_perm_stat("int", 22);
        set_perm_stat("kar",19);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20,10,20);
        set_natural_armor(50,5);
        set ("race", "drow");
        set ("gender", "male");
        set( "tactic_func", "emit_confuse" );
        set_c_limbs(({"身体","脚部","手臂"}));
        set( "inquiry", ([
                "help" : ({
"哎呀呀～年轻人, 需要帮助吗? 我很乐意帮助你, 可是我只会炼金术耶～\n"
"最近不是在禁断之地有许多的蛇(snake)吗? 好像很危险哦, 可是....\n"
                  }),
                "snake" : ({
"嗯．．我最近从书本上看到，某种蛇的眼睛能发光(light)，好像很有用的样子。\n"
                   }),
                "light" : ({
"详细的情形我也不知道啦～好像是叫作蛇眼之石(stone)吧！\n"
                  }),
                "stone" : ({
"听说蛇眼石是在司娜可女神神殿里，可是那里不准靠近，所以我也没看过..\n"
                  })
                        ]) );
        wield_weapon(OBJ"scale_dagger");
        equip_armor(ARM"robe");
        equip_armor(ARM"lucky_headband.c");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="stone of snake's eye"))
     return 1;
write("奇姆说道：喔...这是蛇眼石耶！好，我帮你将它作成漂亮的戒指吧。\n");
write("你看奇姆在那里敲敲打打的，弄了好一会儿....\n");
   if (!this_object()->query("ring")) {
     write("奇姆说道：好了，这戒指就命名为蛇眼石之戒吧，来，给你。\n");
     ob=new(ARM"ring");
     ob->move(this_player());
     set("ring",8);
   }
   else
  write("奇姆说道：对不起哦！我的机器坏了，不能作戒指了\n");
   return 1;
}
int emit_confuse()
{
        object victim;
   if( random(10)>2 ||!(victim= query_attacker())) return 0;
            tell_room( environment(this_object()),
                    "奇姆从口袋拿出一把毛绒绒的毯子向你用力一挥!!\n",
                        this_object() );
            (CONDITION_PREFIX + "confused")->apply_effect( victim, 6, 10 );
        return 1;
}

