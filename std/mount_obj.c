// This is the mount object, inherited by monsters can be mounted.
// By Ruby@ES 1995-6-18

#include <mudlib.h>
inherit OBJECT;
int hit1(string arg);
void create()     
{
        if (clonep(this_object())) {
                set_default_ob("/std/mount_obj");
                return ;
        }
        set_name( "wooden horse", "小木马" );
        set("short", "小木马");
        set("long", "这是一匹木马");
        set( "unit", "匹" );
        set("weight", 0);
        set("prevent_drop",1);
        set("prevent_insert",1);
}

void init()
{
        add_action( "do_dismount", "dismount" );
        add_action( "do_hit","hit");
}

int do_dismount()
{
        return call_other("/adm/daemons/mount","dismount",this_object(),this_player());
}

int scare_me()
{
        return "/adm/daemons/mount"->scare_me(this_object());
}
int do_hit(string arg)
{
   if(this_object()->query("name")=="chocobo" ||
      this_object()->query("name")=="black chocobo") return hit1(arg);
   return 0;
}

int hit1(string arg)
{
   object owner, target,me;
   int rid,deb,dod,dam;

   owner = environment(this_object());
   me=this_object();

   if( !living(owner) ) 
        return notify_fail("它不听你的指挥。\n");
   if( !arg ) return notify_fail("你想撞谁？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("这里没有那种东西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("撞自己？你疯啦？\n");
   if( !living(target) )
        return notify_fail("你的坐骑用力的撞了"
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
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必须换另一种战术。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交谈能力太低了!\n" );
   if( owner->query_skill("riding")/2 +
        random( owner->query_skill("riding")/2)
      < ( int )target->query_skill("dodge")  ) {

        tell_object( owner,
            "\n你命令"+me->query("c_name")+"向对方撞去, 但是敌人闪过了!\n\n" );
        tell_object( target,
             "\n"+me->query("c_name")+"向你撞来, 但是你闪过了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"骑着"+me->query("c_name")
             +"撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
      if(me->query("name")=="black chocobo")
      {
         rid = (int)owner->query_skill("riding");
         deb = (int)target->query("defense_bonus");
         dod = (int)target->query_skill("dodge");
         dam = rid/2 - deb/5 -random(dod)/5;
         tell_object( owner,
         "\n你命令黑色陆行鸟向对方撞去, 敌人摔倒在地, 似乎受到巨大的伤害!\n\n" );
         tell_object( target,
          "\n黑色陆行鸟向你撞来, 你摔倒在地, 似乎受到巨大的伤害!\n\n" );

         target->add("hit_points",-dam);
         owner->add("talk_points",-20);
       }
      else
       {
         tell_object( owner,
            "\n你命令"+me->query("c_name")+"向对方撞去, 敌人摔倒在地上了!\n\n" );
         tell_object( target,
            "\n"+me->query("c_name")+"向你撞来, 你摔倒在地上了!\n\n" );
         tell_room( owner,
            owner->query("c_name")+"骑著"+me->query("c_name")+
            "撞向"+target->query("c_name")+"\n\n",
         ({ owner,target }) );
        }
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你现在摔倒在地，无法攻击！ )\n" );
        return 1;
   }
   return 1;
}
