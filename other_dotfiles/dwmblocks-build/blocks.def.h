//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" CPU: ", "/opt/blocks/cpu",							3,		10,},
	{"RAM: ", "/opt/blocks/mem",							4,		10,},
	{"🔊 ", "/opt/blocks/volume",							1,		10,},
	{"", "/opt/blocks/updates",							5,		0,},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
