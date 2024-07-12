n = 5
data = [10, 20, 30, 40, 50]

sum_value = 0
prefix_sum = [0]
for i in data:
  sum_value += i
  prefix_sum.append(sum_value)

print(prefix_sum)
left = 3
right = 4
print(prefix_sum[right] - prefix_sum[left - 1])

left = 1
right = 1
print(prefix_sum[right] - prefix_sum[left - 1])