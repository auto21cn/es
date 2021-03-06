// Sun  07-31-94 empty bottle, can, cup... etc
// need to add followup function to handle recycle.
 
#include <mudlib.h>
#include <config.h>
 
inherit OBJECT;
 
void create()
{
    seteuid(getuid());
    set_short("@@short","@@c_short");
    set_long("@@long","@@c_long");
    set("weight",1);
    set("unit","个");
    set("recycle",10); // recycle value, coin type is copper.
    set("prevent_drop",1);
}
 
string c_short()
{
    return "空"+query("c_name");
}
 
string short()
{
    return "an empty "+query("name");
}
 
string long()
{
    return "An empty "+query("name")+"\n"+
    "You think for the sake of the environment, you should recycle it.\n";
}
 
string c_long()
{
    return "一个空"+query("c_name")+"\n"+
    "基於环保的理由, 你觉得你应该把它送到资源回收中心去.\n";
}
 
