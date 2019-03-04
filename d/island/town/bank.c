#include "../island.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("������");
	set_long( @C_LONG
������һ���ĸ�ʢ����Ǯׯ��ֻ��ͷ��һƬ�Ҷ��Դ���������ƺ�
��ʾ�������ϰ���λ����ϸ��ļһ����������������ֻҪ25ö��
�Ҿ��ܽ�Ǯ����Ǯׯ�У�Ҫ�����Ѿ��л�ͷ�ˣ�Ҳ�������������Ǯ
ׯ����˴���Ҳ�ṩǮ�ҵĶһ����񣬵�Ȼ����������Զһ����ϵ�
Ǯ�ҡ�ǽ�ϻ�����һ������(help_list)�����Կ�����
C_LONG
	);
	set("item_desc",(["help_list":@LONG
�� ר�Ÿ�������ָ��Ŀ��� ��

   (1) ���ʻ���
        �� ��ȷ�����ȷ�ж�ʮ����ң�һ��Ҫ���ࡣ� û��Ҫ�Ȼ���
        �� �������� open account �������Ϳ����ˣ��򵥰�....:P
        �� ������Щɢ�εİ��������ˣ�ֻҪ�� open account һ�ξͿ����ˣ�
        
   (2) ������
        �� ����� deposit ����֣���ʽ�ǣ� deposit [����] [Ǯ������] ��
        �� ����� withdraw �Ϳ��ԣ���ʽ�ǣ� withdraw [����] [Ǯ������] ��
        
   (3) ���ң�
        �� ֻҪ�� convert ���Ǿͻ���㻻Ǯ���� ��ʽ������ ��
           �� convert [����] [Ǯ������] to [�µ�Ǯ������] ��
           �� convert [Ǯ������] to [�µ�Ǯ������] ��
        �� ���ܴ󹫿�����Ӣ�Ĳ��õĿ���ߣ�
           ES Ǯ�������б� ��
              �� �׽�� �� platinum  (��Ҳ����ȥ��ĳ��ԭ�ӱ��ϵ� mark)
              �� ��  �� �� gold
              �� ��  �� �� silver        
              �� ͭ  �� �� copper    (��Ǯ����ͭ�ң������Ƚ϶�...:P)
LONG
        ]));
	set( "light", 1 );
	set( "exits", ([ 
		"south" : ITOWN"town04" ]) );
	set("objects",([
	        "taxman" : IMON"taxman" ]) );	
	reset();
}

void init()
{
	bank::init();
	exchange::init();
}