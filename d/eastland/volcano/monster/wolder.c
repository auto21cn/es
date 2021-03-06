#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The older", "矮灵族老人" );
	add( "id", ({ "older" }) );
	set_short( "矮灵族老人" );
	set_long(
          "一个矮灵族的老人，满脸皱纹，驼著背，他是50年前火山爆发的幸存者之一。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -10 );
	set_perm_stat( "str", 15 );
	set( "wealth/gold", 5 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",40);
        set("natural_defense_bonus",15);
        set_natural_weapon(15,5,5);

        ob1=new(OWEAPON"wstick");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );

        equip_armor(OARMOR"boots1");
        set("inquiry", ([
            "square":"@@ask_square",
            "rose": "@@ask_rose",
            "volcano":"@@ask_volcano",
            "fire" : "@@ask_fire",
            ]) );
}

void ask_square(object who)
{
  tell_object(who,
   "\n老人说：不知道是不是我老眼昏花，我曾看过广场中间的巨大营火(fire)曾经熄\n"
   "灭，待我带人去看时，它又恢复原状了．．．．部落里没有人愿意相信我的话。\n\n"
   );
   return;
}

void ask_fire(object who)
{
  tell_object(who,
   "\n老人说：那营火实在很奇怪，我曾看它消失过。\n"
  );
  return;
}

void ask_rose (object who)
{
  tell_object(who,
    "老人说：我那个儿子在发春了，我活那麽久，还没听说过有蓝玫瑰的存在。\n"
  );
  return;
}

void ask_volcano(object who)
{
  tell_object(who,
     "老人说：这座火山实在是我们矮灵族的恶梦，50年前的爆发把我们矮灵族几乎全毁了，只有少数人还活下来，所以找一个好方法来解决火山爆发的问题，实在是刻不容缓。\n"
  );
  return;
}
