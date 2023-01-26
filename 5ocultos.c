#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	main(void)
{
	t_data	*data;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 500, 500, "mlx");
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, 2, 1L<<0, key_press, data);
}