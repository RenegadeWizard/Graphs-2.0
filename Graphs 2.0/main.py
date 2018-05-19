import dane, subprocess, time
from multiprocessing import Process

tab = [100,200,300,400,500,600,700,800,900,1000]
tab2 = [10,11,12,13,14,15,16,17,18,19,20]
results_files = ['wynik_euler.txt','wynik_hamilton.txt','wynik_part2.txt']
data_files = ['dane_euler_'+str(i)+'.txt' for i in tab] + ['dane_hamilton_'+str(i)+'.txt' for i in tab] + ['dane_czesc_2_'+str(i)+'.txt' for i in tab2]

def timer(delay,temp):
    time.sleep(delay)

def execution(task,time_period):
    p1 = Process(target=timer,args=(time_period,''))
    p2 = Process(target=timer,args=(2,''))
    p1.start()
    p2.start()


def Main():
    execution('subprocess.run("ls")',5)
    # for i in range(3):
    #     for j in data_files:
    #         with open(results_files[0],'a') as file:
    #             pass
    #         with open(results_files[])

Main()
