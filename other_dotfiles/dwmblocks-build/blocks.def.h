//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" ♫: ", "/opt/blocks/gettitle",							10,		0,},
	{"AAPL: ", "stonks AAPL",							10,		0,},
	//{"GME: ", "stonks GME",							10,		0,},
	//{"BTC: ", "stonks -c BTC",							10,		0,},
	{"CPU: ", "/opt/blocks/cpu",							3,		13,},
	//{"RAM: ", "/opt/blocks/mem",							4,		14,},
	{"🔊 ", "/opt/blocks/volume",							0,		11,},
	{"", "/opt/blocks/updates",							5,		35,},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		36},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "   ";
static unsigned int delimLen = 5;
