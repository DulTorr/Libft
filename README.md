*Este proyecto ha sido creado como parte del currículo de 42 por dutorrez.*

# Libft

## Descripción

`libft` es una librería estática escrita en C que reúne un conjunto de funciones de propósito general. Parte de ellas son reimplementaciones de funciones de la librería estándar (`libc`), y el resto son utilidades adicionales que no existen en ella o que se comportan de forma distinta.

El objetivo del proyecto es comprender en profundidad cómo funcionan estas funciones implementándolas desde cero, trabajando directamente con punteros, memoria dinámica y cadenas de caracteres. El resultado, `libft.a`, es una herramienta reutilizable a lo largo del resto del cursus.

La librería se divide en tres partes: funciones de la `libc`, funciones adicionales y funciones para manipular listas enlazadas. Todo el código respeta la Norma, no declara variables globales y no produce leaks de memoria.


### Contenido de la librería
- **Carácter:** ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint.
- **Memoria:** ft_memset, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc, ft_bzero.
- **Cadenas:** ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_strmapi, ft_striteri, ft_split.
- **Conversión:** ft_atoi, ft_itoa, ft_toupper, ft_tolower.
- **Escritura:** ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd.
- **Listas:** ft_lstnew, ft_lstmap, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter.

## Instrucciones

Clona el repositorio y compila con `make`:

```bash
git clone https://github.com/DulTorr/Libft.git libft
cd libft
```

Reglas disponibles en el Makefile:

```bash
make          # compila la parte obligatoria y genera libft.a
make bonus    # compila la parte obligatoria junto con las funciones de listas
make clean    # elimina los archivos objeto (.o)
make fclean   # elimina los .o y libft.a
make re       # equivale a fclean seguido de make
```

Todos los archivos `.c` se compilan con las flags `-Wall -Wextra -Werror` y la librería se genera con `ar`.

Para usarla en tu propio programa, incluye la cabecera y enlaza contra la librería:

```c
#include "libft.h"

int main(void)
{
    char *s;

    s = ft_strjoin("Hola, ", "42!");
    if (!s)
        return (1);
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

```bash
cc main.c -L. -lft -o programa
./programa
```

## Funciones

### Parte 1 — Funciones de la libc

Reimplementaciones con el prefijo `ft_`. Mantienen el mismo prototipo y comportamiento que las originales descritas en su página del manual.

| Función | Descripción |
|---------|-------------|
| `ft_isalpha` | Devuelve 1 si el carácter es una letra, 0 si no |
| `ft_isdigit` | Devuelve 1 si el carácter es un dígito, 0 si no |
| `ft_isalnum` | Devuelve 1 si el carácter es alfanumérico, 0 si no |
| `ft_isascii` | Devuelve 1 si el carácter pertenece a la tabla ASCII, 0 si no |
| `ft_isprint` | Devuelve 1 si el carácter es imprimible, 0 si no |
| `ft_strlen` | Calcula la longitud de una cadena sin contar el terminador nulo |
| `ft_memset` | Rellena una zona de memoria con un byte determinado |
| `ft_bzero` | Pone a cero una zona de memoria |
| `ft_memcpy` | Copia n bytes de una zona de memoria a otra |
| `ft_memmove` | Copia n bytes de forma segura aunque las zonas se solapen |
| `ft_strlcpy` | Copia una cadena limitando el tamaño del destino |
| `ft_strlcat` | Concatena dos cadenas limitando el tamaño del destino |
| `ft_toupper` | Convierte una letra minúscula en mayúscula |
| `ft_tolower` | Convierte una letra mayúscula en minúscula |
| `ft_strchr` | Busca la primera aparición de un carácter en una cadena |
| `ft_strrchr` | Busca la última aparición de un carácter en una cadena |
| `ft_strncmp` | Compara dos cadenas hasta un máximo de n caracteres |
| `ft_memchr` | Busca un byte dentro de una zona de memoria |
| `ft_memcmp` | Compara dos zonas de memoria byte a byte |
| `ft_strnstr` | Busca una subcadena dentro de otra, limitando la búsqueda a n caracteres |
| `ft_atoi` | Convierte el principio de una cadena en un número entero |
| `ft_calloc` | Reserva memoria para un array y la inicializa a cero |
| `ft_strdup` | Devuelve una copia de una cadena reservada con malloc |

### Parte 2 — Funciones adicionales

| Función | Descripción |
|---------|-------------|
| `ft_substr` | Devuelve una subcadena de `s` que empieza en `start` y mide como máximo `len` |
| `ft_strjoin` | Devuelve una nueva cadena resultado de concatenar `s1` y `s2` |
| `ft_strtrim` | Devuelve una copia de `s1` sin los caracteres de `set` al principio y al final |
| `ft_split` | Divide una cadena por un carácter delimitador y devuelve un array terminado en NULL |
| `ft_itoa` | Convierte un entero (incluidos los negativos) en una cadena |
| `ft_strmapi` | Aplica una función a cada carácter de una cadena, pasando su índice, y devuelve el resultado en una cadena nueva |
| `ft_striteri` | Aplica una función a cada carácter de una cadena pasando su dirección, permitiendo modificarlo in situ |
| `ft_putchar_fd` | Escribe un carácter en el descriptor de archivo indicado |
| `ft_putstr_fd` | Escribe una cadena en el descriptor de archivo indicado |
| `ft_putendl_fd` | Escribe una cadena seguida de un salto de línea en el descriptor indicado |
| `ft_putnbr_fd` | Escribe un número entero en el descriptor de archivo indicado |

Las funciones que reservan memoria devuelven `NULL` si la reserva falla.

### Parte 3 — Listas enlazadas

Las funciones de esta parte trabajan sobre la siguiente estructura, declarada en `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Donde `content` almacena los datos del nodo (como `void *`, para admitir cualquier tipo) y `next` apunta al siguiente nodo, o a `NULL` si es el último de la lista.

| Función | Descripción |
|---------|-------------|
| `ft_lstnew` | Crea un nodo nuevo con el contenido dado y `next` a NULL |
| `ft_lstadd_front` | Añade un nodo al principio de la lista |
| `ft_lstsize` | Devuelve el número de nodos de la lista |
| `ft_lstlast` | Devuelve el último nodo de la lista |
| `ft_lstadd_back` | Añade un nodo al final de la lista |
| `ft_lstdelone` | Libera el contenido de un nodo con la función `del` y el nodo en sí, sin tocar el siguiente |
| `ft_lstclear` | Elimina y libera un nodo y todos los que le siguen, dejando el puntero a NULL |
| `ft_lstiter` | Recorre la lista aplicando una función al contenido de cada nodo |
| `ft_lstmap` | Crea una lista nueva aplicando una función al contenido de cada nodo |

## Recursos

- Páginas del manual de cada función original: `man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 atoi`, `man 3 calloc`, etc.
- `man ar` y `man make`, para entender la generación de la librería estática.
- La Norma de 42 y la herramienta `norminette` para verificar el estilo del código.
- [C Programming A Modern Approach 2nd Ed](https://archive.org/details/c-programming-a-modern-approach-2nd-ed-c-89-c-99-king-by)
- [Como hacer un Makefile](https://hernandis.me/blog/como-hacer-un-makefile/)
-  [README.MD File - GeeksforGeeks](https://www.geeksforgeeks.org/git/what-is-readme-md-file/)


### Uso de IA
 
 Se ha usado Claude AI para el formato de este README, resolver dudas conceptuales y la verificación del correcto funcionamiento de las funciones (casos límite).
