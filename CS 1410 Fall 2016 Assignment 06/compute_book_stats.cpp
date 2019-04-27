/*This program prompts the user to open a text file and stores each string 
 *into a vector of strings and computes several statistics such as the 
 *word count, character count, longest and shortest word and many more.
 *
 *The extra statistic this program implements is comparing the length
 *of the target word to other strings in the file and summing that up.
 *
 *Author: Steen Sia, sia
 *Prog. Assignment 6b
 *Last updated: October 19, 2016
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int compare_length(vector<string>, string target);
int string_count(vector<string> my_strings);
int word_count(vector<string>, string target);
int char_count(vector<string>);
string shortest_string(vector<string>);
string longest_string(vector<string>);
string word_before(vector<string>, string target);
string word_after(vector<string>, string target);

int main(){

  ifstream in_file;
  vector<string> my_strings;
  string file_name;
  string target;
  string input;
  //int count;
  int average_length;

  
  cout << "Enter the name of a text file: ";
  cin >> file_name;
  
  cout << "Enter a word to search: ";
  cin >> target;
  
  //Opens a text file from which the user enters
  in_file.open(file_name.c_str());
  
  if(in_file.fail())
    {
      cout << "Please enter a valid file name." << endl;
      return 0;
    }

  //Reads the files and puts each string into vector and increments
  while(in_file >> input)
    {
      //count++;
      my_strings.push_back(input);      
    }

  //Computes average by dividing the total number of characters by total number of strings
  average_length = char_count(my_strings) / string_count(my_strings);
  
  cout << "The number of words in the file is: " << string_count(my_strings) << endl;
  cout << "The number of characters in the file is: " << char_count(my_strings) << endl;
  cout << "The average length of all the words in the file is: " << average_length << endl;
  cout << "The shortest word in the file is: " << shortest_string(my_strings) << endl;
  cout << "The longest word in the file is: " << longest_string(my_strings) << endl;
 
  //Checks if the target word is found atleast once before printing other statistics
  if(!(word_count(my_strings, target) == 0))
    {
      cout << "The word you searched for appeared this many times: " << word_count(my_strings, target) << endl; 
      cout << "The number of strings that equal the length of your word is: " << compare_length(my_strings, target) << endl;
      cout << "The word that lexicographically comes before the word you searched is: " << word_before(my_strings, target) << endl;
      cout << "The word that lexicographically comes after the word you searched is: " << word_after(my_strings, target) << endl;
    }
  else
    cout << "The word you searched for does not exist." << endl; 
}
int string_count(vector<string> my_strings)
{
  int count = 0;
  for(int i = 0; i < my_strings.size()-1; i++){
    count++;
  }
  return count;
}
/*This function lexicographically compares the strings that are less
 *than the target word or come before it.
 *
 *Parameters:
 *vector -- the list of strings inside the file
 *string -- the target word that is being searched
 *
 *Return:
 *string -- the word that lexicographically comes before the target word
 */
string word_before(vector<string> my_strings, string target)
{
  vector<string> before_words;
  for(int i = 0; i < my_strings.size(); i++){
    if(my_strings[i] < target){
      before_words.push_back(my_strings[i]);
    }
  }

  if(before_words.size() == 0){
    return target;
  }

  string latest = before_words[0];
  for(int i = 1; i < before_words.size(); i++){
    if(before_words[i] > target){
      latest = before_words[i];
    }
  }
  return latest; 
}
/*This function lexicographically compares the strings that are greater
 *than the target word or come after it.
 *
 *Parameters:
 *vector -- the list of strings inside the file
 *string -- the target word that is being searched
 *
 *Return:
 *string -- the word that lexicographically comes after the target word
 */
string word_after(vector<string> my_strings, string target)
{
  vector<string> after_words;
  for(int i = 0; i < my_strings.size(); i++){
    if(my_strings[i] > target){
      after_words.push_back(my_strings[i]);
    }
  }

  if(after_words.size() == 0){
    return target;
  }

  string earliest = after_words[0];
  for(int i = 1; i < after_words.size(); i++){
    if(after_words[i] < target){
      earliest = after_words[i];
    }
  }
  return earliest; 
}

/*This function increments the number of times the target word's length 
 *matches up with the string length inside the file.
 *
 *Parameters:
 *vector -- the list of strings inside the file
 *string -- the target word that is being searched
 *
 *Return:
 *int -- the number of times target word's length matches
 */
int compare_length(vector<string> my_strings, string target)
{
  int target_length = 0;
  for(int i = 0; i < my_strings.size(); i++)
    {
      if(my_strings[i].length() == target.length())
	target_length++; 
    }
  return target_length;
}
/*This function totals the number of times the user's target word appears
 *in the text file.
 *
 *Parameters:
 *vector -- the list of strings inside the file
 *string -- the target word that is being searched
 *
 *Return:
 *int -- the number of times target word is searched
 */
int word_count(vector<string> my_strings, string target)
{
  int num_word = 0;
  for(int i = 0; i < my_strings.size(); i++)
    {
      if(my_strings[i] == target)
	num_word++;
    }
  return num_word;
}
/*This function sums the total number of characters in the text file.
 *
 *Parameters:
 *vector-- the list of strings inside the file
 *
 *Return:
 *int -- the total number of characters
 */
int char_count(vector<string> my_strings)
{
  int num_char = 0;
  for(int i = 0; i < my_strings.size(); i++)
    {
      num_char += my_strings[i].length();
    }
  return num_char;
}
/*This function finds the shortest string or word in the file
 *
 *Parameters:
 *vector-- the list of strings inside the file
 *
 *Return:
 *string -- the shortest string/word in the file
 */
string shortest_string(vector<string> my_strings)
{
  string shortest = my_strings[0];
  for(int i = 0; i < my_strings.size(); i++)
    {
      if(my_strings[i].length() < shortest.length())
	shortest = my_strings[i];
    }
  return shortest;
}
/*This function finds the longest string or word in the file
 *
 *Parameters:
 *vector-- the list of strings inside the file
 *
 *Return:
 *string -- the longest string/word in the file
 */
string longest_string(vector<string> my_strings)
{
  string longest = my_strings[0];
  for(int i = 0; i < my_strings.size(); i++)
    {
      if(my_strings[i].length() > longest.length())
	longest = my_strings[i];
    }
  return longest;
}
