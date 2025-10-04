#include <iostream>
#include <unordered_map>
using namespace std;
bool anagrams(string s, string t){
    // Check if the strings have different lengths, return false immediately if tehy do
    if(s.length() != t.length()) return false; 
    // Define an array of prime numbers corresponding to each letter of alphabet
    int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    //Created an unordered map to store mapping between letters and prime numbers
    unordered_map<char, int>primeMap;
    // Initialize a character variable starting with 'a'
    char letter = 'a';
    // Iterate through the 26 letters of the alphabet (0 to 26 inclusive)
    for(int i = 0; i < 26; i++){
        // Assign the current prime number to the current letter in the map
        primeMap[letter] = primeNumbers[i];
        // Increment to the next letter in the alphabet
        letter++;
    }
    // Initialize product variables for both strings, starting with 1 (multiplicative identity)
    int product1 = 1, product2 = 1;
    // Itearte through each character in the first string 's'
    for(char s1: s){
        // Convert the current character to lowercase for case-insensitive comparison
        char lowerLetter = tolower(s1);
        // Check if the lowercase letter exists in the prime map
        if(primeMap.find(lowerLetter) != primeMap.end()){
            // Multiply the current result by the prime number associated with the letter
            product1*=primeMap[lowerLetter];
        }
    }
    // Iterate through each character in the second string 't'
    for (char t1: t){
         // Convert the current character to lowercase for case-insensitive comparison
        char lowerLetter = tolower(t1);
         // Check if the lowercase letter exists in the prime map
        if(primeMap.find(lowerLetter) != primeMap.end()){
            // Multiply the current result by the prime number associated with the letter
            product2*=primeMap[lowerLetter];
        }
    }
    // Compare the final products of prime numbers for both strings
    if(product1 != product2){
         // Return false if the products are different (not anagrams)
        return false;
    }
    // Return true if the products are equal (strings are anagrams)
    return true;

}
void testAnagrams() {
    // Caso 1: Strings muy largos (puede causar overflow)
    string str1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    string str2 = "zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba";
    cout << "Text 1: " << str1 <<endl;
    cout << "Text 2: " << str2 << endl;
    if(anagrams(str1, str2) == true){
        cout << "Anagram: True" << endl;

    }else {cout << "Anagram: False" <<endl;} 

    // Expected: True - pero puede causar overflow con números primos
    
    // Caso 2: Caracteres no alfabéticos (depende de la implementación)
    string str3 = "hello!@#";
    string str4 = "olleh#@!";
    cout << "Text 3: " << str3 <<endl;
    cout << "Text 4: " <<str4 << endl;
    if(anagrams(str3, str4) == true){
        cout << "Anagram: True"<<endl;

    }else {cout << "Anagram: False"<<endl;} 

    // Expected: Depende si filtras caracteres especiales
    
    // Caso 3: Strings con muchos caracteres duplicados
    string str5 = "aaaaaaaaaaaaaaaaaaaa"; // 20 'a's
    string str6 = "aaaaaaaaaaaaaaaaaaaa"; // 20 'a's
    // Expected: True - pero producto = 2^20 = 1,048,576
    cout << "Text 5: " << str5 <<endl;
    cout << "Text 6: " << str6 << endl;
    if(anagrams(str5, str6) == true){
        cout << "Anagram: True"<<endl;

    }else {cout << "Anagram: False"<<endl;} 

    
    // Caso 4: Overflow intencional
    string str7 = "a"; // 20 'z's
    string str8 = ""; // 20 'z's
    // z = 101, producto = 101^20 = número ENORME
    cout << "Text 7: " << str7 <<endl;
    cout << "Text 8: " << str8 << endl;
    if(anagrams(str7, str8) == true){
        cout << "Anagram: True"<<endl;

    }else {cout << "Anagram: False"<<endl;} 

    // Caso 4: Overflow intencional
    string str9 = "HOLA"; // 20 'z's
    string str10 = "M"; // 20 'z's
    // z = 101, producto = 101^20 = número ENORME
    cout << "Text 9: " << str9 <<endl;
    cout << "Text 10: " << str10 << endl;
    if(anagrams(str9, str10) == true){
        cout << "Anagram: True"<<endl;

    }else {cout << "Anagram: False"<<endl;} 

}