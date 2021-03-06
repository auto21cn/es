#include <../goomay.h>
#include <stats.h>

inherit Mob_special;
int *c_length = ({ 0,4,8,16,20 });

string *c_song = ({
"燎沈香，消溽暑。鸟雀呼晴，侵晓窥檐语。 \n",
"叶上初阳乾宿雨，水面清圆，一一风荷举。 \n",
"故乡远，何日去？家住吴门，久作长安旅。 \n",
"五月鱼郎相忆否？小楫轻舟，梦入芙蓉浦。 \n",
"尊前拟把归期说，未语春容先惨咽。 \n",
"人生自是有情痴，此恨不关风与月。 \n",
"离歌且莫翻新阕，一曲能教肠寸结。 \n",
"直须看尽洛城花，始共春风容易别。 \n",
"洞庭青草、近中秋，更无一点风色。 \n",
"玉界琼田三万顷，著我扁舟一片。 \n",
"素月分辉，明河共影，表里俱澄澈。 \n",
"悠然心会，妙处难与君说。 \n",
"应念岭表经年，孤光自照，肝肺皆冰雪。 \n",
"短发萧骚襟袖冷，稳泛沧溟空阔。\n",
"尽□西江，细斟北斗，万象为宾客。\n",
"扣舷独笑，不知今夕何夕。\n",
"驿外断桥边，寂寞开无主。\n",
"已是黄昏独自愁，更著风和雨。\n",
"无意苦争春，一任群芳妒。\n",
"零落成泥碾作尘，只有香如故。\n",

});


void create()
{
	::create();
	set_level(6);
        set_name( "singing girl", "卖唱少女" );
        add( "id", ({ "girl" }) );
        set_short("卖唱少女" );
        set_long(
@LONG
她是一个三分□腆中透著十分清丽的女孩，虽然身上的衣服已经破旧了，
可是还是洗的很乾净。她抱著一把琵\琶，眼睛望著地上，在潮来潮往的人海
里，显得无限寂寞孤单。或许\你可以驻足休息一下，只要付(pay)她十块金币
，你就能在欣赏美妙歌曲的同时又帮助一个落难的少女。
LONG
        );
        set( "gender", "female" );
	set( "race", "human" );
	set_natural_weapon( 7, 6, 14 );
	set_natural_armor( 35, 12 );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 12 );
	set_skill( "dodge", 60 );
	set("defense_type","dodge");
	set( "wealth/gold", 1 );
        set_natural_weapon( 20, 6, 16 );
        set_natural_armor( 30, 10 );
        set_c_verbs(({"%s用指甲抓向%s","%s用琵\琶砸向%s","%s用脚踹向%s"}));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "卖唱少女用她的琵\琶往你的身体砸来..\n\n");
set("c_room_msg","卖唱少女的用她的琵\琶扫过");
set("c_room_msg2", "的身体，把他打得脚步踉跄 ...\n");
}

void init()
{
	::init();
	add_action( "do_fortell", "pay");
}
void sing(int i,int j)
{
 tell_room(environment(),c_song[i] ,this_object());
 i++;
if (i<j)
 call_out("sing",3,i,j);
 else
 tell_room(environment(),
   "\n琵\琶声渐渐低沈不可闻～～\n"
   "卖唱少女微微一福，低声道：多谢各位大爷 !!\n",this_object());
 return;
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age,song_no=0;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"付谁？多少钱？\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
		tell_room( environment(), 
			"卖唱少女说道: 对不起，客官 ! 我只收金币。\n" ,
			this_object() );
		return 1;
	}
if( !this_player()->debit(type, num) ) return notify_fail(
	"客官 ! 请你不要欺负一个可怜的女孩好吗？你明明没有那麽多金币 !\n");
	if( num < 10 ) {
		write(
			"卖唱少女向你□腆一笑，摇一摇头，把钱退还给你。\n");
		this_player()->credit(type, num);
		return 1;
	}
	if ( num >=10){
        tell_room( environment(),
		"卖唱少女向在场众人一福，低声道：献丑了。\n"
		"说毕，玎玎地拨了两声琵\琶，曼声唱道：\n\n",this_object());
	song_no=random(4);
	call_out("sing",2,c_length[song_no],c_length[song_no+1]);

	return 1;
	}
}

