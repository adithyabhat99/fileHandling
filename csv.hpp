using namespace std;
class CSV:public File{
    public:
    CSV(){

    }
    CSV(string file):File(file){
        if(!existOrnot())
            return;
        int ch;
        do{
            cout<<"Enter choice,1 Display File,2 Show details,0 Back\n";
            cin>>ch;
            switch(ch){
                case 1:display();
                break;
                case 2:printDetails();
                break;
                case 0:return;
                default:cout<<"Enter correct choice\n";
            }
        }while(ch);
    }
    void display(){
        ifstream in;
        string line;
        in.open(filename);
        int i,j,c=0;
        while(in){
            getline(in,line);
            j=1;
            for(i=0;i<line.size() && j<10;i++){
                if(line[i]==','){
                    if(c)
                    cout<<setw(5);
                    else{
                        cout<<setw(10);
                    }
                    j++;
                    continue;
                }
                if(line[i]=='"'){
                    continue;
                }
                cout<<line[i];
            }
            c=1;
            cout<<endl;
        }
        in.close();
    }
};