data = str(input())

count = 0
for i in data:
    if i == '+':
        count += 1
    elif i == '-':
        break

data = data.replace('-', ' ').replace('+', ' ')
number = list(map(int, data.split(' ')))
print(sum(number[:count+1]) - sum(number[count+1:]))