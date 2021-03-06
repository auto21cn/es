// IRC Post Office Room.. Elon@Eastern.Stories    Sat  08-20-94
// This is almost identical to the post office at Farwind.
 
#include <config.h>
#include <mailer.h>
#include "irc.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        seteuid(getuid()) ;
        set_short( "The post office", "邮局");
        set_long( @LONG
This is the IRC post office. Here you can send mails to anyone on
the mud or read your own mails.
The news bulletin is posted on the wall.
 
LONG
, @C_LONG
这里是 ES IRC 世界的邮局, 你可以在这里写信给其他玩家, 或\阅\读你自己
的信件。
墙壁上有一个公布栏 (bulletin).

C_LONG
        );
        set("light",1) ;
        set("exits", ([ "east" : RM+"lobby" ]) ) ;
        set("pre_exit_func", ([ "east" : "dest_mailer" ]) ) ;
}
 
void init()
{
        add_action("mail", "mail") ;
        add_action("help", "help");
        add_action("read_bulletin", "read") ;
}
 
int mail(string arg)
{
   object ob;
 
   seteuid("TEMP");
 
   ob = new(MAILER);
   ob->move(this_player());
   ob->start_mail(arg);
   return 1;
}
 
int help(string str)
{
    if (str == "mail") {
        this_player()->more(MAILER_LONG);
        return 1;
    } else return 0;
}
 
int read_bulletin (string str)
{
        if (!str && str!="bulletin") return 0 ;
        if (can_read_chinese()) {
            cat(RM+"c_post.news");
            return 1;
        }
        else {
            cat(RM+"post.news");
            return 1;
        }
}
 
int dest_mailer()
{
        object ob ;
 
        ob = present("mailer",this_player());
        if (ob) ob->remove() ;
        return 0 ;
}
