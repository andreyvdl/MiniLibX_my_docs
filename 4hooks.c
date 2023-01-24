#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

#define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
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

int	main(void)
{
	t_data	*data;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 500, 500, "Iscas");
	data->img = mlx_new_image(data->mlx, 500, 500);
	mlx_loop(data->mlx);
}