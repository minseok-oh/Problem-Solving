var results []int
var nameIndex map[string]int

func initialize(enroll []string) {
    results = make([]int, len(enroll))
    nameIndex = make(map[string]int)
    
    for i, enr := range enroll {
        nameIndex[enr] = i
    }
}

func plusAmount(name string, referral []string, amount int) {
    if name == "-" || amount == 0 {
        return
    }
    
    var parent int = amount / 10
    
    var index int = nameIndex[name]
    results[index] += (amount - parent)
    plusAmount(referral[index], referral, parent)
}

func solve(referral []string, seller []string, amount []int) {
    for i, name := range seller {
        plusAmount(name, referral, amount[i] * 100)
    }
}

func solution(enroll []string, referral []string, seller []string, amount []int) []int {
    initialize(enroll)
    solve(referral, seller, amount)
    return results
}
