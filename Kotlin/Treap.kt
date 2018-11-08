import kotlin.math.absoluteValue
import kotlin.math.sqrt

class Treap {
    private data class Node(var key: Int, var left: Node?, var right: Node?) {
    }

    private val NULL: Node = Node(Int.MIN_VALUE, null, null)
    private var root: Node = NULL

    fun insert(value: Int) {
        insert(root, value)
    }

    fun delete(value: Int) {
        delete(root, value)
    }

    fun isEmpty(): Boolean {
        return root == NULL
    }

    fun contains(value: Int): Boolean {
        var x = 10
        x.absoluteValue
        sqrt(x.toDouble())
    }

    private fun insert(node: Node, value: Int): Node {
        when {
            node == NULL -> {
                return Node(value, NULL, NULL)
            }
            node.key < value -> node.right = insert(node.right!!, value)
            else -> node.left = insert(node.left!!, value)
        }
        return node
    }

    private fun delete(node: Node?, value: Int): Node? {

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
