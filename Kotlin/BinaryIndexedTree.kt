class BinaryIndexedTree(size: Int) {
    private val tree: LongArray = LongArray(size)

    private fun lastBit(index: Int): Int {
        return index and -index
    }

    init { }

    fun add(index: Int, delta: Long) {
        var _index = index
        _index += 1
        while (_index <= tree.size) {
            tree[_index - 1] += delta
            _index += lastBit(index)
        }
    }

    fun prefix(end: Int): Long {
        var _end = end
        var result = 0L
        while (end > 0) {
            result += tree[end - 1]
            _end -= lastBit(end)
        }
        return result
    }

    fun size(): Int {
        return tree.size
    }

    fun sum(start: Int, end: Int): Long {
        return prefix(end) - prefix(start)
    }
}
