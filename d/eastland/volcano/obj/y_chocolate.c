#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "yellow_chocolate", "黄色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short( "黄色巧克力" );
	set_long(
		"这是一个欲望巧克力，你可以□□看(taste)。\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   int align;

   if(!arg || arg!="chocolate")
   { write("你要吃什麽？\n");
     return 1;
   };

   write("你吃了这块巧克力，你的心里浮出一个影像：\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",9,this_player());
   call_out("end",11,this_object());

   align=this_player()->query("alignment");
   this_player()->set("alignment",align+10);
   return 1;
}

int idle_time1(object who)
{
    tell_object(who,"你耳边听到朝拜的声音，定神一看，只见所有的ES玩家正跪在地上向你膜拜  \n");
    tell_object(who,"你不禁哈哈大笑．．．．．．．．我是ES之王啦．．．．．．．．．．．．  \n");
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who,"突然你的眼前一片黑暗，你震了一下，你发觉你的周围都是人，而且不知道用\n");
    tell_object(who,"手对著你指指点点的做什麽，脸上还带著鄙视的笑容，\n");
    tell_object(who,"你正觉得奇怪时，突然发现自己正流著口水，地上还□□的，糗死了\n");
    tell_object(who,"你恨不得地上有个洞可以马上钻进去。\n");
    who->set_temp("block_command",0);
    return 1;
}

void end(object ob1)
{
  ob1->remove();
  return;
}
