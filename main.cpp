#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Reader(vector<string> name)
{
    string temp;
    //if stream is a reader
    ifstream myInputFile;
    myInputFile.open("names/BoyNames.txt");

    
    if(myInputFile.is_open())
    {
        while(myInputFile >> temp)
        {
            name.push_back(temp);
        }
         myInputFile.close();
    }
}

void Writer(vector<string> name)
{
    //of stream is a writer
    ofstream myOutputFile;
    myOutputFile.open("names/SortedNames.txt");
    
    for(int i = 0; i < name.size(); i++)
    {
        myOutputFile << name[i] << endl;
    }
   
    myOutputFile.close();
}

void bothStreams(vector<string> myNames)
{
    Reader(myNames);
    sort(myNames.begin(), myNames.end());
    Writer(myNames);  
}

void oneStream()
{
    vector<string> myNames;
    
    string str;
    //f stream can become a reader or writer
    fstream myFile;
    
    myFile.open("names/BoyNames.txt");
    
    if(myFile.is_open())
    {
        while(myFile >> str)
        {
            myNames.push_back(str);
        }
         myFile.close();
    }
    
    sort(myNames.begin(), myNames.end());
    myFile.open("names/SortedNames.txt");
    
    for(int i = 0; i < myNames.size(); i++)
    {
        myFile << myNames[i] << endl;
    }
   
    myFile.close();
}

int main(int argc, char** argv) {

    vector<string> myNames;
    
    bothStreams(myNames);
    oneStream();
}



