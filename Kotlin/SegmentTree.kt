class SegmentTree(size: Int) {
    internal class TreeNode {
        var left: Int = 0
        var right: Int = 0
        var cover: Int = 0
        var value: Int = 0
    }

    private val tree: Array<TreeNode> = Array(2 * size) { TreeNode() }

    init { }

    fun build(node_num: Int, left_branch: Int, right_branch: Int) {
        tree[node_num].left = left_branch
        tree[node_num].right = right_branch
        if (right_branch - left_branch >= 1) {
            val mid = (left_branch + right_branch) / 2
            build(2 * node_num + 1, left_branch, mid)
            build(2 * node_num + 2, mid + 1, right_branch)
        }
    }

    fun pushDown(num: Int) {
        if (tree[num].cover > 0) {
            tree[2 * num + 1].cover += tree[num].cover
            tree[2 * num + 2].cover += tree[num].cover
            val mid = (tree[num].left + tree[num].right).shr(1)
            tree[2 * num + 1].value += tree[num].cover * (mid - tree[num].left + 1)
            tree[2 * num + 2].value += tree[num].cover * (tree[num].right - mid)
            tree[num].cover = 0
        }
    }

    fun add(num: Int, left_branch: Int, right_branch: Int, d: Int) {
        if (tree[num].left == left_branch && tree[num].right == right_branch) {
            tree[num].cover += d
            tree[num].value = d * (tree[num].right - tree[num].left + 1)
        } else {
            pushDown(num)
            val mid = (tree[num].left + tree[num].right) / 2
            if (left_branch > mid) {
                add(2 * num + 2, left_branch, right_branch, d)
            } else if (right_branch <= mid) {
                add(2 * num + 1, left_branch, right_branch, d)
            } else {
                add(2 * num + 1, left_branch, mid, d)
                add(2 * num + 2, mid + 1, right_branch, d)
            }
            tree[num].value = tree[num * 2 + 1].value + tree[num * 2 + 2].value
        }
    }

    fun query(num: Int, left_branch: Int, right_branch: Int): Int {
        if (tree[num].left == left_branch && tree[num].right == right_branch) {
            return tree[num].cover
        }
        pushDown(num)
        val mid = (tree[num].left + tree[num].right) / 2
        if (left_branch > mid) {
            return query(2 * num + 2, left_branch, right_branch)
        } else if (right_branch <= mid) {
            return query(2 * num + 1, left_branch, right_branch)
        } else {
            return query(2 * num + 1, left_branch, mid)+ query(2 * num + 2, mid + 1, right_branch)
        }
    }
}