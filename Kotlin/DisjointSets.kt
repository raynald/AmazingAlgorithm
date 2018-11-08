class DisjointSets(var size: Int) {
    val num: IntArray = IntArray(size) { -1 }

    fun find(x: Int): Int {
        if (num[x] == -1) return x
        return find(num[x])
    }

    fun union(x: Int, y: Int): Int {
        val fx = find(x)
        val fy = find(y)
        if (fx == fy) return -1
        num[fx] += num[fy]
        num[fy] = fx
        return 0
    }

    fun getSize(x: Int): Int {
        val fx = find(x)
        return -num[fx]
    }
}