## ZAPPY Project

The goal of the Zappy project is to make a network game.
All the game rules are (of course) explained in the subject. Futhermore, we wrote a bit documentation to clarified these rules and how work the game.


   HOW TO PLAY ???
First of all, you need to boot on linux.
Get gcc and Makefile in order to compile. You'll get 2 programs.
zappy_server: start the server
zappy_ai: start the client (ai)
Execute zappy_server then zappy_ai with correct parameters.
There you are, you have a wonderful ai battle !
Enjoy.


   SO WHAT fzappy_server.sh DO ???
You can run the server with suggested parameters simply executing the script.
USAGE: ./fzappy_server [port]


   SERVER PROGRAM USAGE PLZ ???
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
-> port is the port number
-> width is the width of the world
-> height is the height of the world
-> nameX is the name of the team X
-> clientsNb is the number of authorized clients per team
-> freq is the reciprocal of time unit for execution of actions


   CLIENT PROGRAM USAGE PLZ ???
USAGE: ./zappy_ai -p port -n name -h machine
-> port is the port number
-> name is the name of the team
-> machine is the name of the machine; localhost by default


For some reasons, some choices were made:

[SERVER] -> The lasts arguments given as parameter to the programm will be selected
For exemple : ./zappy_server -p 4242 -p 4343
-> port will be 4343

[SERVER] -> The flag "-no_graph" as been added to disable the graphical render

[CLIENT] -> the client can play by himself with the flag "-no_ia"
