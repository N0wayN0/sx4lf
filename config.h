#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 800,
	WIN_HEIGHT = 600
};

/* colors and font are configured with 'background', 'foreground' and
 * 'font' X resource properties.
 * See X(7) section Resources and xrdb(1) for more information.
 */
static const char * const MARK_COLOR   = "#FF0000";

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
	 12.5,  25.0,  50.0,  75.0,
	100.0, 150.0, 200.0, 400.0, 800.0
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 3 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 5;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = false;

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 96, 128, 160, 320, 720 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 3;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
	{ 0,            XK_Escape,        g_quit,               None },
	//{ 0,            XK_Return,        g_switch_mode,        None },
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ 0,            XK_b,             g_toggle_bar,         None },
	//{ ControlMask,  XK_x,             g_prefix_external,    None },
	//{ 0,            XK_Home,            g_first,              None },
	//{ 0,            XK_g,             g_first,              None },
	//{ 0,            XK_G,             g_n_or_last,          None },
	//{ 0,            XK_End,             g_n_or_last,          None },
	//{ 0,            XK_r,             g_reload_image,       None },
	//{ 0,            XK_D,             g_remove_image,       None },
	//{ ControlMask,  XK_h,             g_scroll_screen,      DIR_LEFT },
	//{ ControlMask,  XK_Left,          g_quit,      DIR_LEFT },
	{ ControlMask,  XK_Down,          g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_Up,            g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_Right,         g_quit,      DIR_RIGHT },
	{ 0,            XK_plus,          g_zoom,               +1 },
	{ 0,            XK_KP_Add,        g_zoom,               +1 },
	{ 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_KP_Subtract,   g_zoom,               -1 },
	{ 0,            XK_m,             g_toggle_image_mark,  None },
	//{ 0,            XK_M,             g_mark_range,         None },
	//{ ControlMask,  XK_m,             g_reverse_marks,      None },
	//{ ControlMask,  XK_u,             g_unmark_all,         None },
	//{ 0,            XK_period,        g_navigate_marked,    +1 },
	//{ 0,            XK_comma,         g_navigate_marked,    -1 },
	//{ 0,            XK_braceleft,     g_change_gamma,       -1 },
	//{ 0,            XK_braceright,    g_change_gamma,       +1 },
	//{ ControlMask,  XK_g,             g_change_gamma,        0 },

	//{ 0,            XK_h,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_Left,          g_quit,               DIR_LEFT },
	//{ 0,            XK_j,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_Down,          g_quit,               DIR_DOWN },
	//{ 0,            XK_k,             t_move_sel,           DIR_UP },
	{ 0,            XK_Up,            g_quit,               DIR_UP },
	//{ 0,            XK_l,             t_move_sel,           DIR_RIGHT },
	//{ 0,            XK_Right,         g_quit,               DIR_RIGHT },
	//{ 0,            XK_R,             t_reload_all,         None },

	{ 0,            XK_Next,          g_toggle_fullscreen,  None },
	// { 0,            XK_Right,         i_navigate,           +1 },
	{ 0,            XK_Left,          i_navigate,           -1 },
	{ 0,            XK_Prior,         i_navigate,           -1 },
	{ 0,            XK_N,             i_navigate,           +1 },
	{ 0,            XK_n,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_space,         g_quit,               32 },
	{ 0,            XK_P,             i_navigate,           -1 },
	{ 0,            XK_p,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_BackSpace,     i_navigate,           -1 },
	{ 0,            XK_bracketright,  i_navigate,           +10 },
	{ 0,            XK_bracketleft,   i_navigate,           -10 },
	{ ControlMask,  XK_6,             i_alternate,          None },
	{ ControlMask,  XK_n,             i_navigate_frame,     +1 },
	{ ControlMask,  XK_p,             i_navigate_frame,     -1 },
	{ ControlMask,  XK_space,         i_toggle_animation,   None },
	//{ 0,            XK_h,             i_scroll,             DIR_LEFT },
	//{ 0,            XK_Left,          i_scroll,             DIR_LEFT },
	//{ 0,            XK_j,             i_scroll,             DIR_DOWN },
	{ ControlMask,  XK_Down,          i_scroll,             DIR_DOWN },
	//{ 0,            XK_k,             i_scroll,             DIR_UP },
	{ ControlMask,  XK_Up,            i_scroll,             DIR_UP },
	//{ 0,            XK_l,             i_scroll,             DIR_RIGHT },
	//{ 0,            XK_Right,         i_scroll,             DIR_RIGHT },
	//{ 0,            XK_H,             i_scroll_to_edge,     DIR_LEFT },
	//{ 0,            XK_J,             i_scroll_to_edge,     DIR_DOWN },
	//{ 0,            XK_K,             i_scroll_to_edge,     DIR_UP },
	//{ 0,            XK_L,             i_scroll_to_edge,     DIR_RIGHT },
	{ 0,            XK_equal,         i_set_zoom,           100 },
	{ 0,            XK_w,             i_fit_to_win,         SCALE_DOWN },
	{ 0,            XK_W,             i_fit_to_win,         SCALE_FIT },
	{ ControlMask,  XK_Next,             i_fit_to_win,         SCALE_FIT },
	{ 0,            XK_e,             i_fit_to_win,         SCALE_WIDTH },
	{ ControlMask,  XK_Prior,             i_fit_to_win,         SCALE_WIDTH },
	{ 0,            XK_E,             i_fit_to_win,         SCALE_HEIGHT },
	{ 0,            XK_less,          i_rotate,             DEGREE_270 },
	{ 0,            XK_greater,       i_rotate,             DEGREE_90 },
	{ 0,            XK_question,      i_rotate,             DEGREE_180 },
	{ 0,            XK_bar,           i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_underscore,    i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ 0,            XK_s,             i_slideshow,          None },

	{ ControlMask,  XK_Right,         t_move_img,	        DIR_RIGHT },
	{ ControlMask,  XK_Left,          t_move_img,   	    DIR_LEFT },
	{ ControlMask,  XK_s,             g_dump_files,	        1 },
	{ ControlMask,  XK_a,             g_dump_files,	        2 },
	{ ControlMask,  XK_d,             g_del_selected,	    None },
	{ 0,			XK_t,             g_edit_tags,		    None },
	{ ControlMask,	XK_Return,        g_edit_tags,		    None },
	{ 0,			XK_T,             g_run_cmd,		    1 },
	{ 0,			XK_Delete,        g_run_cmd,		    2 },
	{ 0,			XK_o,             g_run_cmd,		    3 },
	{ 0,			XK_Right,         g_run_cmd,		    3 },
	{ 0,			XK_S,             g_run_cmd,		    4 },
};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            4,                g_zoom,    			+1 },				/* wheel up 	- zoom image */
	{ 0,            5,                g_zoom,    			-1 },				/* wheel down	- zoom out */
	{ 0,            1,                i_drag,               DRAG_RELATIVE },	/* left click 	- dragg zoomed image */
	{ 0,            3,                i_fit_to_win,         SCALE_FIT },		/* right click 	- reset zoom make full screen */
	//{ 0,            2,                g_switch_mode,        None },				/* wheel click	- go to thumb mode */
	//{ 0,            4,                i_navigate,           -1 },				/* wheel up		- navigate back */
	//{ 0,            5,                i_navigate,           +1 },				/* wheel down	- nawigate next */
};

#endif
