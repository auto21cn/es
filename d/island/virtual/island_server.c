// This is the virtual server of *.island.c in /d/island
// By Odin Feb 23, 1995

#include <daemons.h>
#include <mudlib.h>

#define MAP_FILE "/d/island/island.map"
#define TEMPLATE ROOM

inherit REF_D;

mapping legends, rooms;
mixed map;
int width, height;

void create()
{
	int i, j;
	string *f, str, str2, legend, room;

	seteuid(getuid());
	legends = ([]);
	rooms = ([]);
	f = explode( read_file(MAP_FILE), "\n" );
	for(i=0; i<sizeof(f); ++i) {
		if( !f[i] || f[i]=="" || f[i][0]=='#' ) continue;
		if( sscanf(f[i], "%s %s", str, str2)!= 2)
			str = f[i];
		while( (i+1)<sizeof(f) && (f[i+1][0]==' ' || f[i+1][0]=='>' ) ) {
			str2 += (f[i+1][0]=='>'?"\n":"") + extract( f[i+1], 1,strlen(f[i+1]) );
		i++;
		}
		switch(str)
		{
			case "legend:":
				room = 0;
				legend = str2;
				legends += ([ legend:([]) ]);
				break;
			case "room:":
				legend = 0;
				room = str2;
				rooms += ([ room:([]) ]);
				break;
			case "map:":
				if( sscanf(str2, "%d %d", width, height)!=2 )
					error("Invalid map size: "+MAP_FILE+" line#"+i+"\n");
				map = allocate( height );
				for( j=0; (i+1)<sizeof(f) && j<height; j++)
					map[j] = explode(f[++i], " ");
				if( j++ < height )
					error("Incompelete map data: "+MAP_FILE+" line#"+i+"\n");
				break;
			default:
				if( legend && !undefinedp(legends[legend]) )
					legends[legend] += ([ str: resolv_str(str2) ]);
				else if( room && !undefinedp(rooms[room]) )
					rooms[room] += ([ str: resolv_str(str2) ]);
				else
					error( "Invalid terrain entry: "+MAP_FILE+" line#"+i+"\n");
				break;
		}
	}
}

// This function is called when the driver try to compile an object of
// the name *.island.c
object compile_object(string s)
{
	int i, x, y;
	object obj;
	string *fname, index, *d;

	seteuid(getuid(this_object()));
	fname = explode(s, "/");
	index = fname[sizeof(fname)-1];
	if( sscanf( fname[sizeof(fname)-1], "%d,%d", x, y)!=2 )
		error("File not exist: "+s+"\n");
	fname = (string *)implode( fname[0..sizeof(fname)-2], "/" );
	if( !undefinedp(rooms[index]) ) {
		d = keys(rooms[index]);
		obj = new(TEMPLATE);
		for( i=0; i<sizeof(d); ++i )
			obj->set( d[i], rooms[index][d[i]] );
	} else {
		if( y >= height || x >= sizeof(map[y]) )
			error("Virtual room server: Room is out of map!");
		index = map[y][x];
		obj = new(TEMPLATE);
		d = keys( legends[index] );
		for( i=0; i<sizeof(d); ++i )
			obj->set( d[i], legends[index][d[i]] );
	}
	obj->set("original", s);
	obj->set("virtual_server", base_name(this_object()) );
	obj->set("x_coordinate", x);
	obj->set("y_coordinate", y);
	obj->set_outside("island");

	// Link all directions
	if( !obj->query("exits") )
		obj->set("exits", ([]) );
	if( y>0 ) {
		if( undefinedp( legends[map[y-1][x]]["block_move"] ) )
			obj->add("exits", (["north": (string)fname + "/" + x + "," + (y-1) + ".island" ]) );
	}
	if( y<height-1 ) {
		if( undefinedp( legends[map[y+1][x]]["block_move"] ) )
			obj->add("exits", (["south": (string)fname + "/" + x + "," + (y+1) + ".island" ]) );
	}
	if( x>0 ) {
		if( undefinedp( legends[map[y][x-1]]["block_move"] ) )
			obj->add("exits", (["west" : (string)fname + "/" + (x-1) + "," + y + ".island" ]) );
	}
	if( x<width-1 ) {
		if( undefinedp( legends[map[y][x+1]]["block_move"] ) )
			obj->add("exits", (["east" : (string)fname + "/" + (x+1) + "," + y + ".island" ]) );
	}
	obj->reset();
	return obj;
}

mixed query_legends() { return legends; }
mixed query_rooms() { return rooms; }

string query_legend(int x, int y)
{
	if( y<0 || y>=height ) return "  ";
	if( x<0 || x>=sizeof(map[y]) ) return "  ";
	return (string)map[y][x];
}
