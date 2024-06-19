/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:13:02 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/07 15:01:59 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

# ifndef SPACES
#  define SPACES " \t\n\v\r\f"
# endif

# ifndef CHARACTERS
#  define CHARACTERS "0NSEWDO"
# endif

# ifndef CHARACTERS_MM
#  define CHARACTERS_MM "10NSEWDO"
# endif

# ifndef AUTHORIZED
#  define AUTHORIZED " \t\n\v\r\f10NSEWDO"
# endif

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 18
# endif

# ifndef OPENING_FILE_ERROR
#  define OPENING_FILE_ERROR "Error during file opening"
# endif

# ifndef INVALID_CUB_FILE
#  define INVALID_CUB_FILE "Invalid .cub file"
# endif

# ifndef INVALID_MAP
#  define INVALID_MAP "Invalid map"
# endif

# ifndef MALLOC_ERROR
#  define MALLOC_ERROR "Malloc error"
# endif

# ifndef MLX_INIT_ERROR
#  define MLX_INIT_ERROR "MLX init error"
# endif

typedef struct s_display_minimap
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				col_count;
}	t_display_minimap;

typedef struct s_map
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		*floor_color_arr;
	int		*ceiling_color_arr;
	int		floor_color;
	int		ceiling_color;
	int		num_lines;
	int		biggest_line;
	bool	position;
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*address;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_animation
{
	t_texture		*frames;
	int				current_frame;
	size_t			frame_time;
	size_t			last_update_time;
	char			**path_frame;
}	t_animation;

typedef struct s_minimap
{
	int		square_size;
	int		width;
	int		height;
	int		num_square_x;
	char	**map;
}	t_minimap;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			grid_step_x;
	int			grid_step_y;
	double		side_dist_x;
	double		side_dist_y;
	int			ray_x;
	int			ray_y;
	int			wall_hit;
	int			wall;
	double		shortest_dist_wall_cam;
	int			line;
	int			start;
	int			end;
	int			texture_x;
	double		move_speed;
	double		rot_speed;
	double		cos_rot_speed;
	double		sin_rot_speed;
	double		cos_rot_speed_neg;
	double		sin_rot_speed_neg;
	bool		a_move;
	bool		w_move;
	bool		s_move;
	bool		d_move;
	bool		l_turn;
	bool		r_turn;
	bool		display_minimap;
	bool		door_action;
	int			mouse_x;
	int			mouse_y;
	int			last_mouse_x;
	t_animation	anim;
	t_map		map;
	t_texture	main;
	t_texture	n_txt;
	t_texture	s_txt;
	t_texture	w_txt;
	t_texture	e_txt;
	t_texture	door_open_txt;
	t_texture	door_closed_txt;
	t_minimap	minimap;
}	t_data;

/* GNL */

char			*get_next_line(int fd, t_data *data);
size_t			gnl_strlen(char *str);
char			*gnl_strjoin(char *s1, char *s2);
char			*gnl_strdup(char *s);
void			*gnl_memmove(void *dest, void *src, size_t n);

/* INITIALISATION */

void			init_data(t_data *data);
void			init_raycasting(t_data *data);
void			init_texture(t_texture *texture);
void			init_map(t_data *data);

/* INITIALISATION MLX */

int				init_mlx(t_data *data);
void			load_textures_animations(t_data *data);
void			load_texture(t_data *data, t_texture *texture, \
				char *texture_path);

/* RAYCASTING */

int				raycasting(t_data *data);
void			clear_image(t_data *data);
void			check_if_wall_hit(t_data *data);
void			calc_direction(t_data *data);
void			hit_wall(t_data *data);

/* RAYCASTING UTILS */

void			find_hit(t_data *data, t_texture texture);
void			texture_select_display(t_data *data, int x);
void			wall_dist(t_data *data);
void			calc_line(t_data *data);
void			display_line(t_data *data, t_texture texture, int x);

/* RAYCASTING UTILS 2 */

void			setup_raycasting(t_data *data, int x);
void			one_texture_hit_display(t_data *data, t_texture texture, int x);

/* UTILS */

int				rgb_converter(int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, \
				unsigned int color);
unsigned int	get_pixel_color(t_texture texture, int x, int y);
void			free_double_array(char **array);
int				length_double_arr(char **array);

/* PARSING */

int				parse_file(char *file, t_data *data);
int				parse_textures(char *line, t_data *data, int *found_map);
int				check_text_type(t_data *data, char *line, int i);
void			parse_floor_ceiling(t_data *data);

/* PARSING_UTILS */

int				check_color_str(t_data *data, char *texture, char *line);
int				check_rgb_value(int value);
void			check_space_in_color(t_data *data, char *line, int i);
int				parse_color(int i, char *line, t_data *data, char *name_tex);
int				find_zero(char *str);

/* PARSE TEXTURES */

int				parse_one_texture(char *line, t_data *data, char *str, int i);
void			fill_texture(int i, char *line, char *texture, t_data *data);
char			**convert_in_color_arr_split(char *color_str, t_data *data, \
				char *line);
void			convert_in_color_arr(char *color_str, t_data *data, char *line, \
				int **color_arr);
int				store_texture(char *texture, t_data *data, char *str, \
				char *line);

/* PARSE MAP */

int				calc_map_num_lines(char *file, int *nb_lines, t_data *data);
int				fill_map_array(char **map, int fd, t_data *data);
int				store_map(t_data *data, char *file);
int				check_if_linemap(t_data *data, char *line, bool free_line);

/* MAP CHECKER */

int				check_file_extension(char *file_path);
int				map_checker(t_data *data, char **map, int nb_lines);
void			check_middle_lines(t_data *data, char **map, int i);
int				check_duplicates(t_data *data, char value, int i, int j);
void			init_start_position(char value, t_data *data);

/* MOVES */

void			turn_camera_right(t_data *data);
void			move_a(t_data *data);
void			move_w(t_data *data);
void			move_s(t_data *data);
void			move_d(t_data *data);

/* MOVES UTILS */

void			turn_camera_left(t_data *data);
int				move_monitor(t_data *data);
int				mlx_key_loop(t_data *data);
int				on_keypress(int keycode, t_data *data);
int				on_keyrelease(int keycode, t_data *data);

/* END */

void			end_program(t_data *data, bool exit_success, char *message);
int				close_window(t_data *data);
void			free_mlx(t_data *data, bool to_exit, char *message);
void			free_data(t_data *data, bool to_exit, char *message, char *str);
void			free_double_and_single_arr(char *single_arr_1, \
				char *single_arr_2, char **double_arr);

/* MINIMAP */

void			init_minimap(t_minimap *minimap);
void			display_square_line(t_data *data, char map_element, \
int x, int y);
void			display_minimap(t_data *data);
void			create_minimap(t_data *data, double *pos_x_cpy, \
double *pos_y_cpy);

/* MINIMAP UTILS */

void			fill_black_minimap(t_data *data);
void			fill_up(t_data *data, int x_big, int x);
void			fill_down(t_data *data, int x_big, int x);
void			fill_minimap(t_data *data);

/* MOUSE */

int				mouse_infinite_turn(t_data *data);
void			turn_camera(t_data *data, double angle);
int				mouse_hook(int x, int y, t_data *data);

/* ANIMATION */

void			init_path_frame_array(t_data *data);
void			load_animation(t_data *data);
void			init_animation(t_data *data);
size_t			get_time(void);
void			update_animation(t_animation *anim);

/* DOOR */

void			change_door(char *value);
void			change_door_monitor(t_data *data);
void			door_action(int keycode, t_data *data);
void			free_animation(t_data *data);

#endif
