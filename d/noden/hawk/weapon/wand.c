inherit WEAPON;

void create()
{
        set_name("Hell Wand","幽冥权杖");
        add("id",({"wand",}) );
        set_short("幽冥权杖");
        set_long(@C_LONG
这是黑帝斯赐给所有冥界修道士的权杖，唯有经过重重的考验才能拿到这把
法杖，因此所有的修道士都十分珍惜这把得来不易的法杖
C_LONG
        );
        set( "unit", "把" );
        set( "weapon_class", 35 );
        set("type","wand");
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 70 );
        set( "value", ({ 1370, "silver" }) );
        set( "power_on", 1);
        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "evil" );
        set( "special_damage", 40 + random(10) );
        set( "special_c_msg",@LONG
中所储存黑帝斯的魔力放射出来，魔力笼罩在所有敌人的身上，这股
极其邪恶的力量让所有的人受到无与伦比的伤害
LONG
        );
}
