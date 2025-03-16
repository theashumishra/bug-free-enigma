class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
    //int n = A.size();
    vector<int> C(n);
    unordered_set<int> setA, setB;
    int current_count = 0;
    
    for (int i = 0; i < n; ++i) {
        int a = A[i], b = B[i];
        
        // Insert A[i] into setA and check if it exists in setB
        bool insertedA = setA.insert(a).second;
        if (insertedA && setB.count(a)) {
            current_count++;
        }
        
        // Insert B[i] into setB and check if it exists in setA
        bool insertedB = setB.insert(b).second;
        if (insertedB && setA.count(b)) {
            current_count++;
        }
        
        C[i] = current_count;
}
return C;

}
};