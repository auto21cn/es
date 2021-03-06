#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown rock","奇怪的石头");
	add( "id" , ({ "rock" }) );
	set_short("奇怪的石头");
	set_long(
		"这是一颗看来颇特殊的石头，但由於被沙石埋住了，只留下一点表面\n"
		"露出地表，你也不能非常确定他是什麽，也许把它挖出来才能\n"
		"搞清楚它是什麽...\n"
	);
   	set("unit","颗");
   	set("dig",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("is_fresh",1);
}
void init()
{
      add_action("do_dig","dig");
}
int do_dig( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "rock") {
           write("你想挖什麽??\n");
           return 1;
           }
           seteuid(getuid());
           write("你双手并用，把这颗怪石头挖了出来，并且仔细的观察他！\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"双手并用，把路边的一颗石头挖了出来\n"
           "，并且拿在手上仔细观察...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/adventurer/natural_history/stone");break;
           case 1: obj = new("/d/adventurer/natural_history/gem");break;
           default : break;
           }
           
           if (obj->query("c_name")=="小石子") {
           obj->set("need_skill",1);
           str = "普通的\n";
           }
           else str = "罕见的\n";
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("根据你对博物学与自然生物的认识，你断定这是一"+obj->query("unit")+ str
                +obj->query("c_name")+"。你很快的把它收起来...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"说道: 哈，找到一"+obj->query("unit")+"宝贵的"
                +obj->query("c_name")+"，真是赚到了...\n\n", ({this_player()}) );
               
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("你从来没见过这玩意，或许它没什麽用吧..你顺手把它丢在路边\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"似乎不知道挖出的东东是什麽，随便把他\n"
                "丢在路边...\n\n",({this_player()}) );
               
                remove();
                return 1;
                }
                }
int move(mixed ob)
{
	if ( ob && living(ob))
        call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

void not_fresh(object what)
{
	remove();
}
