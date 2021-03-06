#include "../layuter.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "thiris", "席理斯" );
        add ("id", ({ "thief", "daemon","thiris" }) );
        set_short( "席理斯" );
        set("unit","位");
        set_long(
           " 他是当恶魔入侵精灵村时被引入迷宫的残存恶魔族人，是一位可恶的小偷。\n"
        );
        set("alignment",-1000);
        set("wealth/gold",20);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 15, 10, 28 );
        set_natural_armor( 70, 20 );
        set ("gender", "male");
        set ("race", "daemon");
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(LWEAPON"daemon_dagger");
        equip_armor(LARMOR"daemon_amulet");
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(LARMOR"statue");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room( environment(this_object()),
      "\n\n席理斯以微弱的声音说道：在我以前做了许\多的坏事，偷了非常多的东西\n"
      "最近我又利用迷宫因年久失修而产生的破洞，出去捞了好几笔，其中有一个雕像我很喜欢\n"
      "，但是听说它的原主人因为不见了它因而茶饭不思，我很过意不去，希望你能帮我还给他\n"
      "，这是我临终的遗言，希望你帮我完成。\n\n"
      "你见他从床底下拿出一个雕像给你。\n"
      "当他说完此段话, 你便见他两腿一伸回姥姥家了。\n" );
   ob1->set("killer",(string)killer->query("name"));
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
