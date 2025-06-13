
#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdint.h>

# define WIN_W 800
# define WIN_H 600

# define KC_ESC 65307
# define KC_L 65361
# define KC_R 65363
# define KC_U 65362
# define KC_D 65364
# define BTN_UP 4
# define BTN_DN 5

# define PAN_STEP 0.15
# define ZOOM_STEP 1.2

typedef enum e_kind
{
	MANDELBROT,
	JULIA
}			t_kind;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_img;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_kind	kind;
	double	zoom;
	double	off_x;
	double	off_y;
	double c_re; /* Julia 用 C 定数 */
	double	c_im;
	int		iter_base;
	int		hue;
}			t_fract;

void		init_fract(t_fract *f);
int			close_win(t_fract *f);
void		render_frame(t_fract *f);
int			get_color(double mu, int limit, int hue_deg);
double		iter_mu(double cx, double cy, int lim);
int			mouse_hook(int btn, int x, int y, t_fract *f);
int			key_hook(int k, t_fract *f);

#endif
