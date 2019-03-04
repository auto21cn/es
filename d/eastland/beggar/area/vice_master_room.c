#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "vice_master_room", "副帮主之室" );
	set_long(@C_LONG
这里是全副帮主住的地方。这里没什麽贵重的摆设,房子中间放著一张大红桌
子,桌子里还有几个抽屉, 抽屉里不知道放的是什麽东西。桌子後面的墙壁上供奉
著几尊不知明的神明,神明两旁写著『风调雨顺』之类的对联, 对联上面的字歪歪
斜斜一看就知道不是出自於名家手笔。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"west9.c"
	]) );
        set( "c_item_desc", ([
                 "closet" :"一个用檀木做的抽屉。\n"
        ]) );
        set( "objects", ([
                      "unary":DMONSTER"unary.c",
                        "dog":DMONSTER"dog.c"
        ]) );              
     reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    object ob1;
    
      if ( !arg || arg != "closet" ) {
         tell_object(this_player(),"你在找什麽东西？\n");
         return 1;
      }      
      if ( this_object()->query_temp("be_searched") ) {
         tell_object(this_player(),"抽屉己经被别人找过了。\n");
         return 1;
      }
      if ( !this_player()->query_temp("gonfu_asked") ) {
         tell_object(this_player(),"你在找什麽东西?\n");     
         return 1;
      }    
      else {
         tell_object( this_player(),
            "你找到了一封白色的信件。\n");
         ob1=new(DITEM"letter");          
         ob1->set("master",this_player()->query("name"));
         ob1->move(this_player());
         this_object()->set_temp("be_searched",1);
         call_out("recover",1800,this_object());
         return 1;
      }
}
void recover(object obj)
{  
     obj->delete_temp("be_searched");
}
void reset()
{
     this_object()->delete_temp("be_searched");
     ::reset();
}
            