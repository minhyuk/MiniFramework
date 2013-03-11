
#include <string>
#include <iostream>
#include <iosfwd>

#include "MiniFramework.h"

class Int2Char : public Convey<char>, public IInputProcessor<int> {
public:
    ~Int2Char(){}
    void process(const int& file){
        std::cout << "int2char" << file << std::endl;
        char xx = 'A';
        xx++;
        propagate(xx);
    }
};

class Char2String : public Convey<std::string>, public IInputProcessor<char> {
public:
    ~Char2String(){}
    void process(const char& file){
        std::cout << "char2string" << (char)file << std::endl;
        std::string x = "text";
        propagate(x);
    }
};

class Char2Char : public Convey<char>, public IInputProcessor<char> {
public:
    ~Char2Char(){}
    void process(const char& file){
        std::cout << "char2char" << (char)file << std::endl;
        char xx = 'X';
        propagate(xx);
    }
};

void demo1(){
    Int2Char int2char_converter;
    Char2String char2string_converter;
    Char2Char char2char_converter;

    int2char_converter.addNextProcessor(&char2string_converter);
    int2char_converter.addNextProcessor(&char2char_converter);

    char2char_converter.addNextProcessor(&char2string_converter);

    int one = 1;
    int2char_converter.process(one);
}

using namespace std;
class StringSpliter : public Worker< string, vector<string> >{
public:
    virtual void process(const string& obj){
        cout << "[StringSpliter]\n";
        string xx = obj;

        vector<string> splits;
        size_t pos = 0;
        size_t count = xx.find('/');
        while(count != xx.npos){
            splits.push_back ( xx.substr(pos,count) );
            xx = xx.substr(pos + count + 1);
            count = xx.find ('/');
        }
        splits.push_back( xx );

        propagate(splits);
    }
};

class StringsPrinter : public IInputProcessor<vector<string>>{
public:
    virtual void process(const vector<string>& obj){
        cout << "[StringPrinter]\n";
        for_each(obj.begin(), obj.end(), [](string v){
            cout << v << endl;
        });
    }
};


class CallEachString : public Worker<vector<string>, string>{
public:
    virtual void process(const vector<string>& obj){
        cout << "[CallEachString]\n";
        for_each(obj.begin(), obj.end(), [&](string v){
            propagate(v);
        });
    }
};


class SingleStringPrinter : public IInputProcessor<string>{
public:
    virtual void process(const string& obj){
        cout << "[SingleStringPrinter]\n";
        cout << "single string printer = " << obj << endl;
    }
};

class GreedyPicker : public IInputProcessor<string>, public IInputProcessor< vector<string> >{
    void process(const string& obj){
        cout << "[GreedyPicker]\n";
        cout << "greedy process string!!! --> " << obj << endl;
    }
    
    void process(const vector<string>& obj){
        cout << "[GreedyPicker]\n";
        cout << "greedy process string!!!!! --> vector"  << endl;
    }
};

// string --> vector<string> --> print out

void demo2(){
    StringSpliter spliter;
    {
        StringsPrinter printer;
        GreedyPicker greedy;
        CallEachString eachRecall;

        spliter.addNextProcessor(&printer);                         // vector<string> --> stdout
        spliter.addNextProcessor(&greedy);                          // vector<string> --> stdout, string --> stdout
        spliter.addNextProcessor(&eachRecall);                      // vector<string> --> call each strings
        
        {
            SingleStringPrinter singleStringPrinter;
            {
                eachRecall.addNextProcessor(&singleStringPrinter);
                eachRecall.addNextProcessor(&greedy);

                // top level runner
                spliter.process("test/hello/me");
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout << "=== DEMO1 ===" << std::endl;
    demo1();
    
    std::cout << std::endl;

    std::cout << "=== DEMO2 ===" << std::endl;
    demo2();
	return 0;
}


