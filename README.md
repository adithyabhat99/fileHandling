#Handling different types of files with C++


## Compilation(g++ 7.3.0)
'''g++ file.cpp -lboost_system -lboost_filesystem  -lm -lpthread -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o Output'''


## Recommended to use aptitude instead of apt to handle dependencies
'''sudo apt install aptitude'''

'''sudo aptitude install libboost-dev'''
'''sudo aptitude install libboost-thread-dev'''
'''sudo aptitude install  libboost-filesystem-dev'''

Install all dependencies from [here](https://gist.github.com/NoobsArePeople2/8086528)

'''sudo aptitude install libsfml-dev'''

## change line 50 "Status" to "Status1"
'''sudo subl /usr/include/SFML/Audio/SoundSource.hpp'''

### Put all the files in files direcctory
'''mkdir files'''