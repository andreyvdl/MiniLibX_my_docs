#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;

int	main(void)
{
	void	*mlx = 0x0;
	void	*win = 0x0;
	int		display = 42;
	int		window = 42;

	while (1)
	{
		mlx = mlx_init();
		if (!mlx)
			printf("mlx_init falhou\n");
		win = mlx_new_window(mlx, 400, 100, "Sistema de autodestruicao ativado");
		if (!win)
			printf("mlx_new_window falhou\n");
		printf("Conexão e janela criadas\n");
		sleep(3);
		window = mlx_destroy_window(mlx, win);
		win = NULL;
		printf("window: %d | Janela destruída\n", window);
		sleep(3);
		display = mlx_destroy_display(mlx);
		free(mlx);
		mlx = NULL;
		printf("display: %d | Conexão destruída\n", display);
		sleep(3);
	}
}