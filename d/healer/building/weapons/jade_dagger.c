#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "jade dagger", "翡翠匕首" );
	add( "id", ({ "dagger" }) );
	set_short( "翡翠匕首" );
	set_long(
		"一把精致的翡翠匕首，它的刀刃是用纯翡翠磨成的，刀柄用上等的黑檀木\n"
		"制成。虽然这把匕首看起来不是很锋利，但是当你用手指触摸它的刀锋时\n"
		"，你的第六感告诉你，这把匕首杀过不少人....。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weapon_class", 43 );
	set( "min_damage", 25 );
	set( "max_damage", 40 );
	set( "extra_skills",(["anatomlogy":5,"bandage":10]) ) ;
	set( "weight", 30 );
	set( "value", ({ 500, "gold" }) );
	set( "no_sale", 1 );
    set( "hit_func","light_damage" );
}

int light_damage(object victim,int damage)
{
	object holder;
   	int pie,kar,vpie,vkar;
	int degree;
        int sp;
        
   	if( !victim ) return 0;
   	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   	pie = (int)holder->query_stat("piety");
   	kar = (int)holder->query_stat("kar");
   	vpie = (int)victim->query_stat("piety");
   	vkar = (int)victim->query_stat("kar");
   	if (userp(holder)) {
	   	if (pie>vpie) pie = vpie;
	   	if (kar>vkar) kar = vkar;
   	}
   	if (random(pie+kar) < 2* random(vpie+vkar)) return 0;
   	if (userp(holder)) {
		sp = holder->query("spell_points");
		if (! sp || sp < 3) return 0;
		holder->set("spell_points", sp -3 );
	}
	tell_object( holder,"你的翡翠匕首发出一道眩目的光芒, 照向"+
	             victim->query("c_name")+"的眼睛。\n\n");
	tell_object( victim,holder->query("c_name")+
	             "的翡翠匕首发出一道眩目的光芒, 照向你眼睛。\n\n");
	tell_object( victim,"你感到眼睛一阵遽痛....你看不见东西了。\n");
	tell_room( environment(holder),
	             holder->query("c_name")+"的翡翠匕首发出一道眩目的光芒, 照向"+
	             victim->query("c_name")+"的眼睛。\n\n",({holder,victim})
	            );
    degree=victim->query("blind")+1;
    if (degree>10) degree=10;
    victim->set("blind",degree);
	return 0 ;
}
