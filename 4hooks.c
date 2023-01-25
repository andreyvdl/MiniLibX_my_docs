#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
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

int	destroi_tudo(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	teclas(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC)
		destroi_tudo(data);
	printf("Você pressionou a tecla: ");
	write(1, &keycode, 1);
	printf("\nCujo valor em inteiro é: %d\n", keycode);
	return (0);
}

int	mouse(int button, int x, int y, t_data *data)
{
	printf("Botão pressionado: %d\n", button);
	printf("Posição do mouse: %d, %d\n", x, y);
	return (0);
}

int	desenha_triangulo(t_data *data)
{
	int	x;
	int	y;

	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	x = 300;
	while (1)
	{
		y = x - 300;
		while (y < 500)
		{
			// oh continha desgraçada: dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
			// *(unsigned int *)dest = color;
			data->addr[y * data->line_length + (x + y) * (data->bits_per_pixel / 8)] = 0x0000FF00;
			data->addr[y * data->line_length + (x - y) * (data->bits_per_pixel / 8)] = 0x0000FF00;
			data->addr[500 * data->line_length + y * (data->bits_per_pixel / 8)] = 0x0000FF00;
			y++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(void)
{
	t_data	data;
	int	key = 42;
	int	mouse = 42;
	int	expose = 42;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Iscas");
	data.img = mlx_new_image(data.mlx, 500, 500);
	key = mlx_key_hook(data.win, teclas, &data);
	printf("key: %d\n", key);
	mouse = mlx_mouse_hook(data.win, mouse, &data);
	printf("mouse: %d\n", mouse);
	expose = mlx_expose_hook(data.win, desenha_triangulo, &data);
	printf("expose: %d\n", expose);
	mlx_loop(data.mlx);
}