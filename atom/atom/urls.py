"""atom URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.template.context_processors import static
from django.urls import path, include
from django.conf import settings
from django.conf.urls.static import static


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('atom_app.urls')),
    path('Scenario1/index.html', include('atom_app.urls')),
    path('Scenario2/1.html', include('atom_app.urls')),
    path('Scenario3/index.html', include('atom_app.urls')),
    path('Scenario4/index.html', include('atom_app.urls')),
    path('Demonstration/1.html', include('atom_app.urls')),
    path('Demonstration/2.html', include('atom_app.urls')),
    path('Demonstration/3.html', include('atom_app.urls')),
    path('Demonstration/4.html', include('atom_app.urls')),
    path('Demonstration/5.html', include('atom_app.urls')),
    path('Demonstration/6.html', include('atom_app.urls')),
    path('Demonstration/7.html', include('atom_app.urls')),
    path('Demonstration/8.html', include('atom_app.urls')),
    path('Demonstration/9.html', include('atom_app.urls'))
]
