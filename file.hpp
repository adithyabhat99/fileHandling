#include <iostream>
#include "boost/filesystem.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include <boost/date_time/posix_time/conversion.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>
using namespace std;
namespace fs = boost::filesystem;
class File
{
    public:
    string filename;
    File(){

    }
    File(string file){
        filename=file;
    }
    //returns true if file exists,otherwise returns false
    bool existOrnot()
    {
        return fs::exists(filename);
    }
    //returns the size of the file in bytes,returns -1 if file does not exists
    int getSize()
    {
        if (!existOrnot())
        {
            return -1;
        }
        int size = fs::file_size(filename);
        return size;
    }
    //returns 0 if file is not present,
    //returns 1 if file is a regular file, returns 2 if file is a directory
    int basic_type()
    {
        if (!existOrnot())
            return 0;
        if (fs::is_regular_file(filename))
            return 1;
        return 2;
    }
    //returns extension of file
    string findType()
    {
        int i, n = filename.size();
        for (i = 0; i < n; i++)
        {
            if (filename[i] == '.')
                break;
        }
        string type = "";
        while (i < n)
        {
            i++;
            string s = string(1, filename[i]);
            type.append(s);
        }
        //boost::trim_right(type);
        return type;
    }
    void lastModTime(boost::filesystem::path filename)
    {
        using boost::posix_time::ptime;
        using adj = boost::date_time::c_local_adjustor<ptime>;
        time_t const sys_time = last_write_time(filename);
        ptime const utc = boost::posix_time::from_time_t(sys_time);
        ptime const local = adj::utc_to_local(utc);
        cout << "Last modified time :utc :" << utc << endl;
        cout << "                   :local :" << local << endl;
    }
    void printDetails()
    {
        if (!existOrnot())
        {
            return;
        }
        if (basic_type() == 1)
        {
            cout << filename << " is a regular file\n";
            cout << "Type of the file: " << findType() << endl;
            cout << "Size of the file " << getSize() <<"bytes"<< endl;
        }
        else
        {
            cout << filename << " is a directory\n";
            //not possible to get size
        }
        lastModTime(filename);
    }
};
/*int main()
{
    string filename;
    cin >> filename;
    File ob(filename);
    cout<<ob.existOrnot()<<" "<<ob.getSize()<<endl;
    ob.lastModTime();
    ob.getDetails();
    return 0;
}*/