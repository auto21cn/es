#include <mudlib.h>
//#define YUU_DROP "/u/m/mate/yuu_drop"

inherit MONSTER;

void create()
{
  ::create();
  // seteuid(getuid());
  set_level(19);
  set_name( "yuu", "�͹��Ϻ���" );
  set_short( "�͹��Ϻ���" );
  set_long(
    "����������ǰ���ǹ�\�·�����Ա--�͹��Ϻ��У��Դ���������͹�Ĵ�ͷ��\n"
    "�ѹ�\�·���ɨ��һ����Ⱦ����˵��������������ɽ���±��ǳ��Ϻ��з���\n"
    "ʱ����Ȼ�����������ң��Ѿ�����һ�ְ��������´�����Ĳ��ɣ�������\n"
    "��ñ�����������⡣����ޱ�������Ҷ���������������Ҷ���������\n"
    "���֣�������Ҫ���и���\n"
    "    �㿴�����Ϲ��������ģ�Ҳ��\�����������æ(help)�õ㶫����\n"
  );

//  equip_armor ( "/u/m/mate/item/gloves.c" ); 
  set( "gender", "male" );
  set( "race", "dwarf" );
  set( "unit", "λ" );
  set ( "no_attack", 1 );
	modify_stat("str",1000);
  set ("chat_chance", 1);
  set ("chat_output", ({
       "�Ϻ���˵: ��ӭ���ٹ�\�·���\n",
       "�Ϻ���˵: ��˵���ڴ��������˱��봳��ʮ��ͭ����\n",
       "�Ϻ���˵: ��֪����Ħ��ʦ��?\n",
       "�Ϻ���˵: ����֮����֮��\n",
       "�Ϻ���˵: ���λ�����ιۡ�\n",
       "�Ϻ���˵: �����˺ú��, ����, ����\Ŷ\n",
       "�Ϻ���˵: ����˼���ɣ�������.....�ӵ��ΰ�....\n",
       "�Ϻ���˵: �úòι۾ͺã���Ҫ̫����Ŷ��\n",
       "�Ϻ���˵: ���ܲ��ܰ��Ҵ�ɨһ����书\�·�?\n",
       "�Ϻ���˵: �Һò����ײŴ�ɨǬ���ģ��������ֶ�������\n",
       "�Ϻ���˵: �Һò����ײŴ�ɨǬ���ģ��������ֶ�������\n"
  }) ); 
}

void init()
{
  add_action ( "do_ask",  "ask"  );
  add_action ( "do_give", "give" );
  add_action ( "do_drop", "drop" );
}

int do_drop ()
{
  write ( "�Ϻ���˵��: ʦ�ܣ��ڱ���\�·��������Ҷ�����!!\n" );
  return 1;
}

int weapon_armor ( object ob )
{
  if ( ob->query ( "armor_class" ) || ob->query ( "weapon_class" ) )
    return 1;
  return 0;
}

int do_give ( string arg )
{
  object yuu, me;
  object here;
  object ob, *ao;
  string name, what;
  object *usr;
  int    order, i, m, n;

  me = this_player();
  yuu = this_object();
  name = me->query ( "name" );
  here = environment (me);

  if ( !arg ) return 0;
  if ( sscanf ( arg, "%s %d", what, order ) == 2 ) {
    ao = all_inventory (me);
    n = sizeof (ao);
    m = i = 0;
    ob = ao[0];
    while ( i < n && m < order ) {
      if ( ao[i]->id (what) ) { m++; ob = ao[i]; }
      i++;
    }
    i--;
    if ( m == order ) {
      n = 0;
      if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) &&
           weapon_armor ( ob ) ) {
        ob->move ( yuu );
        ob->delete("value");
        n = 1;
      }
    }
  }
  else if ( arg == "all" ) {
    n = 0;
    ao = all_inventory (me);
    for (i=0; i<sizeof (ao); i++) {
      ob = ao[i];
      if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) && 
           weapon_armor ( ob ) ) {
        ob->move ( yuu );
        ob->delete("value");
        n++;
      }
    }
  }
  else if ( ob = present ( arg, me ) ) {
    n = 0;
    if ( !ob->query ( "secure" ) && !ob->query ( "prevent_drop" ) &&
         weapon_armor ( ob ) ) {
      ob->move ( yuu );
      ob->delete("value");
      n = 1;
    }
  }

  if ( n > 0 ) {
/*
    usr = users();

    for (i=0; i<sizeof(usr); i++)
      if ( (string)usr[i]->query ( "class" ) == "monk" )
        tell_object ( usr[i],
          "[���ֺ���] �Ϻ���(yuu): ��л"+name+"Ϊ�����ṩӦ"+n+"������!!!\n" );
*/
    tell_room ( here, "�Ϻ���˵��: ���лл"+name+"Ϊ��ⷶ��ṩ������!!\n" );
  }
  else if ( ob )
    write ( "�Ϻ���˵��: ʦ�ܰ�!!���ֲ�������Ͳ��"+
            "���ֶ�������Ů�������������!!\n" );
  else
    write ( "�Ϻ���˵��: ʦ�ܰ�!!��������������!!\n" );

  return 1;
}

int ask_help ()
{
  tell_object( this_player(), 
    "�������������װ������������æ��װ����\n"
    "���Ϻ�������Щ����    : ask yuu about eqs\n"
    "���Ϻ��ж�����������  : ask yuu about drop <����>\n"
    "���Ϻ��ж�����������  : ask yuu about drop <װ������>\n"
    "���Ϻ��м������ж���  : ask yuu about get\n"
    "�������ϵĶ������Ϻ���: give <����>\n"
    "�밴 ask yuu about types �鿴����Ҫ���Ϻ��а�æ������\n\n"
  );
  return 1;
}

int ask_types ()
{
  tell_object ( this_player(),
"\nͷ��	����	�ۻ�	����	�ּ�	Ь��	��	����	������	��ָ\n" +
"head	body	arms	hands	legs	feet	shield	cloak	amulet	finger\n" +
"\n" +
"\n" +
"����	��	����	β��	����		���\n" +
"kernel	globe	saddle	tail	longblade	blunt\n\n"
  );
  return 1;
}

int ask_drop ( string s )
{
  object *ao;
  object ob;
  object here, me, yuu;
  object *usr;
  string name;
  int   i, n, m;

  if ( !s ) {
    write ( "�Ϻ���˵��: ʦ�ܵ���Ҫ������ʲ����?!\n" );
    return 1;
  }
  else if ( s == "all" ) {
    write ( "�Ϻ���˵��: ʦ�ܣ�͵�������!!\n" );
    return 1;
  }
  me = this_player();
  name = (string)me->query ("c_name");
  yuu = this_object();
  here = environment (me);

  tell_room ( here, "�Ϻ���˵��: "+name+"Ҫ���İ�æ? ����������....\n" );

  ao = all_inventory (yuu);
  n = sizeof (ao);
  m = 0;

  for (i=0; i<n; i++) {
    ob = ao[i];
    if ( (string)ob->query ("type") == s ) {
      if (command ( "drop " + ob->query ( "name" ) ))
        m++;
    }
    else if (command ( "drop " + s ) )
        m++;
  }
  if ( m == 0 ) {
    tell_room ( here,
      "�Ϻ���˵��: ��ǸŶ��"+name+"������ʵ���ǰ�Ī������\n" );
  }
  else
    tell_room ( here,
      "�Ϻ���˵��: ������ע�⣬"+name+"Ҫ���Ķ���"+m+"������!!!\n" );
/*
  else {
    usr = users();

    for (i=0; i<sizeof(usr); i++)
      if ( (string)usr[i]->query ( "class" ) == "monk" )
        tell_object ( usr[i],
          "[���ֺ���] �Ϻ���(yuu): ������ע�⣬"+name+
          "Ҫ���Ķ���"+m+"������!!!\n" );
  }
*/
  return 1;
}

int ask_get ( )
{
  object *ao;
  object ob;
  object here, me, yuu;
  int   i, n, m;

  me = this_player();
  yuu = this_object();
  here = environment (me);

  tell_room ( here, "�Ϻ���˵��: �ܺã��������Ҷ������Ǻ�ϰ��....\n" );
  command ( "get all" );
  tell_room ( here, "�Ϻ���˵��: �����ܼ�Ķ����ˡ�\n" );
  return 1;
}
int ask_eqs(object me)
{
	object *inv;
	string msg, color ;
	int i;
	inv = all_inventory(this_object());
	if ( sizeof(inv) ) {
		msg = "�Ϻ��а������ղظ��㿴�������ϴ��� : \n" ;
		for ( i = 0 ; i < sizeof(inv) ; i ++ ) {
			if ( inv[i]->query("weapon_class") )
				color = "HIY" ;
			else if ( inv[i]->query("armor_class") || inv[i]->query("defense_bonus"))
				color = "HIC" ;
			else
				color = "WHT" ;

			msg += set_color(sprintf("	%s(%s)\n",inv[i]->query("short"),
							capitalize(inv[i]->query("name"))),color,me) ; 
		}
	}	else {
		msg = "�Ϻ���˵�� : ���� ... �����������Ĵ�Կ� ....\n";
	}
	tell_object(me,msg);
	return 1;
}
int do_ask ( string s )
{
  string what, name;

  if ( this_player()->query("class") != "monk" ) {
     tell_object(this_player(),@MESS1
�Ϻ���˵�����ߣ����ֲ�������ɮ�ˣ���ο�������������......
MESS1 );
     return 1; }
 
  if ( !s ) {
    write ( "�Ϻ���˵��: ʦ�ܵ���Ҫ������ʲ����?!\n" );    return 1;
}
  if ( sscanf ( s, "yuu about %s", what ) == 1 ) {
  	if ( what == "eqs" ) return ask_eqs(this_player());
    if ( what == "help" ) return ask_help();
    if ( what == "type" || what == "types" ) return ask_types();
    if ( what == "get" ) return ask_get ();
  }
  if ( sscanf ( s, "yuu about %s %s", what, name ) == 2 ) {
    if ( what == "drop" ) return ask_drop ( name );
  }
  return 0;
}