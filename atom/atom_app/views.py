from django.contrib.contenttypes import views
from django.shortcuts import render
from django.shortcuts import redirect
from django.http import HttpResponse
from django.views.generic.list import ListView
from .arduino import Arduino

arduinoClient = Arduino()

async def Demo(request):
    arduinoClient.asyncStart("Demo")
    return render(request, 'atom_app/Demo/index.html')

def Scenario2(request):
    arduinoClient.asyncStart("Scenario2")
    return render(request, 'atom_app/Scenario2/index.html')

def Scenario3(request):
    arduinoClient.asyncStart("Scenario3")
    return render(request, 'atom_app/Scenario3/index.html')

def Scenario4(request):
    arduinoClient.asyncStart("Scenario4")
    return render(request, 'atom_app/Scenario4/index.html')

async def Demo1(request):
    arduinoClient.asyncStart("Demo1")
    return render(request, 'atom_app/Scenario1/Demonstration/1.html')

def Demo2(request):
    arduinoClient.asyncStart("Demo2")
    return render(request, 'atom_app/Scenario1/Demonstration/2.html')

def Demo3(request):
    arduinoClient.asyncStart("Demo3")
    return render(request, 'atom_app/Scenario1/Demonstration/3.html')

def Demo4(request):
    arduinoClient.asyncStart("Demo4")
    return render(request, 'atom_app/Scenario1/Demonstration/4.html')

def Demo5(request):
    arduinoClient.asyncStart("Demo5")
    return render(request, 'atom_app/Scenario1/Demonstration/5.html')

def Demo6(request):
    arduinoClient.asyncStart("Demo6")
    return render(request, 'atom_app/Scenario1/Demonstration/6.html')

def Demo7(request):
    arduinoClient.asyncStart("Demo7")
    return render(request, 'atom_app/Scenario1/Demonstration/7.html')

def Demo8(request):
    arduinoClient.asyncStart("Demo8")
    return render(request, 'atom_app/Scenario1/Demonstration/8.html')

def Demo9(request):
    arduinoClient.asyncStart("Demo9")
    return render(request, 'atom_app/Scenario1/Demonstration/9.html')

