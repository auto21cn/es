#include <../oldcat.h>
inherit MONSTER ;

int be_get;
void create()
{
        object ob1;

	::create();
	set_level(16);
        set_name( "Old shaman", "老巫医" );
        set_short( "老巫医" );
	add( "id", ({ "shaman" }) );
	set_long(
@LONG
你看见一个年纪很大的老巫医，满脸都是皱纹，胖胖的，驼著背，满口蛀牙，但他的
手仍能很稳的拿著医疗所必须用的器材，你在想他是不是吃太多糖果了，现在他正在
大锅子旁边照料著正在炼的药。
LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
        set_perm_stat("str",25);
        set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 80 );
        set_skill( "anatomlogy", 80 );
        set("defense_type","dodge");
        set( "aim_difficulty", ([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "max_hp", 750 );
        set( "hit_points", 750 );
        set_natural_armor( 58, 16 );
        set( "natural_weapon_class1", 3 );
        set( "natural_min_damage1", 1 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", -500 );
        set( "wealth/gold", 50 );
        set( "inquiry", ([ 
             "candy":"@@ask_candy",
             "box":"@@ask_box",
             "heal":"@@ask_heal",
             "potion":"@@ask_heal",
             "pill":"@@ask_heal",
             ]) );
        ob1=new(OWEAPON"dagger02");
        ob1->move(this_object());
        wield_weapon(ob1);
        equip_armor(OARMOR"amulet1");
        equip_armor(OARMOR"boots2");
        equip_armor(OARMOR"cloak1");

}

void ask_candy(object who)
{
   if (be_get) {
     tell_object(who,
       "\n老巫医说：你长的很报歉，喔 ! 不、不、糖果已被别人捷足先登了。\n");
     return;
   }
   tell_object(who,
     "\n老巫医说道：想要我珍藏的糖果，就得用十块金币交换。\n");
   return;
}

void ask_box(object who)
{
  tell_object(who,
    "\n老巫医说：那个黑盒子有可能是被冷无霜偷走了，我不知道她在那，不过没有\n"
      "必要还是不要惹她比较好，连有名的京城四大名捕都对她无可耐何。\n\n");
  return ;
}

void ask_heal(object who)
{
  tell_object(who,
   "老巫医说道：我正在作一种续命药丸，无耐还缺一种药引(人参果)，假如你能找\n来给我，我就分你一颗。\n");
  return;
}

void init()
{
    add_action( "do_pay", "pay");
}

int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="manlike fruit"))
     return 0;
   if (!item->query(me->query("name"))) {
     printf("老巫医说：你是去那里偷的人参果，偷盗之物我宁死不取。\n");
     item->move(me);
     return 1;
   }
   write("老巫医说：啊、这正是我要的人参果，谢谢。\n\n");
   write("你见到老巫医把人参果丢到大锅子里头，只听得嘶的一声，一股浓浓的橘色烟雾从那锅子\n中飘了出来，弥漫整个帐篷之中，烟雾之中，你隐约见到老巫医不知道在锅子边做什麽，等\n烟雾散去，你注意到那大锅子里已没有任何东西了。\n\n");
   write("老巫医说：这是我刚完成的两颗药丸，一颗分你吧。\n");
   item->remove();
   ob=new(OOBJ"wpill");
   ob->set(this_player()->query("name"),1);
   ob->move(this_player());
   return 1;
}

int do_pay(string arg)
{
        string who, type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "\n付谁？多少钱？\n" );
        if( !id(who ) ) return 0;

        if (be_get) {
           tell_object(this_player(),
              "\n老巫医说道：糖果被别人拿去了，但是钱我是来者不拒。\n");
           return 1;
        }

        if( type != "gold" ) {
         tell_room( environment(), ({
             "\n老巫医说道: 很抱歉，只有金币才能打动我的心。\n" }),
          this_object() );
          return 1;
	}

       if( !this_player()->debit(type, num) ) 
           return notify_fail( 
           "\n你没有那麽多金币。\n" );

       if(num<10) {
         tell_room( environment(),
          "\n老巫医说道: 钱不够，请再给我一遍吧，这次就算老年津贴好了。\n" ,
          this_object() );
                return 1;
	}

        if (num>=10) {
          tell_object(this_player(), 
             "\n老巫医说道: 好 ! 我就忍痛把这块巧克力给你吧。\n");
        ob1=new(OOBJ"y_chocolate");
        ob1->move(this_player());
        be_get=1;
	return 1;
	}

}

void reset()
{
  be_get=0;
}
