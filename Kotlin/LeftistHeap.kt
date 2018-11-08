class LeftistHeap {
    internal class LeftistNode(val element: Long, var left: LeftistNode? = null, var right: LeftistNode? = null, var s: Int = 0) {
    }

    private var root: LeftistNode?

    init {
        root = null
    }

    fun isEmpty(): Boolean {
        return root == null
    }

    fun peek(): Long {
        if (root == null) return -1
        else return root!!.element
    }

    fun add(num: Long) {
        root = merge(LeftistNode(num), root)
    }

    fun poll(): Long {
        if (root == null) return -1
        val ans = root!!.element
        root = merge(root?.left, root?.right)
        return ans
    }

    fun clear() {
        root = null
    }

    private fun merge(h1: LeftistNode?, h2: LeftistNode?): LeftistNode? {
        return when {
            h1 == null -> h2
            h2 == null -> h1
            h1.element < h2.element -> merge1(h1, h2)
            else -> merge1(h2, h1)
        }
    }

    private fun merge1(h1: LeftistNode, h2: LeftistNode): LeftistNode {
        if (h1.left == null) h1.left = h2
        else {
            h1.right = merge(h1.right, h2)
            if (h1.left!!.s < h1.right!!.s) swapChildren(h1)
            h1.s = h1.right!!.s + 1
        }
        return h1
    }

    private fun swapChildren(node: LeftistNode) {
        val t = node.left
        node.left = node.right
        node.right = t
    }
}