if [ -z $1 ]; then
    ./zappy_server -p 4242 -x 35 -y 20 -c 5 -n Scientifique Scout -f 100
else
    ./zappy_server -p $1 -x 4 -y 2 -c 5 -n Scientifique Scout -f 100
fi
