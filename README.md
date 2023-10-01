# GiBo
Game Board (GiBo)

## Equipo:
- [Camilo Álvarez Muñoz.](https://github.com/camiloam20)
- [Simón Sánchez Rúa.](https://github.com/EasierMonk95)
- [Juan Camilo Arteaga Ibarra.](https://github.com/camiloarteaga1)

## Descripción:
Este proyecto surge a partir del concepto de los juegos de mesa, con el objetivo de transformar la experiencia de jugar varios juegos de mesa físicos en una sola "caja" digital versátil. La idea es crear una caja de juegos de mesa electrónica que ofrezca una variedad de juegos en formato digital, eliminando la necesidad de tener múltiples juegos de mesa físicos.

Esta caja de juegos de mesa electrónica se concibe como una solución accesible y compacta, diseñada para partidas de dos jugadores. Los juegos de mesa disponibles serán triqui (Tic-tac-toe), ahorcadito (Hangman) y conecta 4 (Connect-4);


- **Triqui:** el juego podrá ser jugado por dos jugadores a la vez en el modo multijugador, donde cada uno toma su turno para poner su "X" o "O" en la casilla que lo desee, gana el jugador que completa tres de sus símbolos representantes en raya. Después de que todas las casillas hayan sido utilizadas se preguntará si se desea continuar o salir al menú principal.

    - Para el modo de un jugador, el jugador tomará turnos con la máquina para la elección de sus casillas, la máquina elegirá teniendo en cuenta un algoritmo prediseñado para que tenga en cuenta las posibilidades a partir de los espacios disponibles y los que están siendo utilizados.
    
    - Para el multijugador, será como lo es tradicionalmente, turno a turno eligiendo las casillas en cada caso en la que se desea realizar la marcación.

- **Ahorcadito:** el juego tradicional ahorcadito que consta de una palabra formada por una cantidad de letras que deben ser adivinadas por los jugadores o el jugador. A partir de un repositorio de palabras que tendrá el algoritmo, se mostrarán las líneas de cada uno de los caracteres con los que está formada la palabra, revelando en su respectivo espacio el o los caracteres que han sido adivinados, y eliminando de las opciones los que ya han sido utilizados. En caso de equivocarse se mostrará en pantalla un avance del dibujo del personaje que caracteriza al juego "Hangman" y se eliminará el caracter que causó el error. Una vez acabe el juego, se preguntará si se desea continuar o volver a la pantalla principal.

  - Para el modo multijugador, los jugadores elegirán un caracter en su turno, cambiando de jugador cada vez que haya un error de uno de los dos participantes.
  
  - Para el modo de un solo jugador, al contrario que en el modo multijugador, el participante solo será penalizado mostrando un avance del dibujo, lo cual significa la reducción de sus oportunidades para adivinar la palabra escondida.

- **Conecta 4:** es el juego en el que hay un tablero 7x6 contruído por espacios circulares en los que se ubica una ficha roja o amarilla hasta que se conecten 4 fichas del mismo color en raya, empezando desde la parte inferior del tablero hasta la superior. El juego termina una vez se hayan llenado todos los espacios del tablero y/o cuando se hayan logrado tener 4 fichas consecutivas de un mismo color consecutivas. Una vez terminado el juego, se preguntará si se desea continuar o volver a la pantalla principal.

  - En el modo de un jugador, se tomarán turnos contra la máquina para ir colocando las fichas en los respectivos lugares. La máquina analizará cada posición de las fichas en el tablero para tomar la decisión más óptima de su próximo movimiento.
  
  - Para el multijugador, cada uno tomará turnos para posicionar las fichas de su respectivo color en la posición disponible y que desee.

Inicialmente, la "caja" utilizará una pantalla reciclada de un dispositivo no funcional, que estará conectada a un microcontrolador. Además, se incorporarán periféricos, como controles análogos con conexión alámbrica, que podrán guardarse de manera conveniente en un compartimento de la consola para un control fácil y eficiente de la misma. Los controles constarán de los botones básicos, flechas hacia arriba, abajo, derecha e izquierda y dos botones de selección o interacción.

## Requisitos funcionales:
- **Menú:** una interfaz en la cuál el usuario podrá elegir los juegos disponibles o poner a hibernar la consola (GiBo).
- **Modos de uno o dos jugadores:** se tendrá la posibilidad de jugar contra la máquina o contra otra persona de la manera descrita en la idea del proyecto.
- **Control (mando) de botones:** será un control alámbrico compuesto por las flechas tradicionales (arriba, abajo, izquierda y derecha) y por dos botones más para la selección. Para la detección de las señales de los controles se hará uso de los puestos GPIO, las cuales actuarán como señales de entrada para realizar funciones específicas de los juegos (dependeránde cada juego) o selecciones en el menú. Además, por medio de un suiche u otro botón independiente a los controles, se cortará el suministro de energía para el sistema completo.
- **Gestión de energía:** el programa deberá hacer uso de las técnicas de interrupciones para gestionar de manera eficiente el consumo energético del dispositivo, permitiéndole entrar en un modo de reposo, al cual el usuario podrá acceder desde el menú.
- **Procesamiento de datos:** teniendo en cuenta las señales de entrada para el control de las acciones en el dispositivo se desarrollarán cada uno de los juegos propuestos, evitando así fallos que puedan aparecer durante la ejecución. También, según la necesidad que el dispositivo desarrollado presente, poder dar las respuestás más rápidas dentro de nuestros conocimientos y capacidades, desarrollando un código con una buena optimización en el manejo de las instrucciones.
- **Monitor (pantalla):** a partir de la pantalla que se utilice, se procederá a realizar las conexiones necesarias para que el dispositivo muestre en dicha pantalla, la imagen que le permita al usuario saber qué acciones se están ejecutando, permitiéndole tener una buena experiencia con el dispositivo.
- **Respuestas esperadas:** estas depenederán de cada juego o sección del programa en el que se encuentre el usuario, pero en general, se espera que haciendo uso de manera intuitiva (con sentido común) los controladores del dispositivo, la acción se refleje de manera correcta durante la ejecución de los programas realizados.

## Requisitos NO funcionales:
- **Bajo costo:** teniendo en cuenta la funcionalidad y las opciones de juegos que se desean implementar, se estima que la implementación del proyecto tendrá un costo máximo de 300.000 COP. Esto sin contemplar gastos de reparaciones u otros improvistos que puedan surgir durante el desarrollo. 
- **Versatilidad para guardar los mandos de control:** será posible guardarlos como parte de la misma caja, es decir, en un compartimento de la consola misma. 
- **Portabilidad aceptable:** se espera realizar un diseño con un tamaño máximo de 15 pulgadas y un peso máximo de 1.5 Kg. El objetivo es un diseño que sea pequeño y fácil de cargar para así representar una ventaja a comparación de las cajas de juegos de mesa convencionales. 
- **Bajo consumo de energía:** se plantea poder alimentar cada uno de sus componentes con una batería (6000mA/h), esperamos que sea de un celular no funcional.
- **Uso intuitivo:** al ser un objeto similar a lo que se está acostumbrado comúnmente, su uso no ha de ser complicado para los usuarios. 
- **Diseño estético:** la forma y las decoraciones de la consola serán agradables visualmente.

## Componentes y precios:
Esto es una lista de componentes que serán utilizados o posiblemente utilizados, cada uno con sus precios que son relativos a la variación del mercado.

- Raspberry Pi Pico: 42.000 COP
- Controles: 60.000 COP
- Batería: 60.000 COP
- Cableado: 25.000 COP
- Pantalla: 30.000 COP
- Estructura (caja): 20.000 COP
- Decoración: 15.000 COP

El total (en pesos colombianos) de los componentes (suponiendo una compra de cada uno de los componentes) es de 252.000. Es posible que el precio final sea diferente, teniendo en cuenta la aparición de problemas como lo son un componente que se daña o que no funciona correctamente.

Los costos serán cubiertos por el mismo poder adquisitivo de los estudiantes (algunos de los componentes se espera poder ser obtenidos del reciclaje de otros dispositivos no funcionales).
