# FUNÇÕES

## mlx_clear_window

> Limpa a janela, removendo imagens, pixels e strings.   
> Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a janela.   
> Não tem retorno.
```c
void	mlx_clear_window(void *mlx_ptr, void *win_ptr);
```

## mlx_destroy_display\*

> Encerra a conexão com o **Xserver**.   
> Recebe como parâmetro um ponteiro para a conexão com o **Xserver**.   
> Retorna `0` se a conexão foi encerrada com sucesso.
```c
int	mlx_destroy_display(void *mlx_ptr);
```
<sub>\* Essa função não dá free no ponteiro, então tome cuidado para não vazar memória.</sub>

## mlx_destroy_window\*

> Destroi a janela.   
> Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a janela.   
> Retorna `1` se a janela foi destruída com sucesso.
```c
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```
<sub>\* Essa função dá free no ponteiro, então não se preocupe com vazamentos.</sub>

## mlx_init

> Inicializa a conexão com o **Xserver**.   
> Não tem parâmetros.   
> Retorna um ponteiro para a conexão criada.
```c
void	*mlx_init(void);
```

## mlx_new_window

> Inicializa uma janela.   
> Recebe como parâmetros um ponteiro para a conexão com o **Xserver**, o tamanho da janela em pixels (0 representa o canto superior esquerdo da tela, **width** avança para a direita e **height** avança para baixo) e o título da janela.   
> Retorna um ponteiro para a janela criada.
```c
void	*mlx_new_window(void *mlx_ptr, int width, int height, char *title);
```
