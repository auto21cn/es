
#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("wedding flower", "新娘捧花");
	add( "id", ({ "flower" }) );
   set_short("新娘捧花");
   set_long(
	"你仔细的看著这束新娘捧花，闻到一股清香.....\n"
	"婚礼结束後，把它送给下一位想要结婚的女孩吧。\n");
	set("unit","束");
        set("no_sale",1);
        set( "weight", 10 );
   set( "value", ({ 1500, "silver" }) );
}
