#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

int	destroi_tudo(t_data *data)
{
	int r = 42;

	r = mlx_clear_window(data->mlx, data->win);
	printf("clear = %d\n", r);
	r = mlx_destroy_window(data->mlx, data->win);
	printf("window = %d\n", r);
	r = mlx_loop_end(data->mlx);
	printf("end = %d\n", r);
	r = mlx_destroy_display(data->mlx);
	printf("display = %d\n", r);
	free(data->mlx);
}

int	key_press(int keycode, t_data *data)
{
	static int	x = 0;
	static int	y = 0;

	if (keycode == 'd' && x < 499)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x000000FF);
		x++;
	}
	else if (keycode == 'a' && x > 0)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x000000FF);
		x--;
	}
	else if (keycode == 'w' && y > 0)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x000000FF);
		y--;
	}
	else if (keycode == 's' && y < 499)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x000000FF);
		y++;
	}
	else if (keycode == 'r')
		mlx_clear_window(data->mlx, data->win);
	return (0);
}

int	main(void)
{
	t_data	data;
	int	retorno = 42;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Etch A Sketch ou Tron?");
	retorno = mlx_do_key_autorepeaton(data.mlx);
	printf("autorepeat = %d\n", retorno);
	retorno = mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	printf("hook1 = %d\n", retorno);
	retorno = mlx_hook(data.win, 17, 0, destroi_tudo, &data);
	printf("hook2 = %d\n", retorno);
	retorno = mlx_string_put(data.mlx, data.win, 200, 200, 0xFFFFFF, "clique no X");
	printf("string = %d\n", retorno);
	retorno = mlx_do_sync(data.mlx);
	printf("sync = %d\n", retorno);
	mlx_loop(data.mlx);
}