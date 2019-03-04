#include <mudlib.h>
inherit WEAPON;
 
void create()
{
 
        set_name( "evil dagger", "邪皇匕" );
        add( "id", ({ "dagger" }) );
        set_short( "邪皇匕" );
        set_long(
                "这是一把奇异的匕首,握把底部铸了一颗骷颅头,两个窟窿中不时闪烁著妖异的光芒。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 30 );
        set("type","dagger");
        set( "min_damage", 20);
        set( "max_damage", "@@check_ali" );
        set( "weight", 25 );
        set( "second", 1 );
        set( "value", ({ 1500 , "silver" }) );
}
 
int check_ali()
{
    object holder;
    int my_ali,max;
 
    holder = this_player();
    my_ali = (int)holder->query("alignment");
        max = (my_ali < -10000) ? 10 : (-my_ali/1000);
        return (max + 20);
}
 
int stop_wield()
{
        object holder;
        int my_ali;

        holder = this_player();
        my_ali = (int)holder->query("alignment");
        if (my_ali > 0) {
                notify_fail( 
                "匕首上传来一股奇异的力量,使你握不住它!!\n" 
                           );
        return 1;
	}
	return 0;
}

