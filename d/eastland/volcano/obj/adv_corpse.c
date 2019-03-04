#include "../oldcat.h"

inherit "/obj/corpse";
int be_cut;

void create()
{
    ::create();
    ::set_name("advanturer","冒险者");
    set_c_open_long("这是冒险者的遗体，你可以割(cut)下他的头做为战利品。\n");
    set("weight",800);
    set("load",1000);
    be_cut=0;
}

void init()
{
  add_action("cut_head","cut");
}

int cut_head(string arg)
{
   int i;
   object wep,obj,*item;

   if (!arg || arg!="head")
      return notify_fail("你要割啥?\n");

   if (be_cut)
      return notify_fail(
         "这个冒险者的头已经被割走了。\n");
   item=all_inventory(this_player());
   for (i=0;i<sizeof(item);i++)
     if ((string)item[i]->query("name")=="sharp knife") {
       write("你用你手中的锐利小刀把冒险者的头从□体上割了下来。\n");
       obj=new(OOBJ"head");
       obj->move(this_player());
       be_cut=1;
       return 1;
     }
   write("你没有适当的工具可以把头割下来。\n");
   return 1;
}
