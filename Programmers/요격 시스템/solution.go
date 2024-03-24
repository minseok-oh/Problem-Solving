import "sort"

type missile struct {
    s, e int
}
type Missile []missile
var missiles Missile

func (m Missile) Len() int {
    return len(m)
}

func (m Missile) Swap(i, j int) {
    m[i], m[j] = m[j], m[i]
}

func (m Missile) Less(i, j int) bool {
    return m[i].s < m[j].s
}

func initialize(targets [][]int) {
    for _, target := range targets {
        var m missile = missile{target[0], target[1]}
        missiles = append(missiles, m)
    }
    sort.Sort(missiles)
}

func solve() int {
    var result int = 1
    var s, e int = -1, 100000000
    for _, m := range missiles {
        if s <= m.s && m.e <= e {
            s = m.s
            e = m.e
        } else if m.s < e {
            s = m.s
        } else {
            result += 1
            s, e = m.s, m.e
        }
    }
    return result
}

func solution(targets [][]int) int {
    initialize(targets)
    var result int = solve()
    return result
}