class Solution {
public:
// resive un vector de enteros "nums" y un entero k 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*utilizamos un unordered_map que llamaremos frequencyMap
        para contar la frecuencia de cada elemento nums.
        */
        unordered_map<int, int> frequencyMap;
        for (int num : nums)
         {
            frequencyMap[num]++;
         }
         /*Copia las parejas que son de elemento y frecuencia del mapa 
         a un vector que llamaremos items, este sera ordenado segun la
         frecuencia de elementos utilizados usando un mergesort
         para terminar se crea un vector result que tiene los primeros
         k elementos del vector iteams.
         */
         vector<pair<int, int>> items(frequencyMap.begin(), frequencyMap.end());
        mergeSort(items);

        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(items[i].first);
        }
        return result;
        
    }
    /*Resive un vector de pares arr y sus indices left, mid y right
    divide el vector en 2 mitades izquierda y derecha para despues
    fusionarlas de forma ordenada en el vector original arr.
    */
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<pair<int, int>> L(arr.begin() + left, arr.begin() + left + n1);
        vector<pair<int, int>> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].second >= R[j].second) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
    /*
    resive un vector de pares arr, indices left y right.
    este mergeSort divide el vector en 2 partes y llama a mergeSort de
    forma recursiva para ambas mitades, para acabar fusiona esas 2 
    mitades ordenadamente usando la funsion merge.
    */
    void mergeSort(vector<pair<int, int>>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }
    /*
    metodo auxiliar para llamar a la funcion mergeSort.
    */
    void mergeSort(vector<pair<int, int>>& arr) {
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
    }
};