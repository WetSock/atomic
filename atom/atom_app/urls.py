from django.urls import path
from . import views

urlpatterns = [
    path('', views.Scenario1),
    path('Scenario2/index.html', views.Scenario2),
    path('Scenario3/index.html', views.Scenario3),
    path('Scenario4/index.html', views.Scenario4),

]
