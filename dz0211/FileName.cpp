#include<iostream>
#include<string>
#include<fstream>
#include<bitset>
using namespace std;

class filereader
{
public:
    filereader(string path)
    {
        this->_path = path;
    }
    bool correct()
    {
        if (_path.length() < 5)
        {
            cout << "Incorrect file name: " << _path << endl;
            return false;
        }
        inp.open(_path);
        if (!inp.is_open())
        {
            cout << "File " << _path << " can't be reached!" << endl;
            return false;
        }
        inp.close();
        return true;
    }
    virtual void display()
    {
        if (!correct())
        {
            return;
        }
        inp.open(_path);
        char ch;
        while (inp.get(ch))
        {
            cout << ch;
        }
        cout << endl;
        inp.close();
    }
    virtual ~filereader()
    {
        inp.close();
    }
protected:
    string _path;
    ifstream inp;
};

class ascii_file : public filereader
{
public:
    ascii_file(string path) : filereader(path) {};
    ~ascii_file() override
    {
        inp.close();
    }
    void display() override
    {
        if (!filereader::correct())
        {
            return;
        }
        inp.open(_path);
        char ch;
        while (inp.get(ch))
        {
            cout << int(ch);
        }
        cout << endl;
        inp.close();
    }
};

class binary_file : public filereader
{
public:
    binary_file(string path) : filereader(path) {};
    ~binary_file() override
    {
        inp.close();
    }
    void display() override
    {
        if (!filereader::correct())
        {
            return;
        }
        inp.open(_path);
        char ch;
        while (inp.get(ch))
        {
            cout << bitset<8>(ch);
        }
        cout << endl;
        inp.close();
    }
};

int main()
{
    ascii_file file("file.txt");
    file.display();
    return 0;
}
