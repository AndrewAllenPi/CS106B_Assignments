#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

/****************************************
Problem 1: Stanford_assignment1.pdf
****************************************/
/*
 * This program takes a string text and removes all the characters that appear in
 * the string remove and outputs the censored string.
 *
 */
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

/*
 * This program takes a string text and removes all the characters that appear in
 * the string remove. The original string text no longer exists, only its censored version.
 *
 */
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
        while((found = text.find(remove[i], found)) != string::npos) // This version is more efficient than above version
            text.erase(found, 1);
    }
}

/****************************************
Problem 2: Stanford_assignment1.pdf
****************************************/

// Struct that keeps statistics on integer scores between 0 and 100.
struct exam_scores{
    int min;
    int max;
    double average;
};

/*
 * This program takes a file and reads over the file once only and updates the minimum, maximum
 * and average in the struct exam_scores.
 * Precondition: The file contains one integer score per line and at least one entry
 *
 */
exam_scores class_scores(string filename){
    exam_scores stats;
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

                no_of_students++; // required for the average
                total_of_scores += next_score;

                if( next_score > stats.max)
                    stats.max = next_score;
                if( next_score < stats.min)
                    stats.min = next_score;
            }
            fs.close();
            stats.average = double(total_of_scores)/no_of_students;
            return stats;
    }
}

/****************************************
Problem 3: Stanford_assignment1.pdf
****************************************/

/*
 * This program takes a file and reads over the file once only and prints the number of
 * each letter in the file. Capitals and lower case letters are considered the same and other
 * characters are ignored.
 *
 */
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

            // Convert capitals to lower case.
            if(('A' <= ch) && (ch <= 'Z'))
            {
                ch+='a'-'A';
            }
            if(('a' <= ch) && (ch <= 'z'))
            {
                ch-='a'; // convert to vector index
                counts[int(ch)]++;
            }
        }
        fs.close();
        char letter = 'a';
        for(int i = 0; i < 26; i++)
        {
            cout << letter << ": " << counts[i] << endl;
            letter++;
        }
    }
}

int main(){
    string s = "Stanford University", t = "nt";

    cout << CensorString1(s,t) << endl; // Saford Uiversiy
    CensorString2( s, t );
    cout << s << endl; // Saford Uiversiy

    string file = "scores.txt";
    class_scores(file);
    cout << "Average: " << class_scores(file).average << endl
            << "Max: " << class_scores(file).max << endl
                << "Min: " << class_scores(file).min << endl;



    CountLetters("count_letters.txt"); // Lots of a's, 3 P's etc. in counts_letter.txt

}

