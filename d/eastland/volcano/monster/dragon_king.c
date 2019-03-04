#include "../oldcat.h"

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dragon King of Well", "井龙王" );
	add ("id", ({ "king", "dragon", }) );
	set_short( "井龙王" );
	set_long(
    "  井龙王原是北海龙王，因为在儿子闯出大祸之後，得罪了玉帝，才被贬到凡间，\n"
    "他其实是很有智慧的人，且由於曾经过万年的修□，胆识及统御能力皆不同凡响。\n"
	);

        set( "alignment",1600);
        set( "gender", "male" );
        set( "race", "dragon" );
        set( "unit", "位" );
        set( "likefish",1);
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 20);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
	set("special_defense", (["all":60,"none":60,"monk":60,"scholar":60]) );
        set ("aim_difficulty", ([ "critical":30, "vascular":30, "weakest":30, "ganglion":30 ]) );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
        set ("max_sp", 2000);
        set ("spell_points",2000);
	set ("wealth", ([ "gold": 500 ]) );
	set_natural_weapon( 5, 5, 10 );
	set_natural_armor( 50, 41 );
        set ("weight", 400);
        set( "inquiry", ([
             "rose" : "@@ask_rose" ,
             "princess" : "@@ask_princess" ,
             "daughter" : "@@ask_princess",
             "box" : "@@ask_box",
             "door" : "@@ask_door",
             "crystal" : "@@ask_crystal",
             ]) );
        set ("unbleeding",1);
	set ("att_chat_output", ({
	    "龙王说：你们这些小老百姓，是不可能击败我的。\n"
	    }) );
	wield_weapon(OWEAPON"sword1");
        equip_armor(OARMOR"legging2");
        equip_armor(OARMOR"helmet2");
        equip_armor(OARMOR"boots3");
        equip_armor(OARMOR"mail6");
}

void ask_rose( object who )
{
        tell_object( who, 
          "\n龙王道：不错，蓝玫瑰在我的花园中有一棵，但那是我女儿最喜爱的，我不能替\n"
          "她作主，不过你必须先救我的女儿，她已经有生命危险了。\n");
      return ;        
}

void ask_princess(object who)
{
      
      tell_object(who,
      "\n龙王道：我的女儿因为一天到晚都泡在花园里，不知道什麽原因，有一天突然看到她倒在\n"
      "花园里，从此就长睡不起，也\许是三百年一轮的劫数吧，但只要你能治好她，一定\n"
      "给你优厚的报酬。\n"
     );
      return ;
}

void ask_box(object who)
{
   tell_object(who,
    "\n龙王脸严肃的看著你，说道：你问这个做什麽 ? \n"
      "费了我好大的心力，才把宝盒又找了回来，我决定把它锁进我的宝库中，也不想\n"
      "让我的儿子知道，以免他又犯了同样的错误。\n"
   );
   return;
}

void ask_door(object who)
{
  tell_object(who,
    "\n龙王说：我的宝库只有在某段时间才能进去。\n"
  );
  return;
}

void ask_crystal(object who)
{
  tell_object(who,
    "\n龙王说：用手去触摸水晶会发生意想不到的事。\n"
  );
  return;
}

int accept_item(object me, object item)
{
   string name;
   object ob;
 
   name=(string)item->query("name");
   if (!name || (name!="living pill"))
     return 1;
   if (!item->query(me->query("name"))) {
     printf("\n龙王说：你是去那里偷的药丸，偷盗之物我们宁死不取。\n");
     item->move(me);
     return 0;
   }
   write("\n龙王说：啊、你这颗续命药丸可能真的可以救我女儿的命，请拿给我的女儿，给她吃下，谢谢。\n");
   if (!this_object()->query("key")) {
     write("龙王说：这是我女儿寝室的钥匙。\n");
     ob=new(OOBJ"diamond_key");
     ob->move(this_player());
     set("key",1);
   }
   else 
     write("\n龙王说：我女儿寝宫的钥匙已被别人拿走了。\n");
   item->move(this_player());
   return 1;
}
void die()
{
   int i ;
   object *sword,*tmp, dragon_sword;
   
   tmp = children("/d/eastland/volcano/weapon/sword1");
   sword = ({ }) ;
   for(i=0 ; i<sizeof(tmp);i++ )
     {
       if(!environment(tmp[i])) continue ;
       else sword=sword+({tmp[i]}) ;
     }
   
 // 改成clone 出来的 sword 大於二就 remove
   
   if( sizeof(sword)>1 ){
     dragon_sword = present( "dragon sword", this_object() );  
     tell_room(environment(this_object()),
  " 龙王挣扎的说：宝剑一生只有一次．．．．．．\n龙王用尽最後的力量将龙剑粉碎！\n",this_object() );
   dragon_sword->remove();
   }
 ::die();
}

