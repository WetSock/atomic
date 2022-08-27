from django.urls import path
from . import views

urlpatterns = [
    path('', views.Demo),
    path('Scenario2/index.html', views.Scenario2),
    path('Scenario3/index.html', views.Scenario3),
    path('Scenario4/index.html', views.Scenario4),
    path('Demonstration/1.html', views.Demo1),
    path('Demonstration/2.html', views.Demo2),
    path('Demonstration/3.html', views.Demo3),
    path('Demonstration/4.html', views.Demo4),
    path('Demonstration/5.html', views.Demo5),
    path('Demonstration/6.html', views.Demo6),
    path('Demonstration/7.html', views.Demo7),
    path('Demonstration/8.html', views.Demo8),
    path('Demonstration/9.html', views.Demo9),

]
