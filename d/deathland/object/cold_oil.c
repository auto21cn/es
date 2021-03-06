

#include "../echobomber.h"

inherit OBJECT;

void create()
{
    set_name("Cold oil","冷冻油");
    add("id",({"oil",}));
    set_short("a cold oil","冷冻油");
    set_long("a cold oil, you can apply it.\n",
             "冷冻油,你可以试著把它涂(apply)在身上.\n");
    set("weight",1);
    set("no_sale",1);
    set("value",({ 1,"copper"}) );
    set("applied",0);
}

void init()
{
     add_action("to_apply","apply");
}

int to_apply(string str)
{
    
    if (!id(str)) return 0;
    
    set("applied",1);
    set("prevent_drop",1);
    set("extra_look","$N seems apply some special thing");
    set("c_extra_look","$N身上似乎涂著一种冷冷的东西.\n");
    set("invisible",1);
    write("你把油涂到身上.\n"); 
    return 1;
}
