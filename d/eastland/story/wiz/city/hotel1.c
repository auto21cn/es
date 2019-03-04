#include "../../story.h"

inherit ROOM;
int number=0;
void create()
{
	::create();
        set_short("旅馆");
	set("long",@LONG
此处是「巫咸城」里唯一的一家旅馆，你可以在这里休息过夜。尤其是每当受伤风
寒，除了需要妥善包扎以外，睡上一觉不但伤口易於痊愈，一觉起来更是精神饱满！这
里的价钱相当公道，不二价，全写在墙壁上一张黄色纸(paper)上。	
LONG
	);
	set("light", 1);
	set("exits", ([ 
            "west" : SCITY"ww"
        ]) );
        set("c_item_desc", ([
           "paper" :" 斗大的字上面写著：过夜(sleep)一次 500 金币。\n"
        ]) );
        set("objects", ([
           "boss" : SWMOB"boss1"
        ]) );
	reset();
}

void init()
{
     add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
     object player;
     string name;
     if ( number > 5 ) {
        write("这位客倌真对不起，本店已经客满了，下次请早。谢谢。\n"); 
        return 1;
     }
     player = this_player();
     name=player->query("c_name");
     if ( !player->debit("gold", 500) ) {
         write("这位客倌真对不起，您身上所带的钱不够。\n");
         return 1;
     }
     number++;
     write(@LONG

旅馆老板大喊道：小二，快带这位客倌休息去。


於是，店小二急急忙忙地引你到二楼，准备休息去...

LONG 
     );
     tell_room(this_object(),sprintf(
         "%s看起来很疲倦地随著店小二上二楼休息去。\n",player->query("c_name")),player);
     player->move_player(SCITY"hotel2","SNEAK");
     player->set_temp("block_command", 1);
     call_out("result", 6,player, 0 ,this_object());
     return 1;
}

void result(object me, int count, object place)
{
     int sp,fp,med,max_fp,max_sp;
     if( !me ) return 0;
     if( count < 10 ) {
     tell_object(me, "Z z Ｚ ｚ Z z\n");
         if ( me->query("max_fp") ) me->add("force_points",5);
         if ( me->query("max_sp") ) me->add("spell_points",7);
         me->set_temp("block_command",1);
         me->add("medication_resistance",-15);
         me->receive_healing(25);
         call_out( "result",6,me,count+1,place);
         return ;
     }
     med=me->query("medication_resistance");
     fp=me->query("force_points");
     sp=me->query("spell_points");
     max_fp=me->query("max_fp");
     max_sp=me->query("max_sp");
     if ( med<0 ) me->set("medication_resistance",0);
     if ( fp>max_fp ) me->set("force_points",max_fp);
     if ( sp>max_sp ) me->set("spell_points",max_sp);
     me->move_player(SCITY"hotel1","SNEAK");
     me->delete_temp("block_command");
     tell_object(me,
	"你伸个懒腰,看看时间,嗯,休息够了也该上路了。\n");
     tell_room(place,sprintf(
	"%s从楼上走了下来,精神好极了。\n",me->query("c_name")),me);
     return ;
}
void reset()
{
   number=0;   
   ::reset();
}