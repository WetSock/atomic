from django.contrib.contenttypes import views
from django.shortcuts import render
from django.shortcuts import redirect
from django.http import HttpResponse
from django.views.generic.list import ListView
from .arduino import Arduino

arduinoClient = Arduino()

async def Demo(request):
    arduinoClient.demoThread.start()
    return render(request, 'atom_app/Demo/index.html')

def Scenario2(request):
    return render(request, 'atom_app/Scenario2/index.html')

def Scenario3(request):
    return render(request, 'atom_app/Scenario3/index.html')

def Scenario4(request):
    return render(request, 'atom_app/Scenario4/index.html')

async def Demo1(request):
    arduinoClient.demoThread1.start()
    return render(request, 'atom_app/Scenario1/Demonstration/1.html')

def Demo2(request):
    arduinoClient.demoThread2.start()
    return render(request, 'atom_app/Scenario1/Demonstration/2.html')

def Demo3(request):
    arduinoClient.demoThread3.start()
    return render(request, 'atom_app/Scenario1/Demonstration/3.html')

def Demo4(request):
    arduinoClient.demoThread4.start()
    return render(request, 'atom_app/Scenario1/Demonstration/4.html')

def Demo5(request):
    arduinoClient.demoThread5.start()
    return render(request, 'atom_app/Scenario1/Demonstration/5.html')

def Demo6(request):
    arduinoClient.demoThread6.start()
    return render(request, 'atom_app/Scenario1/Demonstration/6.html')

def Demo7(request):
    arduinoClient.demoThread7.start()
    return render(request, 'atom_app/Scenario1/Demonstration/7.html')

def Demo8(request):
    arduinoClient.demoThread8.start()
    return render(request, 'atom_app/Scenario1/Demonstration/8.html')

def Demo9(request):
    arduinoClient.demoThread9.start()
    return render(request, 'atom_app/Scenario1/Demonstration/9.html')

