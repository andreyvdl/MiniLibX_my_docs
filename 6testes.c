#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;

int	destroi_tudo(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	main(void)
{
	t_data	data;
	int		tela_x = 42;
	int		tela_y = 42;
	int		mouse_x = 42;
	int		mouse_y = 42;
	int		r = 42;
	char	*damas[] = {
		"32 32 3 1 ",
		"+ c #0000FF",
		". c #00FFFF",
		"& c #FFFFFF",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++....&&&&....&&&&....&&&&++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++&&&&....&&&&....&&&&....++++",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++",
		"++++++++++++++++++++++++++++++++"
		};

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "Se as damas sao as pecas elas evoluiem para o que?");
	r = mlx_get_screen_size(data.mlx, &tela_x, &tela_y);
	printf("size: x = %d, y = %d | r = %d\n", tela_x, tela_y, r);
	mlx_string_put(data.mlx, data.win, 50, 50, 0x00FFFFFF, "RAPIDO, COLOQUE O MOUSE NA TELA");
	sleep(3);
	r = mlx_mouse_get_pos(data.mlx, data.win, &mouse_x, &mouse_y);
	printf("mouse: x = %d, y = %d | r = %d\nNAO MEXA O MOUSE\n", mouse_x, mouse_y, r);
	sleep(1);
	r = mlx_mouse_hide(data.mlx, data.win);
	printf("hide = %d\n", r);
	srand(time(NULL));
	r = mlx_mouse_move(data.mlx, data.win, rand()%500, rand()%500);
	printf("move = %d\n", r);
	sleep(1);
	r = mlx_mouse_show(data.mlx, data.win);
	printf("show = %d\n", r);
	sleep(1);
	data.img = mlx_xpm_to_image(data.mlx, damas, &tela_x, &tela_y);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 50, 350);
// 6x13
	mlx_set_font(data.mlx, data.win, "6x13"); // aguardem que estou investigando
	mlx_string_put(data.mlx, data.win, 50, 400, 0x00FFFFFF, "Vai uma partidinha de cavalheiros ai?");
	mlx_hook(data.win, 17, 0, destroi_tudo, &data);
	mlx_loop(data.mlx);
}