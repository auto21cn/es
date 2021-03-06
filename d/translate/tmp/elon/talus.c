/* Wed  07-20-94 fixed.
special attack done: Sun  07-24-94
need clue...
*/
 
#include <mudlib.h>
/*#include <maze.c>*/
 
inherit MONSTER;
int sleep,clue,figure, power;
/* power=10 normal attack, little special attack.
         25 ok.. some special attack (used for shaking him up..)
         75 fierce attack.. if player k him while he's sleeping..
*/
 
void reset();
 
void create()
{
        ::create();
        set_level(4);
        set_name( "talus", "塔洛斯" );
add("id",({"traveller"}));
        set_short( "@@short", "@@c_short" );
        set_long( "@@long", "@@c_long" );
        set( "race", "elf" );
        set( "gender", "male" );
        set( "alignment", 200 );
        set( "max_hp",100);
        set("hit_points",100);
        set_perm_stat("int",5);
        set_perm_stat("pie",10);
        set_perm_stat("dex",5);
        set_skill("dodge",50);
        set("wealth/silver",1);
        set_natural_weapon(10,2,10);
        set_natural_armor(10,1);
        set("weight",650);
        set("inquiry",([
        "gital": "@@ask_gital",
        "clue" : "@@ask_clue",
        "help" : "@@help_me",
        ]) );
        set("tactic_func","psionic");
        reset();
}
 
void reset()
{
/*    ::reset();*/
    sleep=1;
    clue=0;
    figure=1;
    power=10;
    write(can_read_chinese()?
    "塔洛斯伸个懒腰, 看看四周, \"没事了? 那我睡了.\"\n":
    "Talus looks around, yawning, \"Nothing else? Then I will sleep.\"\n");
    return;
}
 
int psionic()
{
    object victim;
    int chance, damage;
victim=query("last_attacker");
    if (!victim) {
        return 0;
    }
/* calculating chance of having special attack */
    chance=random(100)+1;
    if (chance<=power) { /* special attack */
        damage=random(power/5)+10;
/* pattern 1, psionic attack */
        if (random(1)+1) {
        write(can_read_chinese(victim)?
        "忽然, 你发现自己身在一个火山口旁, 滚烫的岩浆在你四周翻滚著.\n"+
        "塔洛斯的声音在你脑海中响起: 哈哈哈哈哈... 你的死期到了.\n"+
        "只见一股溶岩打在你身上. 你想要闪躲, 却发现自己无法动弹.\n":
        "Suddenly, your surrounding changes: you are standing besides\n"+
        "a volcano, lava stirs around you. Talus speaks inside your mind:\n"+
        "Die! Die! Die!. You see lava moves towards you, and trying to\n"+
        "run away from it, but found you are unable to move.\n");
tell_room(environment(this_object()),({
        "你看见"+(string)victim->query("c_name")+"呆呆的站著, 似忽被什麽"+
        "力量控制住了.\n",
        "You see "+(string)victim->query("cap_name")+" stands there idly."+
        " Seems to be distracted by something.\n" }),
        ({this_object(),victim}));
        victim->receive_damage(damage);
        return 1;
        }
/* pattern 2, the invisible air blade */
        else {
        tell_room(environment(this_object()),({
        "塔洛斯高举双手, 只见四周的空气迅速地流动.\n",
        "Talus raises his hands, you see the air around him moved rapidly.\n"
        }), this_object());
        write(can_read_chinese(victim)?
        "一把无形的刀狠狠地砍在你身上, 你痛苦地往後退.\n":
        "An invisible blade hacks you hard, you jerk and move backward.\n");
        tell_room(environment(this_object()),({
        (string)victim->query("c_name")+"好像被什麽东西砍到似的, 很痛苦地"+
        "往後退.\n",
        "You see "+(string)victim->query("cap_name")+" jerks backward in"+
" great pain, seems to be hitted by something.\n"}),({this_object(),victim}));
        victim->receive_damage(damage);
        return 1;
        }
    }
    return 0;
}
 
void ask_gital()
{
    if (sleep) {
        write(can_read_chinese()?
        "他在睡觉!\n":"He is sleeping.\n");
        return;
    }
    tell_room(environment(),({
        "Talus said: Gital? I am here because I want to get him out.\n"+
        "Talus sighs deeply.\n"+
        "But that evil mage is too powerful and sneaky, he said finally.\n",
        "塔洛斯说: Gital? 我之所以留在这里就是要想办法把他弄出来.\n"+
        "          谁晓得那魔女太厉害了....\n"+
        "塔洛斯重重的叹了一口气.\n"
        }), this_object());
        return;
}
 
void ask_clue()
{
    if (sleep) {
        write(can_read_chinese()?
        "他在睡觉!\n":"He is sleeping.\n");
        return;
    }
    tell_room(environment(),({
    "Talus shrugs, then said: sure, you can try to open the gate.\n"+
    "                         just follow the colors of the rainbow.\n",
    "塔洛斯耸耸肩, 说道: 也好, 你试试吧. 开门法其实很简单, 照著彩虹\n"+
    "                     的颜色准没错.\n"
        }),this_object());
    clue=1;
        return;
}
 
void help_me(object who)
{
    if (sleep) {
        write(can_read_chinese()?
        "他在睡觉!\n":"He is sleeping.\n");
        return;
    }
    if (!clue) {
        tell_room(environment(),({
    "Talus said: why should I help you? Who do you think you are?\n",
    "塔洛斯莫名奇妙的看著你说道: 我帮你干嘛?\n",
    }), this_object());
    return;
    }
    if (clue && figure) {
    tell_room(environment(),({
    "Talus sighs, \"Help you? I have a hard time to even help myself.\n"+
    "              but anyhow, here is a figure, maybe it will be of\n"+
    "              use to you. The name of the creature is Tio.\n",
    "塔洛斯叹息道: 帮你? 我都自身难保了. 这样吧, 我这有一个小雕像.\n"+
    "              你带著, 说不定有用. 它的名字叫 Tio.\n",
        }),this_object());
/*code to give the ppl who asked this question a figure*/
    figure=0;
        return;
    }
    else {
    tell_room(environment(), ({
    "Talus shakes his head helplessly and said, I wish I could help.\n"+
    "   but there is nothing I can do now.\n",
    "塔洛斯摇摇头道: 我也很想帮你, 可是我实在是无能为力了.\n",
    }),this_object());
    return;
    }
}
 
void init()
{
    ::init();
    add_action("shake_me","shake");
    add_action("wake_me","wake");
}
 
int wake_me(string str)
{
    if (!str || str=="") {
        write(can_read_chinese()?
        "叫醒谁?\n":"Wake who?\n");
        return 1;
    }
/* this part is really dumb... but heck.. if they killed him... */
    if (str!="talus") {
        write(can_read_chinese()?
        "你要叫醒的人不在这里.\n":
        "The one you want to wake up is not here.\n");
        return 1;
    }
    if (!sleep) {
        write(can_read_chinese()?
        "塔洛斯很不耐烦地说: 我早就醒了, 你有事快讲吧!\n":
        "Talus shouted to you: I am already awake! stat your business!\n");
        return 1;
    }
    write(can_read_chinese()?
    "你摇摇塔洛斯, 只见他伸个懒腰坐了起来, 说道: 你找我?\n":
    "You shaked Talus slightly. He awakes and sits up.\n"+
    "Then he looks at you, \"Looking for me?\"\n");
    tell_room(environment(),({
    (string)this_player()->query("name")+" wakes Talus up.\n",
    (string)this_player()->query("c_name")+"把塔洛斯叫醒.\n"
    }), ({this_object(),this_player()}));
    sleep=0;
    return 1;
}
 
 
 
string short()
{
    if (sleep) {
        return "A sleeping traveller.";
    }
    return "Talus the adventurer.";
}
 
string c_short()
{
    if (sleep) {
        return "沉睡中的旅者.";
    }
    return "冒险家塔洛斯.";
}
 
string long()
{
    if (sleep) {
        return
"You see a well seasoned traveller sleeping in the corner. He\n"+
"looked so tired and skinny. Looks like he\'s been staying here\n"+
"for quiet some time.\n"; }
    return
"A tired adventurer. From his appearence you know he\'s been\n"+
"through a lot.\n";
}
 
string c_long()
{
    if (sleep) {
        return
"You see a well seasoned traveller sleeping in the corner. He\n"+
"looked so tired and skinny. Looks like he\'s been staying here\n"+
"for quiet some time.\n"; }
    return
"A tired adventurer. From his appearence you know he\'s been\n"+
"through a lot.\n";
}
 
int kill_ob(object victim)
{
    write(can_read_chinese()?
    "塔洛斯从睡梦中惊醒, 大叫, 哇勒, 敢趁我睡著时打我, 你完了!\n":
    "Talus jumps up, and yells, Go to HELL you jerk, dare you\n"+
    "attack me during my sleep!\n");
    sleep=0;
    power=75;
    ::kill_ob(this_player());
    return 1;
}
 
int shake_me(string str)
{
    if (!str || str=="") {
        return 0;
    }
    if (str!="talus") {
        return 0;
    }
    if (!sleep) {
        write(can_read_chinese()?
        "喂... 摇啥啦.. 我早就醒了! 塔洛斯不耐烦的说道.\n":
        "Talus shouted to you: I am already awake! Stop shaking me!\n");
        return 1;
    }
    write(can_read_chinese()?
    "你很用力的把塔洛斯摇醒, 他一脸不爽的看著你.\n":
    "Talus stares at you as you shakes him up violently.\n");
    tell_room(environment(),({
    "Talus awakes and stares at "+(string)this_player()->query("cap_name")+
    " angrily.\n",
    (string)this_player()->query("c_name")+" 用力的把塔洛斯摇醒, 只见塔洛斯一脸不爽的瞪著他.\n"
    }), ({this_object(),this_player()}) );
    tell_room(environment(), ({
    "Talus said coldly, \"stat your business and be gone.\"\n",
    "塔洛斯冷冷的说道, \"你叫醒我道底要干嘛?\"\n"
    }), this_object());
    power=25;
    return 1;
}
 
