using namespace std;
class Default : public File
{
  public:
    Default()
    {
    }
    Default(string file) : File(file)
    {
        if (!existOrnot())
            return;
        int ch;
        do
        {
            cout << "Enter choice,1 Display File,2 Show details,3 Append a file,0 Back\n";
            cin >> ch;
            switch (ch)
            {
            case 1:
                display();
                break;
            case 2:
                printDetails();
                break;
            case 3:appendFile();
            break;
            case 0:
                return;
            default:
                cout << "Enter correct choice\n";
            }
        } while (ch);
    }
    void display()
    {
        ifstream in;
        string line;
        in.open(filename);
        while (in)
        {
            getline(in, line);
            cout << line << endl;
        }
        in.close();
    }
    void appendFile(){
        string file,line;
        cout<<"Enter name of other file to append\n";
        cin>>file;
        fstream f1,f2;
        f1.open(filename,ios::app);
        f2.open(file,ios::in);
        f1<<endl;
        while(f2){
            getline(f2,line);
            f1<<line<<endl;
        }
        cout<<file<<" appended to "<<filename<<" successfully\n";
    }
};
/*int main()
{
    string s;
    cin >> s;
    Default d(s);
    return 0;
}*/