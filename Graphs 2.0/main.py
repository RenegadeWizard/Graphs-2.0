import dane, subprocess, time, random
# from multiprocessing import Process
import _thread

tab = [100,200,300,400,500,600,700,800,900,1000]
tab2 = [10,11,12,13,14,15,16,17,18,19,20]
results_files = ['wynik_euler.txt','wynik_hamilton.txt','wynik_part2.txt']
data_files = ['dane_euler_'+str(i)+'_'+j+'.txt' for i in tab for j in ['30','70']] + ['dane_hamilton_'+str(i)+'_'+j+'.txt' for i in tab for j in ['30','70']] + ['dane_czesc_2_'+str(i)+'.txt' for i in tab2]

def full(n):
    return n*(n-1)/2

def check(tab,percent):
    n = int(max(tab)+1+3*len(tab[max(tab)+2:])/4)
    n_max = full(max(tab)+1)
    if n > n_max * percent:
        return True
    return False

def count(tab):
    n = int(max(tab)+1+3*len(tab[max(tab)+2:])/4)
    n_max = full(max(tab)+1)
    return 100 * n/n_max



def timer(temp,delay):
    time.sleep(delay)
    print(temp)

def execution(task,time_period):
    # p1 = Process(target=timer,args=(time_period,''))
    # p2 = Process(target=timer,args=(2,''))
    # p1.start()
    # p2.start()
    try:
       _thread.start_new_thread( timer, ("Thread-1", 2, ) )
       _thread.start_new_thread( timer, ("Thread-2", 4, ) )
    except:
        print ("Error: unable to start thread")


def Main():
    # execution('subprocess.run("ls")',5)
    for i in results_files:
        if i == 'wynik_part2.txt':
            with open(i,'w') as file:
                file.write(i[6:-4]+'\t')
                for j in tab2:
                    file.write(str(j)+'\t')
            continue
        with open(i,'w') as file:
            file.write(i[6:-4]+'\t')
            for j in tab:
                file.write(str(j)+'\t')


    arr = [0] + dane.los_bez_pow(100) + [0]
    nie = []
    s = 0
    while(not check(arr,0.7)):
        print(len(arr),len(nie))
        a = random.randrange(len(set(arr)-set(nie)))
        a1 = list(set(arr)-set(nie))[a]
        nie.append(a1)
        a = random.randrange(len(set(arr)-set(nie)))
        a2 = list(set(arr)-set(nie))[a]
        while(arr.index(a1)+1 == arr.index(a2) or arr.index(a1)-1 == arr.index(a2)):
            a = random.randrange(len(set(arr)-set(nie)))
            a2 = list(set(arr)-set(nie))[a]
        nie.append(a2)
        a = random.randrange(len(set(arr)-set(nie)))
        a3 = list(set(arr)-set(nie))[a]
        while(arr.index(a1)+1 == arr.index(a3) or arr.index(a1)-1 == arr.index(a3) or arr.index(a2)+1 == arr.index(a3) or arr.index(a2)-1 == arr.index(a3)):
            a = random.randrange(len(set(arr)-set(nie)))
            a3 = list(set(arr)-set(nie))[a]
        nie.append(a3)
        arr += [a1,a2,a3,a1]
    print(arr)
    print(count(arr),0.3)
    # for i in data_files:
    #     with open(i,'w') as file:
    #         arr = dane.los_bez_pow()



    # for i in range(3):
    #     for j in data_files:


Main()
