import math

def is_prime_number(x):
  if x == 1:
    return False
  for i in range(2, int(math.sqrt(x)) + 1):
    if x % i == 0:
      return False
  return True

print(is_prime_number(7))
print(is_prime_number(1))



def find_prime_number(n):
  n = 1000
  array = [True for i in range(n + 1)]

  for i in range(2, int(math.sqrt(n)) + 1):
    if array[i] == True:
      j = 2
      while i * j <= n:
        array[i * j] = False
        j += 1

  for i in range(2, n + 1):
    if array[i]:
      print(i, end=' ')

#find_prime_number(100)