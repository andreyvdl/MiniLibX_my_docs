#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;

void	draw(t_data *data)
{
	for (int i = 0; i < 300; i++)
	{
		mlx_pixel_put(data->mlx, data->win, i, i, 0x00FF0000);
		usleep(2000);
		mlx_pixel_put(data->mlx, data->win, i, 250, 0x0000FF00);
		usleep(2000);
		mlx_pixel_put(data->mlx, data->win, 250, i, 0x000000FF);
	}
}

int	main(void)
{
	t_data	data;
	int		clear = 42;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 300, 300, "De 0 a 200");
	while (1)
	{
		mlx_string_put(data.mlx, data.win, 100, 90, 0x00FFFFFF, "Desenhando...");
		draw(&data);
		mlx_string_put(data.mlx, data.win, 50, 200, 0x00FFFFFF, "Limpando em 3 segundos...");
		sleep(3);
		clear = mlx_clear_window(data.mlx, data.win);
		printf("Clear: %d | Janela limpa!\n", clear);
		sleep(3);
	}
}
