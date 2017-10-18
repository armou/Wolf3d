/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:07:51 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/18 19:03:42 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "../libs/minilibx_macos/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/X.h"
// # include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include <pthread.h>

# define WIDTH 1000
# define HEIGHT 800
# define MAPW 24
# define MAPH 24
# define OFFSET 0.15

# define MAP v->wolf->map
# define TAB v->wolf->tab
# define XMAX v->wolf->xmax
# define YMAX v->wolf->ymax

/*
** Env define
*/

# define MLX v->img->mlx
# define WIN v->img->win
# define IMG v->img->img
# define DATA v->img->data
# define BPP v->img->bpp
# define SIZELINE v->img->sizeline
# define ENDIAN v->img->endian

/*
** Wall Textures define
*/

# define SIZELINETEX v->wtex->sizeline_tex
# define WALLDATA v->wtex->wall_data
# define WALL v->wtex->wall
# define WINDOW v->wtex->window
# define WINDOWDATA v->wtex->window_data
# define DOOR v->wtex->door
# define DOORDATA v->wtex->door_data
# define TEX v->wtex->tex
# define PX v->wtex->px
# define WALLX v->wtex->wallx

/*
**Floor Textures define
*/

# define FLOORX v->ftex->floor_x_wall
# define FLOORY v->ftex->floor_y_wall
# define D_WALL v->ftex->dist_wall
# define D_PLAYER v->ftex->dist_player
# define D_DRAW v->ftex->dist_draw
# define F_XDRAW v->ftex->floor_x_draw
# define F_YDRAW v->ftex->floor_y_draw
# define FLOORTEX_X v->ftex->floor_tex_x
# define FLOORTEX_Y v->ftex->floor_tex_y
# define GRASS v->ftex->grass
# define GRASSDATA v->ftex->grass_data
# define MARBLE v->ftex->marble
# define F_SIZELINE v->ftex->floor_sizeline
# define FTEX v->ftex->floortex
# define CEIL v->ftex->ceil
# define SKYBOX v->ftex->skybox
# define SKYDATA v->ftex->skybox_data
# define STEXH v->ftex->skybox_tex_height
# define STEXW v->ftex->skybox_tex_weight
# define SKYCOLOR v->ftex->skybox_color
# define SKYSIZELINE v->ftex->skybox_sizeline
# define SKYBPP v->ftex->skybox_bpp
# define EXT v->ftex->exterior

/*
** Sprites define
*/

# define SPTEXW v->sp->sprite_tex_width
# define SPTEXH v->sp->sprite_tex_height
# define RABBIT v->sp->rabbit
# define SPRITEX v->sp->sprite_x
# define SPRITEY v->sp->sprite_y
# define SPRITETEX v->sp->sprite_tex
# define SPRITEPOSX v->sp->sprite_pos_x
# define SPRITEPOSY v->sp->sprite_pos_y
# define SPHEIGHT v->sp->sprite_height
# define SPWIDTH v->sp->sprite_width
# define SPDRAWSTARTY v->sp->sprite_drawstart_y
# define SPDRAWENDY v->sp->sprite_drawend_y
# define SPDRAWSTARTX v->sp->sprite_drawstart_x
# define SPDRAWENDX v->sp->sprite_drawend_x

/*
** Raycasting define
*/

# define DRAWSTART v->wolf->draw_start
# define DRAWEND v->wolf->draw_end
# define LINEHEIGHT v->wolf->line_height
# define MAPX v->wolf->mapx
# define MAPY v->wolf->mapy
# define HIT v->wolf->hit
# define SIDE v->wolf->side
# define POSX v->wolf->posx
# define POSY v->wolf->posy
# define DIRX v->wolf->dir_x
# define DIRY v->wolf->dir_y
# define STEPX v->wolf->step_x
# define STEPY v->wolf->step_y
# define RAYPOSX v->wolf->rayposx
# define RAYPOSY v->wolf->rayposy
# define RAYDIRX v->wolf->raydirx
# define RAYDIRY v->wolf->raydiry
# define COLOR v->wolf->color
# define PLANEX v->wolf->plane_x
# define PLANEY v->wolf->plane_y
# define CAMX v->wolf->cam_x
# define D_SIDEX v->wolf->dist_sidex
# define D_SIDEY v->wolf->dist_sidey
# define D_DELTAX v->wolf->dist_deltax
# define D_DELTAY v->wolf->dist_deltay
# define D_PERPWALL v->wolf->dist_perp_wall
# define ROTSPEED v->wolf->rotation_speed
# define MS v->wolf->move_speed

typedef enum		e_esprite
{
	RABBITSP,
}					t_esprite;

typedef struct		s_img
{
	void			*mlx;
	void			*img;
	void			*win;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_img;

typedef struct		s_tex
{
	int				px;
	int				sizeline_tex;
	char			*wall_data;
	void			*wall;
	void			*window;
	char			*window_data;
	char			*door_data;
	void			*door;
	int				tex;
	double			wallx;
}					t_tex;

typedef struct		s_tex_f
{
	void			*grass;
	void			*marble;
	void			*ceil;
	void			*skybox;
	char			*skybox_data;
	char			*grass_data;
	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_wall;
	double			dist_player;
	double			dist_draw;
	double			floor_x_draw;
	double			floor_y_draw;
	int				floor_tex_x;
	int				floor_tex_y;
	int				floor_sizeline;
	int				floortex;
	int				skybox_tex_height;
	int				skybox_tex_weight;
	int				skybox_color;
	int				skybox_sizeline;
	int				skybox_bpp;
	int				exterior;
}					t_tex_f;

typedef struct		s_sprite
{
	void			*rabbit;
	double			sprite_x;
	double			sprite_y;
	double			sprite_pos_x;
	double			sprite_pos_y;
	int				sprite_tex_width;
	int				sprite_tex_height;
	int				sprite_tex;
	int				sprite_height;
	int				sprite_width;
	int				sprite_drawstart_y;
	int				sprite_drawend_y;
	int				sprite_drawstart_x;
	int				sprite_drawend_x;
}					t_sprite;

typedef struct		s_w
{
	double			posx;
	double			posy;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			dir_x;
	double			dir_y;
	double			dist_sidex;
	double			dist_sidey;
	double			dist_deltax;
	double			dist_deltay;
	double			dist_perp_wall;
	double			rotation_speed;
	double			move_speed;
	int				step_x;
	int				step_y;
	int				mapx;
	int				mapy;
	int				xmax;
	int				ymax;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	int				hit;
	int				side;
	char			*map;
	char			**tab;
}					t_w;

typedef struct		s_env
{
	t_img			*img;
	t_w				*wolf;
	t_tex			*wtex;
	t_tex_f			*ftex;
	t_sprite		*sp;
	void			(*pfonct_key[279])(void *, int);
	void			(*pfonct_mouse[10])(int, int, int, void *);
}					t_env;

int					ft_exitprog(t_env *v);
void				ft_ptr_ft(t_env *v);
void				ft_raycast_wall(t_env *v, int x);
void				ft_parse_wolf(t_env *v, int fd);
void				ft_exit(int i);
int					ft_keypress(int keycode, t_env *v);
void				ft_ptr_exit(void *arg, int keycode);
void				ft_isvalid(char *str, char **tab, int x, int y);

void				ft_movlr(void *arg, int keycode);
void				ft_movfb(void *arg, int keycode);
void				ft_rotright(void *arg, int keycode);
void				ft_rotleft(void *arg, int keycode);
void				ft_activate(void *arg, int keycode);

void				ft_init_var(t_env *v);
void				ft_print_wall(t_env *v, int x);
void				ft_calc_step(t_env *v);
void				ft_dda(t_env *v);
void				ft_calc_dist(t_env *v);

void				ft_init_tex(t_env *v);
void				ft_floorcasting(t_env *v, int y, int a);
void				ft_ceilcasting(t_env *v, int x, int y);
void				ft_skycasting(t_env *v);
void				ft_color_floor_tex(t_env *v, int x, int y);
void				ft_create_sprites(t_env *v);
void				ft_skybox(t_env *v, int x, int y);

#endif
