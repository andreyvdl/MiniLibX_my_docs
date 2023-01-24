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

int	main(void)
{
	t_data	data;
	int		inutil;
	int		contador = 0;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 400, 400, "Pikachu, eu escolho voce!");
	while (1)
	{
		data.img = mlx_xpm_file_to_image(data.mlx, "pikachu.xpm", &inutil, &inutil);
		printf("Carregando imagem...\n");
		sleep(1);
		srandom(time(NULL));
		mlx_put_image_to_window(data.mlx, data.win, data.img, random()%301, random()%301);
		printf("Deletando imagem...\n");
		sleep(1);
		inutil = mlx_destroy_image(data.mlx, data.img);
		printf("Image: %d | Imagem deletada!\n", inutil);
		sleep(1);
		contador++;
		if (contador == 30)
		{
			inutil = mlx_clear_window(data.mlx, data.win);
			printf("Clear: %d | Janela limpa!\n", inutil);
			contador = 0;
		}
	}
}