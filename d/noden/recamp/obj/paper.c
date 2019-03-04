#include <mudlib.h>
inherit OBJECT;

int inked;

string query_c_long()
{
   if ( inked )
     return  "这张画布上面拓印了古壁上奇怪的文字，应该去找个会解读的人看看吧!!\n" ;
   else
     return  "这张画布似乎可以用来写字、画画或拓印(squeeze)东西。\n" ;
}

void create()
{
	set_name("paper", "画布");
	add( "id", ({ "paper" }) );
	set_short( "画布" );
	set("long","@@query_c_long");
	set( "weight", 1 );
	inked = 0;
}

int query_inked() { return inked; }

void init()
{
	add_action( "squeeze_wall", "squeeze" );
}

int squeeze_wall(string str)
{
        object obj1, obj2;
        if ( !str || str=="" || str !="wall" )
          write("你找不到适当的东西!!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply_wall")==1) { 
              write("你将纸置於石壁上，并顺利地将壁上古文拓印下来!!\n");
              inked = 1 ; 
            }
            else
              write("请用用大脑吧！这里没有办法拓印！\n");
          }
        }
        return 1;
}
