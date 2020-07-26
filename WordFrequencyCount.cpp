/*

                      Name : Ashish Bisht
        PROGRAM TO FIND FREQUENCY OF EACH WORD FROM .TXT FILE WITHOUT USING MAPREDUCE (case-insensitive)

              code and file should be in same directory
*/


#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
#include<conio.h>


using namespace std;

vector<string>::iterator find_word_in_vector(vector<string> &words_collection, string& word) //function to search word in the stored vector
{

    vector<string>::iterator pos;

    for(int i=0;word[i]!='\0';i++)                     //Converting every word to lower case
    {
        if(word[i]>='A' && word[i]<='Z')                
        word[i]+=32;
    }
    pos = find(words_collection.begin(), words_collection.end(), word);

       return pos;

    
}

int main()
{
  
    system("cls");
    string file, word = "";
    char ch;
    int i;
    vector<string> words_collection;
    vector<int> word_count;

    cout<<"\n\t**** Word Count Program without Map Reduce *****\n";
    cout << "\n\tEnter the  File  Name(with .extension) which need to be used(without any special symbols or space ) : ";
    getline(cin, file);


    ifstream File_in(file, ios::in);

    if (!File_in)
    {
        cout << "\n\n\tFile cannot be Opened\n\t";
        return 1;
    }

    File_in.seekg(0); //place the file Pointer at the starting of the file
    cout << "\n\n\tContent Of FILE\n\n";


    while (!File_in.eof())
    {

        File_in.get(ch);
        cout << ch;

        if ((ch >='A' && ch <='Z') || (ch >='a' && ch <= 'z') ||(ch>='0'&&ch<='9')) //checking for only alaphabets
        {
            word += ch;
        }

        if (word != "" && !((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')||(ch>='0'&&ch<='9'))) //checking when some special symbol encounters(other than alaphabet) means we get a complete word
        {

            vector<string>::iterator it = find_word_in_vector(words_collection, word);

            if (it != words_collection.end())       //if word is availabe in the vector then iterator is returned of that location else end location iterator  is returned 
            {
                word_count[it - words_collection.begin()] += 1; //finding the index location when word is already present in the vector then increase its frequency by 1
            }
            else //if new word then add to vector and its frequency to 1
            {
                words_collection.push_back(word);
                word_count.push_back(1);
            }

            word = ""; //clear the word string
        }
    }

    //This is for the last word remaining before the end of file
    if (word != "")
    {
        vector<string>::iterator it = find_word_in_vector(words_collection, word);

        if (it != words_collection.end())                   
        {
            word_count[it - words_collection.begin()] += 1; //finding the index location when word is already present in the vector then increase its frequency by 1 in word_count vector
        }
        else //if new word then add to vector and its frequency to 1
        {
            words_collection.push_back(word);
            word_count.push_back(1);
        }
    }
    File_in.close();

    cout << "\n\n\n\tFrequency of Words : \n\n";
    for (i = 0; i < words_collection.size(); i++)
    {
        cout <<"\t"<<words_collection[i] << " : " << word_count[i]<<" Times";
        cout << "\n";
    }
   
    getch();
    return 0;
}
