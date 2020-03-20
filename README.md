# Mini GameEngine 
Proyecto Final de la Materia "Diseño de Sistemas de Juegos" Ciclo Escolar 2020 ENE-MAR
## M. 14004 Carlo Andrés Hinojosa Relión
![UML Diagram Class](https://user-images.githubusercontent.com/50237712/77143598-491cc300-6a49-11ea-90dd-503e0182f2c4.png)
Aquí se puede ver cómo está subdividido por módulos, Donde Cada uno se encarga de algo diferente, de ahí su título, sus métodos y sus atributos, No incluí el Sistema de Scripting porque ese lo trato de manera más especializada abajo
###Sistema de Scripting
Para el Sistema de scripting integré LUA, juento con archivos con terminación .Lua para correr los tests, lo que se hace es ir envolviendo los métodos y atributos de cada clase para que el usuario las pueda utilizar. Puede desde agregar texto con distintas fonts en UTF-18 Hasta agregar Gifs
##Streaming Assets
En la Carpeta Debug(Dónde se genera el ejecutable) se encuentran varias cosas que se pueden modificar. Tenemos 2 carpetas
1. *EngineConfig*
2. *Scripts*
En _EngineConfig_ Contamos con 3 Archivos (Favor de no eliminarlos)
- Console.txt: Guarda el texto de la consola de la última vez que se ejecutó el programa
- Localized.txt:Se encarga de Agregar los idiomas, si quieres agregar otro simplemente sigue el formato del texto y agrega la traducción al idioma que quieres de las palabras clave
- Settings.ini: Aquí hay varias cosas que se pueden cambiar
	1.width: El ancho de la pantalla del Programa
	2.height: El alto de la pantalla del programa
	3.idiom: El idioma, se escribe en mayúsculas Ej.(ENGLISH, ESPANOL)
	4.Verbo: El nivel de verbosidad, máximo es 3 (Que tan específica es la salida de la consola
	5.buffer: Es la memoria que se le quiere asignar al programa antes de iniciarlo
En la Carpeta _Scripts_ Están todos los scripts que se quieran utilizar, se añade como documento de texto y se guarda como .lua

##ScreenShot de las distintas cosas que se pueden Agregar (Fuentes, Imágenes, Gifs, Primitivas)
![image](https://user-images.githubusercontent.com/50237712/77201807-c3cdf880-6ab2-11ea-912d-c102e268ed5a.png)

##Recursos utilizados
-Stack Allocator (Felipe Mandujano)
-SDL
-C++
-LUA
-STL


##Agradecimientos
Felipe Mandujano