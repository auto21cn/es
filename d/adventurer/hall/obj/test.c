#include "mudlib.h"

inherit OBJECT;

void create()
{
     set_name("salt bottle","盐罐");
     set_short("盐罐");
     set_long("盐是做菜时不可或缺的帮手，不仅可以使食物更加美味，更可使食物常保新\n"
     "鲜。这个盐罐就是装盐用的，但是由於盖子是密封的，你也不知道里面还\n"
     "有多少盐。\n"
      );
     set("use_time",10);
     add("id",({ "bottle","salt" }) );
     set( "unit", "瓶");
     set("weight",10);
     set("value", ({ 400, "silver" }));
}
void init()
{
	add_action("do_cook","cook");
}
int do_cook(string arg)
{
	int skill1,skill2;
	object me,target,env;
	me = this_player();
	skill1 = me->query_skill("anatomlogy");
	skill2 = me->query_skill("cook");
    	if ( !skill2 || skill2=0 ) 
    	        return notify_fail("你想干什麽?");
    	if (!arg) return notify_fail("你要用什麽材料展露你出色的厨艺？\n");
	env = environment(me);
	if( !env || !target = present(arg, env) )
		return notify_fail("你要烹饪的材料不在这里。\n");
        if ( !target->id("corpse")) {    
	  tell_object(me,"你疯了吗?这个东西不能拿来煮啦!!\n");
	  tell_room( env, 
	             me->query("c_name")+"竟然企图把"+
	             target->query("c_name")+"作为料理的材料。\n", me);
	             return 1;
	                            }
	if ( !me->query_vision() )
        return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
	if ( !present("carver",me) )
	        return notify_fail("你还需要一把菜刀才能表现你完美的厨艺。\n");
	tell_object(me,
		set_color("你掏出盐罐和菜刀，蹲在路边的尸体旁，开始剥洗...\n","HIY") );
	tell_room(environment(me),sprintf("%s掏出一把小菜刀和一个小罐子，鬼鬼祟祟的蹲在路边的尸体旁边...",
		me->query("c_name")),
		me );
        target->remove();
        seteuid(getuid());
        call_out("cook",3,me);
        return 1;
} 
int cook(object me)
{
        object meat;
        int heal1,heal,skill1,skill2,level;
        
        skill1 = me->query_skill("anatomlogy");
        skill2 = me->query_skill("cook");
        level = me->query_level();
        heal1 = 7*skill2+2*skill1+3*level-random(10);
        heal = heal1/20;
        if ( !random(skill1)>9 ) 
                return notify_fail("你企图用菜刀割下尸体的肉，却把尸体挖的面目全非..\n");
        tell_object(me,
        "你掏出菜刀，切下尸体身上的上肉，再撒上一些盐，把它做成乾肉。\n");
        tell_room(environment(me),"你看到" +me->query("c_name")+                
        "用菜刀把尸体上的肉一片片切下来，又在肉上撒上一些东西...\n",me);
        meat = new("/d/adventurer/hall/obj/dry_meat");
        meat->set("heal",heal);
        if (skill2/2-random(5)<1) 
                 {
                 meat->set("rotten",1);
                 meat->move(me);
                 set("use_time",query("use_time")-1);
                 if ( query("use_time")<1 ) {
                       tell_object(me,
                       "你发现盐罐已经空了，你随手把它丢在路边。\n");
                       remove();
                       return 1;
                                            }
                 return 1;
                 }
        meat->move(me);
        set("use_time",query("use_time")-1);
        if ( query("use_time")<1 ) {
                        tell_object(me,
                        "你发现盐罐已经空了，你随手把它丢在路边。\n");
                        remove();
                        return 1;
                                   }
        return 1;
}
