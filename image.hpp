#include<X11/Xlib.h>

#include "CImg.h"

using namespace cimg_library;
namespace s=std;
class Image:public File{
    public:
    Image(){

    }
    Image(s::string file):File(file){
        if(!existOrnot())
            return;
        int ch;
        do{
            s::cout<<"Enter choice,1 Open image,2 Show details,3 Show blurred image,0 Back\n";
            cin>>ch;
            switch(ch){
                case 1:showImage();
                break;
                case 2:
                printDetails();
                printResolution();
                break;
                /*case 3:showProfile();
                break;*/
                case 3:blurImage();
                break;
                case 0:return;
                default:cout<<"Enter correct choice\n";
            }
        }while(ch);
    }
    void showImage(){
        const char * file=filename.c_str();
        CImg<unsigned char> image(file),vis(500,400,1,3,0);
        CImgDisplay display(image,file);
        while(!display.is_closed()){
        }
    }
    void printResolution(){
        int height,width;
        const char * file=filename.c_str();
        CImg<unsigned char> image(file);
        width=image.width();
        height=image.height();
        cout<<"Resolution: "<<width<<" * "<<height<<endl;
    }
    /*void showProfile(){
        const char * file=filename.c_str();
        CImg<unsigned char> image(file),vis(500,400,1,3,0);
        const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
        image.blur(2.5);
        CImgDisplay display(image,"Click anywhere!"),draw_profile(vis,"Intensity profile");
        while(!display.is_closed() && !draw_profile.is_closed()){
            display.wait();
            if(display.button() && draw_profile.mouse_y()>=0){
                const int y=draw_profile.mouse_y();
                vis.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
                vis.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
                vis.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_profile);
            }
        }
    }*/
    void blurImage(){
        const char * file=filename.c_str();
        CImg<unsigned char> image(file);
        image.blur(2.5);
        CImgDisplay display(image,file);
        while(!display.is_closed()){
            display.wait();
        }
    }
};
/*int main(){
    Image("jp.jpg");
    return 0;
}*/