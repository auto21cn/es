#include "../oldcat.h" 

inherit OBJECT;

object place;
void create()
{
	set_name( "manlike fruit", "人参果" );
	set_short( "人参果" );
	set_long(
	  "这是个可以延年益寿、千年一结的人参果。\n"
	);
        add("id",({"fruit"}) );
        set( "unit", "个");
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   int align;

   if(!arg || arg!="fruit")
   { write("你要吃什麽？\n");
     return 1;
   };
   this_object()->set("prevent_drop",1); 
   write("你吃了这颗人参果之後，突然你觉得身体好像有什麽变化．．．．．\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",5,this_player());
   call_out("end",25,this_object(),this_player());

   return 1;
}

int idle_time1(object who)
{
    tell_object(who, "你觉得你的身子一轻，慢慢的飘了起来，你不禁暗暗偷笑，好不容易在ＥＳ中混那麽久，终於成仙了。\n");
    tell_room(environment(this_player()),"\n你见到 "+this_player()->query("c_name")+" 慢慢的飘了起来，往天空中飞上去。\n\n",this_player());
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who, "你发觉自己仍不断的升高，离地面越来越远，终於看不见了，你整个身体悬在半空中，不知到会飘到何处。\n");
    tell_room(place=environment(who),"\n"+who->query("c_name")+"越飞越高、越飞越快，终於缩成一点，消失在空中了。\n\n",who);
    who->set_temp("block_command",0);
    who->move_player(OTEMP"void","SNEAK");
    return 1;
}

void end(object ob1,object who)
{
  tell_object(who,"\n空中传来巫师老猫的声音：对不起、你修□还不够，等你功\德圆满时，\n自然有人会来带你成仙。\n\n");
  tell_room(place,"\n你见到"+who->query("c_name")+"从空中慢慢的飘了下来。\n\n",who);
  who->move_player(place,"SNEAK");
  ob1->remove();
  return;
}
