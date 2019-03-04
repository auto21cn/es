
#include "../layuter.h"

inherit MONSTER;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Elf Lord", "精灵王" );
        add ("id", ({ "elf", "lord" }) );
        set_short( "精灵王" );
        set("unit","位");
   set_long( @LONG
精灵王是精灵村的领导者, 他操纵精灵村的各种物产使得精灵
们能够各师其职、各尽其力地把精灵村建立成为一个丰衣足食
的世外桃源, 但当有外族入侵时, 他又转而变成一位恐怖的战
士－此乃因他於年轻时意外获得一把『以太精灵剑』, 因而超
越所有族人而成为最强之战士。而他又助现任国王之祖父亚拉
曼三世击退入侵诺达尼亚之默尔斯人无数次, 而受勋「战王」。
LONG );
        set("alignment",500);
        set("wealth/gold",20);
        set_perm_stat("int",30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 20);
        set_perm_stat("kar",30);
        set_natural_weapon( 20, 10, 35 );
        set_natural_armor( 40, 40 );
        set ("gender", "male");
   set( "max_hp", 1110 );
   set( "hit_points", 1110 );
        set ("aim_difficult",(["critical":50, "vascular":20, ]));
        set ("special_defense",
          (["all":60,"fire":35,"poison":15,"none":25]));
        set ("race", "elf");
        set_c_verbs(({"用%s向%s砍去","用%s使出必杀一击向%s攻击","用%s向%s刺去"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
       
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("longblade",100);
   set( "war_score", 1000000 );
        
        wield_weapon(LWEAPON"sword");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"glove");
        equip_armor(LARMOR"shield");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"plate");
        equip_armor(LARMOR"cloak");
}

void die()
{
   object scroll;

   scroll = new( "/d/mage/tower/obj/eb8_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "『咚』的一声, 一件东西从精灵王的手掌中落在地上。\n",
     this_object() );
   ::die(1);
}
