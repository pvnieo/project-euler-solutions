print(sum([i for i in range(2, 400000) if i == sum([int(x)**5 for x in str(i)])]))
