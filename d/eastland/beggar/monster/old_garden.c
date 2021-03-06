#include "../dony.h"

inherit MONSTER;
 
int receive_damage(int damage);
void create()
{
        object ob1;
	::create();
	set_level(19);
	set_name( "Old gardener", "老院长" );
	add( "id", ({ "old","gardener" }) );
        set_short( "祠堂 老院长" );
	set_long(@C_LONG
老院长是『新胆村』中最长寿的人, 相传他己经活了三百年之久,这得归功於他多
年研究长生不老之术。老院长平时掌管祠堂大大小小的事物, 近几天以来为了『
丐帮』祭祖大典忙得不可开交,忙归忙可是他仍然精神奕奕丝毫不输那些年轻的小
伙子喔!!
C_LONG	
	);
        set("hit_points",2000);
        set("max_hp",2000);    
        set("weight",700);
        set("wealth/gold",200);
        set_perm_stat("str",25);
        set_perm_stat("int",35);
        set_perm_stat("dex",23);
        set_perm_stat("kar",40);
        set_natural_armor(70,0);
        set_natural_weapon(31,15,25);
        set_skill("dodge",60);
        set_skill("blunt",60);
        set( "race", "human" );
	set( "gender","male");
	set( "unit", "位" );
        set_temp("be_joke",10);
        set("aim_difficulty",
           (["critical":200,"vascular":70,"ganglion":50,"weakest":60]) );
        set("stun_difficulty",90);
        
        wield_weapon(DWEAPON"broom");
        equip_armor(DARMOR"enforcer_robe");
        ob1 = new( DITEM"life_ball" );
        ob1->move( this_object() );
        set( "inquiry", ([
                   "hau":"@@ask_hau",
               "history":"@@ask_history", 
                "before":"@@ask_before", 
             "continue1":"@@ask_continue1",      
             "continue2":"@@ask_continue2",
             "continue3":"@@ask_continue3",
                   "uki":"@@ask_uki",
              "worship":"@@ask_worship"       
                    ]) );
}
void init()
{
    ::init();
    add_action("do_backstab","backstab");
}
    
void do_backstab(string str)
{
    tell_object(this_player(),"想 bs ? \n");
    this_player()->set_temp("block_command",1);
    call_out("recover1",5,this_player());
}
void recover1(object obj)
{
    obj->delete_temp("block_command");
    tell_object(obj,"请不要在这种神圣的地方干这码事。\n");
}
void ask_hau(object asker)
{
   if ( asker->query_temp("uki_asked") ) {
      tell_object( asker,
        "祠堂 老院长说道:喔,你问霍先生内人的病?\n"
        "祠堂 老院长说道:其实小雪子说的没有错啦,只是九转熊蛇丸生性属阴需要一\n"
        "                属阳的药物才能达到『阴阳和合』的境界,把效用发挥到极\n"
        "                限,以至於起死回生。\n"
        "祠堂 老院长叹道:唉,我本有多年研制的『六阳正气丹』可以和熊蛇丸配合达\n"                         
        "                到『阴阳和合』的境界,可是不知道遗失在那里.....\n\n"
        "祠堂 老院长想了一会儿......\n\n");
        asker->set_temp("old_asked",1);
        call_out("recover2",10,asker);
   } 
   else 
      tell_object( asker,
        "祠堂 老院长说道:我不清楚。\n"
      );     
}
void ask_history(object asker)
{
write(@C_LONG
老院长说道:你问『薪胆村』的历史?那可是要从很久以前说起(before)?
C_LONG
      );
}
void ask_before(object asker)
{
write(@C_LONG
老院长说道:    大约在二百八十年前,中原江湖上各大帮派林立;多馀千人的大帮会少说
           有二、三百个;小如一、两百人的小派门更是不下千个,一时风云涌起袭卷著
           武林的每一个角落。
               然而, 学过经济学的人都知道,在这块有限的土地资源之下,一旦帮派多
           了起来相对的能分配给众人的区域就少了起来。 更由於人类的恶根性---『
           深信著暴力就能够解决一切』的支使之下, 凡是有地盘之争或者彼此理念不
           同或者其它的芝麻小事都能使人大动干伐。若是单纯两派之斗还好,就是有那
           些想趁火打劫,想从中分一杯羹的, 往往引得一派的覆亡累至满门於一夜之间
           悉数消失殆尽。不过总是有人会看不惯因而从中加以调停,调停的结果虽然表
           面上能使之罢斗,但彼此总还会有或多或少的隙缝存在, 甚至有那些不甘於调
           停结果的,往往呼朋引伴其结果是引来更大的斗争。
老院长顿了一下,喝了一口茶,说道:要继续(continue1)?           
C_LONG
    );
}
void ask_continue1(object asker)
{
write(@C_LONG
老院长继续说道:  这时, 就有些属於『较大』的门派倡议大家选一个武林盟主来领导众
           人,一时颇得江湖中人的支持。但是,人人为争那一个盟主席位更是打的头破
           血流,引来的却是另一场更大的血腥。出乎意料的是,选出来的武林盟主却能
           够带来江湖上数十年的安宁, 想必是人类天生的努役性驱使吧!数十年之後,
           武学日式衰微, 江湖上再也找不到一个足以担当武林盟主之位的人,於是,干
           戈大起,引发了一场更大的浩劫。
老院长说道:对不起,口又渴了。老院长喝了一口茶。
老院长说道:要继续(continue2)?                        
C_LONG
     );
}
void ask_continue2(object asker)
{
write(@C_LONG
老院长说道:   这时正值异族入侵,朝廷正苦於无法把整个中原势力纳入统治之中,见到江
          湖上那些武人自相残杀,更是乐於旁观。但为保千秋大业,势必要把整个帮会势
          力给连根拔起。於是,朝廷计划筹谋,正当布置好了所有准备, 但恰逢选出武林
          盟主相安後的数十年,於是宣告作废。无奈数十年之後,武林又开始自斗并且给
          了朝廷一个最好的机会,朝廷也知道这个良机一踪即失,遂派遗鹰门爪牙逐一铲
          除各大帮派。出手不外乎是威胁利诱,如有顺从归顺那是最好不过,不服就连根
          给拔起,手段极其狠毒,仅仅几个月之间,各大帮派已十之去九,这时武林像一盘
          散沙,又有那一个派门能抵挡得了朝廷的攻势呢?
老院长说道:要继续(continun3)?                            
C_LONG
     );
}
void ask_continue3(object asker)
{
write(@C_LONG
老院长说到这里,面色有点惨白:   位天下第一大帮的丐帮在面临朝廷这波的攻击之下,不
          免也有些狠狈,更何况在异族还未入侵之前,丐帮处处在跟异族作对;入关之後,
          丐帮又到处滋扰生事表示不服异族统治,种种举动早已被朝廷视为眼中钉,背後
          的芒刺。最後,丐帮在与朝廷的一场重要的决战里,自八袋弟子已上,悉数阵亡,
          所幸一名七袋见得快,得以保住帮中重要的物事, 更忧於朝廷防不胜防的攻势,
          无奈只好退居到一处隐密之处,俟机复帮, 并把所在之地命名为『薪胆村』取'
          卧薪尝胆'之意。到了这里,仍然是推选一位帮主来管理一切的事务。日子飞逝
          ,渐渐地,丐帮在这里安居下来,大部份的弟子也都娶妻生子,安和乐利了一百多
          年。可是,十多年前.......
你看老院长的样子不想继续再说下去,他脸上显现遭遇到一件极悲惨的事。                    
C_LONG
    );
}
void ask_uki()
{
write(@C_LONG
老院长说道:小雪子是一个很不错的女孩子,这些年多亏有她,否则,村内的人生病真不知道
           该怎麽办?
C_LONG
    );           
}
void recover2(object obj)
{
      tell_object( obj,
        "祠堂 老院长说道:我记得在□完鸡以後就不见了,你可以去找找。\n");
}
void ask_worship()
{
write(@C_LONG
祠堂 老院长说道:你问祭祖大典喔,那是村里一年一度的盛事,帮主会招集所有的人考核过
                去一年来的功过。还有就是,如遇新旧帮主交接也是由那时完成。通常,
                在大典上都会邀请一些武林成名人士,唉, 已经在这里生活了这麽久了,
                还有需要再去管那些江湖上的事吗?
C_LONG
      );
}
int receive_damage(int damage)
{
    int hits;
    object victim,act_ob;
    string mob_name,vic_name;
    
    victim=query_attacker();
    if ( !victim ) return ::receive_damage(damage);
    mob_name=this_object()->query("c_name");
    vic_name=victim->query("c_name");
    
    act_ob = previous_object();
    if( act_ob && living(act_ob) ) set("last_attacker", act_ob);

    if ( ( victim->query("class")=="mage" ) )
       victim->set("spell_points",0);
    
    if (random(6)>2){
       tell_room( environment(this_object()),set_color(
            "吓!!"+mob_name+"运起挪移心法,把所受到的伤害悉数由"+vic_name+"接收!!\n","HIW"),victim);
       tell_object( victim, set_color(
            "吓!!"+mob_name+"运起挪移心法,把所受到的伤害悉数由你接收!!\n","HIW"));         
       hits = (int)victim->query("hit_points");
       hits -= damage;
       if( hits < 1 && wizardp(victim) && victim->query("immortal") )
          hits = (int)victim->query("max_hp");
       victim->set("hit_points",hits);
    }
    else{
       hits= (int)this_object()->query("hit_points");
       hits-=damage;           
       this_object()->set("hit_points",hits);
    }
    return 1;
}                                  
