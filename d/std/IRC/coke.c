// This is an example file..
// coke.c basic setup for drink.. use as little set's as possible
// Elon@Eastern.Stories Mon  08-01-94
 
inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("coke","可乐");
    set_short("Coca Cola","可口可乐");
    set_long("Gotta have a Coke!\n",
    "可口可乐, 来一瓶吧!\n");
    set("tp",50);
}
