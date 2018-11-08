class MinimumCyclicPermutation {
    fun calc(s: String): Int {
        var i = 0
        var j = 1
        var count = 0
        val len = s.length
        var x = 0
        var y = 0
        while (i < len && j < len && count < len) {
            x = (i + count) % len
            y = (j + count) % len
            when {
                s[x] == s[y] -> count ++
                s[x] > s[y] -> {
                    i += count + 1
                    count = 0
                }
                else -> {
                    j += count + 1
                    count = 0
                }
            }
            if (i == j) j = i + 1
        }
        return i
    }
}