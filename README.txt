
                                                                                
                                   %&&&&&#                                    
                            &&&&&&&&&&  &&&&%&&&&                             
                         &&&&&&&&&&&&   &&&  /&&&&&&                          
                      &&&&&&&&&&&&.    &&    &%&&&&&&&#                       
                    ,&&&&&&&&&&&    &&     &&  &&&& &&&&                      
                   %&&&&&&&&&     &&    &&%   .&&   &&&&&\                    
                  /&&&&&&&&    &&     &&    #&&    &&&&&&&.                   
                  &&&&&&&    &&    &&#    &&    .&&/&&&&&&&                   
                  &&&&&&,  &&    &&    &&&    &&#  #&&&&&&&                   
                  &&&&&&& /&   &&    &&    *&&    &&&&&&&&&                   
                  &&&&&&&& &(.&#   &&    &&,    &&&&&&&&&&%                   
                   &&&&&&&&&&&&  *&&   &&&   &&&&&&&&&&&&&                    
                    &&&&&&&&&&&# &&&# &&&& %&&&&&&&&&&&&&                     
                     *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                       
                       *&&&&                    .&&&&                         
                          *&&&&&&           &&&&&&                            
                               %&&&&     &&&&%                                
                                                                                


              /$$$$$$ /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$      /$$
             |_  $$_/|__  $$__/| $$_____/ /$$__  $$| $$$    /$$$
               | $$     | $$   | $$      | $$  \__/| $$$$  /$$$$
               | $$     | $$   | $$$$$   |  $$$$$$ | $$ $$/$$ $$
               | $$     | $$   | $$__/    \____  $$| $$  $$$| $$
               | $$     | $$   | $$       /$$  \ $$| $$\  $ | $$
              /$$$$$$   | $$   | $$$$$$$$|  $$$$$$/| $$ \/  | $$
             |______/   |__/   |________/ \______/ |__/     |__/



    _       _      _                 _   _       _                 _           
   /_\   __| |_ __(_) __ _ _ __     /_\ | | ___ (_) __ _ _ __   __| |_ __ ___  
  //_\\ / _` | '__| |/ _` | '_ \   //_\\| |/ _ \| |/ _` | '_ \ / _` | '__/ _ \ 
 /  _  \ (_| | |  | | (_| | | | | /  _  \ |  __/| | (_| | | | | (_| | | | (_) |
 \_/ \_/\__,_|_|  |_|\__,_|_| |_| \_/ \_/_|\___|/ |\__,_|_| |_|\__,_|_|  \___/ 
                                              |__/                             
  __       _                 _                           _   _                 
 / _\ __ _| | __ _  __ _  __| | ___     /\/\   __ _ _ __| |_(_)_ __   ___ ____ 
 \ \ / _` | |/ _` |/ _` |/ _` |/ _ \   /    \ / _` | '__| __| | '_ \ / _ \_  / 
 _\ \ (_| | | (_| | (_| | (_| | (_) | / /\/\ \ (_| | |  | |_| | | | |  __// /  
 \__/\__,_|_|\__, |\__,_|\__,_|\___/  \/    \/\__,_|_|   \__|_|_| |_|\___/___| 
             |___/                                                             





                  ___                _ _         _  __      
                 / __|___ _ __  _ __(_) |__ _ __(_)/_/ _ _  
                | (__/ _ \ '  \| '_ \ | / _` / _| / _ \ ' \ 
                 \___\___/_|_|_| .__/_|_\__,_\__|_\___/_||_|
                               |_|                          

              Para compilar ir al directorio de el codigo fuente

                                > cd src


                              Y utilizar make

                                 > make



                       ___  _                _  __      
                      | __|(_)___ __ _  _ __(_)/_/ _ _  
                      | _| | / -_) _| || / _| / _ \ ' \ 
                      |___|/ \___\__|\_,_\__|_\___/_||_|
                         |__/                           

 Para ejecutar el programa, si se quiere interactuar con el mediante la ventana
                         de comandos, se puede hacer:

                                 > ./snakes 

      Si se quiere jugar un juego con parametros personalizados se puede:

                        > ./snakes 40 8 8 -5 3 4 200 a


   Por otro lado, si se prefiere hacer una simluacion mas dinamica, se puede
           ejecutar especificando los archivos de entrada y salida:

                          > ./snakes in.txt out.txt

     Del mismo modo, para utilizar parametros personalizados Y archivos del

                > ./snakes in.txt out.txt 20 4 4 -2 3 1 100 m



                 ___  _            __         _         _     
                |   \(_)___ __    / _|___    (_)_  _ __| |_   
                | |) | (_-</ _|_  > _|_ _|   | | || (_-<  _|_ 
                |___/|_/__/\__(_) \_____|   _/ |\_,_/__/\__(_)
                                           |__/               

Para realizar este programa, utilice algunos conceptos de POO tales como:
   * Clases/objetos (duh)
   * Encapsulacion (con los atributos y metodos privados y protegidos)
   * Abstracción (con los header files)
   * Polomorfismo (sobrecarga de operadores y de metodos)

Algunas justificaciones del diseno que tome al realizar este programa son:
   * Las casillas de snakes y ladders del tablero son generadas de manera
     aleatoria.
   * Para evitar repetir codigo cuando el programa se corre por si solo vs.
     cuando se utilizan archivos de entrada y salida, el constructor de la clase
     Game tiene como argumentos dos streams, y estos pueden ser asignados como
     streams de tipo archivo o de terminal segun los argumentos que se le pase
   * Usualmente asigno como nombre a los atributos de las clases el prefijo "d_"
     y omito los prefijos "get" en los metodos porque asi lo lei en un libro y
     es algo a lo que me acostrumbre jeje
   * Sobrecargue los square brackets en la clase Board para que me diera la
     la representacion de string del tipo de casilla porque me gusto como se
     veia esta notacion
   * Obviamente llame a la clase Die porque es un solo dado ಠ╭╮ಠ
   * Intente que cada constante para los valores default de su constructor
     estuviera en su propio header file, en lugar de juntar todas las constantes
     en el programa principal, y a consecuencia los constructores de la clase
     Board estan un poco extranos, pero es la solucion menos compleja que
     encontre
   * En general la manera en la que me gusta disenar las cosas es permisivas y
     que manejen valores inusuales (e. g. si el numero de serpientes + el numero
     de escaleras > tamano del tablero, solo poner el numero maximo posibles; o 
     si la nueva posicion esta fuera del tablero, poner la nueva posicion en uno
     de sus limites).
