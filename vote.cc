#include<iostream>
#include<map>
/* Moves all elements that appear more than n/k times to the front of the range.
 *  * Returns the end of this range of elements.
 *   * O(n log k) time using O(k) memory. */
template<class FIterator>
FIterator find_repeats(FIterator first, FIterator last, int k) {
    /* Compute the candidate elements in one pass. */
    int N = 0;
    std::map<typeof(*first), int> count;
    for(FIterator it = first; it != last; ++it, ++N) {
        ++count[*it];
        if(count.size() == k) {
            for(typeof(count.begin()) jt = count.begin(), tmp; jt != count.end(); ) {
                tmp = jt++;
                if(--tmp->second == 0) {
                    count.erase(tmp);
                }
            }
        }
    }
    std::cout << count.size() << std::endl;
    /* Verify the candidate elements in a second pass. */
    FIterator result = first;
    std::map<typeof(*first), int> candidate_count;
    for(FIterator it = first; it != last; ++it) {
        if(count.find(*it) != count.end() && ++candidate_count[*it] == N / k + 1) {
            std::swap(*result++, *it);
        }
    }
    std::sort(first, result);
    return result;
}

int main() {
    int N = 10;
    //int A[] = {7, 6, 6, 8, 5, 3, 6, 2, 8, 1};
    int A[] = {7, 6, 6, 8, 6, 6, 6, 5, 8};
    int M = find_repeats(A, A + N, 3) - A;
    for(int i = 0; i < M; i++) {
        std::cout << A[i] << std::endl;
    }
    return 0;
}

