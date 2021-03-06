// bandages.c
// Rewritten by Yueh from bandage.c (1-2-96)
#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
#include <compress_obj.h>
	set_name( "bandages", "绷带卷" );
	set_short("绷带卷" );
	set_long(
		"绷带是一种常见的、用来使受伤的人加快恢复速度的医药用品，绷带\n"
		"卷共可包扎五次。你可以用 bandage 指令替自己或别人包扎。\n"
	);
	set( "unit", "卷" );
	set( "weight", 25 );
	set("left",5);
	set( "value", ({ 75, "silver" }) );
}

void init()
{
	add_action("do_bandage", "bandage");
}

int do_bandage(string arg)
{
	object dest,ban;
	int skill, pie, left;
	mixed *cond; 

	// The player must carry the bandage before he can bandage.
	if( environment()!=this_player() ) return 0;
	
	if( !arg || arg=="me" || arg=="myself" ) dest = this_player();
	else dest = present( arg, environment(this_player()) );
	if( !dest )
		return notify_fail("你要包扎谁？\n");

	if( (int)dest->query_temp("bandaged") >= time()) {
		write("如果你要重新包扎，请先除去(remove)原来的绷带。\n");
		return 1;
	}

	if( dest->query("hit_points")==dest->query("max_hp") ) {
		write("绷带只能用来包扎受伤的人。\n");
		return 1;
	}
	
	// Ok, now do the bandage stuff.
	if( dest==this_player()) {
		write("你从绷带卷撕下一段绷带细心地为自己的伤口包扎。\n");
		tell_room( environment(this_player()), 
			sprintf("%s用绷带包扎自己的伤口。\n",this_player()->query("c_name")),
			this_player() );
	} else {
		write(sprintf("你从绷带卷撕下一段绷带细心地替%s包扎伤口。\n",dest->query("c_name")));
		tell_object( dest,
			sprintf("%s用绷带替你包扎伤口。\n",this_player()->query("c_name")));
		tell_room( environment(this_player()), 
			sprintf("%s用绷带替%s包扎伤口。\n",this_player()->query("c_name"),dest->query("c_name")),
			({ dest, this_player() }) );
	}
	
	skill = this_player()->query_skill("bandage");
	pie = dest->query_stat("pie");
	cond = dest->query("conditions/herb_apply");
	if( cond && sizeof(cond) ) {
		// speed up 减 0% 到 80%, when skill 0 到 100, by Kyoko/Annihilator.
		cond[0] -= cond[0] * skill * 8 / 1000;
		if( cond[0] < 1 ) cond[0] = 1;
		dest->set("conditions/herb_apply", cond);
	}
	BANDAGED->apply_effect(dest, 12-skill*84/1000);
	dest->set_temp("bandaged",time()+50+skill+3*pie);

	ban=new("/obj/bandage_used");
	ban->set_fuel(50+skill+3*pie);
	this_player()->add("load",-5);
	set("weight",query("weight")-5);
	ban->move(dest);
        // add this part to exp gain for healers
        if((string)this_player()->query("class")=="healer")
             this_player()->gain_experience(skill/5) ;
	left=query("left")-1;
	if (left== 0) {
		write("这卷绷带卷用完了，你随手把它丢掉。\n");
		remove();
	}
	else set("left",left);
	return 1;
}

