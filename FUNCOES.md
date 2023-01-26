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

## mlx_destroy_image<sup>**1**</sup>

* Destroi uma imagem.   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a imagem.   
* Retorna `1` se a imagem foi destruída com sucesso.
```c
int	mlx_destroy_image(void *mlx_ptr, void *img);
```
<sub><sup>**[1]**</sup>Essa função dá free no ponteiro, então não se preocupe com vazamentos.</sub>

## mlx_destroy_window<sup>**1**</sup>

* Destroi a janela.   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e um ponteiro para a janela.   
* Retorna `1` se a janela foi destruída com sucesso.
```c
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```
<sub><sup>**[1]**</sup>Essa função dá free no ponteiro, então não se preocupe com vazamentos.</sub>

## mlx_expose_hook

* Ela só funciona se você mudar o tamanho da janela (tive que testar no WSL), mesmo que o Manuel diga que funciona quando você minimiza a janela... [**NÃO ACREDITE NAS MENTIRAS DELE**](https://youtu.be/VIbjjDtQVhQ).   
* Recebe como parâmetros um ponteiro para a janela, uma função que será chamada e um ponteiro para um argumento.   
* Retorno é indefinido.   
* A função que é chamada recebe como parâmetro um ponteiro para um argumento.   
* A função que é chamada pode retornar o que ela quiser.
```c
int	mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int	funct_ptr(void *param);
```

## mlx_get_color_value

* Ela transforma uma cor em um valor inteiro... só vi utilidade em querer saber o valor decimal de um hex... o que da pra fazer na internet **OU NA CALCULADORA**😡...   
* Recebe como parâmetros um ponteiro para a conexão com o **Xserver** e uma cor em int😑...   
* Retorna um valor inteiro que representa a cor😶...
```c
int	mlx_get_color_value(void *mlx_ptr, int color);
```

## mlx_get_data_addr

* Ela cria array de tipo char do tamanho **total**<sup>1</sup> da imagem e coloca informação sobre os `bits por pixel`, `tamanho de 1 linha` e [`extremidade mais importante`](https://pt.wikipedia.org/wiki/Extremidade_(ordena%C3%A7%C3%A3o)).   
* Recebe como parâmetros um ponteiro para a imagem, um ponteiro para o tamanho de cada pixel, um ponteiro para o tamanho de cada linha e um ponteiro para o tamanho da imagem.   
* Retorna um ponteiro para o array de tipo char.
```c
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
```
<sub><sup>1</sup>Com total eu teorizo que a formula para o tamanho é: `largura da imagem * altura da imagem * bits por pixel`, isso pois para conseguirmos pintar um pixel nessa imagem, acessamos o array na posição `y * size_line + x * (bpp / 8)` onde x é a posição da largura e y a da altura (no código fonte tem essa conta `(width + 32) * height * 4`, mas tenho quase certeza que ela retorna num número menor que o array final).</sub>


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
