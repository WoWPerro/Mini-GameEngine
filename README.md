This is a c++ Solution with SDL already setted up for drawing on screen It has already setted up the Linker, external Libs, etc. It also contains SDL-Image & Text, with clases with implementations you can call for drawing, Displaying text or displaying Images, plus Gamestates with the Init, Draw & update States. Also An example of a GameState called "Game". It also contains data Structures made by Myself, feel free to use this project for understanding how to use SDL or a Structure of a game.

=======================================================================================================================================
Instrucions
The project is setted up in x86, for compiling clone the project, then compile it (It will tell you you are missing DLLs), but when you compile it will create a Debug Folder. Go to your Debug folder and paste the missing Dlls, they are in paths:

SDLDrawReady\ExternalLibs\SDL2_image-2.0.4\lib\x86
-libjpeg-9.dll
-libpng16-16.dll
-libtiff-5.dll
-libwebp-7.dll
-SDL2_image.dll
-zlib1.dll

SDLDrawReady\ExternalLibs\SDL2-2.0.9\lib\x86
libfreetype-6
SDL2
SDL2_ttf


after you copy-paste this files to your debug folder it should be ready for you to start using it.
======================================================================================================================================
Also feel free to contribute to the project