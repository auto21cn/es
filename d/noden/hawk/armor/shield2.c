inherit ARMOR;

void create()
{
        set_name("Heaven shield","圣光盾");
        add( "id", ({ "shield" }) );
        set_short( "圣光盾") ;
        set_long(@LONG
这是一只经过诗摩尔圣力冶冶过的盾牌，威力自是不在话下，不过要能完全
发挥出它的力量，你自己也是要有点斤两。
LONG
        );
        set("unit","面");
        set( "type", "shield" );

        set( "material", "mage");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "no_sell",1);
        set( "weight", 100 );
        set( "equip_func","wear_func");
        set( "unequip_func","unwear_func");
        set( "value", ({ 100, "silver" }) );
}

void wear_func()
{
        if( (int)this_player()->query_level() < 15)
        {
                tell_object( this_player(),
                "唉..你的能力不够..恐怕无法充份利用到盾牌的能力\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",3);
        }

        if( ((int)this_player()->query("spell_levels/guild") < 45)||
          ((int)this_player()->query("spell_levels/black-magic") < 42))
        {
                tell_object( this_player(),
                "你对魔法的了解还不够..无法让盾真正发挥出它的威力\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",6);
                set( "special_defense",
			([ "fire": -15, "evil": 10, "cold": 15,
				"divine": -10, "poison":-15, "energy": 15]));
                write( set_color(
                        "\n圣光盾呼应著你的魔力，散出一道金光笼罩在你的身边...\n\n"
                        ,"HIW") );
        }
}

void unwear_func()
{
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
}
