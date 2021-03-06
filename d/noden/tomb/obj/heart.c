#include <mudlib.h>

inherit ARMOR;

void create()
{
   set_name( "golden heart", "黄金之心" );
   add( "id", ({ "heart" }) );
   set_short( "黄金之心" );
	set_long(
   "这是一颗纯金的心脏, 它正散发一股奇异的光泽, 或许具有神秘的力量。\n"
	);
	set( "type", "misc" );
   set( "material", "healer" );
   set( "weight", 50 );
   set( "prevent_drop", 1 );
   set( "defense_bonus", 6 );
   set( "extra_skills", ([ "anatomlogy" : 10 ]) );
   set( "equip_func", "equip_heart" );
   set( "unequip_func", "unequip_heart" );
}

int equip_heart()
{
   int op_succ, op_fail, op_times;

   op_succ = this_player()->query("op_succ_count");
   op_fail = this_player()->query("op_fail_count");
   op_times = op_succ + op_fail;

   if( op_times > 100 ) {
        set( "defense_bonus", 10 );
        tell_object( this_player(),
          "黄金之心闪耀著令人眩目的光彩!\n" );
        return 1;
   }
   if( op_times < 100 && op_times > 50 ) {
        set( "defense_bonus", 8 );
        tell_object( this_player(),
          "黄金之心闪耀著十分灿烂的光芒!\n" );
        return 1;
   }
}

int unequip_heart()
{
   set( "defense_bonus", 6 );
   return 1;
}
      
