#include <SFML/Audio.hpp>
using namespace std;
class Music:public File{
    sf::SoundBuffer buffer;
    sf::Sound sound;
    string song;
    bool p;
    int volume;
    public:
    Music(){

    }
    Music(string s):File(s){
        song=s;
        volume=100;
        p=false;
        if(!existOrnot())
            return;
        int ch;
        do{
            cout<<"Enter choice,1 Enter Player,2 Show details,0 Back\n";
            cin>>ch;
            switch(ch){
                case 1:p=true;
                play();
                break;
                case 2:printDetails();
                break;
                case 0:return;
                default:cout<<"Enter correct choice\n";
            }
        }while(ch);
    }
    void play(){
        int ch;
        if( !buffer.loadFromFile(song)){
            cout<<"Audio could not be played\n";
            return;
        }
        sound.setBuffer(buffer);
        sound.play();
        p=true;
        do{
            cout<<"Press 1 Play,2 Pause,3 Set Volume,4 Loop music,5 Stop Loop,0 Back\n";
            cin>>ch;
            switch(ch){
                case 1:if(!p) sound.play();
                p=true;
                break;
                case 2:p=false;
                sound.pause();
                break;
                case 3:cout<<"Enter volume(0-100): ";
                cin>>volume;
                sound.setVolume(volume);
                break;
                case 4:sound.setLoop(true);
                break;
                case 5:sound.setLoop(false);
                break;
                case 0:return;
                default:cout<<"Press correct choice\n";
            }
        }while(ch);
    }
};
/*int main(){
    string song;
    cin>>song;
    Music m(song);
    m.play();
    return 0;
}*/