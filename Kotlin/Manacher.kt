class Manacher {
    fun longestPalindromeSubstring(text: String): String {
        val res = text.toList().map{listOf('#', it)}.flatMap { it.toList() }.toMutableList()
        res.add('#')
        val p: IntArray = IntArray(res.size) { 0 }
        var border = 0
        var center = 0
        for (i in 0 until res.size) {
            p[i] = if (border > i) minOf(p[2 * center - i], border - i) else 1
            while (i + p[i] < res.size && i >= p[i] && res[i + p[i]] == res[i - p[i]]) p[i] ++;
            if (i + p[i] > border) {
                border = i + p[i]
                center = i
            }
        }
        var ans = 0
        var ret = ""
        for (i in 0 until res.size) {
            if (p[i] > ans) {
                ans = p[i]
                ret = text.substring((i - p[i] + 1) / 2, (i + p[i] + 1 ) / 2)
            }
        }
        return ret
    }
}