#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;

void init()
{
	add_action( "eat_food", "drink_me" );
}

void create()
{
        
	set_name("Sugar Swallow-Nest","「冰糖燕窝」");
	add( "id" , ({ "nest","sugar swallow-nest" }) );
        set_short(set_color("「冰糖燕窝」","HIY"));
        set_long(@C_LONG
一碗精心调制的补品，嗯，喝下它(drink_me nest)想必能让你神清气爽。
C_LONG
	);
   	set("unit","碗");
   	set("weight", 50);
   	set("value",({ 450, "gold" }) );
}

int eat_food(string arg)
{
        
    if( !arg || ( arg != "nest") && ( arg != "sugar swallow-nest" ) ) {
        tell_object(this_player(),"请用 ( drink_me nest )。\n");
        return 1;
    }
    this_player()->add_temp("drink_nest_times",1);
    if( this_player()->query_temp("drink_nest_times")>5 ) {
       tell_object(this_player(),
         "哟呀，你喝下了这一碗"+set_color("「冰糖燕窝」","HIY")+"之後觉得不大对劲，看来是补过头了～～\n");
       tell_room( environment(this_player()),"哟呀，"+
         this_player()->query("c_name")+
         "喝一碗"+set_color("「冰糖燕窝」","HIY")+"之後开始有点怪怪的，看来是补过头了～～\n",
         this_player());
       this_player()->delete_temp("drink_nest_times");
       CONFUSED->apply_effect(this_player(),20,1);    
       remove();
       return 1;
    }
    tell_room( environment(this_player()),"你站在旁边流口水地看著"+
        this_player()->query("c_name")+"喝下一碗"+set_color("「冰糖燕窝」","HIY")+"～～\n", 
         this_player());
    tell_object( this_player(),
        "你满足地喝下一碗"+set_color("「冰糖燕窝」","HIY")+"。嗯，好喝～～\n");
    this_player()->set("hit_points",this_player()->query("max_hp"));
    this_player()->set("spell_points",this_player()->query("max_sp"));
    remove();
    return 1;
}
