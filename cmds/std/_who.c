//#pragma save_binary

/*
// Written By Jubal @ TMI
// Sulam changed the title stuff 1/2/92
// Modified for time zones by DocZ @ TMI (1/20/92)
//
// Modified for players by Truilkan@TMI (02/15/92) -- eventually TMI
// will be used as the base for a real mud and real muds have real players
// that need player-type who commands (those that don't contain for-wizard
// eyes only information.  The original TMI who command has been renamed
// as "people")
// Modified to respect invisibility by Mobydick 10/10/92
// Pallando (93-02-22) Changed [0] to <login> on aesthetic grounds.
// Watcher (93-03-22) Removed User inhabited monsters from the display.
// Watcher (93-04-14) Change the query("invisible") to a visible() check.
// Grendel (93-07-13) Added sorting alphabetically
// Grendel (93-07-26) Added -d option, optimised
// Grendel (93-08-18) Added @mud option, optimised
// Kyoko   (94-05-11) Added -b option, optimised
// Iris    (95-05-10) Added -l option, default brief mode

// Bugs: wont detect netdead wizards in monster bodies (!)
//       Don't know whether to get round this by checking for connection
//       objects or not - haven't looked at connection objects
//       closely yet to figure out if it is safe
//       Could be optimised some more...
*/

#include <writef.h>
#include <mudlib.h>
#include <daemons.h>
#include <net/daemons.h>
#include <net/macros.h>

#define SYNTAX "Usage: who [ @<mud> | -d | -l ]\n"
#define SHORT_DESCRIPTION "short"
#define CAP_NAME "c_name"
#define WHO_TITLE "c_title"

inherit "/adm/daemons/timezone";
inherit DAEMON;

#define c_dvd "——————————————————————————————————————\n"


// sort array doesn't allow the optional argument the way filter array
// does, so we have to make it global
// This mapping is used so we don't have to do player->query("name")
// several zillion times in the sort function
mapping levels;

int cmd_who( string arg )
{
        object *list, *list_wiz,netdead;
        string lines, zone_name, str, msg, mud, pretitle;
        int i,time_zone, wiz_only, dead;
                                string field1,field2, domain_level, c_domain_level,title;
                                mixed val;

        levels = ([ ]);
        if ( !netdead = find_object("/d/std/rooms/netdead" ) ) {
                // Removed new() to a room, wierd code... by Annihilator(05/31/95)
                call_other("/d/std/rooms/netdead", "???");
                netdead = find_object("/d/std/rooms/netdead");
        }
        // check args
        if( arg && arg!="" ) {
            // long option
                if( arg=="-l" ) {
                        lines = "";
                list_wiz = filter_array(users(), "filter_wizards", this_object());
                list_wiz = sort_array(list_wiz, "sort_wizards", this_object());
                        list = filter_array(users()+all_inventory(netdead), "filter_users", this_object());
                        list = sort_array(list, "sort_users", this_object());

                        lines += "◎ 蓝天  \t\t\t\t\t( " + ctime( time() ) + " )\n";

                        lines += c_dvd;

                i=sizeof(list_wiz);
                while( i-- ) {


                                if( !(title = list_wiz[i]->query(WHO_TITLE)) )
                                        title = list_wiz[i]->query("short");
                                if( member_group( list_wiz[i]->query("name"), "admin" ) ) {
                                        c_domain_level = "admin";
                                        domain_level = "God";
                                } else {
                                        c_domain_level = (string)DOMAIN_D->query_domain_level(list_wiz[i]->query_link());
                                        switch( c_domain_level ) {
                                                case "archwizard" : domain_level = "Arch"; break;
                                                case "sage"       : domain_level = "Sage"; break;
                                                case "adept"      : domain_level = "Adept"; break;
                                                case "wizard"     : domain_level = "Wiz"; break;
                                                case "apprentice" : domain_level = "Newbie"; break;
                                                default : domain_level = "???"; break;
                                        }
                                }
                                field1=
                                        sprintf( "【 %s 】%s%s (%s)", to_chinese(c_domain_level),
                                                (list_wiz[i]->query_temp("IRC_USER")?"#":" "),
                                                title,
                                                capitalize((string)list_wiz[i]->query("name")) );

                                if( list_wiz[i]->query("npc") && wizardp(this_player()))
                                        field1 += sprintf( " ",
                                                capitalize( (string)list_wiz[i]->link_data("name") ) );

                                if( list_wiz[i]->query("make-up") && wizardp(this_player()))
                                        field1 += sprintf( " [由 %s 化装]",
                                                capitalize( (string)list_wiz[i]->link_data("name") ) );

                                if (in_edit(list_wiz[i]) || in_input(list_wiz[i]))
                                        field1 += " (编辑中)";
                        
                                if( !field1) field1= "(null)";

                                val = query_idle( list_wiz[i] );
                                if( val >= 3600 )
                                        field1 += "[发呆 " + val/3600 + " 小时]";
                                else if( val >= 60 )
                                        field1 += "[发呆 " + val/60 + " 分钟]";
                                lines += sprintf("%65-s\n", field1 );
                        }
                        i = sizeof(list);
                        if( !wiz_only ) while(i--) {
                        field1 = ""; field2 = "";
                                if( !(title = list[i]->query(WHO_TITLE)) ) title = list[i]->query("short");
                                field1= 
                                        sprintf( "【 %2d 】%s%s (%s)", list[i]->query_level()+list[i]->query("level"),
                                                ( list[i]->query_linkdead() ? "*" : (list[i]->query_temp("IRC_USER")?"#":" ")),
                                                title,
                                                capitalize((string)list[i]->query("name")) );

                                if( list[i]->query("npc") && wizardp(this_player()))
                                        field1 += sprintf( " [由 %s 操纵中]",
                                        capitalize( (string)list[i]->link_data("name") ) );

                                if( list[i]->query("make-up") && wizardp(this_player()) )
                                        field1 += sprintf( " [由 %s 化装]",
                                        ( list[i]->query_linkdead() ? 
                                                capitalize( (string)list[i]->query("org_name") ) :
                                                capitalize( (string)list[i]->link_data("name")) )
                                                );

                                if (in_edit(list[i]) || in_input(list[i]))
                                        field1 += " (编辑中)";
/*
                                if ( list[i]->query_linkdead() )
                                        field1 += " (断线中)";
*/
                                if( !field1) field1= "(null)";

                                val = ( list[i]->query_linkdead() ? 0 : query_idle( list[i] ));
                                if( val >= 3600 )
                                        field1 += "[发呆 " + val/3600 +" 小时]";
                                else if( val >= 60 )
                                        field1 += "[发呆 " + val/60 + " 分钟]";
                                lines += sprintf("%65-s %s\n", field1, wizardp(list[i])? "<wiz>":"");
                        }
                        lines += c_dvd;
                        lines += 
                                "目前共有 " + (sizeof(list_wiz)+sizeof(list)) + " 位使用者连线中。";
                        lines += "\t系统负担: " + query_load_average() + "\n";
                        this_player()->more(explode(lines, "\n"), 0, 1);                
                return 1;
            // linkdead option
            } else if(arg=="-d") {
                        // netdead = find_object("/d/std/rooms/netdead");
                        if ( !netdead ) list = ({ });
                        else list = all_inventory(netdead);
                        list = filter_array(list,"deadp",this_object());
                        if( !sizeof(list) ) {
                                printf("%s%s%s",c_dvd,"目前没有断线的玩家。\n",c_dvd);
                            return 1;
                        }
                        list = sort_array(list, "sort_users", this_object());
                        printf("%s%s%s",c_dvd,"  目前断线的玩家有: \n",c_dvd);
                        i = sizeof(list);
                        while( i-- ) write(capitalize(geteuid(list[i]))+"\n");
                        write(c_dvd);
                        return 1;
            } else if( sscanf(arg, "@%s", mud) == 1) {
                        // rwho option
                        if(mud == mud_nname())
                                write((string)RWHO_D->rwho_mud());
                        else
                                write((string)RWHO_D->remote_who(mud, previous_object()));
                        return 1;
                } else if( arg=="-w" ) {
                        // Added by Annihilator 09/26/94
                        wiz_only == 1;
            } else {
                        // bad option
                        notify_fail( SYNTAX );
                        return 0;
            }
        }
        list_wiz = filter_array(users(), "filter_wizards", this_object());
//      list_wiz = sort_array(list_wiz, "sort_wizards", this_object());
        list = filter_array(users()+all_inventory(netdead), "filter_users", this_object());
// sort_array costs LOTS of eval cost, commeneted out by Annihilator (05/31/95)
//      list = sort_array(list, "sort_users", this_object());
        write( "\n◎ 蓝天  \t\t\t\t( " + ctime( time() ) + " )\n");
        write(c_dvd);
        msg = "巫师 : ";
        i = sizeof(list_wiz); 
        while( i-- ) 
                msg = sprintf("%s%s, ", msg, list_wiz[i]->query("name"));
                                        
        write(iwrap(msg, 70));
        msg = "玩家 : ";
        i = sizeof(list);
        while( i-- ) 
                msg = sprintf("%s%s%s%s, ", msg, interactive(list[i]) ? "" : "*",
                                list[i]->query_temp("chat_user") ? "#" : "",
                                list[i]->query("name") );
        write(iwrap(msg, 70)+c_dvd);
        printf("目前共有 %d 位使用者连线中。",(sizeof(list_wiz)+sizeof(list)));

        printf( "\t系统负担 : %s \n\n",query_load_average());
        return 1;
}

// note this returns the list in REVERSE order - this is a speed
// optimisation, instead of doing for(i=0;i<sizeof(foo);i++)
// we can do i=sizeof(foo); while(i--)
int sort_users(object u1, object u2)
{
        // use the levels mapping for speed
        return (int)levels[u1] - (int)levels[u2];
}

int sort_wizards( object w1, object w2 )
{
    return (int)levels[w1] - (int)levels[w2];
}

int filter_users(object who)
{
        if( (int)who->query("npc") && !wizardp(this_player()) ) return 0;
        if ( !who->query("user")) return 0;
        if( wizardp(who) ) return 0;
        if( visible(who, this_player()) ) {
                // build up the levels mapping
                levels[who]=(int)who->query_level()+(int)who->query("level");
                if( !levels[who] || levels[who]==0 ) return 0;
                return 1;
        }
   return 0;
}

int filter_wizards(object who)
{
   string domain_level;
   if( !wizardp(who) ) return 0;
   if( visible(who, this_player()) ) {
     if( member_group( who->query("name"), "admin" ) )
       levels[who] = 20;
     else {
       domain_level = (string)DOMAIN_D->query_domain_level(who->query_link());
       switch( domain_level ) {
         case "archwizard" : levels[who] = 15; break;
         case "sage"       : levels[who] = 13; break;
         case "adept"      : levels[who] = 11; break;
         case "wizard"     : levels[who] = 9; break;
         case "apprentice" : levels[who] = 7; break;
         default : levels[who] = 0; break;
       }
     }
//     if( !levels[who] || levels[who]==0 ) return 0;
     return 1;
   }
}

// used by linkdead option
int deadp(object who)
{
    if(!geteuid(who))
                return 0;
    return (int)who->query_linkdead();
}
 
int help()
{
        write ( @HELP
使用格式: who <-l或-d>

列出当前在线的玩家与巫师.
加入-l参数可列出更详细的资料，加入-d可列出已经断线的玩家.
HELP
        );
        return 1 ;
}
 
/* EOF */
