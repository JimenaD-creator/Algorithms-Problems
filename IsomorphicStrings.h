#include <iostream>
#include <unordered_map>
using namespace std;
bool isIsomorphic(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    unordered_map<char, char>map_s1_to_s2;
    unordered_map<char, char>map_s2_to_s1;

    for (int i = 0; i< s1.size(); i++){
        char char_s1 = s1[i];
        char char_s2 = s2[i];

        if(map_s1_to_s2.find(char_s1) != map_s1_to_s2.end()){
            if(map_s1_to_s2[char_s1] != char_s2){
                return false;
            }
        }else{
            map_s1_to_s2[char_s1] = char_s2;
        }

        if(map_s2_to_s1.find(char_s2) != map_s2_to_s1.end()){
             if(map_s2_to_s1[char_s2] != char_s1){
                return false;
            }

        } else {
            map_s2_to_s1[char_s2] = char_s1;
        }
    }
    return true;
}
void testIsomorphic() {
    // Caso 1: Strings muy largos (stress test)
    string s1 = "abcabcabcabcabcabcabcabcabcabc";
    string s2 = "xyzxyzxyzxyzxyzxyzxyzxyzxyzxyz";
    cout << "String 1: " << s1 <<endl;
    cout << "String 2: " << s2 << endl;
    if(isIsomorphic(s1, s2) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: True - pero prueba eficiencia O(n)
    
    // Caso 2: Mapeo circular complejo
    string s3 = "abcde";
    string s4 = "bcdea";
    cout << "String 3: " << s3 <<endl;
    cout << "String 4: " << s4 << endl;
    if(isIsomorphic(s3, s4) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: True - mapeo: a→b, b→c, c→d, d→e, e→a
    
    // Caso 3: Todos caracteres iguales vs diferentes
    string s5 = "aaaa";
    string s6 = "bbbb";
    cout << "String 5: " << s5 <<endl;
    cout << "String 6: " << s6 << endl;
    if(isIsomorphic(s5, s6) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: True - mapeo simple a→b
    
    string s7 = "aaaa";
    string s8 = "bcde";
    cout << "String 7: " << s7 <<endl;
    cout << "String 8: " << s8 << endl;
    if(isIsomorphic(s7, s8) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: False - a mapea a b, c, d, e
    
    // Caso 4: Mapeo bidireccional inválido
    string s9 = "ab";
    string s10 = "aa";
    cout << "String 9: " << s9 <<endl;
    cout << "String 10: " << s10 << endl;
    if(isIsomorphic(s9, s10) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: False - a→a, b→a (viola unicidad en s2)
    
    string s11 = "aab";
    string s12 = "ab";
    cout << "String 11: " << s11 <<endl;
    cout << "String 12: " << s12 << endl;
    if(isIsomorphic(s11, s12) == 1){
        cout << "Isomorphic: True"<<endl;
    }else{
        cout << "Isomorphic: False"<<endl;
    }
    // Expected: False - a→a, a→b (viola unicidad en s1)
}