#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Fat Tung","肥东");
    add("id",({"fat","tung","cooker"}) );
    set_short("肥东");
	set_long(@C_LONG
    你看到一个超级大胖子，胖的似乎连走出厨房门都有困难，他就是梁山泊的厨子
，名叫肥东，据山贼们的说法，肥东煮的菜又少又难以下□，所以当山贼们有钱时，
宁可去孙二娘的酒店中花钱吃饭，而免费的伙食都没人要吃。肥东现在正在作今天的
饭。不要因他淳朴的外表而以为他好欺负，听说他少年时曾在少林学艺。 
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "lizardman");
    set( "unit", "位" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("unarmed",70);
    set_skill("block",100);
    set_skill("dodge",100);	
    set ("max_fp",800);
    set ("max_hp",1000);
    set ("force_points",800);
    set ("hit_points",1000);
    set_natural_weapon(35,20,40);
	set_natural_armor(80,40);
	set ("aim_difficulty",([ "gangolion":60,"vascular":100]) );
	set("special_defense", (["all":50,"none":20]) );
    set("attack_skill","monk/fist/tb_fist");
    set("gonfus/ho_fist",80);
    set ("weight", 800);
    set("inquiry",([
        "trouble" : "@@ask_trouble",
        "diet" : "@@ask_diet",        
        "skill" : "@@ask_skill"
        ]));
    equip_armor(TARMOR"cook_hat");
    equip_armor(TARMOR"cook_cloth");
    equip_armor(TARMOR"pot");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name !="cook note" && name != "diet_tea" ) ) return 1;
	if (name == "cook note") {
     if ((int)this_player()->query_temp("fat_quest/skill")<1) {
     tell_object(me,
@ANSWER1
肥东接过这本笔记，看也不看，就把它当柴火烧掉了....
ANSWER1
);     
     item->remove();
     return 1;
}     
     if ((int)this_player()->query_temp("fat_quest/skill")==1) {
     tell_object(me,
@ANSWER2
肥东接过这本笔记，翻了一下，说道: 这些我都会了，你能不能再帮我问问别人??
ANSWER2
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if ((int)this_player()->query_temp("fat_quest/skill")==2) {     
     tell_object(me,
@ANSWER3
肥东接过这本笔记，翻了一下，说道: 你是从那找到这麽多资料的? 有了这些，我一
定能做出更好吃的鱼料理。真是太感谢你了!!
ANSWER3
	);
        this_player()->set_temp("fat_quest/skill",3);
        item->remove();
if ((int)this_player()->query_temp("fat_quest/diet")<4) {
write("肥东说道: 对了，你不是要帮我减肥吗? 现在进度如何??\n");
        return 1;
}
else { 
        write("你完成了肥东任务，得到了7000点经验值\n");                
        this_player()->gain_experience(7000);
        return 1;
}}}
     if (name == "diet_tea")
{     
if ((int)this_player()->query_temp("fat_quest/diet")<3) {
     tell_object(me,
@DIET1
肥东接过这杯茶，问道: 你干嘛对我这麽好??说完把茶倒到流理台
DIET
	);
        item->remove();	
	return 1;
}
else {
     tell_object(me,
@DIET2
肥东问道: 这就是减肥茶吗? 而後将它一饮而尽     
DIET2
);
command("drink diet_tea");
    item->remove();
    this_player()->set_temp("fat_quest/diet",4);
    if ((int)this_player()->query_temp("fat_quest/skill")<3) {
    write("肥东问道: 对了，你有办法使我做出更好的鱼料理吗??\n");
    return 1;
    }
    else { write("你完成了肥东任务，得到7000点经验值\n");
    this_player()->gain_experience(7000);    
    return 1;
}}}}
void ask_skill()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3) {
write(
"肥东摇头说道: 想要学煮饭吗? 看你只配学泡面......\n");
}
else {
write(
"我是跟一个流浪的半身人厨师学做菜的，他做的料理不但美味，还能撼动人心。\n"
"可惜当时时间有限，我只学到了肉类的料理法而已，真是可惜，後来他去诺达尼\n"
"亚大陆旅行，我就跟他失去联络了，一转眼已经十多年啦....唉........\n");
return 1;
}}
void ask_diet()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<3)
write(
"肥东说道: 我是想减肥呀，可是得先解决目前的问题吧?\n");
else {
write(
"你一五一十的把张顺的话告诉了肥东，肥东听完後默然无语，好像很难过的样子。\n"
"你於心不忍，决定再帮他一个忙，设法帮助他恢复苗条的身材.......\n");
return 1;
}}
void ask_trouble()
{
if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")==0) 
write(
"肥东说道: 你是谁啊? 干嘛来这里问东问西的?\n");
else { 
write(
"肥东感激的说道: 好吧，让我来告诉你我的困难。事情是这样的: \n"
"十年前，梁山泊刚成立的时候，我加入了他们的行列。当时的大头目宋江成立了一\n"
"个大众的食堂，使大家能有免费的伙食，经费由山寨补助，由我当负责人。\n"
"这麽多年来，也经历了不少事情，例如孙二娘的饭馆开张，抢走我不少生意，但是\n"
"我的公营饭店仍然得继续经营下去。\n\n");
call_out("ask_trouble2",10,this_player());
}
return 1;
} 
int ask_trouble2()
{
write(
"肥东又深深的叹了一口气，继续说道: \n"
"但是长久以来，我都用後山猎得的野兽来作料理，用了快十年了，後山的野兽几乎\n"
"快被猎光了，换句话就是我找不到肉类来作菜.......唉......\n"
"弟兄们早就习惯了大口喝酒，大口吃肉的日子，所以现在他们都到孙二娘的酒店去\n"
"花钱吃饭了。不过说也奇怪，为什麽他们还找的到肉(meat)呢?\n\n");
call_out("ask_trouble3",10,this_player());
return 1;
}
int ask_trouble3()
{
write(
"我现在的问题是，要如何恢复公营饭店的生意呢? 其实我也不是很在意这\n"
"里的生意，只是看到大家都花钱去吃饭，感到对宋江老大有点过意不去，\n"
"肥东诚挚的握住你的手说道: 讲了这麽多，心里感到好多了。\n"
"你能帮我恢复饭店的生意，让大家都能免费吃到好吃的食物吗?\n");
this_player()->set_temp("fat_quest/meat",1);
return 1;
}
