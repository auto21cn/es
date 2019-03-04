//sage 修改于：98-4-29 6:47////#pragma save_binary

#include <move.h>
#include <daemons.h>
#include "killer.h"
mapping levels = ([]);

mapping skill_list = ([
        "inner-force": ({ 100, 100 }), 
        "two-weapon" : ({ 180, 100 }),
        "longblade"  : ({ 100, 100 }),
        "shortblade" : ({ 150, 100 }),
        "thrusting"  : ({ 150, 100 }),
        "polearm"    : ({ 100, 100 }),
        "jousting"   : ({  80, 100 }),
        "blunt"      : ({ 250,  80 }),
        "dagger"     : ({ 250,  80 }),
        "axe"        : ({ 150,  90 }),
        "parry"      : ({ 180, 100 }),
        "block"      : ({ 150, 100 }),
        "tactic"     : ({ 250, 100 }),
        "defend"     : ({ 100, 100 }),
        "riding"     : ({ 100, 100 })
]);

string *c_titles = ({
        "杀手帮打杂工",
        "杀手帮看门夫 ",
        "杀手帮菜鸟杀手",
        "杀手帮老鸟杀手",
        "杀手帮白虎堂堂主",
        "杀手帮青龙舵舵主",
        "杀手帮左护法",    
        "杀手帮右护法",
        "杀手帮长老",
        "杀手帮副帮主",

});

/*
 * TO DESIGN A GUILD:
 *    You must define the following functions in the guild object that
 * can be called in /std/guild.c or other place. These function should
 * do certain check to make sure its argument are correct.
 */

/************************** INTERFACE *****************************/
int is_guild_member(object obj);
int query_stat_max(string stat);
string *query_skill_list();
int query_skill_exp_cost(string sk_name, int sk_level);
int query_skill_max(string skill);
int query_skill_cost(string skill);
string *query_guild_master();
int equip_level(object armor);
/************************** INTERFACE *****************************/

void create()
{
        seteuid( getuid() );
}

// This function judge if a player is a member of this guild. Return 1
// means yes, and 0 for no.
int is_guild_member(object obj)
{
        if( !living(obj) || !obj->query("user") ) return 0;
        if( (string)obj->query("organization") != "killer" ) return 0;
        return 1;
}

string query_guild_room()
{
        return GUILD_LOCATION;
}


// The following founctions maintains the skill experience system of this
// guild. You MUST define them in the guild object. These functions are
// called in /std/guild.c to determinate if a player can raise his/her
// skills by training.
string *query_skill_list()
{
        return keys(skill_list);
}

int query_skill_exp_cost(string sk_name, int sk_level)
{
        if( undefinedp( skill_list[sk_name] ) ) return 0;
        if( sk_level < 0 || sk_level >= skill_list[sk_name][1] ) return 0;
        return (int)STATS_D->query_skill_exp(sk_level) * skill_list[sk_name][0] / 100;
}

int query_skill_cost(string skill)
{
        if( undefinedp( skill_list[skill] ) ) return 0;
        return (int)skill_list[skill][0];
}

int query_skill_max(string skill)
{
        if( undefinedp( skill_list[skill] ) ) return 0;
        return (int)skill_list[skill][1];
}

string *query_guild_master()
{
        return GUILD_MASTER;
}

int check_token(object player)
{
        string old_org;
        if( !is_guild_member( player ) ) 
        {
           write("你不是本组织的!\n");
           return 1;
        }
        old_org = (string)player->query("organization");
        player->delete( "organization" );
        PATH_D->delete_path(player, "/d/"+old_org+"/cmds");
        player->set("organization", ORG_NAME );
                // just add for a while.
        PATH_D->add_path(player, "/d/"+ORG_NAME+"/cmds");
        write("身份确认成功!\n");
        return 1;


}


// This function is called when a player want join the guild in /std/guild.c
// The guild check if the player is a wizard or didn't join any guild first
// and call this function to enroll player. You can put extra check here, and
// return 0 if failed.
int join_player(object player)
{
        string race,old_org;

        race = (string)player->query("race");
        if( member_array(race, ({"imp", "beholder", "vampire" }))!=-1 )
                return notify_fail( 
                        "对不起，本公会不收妖精、眼魔与吸血鬼。\n");

        old_org = (string)player->query("organization");
        player->delete( "organization" );
        PATH_D->delete_path(player, "/d/"+old_org+"/cmds");
        player->set("organization", ORG_NAME );
                // just add for a while.
        PATH_D->add_path(player, "/d/"+ORG_NAME+"/cmds");
        player->set("level",1);

        return 1;
}

string query_c_title(object player)
{
        int level;
        string kni, str;
        
        level = player->query("level");
        if( level < 1 ) level = 1;
        if( level > 10 ) level = 10;
        str = c_titles[level-1] +" "+to_chinese(player->query("class"))
              +player->query("c_name");
        return str;
}
string query_title(object player)
{
        return query_c_title(player);
}
string *query_titles()
{
        return c_titles;
}
string query_org()
{
        return ORG_NAME;
}
string *query_c_titles()
{
        return c_titles;
}

// The funnction decide equip level when a knight wear armor
int equip_level(object armor)
{
        string material;
        
        material = armor->query("material");
        if( !material ) return 2;
        if( member_array(material, ALLOWED_MATERIAL) != -1 ) return 0;
        else if( member_array(material, SECOND_MATERIAL) != -1 ) return 1;
        else return 2;
}
int filter_members(object plr)
{
        if( (string)plr->query("organization")==ORG_NAME
              && visible(plr,this_player()) ) {
                levels[plr] = (int)plr->query("level");
                if( !levels[plr] || levels[plr] == 0 ) return 0;
                return 1;
        }
        return 0;
}

int sort_members( object u1, object u2 )
{
        return (int)levels[u2] - (int)levels[u1];
}

int filter_member(object plr)
{
        if( (string)plr->query("organization") == ORG_NAME ) return 1;
        return 0;
}

// default function to list all guild members.
int list_guild_members()
{
        object *usr;
        int i;

        usr = filter_array( users(), "filter_members", this_object() );
        usr = sort_array( usr, "sort_members", this_object() );
        if( sizeof(usr) ) {
                this_player()->quick_message(
             "目前共有 " + sizeof(usr) + " 位"+to_chinese(ORG_NAME)+"连线中:\n"
                         "==================================\n");
                for( i=0; i<sizeof(usr); i++ )
                        this_player()->quick_message(
                                sprintf( "[ %2d ] %s (%s)\n", usr[i]->query("level"),
                                        usr[i]->query("short"), capitalize(usr[i]->query("name")) ) );
        } else 
                this_player()->quick_message(
                        "似乎没有任何"+to_chinese(ORG_NAME)+"公会的成员在线上....。\n");
        return 1;
}

// default guild channel, added by Kyoko.
// if a admin set listening then he will heaar, too.
int guild_line(string msg)
{
        object *usr;
        int i;
        string color;

        if( !msg ) return notify_fail(
                "你要对本组织的同伴说什麽？\n");
        usr = filter_array( users(), "filter_member", this_object() );
        if( sizeof(usr) )
                for( i=0; i<sizeof(usr); i++ )
                        usr[i]->quick_message( 
                                sprintf(set_color("[%s] %s(%s):", "CYN", usr[i])+" %s\n",
                                        to_chinese(ORG_NAME), this_player()->query("c_name"),
                                        capitalize(this_player()->query("name")), msg) );
        return 1;
}
