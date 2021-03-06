#include <mudlib.h>

inherit OBJECT;

void create()
{
	set("packked",0);
	set_name( "Herb of re-live", "回阳草" );
	add( "id", ({ "herb" }) );
	set_short( "回阳草" );
	set_long(@C_LONG
这是一株回阳草，它现在被挖离泥土了，所以显得有些枯\萎，你最
好赶快把它包好(pack)、种(plant)回去，再浇(water)些水。
C_LONG
	);
	set( "unit", "株" );
	set( "weight", 5 );
	set( "packked", 0 );
	set( "value", ({ 1, "copper" }) );
//	set( "no_sale", 1 );
	set( "useless", 1 );
}

void init()
{
	add_action( "do_plant", "plant" );
	add_action( "do_pack", "pack" );
	call_out( "mess_up", 30, this_object(), 1 );
}

int do_pack(string arg)
{
    if( !arg || arg!="herb" )
    	return notify_fail( can_read_chinese() ?
    		"包什麽？\n" : "pack what?\n"
    	);
    if( query("packked") )
    	return notify_fail( "这株回阳草已经包过了。\n");
    tell_object(this_player(),
     	"你仔细的把回阳草连土包好，看来它可以维持长一点的时间。\n"
    );
	set("packked", 1);
    return 1;
}

int do_plant(string arg)
{
	object obj;

	obj=environment( this_player() );
   	if( !arg || arg != "herb" )
    	return notify_fail("种什麽？\n");
	if( (string)obj->query("short")=="药圃" ) {
	  if( query("packked") ) {
        tell_object(this_player(),
                    "你把回阳草种在药圃上，可是它还是垂头丧气的。\n"
		);
		this_player()->set_temp("herb_quest/step",1);
	  } else
        tell_object(this_player(),
            "由於你没有把回阳草包好，它已经七零八落的活不成了，你只好把它丢了。\n"
        );
      remove();
	} else
       tell_object(this_player(),
         "你要把回阳草种在这里？你确定？\n"
       );
    return 1;
}

void mess_up(object what, int first)
{
    object owner;
    
    owner = environment(what);
    if( what->query("packked") && first ) {
    	call_out( "mess_up", 100, what, !first );
    	return;
    }
    if( living(owner) )
      tell_object( owner,  
		"啊! 回阳草枯\了，你只好把它扔了。\n" 
      );
    what->remove();
}
