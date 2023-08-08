#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
 
//  Main Idea = We should try to give the smaller apartment to the applicant who needs less space, because
// if we give it to another applicant, we may lose the opportunity to give house to the applicant who needs
// less space. This intuition can be used to build a greedy solution
// First sort the desired and actual size arrays of apartment in ascending order, and simultaneously traverse through both the arrays
// There are three cases possible:
// 1] We find a suitable apartment for the applicant within the given maximum allowed differnce.
// 2] If the desired apartment size of the applicant is too big, move the apartment pointer to the right to find a bigger one.
// 3] If the desired apartment is too small , skip that applicant and move to the next person

// Time complexity = O(max(a, b) * log(max(a, b))), since we are sorting the arrays and then traversing
// Space complexity = O(max(a, b)), to store the two arrays.

int main()
{
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    int a[n], b[m];
    int ans=0;
   for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	while (i < n && j < m) {
		// Found a suitable apartment for the applicant
		if (abs(a[i] - b[j]) <= k) {
			++i;
			++j;
			++ans;
		} else {
			// If the desired apartment size of the applicant is too big,
			// move the apartment pointer to the right to find a bigger one
			if (a[i] - b[j] > k) {
				++j;
			}
			// If the desired apartment size is too small,
			// skip that applicant and move to the next person
			else {
				++i;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}