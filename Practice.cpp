#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
// Function to apply P-box (Permutation) using a given table
vector<int> apply_PBox(const vector<int> &input, const vector<int> &table)
{
    vector<int> output(table.size());
    for (size_t i = 0; i < table.size(); i++)
        output[i] = input[table[i] - 1]; // Adjusting 1-based indexing to 0-based
    return output;
}
// Function to apply S-box (Substitution) using a given table
int apply_SBox(int input, const vector<vector<int>> &SBox)
{
    int row = ((input & 0x20) >> 4) | (input & 0x01); // Row = first and last bit
    int col = (input >> 1) & 0x0F;                    // Column = middle 4 bits
    return SBox[row][col];                            // S-box lookup
}
// Function to take vector input
vector<int> takeVectorInput(int size, const string &message)
{
    vector<int> vec(size);
    cout << message;
    for (int i = 0; i < size; i++)
        cin >> vec[i];
    return vec;
}
int main()
{
    int pSize;
    cout << "Enter size of P-box table: ";
    cin >> pSize;
    vector<int> PBoxTable = takeVectorInput(pSize, "Enter P-box permutation table: ");
    vector<int> inputBits = takeVectorInput(pSize, "Enter bits for permutation: ");
    vector<int> permutedBits = apply_PBox(inputBits, PBoxTable);
    cout << "P-Box Output: ";
    for (int bit : permutedBits)
        cout << bit;
    cout << endl;
    int sRows, sCols;
    cout << "Enter S-box dimensions (rows and columns): ";
    cin >> sRows >> sCols;
    vector<vector<int>> SBoxTable(sRows, vector<int>(sCols));
    cout << "Enter S-box table values:\n";
    for (int i = 0; i < sRows; i++)
        for (int j = 0; j < sCols; j++)
            cin >> SBoxTable[i][j];
    int inputSBox;
    cout << "Enter a 6-bit number for S-box substitution: ";
    cin >> inputSBox;
    int outputSBox = apply_SBox(inputSBox, SBoxTable);
    cout << "S-Box Output: " << bitset<4>(outputSBox) << endl;
    return 0;
}