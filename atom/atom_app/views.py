from django.contrib.contenttypes import views
from django.shortcuts import render
from django.shortcuts import redirect
from django.http import HttpResponse
from django.views.generic.list import ListView


def Demo(request):
    return render(request, 'atom_app/Demo/index.html')

def Scenario1(request):
    stage = request.GET.get('stage', 0)
    if stage:
        return render(request, f'atom_app/Scenario1/Demonstration/{stage}.html')
    return render(request, 'atom_app/Scenario1/index.html')

def Scenario2(request):
    return render(request, 'atom_app/Scenario2/index.html')

def Scenario3(request):
    return render(request, 'atom_app/Scenario3/index.html')

def Scenario4(request):
    return render(request, 'atom_app/Scenario4/index.html')
