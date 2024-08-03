import random
with open('data1.txt', 'w') as file:
    for i in range(1):
        increasing_numbers = ' '.join(str(j + 1) for j in range(500))
        random_numbers = ' '.join(str(random.randint(0, 3)) for _ in range(500))
        file.write(f"{increasing_numbers}\n{random_numbers}\n")