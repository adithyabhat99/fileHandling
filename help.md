g++ file.cpp -lboost_system -lboost_filesystem  -lm -lpthread -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio



sudo apt install libboost-dev
sudo apt install libboost-thread-dev
sudo apt-get install  libboost-filesystem-dev
https://gist.github.com/NoobsArePeople2/8086528
sudo apt-get install libsfml-dev

sudo subl /usr/include/SFML/Audio/SoundSource.hpp
(change line 50 "Status" to "Status1")