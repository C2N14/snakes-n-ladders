
                                                                                
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


   Por otro lado, si se prefiere hacer una simluacion mas dinamica, se puede
           ejecutar especificando los archivos de entrada y salida:

                          > ./snakes in.txt out.txt



                 ___  _            __         _         _     
                |   \(_)___ __    / _|___    (_)_  _ __| |_   
                | |) | (_-</ _|_  > _|_ _|   | | || (_-<  _|_ 
                |___/|_/__/\__(_) \_____|   _/ |\_,_/__/\__(_)
                                           |__/               

Para realizar este programa, utilice algunos conceptos de POO tales como:
   * Clases/objetos (duh)
   * Encapsulacion (con los atributos y metodos privados)
   * Abstracción (con los header files)
   * Sobrecarga de operadores y de metodos (en la clase Board)

Algunas justificaciones del diseno que tome al realizar este programa son:
   * Las casillas de snakes y ladders del tablero son generadas de manera
     aleatoria, sin embargo existen algunas restricciones:
      - No puede haber snakes ni en la ultima casilla, ni en una casilla donde
        los pasos llevarian antes de la primera
      - No puede haber ladders ni en la primera casilla, ni en una casilla donde
        los pasos llevarian despues de la ultima
   * Para evitar repetir codigo cuando el programa se corre por si solo vs.
     cuando se utilizan archivos de entrada y salida, el constructor de la clase
     MyGame tiene como argumentos dos streams, y estos pueden ser asignados como
     streams de tipo archivo o de terminal segun los argumentos, en main()
   * Prefiero almacenar los tipos de casilla como enums en lugar de strings por
     que asi me aseguro que solo pueden existir estos tipos :)
   * Usualmente asigno como nombre a los atributos de las clases el prefijo "d_"
     y omito los prefijos "get" en los metodos porque asi lo lei en un libro y
     es algo a lo que me acostrumbre jeje
   * Sobrecargue los square brackets en la clase Board para que me diera la
     la representacion de string del tipo de casilla porque me gusto como se
     veia esta notacion
   * Obviamente llame a la clase Die porque es un solo dado ಠ╭╮ಠ
   * En general todos los constructores estan hechos para ser personalizables,
     por si se quisiera extender un poco la funcionalidad del juego (o mas bien
      cuando *wink* *wink*)
