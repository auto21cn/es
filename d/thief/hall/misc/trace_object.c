//#pragma save_binary

// trace_object for /cmds/std/_trail.c

#include <mudlib.h>
inherit OBJECT;

void stop_trace(object,object);
int check_move(object,string);
int be_found(object ,object);
int do_go(string);
int flag;
void create()
{
	flag = 0;
	seteuid( getuid() );
	if ( clonep(this_object()) ) {
		set_default_ob(__FILE__);
		return;
	}
	set_name("trace object","发报器");
	add( "id", ({ "ob" }) );
	set_short("发报器");
	set_long(
	"这是用来跟踪某人用的东西, 玩家是看不到的, 请不要随便 dest 掉。\n"
	);
	set("prevent_drop", 1);
	set("prevent_insert", 1);
	set("invisible",1);

}

void init()
{
	add_action("do_go", "go");
}

int do_go(string dir)
{
	int i;
	object *tracers,target,oldenv,newenv;

	target = this_player();
	oldenv = environment(target);
	tracers = target->query_temp("tracers");
	if ( !flag ) {
		flag = 1;
		target->force_me("go "+dir);
	} else {
		flag = 0;
		return 0;
	}
//	"/cmds/std/_go"->cmd_go(dir);
//	newenv = environment(target);
	for ( i = sizeof(tracers)-1 ; i >= 0; i--) {
	    if ( tracers[i] == 0 ) continue;
	    if ( ! visible(target,tracers[i]) ) continue;
	    if ( present(tracers[i],oldenv) ) {	
		tracers[i]->quick_message( 
			sprintf("你悄悄地跟著%s往%s移动....\n",target->query("c_name"),to_chinese(dir)));
/*
	//	if ( random(30) > 20 )  
		  if ( be_found(tracers[i],target) ) {
		    	tracers[i]->quick_message( sprintf("不妙! %s发现你的行踪, 不能再跟了。\n",target->query("c_name")));
			target->quick_message(sprintf("\n你发现%s躲躲藏藏的跟著你走过来,不知道有什麽企图...\n",tracers[i]->query("c_name")) );	
			stop_trace(target,tracers[i]);
		  }
*/
		if ( wizardp(tracers[i]) )
			tell_object(tracers[i],"go "+dir);

//	    	tracers[i]->push_cmd("go "+dir);
		tracers[i]->force_me("go "+dir) ;
	    } // end of present
	} // end of for 
	if ( sizeof(tracers) < 1 ) 
		this_object()->remove();
	return 1;
}

int be_found(object tracer,object target)
{
	int skill;

	if ( wizardp(tracer) ) return 0;

	skill = (int) tracer->query_skill("hide") + 
		(int)tracer->query_skill("sneak") +
		(int)tracer->query_stat("kar")*5;
	// if not hidding , easy be found
	if ( (int) tracer->query_temp("hidding") == 0 ) 
		skill = skill / 10;
	if ( random(skill) < (int)target->query_level() * 6 ) 
		return 1;
	return 0;
}

void stop_trace(object target,object tracer)
{
	object *tracers;

	tracers = target->query_temp("tracers");
	tracers -= ({tracer});
	target->set_temp("tracers",tracers);
	tracer->delete_temp("trace_target");
}

#if 0
int check_move(object me,string dir)
{
	string func;

	func = (string) environment(me)->query("pre_exit_func/"+dir);
	tell_object(me,"func = " + func + "\n");
	if ( func && call_other(environment(me),func) )
		return 0;
	return 1;
}
#endif
