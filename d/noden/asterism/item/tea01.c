inherit "/d/noden/asterism/item/drink.c" ;

void create()
{
    ::create();
    seteuid(getuid());
    set("id", ({ "tea" , "herb tea","herbtea" }) ) ;
    set_name("herb tea","��ݲ�");
    set_short("��ݲ�");
    set_long(
    "������ǧ�ݼ��ܴ��䷽�Ƴɵ���ݲ衣ɶ��......˭��ǧ�ݣ�\n"
    "��......Ϊ�������������룬��֪���Ļ������˰�!!\n");
    set("container",0) ;
    set("tp",80);
    set("value",({ 50,"silver" }) ) ;
    set("amount",0) ;
    set("c_succ","�����һƿ��ݲ�,һ�������ĸо�������ĺ�ͷ��\n") ;
   set("c_osucc","$CN������һƿ��ݲ衣���������۵�����,�����������ɿڵ����ӡ�\n") ;
}