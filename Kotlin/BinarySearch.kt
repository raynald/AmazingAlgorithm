/**
 * Find closest element, return the index
 */
class BinarySearch {
    fun search(num: IntArray, left: Int, right: Int, target: Int): Int {
        if (target < num[left]) return left
        if (target > num[right]) return right
        var lft = left
        var rgt = right
        while (lft <= rgt) {
            val mid = (lft + rgt) / 2
            if (target > num[mid]) {
                lft = mid + 1
            } else {
                rgt = mid - 1
            }
        }
        return if (num[lft] - target < target - num[rgt]) lft else rgt
    }
}
