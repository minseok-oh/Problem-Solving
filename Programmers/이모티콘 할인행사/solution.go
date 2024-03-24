var sales, result []int

func getIncome(users [][]int, emoticons []int) []int {
    var res []int
    res = append(res, 0, 0)
    
    for _, user := range users {
        var in int = 0
        for i, sale := range sales {
            if user[0] <= sale {
                in += emoticons[i] * (100 - sale) / 100
            }
        }
        
        if in >= user[1] {
            res[0] += 1
        } else {
            res[1] += in
        }
    }
    return res
}

func findGreatestSales(users [][]int, emoticons []int) {
    if len(sales) == len(emoticons) {
        var income []int = getIncome(users, emoticons)
        
        if income[0] > result[0] {
           result = income    
        } else if income[0] == result[0] && income[1] > result[1] {
           result = income
        }
        return
    }
    
    for i := 10; i < 50; i += 10 {
        sales = append(sales, i)
        findGreatestSales(users, emoticons)
        sales = sales[:len(sales) - 1]
    }
}

func solution(users [][]int, emoticons []int) []int {
    result = append(result, 0, 0)
    findGreatestSales(users, emoticons)
    return result
}
