#include <X11/XF86keysym.h>
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",    NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",   NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",NULL };
static const char *upvolx[]   = { "/usr/bin/pkill", "-RTMIN+11", "dwmblocks",    NULL };
static const char *downvolx[]   = { "/usr/bin/pkill", "-RTMIN+11", "dwmblocks",    NULL };
static const char *mutevolx[]   = { "/usr/bin/pkill", "-RTMIN+11", "dwmblocks",    NULL };
static const char *altbarclass      = "eww-bar"; /* Alternate bar class name */
static const char *altbarcmd        = "/home/konicks/.barrc"; /* Alternate bar launch command */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx = 3;   /* border pixel of windows */
//static const unsigned int framex	= 50; /* gap between windows */
static const unsigned int snap     = 32;  /* snap pixel */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 1;   /* 0 means bottom bar */
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static const unsigned int baralpha = 0xFF;
static const unsigned int borderalpha = 0xFF;
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 90;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 90;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

/* Mononoki Nerd Font must be installed from AUR nerd-fonts-complete.
 * Otherwise, your default font will be Hack which is found in the standard
 * Arch repos and is listed as a dependency for this build. JoyPixels is also
 * a hard dependency and makes colored fonts and emojis possible.
 */
static const char *fonts[]     = {
								  "Cascadia Code:size=12:antialias=true:autohint=true",
								  "JetBrains Mono:size=12:antialias=true:autohint=true",
                                  "Hack:size=10:antialias=true:autohint=true",
                                  "JoyPixels:size=10:antialias=true:autohint=true"
						     	};
static const char col_1[]  = "#262626"; /* background color of bar */
//static const char col_1[]  = "#0f1a2e"; /* background color of bar */
static const char col_2[]  = "#282c34"; /* border color unfocused windows */
static const char col_3[]  = "#d7d7d7";
static const char col_4[]  = "#262626"; /* border color focused windows and tags */
static const char col_5[]  = "#495843"; /* border color focused windows and tags */
//static const char col_5[]  = "#111d35"; /* border color focused windows and tags */
//static const char col_5[]  = "#585d71"; /* border color focused windows and tags */
static const char col_6[]  = "#333333"; /* border color focused windows and tags */
//static const char col_4[]  = "#3f00e4"; /* border color focused windows and tags */
//static const char col_4[]  = "#2a9e3d"; /* border color focused windows and tags */
/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
/*
static const char *colors[][3]        = {
	[SchemeNorm] = { col_3, col_1, col_5 },
	[SchemeSel]  = { col_3, col_5,  col_5 },
	[SchemeTitle]  = { col_3, col_1,  col_5 },
};
*/
static const char *colors[][3]        = {
	[SchemeNorm] = { "#aaaaaa", "#121212", "#121212" },
	[SchemeSel] = { "#aaaaaa", "#222222", "#121212" },
	[SchemeTitle] = { "#aaaaaa", "#121212", "#121212" },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { baralpha, baralpha, borderalpha },
	[SchemeSel]  = { baralpha, baralpha, borderalpha },
	[SchemeTitle]  = { baralpha, baralpha, borderalpha },
};

/* tagging */
//static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}; 
//static const char *tags[] = { " env ", " www ", " ext ", " go ", " home ", " srv ", " spot ", " dis ", " vbox "}; 
static const char *tags[]={" 一 "," 二 "," 三 "," 四 "," 五 "," 六 "," 七 "," 八 "," 九 "};


static const Rule rules[] = {
/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 4,            0,           -1 },
	{ "Brave-browser",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Vimb",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Org.gnome.Nautilus",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Minecraft Launcher",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Spotify",  NULL,       NULL,       1 << 6,       0,           -1 },
	{ "discord",  NULL,       NULL,       1 << 7,       0,           -1 },
	{ "Steam",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Alacritty",  NULL,       NULL,       1,       0,           -1 },
	{ "XTerm",  NULL,       NULL,       1 << 5,       0,           -1 },
	{ "heroic",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "VirtualBox Manager",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Gnome-boxes",  NULL,       NULL,       1 << 8,       0,           -1 },
};
/* layout(s) */
static const float mfact     = 0.70; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "</>",      tile },    /* first entry is default */
	{ "~~~",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* If you are using the standard dmenu program, use the following. */
static const char *dmenucmd[]    = { "dmenu_run", NULL };
/* If you are using the dmenu-distrotube-git program, use the following for a cooler dmenu! */
/* static const char *dmenucmd[]    = { "dmenu_run", "-g", "10", "-l", "48", "-p", "Run: ", NULL }; */

/* the st terminal with tabbed */
static const char *termcmd[]     = { "alacritty", NULL };

static Key keys[] = {
	/* modifier             key        function        argument */
	{ MODKEY,    			XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,               XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,               XK_Escape, spawn,          CMD("leave") },

//	{ MODKEY,               XK_n, tagspwn,          {0} },

	{ MODKEY,               XK_b,      togglebar,      {0} },
	{ MODKEY,               XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,      focusstack,     {.i = -1 } },
	//{ MODKEY,               XK_i,      incnmaster,     {.i = +1 } },
	//{ MODKEY,               XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,               XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,               XK_q,      zoom,           {0} },
	{ MODKEY,               XK_Tab,    view,           {0} },
	{ MODKEY,     XK_c,      killclient,     {0} },
	//{ MODKEY,				XK_Left,	   shiftview,      {.i = -1} },
	//{ MODKEY,				XK_Right,	   shiftview,      {.i = +1} },
	{ 0,        XK_Print,    spawn,          CMD("maim ~/screenshots/$(date +%s).png") },
	{ MODKEY,        XK_s,    spawn,          CMD("scrot -s ~/screenshots/$(date +%s).png") },
    /* Layout manipulation */
	{ MODKEY,               XK_space,  spawn,      CMD("eww open launcher") },

    /* Switch to specific layouts */
	{ MODKEY,               XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,               XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,               XK_m,      setlayout,      {.v = &layouts[2]} },

	{ MODKEY,               XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } },

    /* Switching between monitors */
	{ MODKEY,               XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,               XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_period, tagmon,         {.i = +1 } },
	
    /* Apps Launched with SUPER + ALT + KEY */
	
	TAGKEYS(                  XK_1,          0)
	TAGKEYS(                  XK_2,          1)
	TAGKEYS(                  XK_3,          2)
	TAGKEYS(                  XK_4,          3)
	TAGKEYS(                  XK_5,          4)
	TAGKEYS(                  XK_6,          5)
	TAGKEYS(                  XK_7,          6)
	TAGKEYS(                  XK_8,          7)
	TAGKEYS(                  XK_9,          8)
	{ MODKEY|ShiftMask,       XK_q,	   quit,		   {0} },
    { MODKEY|ShiftMask,       XK_r,    quit,           {1} }, 
	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                       XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },

	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvolx } },
	{ 0,                       XF86XK_AudioMute, spawn, {.v = mutevolx } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvolx   } },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask   button          function        argument */
	{ ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,     0,           Button2,        zoom,           {0} },
	{ ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
	{ ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
	{ ClkTagBar,       0,           Button1,        view,           {0} },
	{ ClkTagBar,       0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
	{ ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};


static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

