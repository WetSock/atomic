from django.urls import path
from . import views

urlpatterns = [
    path('', views.Demo),
    path('Scenario1/index.html', views.Scenario1, name='Scenario1'),
    path('Scenario2/index.html', views.Scenario2, name='Scenario2'),
    path('Scenario3/index.html', views.Scenario3, name='Scenario3'),
    path('Scenario4/index.html', views.Scenario4, name='Scenario4'),

]
