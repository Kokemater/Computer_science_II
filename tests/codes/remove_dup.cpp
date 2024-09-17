#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; 

        int uniqueIndex = 0; 
        
        // Recorre el vector desde el segundo elemento
        for (int i = 1; i < nums.size(); ++i) {
            // Solo mueve el elemento si es diferente del anterior
            if (nums[i] != nums[uniqueIndex]) {
                ++uniqueIndex; // Avanza el índice del valor único
                nums[uniqueIndex] = nums[i]; // Coloca el valor único en la posición correcta
            }
        }
        
        // El tamaño del vector sin duplicados es uniqueIndex + 1
        return uniqueIndex + 1;
    }
};

int main() {
    vector<int> lista = {1, 2, 2, 3};
    Solution sol;
    int length = sol.removeDuplicates(lista);

    cout << "Número de elementos únicos: " << length << endl;
    cout << "Contenido del vector después de eliminar duplicados: ";
    for (int i = 0; i < length; ++i) {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}
