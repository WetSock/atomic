from django.contrib.contenttypes import views
from django.shortcuts import render
from django.shortcuts import redirect
from django.http import HttpResponse
from django.views.generic.list import ListView
import requests



def Demo(request):
    ## x = requests.get('http://192.168.2.202/?turnOff')
    return render(request, 'atom_app/Demo/index.html')

def Scenario2(request):
    return render(request, 'atom_app/Scenario2/index.html')

def Scenario3(request):
    return render(request, 'atom_app/Scenario3/index.html')

def Scenario4(request):
    return render(request, 'atom_app/Scenario4/index.html')

def Demo1(request):
    ## x = requests.get('http://192.168.2.202/?setDemo1')
    return render(request, 'atom_app/Scenario1/Demonstration/1.html')

def Demo2(request):
    ## x = requests.get('http://192.168.2.202/?setDemo2')
    return render(request, 'atom_app/Scenario1/Demonstration/2.html')

def Demo3(request):
    ## x = requests.get('http://192.168.2.202/?setDemo3')
    return render(request, 'atom_app/Scenario1/Demonstration/3.html')

def Demo4(request):
    ## x = requests.get('http://192.168.2.202/?setDemo4')
    return render(request, 'atom_app/Scenario1/Demonstration/4.html')

def Demo5(request):
    ## x = requests.get('http://192.168.2.202/?setDemo5')
    return render(request, 'atom_app/Scenario1/Demonstration/5.html')

def Demo6(request):
    ## x = requests.get('http://192.168.2.202/?setDemo6')
    return render(request, 'atom_app/Scenario1/Demonstration/6.html')

def Demo7(request):
    ## x = requests.get('http://192.168.2.202/?setDemo7')
    return render(request, 'atom_app/Scenario1/Demonstration/7.html')

def Demo8(request):
    ## x = requests.get('http://192.168.2.202/?setDemo8')
    return render(request, 'atom_app/Scenario1/Demonstration/8.html')

def Demo9(request):
    ## x = requests.get('http://192.168.2.202/?setDemo9')
    return render(request, 'atom_app/Scenario1/Demonstration/9.html')

