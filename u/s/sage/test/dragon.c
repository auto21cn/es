//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "黑龙" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "黑龙" );
        set_long( @C_LONG
    传说中邪恶的神灵，只要它出现，大地将变的战火连篇，人世间将永远得
不到安宁，除非是勇者出现，否则这种情况将持续下去。它正用邪恶的眼睛看
着你，不断地向你嘿嘿冷笑。
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "条" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "一只$N在天空中一闪而过。");
        setenv( "C_MOUT", "$N闪电般地向$D飞去。");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N正坐在一条黑龙。\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一脚踢在%s脸上", "%s一爪抓到%s",
                    "%s用大嘴咬%s", }) );
    set_c_limbs( ({ "龙身", "龙角", "龙嘴", "龙脚", "龙尾", "龙爪", }) );
    set( "c_death_msg", "%s说: 你们会后悔的:( .... 然後就死了。\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "黑龙狂叫一声: 傲....\n"
             "黑龙把"+item->query("c_name")+"一口吃掉!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "黑龙滴下了一滩口水, 真脏啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你现在可以骑黑龙了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "黑龙狂叫一声: 又是你这杀人魔王，看招!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "黑龙狂叫一声: 又是你这杀人魔王，看招!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("黑龙不听你的指挥。\n");
   if( !arg ) return notify_fail("你想咬谁？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("这里没有那种东西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("咬自己？你疯啦？\n");
   if( !living(target) )
        return notify_fail("黑龙张开大嘴用力的咬了"
                        +target->query("c_name")+"但是什麽事也没发生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想咬谁？\n");
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
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交谈能力太低了!\n" );
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n你命令黑龙向对方咬去, 但是敌人闪过了!\n\n" );
        tell_object( target,
             "\n黑龙向你咬来, 但是你闪过了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑龙咬向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n你命令黑龙向对方的腿部咬去, 敌人被咬去了一块肉!\n\n" );
        tell_object( target,
            "\n黑龙向你腿部咬来, 你被咬地鲜血淋漓，摔倒在地上了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑龙咬向"+target->query("c_name")+"腿部\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你腿部受伤，无法攻击！ )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "黑龙" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "黑龙" );
        set_long( @C_LONG
    传说中邪恶的神灵，只要它出现，大地将变的战火连篇，人世间将永远得
不到安宁，除非是勇者出现，否则这种情况将持续下去。它正用邪恶的眼睛看
着你，不断地向你嘿嘿冷笑。
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "条" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "一只$N在天空中一闪而过。");
        setenv( "C_MOUT", "$N闪电般地向$D飞去。");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N正坐在一条黑龙。\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一脚踢在%s脸上", "%s一爪抓到%s",
                    "%s用大嘴咬%s", }) );
    set_c_limbs( ({ "龙身", "龙角", "龙嘴", "龙脚", "龙尾", "龙爪", }) );
    set( "c_death_msg", "%s说: 你们会后悔的:( .... 然後就死了。\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "黑龙狂叫一声: 傲....\n"
             "黑龙把"+item->query("c_name")+"一口吃掉!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "黑龙滴下了一滩口水, 真脏啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你现在可以骑黑龙了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "黑龙狂叫一声: 又是你这杀人魔王，看招!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "黑龙狂叫一声: 又是你这杀人魔王，看招!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("黑龙不听你的指挥。\n");
   if( !arg ) return notify_fail("你想咬谁？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("这里没有那种东西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("咬自己？你疯啦？\n");
   if( !living(target) )
        return notify_fail("黑龙张开大嘴用力的咬了"
                        +target->query("c_name")+"但是什麽事也没发生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想咬谁？\n");
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
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交谈能力太低了!\n" );
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n你命令黑龙向对方咬去, 但是敌人闪过了!\n\n" );
        tell_object( target,
             "\n黑龙向你咬来, 但是你闪过了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑龙咬向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n你命令黑龙向对方的腿部咬去, 敌人被咬去了一块肉!\n\n" );
        tell_object( target,
            "\n黑龙向你腿部咬来, 你被咬地鲜血淋漓，摔倒在地上了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑著黑龙咬向"+target->query("c_name")+"腿部\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你腿部受伤，无法攻击！ )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
