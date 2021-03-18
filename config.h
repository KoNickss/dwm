#include <X11/XF86keysym.h>
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };
/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx = 2;   /* border pixel of windows */
static const unsigned int gappx     = 20;       /* gap pixel between windows */
static const unsigned int snap     = 32;  /* snap pixel */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 1;   /* 0 means bottom bar */
static const unsigned int baralpha = 0x50;
static const unsigned int borderalpha = OPAQUE;
/* Mononoki Nerd Font must be installed from AUR nerd-fonts-complete.
 * Otherwise, your default font will be Hack which is found in the standard
 * Arch repos and is listed as a dependency for this build. JoyPixels is also
 * a hard dependency and makes colored fonts and emojis possible.
 */
static const char *fonts[]     = {"Mononoki Nerd Font:size=12:antialias=true:autohint=true",
                                  "Hack:size=12:antialias=true:autohint=true",
                                  "JoyPixels:size=12:antialias=true:autohint=true"
						     	};
static const char col_1[]  = "#262626"; /* background color of bar */
static const char col_2[]  = "#282c34"; /* border color unfocused windows */
static const char col_3[]  = "#d7d7d7";
static const char col_4[]  = "#5a7c59"; /* border color focused windows and tags */
//static const char col_4[]  = "#000000"; /* border color focused windows and tags */
//static const char col_4[]  = "#2a9e3d"; /* border color focused windows and tags */
/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
static const char *colors[][3]        = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_3, col_1, col_2 },
	[SchemeSel]  = { col_3, col_4,  col_4 },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "}; 
// static const char *tags[] = { "", "", "", "", "", "", "", "", "" };


static const Rule rules[] = {
/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 4,            0,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Vimb",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Org.gnome.Nautilus",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Minecraft Launcher",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Spotify",  NULL,       NULL,       1 << 6,       0,           -1 },
	{ "discord",  NULL,       NULL,       1 << 7,       0,           -1 },
	{ "Microsoft Teams - Preview",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Steam",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Alacritty",  NULL,       NULL,       1,       0,           -1 },
	{ "XTerm",  NULL,       NULL,       1 << 5,       0,           -1 },
	{ "heroic",  NULL,       NULL,       1 << 3,       0,           -1 },
};
/* layout(s) */
static const float mfact     = 0.70; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
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
	{ MODKEY,               XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,               XK_d,      incnmaster,     {.i = -1 } },
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
	{ MODKEY,               XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },

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


