from django.conf.urls import url
from . import views

urlpatterns = [
    url('q1', views.index1, name='index1'),
    url('q2', views.index2, name='index2'),
    url('q3', views.index3, name='index3'),
    url('q4', views.index4, name='index4'),
    url('q5', views.index5, name='index5'),
    url('carshomepage', views.carshomepage, name='carshomepage'),
    url('carsdisplaypage', views.carsdisplaypage, name='carsdisplaypage'),
    url('firstPage', views.firstPage, name="firstPage"),
    url('secondPage', views.secondPage, name='secondPage'),
    url('register', views.register, name='register'),
    url('success', views.success, name='success'),
    url('tech', views.tech, name='tech'),
    url('bill', views.bill, name='bill')
]