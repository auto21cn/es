#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid( getuid() );
        set_name("news plaque", "������");
        set_short("������");
        add( "id", ({"news","plaque",}) );
        set( "long", "@@query_long" );
        set( "unit", "��" );
        set( "weight", 10000 );
        set( "prevent_get", 1);
}

string query_long()
{
   write( "�����������¹��棺\n" );
   cat( "/adm/news/c_motd" );
   write( @MORE
����BUG ��ֱ�ӱ������ʦ�ߣ���ǰ��ð���߹�������ұ���֮����
�������ο�STATUE����֮���ϣ�ֱ����ϵ������֮��ʦ���������ܵ�
��������Ĵ𸲡�

MORE
   );
   return "����ֱ��POST�BUG ����������ʦ����ἰ�紦�������⡣\n";
}