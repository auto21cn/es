//#pragma save_binary

#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set("can_apply", 1);
	set("reaction", 0);
}

void init()
{
	medicine::init();
}

int apply(object me, object dest)
{
	int frequency, heal, duration;

	if( me->query_attacker() || dest->query_attacker() ) {
		tell_object(me, can_read_chinese(me)?
			"( 你不能在战斗中敷这种药，或替战斗中的人敷这种药。 )\n":
			"You can't do this while you or your patient is fighting!\n" );
		return 0;
	}

	if( dest->query_temp("bandaged") ) {
		tell_object( me, can_read_chinese(me)?
			"你必须先把绷带拆掉，才能敷药。\n":
			"You can't apply herbs when the wounds are bandaged.\n");
		return 0;
	}

	if( (int)dest->query("hit_points") >= (int)dest->query("max_hp") ) {
		tell_object( me, can_read_chinese(me)?
			(me==dest? "你":(string)dest->query("c_name"))+
			"一点伤也没有，还是省省吧。\n" :
			(me==dest? "You":(string)dest->query("cap_name"))+
			" doesn't seems to need that.\n" );
		return 0;
	}

	// if we got here, mean me can apply this at dest.
	frequency = (int)query("heal_frequency");
	if( frequency < 1 ) frequency = 10;
	heal = (int)query("heal_apply");
	if( undefinedp(heal) ) heal = 1;
	duration = (int)query("duration");
	if( duration < 1 ) duration = 1;

	HERB_APPLY->apply_effect(dest, frequency, heal, duration);
	return 1;
}
