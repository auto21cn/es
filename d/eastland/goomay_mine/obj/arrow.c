#include <../zeus.h>

inherit OBJECT;

void create()
{
	set_name("singing arrow", "响铃箭" );
	add("id",({"arrow"}));
	set_short( "...","响铃箭" );
	set_long("..",
	"这是一只经过特殊设计的箭，尾端有著一条条的隙缝，行进时可\n"
	"发出鬼哭神号的声音，令人心胆俱碎．现在正牢牢地插在地上\n"
	);
	set("unit","只");
	set("weight", 5000 );
}