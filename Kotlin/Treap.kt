import java.util.*

class Treap {
    data class Node(var key: Int, var count: Int = 1, var priority: Int, var left: Node? = null, var right: Node? = null)

    private var root: Node? = null
    private val ran = Random()

    fun insert(value: Int) {
        root = insert(root, value)
    }

    fun delete(value: Int) {
        delete(root, value)
    }

    fun isEmpty(): Boolean {
        return root == null
    }

    fun contains(value: Int): Boolean {
        return contains(root, value)
    }

    private fun contains(node: Node?, value: Int): Boolean {
        when {
            node == null -> return false
            node.key == value -> return true
            node.key < value -> return contains(node.right, value)
            else -> return contains(node.left, value)
        }
    }

    private fun insert(node: Node?, value: Int): Node {
        when {
            node == null -> return Node(value, 1, ran.nextInt(100))
            node.key < value -> {
                node.right = insert(node.right, value)
                if (node.priority < node.right!!.priority) {
                    leftRotate(node)
                }
            }
            node.key > value -> {
                node.left = insert(node.left, value)
                if (node.left!!.priority < node.priority) {
                    rightRotate(node)
                }
            }
            else -> node.count ++
        }
        return node
    }

    private fun delete(node: Node?, value: Int): Node? {
        when {
            node == null -> return null
            node.key == value -> {
                when {
                    node.count > 1 -> node.count --
                    node.left == null && node.right == null -> return null
                    node.left == null -> return node.right
                    node.right == null -> return node.left
                    else -> {
                        if (node.left!!.priority < node.right!!.priority) {
                            rightRotate(node)
                            node.right = delete(node.right, value)
                        } else {
                            leftRotate(node)
                            node.left = delete(node.left, value)
                        }
                    }
                }
            }
            node.key < value -> node.right = delete(node.right, value)
            else -> node.left = delete(node.left, value)
        }
        return node
    }

    private fun leftRotate(node: Node): Node {
        val temp = node.right!!
        node.right = temp.left
        temp.left = node
        return temp
    }

    private fun rightRotate(node: Node): Node {
        val temp = node.left!!
        node.left = temp.right
        temp.right = node
        return temp
    }
}
