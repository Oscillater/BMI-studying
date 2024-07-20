import random
with open('data.txt', 'w') as file:
    for i in range(8):
        increasing_numbers = ' '.join(str(j + 1) for j in range(200))
        random_numbers = ' '.join(str(random.randint(0, 3)) for _ in range(200))
        file.write(f"{increasing_numbers}\n{random_numbers}\n")