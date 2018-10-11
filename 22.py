
st = ''
with open("p022_names.txt", "r") as f:
    st = f.read().split(",")
    st = [x[1:len(x)-1] for x in st]
    st.sort()

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
name_weight = {}
for i, x in enumerate(alphabet):
    name_weight[x] = i+1
count = 0
for i in range(len(st)):
    name = st[i]
    k = 0
    for j in name:
        k += name_weight[j]
    count += k*(i+1)

print(count)
