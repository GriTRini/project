import csv
import matplotlib.pyplot as plt
from tkinter import *
from drawnow import *
import folium
import turtle

# csv 파일 열기
l = open('project_estimator_global_position_0.csv')              # GPS
a = open('project_sensor_accel_0.csv')                          # 가속도
g = open('project_sensor_gyro_0.csv')                           # 자이로
al = open('project_estimator_global_position_0.csv')            # 고도

# 헤더파일 출력
print(csv.reader(l))
position = csv.reader(l)
header = next(position)
print(header)

print(csv.reader(a))
accel = csv.reader(a)
header = next(accel)
print(header)

print(csv.reader(g))
gyro = csv.reader(g)
header = next(gyro)
print(header)

print(csv.reader(al))
altitude = csv.reader(al)
header = next(altitude)
print(header)


# 리스트 생성
name = []
lat = []
lon = []
heading = []
Gx = []
Gy = []
Gz = []
Ax = []
Ay = []
Az = []
alt = []

# 기체 방향 확인
def head():
    turtle.shape('turtle')
    turtle.left(90)
    turtle.turtlesize(20, 20, 1)
    for row in position:
        heading.append(float(row[21]))
    for i in range(0, len(heading)):
        print(float(heading[i]))
        if float(heading[i]) >= 0:
            if float(heading[i-1]) >= 0:
                turtle.right((float(heading[i]) * 10) - (float(heading[i-1]) * 10))
            else:
                turtle.left(float(heading[i-1]) * 10)
                turtle.right(float(heading[i]) * 10)
        elif float(heading[i]) < 0:
            if float(heading[i-1]) >= 0:
                turtle.left(float(heading[i-1]) * 10)
                turtle.right(float(heading[i]) * 10)
            else:
                turtle.right(((float(heading[i])) * 10) - ((float(heading[i-1])) * 10))

# 경도 위도 데이터값
def Local():
    local_map = folium.Map(location=[36.32150740022885, 127.41184443849869], zoom_start=15)
    exlon = 0
    exlat = 0
    for row in position:
        sub1 = abs(exlon - float(row[2]))
        sub2 = abs(exlat - float(row[3]))
        if sub1 > 0.001 or sub2 > 0.001:
                lat = float(row[2])
                lon = float(row[3])

                maker = folium.Marker(location = [lat, lon])
                maker.add_to(local_map)
                local_map.save('local.html')
                exlon = float(row[2])
                exlat = float(row[3])






# 자이로 센서 그래프
def showplot_Gyro():
    plt.title('Gyro Data')
    plt.plot(Gx, color='r', label='Gx')
    plt.plot(Gy, color='b', label='Gy')
    plt.plot(Gz, color='y', label='Gz')
    plt.legend()

# 자이로 센서 데이터값
def Gyro():
    for row in gyro:
        Gx.append(float(row[3]))
        Gy.append(float(row[4]))
        Gz.append(float(row[5]))
        drawnow(showplot_Gyro)

# 가속도계 그래프
def showplot_Accel():
    plt.title('Accel Data')
    plt.plot(Ax, color='r', label='Ax')
    plt.plot(Ay, color='b', label='Ay')
    plt.plot(Az, color='y', label='Az')
    plt.legend()

# 가속도계 값
def Accel():
    for row in accel:
        Ax.append(float(row[3]))
        Ay.append(float(row[4]))
        Az.append(float(row[5]))
        drawnow(showplot_Accel)

# 고도 그래프
def showplot_Alti():
    plt.title('Altitude Data')
    plt.plot(alt, color='r', label='alt')
    plt.legend()

# 고도 값
def Alti():
    for row in altitude:
        alt.append(float(row[4]))
        drawnow(showplot_Alti)



#윈도우창 만들기

w = Tk()
w.title('Px4 log review')

#이미지 불러오기
photo1 = PhotoImage(file = 'Px4.PNG')

Px4_png = Label(w, image = photo1)

# 버튼 만들기
btn1 = Button(w, text = 'Location Data', command = Local)
btn2 = Button(w, text = 'Gyro Data', command = Gyro)
btn3 = Button(w, text = 'Accel Data', command = Accel)
btn4 = Button(w, text = 'Altitude Data', command = Alti)
btn5 = Button(w, text = 'Heading Data', command = head)
btn6 = Button(w, text = '종료', command = quit)

#위젯배치   : pack(), place(), grid()
Px4_png.pack()
btn1.pack()
btn2.pack()
btn3.pack()
btn4.pack()
btn5.pack()
btn6.pack()


w.geometry('700x500')

w.mainloop()