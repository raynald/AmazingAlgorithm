class Trie {
    internal class TrieNode(var value: Int = 0) {
        val children: Array<TrieNode?> = Array<TrieNode?>(26) { null }
    }

    private var root: TrieNode = TrieNode()
    private var count = 0

    fun insert(key: String) {
        count ++
        var node = root
        for (ch in key) {
            if (node.children[ch - 'a'] == null) {
                node.children[ch - 'a'] = TrieNode()
            }
            node = node.children[ch - 'a']!!
        }
        node.value = count
    }

    fun search(key: String): Boolean {
        var node: TrieNode? = root
        for (ch in key) {
            if (node == null) return false
            if (node.children[ch - 'a'] == null) return false
            node = node.children[ch - 'a']
        }
        return node != null && node.value > 0
    }

    private fun isFreeNode(node: TrieNode): Boolean {
        for (i in 0 .. 25) {
            if (node.children[i] != null) return false
        }
        return true
    }

    private fun canDelete(node: TrieNode?, key: String, index: Int): Boolean {
        if (node != null) {
            if (index == key.length) {
                if (node.value > 0) {
                    node.value = 0
                    return isFreeNode(node)
                }
            } else {
                if (canDelete(node.children[key[index] - 'a'], key, index + 1)) {
                    node.children[key[index] - 'a'] = null
                    return (node.value == 0 && isFreeNode(node))
                }
            }
        }
        return false
    }

    fun delete(key: String) {
        canDelete(root, key, 0)
    }
}