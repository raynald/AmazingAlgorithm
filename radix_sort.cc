#include <iostream> /* cout */
#include <cstdlib> /* srand, rand */
#include <ctime> /* time() */
#include <list> /* list */

#define BASE 10 // # of buckets to use
#define ARRAY_SIZE 50 // max # of elements in array

using namespace std;

void radix(int* nums, int length, int max) {
    list<int> bucket[BASE];
    int i;
    
    // iterate through each radix until n>max
    for (int n=1; max >= n; n *= BASE) {
        // sort list of numbers into buckets
        for (i=0; i<length; i++)
            bucket[(nums[i]/n)%BASE].push_back(nums[i]);
        
        // merge buckets back to list
        for (int k=i=0; i<BASE; bucket[i++].clear())
            for (list<int>::iterator j = bucket[i].begin(); j != bucket[i].end(); nums[k++] = *(j++));
    }
}

int main() {
    int nums[ARRAY_SIZE];
    int i;
    int max=0;
    srand(time(NULL));
    
    // store random numbers to array, print their current order
    cout << "Before:\r\n";
    for (i=0; i<ARRAY_SIZE; i++) {
        // generate random #, 1-1000
        nums[i] = rand()%1000 + 1;
        
        // determine max element upon addition to array
        max = (nums[i] > max)? nums[i]: max;
        cout << "\t" << nums[i] << " ";
    }
    cout << endl << endl;
    
    // sort using radix algorithm, passing max element
    radix(nums,ARRAY_SIZE,max);
    
    // print sorted array
    cout << "After:\r\n";
    for (int i=0; i<ARRAY_SIZE; i++)
        cout << "\t" << nums[i] << " ";
    cout << endl;
    return 0;
}

