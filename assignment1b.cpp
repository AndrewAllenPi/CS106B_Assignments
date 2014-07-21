#include<iostream>
#include<istream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;



string CensorString1(string text, string remove){
    if(remove.empty())
    {
        return text;
    }
    if(text.empty())
    {
        return text;
    }

    for(int i = 0; i < remove.size(); i++)
    {
        int found;
        while((found = text.find(remove[i])) != string::npos)
            text.erase(found, 1);
    }
    return text;

}

void CensorString2(string &text, string remove){
    if(remove.empty())
    {
        return;
    }
    if(text.empty())
    {
        return;
    }

    for(int i = 0; i < remove.size(); i++)
    {
        int found = 0;
        while((found = text.find(remove[i], found)) != string::npos)
            text.erase(found, 1);
    }
}

struct exam_scores{
public:
    int min;
    int max;
    double average;
};

exam_scores class_scores(string filename){
    exam_scores stats;
    stats.average = 0;
    stats.max = 0;
    stats.min = 100;
    int no_of_students = 0;
    int total_of_scores = 0;
    ifstream fs;
    fs.open(filename.c_str());
    if(fs.fail())
    {
        cout << "file did not open" << endl;
    }
    else
    {
        while(!fs.eof())
            {
                int next_score;
                fs >> next_score;
                no_of_students++;
                total_of_scores += next_score;
                stats.average = double(total_of_scores)/no_of_students;
                if( next_score > stats.max)
                    stats.max = next_score;
                if( next_score < stats.min)
                    stats.min = next_score;
            }
            fs.close();
            return stats;
    }
}

void CountLetters(string filename){
    vector<int > counts(26,0);
    ifstream fs;
    fs.open(filename.c_str());
    if(fs.fail())
    {
        cout << "file did not open" << endl;
    }
    else
    {
        while(!fs.eof())
        {
            char ch;
            fs >> skipws >> ch;
            if((65 <= ch) && (ch <= 90))
            {
                ch+=32;
            }
            if((97 <= ch) && (ch <= 122))
            {
                ch-=97;
                counts[int(ch)]++;
            }
        }
        fs.close();
        char letter = 97;
        for(int i = 0; i < 26; i++)
        {
            cout << letter << ": " << counts[i] << endl;
            letter++;
        }
    }
}

int main(){
    string s = "Stanford University", t = "nt";

    cout << CensorString1(s,t) << endl;
    CensorString2( s, t );
    cout << s << endl;

    string file = "scores.txt";
    class_scores(file);
    cout << "Average: " << class_scores(file).average << endl
            << "Max: " << class_scores(file).max << endl
                << "Min: " << class_scores(file).min << endl;



    CountLetters("count_letters.txt");

}

