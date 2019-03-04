#include <mudlib.h>

inherit OBJECT;

void create()
{
   seteuid(getuid());
   set_name( "mummy", "木乃伊" );
   set_short( "木乃伊" );
   set_long(
	"一具硕大的木乃伊, 或许你可以试著解剖(anatomise)它。\n"
	);

   set( "unit", "具" );
   set( "weight", 5000 );
   set( "prevent_get", 1 );
}

void init()
{
   add_action( "am_corpse", "anatomise" );
}

int am_corpse(string str)
{
   object heart, weapon;
   int op_succ, op_fail;

   op_succ = this_player()->query("op_succ_count");
   op_fail = this_player()->query("op_fail_count");

   weapon = (object)this_player()->query("weapon1");

   if( !str || str != "mummy" )
   return notify_fail( "你想要做啥?\n" );
   if( !weapon || (string)weapon->query("type") != "dagger" )
   return notify_fail( "你似乎缺乏适当的解剖工具。\n" );
   if( op_succ >= op_fail && op_succ +op_fail > 25
     && (string)this_player()->query("class") == "healer" ) {
	heart = new( "/d/noden/tomb/obj/heart" );
	tell_object( this_player(),
	"你幸运地得到一颗黄金之心!\n" );
	heart->move(this_player());
   }
     write( "你把木乃伊切烂了。\n" );
   tell_room( environment(this_object()),
	  "木乃伊被"+this_player()->query("c_name")+"切烂了。\n", ({ this_player() }) );
   this_object()->remove();
   return 1;
}

