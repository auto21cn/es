
// Deathland/ruin1/ruin35.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遗迹");
     set_long(@Long
Long
,@CLong
在这里你发现这个地方是一个平常人所居住的房子 ,这里与遗迹其它的地方完
全不同 .明显地有著人类居住在这里 .由这里的\摆\设你能了解到这个地方的主人一
定相当的有学问 ,因为这个地方几乎快要被书给淹没了 .
CLong
);
     set("item_func",([
          "books":"look_books",
          "book":"look_book",
          ]) );
     set("search_desc",([
          "floor":"@@search_floor"
          ]) );
     set("objects",([
         "ranger":Deathland"/monster/ranger",
         ]) );
     set("exits",([
         "south":Deathland"/ruin1/ruin34",
         ]) );
     ::reset();
}

int look_books()
{
    write(can_read_chinese()?
          "一座书山 ,\或\许\你能找出一些有用的知识 ,但是如何从这些书中发现\n"
          "你想要的呢 ?\n":
          "NEEd to work");
    return 1;    
}

int look_book()
{
    write(can_read_chinese()?
          "你想要看那一本书呢 ?\n":
          "Which book do you want to look ?\n"
         );
    return 1;      
}

string search_floor()
{
     object *items,who;
     int i;
     
     who=this_player();  
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if ( items[i]->query("quest_action/pepper_find") ) {
          items[i]->set("quest_item/summon_pepper",1);
          return "你搜寻地板时, 发现了一瓶胡椒粉.\n";
          } 
     return "地板似乎有点奇怪, 但你无法确定.\n";
}
