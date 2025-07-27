import cpuinfo, time
cpu_info_dict = cpuinfo.get_cpu_info()
cpu_model = cpu_info_dict.get('brand_raw')
print("Input amount of operations you want your CPU to execute: ", end="")
operations = int(input())
t1 = time.time()
cnt = 0
for i in range(operations):
    cnt += 1
t2 = time.time() - t1
print(f"{cpu_model} (Your CPU) executes {operations} operations in {t2} seconds, which is {t2 / 3600} hours, {(t2 / 60) % 60} minutes and {t2 % 60} seconds")
