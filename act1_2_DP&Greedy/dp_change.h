// Dynamic programming version of coin change problem.
#ifndef DP_CHANGE_H_
#define DP_CHANGE_H_

#include <vector>
#include <map>

using namespace std;

vector<int> dpChange(int change)
{
    // "denom" vector is a global variable
    // Arreglo de pares: { numero de monedas, quién lo etiquetó (etiquetar de donde viene la solución) }
}
// alias for dpChange: to comply with the assignment
vector<int> minNumMonDP(int n) { return dpChange(n); }

#endif // DP_CHANGE_H_
