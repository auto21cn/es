#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("statue","娜考璐璐雕像");
	add( "id" , ({ "statue" }) );
	set_short("statue" , "娜考璐璐雕像");
	set_long(@AAA
一个雕刻相当精美的雕像，仔细一看原来是个娜考璐璐的人像，真不愧是
一代雕刻大师橘右京刻的，人物栩栩如生，要不是因为这个雕像比真人来
得小，还真以为这是真人呢！！	
AAA
	);
   	set("unit","个");
   	set("weight", 20);
   	set("nakoruru_statue",1);
   	set("value",({ 1, "silver" }) );
}

