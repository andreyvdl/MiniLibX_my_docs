#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

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
	if (keycode == ESC)
		destroi_tudo(data);
	if (keycode == 'r')
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_string_put(data->mlx, data->win, 150, 265, 0x00FF0000, "Clique abaixo com o mouse para pintar");
	}
	printf("Você pressionou a tecla: %c", keycode);
	printf("\nCujo valor em inteiro é: %d\n", keycode);
	return (0);
}

int	rato(int button, int x, int y, t_data *data)
{
	printf("Botão pressionado: %d\n", button);
	printf("Posição do mouse: %d, %d\n", x, y);
	if (button == 1)
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FFFFFF);
	return (0);
}

void	pinta_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	// ponteiro_pontoXY = &addr[y * tamanho de 1 linha + x * (transforma bits em bytes)]
	// conteudo_do_pontoXY = cor
	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	desenha_triangulo(t_data *data)
{
	int	x;
	int	y;
	static int	i = 0;
	static int	quantidade = 0;

	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	x = 250;
	y = 0;
	while (y < 250)
	{
		pinta_pixel(data, x + y, y, 0x0000FF00);
		pinta_pixel(data, x - y, y, 0x0000FF00);
		pinta_pixel(data, y, 250, 0x0000FF00);
		y++;
	}
	while (y < 500)
	{
		pinta_pixel(data, y, 250, 0x0000FF00);
		y++;
	}
	if (i == 499)
		i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->img, i++, 0);
	if (quantidade == __INT32_MAX__)
		quantidade = 0;
	quantidade++;
	usleep(quantidade);
	return (42);
}

int	main(void)
{
	t_data	data;
	int	key = 42;
	int	mouse = 42;
	int	expose = 42;
	int	loop = 42;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Iscas");
	data.img = mlx_new_image(data.mlx, 500, 251);
	key = mlx_key_hook(data.win, teclas, &data);
	sleep(1);
	printf("key: %d\n", key);
	mouse = mlx_mouse_hook(data.win, rato, &data);
	sleep(1);
	printf("mouse: %d\n", mouse);
	expose = mlx_expose_hook(data.win, desenha_triangulo, &data);
	sleep(1);
	printf("expose: %d\n", expose);
	loop = mlx_loop_hook(data.mlx, desenha_triangulo, &data);
	sleep(1);
	printf("loop: %d\n", loop);
	mlx_string_put(data.mlx, data.win, 150, 265, mlx_get_color_value(data.mlx, 0x00FF0000), "Clique abaixo com o mouse para pintar");
	mlx_loop(data.mlx);
}