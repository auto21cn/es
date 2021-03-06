//#pragma save_binary

// monk_book.c
// The guild token of the monk's guild.
// Sub Usage: The spell book of mages, containing most spells one can find
//            in the mud. But not all spells it can remember.
// Created by Kyoko Autinashi Nov 9 '93.
// use by angel for monk_guild

#include <mudlib.h>
#include "monk.h"    

inherit GUILD_OB;
inherit OBJECT;
mapping levels = ([]);

void create()
{
	guild_ob::create();
	seteuid( getuid() );
	set_class_name("monk");
#include <compress_obj.h>
	set_name("monk_book", "佛经");
	set_short("佛经");
	set_long( @LONG
这是一本泛黄的佛经。少林固然有号称天下常胜不败门派的美誉，也拥有笑傲武林的
武学经典，但是希望众僧切勿以此为傲... 强中自有强中手，还是希望大家多多研习
佛经，早日超脱这个争强夺胜的世界... 如果你想知道这本佛经的资料及使用，可用
\"help monk_book\" 指令。
LONG
	);

	set( "weight", 10 );
	set( "unit", "本" );
        
	set( "allow_material", ({ "cloth", "leather","wood","stone", }));
	set( "second_material", ({ "element", }));

	set( "extra_look", "$N随身带著一本破旧泛黄的佛经，上面用楷书写著『少林』。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_comrades","monks");
	add_action("do_chat", "monk");
}

int do_comrades()
{
        object *usr, temp;
        int i, j;

        usr = filter_array( users(), "filter_monk", this_object() );
        usr = sort_array( usr, "sort_usrs", this_object() );
        if ( sizeof(usr) ) {
           i = sizeof(usr);
           write( 
             "目前共有 " + i + " 位少林武僧连线中:\n"
			 "==================================================\n");
           while(i--) {
                printf( "[ %2d ] %s (%s)\n", usr[i]->query_level(),
                  usr[i]->query("short"), capitalize(usr[i]->query("name")) );
           }
        } else 
           write("似乎没有任何武僧在线上....。\n");
        return 1;
}

int sort_usrs( object u1, object u2 )
{
        return (int)levels[u1] - (int)levels[u2];
}

int filter_monk( object plr )
{        
        string name;
        if( (string)plr->query("class")=="monk" && visible(plr,this_player()) ) {
          levels[plr] = (int)plr->query_level();
          if( !levels[plr] || levels[plr] == 0 ) return 0;
          return 1;
        }
        return 0;
}

int do_chat(string arg)
{
        object *usr;
        int chinese_mode, i;
        chinese_mode = can_read_chinese();
        
        if( !arg ) return notify_fail(
          "你想对其它的少林武僧说什麽？\n");
        return guild_ob::guild_line(arg);
}

int info(string arg)
{
        
	switch(arg) {
		case "history":
		          cat( GUILD_DATA"c_monk_history" );
			break;
	    case "init":
	              cat( GUILD_DATA"c_monk_init" );
	        break;
	    case "skills":
	              cat( GUILD_DATA"c_monk_skills" );
	        break;
	    case "gonfu":
	            cat( GUILD_DATA"c_monk_gonfu" );
	        break;
	    case "commands":
	            cat( GUILD_DATA"c_monk_commands" );
	        break;
		case "topic":
		case "topics" :
		default : 
			cat( GUILD_DATA"c_topics");
			  break;
	}
	return 1;
}

int help( string arg )
{
    if( !arg || !id(arg) ) return 0;
	cat( GUILD_DATA"c_monkbook");
	return 1;
}
