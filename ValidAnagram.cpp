//IT MEANS IF s = "anagram" and t = "nagaram", then return true.{in this we can see that all the letter that are present in s are
// also present in t and vice versa.}
// If s = "rat" and t = "car", then return false. 




// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()) return false;
//         int countS[26] = {0};
//         int countT[26] = {0};

//         for (int i = 0; i < s.length(); i++) {
//             countS[s[i] - 'a']++; 
//             countT[t[i] - 'a']++; 
//         }

//         for(int i =0; i<26; i++){
//             if(countS[i] != countT[i]){
//                 return false;
//             }
//         }
//         return true;

//     }
// };

#include <iostream>
#include <unordered_map>
#include <string>   
using namespace std;
int main(){
    string s ; string t;
    cout<<"Enter two strings: ";
    cin>>s>>t;
    if(s.length() != t.length()){
        return false;
    }
    int countS[26] = {0};
    int countT[26] = {0};
    for(int i=0;i<s.length();i++){
        countS[s[i]-'a']++;
        countT[t[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(countS[i] != countT[i]){
            return false;
        }
    }
    return true;
}