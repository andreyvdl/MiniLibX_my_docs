# FUNÇÕES

## mlx_clear_window

* Limpa a janela, removendo imagens, pixels e strings.   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a janela.   
* Retorna `1` se a janela foi limpa com sucesso.
```c
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
```

## mlx_destroy_display<sup>**1**</sup>

* Encerra a conexão com o **Xserver**.   
* Recebe como parâmetro um ponteiro para a conexão com o **Xserver**.   
* Retorna `0` se a conexão foi encerrada com sucesso.
```c
int	mlx_destroy_display(void *mlx_ptr);
```
<sub><sup>**[1]**</sup>Essa função não dá free no ponteiro, então tome cuidado para não vazar memória.</sub>

## mlx_destroy_image<sup>**2**</sup>

* Destroi uma imagem.   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a imagem.   
* Retorna `1` se a imagem foi destruída com sucesso.
```c
int	mlx_destroy_image(void *mlx_ptr, void *img);
```
<sub><sup>**[2]**</sup>Essa função dá free no ponteiro, então não se preocupe com vazamentos.</sub>

## mlx_destroy_window<sup>**3**</sup>

* Destroi a janela.   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a janela.   
* Retorna `1` se a janela foi destruída com sucesso.
```c
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```
<sub><sup>**[3]**</sup>Essa função dá free no ponteiro, então não se preocupe com vazamentos.</sub>

## mlx_expose_hook

> "A função `mlx_expose_hook` é uma função de gancho que é chamada quando uma janela precisa ser redesenhada, geralmente devido a uma mudança de tamanho ou ao retorno de uma janela minimizada. Essa função é geralmente usada para redesenhar a janela quando ela é exposta." - chatGPT.   
* Eu sinceramente não entendi o uso dela nem pra que serve.   
* Recebe como parâmetros um ponteiro para a janela, uma função que será chamada e um ponteiro para um argumento.   
* Retorna sempre `10`.   
* A função que é chamada recebe como parâmetro um ponteiro para um argumento.
```c 	 	
int	mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int	funct_ptr(void *param);
```

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
