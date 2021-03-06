//black_chocobo.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
	::create();
	seteuid( getuid() );
   set_level(18);
	set_name( "black chocobo", "黑色陆行鸟" );
	add ("id", ({ "bird", "chocobo", }) );
	set_short( "黑色陆行鸟" );
	set_long( @C_LONG
变种的陆行鸟，不但可以在地上跑，还能在空中飞。可惜飞行速度并不是
很快，时速大约只有三十公里。看它拼命振翅的样子，滑稽极了。
传说它酷食任何东西。又如果你是它的主人, 它会帮你撞击(hit)敌人。
C_LONG
	);
   set( "alignment", 1500 );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 25 );
   set_perm_stat( "int", 13 );
   set_perm_stat( "con", 25 );
	set_perm_stat( "piety", 25 );
	set_perm_stat( "karma", 30 );
   set_natural_weapon( 40, 20, 40 );
   set_natural_armor( 100, 50 );
	setenv( "C_MIN", "突然一只$N快速地飞了进来。");
	setenv( "C_MOUT", "$N振翅往$D边飞走了。");
	set ("special_defense",
	    ([ "all" : 25 ]) );
	set ("wimpy", 100);
	set_skill( "dodge" ,100);
	set ("moving", 1);
	set ("speed", 5);
   set( "mountable", 0 );
   set( "max_load", 2400 );
   set( "c_extra_look", "$N正骑著一只黑色陆行鸟。\n");
    set ("weight", 900);
   set( "exp_reward", 5555 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一脚踢在%s脸上", "%s一爪抓到%s",
                    "%s用大嘴啄%s", }) );
    set_c_limbs( ({ "身体", "翅膀", "嘴", "脚", "屁股", "爪子", }) );
    set( "c_death_msg", "%s说: 我咧#@!&$*? :( .... 然後就死了。\n" );
}

void init()
{
//      monster::init();
   add_action( "hit_enemy", "hit" );
   mount::init();
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
            "黑色陆行鸟尖叫一声: GEEE....\n"
            "黑色陆行鸟把"+item->query("c_name")+"吃下肚!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "黑色陆行鸟滴下了一滩口水, 真脏啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你现在可以骑黑色陆行鸟了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
      "黑色陆行鸟尖叫一声: 又是 "+who->query("c_name")+" 这杀人魔，快逃!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "黑色陆行鸟尖叫一声: 又是你这杀人魔，快逃!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;
   int rid, deb, dod, dam;

   owner = environment(this_object());

   if( !living(owner) ) 
        return notify_fail("黑色陆行鸟不听你的指挥。\n");
   if( !arg ) return notify_fail("你想撞谁？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("这里没有那种东西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("撞自己？你疯啦？\n");
   if( !living(target) )
        return notify_fail("黑色陆行鸟用力的撞了"
                        +target->query("c_name")+"但是什麽事也没发生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想撞谁？\n");
   if( !owner->query_vision() )
        return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
   if ( target->query("no_attack") )
        return notify_fail("这家伙－不能杀。\n");
   if( userp(target) && (int)target->query_level()< 5 )
        return notify_fail("你不能 PK 他 !!\n");
   if( "berserk" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( "melee" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( "flank" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交谈能力太低了!\n" );
   if( (int)target->query("hit_points")<50 )
        return notify_fail("黑色陆行鸟不屑欺负如此不堪一击的家伙。\n");

   if( target->query_temp("dodge_hit") ) {
        tell_object( owner,
            "\n你命令黑色陆行鸟向对方撞去, 但是敌人闪过了!\n\n" );
        tell_object( target,
            "\n黑色陆行鸟向你撞来, 但是你闪过了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑色陆行鸟撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
   rid = (int)owner->query_skill("riding");
   deb = (int)target->query("defense_bonus");
   dod = (int)target->query_skill("dodge");
   dam = rid/2 - deb/5 -random(dod)/10;
        tell_object( owner,
            "\n你命令黑色陆行鸟向对方撞去, 敌人似乎受到巨大的伤害!\n\n" );
        tell_object( target,
            "\n黑色陆行鸟向你撞来, 你似乎受到巨大的伤害!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑色陆行鸟撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->add("hit_points",-dam);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->set_temp("dodge_hit",1);
        return 1;
   }
   return 1;
}
