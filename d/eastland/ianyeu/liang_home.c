// File: /u/m/mad/room/liang_home.c
// Generated by Roommaker Wed May  3 12:28:48 1995

#include "mad.h"

inherit DOORS;
inherit ROOM;

int cleaver = 1;

void create()
{
	::create();
   set_short( "��լ" );
	set_long( @LONG_DESCRIPTION
����һ��ƽ����Сľ�ݡ����㻷������ʱ, �������е�
������������ľ��������; ��Ȼ���ų���, ȴ��һ�����
�����ס���ſ�, ���, ��ʹ�ǰ���, ��������һƬ�ڰ�,
����\������ھ���ʲ���!
LONG_DESCRIPTION
	);

   set( "objects", ([
           "mother" : IANMOB"liang_mother",
           "girl" : IANMOB"girl" ]) );
	set( "exits", ([ 
          "east" : IAN"hamlet_path2" ]) );
   create_door( "east", "west", ([
                "keyword" : ({ "wooden door", "door" }),
                "name" : "wooden door",
                "c_name" : "ľ��",
                "c_desc" : "һ�Ⱥ���ͨ��ľ��",
                "status" : "locked",
                "lock" : "IANYEU_LIANG_HOME"
        ]) );
   set( "c_item_desc", ([
            "bed" : "һ������ͨͨ��Сľ��.\n" ]) );
   set( "search_desc", ([
            "bed" : "@@search_bed" ]) );
	reset();
}

void reset()
{
   ::reset();
   cleaver = 1;
}

string search_bed()
{
   object obj;

   if( !cleaver ) return "���������ң���û�з����κζ�����\n";

   obj = new( IANOBJ"cleaver" );

   obj->move(this_object());
   cleaver = 0;
   return "����ϸ������Сľ��, ������һ������!\n";
}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#20");
}