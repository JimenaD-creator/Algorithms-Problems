#include <iostream>
#include <vector>
using namespace std;
int climbingStairs(int totalSteps){
    if(totalSteps == 0 || totalSteps == 1) return 1;
    if(totalSteps < 0){
        return 0;
        cout << "The steps must be positive numbers" <<endl;
    }
    //We create a vector to store the number of ways with the size of totalSteps + 1
    vector<int>ways(totalSteps+1);
    ways[0] = 1;
    ways[1] = 1; 

    for (int i=2; i <= totalSteps; i++){
        ways[i] = ways[i-1] + ways[i-2];
    }
    return ways[totalSteps];
}

void testRobotStairs() {
    // Caso 1: Número muy grande (puede causar stack overflow en recursión)
    int n1 = 1000;
    // Expected: Fibonacci grande - necesita programación dinámica iterativa
    cout << "Number: " << n1 <<endl;
    cout << "Steps: " << climbingStairs(n1) <<endl;
    
    // Caso 2: n = 0 (caso borde)
    int n2 = 0;
     cout << "Number: " << n2 <<endl;
    cout << "Steps: " << climbingStairs(n2) <<endl;
    // Expected: 1 manera (no moverse)
    
    // Caso 3: Número negativo (comportamiento indefinido)
    int n3 = -5;
    cout << "Number: " << n3 <<endl;
    cout << "Steps: " << climbingStairs(n3)<<endl;
    // Expected: Debería manejarse con validación
    
    // Caso 4: Número que causa overflow aritmético
    int n4 = 1000000;
    cout << "Number: " << n4 <<endl;
    cout << "Steps: " << climbingStairs(n4) <<endl;
    // Expected: Necesita usar long long o BigInt
}